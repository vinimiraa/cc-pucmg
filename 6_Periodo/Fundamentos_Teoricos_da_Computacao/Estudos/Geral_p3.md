# 1. Introdução

No campo teórico, definimos os limites do que é computável por meio dos **Problemas de Decisão**. Esses são problemas caracterizados por uma classe de perguntas que exigem uma resposta binária: **SIM (YES)** ou **NÃO (NO)**. Para analisar esses problemas matematicamente, nós os representamos como linguagens.

## Definição: Problemas de Decisão e Decidibilidade

- **Problema de Decisão:** Uma questão formal (por exemplo, "Este DFA aceita a cadeia $w$?") cuja resposta é estritamente binária.
    
- **Decidibilidade:** Um problema é decidível se existe um algoritmo — especificamente uma Máquina de Turing — que fornece uma resposta para toda entrada. Uma linguagem que representa tal problema é chamada de **Turing-decidível**.
    

A **Hierarquia de Chomsky** é a estrutura fundamental para organizar essas linguagens. Veja essa hierarquia não apenas como uma lista de tipos, mas como uma progressão aninhada de poder: toda linguagem Regular é inerentemente Livre de Contexto, e toda linguagem Livre de Contexto é inerentemente Sensível ao Contexto. Compreender onde um problema se encontra nessa hierarquia nos diz exatamente qual "maquinário" é necessário para resolvê-lo.

---

# 2. Tipo 3: Linguagens Regulares

As **Linguagens Regulares (GR)** representam o nível mais restrito e eficiente da hierarquia. Elas são definidas por meio de **Expressões Regulares**, **Gramáticas Regulares** ou reconhecidas por **Autômatos Finitos**.

## Reconhecedores

- **DFA (Autômato Finito Determinístico):** Memória fixa, transições baseadas em estados.
    
- **NFA (Autômato Finito Não Determinístico):** Permite múltiplas transições possíveis para a mesma entrada.


## Lógica da Decidibilidade

As linguagens do Tipo 3 são altamente tratáveis. Consideramos diversos problemas importantes como decidíveis:

- **Aceitação ($A_{DFA}$, $A_{NFA}$, $A_{REX}$):** Determinar se uma cadeia pertence a uma linguagem é resolvido por simulação direta ou conversão para um DFA.
    
- **Vazio ($E_{DFA}$):** Decidido marcando o estado inicial e percorrendo todos os estados alcançáveis; se nenhum estado de aceitação for marcado, a linguagem é vazia, isto é, $L(D)=\emptyset$.
    
- **Equivalência ($EQ_{DFA}$):** Para decidir se $L(A)=L(B)$, construímos um DFA $C$ utilizando a diferença simétrica:
    

$$  
L(C)=(L(A)\cap L(B)')\cup(L(A)'\cap L(B))  
$$

Em seguida, verificamos se

$$  
L(C)=\emptyset.  
$$

Se isso for verdadeiro, então

$$  
L(A)=L(B).  
$$

---

# 3. Tipo 2: Linguagens Livres de Contexto (CFL)

As **Gramáticas Livres de Contexto (GLC)** permitem descrever estruturas recursivas e aninhadas, como a sintaxe de linguagens de programação ou delimitadores balanceados.

## Do Finito para a Pilha

O salto do Tipo 3 para o Tipo 2 é definido pela adição de uma **memória em pilha**. Enquanto um Autômato Finito não possui memória dos estados anteriores além de sua posição atual, o **Autômato de Pilha (Pushdown Automaton)** utiliza sua pilha para "contar" ou "associar" símbolos.

Entretanto, uma única pilha possui limitações: ela consegue reconhecer linguagens como

$$  
a^i b^i,  
$$

mas não consegue lidar com dependências de três grupos, como

$$  
a^i b^i c^i.  
$$

### Decidibilidade

O problema $A_{CFG}$ (a cadeia $w$ é gerada pela gramática $G$?) é decidível por meio da verificação de todas as derivações possíveis. Embora seja mais complexo que o caso das linguagens Regulares, as Linguagens Livres de Contexto continuam sendo computacionalmente eficientes para análise sintática (_parsing_).

---

# 4. Tipo 1: Linguagens Sensíveis ao Contexto (CSL)

As **Gramáticas Sensíveis ao Contexto (GSC)** introduzem a restrição de **monotonicidade**: para toda regra

$$  
u\rightarrow v,  
$$

o comprimento da saída deve ser pelo menos o comprimento da entrada:

$$  
|u|\le |v|.  
$$

## Nuance Matemática

Uma distinção importante nesse nível é que gramáticas do Tipo 1 não podem conter a cadeia vazia

$$  
\lambda.  
$$

Se uma linguagem aceita por uma máquina do Tipo 1 incluir $\lambda$, essa linguagem é classificada como **Recursiva**, mas tecnicamente está fora da definição estrita de uma Gramática do Tipo 1.

Por exemplo, a linguagem

$$  
{a^i b^i c^i \mid i>0}  
$$

