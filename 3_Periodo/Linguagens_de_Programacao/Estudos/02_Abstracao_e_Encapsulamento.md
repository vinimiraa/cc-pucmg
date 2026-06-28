# **Abstração e Encapsulamento**
## **Abstração**

O conceito de **abstração** em programação é fundamental para simplificar o desenvolvimento de sistemas complexos. Ele permite focar no que um programa faz, sem se preocupar com os detalhes de como isso é implementado.

1. **O que é abstração?**  
	
    Abstração é o processo de identificar as propriedades essenciais de um fenômeno e ignorar os detalhes irrelevantes. Em programação, isso se refere à distinção entre **o que** uma parte do programa faz (a sua interface) e **como** ela é implementada (os detalhes internos).
	
2. **Tipos de Abstrações**:
	
    - **Abstração de Função**: Uma função encapsula uma expressão a ser avaliada. Do ponto de vista do usuário, ao chamar a função, ele fornece argumentos e obtém um resultado. O programador, no entanto, sabe que a função avalia esses argumentos para produzir o resultado.
		
    - **Abstração de Procedimento**: Similar às funções, os procedimentos encapsulam uma série de comandos que atualizam variáveis. Um procedimento pode alterar o estado do programa com base em seus parâmetros.
	
3. **Princípio da Abstração**:  
	
    Esse princípio diz que podemos construir abstrações sobre qualquer conjunto de elementos sintáticos, desde que essas abstrações representem alguma computação. Ele ajuda a organizar o código e torná-lo mais expressivo e modular.
	
4. **Parâmetros**:
	
    - **Argumentos**: um valor que pode ser passado para uma abstração.
		
        - **Parâmetros Formais**: São identificadores usados dentro de funções ou procedimentos para referenciar os argumentos passados.
			
        - **Parâmetros Reais**: São os valores ou expressões fornecidos ao chamar uma função ou procedimento.
	
    - **Mecanismos de Passagem de Parâmetros**: Determinam como os valores são associados entre os parâmetros formais e reais. Existem diferentes métodos, como **passagem por valor** (cópia do valor) ou **passagem por referência** (um link direto para a variável original).
		
        - **Por Cópia**: permite que e valores sejam copiados para dentro ou para fora de uma abstração.
		        
	        - Desvantagem: a cópia de valores compostos pode ter custo alto.
		
        - **Por Definição**: o permite que um parâmetro formal X seja amarrado diretamente ao argumento.
	        
            - **Constante**: o argumento é um valor. X é amarrado ao valor do argumento durante a ativação da abstração chamada;
	            
            - **Referência**: o argumento é uma referência a uma variável, logo qualquer utilização de X é, na verdade, uma utilização indireta do argumento
				
            - **Procedimental**: o argumento é uma abstração de procedimento, logo qualquer chamada a X é, na verdade, uma chamada indireta ao procedimento.
				
            - **Funcional**: : o argumento é uma abstração de função, logo qualquer chamada a X é, na verdade, uma chamada indireta à função.
		
        - **Por Nome**:
				
            - Cada ocorrência do parâmetro é considerada como sendo textualmente substituída pelo argumento. Podendo levar a complicações.
				
            - A passagem de nome é poderosa, porque permite passar funções e procedimentos, além das variáveis simples e estruturadas.
				
            - A passagem de nome pode levar a programas que são difíceis de ler.
	
    - **Mecanismos de Definição X Mecanismos de Cópia**:
	    
        - O mecanismo de definição possui uma semântica mais simples.
	        
        - O mecanismo de definição, em geral, é mais eficiente.
	        
        - Uma desvantagem dos parâmetros variáveis é a possibilidade de utilização de apelidos (“*aliasing*”), o que torna o programa mais difícil de entender.
	        
        - Em algumas situações, os parâmetros constantes e variável possibilitam um poder de expressão similar aos dos mecanismos de cópia. Assim, a escolha é uma decisão importante para o projetista da linguagem.
		
    - **Princípio da Correspondência**: para cada forma de declaração, existe um mecanismo de passagem de parâmetro e vice-versa, em outras palavras qualquer declaração pode ser passada como parâmetro para uma função ou procedimento.
	
