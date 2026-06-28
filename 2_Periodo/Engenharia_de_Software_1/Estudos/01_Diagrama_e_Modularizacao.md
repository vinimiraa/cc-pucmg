# Diagramas e Modularização

## **UML**

- *Unified Modeling Language* (ou linguagem de modelagem unificada) é uma linguagem de modelagem orientada a objetos.
	
- A UML auxilia na visualização do sistema como um todo e os por meio de diagramas padronizados.
	
- Diagramas:
	
	- Diagrama de Caso de Uso;
		
	- Diagrama de Classe;
		
	- Diagrama de Atividade.

> [!NOTE] **Interdependência entre Modelos**
> 
> A partir do modelo de Casos de Uso pode-se obter dados para o modelo de Classes, e a partir do último pode-se adquirir detalhes para refinar o primeiro.

### Diagrama de Casos de Uso (CSU)

- Descreve o que um sistema (ou um subsistema, classe, ou interface)faz, mas não especifica como ele faz.
	
- Dividido em duas partes:
	1. Diagrama – figura ilustrativa das funcionalidades e usuários do sistema;
	2. Documentação – descrição narrativa (textual) das interações que ocorrem 
	   entre o(s) elemento(s) externo(s) e o sistema.

- Representa as funcionalidades do sistema ( RF ):
	- Elementos observáveis do sistema;
	- Elementos que interagem com o sistema.

#### Simbolos

- Caso de Uso:
	
	- Representa uma funcionalidade do Sistema ( RF );
		
	- Representado por uma elipse;
	
	````
	  ___________	
     /	         \
	| Caso de Uso |
     \___________/
        
	````

	- Constituem todas as funcionalidades do Sistema.

- Ator:
	- Representa qualquer coisa externa que interaja com o Sistema;
	- Representado por o desenho de palitinho de uma pessoa;

	````
	  O
     /|\
	 / \
	````

	- Classificados em atores primários ou secondários;
	- Não fazem parte do Sistema;
	- Deve ser conectado a *um ou mais* casos de uso;
	- Representam papéis assumidos e não a pessoa;
	- Um caso de uso é iniciado por um ator para ativar certa funcionalidade no sistema (evento/estímulo).

- Limite (Fronteira do Sistema):
	- Representa o limite do Sistema, isto é até onde deve-se preocupar;
	- Representado por um retângulo.

	````
	 _______
	|	    |
	|	    |
	|_______|
	````

#### Relacionamentos

- Entre *Atores* e *Caso de Uso*:
		
	- Associação.
	
- Entre *Casos de Uso*:
		
	- Generalização (herança);
		
	- Extensão (extend);
		
	- Inclusão (include).
	
- Entre *Atores*:
		
	- Generalização (herança).
	
- Associação:
		
	- Indica que o ator se comunica com o caso de uso:
		
	- Representado por uma linha contínua: ````________```` ;
		
	- Um ator deve estar associado a pelo menos um caso de uso ou a muitos deles.
		
	- Um caso de uso deve estar associado a pelo menos um ator ou a um caso de uso.
	
- Generalização:
		
	- Permite que um caso de uso herde características de um caso de uso mais genérico;
		
	- Permite que um ator herde características de um ator mais genérico;
		
	- O herdeiro pode especializar o comportamento;
		
	- Enfatiza o reuso
		
	- Representado por uma seta: ````---->````;
		
	- "A cabeça da pistola aponta pra geral." 
				Diniz,Caio - 2024.
	
- Inclusão:
	
	- Indicam obrigatoriedade em imininência, isto é, a execução do primeiro obriga
	  a execução do segundo. (o primeiro só acontece se o segundo acontecer primeiro);
		
	- Utilizados quando há ações que servem a mais de um Caso de Uso;
		
	- Representado por uma linha tracejada com seta: ````- - - -> <<include>>````;
		
	- A seta aponta para o Caso de Uso que é obrigatório.
	
