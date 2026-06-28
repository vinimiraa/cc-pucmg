# Resumo: Isomorfismo e mais conceitos

## Isomorfismo

- Dois grafos $G$ e $H$ são ditos isomorfos se existir uma correspondência um-para-um ($1:1$) entre seus vértices e entre suas arestas, de maneira que as **relações de incidência são preservadas**.
	
- Condições **necessárias mas não suficientes** para que $G$ e $H$ sejam isomorfos: 
	
	- Mesmo número de vértices. 
		
	- Mesmo número de arestas.
		
	- Mesmo número de componentes.
		
	- Mesmo número de vértices com o mesmo grau.
	
- Não existe algoritmo eficiente para determinar se dois grafos são isomorfos.

## Conceitos

- **Grafo Complementar**:
	
	- Seja $G = (V, E)$ um grafo simples direcionado ou não-direcionado. O grafo complementar de $G$, denotado por $C(G)$ ou $\overline{G}$, é um grafo formado da seguinte maneira:
		
		- Os vértices de $C(G)$ são todos os vértices de $G$.
			
		- As arestas de $C(G)$ são exatamente as arestas que faltam em $G$ para formarmos um grafo completo.
	
- **Subgrafo**:
	
	- Um grafo $G' = (V' , E')$ é dito ser subgrafo de um grafo $G = (V, E)$ quando $V' \subset V$ e $E' \subset E$.
	
	- **Subgrafo Induzido**:
		
		- Se $G_2 = (V_2, E_2)$ é um subgrafo de $G_1 = (V_1, E_1)$ e possui toda aresta $(v,w)$ de $G_1$ tal que ambos, $v$ e $w$, estejam em $V_2$, então $G_2$ é o subgrafo induzido pelo subconjunto de vértices $V_2$.
		
		> Isto é, um subgrafo que preserva todas as arestas do grafo original que conectam os vértices escolhidos.
		
	- Um grafo $H$ é dito ser um subgrafo de um grafo $G \ (H \subseteq G)$ se todos os vértices e todas as arestas de $g$ estão em $G$:
		
		- Todo grafo é subgrafo de si próprio.
			
		- O subgrafo de um subgrafo de $G$ é subgrafo de $G$.
			
		- Um vértice simples de $G$ é um subgrafo de $G$.
			
		- Uma aresta simples de $G$ (juntamente com suas extremidades) é subgrafo de $G$.
		
	- **Subgrafos Disjuntos de Arestas**:
		
		- Dois (ou mais) subgrafos $G_1$ e $G_2$ de um grafo $G$ são disjuntos de arestas se $G_1$ e $G_2$ não tiverem nenhuma aresta em comum. 
		
	- **Subgrafos Disjuntos de Vértices**:
		
		- Dois (ou mais) subgrafos $G_1$ e $G_2$ de um grafo $G$ são disjuntos de vértices se $G_1$ e $G_2$ não tiverem nenhum vértice em comum. 

### Caminhos e Circuitos

- **Sequência de Arestas**:
	
	- Sequência alternada de vértices e arestas começando e terminando com vértice. Cada aresta é incidente ao vértice que a precede e a antecede.
	
- **Caminho**:
	
	- Sequência de arestas no qual nenhuma aresta aparece mais de uma vez.
		
		- **Caminho aberto**:
			
			- Vértice inicial é diferente do vértice final.
			
		- **Caminho fechado**: 
			
			- Caminhos que começam e terminam no mesmo vértice.
	
- **Teorema**:
	
	- Se um grafo possui exatamente 2 vértices de grau ímpar, existe uma aresta entre esses dois vértices.
	
- **Teorema**:
	
	- Um grafo simples com $n$ vértices e $k$ componentes possui no máximo $\frac{(n − k)(n − k + 1)}{2}$ arestas.
	
- **Teorema**:
	
	- O número mínimo de arestas de um grafo simples com $n$ vértices e $k$ componentes é $n − k$.

---
FIM