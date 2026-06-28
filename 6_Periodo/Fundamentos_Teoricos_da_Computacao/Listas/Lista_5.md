- Fundamentos Teóricos da Computação - Lista 5
- 812839 - Vinícius Miranda de Araújo

1. O problema consiste em verificar se um DFA aceita todas as strings possíveis sobre o alfabeto, isto é, se sua linguagem é igual a $\Sigma^*$.

	Podemos reescrever essa condição de forma equivalente utilizando complemento de linguagens regulares. Um DFA aceita todas as strings se, e somente se, não existe nenhuma string que ele rejeite, ou seja, se o complemento da sua linguagem é vazio:
	
	$L(A)=\Sigma^* \iff L(\overline{A}) = \emptyset$
	
	Como as linguagens regulares são fechadas sob complemento, é possível construir um DFA equivalente para o complemento de $A$. Em seguida, o problema reduz-se a verificar se essa linguagem é vazia.
	
	O problema de vazio para DFA **é decidível**, pois pode ser resolvido marcando os estados alcançáveis a partir do estado inicial. Se nenhum estado de aceitação for alcançável, aceitar.
	
<br>

2. O problema consiste em verificar se uma string www é aceita por um DFA AAA.

	Como um DFA possui função de transição determinística e número finito de estados, a execução sobre uma entrada qualquer é única e finita.
	
	Assim, é possível simular diretamente a função de transição estendida do autômato, processando a string símbolo por símbolo até alcançar um estado final ou não final.
	
	Como essa simulação sempre termina após um número finito de passos proporcional ao tamanho da entrada, trata-se de um procedimento efetivo.
	
	Portanto, o problema **é decidível**, pois existe um procedimento mecânico que sempre termina e determina corretamente a aceitação da string.

<br>

3. No problema de verificar se duas linguagens regulares são equivalentes, constrói-se um DFA $C$ tal que sua linguagem representa exatamente a diferença entre as linguagens de $A$ e $C$:

	$L(C) = (L(A)\cap \overline{L(B)}) \cup (\overline{L(A)} \cap L(B))$
	
	Essa construção corresponde à diferença simétrica entre $L(A)$ e $L(B)$, isto é, todas as strings em que os dois autômatos se comportam de forma diferente.
	
	Assim, se a linguagem $L(C)$ for vazia, significa que não existe nenhuma string que diferencie $A$ e $B$, e portanto $L(A)=L(B)$. Por outro lado, se $L(C)$ não for vazia, então existe pelo menos uma string que é aceita por um dos autômatos e rejeitada pelo outro, concluindo que $L(A)\neq L(B)$.
	
	Como o problema de vazio para DFA é decidível por meio de análise de alcançabilidade em grafos finitos, conclui-se que o problema de equivalência e de diferença entre DFA **é decidível**. 

<br>

4. O problema consiste em verificar se a linguagem reconhecida por um DFA $A$ está contida na linguagem reconhecida por um DFA $B$.
	
	Essa condição pode ser reescrita de forma equivalente como a inexistência de um contraexemplo, ou seja, não deve existir nenhuma string que pertença a $L(A)$ e não pertença a $L(B)$:
	
	$L(A) \subseteq L(B) \iff L(A) \cap \overline{L(B)} = \emptyset$
	
	Como linguagens regulares são fechadas sob complemento e interseção, é possível construir um DFA que reconhece exatamente o conjunto $L(A) \cap \overline{L(B)}$​.
	
	O problema então se reduz a verificar se essa linguagem é vazia.
	
	Como o problema se reduz ao teste de vazio de um DFA, conclui-se que ele **é decidível**.

<br>

5. O problema consiste em verificar se uma gramática livre de contexto gera a cadeia vazia.

	Isso pode ser resolvido analisando quais variáveis da gramática conseguem derivar a string vazia. Uma variável é considerada “anulável” se ela pode gerar $\lambda$ diretamente ou indiretamente por meio de suas produções.
	
	Esse conjunto de variáveis anuláveis pode ser construído iterativamente: inicialmente são marcadas as variáveis que produzem $\lambda$ diretamente, e em seguida são adicionadas aquelas que produzem apenas símbolos já marcados como anuláveis. Esse processo continua até atingir um ponto fixo.
	
	Como o número de variáveis da gramática é finito, esse processo sempre termina.
	
	Se o símbolo inicial pertencer ao conjunto de variáveis anuláveis, então a gramática gera $\lambda$.

	Como o problema pode ser resolvido por um processo iterativo em um conjunto finito que sempre termina, conclui-se que ele **é decidível.**