é Sensível ao Contexto, pois exige o acompanhamento simultâneo de três contagens — uma tarefa impossível para um Autômato de Pilha, mas viável para um **Autômato Linearmente Limitado (LBA)**.

## Autômato Linearmente Limitado (LBA)

O LBA é uma Máquina de Turing com uma fita restrita. Ele utiliza dois marcadores especiais ("sentinelas"):

- $<$ (esquerda)
    
- $>$ (direita)
    

### Restrições da Fita

- **Máquina de Turing padrão:** espaço de trabalho infinito.
    
- **LBA:** a entrada $w$ é escrita como
    

$$  
.  
$$

A máquina pode ler e escrever, mas não pode apagar os marcadores nem mover-se além deles. Assim, o espaço de trabalho é estritamente limitado a

$$  
|w|+2.  
$$

Como esse espaço é finito, podemos decidir a pertinência de uma cadeia verificando todas as possíveis **formas sentenciais** até o comprimento da entrada.

---

# 5. Tipo 0: Gramáticas Irrestritas

As **Gramáticas Irrestritas (GI)** representam o topo da hierarquia, onde as regras

$$  
u\rightarrow v  
$$

não possuem restrições de comprimento. Elas geram as **Linguagens Recursivamente Enumeráveis**, reconhecidas pela **Máquina de Turing (MT)** universal.

## Simulação Não Determinística com 3 Fitas

Para provar que uma MT pode reconhecer qualquer GI, utilizamos uma simulação não determinística com três fitas:

1. **Fita 1 (Entrada):** armazena a cadeia alvo $w$.
    
2. **Fita 2 (Regras):** funciona como um banco de dados contendo todas as produções
    

$$  
u\rightarrow v  
$$

no formato

$$  
u\#v.  
$$

3. **Fita 3 (Estado da Derivação):** acompanha a forma sentencial atual.
    

## Laço Computacional

- **Passo 0:** Escrever as produções da gramática na Fita 2 e o símbolo inicial $S$ na Fita 3.
    
- **Passo 1:** A máquina escolhe não deterministicamente uma produção $u\#v$ da Fita 2.
    
- **Passo 2:** Procura na Fita 3 uma ocorrência de $u$. Caso nenhuma ocorrência seja encontrada, aquele ramo da computação para em um estado de não aceitação.
    
- **Passo 3:** Se $u$ for encontrado, ele é substituído por $v$, atualizando a forma sentencial da Fita 3.
    
- **Passo 4:** A Fita 3 é comparada com a Fita 1. Se forem idênticas, a máquina para em um estado de aceitação. Caso contrário, o ciclo continua.
    

---

# 6. Síntese

| Nível (Tipo) | Nome da Gramática          | Máquina Reconhecedora               | Categoria da Linguagem     | Restrição Principal (O "Diferencial")                                                    |
| ------------ | -------------------------- | ----------------------------------- | -------------------------- | ---------------------------------------------------------------------------------------- |
| Tipo 0       | Irrestrita (GI)            | Máquina de Turing (MT)              | Recursivamente Enumerável  | Nenhuma restrição; $u\rightarrow v$ permite qualquer alteração no comprimento da cadeia. |
| Tipo 1       | Sensível ao Contexto (GSC) | Autômato Linearmente Limitado (LBA) | Sensível ao Contexto (LSC) | Regras monotônicas                                                                       |
| Tipo 2       | Livre de Contexto (GLC)    | Autômato de Pilha                   | Livre de Contexto (CFL)    | Apenas um não terminal no lado esquerdo; requer uma pilha como memória.                  |
| Tipo 3       | Regular (GR)               | Autômatos Finitos (DFA/NFA)         | Regular                    | Mais restritiva; não possui memória além do estado atual.                                |

À medida que descemos do Tipo 0 para o Tipo 3, adicionamos restrições às regras gramaticais. Isso simplifica a máquina necessária para reconhecimento, mas reduz o conjunto de linguagens que podem ser descritas.

---

# Conclusão

A Hierarquia de Chomsky demonstra que a complexidade de uma linguagem é determinada pelas restrições de sua gramática e pela arquitetura da máquina que a reconhece. Essa relação constitui a base da decidibilidade: uma linguagem só é "resolúvel" se conseguirmos construir uma Máquina de Turing que a decida.

## 3 Principais Conclusões

- **Arquitetura Aninhada:** Cada nível da hierarquia é subconjunto do nível acima; a Máquina de Turing é o reconhecedor "universal" que engloba todos os demais.
    
- **Memória e Limites:** A transição de Linguagens Regulares para Livres de Contexto exige uma pilha; a transição para Linguagens Sensíveis ao Contexto exige uma fita, embora limitada.
    
- **O Limite da Decidibilidade:** Enquanto problemas envolvendo Linguagens Regulares e Livres de Contexto são, em geral, decidíveis, o avanço para o Tipo 0 introduz a possibilidade de laços infinitos, nos quais uma máquina pode jamais produzir uma resposta **SIM** ou **NÃO**.