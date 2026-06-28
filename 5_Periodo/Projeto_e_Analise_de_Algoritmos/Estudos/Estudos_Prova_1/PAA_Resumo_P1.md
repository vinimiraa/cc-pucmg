# Resumo: Projeto e Análise de Algoritmos - Prova 1

## Introdução

- Eficiência $\times$ Eficácia:
	- **Eficiência**: 
		- Realizar uma tarefa da melhor maneira possível, com menos recurso, tempo ou esforço.
		- Foco no **processo**.
	- **Eficácia**: 
		- Capacidade de alcançar o objetivo ou resultado esperado.
		- Foco no **resultado**
- Um algoritmo é **eficiente** quando o custo ==computacional de sua execução pode ser expresso por uma função **polinomial**== em relação ao tamanho da entrada.

## Relações de Recorrência

- **Definição Geral**:
	- Uma **relação de recorrência** é uma ==equação que define cada termo de uma sequência em função de um ou mais termos anteriores. A partir de condições iniciais e dessa regra de dependência, é possível calcular todos os termos subsequentes da sequência==. Esse tipo de relação é muito utilizado para modelar processos que evoluem passo a passo ao longo do tempo.
- **Definição em PAA**:
	- No contexto de **Projeto e Análise de Algoritmos**, uma relação de recorrência ==expressa a **complexidade de tempo** de algoritmos recursivos. Ela descreve o custo de resolver um problema em função do custo de resolver subproblemas menores, incluindo também o custo adicional necessário para combinar as soluções parciais==.

Por exemplo:

$$T(n) =  \begin{cases} T(n-1) + n  & , & n > 1 \\ 1 & , & n = 1 \end{cases}$$

- **Explicação Intuitiva**:
	
	Essa recorrência significa que o custo para resolver um problema de tamanho $n$ é o custo de resolver um problema de tamanho $n−1$, somado a um esforço adicional proporcional a $n$.
	
	- Para $n=1$, o custo é $1$.
	- Para $n=2$, temos $T(2) = T(1) + 2 = 1 + 2 = 3$.
	- Para $n=3,$ $T(3) = T(2) + 3 = 3 + 3 = 6$.
	- Para $n=4$, $T(4) = T(3) + 4 = 6 + 4 = 10$.
	
	Seguindo esse raciocínio, vemos que $T(n)$ acumula a soma dos números de $1$ até $n$.  
	Ou seja:
	
	$$T(n) = 1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2} = \frac{n^2 + n}{2}$$
	
- **Jeito Sílvio**:
	
	 A ideia básica da técnica é expandir a relação de recorrência até que possa ser detectado o seu comportamento no caso geral. ==Esta técnica para fechar relações de recorrência é chamada de **Expansão Telescópica**==.
	
	$$
	\begin{aligned}
	T(n) & = \cancel{T(n-1)} + n \\
	\cancel{T(n-1)} & = \cancel{T(n-2)} + (n-1)  \\
	\cancel{T(n-2)} & = T(n-3) + (n-2) \\
	& \vdots \\
	T(n-i) & = T(n-i-1) + (n-i) \\
	& \vdots \\
	T(3) & = \cancel{T(2)} + 3 \\
	\cancel{T(2)} & = \cancel{T(1)} + 2 \\
	\cancel{T(1)} & = 1 \\ \\
	\end{aligned}
	$$
	
	Somando todos os incrementos restantes da expansão recursiva, temos:
	
	$$
	T(n) = n + (n-1) + (n-2) + \cdots + 3 + 2 + 1
	$$
	
	Observando que podemos escrever a mesma soma em ordem inversa:
	
	$$
	T(n) = 1 + 2 + 3 + \cdots + (n-2) + (n-1) + n
	$$
	
	Somando essas duas expressões termo a termo, cada par resulta em $(n+1)$:
	
	$$
	2T(n) = (1+n) + (2+n-1) + \cdots + (n-1+2) + (n+1)
	$$
	
	Portanto:
	
	$$
	2T(n) = n(n+1) \quad \Rightarrow \quad T(n) = \frac{n(n+1)}{2}
	$$
	
## Ordens Assintóticas

