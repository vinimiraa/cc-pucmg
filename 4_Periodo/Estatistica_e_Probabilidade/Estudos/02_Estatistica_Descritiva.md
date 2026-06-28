# **Estatística Descritiva**

## **Tabela de Frequência**

Relaciona uma variável categórica com suas **frequências absolutas e relativas**.

### Construção para Variáveis Quantitativas 

1. Determinar o número de classes. Uma regra prática para determinar o número de classes é a seguinte: 
	
	$$
	\text{número de classes} = k = \sqrt{n}
	$$
	
	>É recomendado que o número de classes esteja entre 4 e 10. Também pode ser calculado através da fórmula de *Sturges*: $k = 1 + \log_2(n)$
	
2. Identifique o maior valor ($máx$) e o menor valor ($mín$) da amostra; 
	
3. Calcule a amplitude total dos dados ($a$): 
	
	$$
	a = \text{máx} - \text{mín}
	$$ 
	
4. Calcule o comprimento de cada intervalo, ou seja, a amplitude das classes ($h$): 
	
	$$
	h = \frac{a}{k} \rightarrow h = \frac{\text{amplitude}}{\text{número de classes}}
	$$
	
5. Arredonde o valor de $h$ conforme as regras de arredondamento. Este número deve ter a mesma quantidade de casas decimais dos dados da amostra;
	
6. Calcule os limites de cada intervalo: 
	- A primeira classe vai de $mín$ até $mín + h$; 
	- A segunda classe vai de $mín + h$ até $mín + 2*h$;
	- ...
	
7. Construa uma tabela de frequências com as seguintes colunas: 
	- Limites de cada intervalo: os intervalos são fechados à esquerda e abertos à direita. NOTAÇÃO: ⊢ 
	- Frequência absoluta de cada intervalo ($n_i$). 
	- Frequência relativa de cada intervalo ($f_i$). 
	- Frequência absoluta acumulada de cada intervalo ($N_i$); 
	- Frequência relativa acumulada de cada intervalo ($F_i$).


## **Representação gráfica de variáveis quantitativas**

### Histograma

Os dados apresentados no eixo das abscissas (eixo X) são numéricos e têm uma **ordem que deve ser obedecida rigorosamente**. Por ser um gráfico resultante da tabela de frequências, essa ordem é a mesma apresentada na tabela. **Os números devem, portanto, aparecer em sequência, quer existam ou não dados com determinados valores**. A **altura das barras pode representar tanto a frequência absoluta quanto a frequência relativa**.

