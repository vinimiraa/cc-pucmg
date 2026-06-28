# Resposta de Lista de Exercícios

## Q1

![[Pasted image 20251027165249.png]]

- Comprimento da maior subsequência monotônica não decrescente (*Longest Increasing Subsequence* - LIS).

- **Método 1:**  
    Modelar o problema como um **grafo direcionado** $G = (V, E)$, onde $V$ contém os elementos da sequência $X$, e $E$ contém uma aresta de $X_i$ para $X_j$ se $X_i < X_j$ e $i < j$. Aplicando um algoritmo de ordenação topológica (ou caminho crítico), o número de iterações necessárias corresponde ao comprimento da LIS.
    - Custo $O(V + E)$.
	
- **Método 2:**  
    Analisar cada elemento em relação aos anteriores. Se $X_i$ for maior que algum elemento anterior $X_j$, então atualiza-se o valor de $LIS[i] = LIS[j] + 1$; caso contrário, mantém-se o valor inicial. O processo é repetido para todos os elementos da sequência, partindo de um vetor inicializado com $1$ (ou $-\infty$, dependendo da modelagem).
	- Custo $O(n^2)$.

---

## Q2

![[Pasted image 20251027165310.png]]

- Subsequência contínua de soma máxima (*Maximum Subarray Problem*).

- A cada iteração, mantém-se a soma parcial atual (`soma`) e o melhor resultado encontrado até o momento (`max_soma`). Se a soma parcial se tornar negativa, ela é reiniciada para $0$, pois uma soma negativa não pode contribuir para uma subsequência de soma máxima futura. Assim, percorrendo o vetor apenas uma vez, atualizando localmente as variáveis.

```c
int max_soma(int n, int* L) // n = len(L)
{
  int max_soma = INT_MIN;
  int soma = 0;
  for(int i = 0; i < n; i++)
  {
	  soma += L[i];
	  if(soma > max_soma) max_soma = soma;
	  if(soma < 0) soma = 0;
  }
  return max_soma;
}
```

- Custo $O(n)$.

---

## Q3

![[Pasted image 20251027165330.png]]

- Comprimento da maior subsequência comum (*Longest Commom Subsequence* - LCS).

- Relação de Recorrência (Modelagem):

$$
L(i, j) = 
\begin{cases}
0 & , \text{ se } \ i = 0 \lor j = 0 \\
1 + L(i - 1, j - 1) & , \text{ se } \ X_i = X_j \\
max\{L(i, j - 1), L(i - 1, j)\} &, \text{ se } \ X_i \neq X_j \\
\end{cases}
$$

```c
int lcs_iterative(int n, int m, char* x, char* y) // n = len(x), m = len(y)
{
	int** L = (int**) malloc((n+1) * sizeof(int)); // n+1 linhas
	for(int i = 0; i <= n; i++) {
		L[i] = (int*) calloc((m+1), sizeof(int)); // cada linha com m+1 colunas
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(x[i-1] == y[j-1]) {
				L[i][j] = 1 + L[i-1][j-1];
			} else {
				L[i][j] = MAX(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	return L[n][m];
}
```

```c
define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs_recursive_memoization(char* x, char* y, int i, int j) // i e j são posições
{
	if (i == 0 || j == 0)
		return 0;
	if (memo[i][j] != -1)
		return memo[i][j];
	if (x[i - 1] == y[j - 1])
		memo[i][j] = 1 + lcs_recursive_memoization(x, y, i - 1, j - 1);
	else
		memo[i][j] = MAX(
			lcs_recursive_memoization(x, y, i - 1, j),
			lcs_recursive_memoization(x, y, i, j - 1)
		);
	
	return memo[i][j];
}
```

- Custo $O(m \times n)$.

---

## Q4

![[Pasted image 20251027165347.png]]

- Tamanho da maior subsequência palindrômica.

- Para este problema, pode-se utilizar a LCS (*Longest Commom Subsequence*) na qual recebe como parâmetro a sequência $X$ e o inverso de $X$, isto é:

$$
\text{Tamanho da Maior Subsequência Palindrômica} = |LCS(X, inv(X))| 
$$

- Custo $O(n^2)$.

---

## Q5

![[Pasted image 20251027165402.png]]

- Assim como na multiplicação de matrizes, o valor final depende de como se escolhe o ponto de corte `k` entre `i` e `j`.

- Defini-se duas tabelas:
	- $M[i,j]$: o **valor máximo** possível da subexpressão
	- $m[i,j]$: o **valor mínimo** possível da subexpressão
    
	Essa duplicidade é necessária porque a divisão não é associativa nem monotônica, e o máximo em uma parte pode produzir mínimo global, dependendo da forma da expressão.