- A complexidade assintótica é definida pelo ==crescimento de complexidade para entradas suficientemente grandes==.
- O comportamento assintótico de um algoritmo é o mais procurado, já que, para um volume grande de dados, a complexidade torna-se importante. ==O algoritmo assintoticamente mais eficiente é o melhor para todas as entradas, exceto talvez para entradas relativamente pequenas==.
- A taxa de crescimento de um função está diretamente associado a ordem de complexidade, o que nos leva às notações assintóticas.

- **Big O** ($O$):
	
	A notação $O$ define um **limite assintótico superior** a menos de constantes. Por exemplo, a função quadrática $g(n)=n^2$ cresce mais rapidamente do que a linear $f(n)=7n+13$, a partir de certo ponto. Assim, $f(n) \in O(g(n))$.
	
	$$
	\begin{aligned}
	f(n) = O(g(n)) \ \text{se e somente se} \\
	\exists \ c > 0, n_0 \geq 0 \mid f(n) \leq c \times g(n), \forall \ n \geq n_0 \\
	\end{aligned}
	$$
	
	Isso significa que para $n$ suficientemente grande, $g(n)$ é um limite superior para $f(n)$ com um fator constante, isto é, existem constantes $c$ e $n_0$ tais que, para valores de $n$ não menores que $n_0$, o valor de $f(n)$ é sempre menor ou igual ao produto $c \times g(n)$.
	
	Dizer que um algoritmo é $O(1)$ significa que o número de operações fundamentais executadas é limitado por uma constante.
	
- **Omega** ($\Omega$):
	
	A notação define um **limite assintótico inferior** a menos de constantes. Por exemplo, a função cúbica $g(n) = 7n^3+5$ cresce menos rapidamente do que a exponencial $f(n)=2^n$, a partir de certo ponto. Assim, $f(n) \in \Omega(g(n))$.
	
	$$
	\begin{aligned}
	f(n) = \Omega(g(n)) \ \text{se e somente se} \\
	\exists \ c > 0, n_0 \geq 0 \mid f(n) \geq c \times g(n), \forall \ n \geq n_0 \\
	\end{aligned}
	$$
	
	Isso significa que, para valores suficientemente grandes de $n$, $f(n)$ cresce no mínimo tão rápido quanto $g(n)$, até um fator constante.
	
- **Theta** ($\Theta$):
	
	A notação  $\Theta$ define um **limite assintótico exato**, a menos de constantes. Por exemplo, as funções quadráticas $f(n)=7n^2+13$ e $g(n)=n^2+3$ crescem com a mesma rapidez, a partir de certo ponto. Assim, $f(n) \in \Theta(g(n))$.
	
	$$
	\begin{aligned}
	f(n) = \Theta(g(n)) \ \text{se e somente se} \\
	f(n) = O(g(n)) \ \land \ f(n) = \Omega(g(n)) 
	\end{aligned}
	$$
	
	ou
	
	$$
	\begin{aligned}
	f(n) = \Theta(g(n)) \ \text{se e somente se} \\
	\exists \ c > 0, d > 0, n_0 \geq 0 \mid c \times g(n) \leq f(n) \ \land \ f(n) \leq d \times g(n), \forall \ n \geq n_0 \\
	\end{aligned}
	$$
	
	Isso significa que existem constantes $c,d$ e $n_0$ tais que, para todo valor de $n$ maior ou igual a $n_0$, o valor de $f(n)$ está entre os produtos $c \times g(n)$ e $d \times g(n)$.
	
- Para simplificar a notação, muitas vezes no cálculo de complexidade, será usado simplesmente $log \ n$, independente da base, pois a troca de base é simplesmente a multiplicação por uma constante, o que não altera a ordem de complexidade. 

## Complexidade dos Algoritmos

- Historicamente, ==a expressão "algoritmo não eficiente" é associada a algoritmos de complexidade não polinomial, ou simplesmente algoritmo não polinomial==. Essa associação entre algoritmo não eficiente e algoritmo não polinomial justifica-se porque ==um algoritmo com complexidade, digamos, $2^n$ tem um tempo de execução que cresce tão rapidamente com $n$ que, para $n$ razoavelmente grande, torna-se proibitivo==. Além disso, um problema que tenha um tal algoritmo como melhor opção de solução torna-se intratável para entradas razoavelmente grandes.
	
