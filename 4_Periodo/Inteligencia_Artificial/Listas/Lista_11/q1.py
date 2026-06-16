import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import StandardScaler
import pickle
from sklearn.ensemble import RandomForestClassifier
from skopt import BayesSearchCV
from skopt.space import Integer, Real, Categorical
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.cluster import DBSCAN
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt
import seaborn as sns
from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder

# * ---------------------------------------
# * Configurações iniciais 
# * ---------------------------------------

analysis = False  # Se True, executa a análise exploratória dos dados
verbose = True  # Se True, exibe informações detalhadas

# * ---------------------------------------
# *  Carregando os dados
# * ---------------------------------------

# Arquivo de treino
training_data = pd.read_csv('titanic/train.csv')

# Arquivo de teste
test_data = pd.read_csv('titanic/test.csv')

# Arquivo com a resposta correta do conjunto de teste
truth_table = pd.read_csv('titanic/gender_submission.csv')

# Adicionando coluna 'Survived' ao test_data
test_data.insert(0, 'Survived', np.nan)

# * ---------------------------------------
# * Análise exploratória dos dados
# * ---------------------------------------

if analysis:
    # --- Vizualizando os dados carregados ---
    print("Dados de treino:")
    print(training_data.head())

    print("\nDados de teste:")
    print(test_data.head())

    print("\nTabela de verdade:")
    print(truth_table.head())

    # --- Verficando as estatísticas descritivas dos dados ---
    print("\nEstatísticas descritivas dos dados de treino:")
    print(training_data.describe())

    print("\nEstatísticas descritivas dos dados de teste:")
    print(test_data.describe())

    print("\nEstatísticas descritivas da tabela de verdade:")
    print(truth_table.describe())

    # --- Verificando valores ausentes ---
    print("\nValores ausentes nos dados de treino:")
    print(training_data.isnull().sum())

    print("\nValores ausentes nos dados de teste:")
    print(test_data.isnull().sum())

    print("\nValores ausentes na tabela de verdade:")
    print(truth_table.isnull().sum())

    # --- Verificando a distribuição de classes na coluna 'Survived' ---
    print("\nDistribuição de classes na coluna 'Survived' dos dados de treino:")
    print(training_data['Survived'].value_counts(normalize=True))

    # --- Verificando os tipos de dados ---
    print("\nTipos de dados nos dados de treino:")
    print(training_data.dtypes)

    print("\nTipos de dados nos dados de teste:")
    print(test_data.dtypes)

    print("\nTipos de dados na tabela de verdade:")
    print(truth_table.dtypes)

# * ---------------------------------------
# * Pré-processamento dos dados
# * ---------------------------------------

# --- Selecionando colunas irrelevantes ou com muitos valores ausentes ou não mais necessárias ---
columns_to_drop = ['PassengerId', 'Name', 'SibSp', 'Parch', 'Ticket', 'Cabin', 'Embarked']
if verbose:
    print("\nColunas a serem removidas:")
    print(columns_to_drop)

# --- Preenchendo valores ausentes ---
# Preenchendo valores ausentes com a média para 'Age' e 'Fare'
training_data['Age'] = training_data['Age'].fillna(training_data['Age'].mean())
training_data['Fare'] = training_data['Fare'].fillna(training_data['Fare'].mean())
if verbose:
    print("\nDados de treino após preenchimento de valores ausentes:")
    print(training_data.head())
    print("\nValores ausentes restantes nos dados de treino:")
    print(training_data.isnull().sum())

test_data['Age'] = test_data['Age'].fillna(test_data['Age'].mean())
test_data['Fare'] = test_data['Fare'].fillna(test_data['Fare'].mean())
if verbose:
    print("\nDados de teste após preenchimento de valores ausentes:")
    print(test_data.head())
    print("\nValores ausentes restantes nos dados de teste:")
    print(test_data.isnull().sum())

# --- Convertendo colunas categóricas em numéricas ---
encoder = LabelEncoder()

training_data['Sex'] = encoder.fit_transform(training_data['Sex'])
if verbose:
    print("\nDados de treino após codificação da coluna:")
    print(training_data.head())

test_data['Sex'] = encoder.transform(test_data['Sex'])
if verbose:
    print("\nDados de teste após codificação da coluna:")
    print(test_data.head())

