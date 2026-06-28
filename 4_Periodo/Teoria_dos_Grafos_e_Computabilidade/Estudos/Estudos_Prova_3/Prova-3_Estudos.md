# Estudos: Prova 3

## Grafo Planar

- Se é possível desenhar um grafo de maneira que nenhuma aresta se cruza, então o grafo é planar.
- Quando o grafo é desenhado sem cruzamento de arestas, os vértices e arestas dividem o grafo em regiões. Cada região é chamada de **face**.
	- O número de faces não muda independente da maneira que o grafo é desenhado, contanto que não haja cruzamento de arestas.
- Para qualquer **grafo planar (conectado)** com $v$ vértices, $e$ arestas e $f$ faces, temos:
	$$v - e + f = 2$$
- Teorema de Fáry:
	- Todo o grafo planar (simples) pode ser desenhado sem cruzamento e com segmentos de reta.

## Grafo Não-Planar

- Maiorias dos grafos não tem uma representação de um grafo planar.
- Se existir um $K_5$ ou um $K_{3,3}$ no grafo original, então o grafo é não-planar.

## Grafo Homeomórfico

Recall that a graph G 0 is a subgraph of G if it can be obtained by deleting some vertices and/or edges of G.

> Smoothing of the pair of edges {a, b} and {b, c}, in which the degree of vertex b is equal to 2, means to remove these two edges, and add {a, c}.

## Teorema de Kuratowski

- O teorema de Kuratowski diz que um grafo é planar se e somente se não contém um subgrafo que é homeomórfico à $K_5$ ou $K_{3,3}$.

> What this really means is that every non-planar graph has some smoothing that contains a copy of K5 or K3,3 somewhere inside it.

## Teorema de Wagner

- The Wagner’s therorem says that a graph has planar embedding, if, and only if, it contains no minor isomorphic to K5 or K3,3.
- A contraction of G is a graph obtained from G by repeated edge contractions. A minor of G is any subgraph of a contraction of G.

## Grafo Dual

![[Pasted image 20250620154532.png]]

## Coloração em Grafo

- Color it so that adjacent regions are colored differently.
- There are some algorithms that are efficient, but not optimal to compute a vertex coloring (that is proper too as defined).

> **Teorema das 4 Cores**
> 
> - It turns out that the is no map that needs more than 4 colors . 
> - This is the famous Four Colour Theorem , which was originally conjectured by the British/South African mathematician and botanist, Francis Guthrie who at the time was a student at University College London

### Coloração em Vértices

- Thanks to the geometric duality , coloring regions of a map corresponds to coloring vertices of the graph. I Vertex Coloring An assignment of colors to the vertices of a graph; I Proper Coloring If the vertex coloring has the property that adjacent vertices are colored differently.
- If the graph has v vertices, the clearly at most v colours are needed. However, usually, we need far fewer .

### Coloração em Arestas

- Let G = (V, E) be a undirected connected graph. The graph G is K-edge-colorable if the edges can be colored by using K colors;

### Clique

- The clique number of a graph, G = (V, E), is the number of vertices in the largest clique in G.

## Grafo Linha

- Let G = (V, E) be a undirected connected graph. A line graph L(G) is defined as follows: 
	1. The vertices of L(G) are the edges of G; 
	2. Two vertices are adjacent in L(G) if their corresponding edges in G are adjacent.