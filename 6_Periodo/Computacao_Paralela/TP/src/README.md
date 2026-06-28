# K-Means Clustering - Implementações Paralelas

Implementações do algoritmo K-Means em C e CUDA, explorando diferentes estratégias de paralelização: OpenMP para CPU, OpenMP offload para GPU e CUDA.

O dataset padrão são pontos 2D gerados aleatoriamente em um círculo, e a saída é gerada em formato EPS.

---

## Arquivos

| Arquivo             | Descrição            | Ambiente     |
|---------------------|----------------------|--------------|
| `k-means-seq.c`     | Sequencial           | Qualquer     |
| `k-means-par-cpu.c` | Paralelo OpenMP CPU  | Windows 11   |
| `k-means-par-gpu.c` | Paralelo OpenMP GPU  | Linux / WSL2 |
| `k-means-cuda.cu`   | Paralelo CUDA        | Linux / WSL2 |

---

## Compilação e execução

### Sequencial (`k-means-seq.c`) - Windows / Linux / WSL2

```bash
gcc -O2 k-means-seq.c -o k-means-seq -lm
time ./k-means-seq > output.eps
```

### OpenMP CPU (`k-means-par-cpu.c`) - Windows 11

```bash
gcc -O2 -fopenmp k-means-par-cpu.c -o k-means-par-cpu -lm
time ./k-means-par-cpu [num_threads]
```

O número de threads é opcional; se omitido, usa o máximo disponível.

### OpenMP GPU (`k-means-par-gpu.c`) - Linux / WSL2

```bash
gcc -O2 -fopenmp -foffload=nvptx-none k-means-par-gpu.c -o k-means-par-gpu -lm
# ou, se necessário:
gcc -O2 -fopenmp -foffload=nvptx-none -fcf-protection=none -fno-stack-protector k-means-par-gpu.c -o k-means-par-gpu -lm

time ./k-means-par-gpu [num_threads]
```

### CUDA (`k-means-cuda.cu`) - Linux / WSL2

```bash
nvcc -O2 k-means-cuda.cu -o k-means-cuda
time ./k-means-cuda
```

---

## Resultados de desempenho

### OpenMP CPU - Windows 11

Dataset: 1.000.000 pontos, 11 clusters

| Configuração        | Tempo real |
|---------------------|------------|
| Sequencial          | 0m19.837s  |
| OpenMP - 1 thread   | 0m19.681s  |
| OpenMP - 2 threads  | 0m23.110s  |
| OpenMP - 4 threads  | 0m23.508s  |
| OpenMP - 8 threads  | 0m25.765s  |
| OpenMP - 16 threads | 0m20.392s  |
| OpenMP - 32 threads | 0m30.151s  |

### OpenMP GPU offload - Linux / WSL2

Dataset: 1.000.000 pontos, 11 clusters

| Configuração       | user  | system | cpu | real   |
|--------------------|-------|--------|-----|--------|
| Sequencial         | 3.45s | 3.68s  | 99% | 7.156s |
| OpenMP GPU offload | 1.93s | 4.45s  | 95% | 6.697s |

### CUDA - Linux / WSL2

Dataset: 1.000.000 pontos, 11 clusters

| Configuração       | user  | system | cpu | real   |
|--------------------|-------|--------|-----|--------|
| Sequencial         | 3.45s | 3.68s  | 99% | 7.156s |
| CUDA GPU           | 1.44s | 4.12s  | 96% | 5.773s |

---

## Estrutura do algoritmo

1. Cada ponto recebe um cluster inicial aleatório.
2. Calcula-se o centróide de cada cluster (média dos pontos do cluster).
3. Cada ponto é reatribuído ao centróide mais próximo.
4. Repete os passos 2–3 até que menos de 0,01% dos pontos mudem de cluster.

A convergência é controlada por `minAcceptedError = size / 10000`.

---

## Alterações para Paralelização em relação ao Sequencial

### Visão Geral das Modificações

A versão sequencial processa um ponto de cada vez e realiza todas as operações na CPU. 
As versões paralelizadas dividem o trabalho entre múltiplas threads (OpenMP) ou entre GPU e CPU (CUDA), reduzindo o tempo de processamento através do paralelismo.

### 1. **OpenMP CPU (`k-means-par-cpu.c`)**

#### Alterações principais:

**a) Paralelização do cálculo de centróides**
```c
// Sequencial: loop simples
for (size_t j = 0; j < size; j++) {
    t = observations[j].group;
    clusters[t].x += observations[j].x;
    clusters[t].y += observations[j].y;
    clusters[t].count++;
}

// Paralelo: acesso concorrente sincronizado
#pragma omp parallel for private(t)
for (size_t j = 0; j < size; j++) {
    t = observations[j].group;
    #pragma omp atomic
    clusters[t].x += observations[j].x;

    #pragma omp atomic
    clusters[t].y += observations[j].y;

    #pragma omp atomic
    clusters[t].count++;
}
```
- Cada thread processa uma parcela dos dados em paralelo
- `#pragma omp atomic` garante operações thread-safe nos acumuladores

