# **Sistema de Tipo**

## **Definição e Função**

Um **sistema de tipos** é uma coleção de regras que define como atribuir tipos às várias partes de um programa. O **verificador de tipos** é a implementação prática dessas regras, garantindo que construções sintáticas sigam as normas do sistema.


## **Monomorfismo**

- Um sistema **monomórfico** exige que constantes, variáveis, parâmetros e resultados de funções sejam explicitamente declarados com um tipo específico.

- **Vantagem**: Verificação simples e direta.

- **Desvantagem**: Dificulta a reutilização, já que não suporta algoritmos ou estruturas genéricas.

- Exemplo: Pascal, onde abstrações definidas pelo programador são monomórficas, mas algumas funções padrão, como `write` e `eof`, introduzem polimorfismo e sobrecarga, criando inconsistências no sistema.


## **Sobrecarga**

A **sobrecarga** permite associar múltiplas entidades a um mesmo identificador ou operador:

- **Polimorfismo ad-hoc**: Requer que chamadas sejam desambiguadas com base no tipo dos argumentos ou do contexto.
	
- Tipos:
	- **Independente de contexto**: Baseia-se no tipo dos parâmetros para diferenciar funções.
	- **Dependente de contexto**: Considera o contexto e pode introduzir ambiguidades.


## **Polimorfismo**

Relaciona-se a abstrações que operam uniformemente sobre valores de diferentes tipos:

- **Polimorfismo paramétrico**: Uso de variáveis de tipo ao invés de tipos específicos. Exemplo em ML:

  ```ml
  fun segundo (x: σ, y: τ) = y
  ```
  
- Aqui, `σ` e `τ` representam qualquer tipo.


## **Tipos Parametrizados**

- Um tipo que aceita outros tipos como parâmetros. Exemplos:
	
	- Em Pascal: tipos pré-definidos como `array` ou `set`.
		
	- Em ML: definição flexível, permitindo programadores criarem novos tipos parametrizados.


## **Politipos**

- Contêm variáveis de tipo (e.g., `σ x τ → τ`) e derivam uma família de tipos por substituição. Politipos permitem abstrações genéricas e são contrastados com monotipos, que não possuem variáveis de tipo.


## **Inferência de Tipo**

- **Monomórfica**: O compilador deduz o tipo com base no contexto. Exemplo em ML:

  ```ml
  fun par(n) = (n mod 2 = 0)
  ```

	Aqui, `par` é inferido como `integer → boolean`.  

- **Polimórfica**: Permite inferir politipos. Exemplo:

  ```ml
  fun length (l) =
    case l of
      nil → 0
    | cons (h, t) → 1 + length(t)
  ```
 
	`length` é inferido como `Lista(τ) → integer`.


## **Coerção**

- Transformação implícita de valores entre tipos diferentes (type casting). Exemplo:

	- Coerção explícita em Ada: `Float(x)`.
		
	- Linguagens modernas tendem a evitar coerção para evitar ambiguidades.


## **Subtipos e Herança**

- Relacionado à possibilidade de subtipos herdarem operações de seus supertipos:
	
	- Exemplo em Pascal: intervalos como subtipos de tipos primitivos.
		
	- Subtipos devem ser subconjuntos seguros (`S ⊆ T`).
	
- Conexão com Programação Orientada a Objetos, onde herança permite reuso de operações e propriedades.