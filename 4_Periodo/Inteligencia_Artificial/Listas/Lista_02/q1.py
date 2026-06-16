import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import GridSearchCV
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from yellowbrick.classifier import ConfusionMatrix
from sklearn import tree

# Ler o arquivo de treino
training_data = pd.read_csv( 'titanic/train.csv' )
# Ler o arquivo de teste
test_data = pd.read_csv( 'titanic/test.csv' )
# Ler o arquivo com a resposta correta do o conjunto de teste
truth_table = pd.read_csv( 'titanic/gender_submission.csv' )

# Adicionar coluna 'Survived' ao test_data
test_data = test_data.merge(truth_table, on='PassengerId', how='left')

# ------------------------------------
# --- Pre-processamentos de Dados
# ------------------------------------

# Remover colunas irrelevantes ou com muitos valores ausentes
columns_to_drop = ['PassengerId', 'Name', 'Ticket', 'Cabin', 'Embarked']

# Transformação de dados categóricos
encoder = LabelEncoder()
training_data['Sex'] = encoder.fit_transform( training_data['Sex'] )
test_data['Sex']     = encoder.transform( test_data['Sex'] )

# Preenchendo valores ausentes
training_data['Age'] = training_data['Age'].fillna( training_data['Age'].median( ) )
test_data['Age']     = test_data['Age'].fillna( test_data['Age'].median( ) )

training_data['Fare'] = training_data['Fare'].fillna( training_data['Fare'].median( ) )
test_data['Fare']     = test_data['Fare'].fillna( test_data['Fare'].median( ) )

# Separar variáveis independentes e dependentes
X_treino = training_data.drop( columns = columns_to_drop + ['Survived'], axis = 1 ) # X_treino = colunas de treino
y_treino = training_data['Survived']                                                # y_treino = coluna de resposta

X_teste  = test_data.drop( columns = columns_to_drop + ['Survived'], axis = 1  )    # X_teste = colunas de teste
y_teste  = test_data['Survived']                                                    # y_teste = coluna de resposta

# ------------------------------------
# --- Descobrir melhores hiperparâmetros
# ------------------------------------

# Definição de hiperparâmetros para Decision Tree
params = {
    'criterion'        : ['gini', 'entropy'],
    'max_depth'        : [None, 2, 3, 4],
    'max_features'     : [None, 'sqrt', 'log2', 0.2, 0.4, 0.6, 0.8],
    'min_samples_split': [20, 30, 40, 50]
}

# Encontrar melhores hiperparâmetros
modelo = GridSearchCV(
    estimator  = DecisionTreeClassifier( ),
    param_grid = params,
    cv         = 10,
    n_jobs     = 5,
    verbose    = 1,
)

# Treina o modelo com os dados de treino (X_treino e y_treino)
modelo.fit( X_treino, y_treino )
print( "Melhores hiperparâmetros..:", modelo.best_params_ )
print( "Melhor pontuação..........:", modelo.best_score_ )

# ------------------------------------
# --- Treinar o Modelo
# ------------------------------------

# Treinar modelo final com os melhores hiperparâmetros
modelo_final = DecisionTreeClassifier(
    max_depth         = 4, 
    criterion         = 'gini',
    max_features      = modelo.best_params_['max_features'],
    min_samples_split = modelo.best_params_['min_samples_split'],
    random_state      = 42
)
modelo_final.fit( X_treino, y_treino )

# ------------------------------------
# --- Testar e Avaliar o Modelo
# ------------------------------------

# Resetar os índices dos DataFrames
X_treino = X_treino.reset_index( drop=True )
y_treino = y_treino.reset_index( drop=True )
X_teste  = X_teste.reset_index( drop=True )
y_teste  = y_teste.reset_index( drop=True )

# Fazer previsões
y_pred = modelo_final.predict( X_teste )

# Avaliar o modelo
print( "Acurácia do modelo........:", accuracy_score( y_teste, y_pred ) )
print( "Matriz de Confusão........:\n", confusion_matrix( y_teste, y_pred ) )
print( "Relatório de Classificação:\n", classification_report( y_teste, y_pred ) )

# Plotar a matriz de confusão
cm = ConfusionMatrix( modelo_final )
cm.fit( X_treino, y_treino )
cm.score( X_teste, y_teste )
cm.show( )  # Exibir a matriz de confusão

# Plotar a árvore de decisão
plt.figure( figsize = (10, 10) )
tree.plot_tree(
    modelo_final,
    feature_names = X_treino.columns,
    class_names   = ['Não Sobreviveu', 'Sobreviveu'],
    filled        = True,
    rounded       = True
)
plt.show( )  # Exibir a árvore de decisão

# Importância das features
importancias = modelo_final.feature_importances_
features     = pd.DataFrame( {'Feature': X_treino.columns, 'Importância': importancias} )
features     = features.sort_values( by='Importância', ascending=False )
print( features )