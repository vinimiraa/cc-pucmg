# Inferência Estatística

## **Estimação de Parâmetros**

- **Inferência Estatística**:
	Procedimentos para fazer generalizações sobre as características de uma população a partir da informação contida na amostra.
	
- **Estimação**: 
	É o processo que consiste em utilizar dados amostrais para estimar os valores de parâmetros populacionais desconhecidos. Qualquer característica de uma população pode ser estimada a partir de uma amostra aleatória.
	
- **Parâmetros**:
	São as características populacionais, geralmente desconhecidas:
	- $\mu$ = média populacional.
	- $\sigma$ = desvio padrão populacional. 
	- $p$ = proporção populacional. 
	
	> Como o cálculo destes parâmetros é quase impossível, estimamos os valores a partir de uma amostra da população.
	
- **Estimadores (ou Estatísticas)**:
	
| Parâmetro | Estimador                                                                       |
| --------- | ------------------------------------------------------------------------------- |
| $\mu$     | $$\overline{x} = \frac{x_1 + x_2 + \cdots + x_n}{n}$$                           |
| $\sigma$  | $$s = \sqrt{\frac{\sum(x_i - \overline{x})^2}{n-1}}$$                           |
| $p$       | $$\hat{p} = \frac{\text{nº de elementos com a caraterística de interesse}}{n}$$ |
	
- **Estimativa**:
	- Estimativas Pontuais: 
		- Valores dos estimadores ($\overline{x}, s, \hat{p}$).
		- Nem sempre são iguais aos valores populacionais, embora estes possam ser bem próximos.
	- Estimativa Intervalar: Fornece um intervalo de valores possíveis, no qual se admite, com certa confiança, que contenha o verdadeiro valor do parâmetro populacional.

## **Distribuições Amostrais dos Estimadores**

### Distribuição Amostral da Média

- $\mu = E(X)$
- $\sigma = \sqrt{Var(X)}$

Pelo **Teorema Central do Limite**:

| Distribuição de $X$        | Tamanho da Amostra | Distribuição de $\overline{X}$              |
| -------------------------- | ------------------ | ------------------------------------------- |
| $X \sim N(\mu; \; \sigma)$ | Qualquer           | $X \sim N(\mu; \; \frac{\sigma}{\sqrt{n}})$ |
| Qualquer                   | $n \ge 30$         | $X \sim N(\mu; \; \frac{\sigma}{\sqrt{n}})$ |

### Distribuição Amostral da Proporção

- $\mu = E(X) = p$
- $\sigma^2 = Var(X) = p(1 - p)$

Pelo **Teorema Central do Limite** para $n$ grande pode-se considerar que:

$$\hat{p} \sim N (p, \, \sqrt{\frac{p(1 - p)}{n}})$$

## **Intervalo de Confiança**

- Um intervalo de confiança consiste em um limite inferior e um limite superior, construídos através de duas partes: uma estimativa pontual para o parâmetro de interesse $\pm$ uma margem de erro que descreve a precisão da estimativa. 

### Intervalos de Confiança para $\mu$ (média populacional)

-  CASO 1: População Normal, $\sigma$ conhecido
	
$$IC = \overline{X} \pm z_{\frac{\alpha}{2}} (\frac{\sigma}{\sqrt{n}})$$
	
- CASO 2: População Normal, $\sigma$ desconhecido
	
$$T = \frac{\overline{X} - \mu_0}{\frac{S}{\sqrt{n}}}$$
	
$$IC = \overline{X} \pm t_{(n-1;\frac{\alpha}{2})} (\frac{S}{\sqrt{n}})$$
	
- CASO 3: População Normal, $\sigma$ desconhecido, grandes amostras
	
$$IC = \overline{X} \pm z_{\frac{\alpha}{2}} (\frac{S}{\sqrt{n}})$$

### Intervalos de Confiança para $p$ (proporção populacional)

$$IC = \hat{p} \pm z_{\frac{\alpha}{2}} \sqrt{\frac{\hat{p}(1 - \hat{p})}{n}}$$

## **Determinação do Tamanho da Amostra**

-  $E$ é a margem de erro máxima admitida.
 
- Para a estimação de $\mu$:

$$n = (\frac{z_{\frac{\alpha}{2}} \times \sigma}{E})^2$$

- Para a estimação de $p$:

$$n = \hat{p}(1 - \hat{p})(\frac{z_{\frac{\alpha}{2}}}{E})^2$$

## **Teste de Hipóteses**

### Conceitos

#### Hipóteses 

- Hipótese nula ($H_0$): é a hipótese aceita como verdadeira até que existam evidências estatísticas que comprovem o contrário. 
	
- Hipótese alternativa ($H_1$): é a hipótese de interesse, a hipótese que rejeita a hipótese nula.
#### Nível de Significância ($\alpha$)

É a probabilidade de ocorrência do erro Tipo I, ou seja: 

$$\alpha = P(\text{rejeitar } H_0 \mid H_0 \text{ é verdadeiro})$$

#### Estatística de Teste

|                       | Testes para uma média                                      | Teste para uma proporção                                  |
| --------------------- | ---------------------------------------------------------- | --------------------------------------------------------- |
| $\sigma$ conhecido    | $Z = \frac{\overline{X} - \mu_0}{\frac{\sigma}{\sqrt{n}}}$ |                                                           |
| $\sigma$ desconhecido | $T = \frac{\overline{X} - \mu_0}{\frac{S}{\sqrt{n}}}$      |                                                           |
| $n \ge 30$            | $Z = \frac{\overline{X} - \mu_0}{\frac{S}{\sqrt{n}}}$      | $Z = \frac{\hat{p} - p_0}{\sqrt{\frac{p_0(1 - p_0)}{n}}}$ |

#### Região de Rejeição

É um valor, obtido através das tabelas das distribuições, que será comparado com o valor da estatística de teste para que se decida sobre a rejeição ou não de $H_0$.

> A região de rejeição depende da hipótese alternativa (bilateral ou unilateral).

- Bilateral: rejeita-se $H_0$ se:
	- $Z < -z_{\frac{\alpha}{2}}$
	- $Z > z_{\frac{\alpha}{2}}$
	- $T > t_{(n-1;\;\frac{\alpha}{2})}$
	- $T < -t_{(n-1;\;\frac{\alpha}{2})}$

### Como Calcular

1. **Definir as Hipóteses:**
    
    - $H_0$: hipótese nula (ex.: $\mu = \mu_0$)
        
    - $H_1$: hipótese alternativa (ex.: $\mu > \mu_0$, $\mu < \mu_0$ ou $\mu \ne \mu_0$)
    
2. **Calcular a Estatística de Teste**.
    
3. **Determinar a Região Crítica (Região de Rejeição)**.
	
	- Calcular o $z_{\alpha}$ ou $t_{(n-1; \; \alpha)}$ e procurar na tabela o valor e determinar $Z$ ou $T$ a partir disso, isto é, fazer o processo inverso. 
    
4. **Conclusão:**
    
    - De onde saiu a conclusão;
		
	- Rejeita ou não rejeita a hipótese (opcional);
		
	- Qual o nível de significância ($\alpha$);
		
	- Conclusão em termos de problema.