**b) Paralelização da reclassificação de pontos**
```c
// Sequencial: verificação serial
changed = 0;
for (size_t j = 0; j < size; j++) {
    t = calculateNearst(observations + j, clusters, k);
    if (t != observations[j].group) {
        changed++;
        observations[j].group = t;
    }
}

// Paralelo: com reduction
#pragma omp parallel for private(t) reduction(+:changed)
for (size_t j = 0; j < size; j++) {
    t = calculateNearst(observations + j, clusters, k);
    if (t != observations[j].group) {
        changed++;
        observations[j].group = t;
    }
}
```
- `reduction(+:changed)` acumula contagens de cada thread seguramente

#### Impacto:
- **Vantagem teórica:** Acelera processamento com múltiplos cores
- **Desvantagem observada:** Overhead de sincronização (atomic) supera benefício em datasets médios
- **Resultado:** Sem ganho ou até degradação de performance no Windows 11

### 2. **OpenMP GPU Offload (`k-means-par-gpu.c`)**

#### Alterações principais:

**a) Transferência de dados para GPU**
```c
#pragma omp target data map(to: observations[0:size], k) \
                        map(alloc: clusters[0:k]) \
                        map(from: observations[0:size])
{
    // Kernels executados na GPU
}
```
- Dados carregados uma vez (to) e retornados no fim (from)

**b) Kernels na GPU com paralelismo em massa**
```c
#pragma omp target teams distribute parallel for
for (size_t j = 0; j < size; j++) {
    // Cálculo de centróides na GPU
}
```
- `teams distribute` cria múltiplos blocos de trabalho
- Cada ponto é processado independentemente em paralelo

#### Impacto:
- **Vantagem:** Execução massivamente paralela (centenas de threads simultâneas)
- **Redução de tempo:** ~6% no exemplo (7.156s $\to$ 6.697s)
- **Custo:** Overhead de transferência de dados entre host-device
- **Bom para:** Datasets muito grandes onde overhead é amortizado

### 3. **CUDA (`k-means-cuda.cu`)**

#### Alterações principais:

**a) Alocação de memória na GPU e sincronização**
```c
cudaMalloc(&d_obs, size * sizeof(observation));
cudaMalloc(&d_clusters, k * sizeof(cluster));

// Transferência host $\to$ device
cudaMemcpy(d_obs, observations, size * sizeof(observation), cudaMemcpyHostToDevice);
```

**b) Kernels separados e otimizados**
```cuda
__global__ void accumulateClusters(observation *obs, cluster *clusters, size_t size) {
    size_t j = blockIdx.x * blockDim.x + threadIdx.x;
    if (j < size) {
        int t = obs[j].group;
        atomicAdd(&clusters[t].x, obs[j].x);  // Thread-safe na GPU
        atomicAdd(&clusters[t].y, obs[j].y);
        atomicAdd((unsigned long long *)&clusters[t].count, 1ULL);
    }
}

__global__ void updateCentroids(cluster *clusters, int k) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < k && clusters[i].count > 0) {
        clusters[i].x /= clusters[i].count;
        clusters[i].y /= clusters[i].count;
    }
}
```

#### Impacto:
- **Vantagem:** Melhor controle e otimização específica para GPU
- **Redução significativa:** ~19% no exemplo (7.156s $\to$ 5.773s)
- **Escalabilidade:** Kernels separados permitem melhor load balancing
- **Hardware nativo:** Uso direto da CUDA Compute Capability
- **Melhor para:** Máquinas com GPU NVIDIA dedicada

---

### 4. **Comparação: Principais Diferenças**

| Aspecto            | Sequencial | OpenMP CPU    | OpenMP GPU              | CUDA             |
|--------------------|------------|---------------|-------------------------|------------------|
| **Execução**       | 1 thread   | N threads CPU | GPU + CPU               | GPU              |
| **Sincronização**  | Nenhuma    | atomic        | Implícita               | atomicAdd nativa |
| **Memória**        | Heap do SO | Compartilhada | Host + GPU              | Separada (H/D)   |
| **Overhead**       | Baixo      | Moderado      | Alto                    | Moderado-Alto    |
| **Escalabilidade** | Limitada   | Até N cores   | Até milhares de threads | Até 10k+ threads |
| **Ganho real**     | Baseline   | -10% a 0%     | +6%                     | +19%             |

---

### 5. **Análise de cada Estratégia**

#### OpenMP CPU - Por que não ganhou?
1. **Contention em acumuladores:** Múltiplas threads competem por `clusters[t].x`
2. **False sharing:** Cache coherence overhead entre cores
3. **Limite de I/O:** Acesso à memória é gargalo, não CPU

#### OpenMP GPU - Ganho modesto
1. **Transferência de dados:** Host $\to$ Device custo 3.68s (overhead)
2. **Execução GPU:** Recupera parcialmente em paralelismo massivo
3. **Resultado líquido:** +6% de melhoria
4. **Ponto de equilíbrio:** Datasets > 5M pontos teriam maior benefício

#### CUDA - Melhor desempenho
1. **Kernel separados:** Menos sincronizações desnecessárias
2. **float vs double:** 2x menos transferência + operações mais rápidas
3. **Hardware nativo:** Uso total da arquitetura GPU
4. **Redução 19%:** Acima do ponto de equilíbrio

---

## Dependências

- **GCC com suporte a OpenMP** - versões CPU e GPU offload
- **GCC com suporte a nvptx** (`-foffload=nvptx-none`) - GPU offload
- **CUDA Toolkit** (`nvcc`) - implementação CUDA

---

## Alunos

- Caio Faria Diniz
- Giuseppe Sena Cordeiro
- Vinícius Miranda de Araújo