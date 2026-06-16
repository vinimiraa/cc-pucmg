/**
 * Computacao Paralela
 * 812939 - Vinicius Miranda de Araujo
 */

Geração de algoritmos paralelos com a menor complexidade possível.

Algoritmos:

```c
[BUBLESORT]
for(i = 0; i < n-1; i++)
  for(j = 0; j < n-i-1; j++) 
    if(arr[j] > arr[j+1])
      swap(&arr[j], &arr[j+1]);
```

```c
[INSERTIONSORT]
for(i = 1; i < n; i++) {
  key = arr[i];
  j = i-1;
  while (j >= 0 && arr[j] > key) {
    arr[j+1] = arr[j];
    j = j-1;
  }
  arr[j+1] = key;
}
```

```c
[CRIVO DE ERASTÓTENES]
for(int p=2; p*p<=n; p++) {
  if(prime[p] == true) 
    for(int i=p*2; i<=n; i += p)
      prime[i] = false;
}
```

---

Algoritmos paralelos:

[BUBBLE SORT]
Na máquina RAM, o BubbleSort possui complexidade O(n²), pois utiliza dois laços aninhados e realiza várias comparações e trocas sucessivas até ordenar todo o vetor.

Para paralelizar no modelo PRAM, a melhor estratégia é transformar o algoritmo em uma versão conhecida como Odd-Even Transposition Sort. Nessa abordagem, em vez de comparar elementos um por vez, são feitas comparações simultâneas entre pares independentes do vetor.

Em uma fase par, são comparados os pares (0,1), (2,3), (4,5) e assim por diante. Em uma fase ímpar, são comparados os pares (1,2), (3,4), (5,6) etc. Como essas comparações não interferem entre si, elas podem ser executadas ao mesmo tempo.

Mesmo com paralelismo total, ainda são necessárias aproximadamente n fases para garantir a ordenação completa. Assim, no modelo PRAM, a complexidade fica O(n).

[INSERTION SORT]
Na máquina RAM, o InsertionSort possui complexidade O(n²) no pior caso, pois cada elemento pode precisar deslocar vários outros para encontrar sua posição correta.

A versão original é muito sequencial, pois cada inserção depende do resultado da anterior. Para paralelizar no modelo PRAM, a melhor alternativa é modificar completamente a lógica do algoritmo.

Cada elemento do vetor pode, simultaneamente, comparar-se com todos os demais para descobrir quantos valores são menores que ele. Essa quantidade representa sua posição final no vetor ordenado. Esse processo é chamado de ranking paralelo.

Por exemplo, se um elemento possui três valores menores que ele, sua posição final será a quarta posição do vetor.

Se houver processadores suficientes para realizar todas as comparações ao mesmo tempo, o tempo total pode ser reduzido para O(1) no modelo PRAM, embora utilizando grande quantidade de processadores.

Portanto:
RAM: O(n^2)
PRAM: O(1)

[CRIVO DE ERASTÓTENES]
Na máquina RAM, o Crivo de Erastóstenes possui complexidade O(n log log n), sendo um método eficiente para encontrar números primos.

Na versão sequencial, para cada número primo encontrado, seus múltiplos são marcados como não primos.

No modelo PRAM, essa marcação pode ser feita em paralelo. Para cada primo p, todos os múltiplos de p podem ser marcados simultaneamente. Além disso, vários primos também podem ser processados ao mesmo tempo.

Dessa forma, grande parte do trabalho ocorre paralelamente, restando apenas a coordenação entre as etapas. Com quantidade suficiente de processadores, a complexidade pode ser reduzida para O(log n).

Portanto:

RAM: O(n log log n)
PRAM: O(log n)