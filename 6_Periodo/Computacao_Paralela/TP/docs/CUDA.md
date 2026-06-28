# 1. Kernel `accumulateClusters`

```cpp
__global__ void accumulateClusters(
    observation *obs,
    cluster *clusters,
    size_t size)
{
    size_t j = blockIdx.x * blockDim.x + threadIdx.x;

    if (j < size)
    {
        int t = obs[j].group;

        atomicAdd(&clusters[t].x, obs[j].x);
        atomicAdd(&clusters[t].y, obs[j].y);
        atomicAdd((unsigned long long *)&clusters[t].count, 1ULL);
    }
}
```

## Objetivo

Realizar a etapa 2 do algoritmo K-Means, acumulando as coordenadas dos pontos pertencentes a cada cluster para calcular os novos centróides.

Cada thread da GPU é responsável por processar um ponto.

---

## Cálculo do índice da thread

```cpp
size_t j = blockIdx.x * blockDim.x + threadIdx.x;
```

### Por que isso é necessário?

Na GPU existem milhares de threads.

Cada thread precisa saber qual elemento do vetor ela irá processar.

Por exemplo:

```text
Bloco 0
Thread 0 → ponto 0
Thread 1 → ponto 1
...
Thread 255 → ponto 255

Bloco 1
Thread 0 → ponto 256
...
```

A fórmula:

```cpp
j = blockIdx.x * blockDim.x + threadIdx.x
```

transforma a hierarquia da GPU em um índice linear.

---

## Impacto

Permite que milhões de elementos sejam distribuídos automaticamente entre milhares de threads.

É a base do paralelismo em CUDA.

---

# 2. Uso do `atomicAdd`

```cpp
atomicAdd(&clusters[t].x, obs[j].x);

atomicAdd(&clusters[t].y, obs[j].y);

atomicAdd(
    (unsigned long long *)&clusters[t].count,
    1ULL);
```

## Objetivo

Evitar condições de corrida.

Imagine:

```text
Thread 1000 → cluster 4

Thread 2000 → cluster 4

Thread 3500 → cluster 4
```

Todas desejam atualizar:

```cpp
clusters[4].x
clusters[4].y
clusters[4].count
```

simultaneamente.

Sem sincronização:

```text
Atualizações poderiam ser perdidas
```

---

## Como o atomic funciona?

O hardware da GPU garante que:

```cpp
clusters[t].count++
```

ocorra de maneira indivisível.

Assim:

```text
Thread 1 atualiza

↓

Thread 2 atualiza

↓

Thread 3 atualiza
```

sem perda de valores.

---

## Impacto

Embora garanta corretude, cria um enorme gargalo.

Com:

```text
1 milhão de pontos
11 clusters
```

temos:

```text
3 milhões de atomicAdd
```

e milhares de threads disputando somente:

```text
11 posições de memória
```

Isso provoca:

- serialização;
    
- contenção;
    
- redução da ocupação da GPU.
    

É o principal gargalo da implementação.

---

# 3. Kernel `updateCentroids`

```cpp
__global__
void updateCentroids(cluster *clusters, int k)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < k && clusters[i].count > 0)
    {
        clusters[i].x /= clusters[i].count;
        clusters[i].y /= clusters[i].count;
    }
}
```

## Objetivo

Calcular a média das coordenadas acumuladas.

Equivale a:

```cpp
x = soma_x / quantidade

y = soma_y / quantidade
```

---

## Impacto

Praticamente não há ganho significativo.

Porque:

```text
k = 11
```

Existem somente 11 clusters.

Executar um kernel inteiro da GPU para apenas 11 divisões possui overhead maior que o trabalho realizado.

Provavelmente essa etapa seria mais eficiente na CPU.

---

# 4. Função Device `calculateNearest`

```cpp
__device__
int calculateNearest(
    observation *o,
    cluster *clusters,
    int k)
```

## Objetivo

Encontrar qual centróide está mais próximo do ponto.

Calcula:

```cpp
dist =
(clusters[i].x-o->x)^2
+
(clusters[i].y-o->y)^2
```

para todos os clusters.

Retorna:

```cpp
índice do menor valor
```

---

## Por que é `__device__`?

Essa função é executada exclusivamente na GPU.

Ela é chamada por outras funções kernel.

Não pode ser chamada diretamente pela CPU.

---

## Impacto

Muito positivo.

Essa operação é:

- independente;
    
- intensiva em cálculos;
    
- altamente paralelizável.
    

É uma das regiões que mais se beneficia da GPU.

---

# 5. Kernel `reassignClusters`

```cpp
__global__
void reassignClusters(
    observation *obs,
    cluster *clusters,
    size_t size,
    int k,
    unsigned int *changed)
```

## Objetivo

Executar as etapas 3 e 4 do K-Means.

Para cada ponto:

1. Encontrar o centróide mais próximo.
    
2. Verificar se houve mudança de cluster.
    
3. Atualizar o grupo.
    
4. Incrementar o contador de alterações.
    

---

## Paralelismo

Cada thread processa um ponto:

```text
Thread 0 → ponto 0

Thread 1 → ponto 1

Thread 2 → ponto 2

...
```

Como os pontos são independentes, existe enorme paralelismo natural.

---

## Impacto

Essa é provavelmente a região que mais contribui para o speedup da implementação.

---

# 6. Atomic na variável `changed`

```cpp
atomicAdd(changed,1);
```

## Objetivo

Contabilizar quantos pontos mudaram de grupo.

Sem sincronização:

```text
Thread 1 lê 100

Thread 2 lê 100

Thread 3 lê 100
```

Todas gravariam:

```text
101
```

