# Análise de Desempenho do Crivo de Eratóstenes com OpenMP

Análise do desempenho da implementação paralela do algoritmo Crivo de Eratóstenes utilizando OpenMP e a ferramenta `perf`. Comparandos as versões sequencial e paralela da aplicação, tem-se:

## Tabela Comparativa

| Métrica                            | Sequencial                          | Paralelo                            |
| ---------------------------------- | ----------------------------------- | ----------------------------------- |
| CPUs utilized                      | 0.997                               | 8.606                               |
| Frontend cycles idle               | 7.05%                               | 5.43%                               |
| Backend cycles idle                | 0.06 stalled cycles per instruction | 0.20 stalled cycles per instruction |
| Instructions per cycle (IPC)       | 1.25                                | 0.27                                |
| Cache miss rate (L1 approximation) | 8.32%                               | 13.72%                              |
| Time elapsed                       | 0.685 s                             | 0.312 s                             |


## Análise dos Resultados

A versão paralela apresentou redução significativa do tempo de execução, passando de aproximadamente 0.685 segundos para 0.312 segundos, demonstrando ganho real de desempenho com a paralelização.

O speedup aproximado obtido foi:

```text
Speedup = 0.685 / 0.312 ~ 2.19
```

Apesar do ganho no tempo total, algumas métricas indicam perda de eficiência interna na execução paralela.

O IPC caiu de 1.25 para 0.27, indicando que as threads passaram mais tempo aguardando acesso à memória e sincronizações do que efetivamente executando instruções úteis.

Além disso, a taxa de faltas em cache aumentou de 8.32% para 13.72%, sugerindo maior contenção de memória, competição entre threads e menor localidade de acesso aos dados.

Os ciclos ociosos de backend também aumentaram significativamente, demonstrando gargalos relacionados à busca de dados na memória.

## Gargalos

1. Criação excessiva de regiões paralelas

O código cria uma nova região paralela para cada valor de `p` gerando overhead elevado devido à criação, sincronização e finalização frequente das threads.

2. Contenção de memória compartilhada

Todas as threads acessam e modificam simultaneamente o vetor `prime`, aumentando a pressão sobre a hierarquia de memória.

Podendo causar:

- aumento de cache misses;
- redução do IPC;
- maior tempo de espera por memória;
- overhead de coerência de cache.

3. Trabalho redundante

O laço interno começa em `p * 2`, porém múltiplos menores que `p * p` já foram processados o que aumenta desnecessariamente a quantidade de operações realizadas.

## Sugestões de Otimização

1. Utilizar uma única região paralela externa

Criar apenas uma região paralela envolvendo todo o processamento, a fim de reduzir o overhead de criação e sincronização de threads

```c
#pragma omp parallel
{
    for (int p = 2; p <= sqrt_n; p++)
    {
        if (prime[p])
        {
            #pragma omp for
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
```

2. Iniciar o laço em `p * p`

Substituir:

```c
for (int i = p * 2; i <= n; i += p)
```

por:

```c
for (int i = p * p; i <= n; i += p)
```
