## P2 - 2025/1

![[Pasted image 20251028141739.png]]

- Abordagem Gulosa:
	Para maximizar o número de mineiros satisfeitos, deve-se ordenar as listas de desejos e tamanhos disponíveis em ordem crescente e, em seguida, emparelhar cada mineiro com o menor pão-de-queijo que atenda ao seu tamanho mínimo.
	
	O algoritmo percorre as duas listas simultaneamente, garantindo que cada decisão local (usar o menor pão possível) preserve a otimalidade global.
	
	A complexidade é $O(n \log n)$ devido à ordenação, e o método é ótimo, pois qualquer solução diferente pode ser transformada nesta sem perda de satisfação total.
	
	```
	1. ordenar P em ordem crescente
	2. ordenar T em ordem crescente
	3. i <- 1          // índice dos mineiros
	4. j <- 1          // índice dos pães
	5. satisfeitos ← 0
	6. enquanto (i <= n e j <= n) faça
	7.     se (T[j] >= P[i]) então
	8.         satisfeitos <- satisfeitos + 1   // mineiro i satisfeito
	9.         i <- i + 1                       // próximo mineiro
	10.        j <- j + 1                       // próximo pão
	11.    senão
	12.        j <- j + 1                       // pão muito pequeno, descarta
	13. fim-enquanto
	14. retornar satisfeitos
	```

- Abordagem Programação Dinâmica:

	A questão pode ser modelada por programação dinâmica, de forma análoga ao problema da Maior Subsequência Comum (LCS).
	
	Definindo $DP[i][j]$ como o número máximo de mineiros satisfeitos considerando os $i$ primeiros desejos e os $j$ primeiros pães, temos:
	
	$$
	DP[i][j] = 
	\begin{cases} 
	0, & \text{se } i=0 \text{ ou } j=0,\\ 
	1 + DP[i-1][j-1], & \text{se } t_j \ge p_i,\\ 
	\max(DP[i-1][j], DP[i][j-1]), & \text{caso contrário.} 
	\end{cases}
	$$
	
	A otimalidade é garantida, pois cada subproblema é resolvido de forma ótima e usado na composição da solução maior. Esse método é mais custoso (menos eficiente) que o guloso, mas serve como uma alternativa.
	
	A complexidade é $O(nm)$, pois é o tempo para preencher a matriz e retorna $DP[n][m]$ como o número máximo de mineiros satisfeitos.
	
	```
	1. criar matriz DP[0..n][0..m]
	2. para i de 0 até n:
	3.     DP[i][0] <- 0
	4. para j de 0 até m:
	5.     DP[0][j] <- 0
	6. para i de 1 até n:
	7.     para j de 1 até m:
	8.         se T[j] >= P[i] então
	9.             DP[i][j] <- 1 + DP[i-1][j-1]
	10.        senão
	11.            DP[i][j] <- max(DP[i-1][j], DP[i][j-1])
	12. retornar DP[n][m]
	```

---
![[Pasted image 20251028143036.png]]

Ordenar os elementos do conjunto em ordem decrescente e selecionar iterativamente os maiores até que a soma acumulada ultrapasse metade da soma total dos elementos. O subconjunto obtido tem a menor cardinalidade possível cuja soma é maior que a dos demais elementos.

A estratégia é ótima porque cada elemento maior contribui mais rapidamente para atingir a metade do total, reduzindo o número de elementos necessários. 

A complexidade é $O(n \log n)$ pelo custo de ordenação; a fase de acumulação é $O(n)$.

---
![[Pasted image 20251028144226.png]]

Ordenar os elementos de $A$ em ordem crescente. Construa uma permutação circular $B$ intercalando os maiores e os menores valores (por exemplo: maior, menor, 2º maior, 2º menor, ...). Essa disposição coloca valores grandes ao lado de valores pequenos, maximizando as diferenças absolutas entre vizinhos. Calcule a soma circular $S = \sum_{i=1}^{n} |B[i] - B[i+1]|$ (com $B[n+1]\equiv B[1]$) e retorna $S$.

