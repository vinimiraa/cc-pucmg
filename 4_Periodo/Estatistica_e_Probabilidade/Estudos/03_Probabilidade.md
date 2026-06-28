# Probabilidade

## **Conceitos**

### Experimento aleatório (E)

Situação em que os **resultados possíveis são conhecidos, mas não sabemos a priori qual deles ocorrerá**. Além disso, os experimentos aleatórios **podem ser repetidos indefinidamente sob as mesmas condições**.

Exemplo: Lançar um dado.

### Espaço amostral (S)

Conjunto de **todos os resultados possíveis de um experimento aleatório**.

Exemplo: $S = \{1, 2, 3, 4, 5, 6\}$

### Evento (A)

Subconjunto do espaço amostral que contém apenas os elementos de interesse. Um evento deve ser representado sempre por letras maiúsculas.

Exemplo: $A = \{\text{Obter\ um\ número\ par}\} = \{2, 4, 6\}$


## **Cálculo de Probabilidades**

### Definição Clássica

Se os **eventos são equiprováveis** (têm a mesma probabilidade de ocorrer), podemos calcular $P(A)$ (onde $A$ é um evento qualquer) como: 

$$
P(A) = \frac{\text{n°\ de\ resultados\ favoráveis\ à\ ocorrêcia\ do\ evento\ A}}{\text{n°\ de\ resultados\ possíveis}}
$$

### Definição Frequentista

Se os **eventos simples não são equiprováveis** (não têm a mesma probabilidade de ocorrer), podemos calcular $P(A)$ (onde $A$ é um evento qualquer) como:

$$
P(A) = \frac{\text{n°\ de\ vezes\ que\ o\ evento\ A\ ocorreu}}{\text{n°\ total\ de\ repetições\ do\ experimento}}
$$


## **Tipos de Eventos Especiais**

### Evento Interseção

É a ocorrência simultânea dos eventos $A$ e $B$  $\Rightarrow$ $A \cap B$

![[evento_intersecao.png | 350]]

### Evento União

É a ocorrência de $A$ ou de $B$, ou de ambos $\Rightarrow$ $A \cup B$.

![[evento_uniao.png | 350]]

### Evento Complementar

O complementar do evento A contém todos os elementos do espaço amostral que não pertencem ao evento $A \Rightarrow \overline{A}\ OU\ A^c$. 

![[evento_complementar.png | 350]]

### Evento Mutuamente Excludente (ou Disjuntos)

Quando a ocorrência de um impossibilita a ocorrência do outro, ou seja, $A \cap B = \emptyset$.

![[evento_mutuamente_exclusivo.png | 350]]


## **Regras de Probabilidade**

### Regra da Adição

Para quaisquer dois eventos $A$ e $B$:

$$
P(A \cup B) = P(A) + P(B) - P(A \cap B)
$$

Se $A$ e $B$ forem mutuamente excludentes, então:

$$
P(A \cup B) = P(A) + P(B)
$$

### Regra da Multiplicação

Para quaisquer dois eventos $A$ e $B$:

$$
P(A \cap B) = P(A) \cdot P(B|A)
$$

Se $A$ e $B$ forem independentes, então:

$$
P(A \cap B) = P(A) \cdot P(B)
$$

### Evento Complementar

Se $A$ é um evento, seu complementar é denotado por $A^c$. Então:

$$
P(A^c) = 1 - P(A)
$$

### Probabilidade Condicional

Probabilidade de ocorrência de um evento $A$ dado que $B$ ocorreu:

$$
P(A|B) = \frac{P(A \cap B)}{P(B)} \quad \text{(desde que } P(B) > 0)
$$

### Independência

Dois eventos $A$ e $B$ são **independentes** se o fato de um deles ter ocorrido não altera a probabilidade de ocorrência de outro, isto é:

$$
P(A|B) = P(A) \text{ e } P(B|A) = P(B)
$$

Pela regra da multiplicação:

$$P(A \cap B) = P(A) \cdot P(B)$$


## **Teorema de Bayes**

É utilizado quando se conhece a probabilidade de um evento condicional e deseja-se inverter essa condição.

### Fórmula:

$$
P(B_i | A) = \frac{P(A | B_i) \cdot P(B_i)}{\sum_{j=1}^{n} P(A | B_j) \cdot P(B_j)}
$$

Onde:

- ${B_1, B_2, ..., B_n}$ é uma partição do espaço amostral
    
- $P(B_i)$ são as probabilidades a priori
    
- $P(A | B_i)$ são as verossimilhanças
    
- $P(B_i | A)$ é a **probabilidade a posteriori**


> [!TIP] Dica
> Tem a mesma lógica do **Algoritmo de Naives Bayes** ~~(quem imaginaria?!)~~.