- Modelagem
	- Para maximizar a divisão, queremos dividir um número grande (numerador) por um número pequeno (denominador).
	- Para minimizar, fazemos o oposto.

	$$
	M[X_i, X_j] = max\{\frac{M[X_i, X_k]}{m[X_{k+1}, X_j]}\} \ , i \leq k \leq j
	$$
	
	$$
	m[X_i, X_j] = \max \{ \frac{m[X_i, X_k]}{m[X_{k+1}, X_j]} \} \ , i < k < j
	$$ 

- Custo $O(n^3)$.

---

## Q6

![[Pasted image 20251027165420.png]]

- Encontrar uma sequência $Z = \langle z_1, z_2, \dots, z_k \rangle$ tal que:
	- ($Z$) é subsequência de ($X$) e subsequência de ($Y$),
	- O peso total  é máximo possível.

- O problema da subsequência comum de peso máximo é uma generalização direta do problema da LCS. A única diferença essencial está no termo somado na recorrência.

	$$
	L(i, j) = 
	\begin{cases}
	0 & , \text{ se } \ i = 0 \lor j = 0 \\
	x_i + L(i - 1, j - 1) & , \text{ se } \ X_i = X_j \\
	max\{L(i, j - 1), L(i - 1, j)\} &, \text{ se } \ X_i \neq X_j \\
	\end{cases}
	$$

- Custo $O(m \times n)$

---

## Q7

![[Pasted image 20251027165436.png]]

- Comprimento da Menor Supersequência Comum (MSC)

- **Método 1**:
	O tamanho da MSC pode ser encontrado somando o tamanho da sequência $X$ com a sequência $Y$ e subtrair da LCS de $X$ e $Y$, isto é:
	
	$$
	\text{Tamanho da Menor Supersequência Comum} = |X| + |Y| - |LCS(X, Y))|
	$$
	
	
- **Método 2**:
	
	$$
	MSC(i, j) = 
	\begin{cases}
	0 & , \text{ se } \ i = 0 \land j = 0 \\
	i & , \text{ se } \ j = 0 \\
	j & , \text{ se } \ i = 0 \\
	1 + MSC(i - 1, j - 1) & , \text{ se } \ X_i = X_j \\
	1 + min\{MSC(i, j - 1), MSC(i - 1, j)\} &, \text{ caso contrário}
	\end{cases}
	$$
	
	Se os caracteres são iguais, eles fazem parte da supersequência.
	Caso contrário, precisamos **incluir um novo caractere** de uma das sequências e escolher o caminho mínimo

- Custo $O(|X| \times |Y|)$.

---

## Q8

![[Pasted image 20251027165445.png]]

- Maior subsequência crescente.

- Semelhante a Q1, mas nesse caso não queremos o tamanho da LIS e sim a própria sequência.

- Analisar cada elemento em relação aos anteriores. Se $X_i$ for maior que algum elemento anterior $X_j$, então atualiza-se o valor de $LIS[i] = LIS[j] + 1$; caso contrário, mantém-se o valor inicial. O processo é repetido para todos os elementos da sequência, partindo de um vetor inicializado com $1$ (ou $-\infty$, dependendo da modelagem).

- Para também recuperar a subsequência propriamente dita, mantém-se um vetor auxiliar `prev[i]`, que armazena o índice do elemento anterior na subsequência ótima terminando em $X_i$. Ao final do preenchimento, identifica-se o índice `end` que contém o maior valor em `LIS`, e reconstrói-se a sequência percorrendo `prev[end]` recursivamente (ou iterativamente) até o início da subsequência.

```c
int lis_iterative_sequence(int n, int* x, int** seq_out, int* seq_len)
{
    if (n == 0) {
        *seq_out = NULL;
        *seq_len = 0;
        return 0;
    }
	
    int* dp = (int*) malloc(n * sizeof(int));
    int* prev = (int*) malloc(n * sizeof(int));
	
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
	
    int best = 1;
    int end = 0;
	
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (x[j] <= x[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j; // guarda o anterior
            }
        }
        if (dp[i] > best) {
            best = dp[i];
            end = i;
        }
    }
	
    // reconstrução da sequência
    *seq_len = best;
    *seq_out = (int*) malloc(best * sizeof(int));
    
    int idx = best - 1;
    for (int i = end; i != -1; i = prev[i]) {
        (*seq_out)[idx--] = x[i];
    }
    
    return best;
}
```

- Custo $O(n^2)$.

---
Vinícius Miranda de Araújo