Para aumentar a soma, é melhor colocar elementos grandes ao lado de elementos pequenos, pois isso gera diferenças maiores. Se dois elementos grandes ou dois elementos pequenos estiverem adjacentes, trocar um deles por um elemento do outro “grupo” não diminui a soma e geralmente a aumenta. Repetindo essa ideia, todos os elementos se organizam alternando grandes e pequenos. Assim, a estratégia de intercalar extremos garante a soma máxima, provando que a construção é ótima.

A complexidade é $O(n \log n)$ tempo (dominado pela ordenação) e $O(n)$ para a permutação.

---
![[Pasted image 20251028150424.png]]

(i) A solução gulosa seria: ordenar os intervalos pelo tempo de fim (crescente). Percorrer os intervalos nessa ordem e adicionar cada intervalo se ele não sobrepor o último intervalo selecionado. Retornar os intervalos escolhidos (ou a soma dos pesos, se todos forem iguais a 1).

Quando todos os pesos são iguais a 1, essa estratégia maximiza o número de intervalos selecionados porque escolher o intervalo que termina mais cedo libera mais espaço para os demais. Trocar intervalos adjacentes que poderiam ser escolhidos nunca diminui o resultado, garantindo otimalidade da abordagem gulosa.

(ii) Para pesos gerais $w_i \ge 1$, podemos: ordenar os intervalos pelo tempo de fim, calcular para cada intervalo $i$ o índice $p(i)$ do último intervalo que não sobrepõe $i$, e definir:

$$OPT(i) = \max \{ w_i + OPT(p(i)),\; OPT(i-1) \}.$$

O valor $OPT(n)$ dá a soma máxima de pesos. Esse método garante otimalidade porque considera todas as combinações de intervalos compatíveis de forma eficiente.

A complexidade da solução gulosa é $O(n \log n)$ (devido a ordenação) e $O(n)$ para a seleção dos intervalos. Para a programação dinâmica, a complexidade também é $O(n \log n)$ usando busca binária para calcular $p(i)$ e $O(n)$ para preencher o vetor $OPT$.

## P2 - 2024/2

![[Pasted image 20251028152431.png]]

(i) Soluções gulosas:
1. Ordena os intervalos pelo tempo de início e seleciona os intervalos sem sobreposição.,
    - Não garante a solução ótima.,
    - Contra-exemplo:
	    ![[Pasted image 20251028153244.png]]
2. Ordena os intervalos pela duração (diferença entre fim e início).,
    - Pode liberar rapidamente o recurso, mas pode gerar soluções subótimas.
    - Contra-exemplo:
	    ![[Pasted image 20251028153313.png]]
3. Calcula o número de conflitos de cada intervalo e seleciona o que tem o menor número de conflitos.,
    - Pode melhorar o desempenho, mas não garante a solução ótima.,
    - Contra-exemplo:
	    ![[Pasted image 20251028153335.png]]
4. Ordena os intervalos pelo tempo de término e seleciona os intervalos sem sobreposição.,
    - Garante a solução ótima para o problema.

(ii) Para pesos gerais $w_i \ge 1$, não existe uma solução gulosa que apresenta o melhor resultado possível. Nesse caso, deve-se utilizar a programação dinâmica que consiste em: ordenar os intervalos pelo tempo de fim, calcular para cada intervalo $i$ o índice $p(i)$ do último intervalo que não sobrepõe $i$, e definir:

$$OPT(i) = \max \{ w_i + OPT(p(i)),\; OPT(i-1) \}.$$

O valor $OPT(n)$ dá a soma máxima de pesos. Esse método garante otimalidade porque considera todas as combinações de intervalos compatíveis de forma eficiente.

A complexidade da solução gulosa é $O(n \log n)$ (devido a ordenação) e $O(n)$ para a seleção dos intervalos. Para a programação dinâmica, a complexidade também é $O(n \log n)$ usando busca binária para calcular $p(i)$ e $O(n)$ para preencher o vetor $OPT$.

---
![[Pasted image 20251028154020.png]]

> Queremos atribuir cada intervalo a um grupo de modo que nenhum grupo tenha intervalos sobrepostos, usando o menor número possível de grupos.

