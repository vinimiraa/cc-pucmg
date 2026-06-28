# Resumo: Conectividade em Grafos Direcionados e Não-Direcionados e Componentes Fortemente Conexos

## Fechos Transitivos

- De $v \in V$:
	
	- Direto:
		
		- Vértices alcançáveis de $v$, com caminho maior ou igual a zero (quem o $v$ chega).
		
	- Inverso:
		
		- Vértices que alcançam v, com caminho maior ou igual a zero (quem chega em $v$).
	
- De $X \subseteq V$:
	
	- Direto:
			
		- Vértices alcançáveis de cada vértice de $X$, com caminho maior ou igual a zero.
		
	- Inverso:
		
		- Vértices que alcançam algum vértice de X, com caminho maior ou igual a zero.

## Conectividade

- Definição:
	
	- Um grafo é dito **conexo** se **existe um caminho entre todo par de vértices**.
		
		- _Formalmente_: $\forall \ u,v \in V,\exists \ \text{path}(u,v)$.
		
	- Um grafo é dito **não conexo** (ou **desconexo**) se **existe pelo menos um par de vértices** entre os quais **não existe caminho**.
		
		- - _Formalmente_: $\exists\ u, v \in V,\ \nexists\ \text{caminho}(u, v)$.
	
- Grafo Não-Direcionado:
	
	- Conexo: 
		
		- Se **existe um caminho entre todo par de vértices**.
		
	- Não-Conexo:
		
		- Se **existe pelo menos um par de vértices** entre os quais **não existe caminho**. 
	
- Grafo Direcionado:
	
	- Fortemente Conexo:
		
		- Para todo par de vértice $u, v$ existe um caminho de $u$ para $v$ **E** de $v$ para $u$.
		
		- _Formalmente_: $\forall \ u,v \in V \mid \exists \ \text{path}(u,v) \text{ e } \text{path}(v,u)$.
		
	- Semi-Fortemente Conexo:
		
		- Para todo par de vértice $u, v$ existe um caminho de $u$ para $v$ **OU** de $v$ para $u$.
		
		-  _Formalmente_: $\forall \ u,v \in V \mid \exists \ \text{path}(u,v) \text{ ou } \text{path}(v,u)$.
		
	- Fracamente Conexo:
		
		- Existe pelo menos um par de vértice $u, v$ no qual não existe um caminho de $u$ para $v$ e nem de $v$ para $u$.
		
		-  _Formalmente_: $\exists \ u,v \in V \mid \nexists \ \text{path}(u,v) \text{ e } \nexists \ \text{path}(v,u)$.
		> $\exists \ u,v \in V \mid v \notin Γ^+(u) \text{ e } u \notin Γ^+(v)$.
		
		- Também é possível pegar o grafo associado, isto é o **grafo obtido desconsiderando a orientação de G**, e verificar se este é conexo:
			- Se o grafo associado for conexo, então o grafo original é fracamente conexo.
	
## Atingibilidade

- Base:
	
	- Um base $B$ de um grafo $G = (V, E)$ é um subconjunto $B \subseteq V$ se:
		
		1. Não há caminho entre vértices de $B$.
			
		2. Todo vértice não pertencente a $B$ pode ser **atingido** por algum vértice de $B$.
	
- Anti-Base: 
	
	- Uma anti-base $A$ de um grafo $G = (V, E)$ é um subconjunto $A \subseteq V$ se:
		
		1. Não há caminho entre vértices de $A$.
			
		2. Todo vértice não pertencente a $A$ pode atingir $A$ por um caminho.
	
- Raíz:
	
	- Sendo $B$ uma base de $G$, se $B$ for um **conjunto unitário**, então dizemos que $B$ **é a raíz** de $G$.
	
- Anti-Raíz:

	- Sendo $A$ uma anti-base de $G$, se $A$ for um **conjunto unitário**, então dizemos que $A$ **é a anti-raíz** de $G$.

## Componentes Fortemente Conexos (Strongly Connected Components - SCC)

A **partição** de um conjunto finito $V$ é um conjunto $P$ de subconjuntos disjuntos não vazios de $V$, cuja união é $V$, isto é:

$$
P = \{S_1, S_2, \cdots, S_k\} \ | \ \cup_{i=1}^{k} S_i = V \text{ e } S_i \cap S_j = \emptyset \ \forall \ i \neq j 
$$

Onde cada subconjunto Si é uma região da partição e, também, um **componente fortemente conexo**.

### Como Encontrar Componentes Fortemente Conexos (Algoritmo de Kosaraju)

Seja $G = (V, E)$ um grafo direcionado. Para identificar as **componentes fortemente conexas** de $G$:

1. Realizar uma busca em profundidade (**DFS**) a partir de um vértice arbitrário, registrando os **tempos de descoberta** e os **tempos de finalização** de cada vértice.
2. Construir o **grafo transposto** $G^- = (V, E')$, no qual, para cada aresta $e = (u, v) \in E$, adiciona-se a aresta reversa $e' = (v, u)$ em $E'$.
3. Realizar uma nova busca em profundidade sobre o grafo $G^-$, explorando os vértices na **ordem decrescente dos tempos de finalização** obtidos na primeira DFS.
	1. A cada nova chamada recursiva da DFS no grafo transposto, atribuir um **rótulo** ou identificador ao componente que está sendo explorada. Todos os vértices visitados nessa chamada pertencem ao **mesmo componente fortemente conexo**.
4. Ao final, o número total de componentes fortemente conexas corresponde ao **número de rótulos diferentes** atribuídos.

> [!NOTE] Observação
> Se o número de componentes fortemente conexas for igual ao número de vértices de $G$, então o grafo é acíclico.

---
FIM