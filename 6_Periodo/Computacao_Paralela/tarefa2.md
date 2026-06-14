/**
 * Computacao Paralela
 * 812939 - Vinicius Miranda de Araujo
 */

## Questão

Dado o seguinte código em OpenMP executando em uma máquina de dois núcleos,

```c
#include <stdio.h>

int main()
{
    #pragma omp parallel
    for(int i = 1; i <= 3; i++)
        printf("%d ",i);
}
```

Qual das saídas abaixo NÃO seria possível?

a) `1 2 1 2 3 3`

b) `1 1 2 3 2 3`

c) `1 2 3 2 1 3`

c) `1 2 1 3 2 3`

d) `1 1 2 2 3 3`

## Resposta

A diretiva utilizada foi `#pragma omp parallel`, então:
- Cada thread vai excutar seu próprio `for` completo.
- Cada thread imprime 1 2 3.
- 2 núcleos $\to$ 2 threads $\to$ 6 números no total.
    - Cada número aparece exatamente 2x.
- As threads podem intercalar, mas preservam a ordem 1 $\to$ 2 $\to$ 3.

Mas na letra C isso não ocorre:

T1: 1 2 3

T2: 2 1 3 $\to$ quebra da ordem

Logo letra C é impossível.