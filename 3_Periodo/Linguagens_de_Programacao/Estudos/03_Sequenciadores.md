# **Sequenciadores**

## **Definição**

Sequenciadores são construções que alteram o fluxo normal de controle (uma única entrada e saída). Eles tornam possíveis fluxos mais genéricos, mas podem introduzir complexidade na programação.

## **Tipos de Sequenciadores**

Os principais tipos são:

- **Saltos (*Jumps*)**: Transferência explícita de controle para outro ponto do programa.
	
- **Escapes**: Interrupções que levam diretamente à saída de comandos.
	
- **Exceções (*Exceptions*)**: Tratamento de condições excepcionais que impedem a execução normal do programa.

### **Saltos (*Jumps*)**

- Permitem transferir controle para *labels* específicos, como `goto L`.
	
- Exemplo de fluxos:
	
	- **Sequencial**: Usa saltos explícitos entre labels.
		
	- **Condicional**: Salta com base em condições.
		
	- **Iterativo**: Realiza saltos para criar loops.
	
- **Vantagens**:
	
	- Simples e eficiente em programas pequenos.
		
	- Oferece controle genérico.
	- 
- **Desvantagens**:
	
	- Torna o código ilegível ("código espaguete").
		
	- Introduz complexidade semântica, especialmente ao lidar com variáveis locais e procedimentos recursivos.

> [!NOTE] Restrições:
> 
> Linguagens como Pascal restringem saltos, permitindo apenas saltar entre blocos específicos, mas proibindo saltos para dentro de procedimentos.

### **Escapes**

- Um escape finaliza a execução de um comando delimitado, permitindo múltiplas saídas com uma única entrada.

Exemplos:

- **C**: Uso de `break` e `continue` para controle de loops.
	
- **Ada**: Permite nomear loops para escapes direcionados.
	
- ***Return***: Retorna de uma função, finalizando sua execução.
	
- ***Halt***: Encerra a execução do programa inteiro.
	

### **Exceções (*Exceptions*)**

- Tratam condições excepcionais, como erros de aritmética (overflow), divisão por zero, ou falhas de I/O.
	
- **Alternativas**:
	
	- **Interromper o programa**: Simples, mas inflexível e pouco robusto.
		
	- **Tratadores de exceção**: Transferem controle para uma seção de código que lida com a exceção.

#### Técnicas de Tratamento

1. **Códigos de Resultado**: Cada abstração retorna um código que indica sucesso ou erro.
	
	- Desvantagem: Programas podem ficar confusos e sujeitos a erros de omissão nos testes.
	
2. **Tratadores de Exceção**:
	
	Exemplo em **Java**:
	
	 ```java
	 try {
		 // código
	 } catch (ExceptionType e) {
		 // tratamento
	 } finally {
		 // código executado sempre
	 }
	 ```
    
   - Tratadores podem ser associados a comandos específicos ou compartilhados entre exceções.

#### Vantagens

- Modularidade e robustez.
	
- Permite execução controlada em cenários inesperados.

#### Exemplo

Um programa tenta converter uma *string* em um número inteiro. Se a *string* não for válida, uma `NumberFormatException` é capturada, e uma mensagem é exibida ao invés de encerrar o programa.


## **Considerações Finais**

Sequenciadores, quando usados adequadamente, fornecem flexibilidade na programação. No entanto, abuso de mecanismos como saltos pode comprometer a legibilidade e manutenção do código, enquanto exceções bem tratadas promovem robustez e modularidade.

