# **Linguagens de Programação**
## **Conceitos Básicos**

1. **Alfabetos e Palavras**: Um alfabeto é um conjunto finito de símbolos (como letras e números). Uma palavra é uma sequência finita desses símbolos. Por exemplo, se o alfabeto é {a, b}, "ab" é uma palavra.
	
2. **Linguagem Formal**: Uma linguagem formal é um conjunto de palavras formadas a partir de um alfabeto. Essas palavras seguem regras específicas. Por exemplo, em uma linguagem que permite apenas palavras que sejam palíndromos (como "aba" ou "aa"), todas as palavras dessa linguagem seguirão essa regra.
	
3. **Gramática**: Gramáticas são conjuntos de regras que definem como palavras de uma linguagem são formadas. Uma gramática é composta por:
		
    - **Variáveis**: símbolos que podem ser substituídos por outros símbolos.
	    
	- **Terminais**: símbolos finais que aparecem nas palavras da linguagem.
	    
	- **Regras de produção**: instruções de como substituir variáveis por outros símbolos ou combinações de símbolos.
	    
	- **Símbolo inicial**: o ponto de partida para gerar palavras.
	
4. **Sistemas de Estados Finitos**: Esses sistemas modelam processos com um número limitado de estados (como o andar de um elevador) e são usados para entender como certas ações levam a diferentes resultados com base em entradas específicas.

### Simbologia

1. **Alfabeto** ($Σ$): Conjunto finito de símbolos usados para formar palavras. Exemplo: $Σ = {a, b}$.
	
2. **Símbolo**: Um elemento individual de um alfabeto. Pode ser uma letra, número, ou outro caractere.
	
3. **Palavra** ($w$): Sequência finita de símbolos justapostos. Exemplo: "ab" é uma palavra formada por símbolos do alfabeto.
	
4. **Palavra Vazia** ($ε$): Uma palavra que não contém símbolos. É como uma sequência "vazia" de caracteres.
	
5. **Gramática** ($G = (V, T, P, S)$):
	
	- **$V$**: Conjunto de símbolos variáveis (não-terminais).
	    
	- **$T$**: Conjunto de símbolos terminais (que aparecem nas palavras finais).
	    
	- **$P$**: Conjunto de regras de produção que definem como as palavras são formadas.
	    
	- **$S$**: Símbolo inicial, de onde começam as derivações.


## **Introdução**

1. O que é uma Linguagem de Programação?
	
    É uma maneira formal de comunicar instruções a um computador. Essas instruções são escritas usando um conjunto de palavras e símbolos específicos.
	
2. Requisitos para ser uma LP:  
	
    - **Universalidade**: Deve ser capaz de expressar qualquer programa de computador.
	    
	- **Implementável**: Deve ser possível ser executada em um computador.
	
3. Sintaxe e Semântica:
	
    - **Sintaxe**: Refere-se à forma, ou seja, como as instruções e comandos são organizados em um programa.
	    
	- **Semântica**: Refere-se ao significado, ou seja, o que as instruções fazem quando o programa é executado.
	
4. Paradigmas de Programação:  

    São diferentes estilos ou "modos de pensar" ao programar, como programação funcional, lógica, procedural, e orientada a objetos.
	
5. Por que estudar LPs?  
	
	- Melhora a compreensão da linguagem que você já usa.
	    
	- Facilita aprender novas linguagens.
	    
	- Ajuda a escolher a linguagem certa para cada tarefa.
	    
	- Melhora a habilidade de criar novas linguagens.
	
6. Importância das LPs:  
	
    Elas são fundamentais para diversas áreas da computação, como bancos de dados, sistemas operacionais, inteligência artificial, e muito mais.


## **Valores**

1. O que é um valor?  
	
    Um valor é qualquer coisa que existe enquanto um programa está exutando, como números, textos ou resultados de cálculos. Valores podem ser guardados, usados em operações e passados para funções.
	
