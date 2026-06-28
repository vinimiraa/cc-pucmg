- Longest Commom Subsequence (LCS) Não Consecutiva

$$
dp[i][j] = 
\begin{cases}
0 &, \text{ se } i = 0 \\
0 &, \text{ se } j = 0 \\
1 + dp[i-1][j-1] &, \text{ se } i,j > 0 \text{ e } X_{i-1} = Y_{j-1} \\
\max \big(dp[i-1][j], dp[i][j-1] \big) &, \text{ se } i,j > 0 \text{ e } X_{i-1} \ne Y_{j-1} \\
\end{cases}
$$

---
- Longest Commom Subsequence (LCS) Consecutiva

$$
dp[i][j] = 
\begin{cases}
0 &, \text{ se } i = 0 \\
0 &, \text{ se } j = 0 \\
1 + dp[i-1][j-1] &, \text{ se } X_{i-1} = Y_{j-1} \\
0 &, \text{ se } X_{i-1} \ne Y_{j-1} \\
\end{cases}
$$

---
- Menor Supersequência Comum (MSC):

$$
dp[i][j] = 
\begin{cases}
0 & , \text{ se } \ i = 0 \land j = 0 \\
i & , \text{ se } \ j = 0 \\
j & , \text{ se } \ i = 0 \\
1 + dp[i-1][j-1] & , \text{ se } \ X_i = X_j \\
1 + \min \big(dp[i][j-1], dp[i-1][j]\big) &, \text{ caso contrário}
\end{cases}
$$
ou
$$|MSC(X,Y)| = |X| + |Y| - |LCS(X, Y))|$$

---
- Maior Subquência Palindrômica:

$$
MSP(X) = LCS(X, inverso(X))
$$

---
- Subsequência contínua de soma máxima (Maximum Subarray Problem):

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

---
- Problema do Troco (Coin Change)
	
	- Número mínimo de moedas
	
	$$
	M(S) = 
	\begin{cases} 
	0 &, \text{ se } S = 0 \\ 
	\min \limits_{c_i \le S} \big( 1 + M(S - c_i) \big) &, \text{ se } S > 0 
	\end{cases}
	$$
	
	- Número de combinações possíveis
	
	$$
	M(S) = 
	\begin{cases} 
	0 &, \text{ se } S = 0 \\ 
	\sum \limits_{c_i \le S} M(S - c_i) &, \text{ se } S > 0 
	\end{cases}
	$$

---
- Distância de Levenshtein:

$$
dp[i][j] = 
\begin{cases}
0 &, \text{ se } i = 0 \\
0 &, \text{ se } j = 0 \\
dp[i-1][j-1] &, \text{ se } i,j > 0 \text{ e } X_{i-1} = Y_{j-1} \\
1 + \min 
\begin{cases}
dp[i-1][j] \\
dp[i][j-1] \\
dp[i-1][j-1] \\
\end{cases} 
&, \text{ se } i,j > 0 \text{ e } X_{i-1} \ne Y_{j-1}
\end{cases}
$$

---
- Problema dos Parêntesis na Divisão:

$$
M[X_i, X_j] = 
\begin{cases}
X_i &, i = j \\
- &, i > j \\
\max \big( \frac{M[X_i, X_k]}{m[X_{k+1}, X_j]} \big) & , i \leq k < j
\end{cases}
$$

$$
m[X_i, X_j] = 
\begin{cases}
X_i &, i = j \\
- &, i > j \\
\max \big( \frac{m[X_i, X_k]}{m[X_{k+1}, X_j]} \big) &, i \leq k < j
\end{cases}
$$

---
- Problema do Escalonamento de Intervalos Ponderados:

$$
M[j]=
\begin{cases}
0 &, \text{ se } j = 0 \\
\max( v_j​ + M[p(j)], M[j−1] )​ &, \text{ se } j \ge i
\end{cases}
​$$

---
- Longest Increasing Subsequence (LIS):

$$
LIS[i]=
\begin{cases}
%1 &, \text{ se } i = 1 \\%
1 + LIS[j] &, \text{ se } j < i \text{ e } X_i \leq X_j \text{ e } LIS[j]+1 > LIS[i] \\
1 &, \text{ caso contrário}
\end{cases}
​$$

