# **Árvore de Decisão**

## **Introdução**

O objetivo de uma árvore de decisão é "inferir" ou "descobrir" uma regra para resolver um problema.

- Exemplo: Determinar se um cliente vai ou não esperar por uma mesa em um restaurante, considerando diversas variáveis, como se ele está com fome, se é um cliente recorrente, entre outros fatores.
	
- É uma abordagem simples e de fácil interpretação.
	
- Navalha de *Occam*: quanto mais simples, melhor.

A complexidade de uma árvore de decisão é avaliada por:

- Número total de **nós**.
	
- Número total de **folhas**.
	
- **Profundidade** da árvore.
	
- Número de **atributos** utilizados.

Uma árvore de decisão pode ser interpretada como uma **disjunção de conjunções** de regras, onde cada caminho na árvore representa uma regra.

- **Árvore de Classificação**: Utilizada para tarefas de **classificação**.
	
- **Árvore de Regressão**: Utilizada para tarefas de **regressão**.


## **Estrutura**

- **Nós**: Representam os testes para variáveis.
	
- **Ramos**: Correspondem aos resultados dos testes.
	
- **Folhas**: Indicam a classificação final.


## **Como Gerar uma Árvore de Decisão**

### Definir os Conceitos do Problema

- Dado um conjunto de dados **D**, o objetivo é classificar as instâncias em categorias (classes).
	
- Cada instância é descrita por **atributos (features)** e uma **classe alvo**.
	
- O objetivo é construir uma **árvore de decisão** que **divide os dados** iterativamente até que todos os exemplos em um nó pertençam à mesma classe.

### Escolher o Melhor Atributo para Dividir os Dados

O processo de seleção de atributos em uma árvore de decisão é projetado para minimizar a profundidade da árvore final.

A ideia é escolher o atributo que mais contribui para uma classificação precisa dos exemplos.

Antes de escolher o melhor atributo deve-se realizar o pré-processamento dos dados [[03_Pre_Processamento_de_Dados]] para tirar qualquer erro nos dados que possam influenciar no modelo.

#### Ganho de Informação (*Information Gain - IG*)

O ganho de informação é medido com base na **Entropia** ($E$), que representa a incerteza do conjunto de dados. A entropia é derivada da teoria da informação e avalia a qualidade de uma divisão (*split*) dos dados.

A fórmula da entropia para um conjunto $S$ é:

$$
E(S) = - \sum_{i=1}^{c} p_i \log_2(p_i)
$$

onde:

- $p_i$: Probabilidade de um elemento pertencer à classe $i$, calculada como a razão entre o número de elementos da classe $i$ e o total de elementos no conjunto $S$.

- $\log_2(p_i)$: Logaritmo de base 2 da probabilidade $p_i$. A base 2 é usada porque a entropia é medida em “*bits*” na teoria da informação. 

- Sinal negativo $(-)$: Garante que a entropia seja positiva, já que logaritmos de probabilidades são números negativos (quando $p_i < 1$).

> [!IMPORTANT]
> Para que o ganho e a entropia estejam entre $0$ e $1$, a base do logaritmo deve ser igual ao número de classes.

- **Entropia alta**: Indica que as classes estão bem misturadas, ou seja, há maior incerteza. Isso reflete um conjunto de dados "impuro" em termos de classificação.
	
- **Entropia baixa**: Indica que o conjunto de dados é mais homogêneo. Se todos os exemplos em $S$ pertencem à mesma classe, a entropia será zero, representando total pureza e ausência de incerteza.

O **ganho de informação** de um atributo é calculado como:

$$
Ganho(atributo) = Entropia(classe) - Entropia(atributo)
$$

$$
Entropia(atributo) = \sum_{i=1}^{v} \frac{p_i+n_i}{p+n} I (\frac{p_i}{p+n}, \frac{n_i}{p_i+n_i})
$$

$$
I (\frac{p_i}{p+n}, \frac{n_i}{p_i+n_i}) = -\frac{p}{p+n} * \log_2(\frac{p}{p+n}) -\frac{n}{p+n} * \log_2(\frac{n}{p+n})
$$

> [!TIP]
> A heurística usada na função ESCOLHER-ATRIBUTO é simplesmente selecionar o **atributo** com o **maior ganho de informação**.

---
#### Índice de Gini

Outra métrica utilizada para medir a impureza de um nó:

$$
Gini(S) = 1 - \sum_{i=1}^{c} p_i^2
$$

Quanto menor o índice de Gini, mais puro é o nó.

### Construir Recursivamente a Árvore

O algoritmo ID3 segue uma abordagem recursiva para dividir os dados:

1. **Se todos os exemplos pertencem à mesma classe, crie um nó folha.**
    
2. **Caso contrário, escolha o melhor atributo** com base no **ganho de informação** (ou outra métrica, como Gini).
    
