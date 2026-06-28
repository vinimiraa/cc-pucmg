# 1. `#pragma omp parallel for private(t)`

```c
#pragma omp parallel for private(t)
for (size_t j = 0; j < size; j++)
{
    t = observations[j].group;

    #pragma omp atomic
    clusters[t].x += observations[j].x;

    #pragma omp atomic
    clusters[t].y += observations[j].y;

    #pragma omp atomic
    clusters[t].count++;
}
```

## Objetivo

Paralelizar a etapa 2 do K-Means, responsável pelo cálculo dos novos centróides.

Cada iteração do laço percorre um ponto e acumula suas coordenadas no cluster correspondente.

---

## Por que usar `parallel for`?

Sem paralelismo:

```c
for (j=0;j<size;j++)
```

apenas uma thread percorre todos os pontos.

Com:

```c
#pragma omp parallel for
```

o OpenMP divide automaticamente o intervalo entre várias threads:

```
Thread 1 → pontos 0 até 250000

Thread 2 → pontos 250001 até 500000

Thread 3 → pontos 500001 até 750000

Thread 4 → pontos 750001 até 1000000
```

Isso permite que vários pontos sejam processados simultaneamente.

---

## Por que `private(t)`?

```c
int t;
```

é usado para armazenar o índice do cluster.

Se fosse compartilhado:

```
Thread 1 escreve t=3
Thread 2 escreve t=8
Thread 3 escreve t=1
```

uma thread poderia sobrescrever o valor utilizado por outra, causando comportamento incorreto.

Com:

```c
private(t)
```

cada thread recebe uma cópia própria:

```
Thread 1 → t privado

Thread 2 → t privado

Thread 3 → t privado
```

eliminando interferências.

---

# 2. `#pragma omp atomic`

```c
#pragma omp atomic
clusters[t].x += observations[j].x;

#pragma omp atomic
clusters[t].y += observations[j].y;

#pragma omp atomic
clusters[t].count++;
```

## Objetivo

Evitar condição de corrida (race condition).

Sem o atomic, imagine:

Cluster 5:

```
Thread 1:
clusters[5].x = 100

Thread 2:
clusters[5].x = 100
```

Thread 1 soma 10:

```
110
```

Thread 2 soma 20:

```
120
```

Resultado esperado:

```
130
```

Mas uma atualização sobrescreve a outra, produzindo:

```
120
```

ou

```
110
```

gerando resultados incorretos.

---

## Como o Atomic resolve?

O OpenMP transforma:

```c
clusters[t].x += observations[j].x;
```

em uma operação indivisível.

Assim:

```
Thread 1 entra
faz atualização
sai

Thread 2 entra
faz atualização
sai
```

garantindo consistência.

---

## Impacto no desempenho

Embora preserve a corretude, aqui existe um problema muito sério.

Para cada ponto são feitas:

- 1 atomic em x
    
- 1 atomic em y
    
- 1 atomic em count
    

Total:

```
3 × 1.000.000 = 3 milhões de operações atômicas
```

por iteração do algoritmo.

Como várias threads tentam atualizar os mesmos clusters simultaneamente, ocorre contenção:

```
Thread 1 esperando

Thread 2 esperando

Thread 3 esperando
```

Na prática, as threads passam grande parte do tempo bloqueadas.

Esse é provavelmente o principal motivo pelo qual o código ficou mais lento.

---

# 3. `#pragma omp parallel for`

```c
#pragma omp parallel for
for (int i = 0; i < k; i++)
{
    clusters[i].x /= clusters[i].count;
    clusters[i].y /= clusters[i].count;
}
```

## Objetivo

Calcular as médias dos clusters.

---

## Funcionamento

Cada iteração é independente:

Cluster 0:

```c
clusters[0].x /= clusters[0].count;
```

Cluster 1:

```c
clusters[1].x /= clusters[1].count;
```

Portanto podem ser executadas em paralelo.

---

## Impacto

Nesse caso o ganho é praticamente inexistente.

Porque:

```c
k = 11
```