# --- Criando colunas derivadas ---

title_map = {
    'Master': 0, 'Miss': 1, 'Mrs': 2, 'Mr': 3, 'Rare': 4
}

# Criando colunas 'FamilySize' e 'isAlone'
training_data['FamilySize'] = training_data['SibSp'] + training_data['Parch'] + 1
training_data['isAlone'] = (training_data['FamilySize'] == 1).astype(int)

# Extraindo títulos dos nomes e convertendo em categorias numéricas
training_data['Title'] = training_data['Name'].str.extract(r' ([A-Za-z]+)\.', expand=False)
training_data['Title'] = training_data['Title'].replace(['Lady', 'Countess', 'Capt', 'Col', 'Don', 'Dr', 'Major', 'Rev', 'Sir'], 'Rare')
training_data['Title'] = training_data['Title'].replace(['Mlle', 'Ms'], 'Miss')
training_data['Title'] = training_data['Title'].replace(['Mme'], 'Mrs')
training_data['Title'] = training_data['Title'].map(title_map).fillna(5).astype(int)

if verbose:
    print("\nDados de treino após criação da coluna 'FamilySize' e 'isAlone':")
    print(training_data.head())

# Criando colunas 'FamilySize' e 'isAlone' no conjunto de teste
test_data['FamilySize'] = test_data['SibSp'] + test_data['Parch'] + 1
test_data['isAlone'] = (test_data['FamilySize'] == 1).astype(int)

# Extraindo títulos dos nomes e convertendo em categorias numéricas no conjunto de teste
test_data['Title'] = test_data['Name'].str.extract(r' ([A-Za-z]+)\.', expand=False)
test_data['Title'] = test_data['Title'].replace(['Lady', 'Countess', 'Capt', 'Col', 'Don', 'Dr', 'Major', 'Rev', 'Sir'], 'Rare')
test_data['Title'] = test_data['Title'].replace(['Mlle', 'Ms'], 'Miss')
test_data['Title'] = test_data['Title'].replace(['Mme'], 'Mrs')
test_data['Title'] = test_data['Title'].map(title_map).fillna(5).astype(int)

if verbose:
    print("\nDados de teste após criação da coluna 'FamilySize' e 'isAlone':")
    print(test_data.head())

# --- Normalizando colunas numéricas ---
scaler = StandardScaler()

training_data[['Age', 'Fare', 'FamilySize']] = scaler.fit_transform(training_data[['Age', 'Fare', 'FamilySize']])
if verbose:
    print("\nDados de treino após normalização:")
    print(training_data.head())

test_data[['Age', 'Fare', 'FamilySize']] = scaler.transform(test_data[['Age', 'Fare', 'FamilySize']])
if verbose:
    print("\nDados de teste após normalização:")
    print(test_data.head())

# --- Remover colunas irrelevantes ou com muitos valores ausentes ou não mais necessárias ---
training_data.drop(columns=columns_to_drop, inplace=True)
if verbose:
    print("\nDados de treino após remoção de colunas:")
    print(training_data.head())

test_data.drop(columns=columns_to_drop, inplace=True)
if verbose:
    print("\nDados de teste após remoção de colunas:")
    print(test_data.head())

# * ---------------------------------------
# * Salvando os dados pré-processados
# * ---------------------------------------

training_data.to_csv('titanic/processed_train.csv', index=False)
test_data.to_csv('titanic/processed_test.csv', index=False)

# * ---------------------------------------
# * Separando os dados de treino e teste
# * ---------------------------------------

X_train = training_data.drop(columns=['Survived'])
y_train = training_data['Survived']

X_test = test_data.drop(columns=['Survived'])
y_test = truth_table['Survived']

# --- Salvando os dados de treino e teste em um arquivo pickle ---
with open('titanic/train_test_data.pkl', 'wb') as f:
    pd.to_pickle((X_train, y_train, X_test, y_test), f)

# * ---------------------------------------
# * Otimizando os hiperparâmetros do modelo
# * ---------------------------------------

# --- Random Forest ---
# Definindo o modelo de Random Forest e os hiperparâmetros a serem otimizados
rf_model = RandomForestClassifier(random_state=42)

