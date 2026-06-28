# **Introdução à Aprendizagem de Máquina**

A aprendizagem de máquina é uma área da inteligência artificial que se concentra na criação de programas de computador capazes de melhorar seu desempenho com base na experiência adquirida.

- Um programa aprende a partir da experiência $E$, em relação a uma classe de tarefas $T$, com uma medida de desempenho $P$, se seu desempenho em $T$, medido por $P$, melhora com $E$. [^1]
	
- Em termos práticos, a aprendizagem de máquina envolve treinar modelos com dados para que possam generalizar decisões e resolver problemas com base em uma métrica de desempenho específica.[^2]

![[Machine_Learning_Algorithms_Map.png]]

## **Estrutura de Dados**

| Dia | Aparência | Temperatura | Umidade | Ventando | Jogar |
| --- | --------- | ----------- | ------- | -------- | ----- |
| d1  | Sol       | Quente      | Alta    | Não      | Não   |
| d2  | Nublado   | Quente      | Alta    | Não      | Sim   |
| ... | ...       | ...         | ...     | ...      | ...   |
| d13 | Nublado   | Quente      | Normal  | Não      | Sim   |
| d14 | Chuva     | Agradável   | Alta    | Sim      | Não   |

- **Cada linha** da tabela representa uma **instância**, ou seja, um exemplo individual.
	
- As colunas **Dia**, **Aparência**, **Temperatura**, **Umidade** e **Ventando** são os **atributos de entrada**, que fornecem informações para o modelo.
	
- A coluna **Jogar** é o **atributo de classificação**, que o modelo tenta prever.
	
- Os atributos podem ser:
	- **Nominais**: Representam categorias ou rótulos, como "Sol" ou "Nublado".
	- **Numéricos**: Representam valores quantitativos, como temperatura em graus.


## **Tipos de Problema**

Os algoritmos de aprendizagem de máquina podem ser classificados com base no **tipo de problema** que resolvem:

### Classificação

- O objetivo é prever ou descrever uma classe específica.
	- O atributo de classificação é **nominal**.

Exemplo:

- Determinar se um e-mail é "spam" ou "não spam" com base em seu conteúdo.

### Regressão

- Semelhante à classificação, mas o atributo de classe é **numérico**.

Exemplos:

- Prever o preço de uma casa com base em atributos como tamanho, localização e número de quartos.  
	
- Estimar a temperatura de uma cidade com base em dados meteorológicos.
	
- Determinar a expectativa de vida de uma pessoa com base em fatores como idade, saúde e estilo de vida.

### Agrupamento (*Clusterização*)

- O objetivo é agrupar instâncias com base nos atributos de entrada, sem um atributo de classificação conhecido.

Exemplo:

- Identificar grupos de clientes com comportamentos de compra semelhantes em um e-commerce.

Por que é útil?  

- Permite descobrir padrões ocultos nos dados, como segmentação de mercado ou perfis de usuários.

### Regras de Associação

- Busca identificar semelhanças ou associações entre elementos.

Exemplo:

- Em sistemas de e-commerce, identificar que clientes que compraram o produto A também compraram o produto B.

Por que é útil?  

- Ajuda a criar estratégias de vendas, como recomendações de produtos.


## **Tipos de Aprendizagem**

Os algoritmos de aprendizagem de máquina também podem ser classificados com base no **tipo de aprendizagem**:

### Aprendizado Supervisionado

O modelo recebe um conjunto de exemplos na forma $(entrada, rótuloDesejado)$, onde o rótulo é conhecido.

Técnicas:

- Redes Neurais do tipo *Multilayer Perceptron*.
	
- *Support Vector Machine* (SVM).
	
- Árvores de Decisão: [[02_Arvore_de_Decisao]].

Exemplo:

- Treinar um modelo para classificar imagens de gatos e cachorros com base em um conjunto de imagens rotuladas.

### Aprendizado Não-Supervisionado

O modelo recebe apenas os atributos de entrada, sem rótulos, e o objetivo é identificar padrões ou agrupamentos.

Técnicas:

- Redes Neurais do tipo mapas auto-organizáveis.
	
- Algoritmo k-médias.

Exemplo:

- Agrupar clientes de um banco com base em seus hábitos financeiros.

### Aprendizado Semi-Supervisionado

Combina dados rotulados e não rotulados para melhorar o desempenho do modelo.

Técnicas:

- *Support Vector Machine* (SVM).

Exemplo:

- Treinar um modelo para classificar documentos, onde apenas uma parte dos documentos possui rótulos.

### Aprendizado por Reforço

Focado na maximização de recompensas com base nos resultados de ações tomadas pelo modelo.

Técnicas:  

- Redes neurais.

Exemplo:

- Treinar um agente para jogar xadrez, onde ele aprende a maximizar suas chances de vitória com base em recompensas obtidas durante o jogo.

### Deep Learning

Consiste em redes neurais com muitas camadas, onde cada camada reconhece padrões de complexidade crescente.

Técnicas:  

- Redes neurais profundas.

Exemplo:

- Reconhecimento facial em imagens, onde as camadas iniciais identificam bordas e formas básicas, e as camadas mais profundas reconhecem características faciais complexas.


## **Descoberta do Conhecimento**

De acordo com Wives [^3], **descobrir conhecimento** significa **identificar**, **receber informações relevantes**, e **processá-las e agregá-las** ao conhecimento prévio do usuário, alterando seu estado atual de conhecimento para resolver uma situação ou problema.

### Mineração de Dados

É o processo de descoberta de padrões interessantes e desconhecidos em grandes bancos de dados.

Por que é importante?  

- Permite extrair informações úteis de grandes volumes de dados, auxiliando na tomada de decisões.

A mineração de dados é uma etapa do processo geral de descoberta de conhecimento em bancos de dados (KDD - *Knowledge Discovery in Databases*).

O processo KDD é definido como "o processo não trivial de identificar padrões válidos, novos, potencialmente úteis e, finalmente, compreensíveis em dados"[^4].

Exemplo:

- Identificar padrões de compra em um supermercado, como a relação entre a compra de pão e leite.

[^1]: Mitchell, T. M. (1997). *Machine Learning*. McGraw-Hill.

[^2]: Brownlee, J. (2016). *Master Machine Learning Algorithms*. Machine Learning Mastery.

[^3]: WIVES, L. Tecnologias de descoberta de conhecimento em textos aplicadas à inteligência competitiva. Exame de Qualificação EQ-069, PPGC-UFRGS, 2002.

[^4]: Fayyad, U., Piatetsky-Shapiro, G., & Smyth, P. (1996). From Data Mining to Knowledge Discovery in Databases. *AI Magazine, 17*(3), 37–54.
