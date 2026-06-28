# **Distribuições Discretas de Probabilidade**

## **Conceitos**

### Variável Aleatória

Uma **variável aleatória (v.a.)** é uma função que associa a cada elemento do espaço amostral um número real. Pode ser:

- **Discreta**: assume valores isolados (como 0, 1, 2, ...).
    
- **Contínua**: assume valores em um intervalo da reta real.

### Distribuição de Probabilidade

Para variáveis discretas, a **função de probabilidade** associa a cada valor $x_i$ da variável a probabilidade $P(X = x_i)$ ou $p(x)$.

Propriedades:

1. $0 \leq p(x) \leq 1$
    
2. $\sum p(x) = 1$

### Distribuição Acumulada

A função de distribuição acumulada (ou função de probabilidade acumulada), denotada por $F(X)$, fornece a probabilidade de a v.a. $X$ apresentar valores menores ou iguais a $x$, ou seja:

$$
F(x) = P(X \leq x) = \sum_{t \leq x} p(t)
$$

### Valor Esperado

É a **média teórica** da variável aleatória:

$$
\mu = E(X) = \sum_{i = 1}^{n} x_i \cdot p(x_i)
$$

### Variância e Desvio Padrão

A **variância** mede a dispersão dos valores em relação à média:

$$
\sigma^2 = Var(X) = \sum_{i = 1}^{n} (x_i - \mu)^2 \cdot p(x_i)
$$

Desenvolvendo a expressão acima:

$$
\sigma^2 = Var(X) = E(X^2) - \mu^2
$$

O **desvio padrão** é a raiz quadrada da variância:

$$
\sigma = \sqrt{Var(X)}
$$


## **Distribuição Binomial**

Modela o número de sucessos em $n$ tentativas independentes, onde a probabilidade de sucesso é $p$ e de fracasso é $q=1−p$.

- **Notação**: $X \sim Bin(n, p)$
    
- **Função de probabilidade**:
    
    $$P(X = x) = \binom{n}{x} p^x \cdot (1 - p)^{n - x}, \quad x = 0, 1, \ldots, n$$
    
- **Parâmetros**:
    
    - $n$: número de tentativas
        
    - $p$: probabilidade de sucesso
		
	- $q$: probabilidade de fracasso, $q = 1 - p$
		
	- $$\binom{n}{x} = \frac{n!}{x!(n - x)!}$$
    
- **Esperança**: $E(X) = n \cdot p$
    
- **Variância**: $V(X) = n \cdot p \cdot (1 - p)$


## **Distribuição de Poisson**

Modela o número de ocorrências de um evento em um intervalo fixo de tempo ou espaço, quando os eventos ocorrem com uma taxa média $\lambda$ constante e independentemente entre si.

- **Notação**: $X \sim Po(\lambda)$
    
- **Função de probabilidade**:
    
    $$P(X = x) = \frac{e^{-\lambda} \lambda^x}{x!}, \quad x = 0, 1, 2, \ldots$$
    
- **Parâmetro**: $\lambda$: taxa média de ocorrência
    
- **Esperança e Variância**: $E(X) = V(X) = \lambda$


## **Distribuição Hipergeométrica**

Modela a probabilidade de se obter $x$ sucessos em $n$ extrações **sem reposição**, a partir de uma população finita de $N$ elementos, onde $r$ são considerados sucessos.

- **Notação**: $X \sim Hip(N, r, n)$
    
- **Função de probabilidade**:
    
    $$P(X = x) = \frac{\binom{r}{x} \binom{N - r}{n - x}}{\binom{N}{n}}, \quad x = 0, 1, 2, \ldots, \min(n, r)$$
    
- **Parâmetros**:
    
    - $N$: tamanho da população
		
	- $n$: tamanho da amostra
        
    - $r$: número de elementos de sucesso na população
        
- **Esperança**: 
	
	$$E(X) = n \cdot p, \text{ onde } p = \frac{r}{N}$$
    
- **Variância**:
    
    $$V(X) = n \cdot p \cdot (1 - p) \cdot \frac{N - n}{N - 1}, \text{ onde } p = \frac{r}{N}$$