3. **Divida o conjunto de dados** em subconjuntos com base nos valores desse atributo.
    
4. **Para cada subconjunto, repita o processo recursivamente** até atingir um critério de parada.
    
5. **Se não houver atributos restantes, crie um nó folha com a classe mais frequente**.

### Critérios de Parada

A recursão pode ser interrompida se:

- Todos os exemplos em um nó pertencem à mesma classe.
	
- Não há mais atributos para dividir (neste caso, usa-se a classe mais frequente no nó como saída).
	
- Um limite de profundidade foi atingido.

### Poda da Árvore (Opcional)

Após a construção da árvore, pode-se realizar **poda** para evitar **overfitting**. Existem dois tipos principais:

- **Pré-poda**: Define critérios para interromper a construção antes que a árvore fique muito complexa.
	
- **Pós-poda**: Remove ramos que têm baixo impacto na classificação.


## **Como Funciona o Algoritmo**

A ideia principal do algoritmo é:

1. Escolher um atributo.
	
2. Expandir a árvore adicionando um ramo para cada valor do atributo.
	
3. Passar os exemplos para as folhas (considerando o valor do atributo escolhido).
	
4. Para cada folha:

    1. Se todos os exemplos pertencem à mesma classe, associar essa classe à folha.

    2. Caso contrário, repetir os passos 1 a 4.


## **Vantagens e Desvantagens**

### Vantagens

- **Flexibilidade**: Árvores de decisão não assumem nenhuma distribuição para os dados. Elas são métodos não paramétricos que dividem o espaço de objetos em subespaços, ajustando diferentes modelos a cada subespaço.
	
- **Seleção de atributos**: O processo de construção seleciona os atributos mais relevantes, tornando o modelo robusto contra atributos irrelevantes ou redundantes.
	
- **Interpretabilidade**: Decisões complexas podem ser aproximadas por uma série de decisões simples e locais, baseadas nos valores dos atributos.
	
- **Eficiência**: O algoritmo de aprendizado de árvore de decisão é guloso e segue uma abordagem de cima para baixo (*top-down*), usando a estratégia dividir para conquistar sem *backtracking*. Sua complexidade de tempo é linear em relação ao número de exemplos.

### Desvantagens

- **Valores ausentes**: Algoritmos precisam de mecanismos específicos para lidar com valores ausentes.
	
- **Atributos contínuos**: Ordenação pode ser um problema. Em grandes conjuntos de dados com muitos atributos contínuos, a ordenação pode consumir até 70% do tempo de indução da árvore.
	
- **Instabilidade**: Pequenas variações no conjunto de treinamento podem gerar grandes mudanças na árvore final. Inferências próximas às folhas tendem a ser menos confiáveis do que aquelas próximas à raiz.


## **Métricas de Avaliação**

- Em problemas de **classificação**, utiliza-se a **matriz de confusão**.  
	
- Em problemas de **agrupamento**, utilizam-se **métricas específicas**, como o *silhouette index*.
	
- Em problemas de **regressão**, utilizam-se métricas como:
	- *Mean squared error (MSE)*.
	- *Mean absolute error (MAE)*.
	- *Normalized MSE and MAE*.
	
- Em problemas de **associação**, utilizam-se **métricas como suporte, confiança, *lift*, entre outras**.

#### Avaliar pela Matriz de Confusão

- **Taxa de Verdadeiro Positivo (VP)**: Número de acertos do classificador para cada classe.
	
- **Taxa de Falso Negativo (FN)**: Número de erros do classificador para cada classe.
	
- **Taxa de Falso Positivo (FP)**: Instâncias que não pertencem à classe considerada, mas foram classificadas como tal.
	
- **Taxa de Verdadeiro Negativo (VN)**: Instâncias que pertencem à classe considerada, mas foram classificadas como não pertencentes.
	
- **Precisão**: Proporção de instâncias corretamente classificadas como pertencentes à classe em questão, dentre todas as classificadas nessa classe.
	
$$
Precision = \frac{VP}{VP+FP}
$$
	
- **Sensibilidade ou Recall**: Proporção de instâncias corretamente classificadas como pertencentes à classe em questão, dentre todas as que realmente pertencem à classe.
	
$$
Recall = \frac{VP}{VP+FN} = TVP
$$
	
- **Acurácia**: Proporção total de instâncias corretamente classificadas.
	
$$
Ac = \frac{VP + VN}{VP + VN + FP + FN}
$$
	
- **F-Measure ou F1 Score**: Média **harmônica** entre precisão e sensibilidade, atribuindo igual importância a ambas.
	
$$
F1 = \frac{2 * recall * precision}{recall + precision}
$$
	
- Para atribuir pesos diferentes a essas métricas:
	
$$
F1 = \frac{(w+1) * recall * precision}{recall + precision}
$$
