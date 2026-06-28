# Resumo: Caminhamento em Grafos

## Caminhamento

- Na **busca em profundidade**, deve-se caminhar no grafo visitando todos os seus vértices sempre procurando o vértice ==mais profundo==.

- Na **busca em largura**, deve-se expandir o conjunto de vértices de forma uniforme em que são visitados todos os vértices de ==mesma distância== ao início antes de visitar outros níveis.

### Busca em Profundidade

- As arestas são exploradas a partir do vértice $v$ mais recentemente descoberto que ainda tem arestas não descobertas saindo dele.
- Quando todas as arestas de $v$ tiverem sido exploradas volta-se até para explorar arestas que saem do vértice a partir do qual $v$ foi descoberto.

- Todos os vértice são inicializados com branco.
- Quando um vértice é visitado pela primeira vez ele torna-se cinza.
- Quando sua lista de adjacentes foi totalmente explorada ele torna-se preto.

- O tempo de descoberta $d[v]$ é o momento em que o vértice $v$ foi visitado pela primeira vez.
- O tempo de término do exame da lista de adjacentes $t[v]$ é o momento em que a visita a toda lista de vértices adjacentes a $v$ foi concluída.
- $d[v]$ e $t[v]$ são inteiros entre $1$ e $2V$, onde $V$ é o número de vértices do grafo.