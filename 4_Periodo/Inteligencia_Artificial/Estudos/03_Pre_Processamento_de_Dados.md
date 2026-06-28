# **Pré-Processamento de Dados**

O pré-processamento de dados é uma das etapas mais importantes, pois a ausência dessa etapa pode enviesar o modelo.

- **Classe Majoritária**: Classe com maior frequência de dados.
- **Classe Minoritária**: Classe com menor frequência de dados.

## **Dados Desbalanceados**

Algoritmos de **Aprendizado de Máquina** podem ter seu desempenho prejudicado na presença de **dados desbalanceados**.  

Quando treinados com dados desbalanceados, esses algoritmos tendem a classificar novos dados na **classe majoritária**.

### Como Resolver

As principais técnicas para resolver este problema são:

#### 1. Redefinir o tamanho do conjunto de dados:

Podemos adicionar instâncias à **classe minoritária** (métodos de ***oversampling***) ou remover instâncias da **classe majoritária** (métodos de ***undersampling***).

- **Problemas com Oversampling**:

	- Risco de criar instâncias irreais, levando a um modelo inadequado.
	- Possibilidade de ***overfitting***, onde o modelo se ajusta excessivamente aos dados de treinamento.

- **Problemas com Undersampling**:  

	- Eliminação de dados importantes da classe majoritária, o que pode prejudicar o modelo.
	- Possibilidade de ***underfitting***, onde o modelo não se ajusta adequadamente aos dados de treinamento.

#### 2. Utilizar diferentes custos de classificação para as classes:

Atribuir custos diferentes para erros de classificação nas classes majoritária e minoritária.  

- Exemplo: Se a classe majoritária tem o dobro de exemplos da classe minoritária, um erro na classe minoritária pode ser considerado equivalente a dois erros na classe majoritária.  
Definir esses custos, no entanto, pode ser desafiador.

#### 3. Induzir um modelo para uma única classe:

Treinar o modelo separadamente para a classe majoritária ou minoritária.  

1. Com o método ***SMOTE*** (*oversampling*).

```python
# $ pip install imbalanced-learn
from imblearn.over_sampling import SMOTE

base = pd.read_csv('/content/sample_data/cancer.csv’, sep=';’)
# Processa base
# Incluir aqui todas as etapas de pré-processamento

# Dividir em conjunto de treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(
	X_prev,
	y_classe,
	test_size = 0.20,
	random_state = 42
)

# Balanceamento com qualquer método oversampling  
smote = SMOTE(random_state=42)
X_resampled, y_resampled = smote.fit_resample(X_treino, y_treino)

# Treinar o modelo com estes arquivos gerados com o Smote
# Depois testar com o arquivo de teste (que está desbalanceado)
```

2. Com o método ***TomekLinks*** (*undersampling*).

```python
# $ pip install imbalanced-learn
from imblearn.under_sampling import TomekLinks

base = pd.read_csv('/content/sample_data/cancer.csv’, sep=';’)
# Processa base
# Incluir aqui todas as etapas de pré-processamento

# Dividir em conjunto de treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(
	X_prev,
	y_classe,
	test_size = 0.20,
	random_state = 42
)

# Balanceamento com qualquer método undersampling  
balanceamento_under = TomekLinks(sampling_strategy='auto')
X_under, y_under = balanceamento_under.fit_resample(X_treino, y_treino)

# Treinar o modelo com estes arquivos gerados com o TomekLinks
# Depois testar com o arquivo de teste (que está desbalanceado)
```

3. Com o método ***RandomUnderSampler*** (*undersampling*).

```python
# $ pip install imbalanced-learn
from imblearn.under_sampling import RandomUnderSampler

base = pd.read_csv('/content/sample_data/cancer.csv’, sep=';’)
# Processa base
# Incluir aqui todas as etapas de pré-processamento

# Dividir em conjunto de treino e teste
X_treino, X_teste, y_treino, y_teste = train_test_split(
	X_prev,
	y_classe,
	test_size = 0.20,
	random_state = 42
)

# Balanceamento com qualquer método undersampling  
undersample = RandomUnderSampler(random_state=42)
X_resampled, y_resampled = undersample.fit_resample(X_treino, y_treino)

# Treinar o modelo com estes arquivos gerados com o RandomUnderSampler
# Depois testar com o arquivo de teste (que está desbalanceado)
```

> [!IMPORTANT] **Importante**  
> Ao usar métodos de ***undersampling***, inclua no conjunto de teste as instâncias descartadas pelo método.

## **Dados Ausentes**

As bases de dados podem conter dados ausentes, o que pode comprometer a qualidade dos dados.

Dados ausentes podem ser causados por:

- Problemas nos equipamentos que realizam a coleta.
- Transmissão e armazenamento dos dados.
- Problemas no preenchimento ou na entrada dos dados por seres humanos.
- O atributo não foi considerado importante na época da coleta.
- Falta de conhecimento do campo.
- Falta de necessidade ou obrigação de apresentar um valor para o atributo.
- Inexistência de um valor para o atributo em algumas instâncias.

Algumas técnicas de Aprendizagem de Máquina ($AM$) conseguem lidar bem com dados ausentes, mas isso não acontece com todos os métodos de $AM$.

### Como Resolver

As principais técnicas para resolver este problema são:

#### 1. Eliminar as instâncias com dados ausentes:

Esta alternativa é geralmente empregada quando um dos atributos com valores ausentes de uma instância é o que indica a sua classe.

