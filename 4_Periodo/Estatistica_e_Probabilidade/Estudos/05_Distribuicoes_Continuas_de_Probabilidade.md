# **Distribuições Contínuas de Probabilidade**

## **Conceitos**

- **Variável Aleatória Contínua:**  
    Uma variável que assume qualquer valor dentro de um intervalo dos números reais.
    
- **Função Densidade de Probabilidade (f.d.p.):**  
    Uma função $f(x)$ é uma f.d.p. se:
    
    - $f(x) \geq 0, \; \forall x$
        
    - $\int_{-\infty}^{\infty} f(x) dx = 1$
        
    - $P(a \leq X \leq b) = \int_{a}^{b} f(x)dx$
        
- **Função de Distribuição Acumulada (F.D.A.):**  
    
    $$F(x) = P(X \leq x) = \int_{-\infty}^{x} f(x)dx$$
    
- **Esperança (Média) de $X$:**  

    $$E(X) = \mu = \int_{-\infty}^{\infty} x f(x) dx$$
    
- **Variância de $X$:**  
	
	$$Var(X) = \sigma^2 = E(X^2) - [E(X)]^2$$

## **Distribuição Uniforme**

- $X \sim U(\alpha, \beta)$
    
- A variável $X$ tem a mesma probabilidade em qualquer ponto do intervalo $[\alpha, \beta]$.

### Função Densidade de Probabilidade:

$$f(x) = \begin{cases} \frac{1}{\beta - \alpha}, & \alpha \leq x \leq \beta \\ 0, & \text{caso contrário} \end{cases}$$

> Observação: $k \times (\beta - \alpha) = 1 \implies k = \frac{1}{\beta - \alpha}$

### Resumo

| Situação                                      | Fórmula                                                                   |
| --------------------------------------------- | ------------------------------------------------------------------------- |
| Função Densidade de Probabilidade (f.d.p.)    | $f(x) = \frac{1}{\beta - \alpha}$, se $\alpha \leq x \leq \beta$          |
| Probabilidade entre dois valores $[x_1, x_2]$ | $P(x_1 \leq X \leq x_2) = \frac{x_2 - x_1}{\beta - \alpha}$               |
| Valor Esperado (Média)                        | $E(X) = \frac{\alpha + \beta}{2}$                                         |
| Variância                                     | $Var(X) = \frac{(\beta - \alpha)^2}{12}$                                  |
| Função de Distribuição Acumulada (F.D.A.)     | $F(x) = \frac{x - \alpha}{\beta - \alpha}$, se $\alpha \leq x \leq \beta$ |

## **Distribuição Exponencial**

- Modelo clássico para descrever **tempo até a ocorrência de um evento**.
    
- $X \sim Exp(\lambda)$

### Função de Densidade de Probabilidade

$$f(x) = \lambda e^{-\lambda x},\; x \geq 0$$

### Função de Distribuição Acumulada (F.D.A.)

$$F(x) = P(X \leq x) = 1 - e^{-\lambda x}$$
### Probabilidade do Tempo Ser Maior que $x$

$$P(X > x) = e^{-\lambda x}$$

### Probabilidade Entre Dois Tempos $[a, b]$

$$P(a \leq X \leq b) = e^{-\lambda a} - e^{-\lambda b}$$

### Resumo

| Situação                                                        | Fórmula                           |
| --------------------------------------------------------------- | --------------------------------- |
| Probabilidade do evento ocorrer até $x$ (antes ou no tempo $x$) | $1 - e^{-\lambda x}$              |
| Probabilidade do evento não ocorrer até $x$ (após o tempo $x$)  | $e^{-\lambda x}$                  |
| Probabilidade do evento ocorrer entre os tempos $a$ e $b$       | $e^{-\lambda a} - e^{-\lambda b}$ |
| Probabilidade do evento ocorrer no instante $x$                 | $\lambda e^{-\lambda x}$          |
| Valor esperado (tempo médio até o evento)                       | $\frac{1}{\lambda}$               |
| Variância do tempo até o evento                                 | $\frac{1}{\lambda^2}$             |

### Propriedade Sem Memória:

Seja $X \sim Exp(\lambda)$, então:  

$$P(X > s + t \mid X > s) = P(X > t)$$

> Ou seja, **o tempo adicional de espera é independente do tempo já decorrido**.

## **Distribuição Normal**

- A mais importante da estatística.
    
- Notação: $X \sim N(\mu, \sigma^2)$

### Características

- Curva **simétrica** em relação à média $\mu$.
    
- Área total sob a curva = 1.
    
- Pontos de inflexão em $\mu - \sigma$ e $\mu + \sigma$.
    
- O pico ocorre em $x = \mu$.

### Padronização (Distribuição Normal Padrão)

Quando $\mu = 0$ e $\sigma = 1$, temos $Z \sim N(0, 1)$.

$$Z = \frac{X - \mu}{\sigma}$$

### Passo a Passo:

1. Desenhar a curva normal e identificar a área de interesse.
    
2. Calcular $Z$.
    
3. Consultar a tabela de valores de $Z$ (Tabela Normal).
    
4. Interpretar o resultado (lembrar do ajuste conforme a tabela utilizada).