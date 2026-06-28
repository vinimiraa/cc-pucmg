# Naive Bayes

## **Introdução**

O **Naive Bayes** é um algoritmo de classificação baseado no **Teorema de Bayes**, assumindo que as variáveis preditoras são estatisticamente independentes entre si. Essa suposição de independência raramente é verdadeira na prática, mas o algoritmo ainda se mostra eficiente para muitas aplicações, especialmente em problemas de classificação de texto e filtragem de spam.

O **Teorema de Bayes** é definido como:

$$
P(A|B) = \frac{P(B|A)*P(A)}{P(B)}
$$
onde:

- $P(A|B)$ é a probabilidade do evento $A$ ocorrer dado que $B$ ocorreu;
    
- $P(B|A)$ é a probabilidade do evento $B$ ocorrer dado que $A$ ocorreu;
    
- $P(A)$ e $P(B)$ são as probabilidades individuais de $A$ e $B$.


## **Como Construir**

### Exemplo de Cálculo

Dado um conjunto de treinamento que avalia riscos de crédito:

| História do crédito | Dívida | Garantias | Renda Anual       | Risco    |
| ------------------- | ------ | --------- | ----------------- | -------- |
| Ruim                | Alta   | Nenhuma   | <15000            | Alto     |
| Desconhecida        | Alta   | Nenhuma   | >=15000 a <=35000 | Alto     |
| Desconhecida        | Baixa  | Nenhuma   | >=15000 a <=35000 | Moderado |
| Desconhecida        | Baixa  | Nenhuma   | >35000            | Alto     |
| Desconhecida        | Baixa  | Nenhuma   | >35000            | Baixo    |
| Desconhecida        | Baixa  | Adequada  | >35000            | Baixo    |
| Ruim                | Baixa  | Nenhuma   | <15000            | Alto     |
| Ruim                | Baixa  | Adequada  | >35000            | Moderado |
| Boa                 | Baixa  | Nenhuma   | >35000            | Baixo    |
| Boa                 | Alta   | Adequada  | >35000            | Baixo    |
| Boa                 | Alta   | Nenhuma   | <15000            | Alto     |
| Boa                 | Alta   | Nenhuma   | >=15000 a <=35000 | Moderado |
| Boa                 | Alta   | Nenhuma   | >35000            | Baixo    |
| Ruim                | Alta   | Nenhuma   | >=15000 a <=35000 | Alto     |
Assim temos:

|          | Risco |
| :------- | :---: |
| Alto     | 6/14  |
| Moderado | 3/14  |
| Baixo    | 5/14  |

| Risco    | Histórico de Crédito | Histórico de Crédito | Histórico de Crédito |
| :------- | :------------------: | :------------------: | :------------------: |
| -        |         Boa          |     Desconhecido     |         Ruim         |
| Alto     |         1/6          |         2/6          |         3/6          |
| Moderado |         1/3          |         1/3          |         1/3          |
| Baixo    |         3/5          |         2/5          |         0/5          |

| Risco    | Dívida | Dívida |
| :------- | :----: | :----: |
| -        |  Alta  | Baixa  |
| Alto     |  4/6   |  2/6   |
| Moderado |  1/3   |  2/3   |
| Baixo    |  2/5   |  3/5   |

| Risco    | Garantia | Garantia |
| :------- | :------: | :------: |
| -        |   Alta   |  Baixa   |
| Alto     |   6/6    |   0/6    |
| Moderado |   2/3    |   1/3    |
| Baixo    |   3/5    |   2/5    |

| Risco    | Renda Anual |    Renda Anual    | Renda Anual |
| :------- | :---------: | :---------------: | :---------: |
| -        |   <15000    | >=15000 a <=35000 |   >35000    |
| Alto     |     3/6     |        2/6        |     1/6     |
| Moderado |     0/3     |        2/3        |     1/3     |
| Baixo    |     0/5     |        0/5        |     5/5     |

Podemos calcular as probabilidades para uma nova entrada com os seguintes atributos:

- História: Boa
	
- Dívida: Alta
	
- Garantias: Nenhuma
	
- Renda: >35000

Calculando, temos:

$P(alto) = 6/14 * 1/6 * 4/6 * 6/6 * 1/6$
$P(alto) = 0,0079$

$P(moderado) = 3/14 * 1/3 * 1/3 * 2/3 * 1/3$  
$P(moderado) = 0,0052$  
  
$P(baixo) = 5/14 * 3/5 * 2/5 * 3/5 * 5/5$  
$P(baixo) = 0,0514$  

$Soma:$
$0,0079 + 0,0052 + 0,0514 = 0,0645$

$P(alto) = 0,0079/0,0645*100 = 12,24$ 
$P(moderado) = 0,0052/0,0645*100=8,06$
$P(baixo) = 0,0514/0,0645*100 = 79,68$  

Obtemos que:

- P(Alto) = 12,24%
    
- P(Moderado) = 8,06%
    
- P(Baixo) = 79,68%

Neste caso, a classe "Baixo" seria a predição final.

### Passos

1. **Coletar os dados:** Criar um conjunto de treinamento com atributos e suas respectivas classes.
    
2. **Calcular as probabilidades a priori:** Determinar a probabilidade de cada classe com base na distribuição dos dados.
    
3. **Calcular as probabilidades condicionais:** Para cada atributo, calcular a probabilidade condicional dentro de cada classe.
    
4. **Multiplicar as probabilidades:** Aplicar o **Teorema de Bayes** multiplicando as probabilidades condicionais pelos valores a priori de cada classe.
    
5. **Normalizar os valores:** Dividir cada probabilidade pelo somatório das probabilidades obtidas para garantir que a soma seja 1.
    
6. **Selecionar a classe com maior probabilidade:** A classe com maior valor final será a predição para o novo registro.


## **Vantagens e Desvantagens**

### Vantagens

- **Simples e rápido:** Requer poucos recursos computacionais.
    
- **Funciona bem com grandes volumes de dados.**
    
- **Eficiente para classificação de texto:** Ampliamente utilizado em filtragem de spam e análise de sentimentos.
    
- **Não exige grande quantidade de dados para treinamento.**

### Desvantagens

- **Suposição de independência:** Na prática, muitos atributos são correlacionados, o que pode impactar a precisão.
    
- **Desempenho inferior em dados com forte dependência entre variáveis.**
    
- **Pode ser sensível a dados pouco balanceados.**