Existem somente 11 iterações.

Mesmo usando 16 threads:

```
16 threads para apenas 11 divisões
```

O custo de criar e sincronizar threads é maior do que o trabalho realizado.

Provavelmente essa paralelização não traz benefício.

---

# 4. `#pragma omp parallel for private(t) reduction(+:changed)`

```c
changed = 0;

#pragma omp parallel for private(t) reduction(+:changed)
for (size_t j = 0; j < size; j++)
{
    t = calculateNearst(observations + j, clusters, k);

    if (t != observations[j].group)
    {
        changed++;
        observations[j].group = t;
    }
}
```

---

## Objetivo

Paralelizar a etapa mais pesada do K-Means:

Determinar qual centróide é o mais próximo de cada ponto.

---

## Por que usar `parallel for`?

Cada ponto é independente.

```
Ponto 1 → cluster mais próximo

Ponto 2 → cluster mais próximo

Ponto 3 → cluster mais próximo
```

Logo, o problema possui paralelismo natural.

Essa é provavelmente a região que mais se beneficia do OpenMP.

---

## Por que `private(t)`?

Cada thread precisa de sua própria variável temporária.

Sem isso haveria sobrescrita entre threads.

---

## Por que `reduction(+:changed)`?

A variável:

```c
changed
```

conta quantos pontos mudaram de grupo.

Se fosse compartilhada:

```
Thread 1 faz changed++

Thread 2 faz changed++

Thread 3 faz changed++
```

poderiam ocorrer perdas nas atualizações.

---

### Sem reduction

Suponha:

```
changed = 0
```

Três threads executam simultaneamente:

```
Thread 1 lê 0
Thread 2 lê 0
Thread 3 lê 0

Todas escrevem 1
```

Resultado:

```
changed = 1
```

quando deveria ser:

```
changed = 3
```

---

### Com reduction

Cada thread possui uma cópia local:

```
changed1
changed2
changed3
changed4
```

Ao final:

```
changed =
changed1 +
changed2 +
changed3 +
changed4
```

Assim não existe contenção durante o laço.

---

## Impacto

Essa é provavelmente a melhor utilização do OpenMP em todo o programa.

A operação:

```c
calculateNearst()
```

é computacionalmente pesada e independente.

Além disso, o reduction evita sincronizações frequentes.

Portanto essa região tende a escalar bem.

---

# Análise geral das diretivas

|Diretiva|Motivo|Impacto|
|---|---|---|
|`parallel for private(t)`|Distribuir iterações entre threads|Bom|
|`private(t)`|Evitar compartilhamento da variável temporária|Necessário|
|`atomic`|Garantir atualização correta dos clusters|Correto, porém muito custoso|
|`parallel for` nos centróides|Dividir cálculo das médias|Ganho praticamente nulo|
|`reduction(+:changed)`|Somar alterações sem race condition|Excelente|
|`parallel for` na classificação|Distribuir pontos entre threads|Região mais escalável|

# Principal gargalo do código

A parte mais problemática é:

```c
#pragma omp atomic
clusters[t].x += observations[j].x;

#pragma omp atomic
clusters[t].y += observations[j].y;

#pragma omp atomic
clusters[t].count++;
```

Ela cria milhões de sincronizações entre threads.

Uma abordagem muito mais eficiente seria utilizar **acumuladores locais por thread**:

```c
local_clusters[thread_id][k]
```

Cada thread acumularia seus próprios valores:

```
Thread 1 → clusters locais

Thread 2 → clusters locais

Thread 3 → clusters locais
```

sem nenhuma sincronização.

Somente ao final ocorreria uma redução:

```
clusters globais =
soma dos clusters locais
```

Essa estratégia praticamente elimina a contenção e é a otimização mais importante para o K-Means paralelo.

Portanto, embora as diretivas escolhidas estejam corretas do ponto de vista funcional, o uso intensivo de `atomic` faz com que o custo de sincronização supere os benefícios do paralelismo, explicando por que os tempos obtidos ficaram piores que a versão sequencial.