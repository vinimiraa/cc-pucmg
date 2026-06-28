# Resumo: Conceitos Básicos e Definições

## Conceitos

- **Vértice**: 
	
	- Objeto simples que pode ter nomes e outros atributos.
	
- **Arestas**:
	
	- Conexão entre dois vértices. 
	
- **Grafo**: 
	
	- Coleção/relação de vértices e arestas.
	
- **Grafo Direcionado**:
	
	- Um grafo direcionado é par $G = (V,E)$, em que $V$ é um conjunto finito e $E$ é uma relação binária em $V$.
	
- **Grafo Não-direcionado**:
	
	- Um grafo não direcionado é um par $G = (V,E)$ em que o conjunto de arestas $E$ consiste em pares de vértices não orientados. A aresta $(v_i , v_j)$ e $(v_j , v_i)$ são consideradas a mesma aresta. 

> Um grafo $G = (V, E)$ em que $V$ é o conjunto de vértices e $E$ o conjunto de arestas de forma que:
> - $E = \{(u, v) \mid u, v ∈ V\}$ : grafo direcionado.
> - $E = \{\{u, v\} \mid u, v ∈ V\}$ : grafo não-direcionado.

## Terminologia

- ***Loop***:
	
	- Uma aresta associada ao par de vértices $(v_i , v_i)$.
	
- **Aresta Paralela**: 
	
	- Quando mais de uma aresta está associada ao mesmo par de vértices.
	
- **Grafo Simples**:
	
	- Um grafo que não possui loops e nem arestas paralelas.
	
- **Vértices Adjacentes**:
	
	- Dois vértices são ditos adjacentes se eles são pontos finais de uma mesma aresta.
	
- **Grau** ($\delta(v)$):
	
	- Grafo não-direcionado: 
		- Número de aresta de incidem em $v$.
		
	- Grafo direcionado: 
		- Grau de Entrada ($\delta^-(v)$): número de arestas que chegam em $v$.
		- Grau de Saída ($\delta^+(v)$): número de arestas que saem de $v$.
		
	 > Um laço (*loop*) conta duas vezes para o grau de um vértice
	
- **Arestas Adjacentes**:
	
	- Duas arestas não paralelas são adjacentes se elas são incidentes a um vértice comum.
	
- **Arestas Incidentes**:
	
	- Quando um vértice é uma das extremidades de uma aresta, então essa aresta é incidente ao vértice.
	
- **Grafo Regular**:
	
	- Um grafo no qual todos os vértices possuem o mesmo grau.
	
- **Vértice Isolado**:
	
	- Um vértice com nenhuma aresta incidente.
	
- **Vértice Pendente**:
	
	- Um vértice de grau igual a 1.
	
- **Grafo Nulo**:
	
	- Um grafo sem nenhuma aresta. Todos os vértices em um grafo nulo são vértices isolados.
	
- **Grafo Rotulado**:
	
	- Um grafo $G = (V,E)$ é dito ser rotulado em vértices (ou arestas) quando a cada vértice (ou aresta) estiver associado um rótulo.
	
- **Grafo Ponderado**:
	
	- Um grafo $G = (V,E)$ é dito ser ponderado quando existe uma ou mais funções relacionando $V$ e/ou $E$ com um conjunto de números.
	
- **Grafo Completo**:
	
	- Um grafo $G=(V,E)$ é completo se para cada par de vértices $v_i$ e $v_j$ existe uma aresta entre $v_i$ e $v_j$. Em um grafo completo quaisquer dois vértices distintos são adjacentes ($K_n$).
	
	> Seja $K_n$ um grafo completo com $n$ vértices. O número de arestas de um grafo completo é:
	> $$|E| = \frac{n \times (n-1)}{2}$$
	
- **Passeio** (*Walk* - $W$):
	
	- Um passeio é uma sequência finita de vértices e arestas: $(v_0, e_1, v_1, e_2, ..., v_{k-1}, e_k, v_k)$, onde:
		- $v_i \in V$ para todo $i = 0, 1, \cdots, k$.
		- $e_i \in E$ para todo $i = 1, 2, \cdots, k$.
		- A aresta $e_i$ conecta os vértices $v_{i-1}$ e $v_i$.
	
- **Trilha** (*Trail* - $T$): 
	
	-  Uma trilha é um passeio onde todas as arestas são distintas.
	
- **Caminho** (*Path* - $P$):
	
	- Um caminho é uma trilha onde todos os vértices são distintos.
	
- **Circuito/Ciclo** (*Cycle* - $C$):
	
	- Um circuito é um caminho fechado onde os vértices de origem e fim são iguais.
	
- **Grafo Bipartido**:
	
	- Um grafo é dito ser bipartido quando seu conjunto de vértices $V$ puder ser particionado em dois subconjuntos $V_1$ e $V_2$, tais que toda aresta de $G$ une um vértice de $V_1$ a outro de $V_2$.
	
- **Grafo Bipartido Completo**:
	
	- Um grafo é dito ser bipartido completo quando seu conjunto de vértices $V$ puder ser particionado em dois subconjuntos $V_1$ e $V_2$, tais que toda aresta de $G$ une um vértice de $V_1$ a outro de $V_2$, e que todo vértice de $V_1$ é adjacente a todo vértice de $V_2$.
	
	> Seja $K_{mn}$ um grafo bipartido completo com $n$ vértices em $V_1$ e $m$ vértices em $V_2$. O número de arestas de um grafo bipartido completo é:
	> $$|E| = n \times m$$

---
FIM