[Tipos de Histograma e Histograma com Python](https://www.alura.com.br/artigos/o-que-e-um-histograma)

### Diagrama de Pontos

Permite a visualização dos aspectos gerais da distribuição da variável em estudo, tais como valores máximo e mínimo, valores mais frequentes, forma da distribuição (simétrica ou assimétrica), etc.

A construção do diagrama de pontos para um conjunto de dados consiste em:

1. Determinar os valores mínimo e máximo do conjunto de dados;
	
2. Com base nestes valores, estabelecer um eixo em escala conveniente;
	
3. Utilizando o eixo estabelecido em no tópico 2, para cada valor observado nos dados, marcar com pontos dispostos verticalmente, sua correspondente frequência

Exemplo:

![[exemplo_diagrama_de_pontos.png]]

### Diagrama de Ramos e Folhas

O diagrama de ramo-e-folhas fornece praticamente as mesmas informações que o histograma, mas com duas vantagens:

- É mais fácil de construir à mão;
	
- Apresenta mais informações, porque mostra os dados reais.

A construção do ramo-e-folhas para um conjunto de dados consiste em:

1. Dividir cada número do conjunto de dados em duas partes: uma composta por um ou mais dígitos iniciais (ramo) e outra composta pelo dígito restante (folha);
	
2. Traçar uma linha vertical e escrever o ramo, com a escala adotada, à esquerda; (opcional)
	
3. Colocar à direita da linha vertical o último algarismo de cada número observado. Estes números formarão as folhas do gráfico;
	
4. Escrever a unidade do ramo-e-folhas, também chamada de chave do gráfico.

Exemplo:

![[exemplo_diagrama_de_ramos_e_folhas.png | 300]]


## **Medidas de Tendência Central**

### Média ($\overline{x}$)

A média ($\overline{x}$) é o **valor que está no centro das distancias dos dados** e é obtido pela soma de todos os valores, dividida pelo número de valores (tamanho da amostra $n$).

$$
\overline{x} = \frac{x_1 + x_2 + x_3 + ... + x_n}{n} = \frac{\sum_{i=1}^{n} x_i}{n}
$$

### Mediana ($Me$)

A mediana ($Md$) é o **valor que está no centro do conjunto ordenado**, assim tem a mesma quantidade de valores acima e abaixo de si.

- Se $n$ ímpar: $$\text{mediana} = \frac{n+1}{2}$$
- Se $n$ par: $$\text{mediana} = \frac{\frac{n}{2} + (\frac{n}{2}+1)}{2}$$

### Moda ($Mo$)

A moda ($Mo$) é o **valor com a maior frequência** no conjunto de dados.

Um conjunto de dados pode ser:

- **Amodal**: não tem moda
	
- **Unimodal**: tem apenas uma moda
	
- **Bimodal**: tem duas modas
	
- **Multimodal**: tem mais de duas modas

### Ponto Médio ($Pm$)

O ponto médio ($Pm$) é **valor que está no centro da amplitude**.

$$
Pm = \frac{Xmáx +Xmin}{2}
$$

---
### Exemplo

Um instrutor registra a média de faltas de seus alunos em determinado semestre. Em uma amostra aleatória, os dados são:

> 2 4 2 0 40 2 4 3 6

**Média**: $\overline{x} = \frac{\sum x}{n}$    $\rightarrow$    $\sum x = 63$    $n = 9$    $\rightarrow$    $\overline x = \frac{63}{9} = 7$

**Mediana**: 
- Ordenar:
	>0 2 2 2 3 4 4 6 40
- 0 2 2 2 ==**3**== 4 4 6 40  $\rightarrow$  3

**Moda**: é 2, pois é o valor que ocorre mais vezes.

**Ponto Médio**: $Pm = \frac{(0 + 40)}{2} = 20$

---

## **Medidas Separatrizes**

### Quartis

Os quartis são pontos que dividem o conjunto de dados ordenados em quatro partes iguais, originando o 1º quartil ($Q_1$), o 2º quartil ($Q_2$) 3º quartil ($Q_3$). Assim:

![[representacao_quartis.png]]

Assim:

- 25 % dos dados estão abaixo de Q1
	
- 50 % dos dados estão abaixo de Q2
	
- 75 % dos dados estão abaixo de Q3

Para encontrar os quartis devemos:

1. Ordenar dos dados de forma crescente;
	
2. Encontrar a localização do quartil $k$, logo: 
	
	$$LQ_k = \frac{k * ( n + 1)}{4}$$
	
3. Se $LQ_k$ for inteiro, o quartil $k$ será o valor no posto $LQ_k$, casos contrário será a média ponderada dos dois valores mais próximos ao posto $LQ_k$.

> [!IMPORTANT] Importante
> A fórmula acima acha-se a **posição** do valor:
> 	
> - Se a **posição for um número inteiro**, então o **valor do quartil é o valor que está na posição** encontrada. 
> 	
> - Caso contrário, se o a **posição for um número real (fracionário)**, então o **valor do quartil será uma média** dos dois valores mais próximos.


## **Medidas de Variabilidade (ou Dispersão)**

### Amplitude da Amostra ($a$)

A amplitude é simplesmente a **diferença entre o maior e o menor valor**:

$$
a = \text{máx} - \text{mín}
$$

### Variância ($s^2$)

**Mede a variabilidade dos dados** através dos desvios em relação à média. *Desvio em relação à média* é a diferença entre cada valor observado e a média do conjunto de dados.

A notação é $s^2$ e é calculada como a soma dos desvios ao quadrado, dividida por $n-1$, ou seja,

$$
s^2 = \frac{\sum_{i=1}^{n}(x_i - \overline{x})^2}{n-1}
$$

O denominador $n-1$ é chamado *graus de liberdade da amostra*. Para calcular a variância da população (chamada $𝜎^2$), a soma dos desvios ao quadrado é dividida por $N$. 

### Desvio-Padrão ($s$)

O desvio-padrão é um valor que possui a mesma unidade de medida dos dados originais. Por definição, o **é a raiz quadrada, com sinal positivo, da variância**. O desvio-padrão da amostra é denotado por 𝑠 e pode ser calculado através da fórmula:

$$
s = \sqrt{\frac{\sum_{i=1}^{n}(x_i - \overline{x})^2}{n-1}} \rightarrow \sqrt{\text{variância}}
$$

### Coeficiente de Variação ($CV$)

O coeficiente de variação ($CV$) é um índice relativo de dispersão que compara o desvio-padrão ($s$) com a média ($\overline{x}$) e **fornece uma medida de homogeneidade dos dados**. É geralmente expresso em %, e é calculado pela fórmula:

$$
CV = \frac{s}{\overline{x}}*100 \rightarrow \frac{\text{desvio padrão}}{\text{média}}*100
$$

- Se $CV ≤ 20\%$ o conjunto é dito **homogêneo**;  
	
- Se $CV > 20\%$ o conjunto é dito **heterogêneo**.

### Amplitude Interquartílica ($AIQ$)

Também chamada de Distância Interquartílica, Amplitude Interquartil, Faixa Interquartil, Desvio Interquartílico

É calculada como a distância entre o $Q_3$ e o $Q_1$:

$$
AIQ = Q_3 - Q_1
$$

Como existem 50% dos valores entre o $Q_1$ e o $Q_3$, quanto maior o valor do $IQ$, maior a dispersão do conjunto de dados. A melhor forma de interpretar o $IQ$ é através do diagrama de caixa (*Boxplot*).


## **Diagrama de Caixa (*Boxplot*)**

O *boxplot* é um gráfico que **apresenta a dispersão do conjunto de dados**, através dos valores mínimo, máximo, primeiro quartil ($Q_1$), mediana ($Q_2$) e terceiro quartil ($Q_3$). Além disso, através deste gráfico é possível verificar se o conjunto de dados possui **valores atípicos (*outliers*)**, que podem afetar fortemente algumas medidas como média e desvio-padrão.

A construção do *boxplot* para um conjunto de dados consiste em:

1. Determinar o valores mínimo, $Q_1$, $Q_2$, $Q_3$, máximo e $AIQ$ do conjunto de dados;
	
2. Com base nestes valores, estabelecer um eixo em escala conveniente;
	
3. Construir um retângulo, iniciando no $Q_1$ e terminando no $Q_3$;
	
4. Trace uma linha dentro do retângulo, no valor do $Q_2$;
	
5. A partir do valor do $Q_1$, em direção ao mínimo, trace uma linha perpendicular à linha do $Q_1$. Essa linha irá terminar no valor mínimo ou no valor de $Q_1 – (1,5 * AIQ)$, o que ocorrer primeiro;
	
6. A partir do valor do $Q_3$, em direção ao máximo, trace uma linha perpendicular à linha do $Q_3$. Essa linha irá terminar no valor máximo ou no valor de $Q_3 + (1,5 * AIQ)$, o que ocorrer primeiro.
	
7. Marque os *outliers*, se houver. Um valor do conjunto de dados é um *outlier* se ele está:
	1. Abaixo de $Q_1 – (1,5 * AIQ)$;
	2. Acima de $Q_3 + (1,5 * AIQ)$.
	

> [!NOTE] Observação
> Para representar um *outlier*, normalmente é utilizado um asterisco (\*), um círculo (•) ou um "$x$".
> 
> Um valor que esteja a uma distância de mais de 3 vezes a amplitude interquartílica do $Q_1$ ou do $Q_3$ é chamado de ***outlier extremo***. Na construção do *boxplot*, símbolos diferentes podem ser usados para representar os dois tipos de *outliers*.
> 


![[exemplo_boxplot.png | 500]]
