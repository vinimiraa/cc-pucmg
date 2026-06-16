import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import GridSearchCV, RandomizedSearchCV
from sklearn.tree import DecisionTreeClassifier
from skopt import BayesSearchCV

# Ler o arquivo de treino
training_data = pd.read_csv( 'titanic/train.csv' )

# ------------------------------------
# --- Pre-processamentos de Dados
# ------------------------------------

# Remover colunas irrelevantes ou com muitos valores ausentes
columns_to_drop = ['PassengerId', 'Name', 'Ticket', 'Cabin', 'Embarked']

# Transformação de dados categóricos
encoder = LabelEncoder()
training_data['Sex'] = encoder.fit_transform( training_data['Sex'] )

# Preenchendo valores ausentes
training_data['Age'] = training_data['Age'].fillna( training_data['Age'].median( ) )

training_data['Fare'] = training_data['Fare'].fillna( training_data['Fare'].median( ) )

# Separar variáveis independentes e dependentes
X_treino = training_data.drop( columns = columns_to_drop + ['Survived'], axis = 1 ) # X_treino = colunas de treino
y_treino = training_data['Survived']                                                # y_treino = coluna de resposta

# ------------------------------------
# --- Otimização de Hiperparâmetros
# ------------------------------------

# Definição de hiperparâmetros para Otimizador de HIPERPARÂMETROS
params = {
    'criterion'        : ['gini', 'entropy'],
    'max_depth'        : [None, 2, 4, 6, 8, 10],
    'max_features'     : [None, 'sqrt', 'log2', 0.2, 0.4, 0.6, 0.8],
    'min_samples_split': [2, 5, 10, 20],
    'min_samples_leaf' : [1, 5, 10, 20],
    'max_leaf_nodes'   : [None, 5, 10, 20, 50]
}

# GridSearchCV para otimização
grid_search = GridSearchCV(
    estimator  = DecisionTreeClassifier( ),  # Modelo de Classificação
    param_grid = params,                     # Dicionário de Hiperparâmetros
    cv         = 10,                         # Cross-Validation (número de divisões para validação cruzada)
    n_jobs     = 1,                          # Número de Processos Paralelos
    verbose    = 1                           # Exibir detalhes da execução
)
grid_search.fit( X_treino, y_treino )

print( "Melhores parâmetros (GridSearchCV)......:", grid_search.best_params_ )
print( "Acurácia (GridSearchCV).................:", grid_search.best_score_ )

# RandomizedSearchCV
random_search = RandomizedSearchCV(
    DecisionTreeClassifier( ),     # Modelo de Classificação
    param_distributions = params,  # Dicionário de Hiperparâmetros
    cv                  = 10,      # Cross-Validation (número de divisões para validação cruzada)
    n_jobs              = 1,       # Número de Processos Paralelos
    verbose             = 1        # Exibir detalhes da execução
)
random_search.fit( X_treino, y_treino )

print( "Melhores parâmetros (RandomizedSearchCV):", random_search.best_params_ )
print( "Acurácia (RandomizedSearchCV)...........:", random_search.best_score_ )

# BayesSearchCV
bayes_search = BayesSearchCV(
    DecisionTreeClassifier( ),   # Modelo de Classificação
    search_spaces= params,       # Dicionário de Hiperparâmetros
    cv           = 5,            # Cross-Validation (número de divisões para validação cruzada)
    n_jobs       = 1,            # Número de Processos Paralelos 
    verbose      = 1             # Exibir detalhes da execução
)
bayes_search.fit( X_treino, y_treino )

print( "Melhores parâmetros (BayesSearchCV).....:", bayes_search.best_params_ )
print( "Acurácia (BayesSearchCV)................:", bayes_search.best_score_ )
