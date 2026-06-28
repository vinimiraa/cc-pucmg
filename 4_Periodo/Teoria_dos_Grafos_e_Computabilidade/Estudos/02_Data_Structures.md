# Resumo: Estruturas de Dados

## Matriz de Incidência Nó-Arco

- Seja um grafo $G = (V, E)$ em que $|V| = n$ e $|E| = m$. Uma matriz de incidência $A_{n \times m}$ nó-arco é representada por:
	- Uma linha para cada nó.
	- Uma coluna para cada aresta.

![[matriz_de_incidencia.png]]

## Matriz de Adjacência

-  Seja um grafo $G = (V, E)$ em que $|V| = n$ e $|E| = m$. Uma matriz de adjacência $A_{n \times n}$ é representada por:
	- Uma linha para cada nó.
	- Uma coluna para cada nó.
	$$a_{ij} = \begin{cases} 1, (i, j) \in E \\ 0, (i, j) \notin E \end{cases}$$
![[matriz_de_adjacencia.png]]

## Lista de Adjacência

Seja um grafo $G = (V,A)$ em que $|V| = n$ e $|A| = m$. Uma lista de adjacência $A_{n \times n}$ é representada por uma lista de nós (ou vértices) em que cada nó aponta para a lista de seus sucessores (ou nós adjacentes).

![[lista_de_adjacencia.png]]

---
FIM