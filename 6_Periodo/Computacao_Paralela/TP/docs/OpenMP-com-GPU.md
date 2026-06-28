# 1. `#pragma omp target teams distribute parallel for`

```c
#pragma omp target teams distribute parallel for \
    map(to: observations[0:size]) \
    map(tofrom: clusters[0:k])
for (size_t j = 0; j < size; j++)
{
    ...
}
```

## Objetivo

Transferir a execução da etapa de cálculo dos centróides da CPU para a GPU.

Enquanto na versão OpenMP para CPU o trabalho era distribuído entre threads da CPU, aqui o OpenMP faz **offloading**, isto é, envia o processamento para a GPU.

---

## Por que usar `target`?

A diretiva

```c
#pragma omp target
```

indica que o código deverá ser executado no dispositivo acelerador (GPU).

Fluxo:

```
CPU
 ↓
Transferência dos dados
 ↓
GPU executa kernel
 ↓
Resultado retorna para CPU
```

Sem ela, o código continuaria sendo executado na CPU.

---

## Por que usar `teams distribute parallel for`?

Essa diretiva cria a hierarquia de execução da GPU.

Ela corresponde aproximadamente a:

```text
Grid
 ├── Team 1
 │     ├── Thread
 │     ├── Thread
 │     └── Thread
 ├── Team 2
 └── Team 3
```

A divisão acontece em três níveis:

### Teams

Criam grupos de threads.

Equivalem aproximadamente aos blocos (blocks) do CUDA.

---

### Distribute

Distribui as iterações entre os teams.

---

### Parallel for

Distribui o trabalho entre as threads de cada team.

---

## Impacto

Permite explorar milhares de threads da GPU simultaneamente.

É a principal diretiva responsável pelo ganho de desempenho obtido.

---

# 2. `map(to: observations[0:size])`

```c
map(to: observations[0:size])
```

## Objetivo

Copiar os pontos para a memória da GPU.

Os dados são somente leitura nessa etapa.

A GPU recebe:

```text
observations
```

mas não precisa devolver esse vetor ao final.

---

## Por que usar `to`?

Porque as coordenadas dos pontos:

```c
observations[j].x
observations[j].y
```

não são alteradas.

Apenas são utilizadas para calcular os centróides.

---

## Impacto

Evita transferências desnecessárias da GPU para a CPU.

Reduz o overhead de comunicação.

---

# 3. `map(tofrom: clusters[0:k])`

```c
map(tofrom: clusters[0:k])
```

## Objetivo

Transferir os clusters para a GPU e trazer os resultados de volta.

Fluxo:

```
CPU
 ↓
clusters
 ↓
GPU

Atualiza x,y,count

↓

CPU
```

---

## Por que `tofrom`?

Porque os clusters são modificados na GPU.

A CPU precisa receber os novos valores para continuar as próximas etapas.

---

## Impacto

Garante consistência entre CPU e GPU.

Entretanto, cada transferência possui custo.

Se executada repetidamente dentro do laço do K-Means, pode representar um gargalo.

O ideal seria manter os dados residentes na GPU através de:

```c
#pragma omp target data
```

evitando cópias a cada iteração.

---

# 4. Atomic

```c
#pragma omp atomic
clusters[t].x += observations[j].x;

#pragma omp atomic
clusters[t].y += observations[j].y;

#pragma omp atomic
clusters[t].count++;
```

## Objetivo

Evitar race conditions.

Milhares de threads da GPU podem tentar atualizar o mesmo cluster simultaneamente.

Exemplo:

```
Thread 5000 → cluster 3

Thread 8000 → cluster 3

Thread 14000 → cluster 3
```

Sem sincronização:

```text
Resultado incorreto
```

---

## Como funciona?

O hardware da GPU garante que:

```c
clusters[t].count++
```

seja realizado de forma indivisível.

---

## Impacto

Apesar de garantir corretude, é uma operação extremamente cara na GPU.

Supondo:

```text
1 milhão de pontos
11 clusters
```

Temos:

```text
3 operações atômicas por ponto

↓

3 milhões de atomics
```

Milhares de threads disputam acesso aos mesmos clusters.

Isso provoca:

- Serialização;
    
- Contenção;
    
- Subutilização da GPU.
    

Esse é o maior gargalo da implementação.

---

# 5. Segundo `target teams distribute parallel for`

```c
#pragma omp target teams distribute parallel for \
    map(tofrom: clusters[0:k])
for (int i = 0; i < k; i++)
{
    clusters[i].x /= clusters[i].count;
    clusters[i].y /= clusters[i].count;
}
```

## Objetivo

Calcular os novos centróides.

---

## Impacto

Essa paralelização praticamente não traz benefício.

Porque:

```c
k = 11
```

Existem apenas 11 iterações.