2. Tipos de Valores:

    - **Tipos Primitivos**: São os valores básicos que a maioria das linguagens de programação já trazem prontos, como números inteiros (1, 2, 3), números decimais (1.5, 2.0), letras ('a', 'b'), e valores lógicos (verdadeiro ou falso).
    
        ```c
        int
        float
        double
        char
        bool
        // string, em algumas linguagens
        enum
        ```
	
    - **Tipos Compostos**: São combinações de valores simples. Por exemplo, uma lista de números ou um registro que guarda várias informações como nome, idade e altura de uma pessoa.
		
        1. **Produto Cartesiano**:
	        
            Um **produto cartesiano** combina elementos de diferentes conjuntos para formar uma tupla. Cada tupla é uma sequência ordenada de elementos, como um registro que agrupa diferentes tipos de dados (exemplo: nome, idade, altura).
			
            ```c
            struct s_Pessoa {
                char  nome[20];
                int   idade;
                float altura;
            };
            ```
			
        2. **União Discriminada**:
			
            Uma **união discriminada** permite que uma variável possa armazenar diferentes tipos de dados em momentos diferentes. Isso é útil para representar alternativas, onde o tipo de dado depende do valor de uma outra variável (exemplo: um item que pode ter uma quantidade ou uma data de entrega).
			
        3. **Mapeamento**:
			
            Um **mapeamento** é uma função que associa valores de um conjunto a valores de outro conjunto. Os arranjos (ou *arrays*) são exemplos comuns de mapeamentos, onde índices são mapeados para valores específicos.
			
        4. **Sequência**:
			
            Uma **sequência** é uma lista ordenada de elementos de um mesmo tipo. Ela permite armazenar um número arbitrário de itens, como uma *string* (sequência de caracteres) ou um arquivo sequencial.
			
        5. **Conjunto Potência**:
			
            Um **conjunto potência** é um conjunto que contém todos os subconjuntos possíveis de um conjunto de base. Em programação, ele representa a ideia de trabalhar com subconjuntos, como um conjunto de ingredientes para uma salada.
			
        6. **Recursão**:
			
            **Recursão** em tipos compostos permite que um tipo possa conter referências a si mesmo, como uma árvore binária, onde cada nó pode ter subárvores. Isso permite a criação de estruturas de dados complexas e potencialmente infinitas.
	
3. Importância dos Valores:
	
    - **Organização**: Agrupar valores em tipos ajuda a definir o que pode ser feito com esses valores, como operações e manipulações.
	    
    - **Segurança**: Definir tipos ajuda a evitar erros, garantindo que operações sejam realizadas com valores compatíveis.
	
4. Tipagem Estática vs Dinâmica:
	
    - **Tipagem Estática**: O tipo de cada valor é definido antes do programa executar, e isso ajuda a evitar erros.
		
    - **Tipagem Dinâmica**: O tipo dos valores pode mudar enquanto o programa executa, o que dá mais flexibilidade, mas pode causar erros se não for bem controlado.
		
        - Equivalência de Tipos:
			
            - **Estrutural**: Tipos são compatíveis se têm a mesma estrutura.
	            
			- **Nomes**: Tipos são compatíveis se têm o mesmo nome de tipo.
			
        - Princípio da Completeza de Tipo:
			
            - Nenhuma operação deve ser arbitrariamente restrita sobre os tipos de valores para manter o poder de expressão.
	
5. Expressões:
	
    São combinações de valores e operações que são avaliadas e geram valor. Por exemplo, a expressão "2 + 3" resulta no valor 5.
	
    1. **Literais**: Valores fixos (ex: 1234, 'a').
		
    2. **Agregados**: Valores compostos de componentes (ex: (a*2, b/2)).
		
    3. **Chamada de Função**: Aplica uma função a um argumento (ex: $f(x)$).
		
    4. **Condicional**: Avalia uma subexpressão baseada em uma condição (ex: if a > b then a else b).
		
    5. **Acesso a Variáveis e Constantes**: Produz valores das variáveis ou constantes indicadas.


## **Armazenamento**