- Os algoritmos podem então ser particionados em duas classes: os *razoáveis* (polinomiais) e os *não razoáveis* (exponenciais). Por outro lado, um problema é dito ==tratável se o limite superior de complexidade é polinomial, ou seja, conhece-se um algoritmo *razoável* que o resolva==. Um problema é chamado de ==intratável se o limite inferior de complexidade é exponencial, ou seja, não existe algoritmo *razoável* que o resolva==. Há os problemas cuja resposta é tão longa, que precisa-se de um tempo exponencial para descrevê-la. Mas, nesse caso, costuma-se dizer que o problema não está bem posto, ou seja, não está definido realisticamente.
	
- Os chamados problemas ==NP-Completos são problemas que têm a questão da complexidade ou tratabilidade não resolvida==, pois não se sabe se existe ou não algoritmo polinomial que o resolva. 

### Conceitos básico

- Um **problema é** uma questão a ser solucionada, caracterizado por:
	- Uma descrição genérica de todos os seus parâmetros.
	- Especificação das propriedade que a resposta ou solução deve satisfazer.
- São três gêneros de problemas, que se diferenciam pela colação da pergunta: **problema de decisão, de localização e de otimização**.
	- Os ==problemas de decisão== tem resposta `Sim ou Não` (*True or False*).
		- Exemplo: Problema da Existência de Cobertura de Vértices.
	- Os ==problemas de localização== envolvem a procura de um elemento que satisfaça a condição de solução.
		- Exemplo: Problema de Determinação de Cobertura de Vértices.
	- Os ==problemas de otimização== requerem um qualidade ótima da solução.
 - Um algoritmo é polinomial sse sua complexidade é de tempo polinomial: $O(p(n))$, onde $p(n)$ é um polinômio, e $n$ representa o tamanho da entrada.
 - Se um algoritmo não é polinomial, diz-se que é exponencial (ainda que sua complexidade não esteja na forma usual da função exponencial, como $n^{log n}$).
 - Algoritmos que resolvem um problema de localização ou de  otimização podem ser modificados para resolver problemas de decisão associados, praticamente sem esforço extra.
 - ==Classes de problemas P, NP e NP-Completo, são definidas para problemas de decisão.==

## Classe de Problemas e Intratabilidade

- **Classe P**: 
	- Problemas (*deterministicamente*) *polinomiais*, consiste nos problemas de decisão $\prod$ que, numa codificação razoável,==podem ser resolvidos por algoritmos determinísticos em tempo polinomial==.
- **Classe NP**: 
	- Problemas *não deterministicamente polinomiais*, consiste nos problemas de decisão $\prod$, que, numa codificação razoável, ==podem ser resolvidos por um algoritmo não determinístico em tempo polinomial==, mas ==podem ser certificados em tempo polinomial==.
- Assim, podemos ver a classe P como a dos problemas que podem ser **resolvidos eficientemente**, enquanto a NP como a classe dos problemas que podem ser **certificados eficientemente**.
- Certamente $P \subseteq NP$, mas não se sabe se $P = NP$.
- **Classe NP-Completo**:
	- Problemas que têm a propriedade de que, se um problema NP-Completo tiver solução determinística polinomial, qualquer outro problema NP também terá. Essa propriedade envolve o conceito de redução polinomial.
	> Dado um problema $\prod_1$, reduzi-lo a outro problema $\prod_2$. A ideia é: dada uma instância de $\prod_1$, constrói-se uma instância de $\prod_2$, de modo que a partir de uma solução dessa instância de $\prod_2$ se possa obter uma solução para a instância original de $\prod_1$.
	- Para ser NP-Completo deve-se cumprir 2 requisitos.
		1. $X \in NP$
		2. $\exists \ Y \in \text{NP-Completo} \mid Y \leq_p X$ 
- **Classe NP-Difícil**:
	- Para ser NP-Difícil deve-se cumprir 2 requisitos.
		1. $X \in NP$
		2. $\exists \ Y \in \text{NP-Difícil} \mid Y \leq_p X$ 
---
FIM