- Extensão:
	
	- Utilizadas para descrever uma ação opcional entre Casos de Uso;
		
	- Indica uma complementação ou derivação de uma funcionalidade.
		
	- Permitido colocar vários pontos de extensão no mesmo Caso de Uso;
		
	- Representado por uma linha tracejada com seta em uma das pontas: ````- - - -> <<extends>>````;
		
	- A seta aponta para o Caso de Uso base.

	- Quando usar:
		
		- Para expressar funcionalidades de extensão;
			
		- Para diferenciar um comportamento obrigatório de outro opcional;
			
		- Para separar um trecho do caso de uso que será usado somente em
		  determinadas condições.

- Comentário:
	
	- Contém uma explicação;
	
	- Representado por uma caixinha de texto com a ponta dobrada.
	
	````
	 _______
	|      <\
	|_______|
	
	````

### Diagrama de Classes (UML)

- Apresenta as classes identificadas e detalhamento do modelo de classes, isto é, como o Sistema deve fazer;

- Assim com os Diagramas de Casos de Uso, possui:
	
	- Diagrama de Classes;
		
	- Descrição textual.

- Utilizado na construção do modelo de projetos, além da redefinição do modelo de análise de  requisitos e usado na implementação.

#### Elementos

- Classes;

- Relacionamentos:
	
	- Associação:
		
		- Multiplicidade;
			
		- Agregação e Composição.
		
	- Generalização (herança).

##### Classes

- Representada por uma "caixa" com três compartimentos (níveis) exibidos, são eles: nome, atributos e métodos;
	
	````
	 _________________________
	|        Empregado        |   <- nome
	+-------------------------+
	| - nome: String          |
	| - sobrenome: String     |   <- atributos
	| - cpf: String           |
	+-------------------------+
	| + vencimento() : double |   <- operações
	|_________________________|  
	````
	
	- Atributos:
		
		- Sintaxe: visibilidade NomeAtributo : Tipo
		
		````
		 __________________________________________________________
		|  Simbolo  |   Nome    |          Significado             |
		+-----------+-----------+----------------------------------+
		|     +     | público   | visível em qualquer classe       |
		|     #     | protegido | qualquer descendente pode usar   |
		|     -     | privado   | visível somente dentro da classe |
		|___________|___________|__________________________________|
		````
		
	- Operações (métodos/funções):
		
		- Sintaxe: visibilidade NomeMétodo() : tipoRetorno
			
		- Parâmetros podem aparecer ou serem ocultados.
		
		````
		 __________________________________________________________
		|  Simbolo  |   Nome    |          Significado             |
		+-----------+-----------+----------------------------------+
		|     +     | público   | visível em qualquer classe       |
		|     #     | protegido | qualquer descendente pode usar   |
		|     -     | privado   | visível somente dentro da classe |
		|___________|___________|__________________________________|
		````

##### Relacionamentos

- Associações:
	
	- Representa relacionamento entre classes;
		
	- Permitem que as classes compartilhem informações entre si;
		
	- Descreve um vínculo que ocorre normalmente entre os objetos de uma ou mais classes;
		
	- Pode haver duas associações (ou mais) definidas entre duas classes;
		
	- Representada por uma seta: ````<----->````.
		
	- Associação Reflexiva (autoassociação):
		
		- Associa objetos da mesma classe;
			
		- Cada objeto tem um papel distinto.	
		
	- Multiplicidade:
		
		- Representa as informações dos limites inferior e superior da quantidade de 
		  objetos aos quais outro objeto pode estar associado (cardinalidade do Bando de Dados);
			
		- Obrigatorio no Diagrama.
		
		````
		 _______________________________________
		|         Nome         |   Simbologia   |
		+----------------------|----------------+
		| Apenas um            |       1        |
		| Muitos               |       *        |
		| Um e somente Um      |     1..1       |
		| Zero ou Muitos       |     0..*       |
		| Um ou Muitos         |     1..*       |
		| Zero ou Um           |     0..1       |
		| Intervalo Específico |    Li..Ls      |
		|_______________________________________|
		````

- Generalização:
	
	- Entre duas classes A e B, se A é uma generalização de B, então B é
	  uma especialização de A;
		
	- Representada por uma flecha partindo da subclasse em direção à superclasse: ````B ----|> A````.
		
	- Termos comuns: 
		1. Superclasse e subclasse; 
			
		2. Classe base e classe herdeira;
			
		3. Supertipo e subtipo; 
			
		4. Classe mãe e classe filha.
	