Esta estratégia não é recomendada quando:  

- Poucos atributos da instância possuem valores ausentes.
- O número de atributos com valores ausentes varia muito entre as instâncias com esse problema.
- O número de instâncias que restarem for pequeno.

#### 2. Definir e preencher manualmente valores para os atributos com valores ausentes:

Esta estratégia não é recomendada quando:

- O número de instâncias ou atributos com valores ausentes for muito grande.

#### 3. Utilizar algum método ou heurística para automaticamente definir valores para atributos com valores ausentes:

Esta estratégia é uma das **mais recomendadas**.

Como imputar estes dados ausentes?

- Moda, média dos valores dos atributos.
- Empregar um indutor para estimar o valor do atributo.

#### 4. Empregar algoritmos de Aprendizagem de Máquina que lidam internamente com valores ausentes:

Este é o caso, por exemplo, de alguns algoritmos indutores de árvore de decisão.

Em **python**, tem os métodos:

- *MissForest*.

```python
$ pip install missingpy
from missingpy import MissForest
```

- *KNNImputer*.

```python
from sklearn.impute import KNNImputer
```

## **Dados Inconsistentes**

Os **dados inconsistentes** são aqueles que apresentam **valores conflitantes em seus atributos**.

Eles costumam surgir durante o processo de integração de dados, quando diferentes conjuntos podem adotar escalas ou padrões distintos para a mesma medida (por exemplo, um conjunto pode utilizar metros, enquanto outro emprega centímetros).

Um exemplo de inconsistência ocorre quando duas instâncias idênticas possuem classificações divergentes.

| Idade | Sexo | Peso | Manchas      | Temp. | # int. | Diagnóstico |
| ----- | ---- | ---- | ------------ | ----- | ------ | ----------- |
| 22    | F    | 72   | Inexistentes | 38,0  | 3      | Doente      |
| 22    | F    | 72   | Inexistentes | 38,0  | 3      | Saudável    |

### Como Resolver

1. **Normalização de Dados**: Converter todas as unidades para um padrão comum. 

2. **Validação e Regras de Integridade**: Definir regras para evitar valores conflitantes.

3. **Detecção e Correção Manual**: Revisar e corrigir manualmente registros que apresentem divergências críticas. 

Exemplo: No conjunto de dados **Iris**, uma inconsistência pode ocorrer se algumas medidas forem registradas em **centímetros** e outras em **milímetros**.  

```python
import pandas as pd

# Carregar dataset
df = pd.read_csv("iris.csv")

# Exibir valores únicos na coluna 'sepal_length' para verificar unidades inconsistentes
print(df["sepal_length"].unique())

# Converter valores inconsistentes (milímetros para centímetros, se necessário)
df["sepal_length"] = df["sepal_length"].apply(lambda x: x / 10 if x > 100 else x)
```

## **Dados Redundantes**

Os **dados redundantes** podem se referir tanto a **instâncias** quanto a **atributos**.

### Quanto a Instâncias:

Uma **instância** é **redundante** quando ela é **muito semelhante** a uma outra instância do mesmo conjunto de dados.

Em casos extremos, instâncias da mesma base de dados podem ser literalmente iguais

Exemplo 1: muito semelhantes.

| Sexo | Escolaridade | FaixaEtaria | Renda | Area | GostaA | GostaB |
| ---- | ------------ | ----------- | ----- | ---- | ------ | ------ |
| F    | 1            | 2           | 4     | 5    | S      | N      |
| F    | 1            | 2           | 4     | 7    | S      | S      |

Exemplo 2: idênticas.

| Idade | Sexo | Peso | Manchas      | Temp. | # int. | Diagnóstico |
| ----- | ---- | ---- | ------------ | ----- | ------ | ----------- |
| 18    | F    | 67   | Inexistentes | 39,5  | 4      | Doente      |
| 18    | F    | 67   | Inexistentes | 39,5  | 4      | Doente      |

### Quanto a Atributos:

Um **atributo** é **redundante** quando seu valor para todas as instâncias **pode ser deduzido** a partir do valor de um ou mais atributos.

Em casos extremos, quando o atributo possui o mesmo valor que um outro atributo para cada uma das instâncias da base de dados.

Exemplo: dedução da idade a partir da data de nascimento.

| Data de Nascimento | Idade |
| ------------------ | ----- |
| 2010               | 15    |
| 2014               | 11    |
| 2007               | 18    |

A redundância de um atributo está relacionada à sua **correlação** com um ou mais atributos do conjunto de dados.

- Dois ou mais atributos estão **correlacionados** quando apresentam um perfil de variação semelhante para as diferentes instâncias.

- Se a correlação ocorrer entre um atributo de entrada e um atributo de classificação, este atributo de entrada terá uma grande influência na predição do valor do atributo rótulo.

### Como Resolver

1. **Eliminação de Duplicatas**: Identificar e remover registros repetidos.  

2. **Normalização de Banco de Dados**: Aplicar boas práticas de modelagem para evitar redundância.  

3. **Uso de Chaves Primárias**: Garantir que cada registro seja único e evitar repetições desnecessárias.  

Exemplo: Duplicatas podem ocorrer se um mesmo espécime for registrado mais de uma vez.

```python
# Verificar registros duplicados
duplicatas = df[df.duplicated()]
print(duplicatas)

# Remover duplicatas mantendo a primeira ocorrência
df = df.drop_duplicates()
```