# Definindo o espaço de busca para os hiperparâmetros
rf_space = {
    'n_estimators': Integer(100, 1000),
    'max_depth': Integer(3, 30),
    'min_samples_split': Integer(2, 20),
    'min_samples_leaf': Integer(1, 20),
    'max_features': Categorical(['sqrt', 'log2', None]),
    'bootstrap': Categorical([True, False])
}

# Realizando a busca bayesiana para otimização dos hiperparâmetros
rf_search = BayesSearchCV(
    estimator=rf_model,
    search_spaces=rf_space,
    n_iter=50,
    cv=5,
    scoring='accuracy',
    n_jobs=-1,
    random_state=42
)

# Ajustando o modelo de Random Forest aos dados de treino
rf_search.fit(X_train, y_train)

# Obtendo os melhores hiperparâmetros e o melhor modelo
best_rf_params = rf_search.best_params_
best_rf = rf_search.best_estimator_
if verbose:
    print("\nMelhores hiperparâmetros encontrados para Random Forest:")
    print(best_rf_params)
    print("\nMelhor modelo de Random Forest:")
    print(best_rf)

# --- MLP (Multi-layer Perceptron) ---
# Definindo o modelo de MLP e os hiperparâmetros a serem otimizados
mlp_model = MLPClassifier(max_iter=1000, random_state=42)

# Definindo o espaço de busca para os hiperparâmetros do MLP
mlp_space = {
    'hidden_layer_sizes': Integer(5, 500),
    'activation': Categorical(['tanh', 'relu']),
    'solver': Categorical(['adam', 'sgd']),
    'alpha': Real(1e-5, 1e-1, prior='log-uniform'),  # regularização L2
    'learning_rate_init': Real(1e-4, 1e-1, prior='log-uniform')
}

# Realizando a busca bayesiana para otimização dos hiperparâmetros do MLP
mlp_search = BayesSearchCV(
    estimator=mlp_model,
    search_spaces=mlp_space,
    n_iter=50,
    cv=5,
    scoring='accuracy',
    n_jobs=-1,
    random_state=42
)

# Ajustando o modelo de MLP aos dados de treino
mlp_search.fit(X_train, y_train)

best_mlp_params = mlp_search.best_params_
best_mlp = mlp_search.best_estimator_
if verbose:
    print("\nMelhores hiperparâmetros encontrados para MLP:")
    print(best_mlp_params)
    print("\nMelhor modelo de MLP:")
    print(best_mlp)

# * ---------------------------------------
# * Treinando e avaliando os modelos
# * ---------------------------------------

# --- Random Forest ---
# --- Treinando o modelo de Random Forest com os melhores hiperparâmetros encontrados ---
rf_model = RandomForestClassifier(**best_rf_params, random_state=42)
rf_model.fit(X_train, y_train)

# Obtendo previsões do modelo de Random Forest nos dados de teste
y_pred_rf = rf_model.predict(X_test)
if verbose:
    # --- Avaliando o modelo de Random Forest ---
    print("\nAcurácia do modelo de Random Forest nos dados de teste:")
    print(accuracy_score(y_test, y_pred_rf))

    print("\nRelatório de classificação do modelo de Random Forest:")
    print(classification_report(y_test, y_pred_rf))

    print("\nMatriz de confusão do modelo de Random Forest:")
    print(confusion_matrix(y_test, y_pred_rf))

# --- MLP (Multi-layer Perceptron) ---
# ---Treinando o modelo de MLP com os melhores hiperparâmetros encontrados ---
mlp_model = MLPClassifier(**best_mlp_params, max_iter=1000, random_state=42)
mlp_model.fit(X_train, y_train)

# Obtendo previsões do modelo de MLP nos dados de teste
y_pred_mlp = mlp_model.predict(X_test)
if verbose:
    # --- Avaliando o modelo de MLP ---
    print("\nAcurácia do modelo de MLP nos dados de teste:")
    print(accuracy_score(y_test, y_pred_mlp))

    print("\nRelatório de classificação do modelo de MLP:")
    print(classification_report(y_test, y_pred_mlp))

    print("\nMatriz de confusão do modelo de MLP:")
    print(confusion_matrix(y_test, y_pred_mlp))

# * ---------------------------------------
# * Identificando agrupamentos de passageiros com perfis semelhantes
# * ---------------------------------------

# --- Preparando os dados para clustering ---
# Remover a coluna 'Survived' para clustering
X = X_train.copy()