- Agregação e Composição:
	
	- Um objeto está contido no outro OU um objeto contém o outro;
		
	- Um objeto B é parte de um objeto A, o objeto A não pode ser parte do objeto B, pois o objeto A é o TODO.
		
	- Composição:
		
		- Representado por uma linha que conecta as classes *relacionadas*
		  com losângulo preto perto da class que representa o TODO;
			
		-  ````(TODO) <>-----> (PARTE)````;
			
		- Se o TODO não existe, logo a PARTE não existe;
			
		- O TODO é responsável por instanciar sua PARTE;
			
		- As informações da PARTE complementam o entendimento do TODO.
		
	- Agregação:
		
		- Representada por uma linha que conecta as classes *relacionadas* 
		  com um losango sem preenchimento, perto da classe que representa o todo;
			
		-  ````(TODO) <>-----> (PARTE)````;
			
		- Ainda que o TODO não exista pode haver a PARTE;
			
		- O objeto TODO recebe as instâncias do objeto PARTE já prontas;
			
		- O TODO não é responsável por instanciar a PARTE.
		
	- Hierarquia:
		
		- Quando há extensão da agregação ou composição por vários níveis, tem-se uma
		  hierarquia de agregações ou hierarquia de composições.
		
	- Considerações:
		
		- Sempre que uma classe TODO for consultada, além de suas informações, devem ser apresentadas  também as informações da classe PARTE;
			
		- A agregação e a composição, podem, em muitos casos, serem substituídas por uma associação binária simples, dependendo de *QUEM FAZ A MODELAGEM* e do *CONTEXTO DO SOFTWARE*.
		
	- Como saber qual é/usar:

````
Se ( informações são necessárias para complementar as informações de outra class ) {
	Se ( PARTE precisa do TODO para existir && TODO não existe, logo PARTE não existe também ) {
		composição( <>----> );
	} 
	senão {
		agregação ( <>----> );
	} // end if
} 
senão {
	associação ( <-----> );
} // end Se
````


## **Modularização**

### Análise de Requisitos

- Entender as funcionalidades do Sistema, sem preocupar-se com características computacionais.
	
- Transformação do conhecimentos em um modelo que represente as necessidades do Sistema.

### Projeto de Sistemas

- Solução para o problema através da construção de um modelo específico.
	
- É parte do modelo inicial criado na análise, com detalhes computacionais e possíveis mudanças no modelo.
	
- Transformação de algo que é compreensível pelo usuário/cliente para algo compreensível pelo computador.

### Modularização

- É um "pedaço" que contém um conjunto de componentes bem definidos de um Sistema (rotinas, classes, definições de tipos, etc.).
	
- Objetivo facilitar desenvolvimento, manutenção e reutilização de código.
	
- Relação de Uso entre Módulos:
	
	- Para um módulo funcionar é possível que ele utilize um recurso de outro módulo;
		
		- Seta: Sai do módulo que usa para o que é usado.
		
	- Essa relação pode ser vista como *cliente* e o outro como *fornecedor*;
		
	- O módulo 'cliente' deve ser compreendido sem a necessidade de uma análise detalhada de 'fornecedor'.
	
- Princípio Fundamental:
	
	- O módulo A deve ser implementado sem que seja necessário conhecer como o
	  módulo B foi feito (só precisará do valor retornado, fornecido) -> ASSINATURA.
	
- Implementação do Módulo:
	
	- Código que realiza determinado serviço;
		
	- Este serviço pode ser ofertado para o resto do sistema através de uma *interface*.
	
- Interface do Módulo:
	
	- Conjunto de serviços oferecidos por um módulo a seus clientes, ou seja, assinaturas 
	  dos métodos (funções) que implementam determinado tipo de serviço;
		
	- Possuem: tipoRetorno nomeFuncao ( parâmetros, ... ).

### Símbolos

- Pacote:
	
	````
	 _______
	|_______|_______
	|               |
	|               |
	|               |
	|_______________|

	````
	
- Dependência:
	
	````
	- - - - - - ->
	````

