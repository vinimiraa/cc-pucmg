# **Definições**

## **Objetivo**

- **Aumentar a vida útil** do sistema dentro os limites de QoS.
	
- **Prever e afastar ao máximo a fase de super-utilização** do sistema, que corresponde à saturação permanente do sistema.
	
- É uma área da computação que propõe uma metodologia com as seguintes ações: (**M**)onitorar, (**C**)oletar, (**I**)dentificar horários críticos, (**S**)intetizar, (**A**)nalisar, (**O**)timizar, (**P**)rever, (**M**)odelar, (**C**)onfigurar e (**N**)egociar.
	
- O que interessa é a **carga de trabalho gerada** pelos usuários, ao acessar as aplicações, e que **podem afetar o desempenho** do sistema.

## **Carga de Trabalho**

Quantidade de requisições que chegam no sistema por unidade de tempo, $requições/min$.

## **Variável de Controle**

Variável mensurável que reflete o desempenho atual do sistema: $\mathbb{R} = (Resposta) , \lambda = (Carga), \mathbb{U} = (Utilização)$.

## **Nível de Serviço**

Desempenho atual entregue pelo sistema e é representado pelo par: $(\lambda, \mathbb{R})$ ou $(\lambda, \mathbb{U})$.

## **Curva Teórica**

Corresponde ao lugar geométrico dos níveis de serviço.

## **LNS / SLA**

LNS = Limites do Nível de Serviço.
SLA = *Service Level Agreement*.

## **Ponto Crítico (P.C.)**

Interseção entre LNS e a curva de desempenho

## **Capacidade do Sistema**

Carga de trabalho correspondente ao P.C..

## **Vida Útil**

Tempo durante o qual o sistema opera no limite do LNS e do P.C..

## **Carga de Saturação**

Corresponde a carga que leva o sistema a operar com 100% de utilização (tipicamente do processador).

## **Fórmulas**

- $\mathbb{R} =$ Tempo de resposta do sistema ($tempo/requisição$): 

$$
\mathbb{R} = \frac{\overline{D_i}}{1 - \mathbb{U_i}} = \frac{\overline{D_i}}{1 - \overline{D_i}\lambda_i}
$$

- $\lambda_{sat} =$ Carga de saturação ($requisição/tempo$):

$$
\lambda_{sat} = \frac{1}{\overline{D_i}}
$$

- $\lambda_c$ = Carga crítica ($requisição/tempo$):

$$
\lambda_c = \frac{LNS - \overline{D_i}}{LNS \cdot \overline{D_i}}
$$

- $\lambda_{otimo} =$ Carga ótima ($requisição/tempo$):

$$
\lambda_{otimo} = \frac{0.5}{1.05 \cdot \overline{D_i}}
$$

- $\mathbb{U} =$ Utilização do sistema ($\%$):

$$
\mathbb{U} = \overline{D_i} \cdot \lambda_c
$$

- $D_u =$ Disponibilidade do sistema:

$$
D_u = 1 - \mathbb{U}
$$

