
## 1. Limite

### 1.1 Definição

$\lim_{x \to a} f(x) = L$, significa limite de $f(x)$ quando $x$ tende a $a$ é igual a $L$.

### 1.2 Limites Laterais

$\lim_{x \to a^-} f(x) = L$, significa limite de $f(x)$ quando $x$ tende a $a$ pela esquerda é igual a $L$.

$\lim_{x \to a^+} f(x) = L$, significa limite de $f(x)$ quando $x$ tende a $a$ pela direita é igual a $L$.

### 1.3 Existência do Limite

$\lim_{x \to a} f(x) = L$ se e somente se $\lim_{x \to a^-} f(x) = L$ e $\lim_{x \to a^+} f(x) = L$

### 1.4 Assíntota Vertical

Acontece quando: $\lim_{x \to a} f(x) = \pm \infty$, logo $\lim_{x \to a^-} f(x) = \lim_{x \to a^+} f(x) = \pm \infty$

### 1.5 Assíntota Horizontal

Acontece quando: $\lim_{x \to \infty} f(x) = a$, logo $\lim_{x \to \infty^-} f(x) = \lim_{x \to \infty^+} f(x) = a$

---

## 2. Função Contínua

Uma função é contínua em um número se: $\lim_{x \to a} f(x) = f(a)$. Implicitamente:
1. $f(a)$ está definido
2. $\lim_{x \to a} f(x)$ existe
3. $\lim_{x \to a} f(x) = f(a)$

Uma função $f$ é contínua em um intervalo se for contínua em todos os números do intervalo. Se $f$ for definido somente de um lado da extremidade do intervalo, entende-se continuidade na extremidade como continuidade à direita ou à esquerda.

> Teorema:
> São funções contínuas: as polinomiais, trigonométricas, exponenciais, racionais, logarítmicas e raízes.

---

## 3. Derivadas

A reta tangente à curva y = f(x) em um ponto P(a, f(a)) é a reta que por P com a inclinação:

$$m = \lim_{x \to a} \frac{f(x) - f(a)}{x - a}$$

Isto é, calcular o coeficiente angular da reta tangente ao gráfico da função no ponto é calcular a derivada no ponto.