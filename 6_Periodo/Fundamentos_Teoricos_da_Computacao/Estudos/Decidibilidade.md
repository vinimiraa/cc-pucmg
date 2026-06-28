# **Decidibilidade Computacional e os Limites da Solvabilidade Algorítmica**

## **Resumo**

A teoria da computação distingue entre problemas que podem ser resolvidos por um algoritmo e aqueles que estão fundamentalmente além do alcance de qualquer máquina computacional. Um problema de decisão é considerado **decidível** se existe um algoritmo -- especificamente uma Máquina de Turing (MT) que para para toda entrada -- capaz de fornecer uma resposta definitiva “SIM” ou “NÃO”.

Embora muitos problemas envolvendo autômatos finitos (DFA, NFA) e gramáticas livres de contexto (CFG) sejam decidíveis, o **Problema da Parada** revela os limites absolutos da computação.

A **Tese de Church-Turing** afirma que qualquer função intuitivamente computável pode ser computada por uma Máquina de Turing. No entanto, como o número de linguagens possíveis é não enumerável enquanto o número de Máquinas de Turing é enumerável, existem mais problemas do que soluções. 

---

## **1. Fundamentos de Problemas de Decisão**

Um problema de decisão é caracterizado por uma classe de perguntas que exigem uma resposta binária (SIM ou NÃO). Esses problemas são representados como linguagens; um problema é decidível se a linguagem que o representa é decidível por uma Máquina de Turing.

### Exemplos de perguntas de decisão:

- **Autômatos:** Um DFA $M$ específico aceita uma string $w$?
- **Gramáticas:** Uma string $w$ pode ser gerada por uma gramática livre de contexto (CFG)?
- **Matemática:** Um polinômio $P$ com coeficientes inteiros possui raízes inteiras?
- **Computação:** Uma Máquina de Turing $M$ para quando recebe a entrada $w$?

---

## **2. Análise de Problemas Decidíveis**

Problemas decidíveis são aqueles para os quais uma Máquina de Turing pode ser construída de modo a sempre alcançar um estado de aceitação ou rejeição.

### **2.1 Linguagens Regulares e Autômatos Finitos**

A tabela a seguir resume a decidibilidade de problemas relacionados a linguagens regulares:

| Linguagem/Problema | Descrição                                        | Estratégia de Prova                                                                                                 |
| ------------------ | ------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------- |
| **$A_{DFA}$**      | Verificar se um DFA $D$ aceita a string $w$.     | Simular $D$ em $w$. Se terminar em estado de aceitação, aceitar; caso contrário, rejeitar.                          |
| **$A_{NFA}$**      | Verificar se um NFA $N$ aceita a string $w$.     | Converter NFA em DFA equivalente $D$ e aplicar o algoritmo de DFA.                                                  |
| **$A_{REX}$**      | Verificar se uma expressão regular $R$ gera $w$. | Converter $R$ em DFA equivalente e aplicar o algoritmo de DFA.                                                      |
| **$E_{DFA}$**      | Verificar se $L(D) = \emptyset$ (Vazio).         | Marcar estados alcançáveis a partir do estado inicial. Se nenhum estado de aceitação for alcançável, aceitar.       |
| **$EQ_{DFA}$**     | Verificar se $L(A) = L(B)$. (Equivalentes)       | Construir um DFA $C$ tal que $L(C) = (L(A) \cap L(B)') \cup (L(A)' \cap L(B))$. Depois verificar se $L(C)$ é vazio. |


### **2.2 Linguagens Livres de Contexto ($A_{CFG}$)**

Para decidir se uma CFG $G$ gera uma string $w$, o algoritmo deve evitar loops infinitos na derivação.

#### Metodologia:

- Converter $G$ para Forma Normal de Chomsky (CNF).
- Nessa forma, qualquer derivação de uma string de tamanho n exige exatamente $2n − 1$ passos.

#### Procedimento de decisão:

- A MT lista todas as derivações possíveis de comprimento $2n − 1$.
- Se $w$ for gerada, aceita; caso contrário, rejeita.

---

## **3. A Tese de Church-Turing**

A Tese de Church-Turing serve como ponte entre a noção intuitiva de “algoritmo” e a definição formal de Máquina de Turing.

- **Afirmação central:** Uma função é computável se e somente se é computável por uma Máquina de Turing.
- **Status:** Não é um teorema matemático provável, mas uma tese apoiada pelo fato de que todos os modelos conhecidos de computação são equivalentes à Máquina de Turing.
- **Implicação:** Se nenhuma MT pode resolver um problema, então nenhum algoritmo (em qualquer linguagem de programação) pode resolvê-lo.
    

---

## **4. Limites da Computação: Indecidibilidade**

Apesar do poder das Máquinas de Turing, existem problemas -- especialmente o Problema da Parada -- que não podem ser resolvidos algoritmicamente.


### **4.1 Problema da Parada ($A_{TM}$)**

Pergunta: dada uma Máquina de Turing $M$ e uma string $w$, $M$ eventualmente para ao processar w?

#### Prova por contradição:

1. Assuma que existe uma MT $H$ que decide $A_{TM}$. $H$ aceita se $M$ para em $w$ e rejeita se $M$ não para.
2. Construa uma nova MT $D$ que usa $H$ como sub-rotina. $D$ recebe a descrição de uma máquina $R(D)$ como entrada.
3. Se $H$ diz que $D$ irá parar, $D$ entra em loop infinito.
4. Se $H$ diz que $D$ não irá parar, $D$ para imediatamente.
5. Conclusão: $D$ para se e somente se não para. Essa contradição lógica prova que $H$ não pode existir.

### **4.2 Reconhecibilidade vs. Decidibilidade**

Embora $A_{TM}$ seja indecidível, ele é reconhecível por Máquina de Turing.

- Uma MT universal $U$ pode simular $M$ em $w$.
- Se $M$ aceita, $U$ aceita.
- Se $M$ entra em loop infinito, $U$ também entra em loop infinito.

Portanto, $U$ não decide o problema, pois não garante resposta “NÃO”.

---

## **5. Não Enumerabilidade e Linguagens Irreconhecíveis**

A existência de problemas que nem podem ser reconhecidos por uma MT é uma consequência da teoria dos conjuntos.

- **Enumerabilidade das máquinas:** o conjunto de todas as MTs é enumerável (contável).
- **Não enumerabilidade das linguagens:** o conjunto de todas as linguagens possíveis é não enumerável.
- **Conclusão:** existem mais linguagens do que máquinas, logo existem linguagens não reconhecíveis por MT.

---

## **Relação entre decidibilidade e complementos**

Um teorema fundamental afirma:

> Uma linguagem $L$ é decidível por MT se e somente se $L$ e seu complemento $L'$ são ambas reconhecíveis por MT.

Como $A_{TM}$ é reconhecível mas não decidível, segue que seu complemento $A'_{TM}$ não é nem reconhecível. Se fosse, $A_{TM}$ seria decidível, o que já foi provado como falso.