1. Ordenar pelo tempo de início (crescente) e alocar primeiro grupo disponível
	- Ordenar os intervalos por $s_i$​ crescente.
	- Para cada intervalo, colocar no primeiro grupo onde não há sobreposição; se nenhum grupo disponível, criar um novo.
	- Não garante solução ótima, pois pode falhar em casos quando os intervalos iniciam cedo mas se prolongam muito, abrindo grupos extras.
2. Ordenar pelo tempo de fim (crescente) e alocar primeiro grupo disponível
	- Ordenar os intervalos por $f_i$​ crescente.
	- Alocar cada intervalo no primeiro grupo compatível; se não houver, criar novo grupo.
	- Garante solução ótima, porque qualquer ponto com $k$ intervalos sobrepostos obriga pelo menos $k$ grupos, e o algoritmo produz exatamente esse número.
3. Alocar no grupo com menor último fim compatível
	- Ordenar os intervalos por qualquer critério (por exemplo, início crescente).
	- Para cada intervalo, escolher o grupo cujo último intervalo termina mais cedo e não sobrepõe o atual; criar novo grupo se necessário.
	- Garante solução ótima, pois mantém os grupos mais compactos e evita criar grupos desnecessários.

A complexidade para a ordenação é $O(n \log n)$ e para a alocação em grupos é $O(ng)$, onde $g$ é o número de grupos criado.

---
![[Pasted image 20251028155134.png]]

> Minimizar o tempo de decida é minimizar a diferença entre tamanho do esquiador e do seu esqui.

- Abordagem Gulosa 1 (Ótima):
	
	Ordena o grupo de esquiadores e esquis crescentemente. Emparelha o menor esqui para o menor esquiador, o segundo menor esqui para o segundo menor esquiador, e assim por diante até que todos os atletas tenham um equipamento.,
	
	Essa abordagem é ótima pois ela minimiza a diferença entre os tamanhos, garantindo que cada decisão local seja ótima para o escopo global. (Melhorar isso) A complexidade é O(nlogn), pois depende da ordenação.

- Abordagem Gulosa 2 (Não ótima):

	Percorrer o grupo de atletas e atribuir cada um a umo esqui ainda livre de menor diferença absoluta (|alturaAtleta - tamEsqui|). Essas atribuições são repetidas até que todos os esquiadores tenham um equipamento. Essa abordagem não é ótima pois a decisão míope não garante a otimalidade global, como no contra-exemplo:,

	- AlturaAtletas = \[160cm, 165cm\] 
	- ComprimEsquis = \[140cm, 165cm\]
	- Resposta Obtida: 
		- Atleta 160cm > Esqui 165cm (5cm dif) 
		- Atleta 165cm > Esqui 140cm (25cm dif)  
		- Soma das diferenças = 30cm 
	- Resposta Ótima: 
		- Atleta 160cm > Esqui 140cm (20cm dif) 
		- Atleta 165cm > Esqui 165cm (0cm dif)  
		- Soma das diferenças = 20cm

---
![[Pasted image 20251028160335.png]]

Para um problema $X$ ser NP-Completo, deve-se:

1. $X \in \text{NP}$.
2. $\exists \ Y \in \text{NP-Completo} \mid Y \leq_p X$.

Assim, sabendo que o problema da Cobertura de Vértices (C.V.) é NP-Completo, para provar que *Hitting Set* (H.S.) é NP-Completo, então:

$\text{C.V.} \leq_p \text{H.S}$ $\to$ isto é, o problema de *Hitting Set* é pelo menos tão difícil quanto o de Cobertura de Vértices.

Portanto, a ideia é transformar o C.V em um problema de H.S. e para isso considerando um grafo $G = (V,E):$

- Cada aresta do grafo será um subconjunto em $\mathcal{S}$.
- Cada vértice do grafo será um elemento do universo $U$.

Assim:
- Universo $U = V$ (os vértices do grafo);
- Coleção de subconjuntos $\mathcal{S} = \{S_e : e \in E\}$, onde $S_{(u,v)} = \{u, v\}$.