Lançar um kernel da GPU para executar somente 11 divisões possui custo maior do que o trabalho realizado.

O overhead de:

- criação do kernel;
    
- sincronização;
    
- transferência dos dados;
    

supera qualquer ganho.

Essa parte seria mais eficiente sendo executada na CPU.

---

# 6. Redução na reclassificação

```c
#pragma omp target teams distribute parallel for \
    map(tofrom: observations[0:size]) \
    map(to: clusters[0:k]) \
    reduction(+:changed)
```

---

## Objetivo

Executar a etapa mais pesada do K-Means diretamente na GPU.

Cada thread recebe um ponto:

```text
Thread 0 → ponto 0

Thread 1 → ponto 1

Thread 2 → ponto 2

...
```

e calcula qual é o centróide mais próximo.

---

## Por que `reduction(+:changed)`?

A variável:

```c
changed
```

conta quantos pontos mudaram de cluster.

Sem reduction:

milhares de threads fariam:

```c
changed++
```

simultaneamente.

Ocorreria race condition.

---

## Como funciona?

Cada thread mantém uma cópia privada:

```text
changed1
changed2
changed3
...
```

Ao final:

```text
changed =
changed1 +
changed2 +
changed3 + ...
```

---

## Impacto

Essa é uma excelente aplicação do OpenMP.

A etapa de busca do centróide mais próximo é:

- altamente paralelizável;
    
- independente;
    
- computacionalmente intensiva.
    

Ela tende a escalar muito bem na GPU.

É provavelmente a região que mais contribui para o speedup.

---

# 7. `map(tofrom: observations[0:size])`

```c
map(tofrom: observations[0:size])
```

## Objetivo

Atualizar o campo:

```c
observations[j].group
```

na GPU e trazer os resultados para a CPU.

---

## Impacto

Permite que as novas classificações sejam preservadas.

Porém existe uma transferência completa de:

```text
1 milhão de observações
```

a cada iteração do K-Means.

Isso pode representar um custo significativo.

Novamente, o ideal seria manter tudo dentro de:

```c
#pragma omp target data
{
    ...
}
```

para evitar cópias repetidas.

---

# Análise das diretivas empregadas

|Diretiva|Função|Impacto|
|---|---|---|
|`target`|Offloading para GPU|Excelente|
|`teams`|Criação dos grupos de threads|Excelente|
|`distribute`|Distribuição entre teams|Excelente|
|`parallel for`|Distribuição entre threads|Excelente|
|`map(to)`|Envio de dados para GPU|Necessário|
|`map(tofrom)`|Sincronização CPU-GPU|Necessário, mas custoso|
|`atomic`|Evitar race conditions|Correto, porém muito caro|
|`reduction(+:changed)`|Soma das alterações|Excelente|

# Principal gargalo

O maior problema da implementação continua sendo:

```c
#pragma omp atomic
clusters[t].x += observations[j].x;

#pragma omp atomic
clusters[t].y += observations[j].y;

#pragma omp atomic
clusters[t].count++;
```

Embora a GPU possua milhares de threads, os acessos atômicos acabam serializando parte da execução.

Na prática:

```text
Milhares de threads
↓
Disputam 11 clusters
↓
Muitos atomics
↓
Contenção
↓
Perda de desempenho
```

---

# Outro gargalo importante: transferência CPU ↔ GPU

A cada iteração do algoritmo ocorre:

```text
CPU
 ↓
observations
 ↓
GPU

processamento

↓

clusters
observations

↓

CPU
```

Essas cópias possuem alto custo.

Uma estratégia mais eficiente seria:

```c
#pragma omp target data
{
    while(...)
    {
        #pragma omp target teams distribute parallel for
        ...

        #pragma omp target teams distribute parallel for
        ...
    }
}
```

mantendo os vetores permanentemente na memória da GPU.

---

# Conclusão

As diretivas escolhidas exploram corretamente o modelo de programação para GPU do OpenMP:

- `target` realiza o offloading;
    
- `teams distribute parallel for` explora o paralelismo massivo da GPU;
    
- `map` controla as transferências de memória;
    
- `reduction` é uma solução eficiente para acumulação;
    
- `atomic` garante corretude.
    

Entretanto, dois fatores limitam o desempenho:

1. **Milhões de operações atômicas sobre apenas 11 clusters**, provocando contenção e serialização.
    
2. **Transferências repetidas entre CPU e GPU**, que aumentam o overhead.
    

A melhor otimização seria utilizar:

- `target data` para manter os dados residentes na GPU;
    
- acumuladores locais por bloco (shared memory), semelhantes aos padrões utilizados em CUDA;
    
- uma redução final para formar os centróides globais.
    

Essas modificações permitiriam explorar de forma muito mais eficiente o paralelismo massivo da GPU.