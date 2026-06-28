# Introdução

## Imagem Digital

- Uma imagem digital é uma matriz onde cada elemento (pixel) representa um nível de cinza ou cor
- O número de linhas e colunas da imagem determina sua ==resolução==. O número de tons de cinza ou cores determina sua ==quantização==
- Na imagem digital, tanto as coordenadas dos pixels quanto seus valores são números inteiros e não negativos. A intensidade pode as vezes ser normalizada entre 0 e 1, assumindo valores fracionários, embora não contínuos.

## Tamanho de uma Imagem sem Compressão

- Sendo: 
	- L o número de linhas 
	- C o número de colunas
	- N o número de tons distintos
	$$\text{Tamanho =} = \frac{L \times C \times lg(N)}{8 \text{ bytes}}$$

## Amostragem Espacial e Espectral

- Dada uma imagem $f(x,y)$, é necessário que seja digitalizada para ser processada.
	- A ==amostragem espacial== define sua resolução
	- A ==amostragem espectral== define sua quantização (número de tons/níveis de cinza (NC))
	- A quantização também pode ser definida pelo número de bits por pixel.

## O Processo de Visão Computacional Clássico

FALTANTE

---
# Geometria
## Transformações Geométricas

- Translação
	Move um ponto para um novo local adicionando valores de translação às coordenadas.
- Escala(r)
	Altera o tamanho do objeto multiplicando as coordenadas dos pontos por uma escala.
- Rotação
	Gira pontos por um ângulo $\theta$ em relação à origem ($\theta > 0$: rotação no sentido anti-horário)

## Composição de transformações

As matrizes de uma série de transformações podem ser concatenadas em uma única matriz

## Forma geral de uma matriz de transformação

Representar uma sequência de transformações como uma única matriz de transformação é mais eficiente!

## Casos especiais de transformação

- Transformações rígidas: Envolvem apenas translação e rotação (3 parâmetros)
	-  Preservar ângulos e comprimentos

- Transformações de similaridade: Envolvem translação, rotação e escala uniforme (4 parâmetros)
	- Preserva ângulos, mas não comprimentos.

- Transformações afins: Envolvem translação, rotação, escala e cisalhamento (shear) (6 parâmetros)
	- Preserva paralelismo de retas mas não ângulos nem comprimentos

## Cisalhamento

- Cisalhamento no eixo $x$:

$x' = x + ay$, $y' = y$

$$
SH_x =
\left[ \begin{array} & 1 & a & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{array} \right]
$$

- Cisalhamento no eixo $y$:

$y' = bx + y, x' = x$

$$
SH_x =
\left[ \begin{array} & 1 & 0 & 0 \\ b & 1 & 0 \\ 0 & 0 & 1 \end{array} \right]
$$

## Espelhamento ou Reflexão

FALTANTE

---
# Morfologia

## Imagens, objetos e elementos estruturantes

- Um objeto $A$ é um conjunto de pixels de frente (foreground=1) presente na imagem I. Os demais pixels de I são de fundo (background=0)
- Um elemento estruturante é um conjunto de pixels com valor de frente(1). Na sua representação matricial identificamos as demais posições como fundo(0), não pertencentes ao conjunto.
- Uma posição pode ser ainda associada a um *don't care* (X).

## Elementos estruturantes

- Um elemento estruturante pode ser refletido antes de ser usado em uma operação. Apenas os elementos de frente são considerados na operação, a não ser que seja especificado o contrário.

## Erosão

- A erosão é usada para encolher o elemento A usando o elemento B:


$$A \ominus B = \{z \mid (B)z \subseteq A\}$$

-  Esta equação indica que a erosão de A por B é o conjunto de todos os pontos z tal que B, transladado por z, está contido em A.

## Dilatação

- A dilatação é usada para expandir um elemento A usando a reflexão de um elemento estruturante B:

$$A \oplus B = \{z \mid (\hat{B})z \cap A \neq \emptyset \}$$
- A dilatação de A por B é o conjunto de todos os deslocamentos z, tal que A e o reflexo de B se sobrepõem por pelo menos um elemento de valor 1.

## Dualidade entre Dilatação e Erosão

- Dilatação e Erosão ==são duais== uma da outra no que diz respeito ==à complementação e reflexão== do conjunto:

$$(A \ominus B)^c = A^c \oplus \hat{B}$$

## Abertura e Fechamento

- Abertura:
	- Suaviza contornos, elimina saliências
- Fechamento: 
	- Suaviza seções de contornos, funde quebras estreitas e concavidades longas e finas, elimina pequenos orifícios e preenche lacunas em contornos

> Essas operações são duais entre si.


### Abertura

- Primeiro erodir A por B, e depois dilatar o resultado por B

$$A \cdot B = (A \ominus B) \oplus B$$

- Em outras palavras, a abertura é a unificação de todos os objetos B totalmente contidos em A

### Fechamento

- Primeiro dilatar A por B e, em seguida, erodir o resultado por B

$$A \cdot B = (A \oplus B) \ominus B$$

- Em outras palavras, o fechamento é o complemento da união de objetos B que não possuem interseção com o objeto A

## Extração de contorno

- Primeiro, erodir A por B, então fazer a diferença entre A e a erosão

	$$\beta(A) = A - (A \ominus B)$$

-  A espessura do contorno depende do tamanho do objeto de construção B

## Detecção de Padrões

- A transformada “Hit-or-Miss” utiliza uma versão estendida do elemento estruturante para localizar padrões.
- O elemento estruturante, neste caso, pode conter elementos de frente, fundo ou *don't cares*.

$$I \circledast B = \{ z \mid (B)_z \subseteq I \}$$

---
# Segmentação

- A etapa de segmentação objetiva particionar a imagem em regiões que representem os objetos da cena ou que possuam determinadas propriedades, como textura ou cor.

- As principais abordagens são:
	- Segmentação por região (ou segmentação por homogeneidade)
	- Segmentação por bordas ou contornos (ou segmentação por descontinuidade)

## Conectividade

- Dois pixels pertencem a uma região conectada se existir um caminho entre eles formado por pixels vizinhos

## Histogramas

- Demonstra a frequência de ocorrência dos valores de uma variável ou sua distribuição de probabilidades

## Segmentação por Região

- Limiarização: 
	- Consiste em utilizar o histograma para estabelecer valores de corte (limiar) que causam o particionamento da imagem em regiões. Quando apenas um valor de limiar for definido, teremos a binarização.
-  A limiarização deve ser seguida de um processo de rotulação uma vez que pode haver mais de um elemento conexo com mesmo valor de limiar, os quais serão considerados como objetos distintos. No caso da imagem conter apenas um objeto, o resultado da limiarização já estará segmentado.