5. **Mecanismos de Avaliação**:
	
    - **Avaliação Prévia**: O parâmetro é avaliado no momento da chamada da função.
		
    - **Avaliação de Ordem Normal (*Lazy*)**: O parâmetro é avaliado apenas quando necessário durante a execução.
			
        - **Avaliação Tardia**: O parâmetro é avaliado apenas na primeira vez que for utilizado.
		
    - O resultado pode variar dependendo da ordem de avaliação.
	
6. **Funções Estritas e Não Estritas**:
	
    - **Funções Estritas** exigem que todos os argumentos possam ser avaliados antes da execução.
		
    - **Funções Não Estritas** podem ser executadas mesmo que alguns de seus argumentos não possam ser completamente avaliados, o que oferece flexibilidade, mas pode ter implicações de desempenho.
	
7. **Vantagens da Abstração**:

    A abstração permite reutilização de código, facilita a manutenção e torna mais fácil a colaboração em projetos maiores, pois cada parte do sistema pode ser entendida e desenvolvida de forma independente, ocultando os detalhes desnecessários.
	
8. **Propriedade de *Church-Rosser***:

    Se uma expressão pode ser avaliada, então ela pode ser avaliada através da utilização consistente da avaliação de ordem normal. Se uma avaliação pode ser realizada em ordens diferentes (misturando ordem normal e aplicativa), então todas as ordens de avaliação produzirão o mesmo resultado.
	    
    - Qualquer LP que permita efeitos colaterais não possui a propriedade de Church-Rosser.


## **Encapsulamento**

**Encapsulamento** é um conceito fundamental em programação que tem como objetivo organizar e modularizar grandes sistemas, protegendo detalhes internos e expondo apenas o necessário para o funcionamento externo, facilitando a manutenção, a reutilização de código e a organização de projetos maiores.

1. **O que é encapsulamento?**
	
    Encapsulamento é o processo de esconder os detalhes internos de um módulo ou objeto, expondo apenas o que é necessário para que outros módulos possam interagir com ele. Um **módulo** é uma unidade de código que pode conter variáveis, funções, procedimentos, e outros componentes. O encapsulamento facilita a **reutilização** de código, pois ao esconder a complexidade interna, garante que o módulo possa ser usado de forma independente.
	
2. **Pacotes e Módulos**
	
    Pacotes são exemplos de módulos em linguagens de programação. Eles agrupam declarações de componentes como variáveis, funções e procedimentos. A principal característica de um pacote é o **ocultamento de informações**, onde certas partes são acessíveis externamente (componentes exportáveis), enquanto outras são mantidas ocultas para serem usadas apenas internamente no pacote.
	
3. **Ocultamento de Informação (*Information Hiding*)**
	
    Esse conceito refere-se à ideia de mostrar apenas o que é necessário e ocultar os detalhes que não são relevantes para o uso externo. Isso reduz a complexidade para os usuários de um módulo e protege contra o uso inadequado de detalhes internos que podem ser alterados sem que o usuário precise saber. Um exemplo em linguagens como Ada é a separação entre a **declaração** e o **corpo** de um pacote, onde a declaração expõe a interface e o corpo implementa os detalhes.
	
4. **Tipos Abstratos de Dados**
	
    Um **tipo abstrato de dados** é um tipo definido por um conjunto de operações. Os detalhes sobre como esse tipo é representado ficam escondidos, e os usuários só interagem com ele por meio dessas operações. Isso evita problemas como a confusão entre diferentes tipos que possuem a mesma estrutura. Por exemplo, é possível ter dois tipos, como `data` e `racional`, que têm a mesma estrutura interna, mas devem ser tratados de forma diferente.
	
5. **Objetos e Classes**
	
    **Objetos** são variáveis ou módulos com suas próprias operações encapsuladas. Eles protegem os dados e garantem que mudanças internas não afetem outros módulos. Uma **classe** é uma definição genérica de um objeto, que pode ser instanciada para criar objetos específicos. Uma classe define quais operações são permitidas sobre seus objetos, mas oculta os detalhes de implementação.
	
6. **Abstrações Genéricas**
	
    Uma **abstração genérica** é uma abstração que permite criar estruturas flexíveis que podem ser aplicadas a diferentes tipos de dados. Um exemplo são **pacotes genéricos**, que podem ser instanciados para diferentes tipos de dados, como criar uma pilha de inteiros ou uma pilha de objetos.