1. **Variáveis**:
	  
    São objetos que contêm valores e modelam estados no mundo real. Variáveis podem ser atualizadas durante a execução de um programa. Elas têm um **tempo de vida** que vai da sua criação até a destruição, e ocupam memória apenas enquanto estão "vivas".
	
2. **Variáveis Compostas**: 
	
    Essas variáveis são formadas por múltiplos componentes, como *arrays* (arranjos) ou registros, e permitem que partes delas sejam atualizadas seletivamente.
	
3. **Arranjos**:  
	
    Podem ser **estáticos** (tamanho definido na compilação), **dinâmicos** (tamanho definido na criação), ou **flexíveis** (tamanho pode mudar durante a execução).
	
4. **Tempo de Vida**:
	
    É o intervalo de tempo entre a criação e a destruição de uma variável. Uma variável só precisa ocupar memória se estiver "viva".
		
    - **Variáveis Locais**: Existem apenas dentro do bloco em que são declaradas.
	    
	- **Variáveis Globais**: Podem ser usadas em diferentes blocos de código.
	    
	- **Variáveis de *Heap***: Podem ser criadas e destruídas a qualquer momento e são acessadas indiretamente via apontadores (ponteiros).
		
    - **Variáveis Persistentes**: Continuam existindo além da execução do programa que as criou, como em arquivos.
	
5. **Referências Penduradas (*Dangling Pointers*)**:  
	
    Ocorrem quando um ponteiro aponta para uma área de memória que foi desalocada, o que pode causar erros graves.
	
6. **Comandos**
	
	- **Saltos**: São instruções que não realizam nenhuma ação, como o comando `skip`.
		
	- **Atribuições**: Atualizam variáveis com novos valores, como `V := E`, e podem ser feitas de várias formas (múltiplas, simultâneas, combinadas).
		
	- **Chamadas de Procedimento**: Executam funções ou procedimentos com base em argumentos fornecidos.
		
	- **Comandos Sequencias**: São executados em uma ordem definida.
		
	- **Comandos Colaterais**: São executados sem ordem definida, não-determísticos.
		
	- Comandos Iterativos**: Repetem uma operação várias vezes, como loops `while` ou `for`.
		   
    - **Comandos Condicionais**: Possui vários subcomandos dentre os quais apenas um é escolhido para ser executado, como o comando `if` ou `if ... else ...` ou `switch-case`.
	
7. **Efeitos Colaterais**: 
	
	Expressões que, ao serem avaliadas, atualizam o valor de variáveis, o que pode complicar o fluxo do programa.


## **Amarração**

1. **Amarrações (*Bindings*)**:  
	
    Amarração é o processo de associar valores a variáveis, funções ou outras entidades em um programa. Isso ocorre em diferentes momentos, como na compilação, no carregamento ou na execução do programa.
	
2. **Tipos de Amarração**:
	
    - **Estática**: Acontece em tempo de compilação. As variáveis têm um valor fixo durante toda a execução do programa.
	    
	- **Dinâmica**: Acontece em tempo de execução, permitindo que variáveis mudem seus valores ao longo do tempo.
	
3. **Escopo**:
	
    - **Escopo Estático**: Determinado em tempo de compilação, onde a variável pode ser usada no código.
	    
	- **Escopo Dinâmico**: Determinado durante a execução, de acordo com a ordem em que as funções são chamadas.
	
4. **Tempo de Vida de Variáveis**:  
	
    O tempo de vida de uma variável está relacionado à sua amarração. Uma variável existe enquanto sua amarração estiver ativa. Variáveis locais têm um tempo de vida curto, enquanto variáveis globais ou persistentes podem viver por mais tempo.
	
5. **Ambientes de Execução**: 
	
    O ambiente de execução é o contexto no qual um programa é executado. Ele define onde e como as amarrações ocorrem e quais recursos estão disponíveis para o programa.
	
6. ***Closures***:  
	
    São funções que "lembram" o ambiente em que foram criadas, permitindo acessar variáveis mesmo após o término de uma função.