# One-Hot Encoding da coluna 'Title' (mantém outras numéricas como estão)
X = pd.get_dummies(X, columns=['Title'], prefix='Title')

# Identificar colunas numéricas que devem ser padronizadas
num_cols = ['Age', 'Fare', 'FamilySize']

# Padronizar apenas as colunas numéricas
scaler = StandardScaler()
X_scaled = X.copy()
X_scaled[num_cols] = scaler.fit_transform(X_scaled[num_cols])

# --- Aplicando DBSCAN ---
# Aplicando DBSCAN para encontrar clusters
dbscan = DBSCAN(eps=1.0, min_samples=3)
clusters = dbscan.fit_predict(X)

# Adicionando os rótulos ao DataFrame
X_clustered = training_data.copy()
X_clustered['Cluster'] = clusters

# Quantidade de clusters e ruídos
n_clusters = len(set(clusters)) - (1 if -1 in clusters else 0)
n_noise = list(clusters).count(-1)
if verbose:
    print("\nNúmero de clusters encontrados:", n_clusters)
    print("Número de pontos de ruído:", n_noise)

# --- Visualizando os clusters ---
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X)

X_clustered['PCA1'] = X_pca[:, 0]
X_clustered['PCA2'] = X_pca[:, 1]

plt.figure(figsize=(10, 6))
sns.scatterplot(
    x='PCA1', y='PCA2',
    hue='Cluster',
    data=X_clustered,
    palette='tab10',
    style=(X_clustered['Cluster'] == -1).map({True: 'X', False: 'o'}),
    s=100
)
plt.title('Clusters de Passageiros com DBSCAN (PCA)')
plt.legend(title='Cluster')
plt.show()

# Distribuição de sobreviventes por cluster
print("\nDistribuição de sobreviventes por cluster:")
print(X_clustered.groupby('Cluster')['Survived'].value_counts(normalize=True))

# Estatísticas descritivas por cluster
print("\nEstatísticas descritivas por cluster:")
for c in sorted(X_clustered['Cluster'].unique()):
    print(f'\nCluster {c}:\n', X_clustered[X_clustered['Cluster'] == c].describe(include='all'))

# * ---------------------------------------
# * Identificando padrões no comportamento dos passageiros
# * ---------------------------------------

# --- Preparando os dados categóricos ---
df = training_data.copy()

# Mapear valores categóricos
df['Sex'] = df['Sex'].map({0: 'male', 1: 'female'})
df['Survived'] = df['Survived'].map({0: 'Not Survived', 1: 'Survived'})
df['Pclass'] = df['Pclass'].map({1: '1st class', 2: '2nd class', 3: '3rd class'})
df['isAlone'] = df['isAlone'].map({0: 'not alone', 1: 'alone'})
df['Title'] = df['Title'].map({
    0: 'Master', 1: 'Miss', 2: 'Mrs', 3: 'Mr', 4: 'Rare', 5: 'Unknown'
})

# Criar grupos etários
df['AgeGroup'] = pd.cut(
    df['Age'],
    bins=[-1, 12, 18, 35, 60, 120],
    labels=['Child', 'Teen', 'Adult', 'MiddleAged', 'Senior']
)

# Selecionar colunas categóricas relevantes
df_apriori = df[['Sex', 'Pclass', 'isAlone', 'Survived', 'Title', 'AgeGroup']].astype(str)
df_apriori = df_apriori.applymap(str.strip)

# Converter para formato de transações
transactions = df_apriori.values.tolist()
te = TransactionEncoder()
te_ary = te.fit(transactions).transform(transactions)
df_encoded = pd.DataFrame(te_ary, columns=te.columns_)

# --- Aplicar Apriori e gerar regras ---

frequent_itemsets = apriori(df_encoded, min_support=0.03, use_colnames=True)
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.6)
rules = rules.sort_values(by='lift', ascending=False)

# --- Visualizando as regras de associação ---
if verbose:
    print("\nRegras com consequente 'Survived':")
    print(rules.loc[rules['consequents'] == {'Survived'}, ['antecedents', 'consequents', 'support', 'confidence', 'lift']])
    print("\nRegras com consequente 'Not Survived':")
    print(rules.loc[rules['consequents'] == {'Not Survived'}, ['antecedents', 'consequents', 'support', 'confidence', 'lift']])