quando o resultado correto seria:

```text
103
```

---

## Impacto

O custo é relativamente pequeno.

Porque:

- somente pontos que mudam executam esse atomic;
    
- existe apenas uma operação por ponto;
    
- muito menos contention do que nos centróides.
    

Portanto, o impacto é pequeno.

---

# 7. Kernel `resetClusters`

```cpp
__global__
void resetClusters(cluster *clusters, int k)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < k)
    {
        clusters[i].x = 0;
        clusters[i].y = 0;
        clusters[i].count = 0;
    }
}
```

## Objetivo

Inicializar novamente os clusters antes da próxima iteração.

---

## Impacto

Muito pequeno.

São apenas:

```text
11 clusters
```

Portanto, o ganho obtido ao executá-lo na GPU é praticamente nulo.

---

# 8. `cudaMalloc`

```cpp
cudaMalloc(&d_obs, size*sizeof(observation));

cudaMalloc(&d_clusters,k*sizeof(cluster));

cudaMalloc(&d_changed,sizeof(unsigned int));
```

## Objetivo

Reservar memória na GPU.

São criadas três estruturas:

### d_obs

Contém todos os pontos.

### d_clusters

Contém os centróides.

### d_changed

Armazena o número de mudanças.

---

## Impacto

Necessário para o funcionamento.

Porém:

```text
cudaMalloc()
```

é uma operação relativamente cara.

Felizmente é executada apenas uma vez.

---

# 9. `cudaMemcpy`

### CPU → GPU

```cpp
cudaMemcpy(
d_obs,
observations,
size*sizeof(observation),
cudaMemcpyHostToDevice);
```

---

### GPU → CPU

```cpp
cudaMemcpy(
observations,
d_obs,
size*sizeof(observation),
cudaMemcpyDeviceToHost);
```

e

```cpp
cudaMemcpy(
clusters,
d_clusters,
k*sizeof(cluster),
cudaMemcpyDeviceToHost);
```

---

## Objetivo

Transferir dados entre host (CPU) e device (GPU).

---

## Impacto

Transferências CPU-GPU são muito mais lentas que acessos internos da GPU.

Contudo, nesta implementação as transferências são poucas.

Os dados permanecem residentes na GPU durante todo o algoritmo.

Isso representa uma grande vantagem sobre a implementação OpenMP GPU.

---

# 10. Configuração dos kernels

```cpp
int blockSize = 256;
```

e

```cpp
<<<(size + blockSize -1)/blockSize,
   blockSize>>>
```

---

## Objetivo

Definir a organização da GPU.

Cada bloco possui:

```text
256 threads
```

Número de blocos:

```cpp
(size+255)/256
```

Para:

```text
1.000.000 pontos
```

temos aproximadamente:

```text
3907 blocos
```

Cada um com:

```text
256 threads
```

Total:

```text
≈ 1 milhão de threads
```

---

## Impacto

Permite explorar o paralelismo massivo da GPU.

Essa configuração é bastante comum em CUDA.

---

# Fluxo completo da execução

```text
CPU

↓

cudaMalloc()

↓

cudaMemcpy()

↓

GPU

resetClusters()

↓

accumulateClusters()

↓

updateCentroids()

↓

reassignClusters()

↓

while(changed > erro)

↓

cudaMemcpy()

↓

CPU
```

---

# Análise geral das construções utilizadas

|Recurso|Objetivo|Impacto|
|---|---|---|
|`__global__`|Executar kernels na GPU|Excelente|
|`__device__`|Funções auxiliares da GPU|Excelente|
|`blockIdx`, `threadIdx`, `blockDim`|Mapear threads aos dados|Essencial|
|`atomicAdd()` nos clusters|Garantir corretude|Gargalo principal|
|`atomicAdd()` em changed|Contabilizar alterações|Baixo impacto|
|`cudaMalloc()`|Alocar memória na GPU|Necessário|
|`cudaMemcpy()`|Transferir dados CPU↔GPU|Custo moderado|
|Grid de 256 threads|Boa ocupação da GPU|Excelente|
|`calculateNearest()`|Região computacional intensiva|Maior ganho de desempenho|

# Principal gargalo da implementação

O maior problema continua sendo:

```cpp
atomicAdd(&clusters[t].x,obs[j].x);

atomicAdd(&clusters[t].y,obs[j].y);

atomicAdd(
(unsigned long long *)&clusters[t].count,
1ULL);
```

Com:

```text
1 milhão de pontos
11 clusters
```

milhões de threads competem por apenas:

```text
11 estruturas
```

produzindo:

```text
Contenção
↓
Serialização
↓
Perda de paralelismo
↓
Speedup limitado
```

---

# Por que o CUDA foi mais rápido que OpenMP GPU?

Na implementação CUDA:

### Os dados permanecem na GPU durante todo o algoritmo.

Enquanto na versão OpenMP GPU:

```text
CPU
↓
GPU
↓
CPU
↓
GPU
↓
CPU
```

existem diversas transferências.

Já no CUDA:

```text
CPU
↓
GPU

várias iterações

↓

CPU
```

Além disso, os kernels CUDA possuem menor overhead que os kernels gerados automaticamente pelo OpenMP.

Por isso os tempos observados:

```text
Sequencial      ≈ 7,15 s

OpenMP GPU      ≈ 6,70 s

CUDA            ≈ 5,77 s
```

mostram que o CUDA consegue explorar melhor a GPU, embora ainda exista espaço para otimização usando:

- memória compartilhada (`shared memory`);
    
- reduções hierárquicas por bloco;
    
- padrões de Tiling;
    
- redução do número de operações atômicas.