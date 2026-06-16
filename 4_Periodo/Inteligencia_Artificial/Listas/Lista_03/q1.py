import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import GridSearchCV
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
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
    'max_depth'        : [2, 3, 4],
    'max_features'     : ['sqrt', 'log2', 0.2, 0.4, 0.6, 0.8],
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

# Treinar modelo de gini com os melhores hiperparâmetros
modelo_gini = DecisionTreeClassifier(
    criterion         = 'gini',
    max_depth         = modelo.best_params_['max_depth'], 
    max_features      = modelo.best_params_['max_features'],
    min_samples_split = modelo.best_params_['min_samples_split'],
    random_state      = 42
)
modelo_gini.fit( X_treino, y_treino )

# Treinar modelo de entropia com os melhores hiperparâmetros
modelo_entropia = DecisionTreeClassifier(
    criterion         = 'entropy',
    max_depth         = modelo.best_params_['max_depth'], 
    max_features      = modelo.best_params_['max_features'],
    min_samples_split = modelo.best_params_['min_samples_split'],
    random_state      = 42
)
modelo_entropia.fit( X_treino, y_treino )

# ------------------------------------
# --- Testar e Avaliar o Modelo
# ------------------------------------

# Fazer previsões
y_pred_gini     = modelo_gini.predict( X_teste )
y_pred_entropia = modelo_entropia.predict( X_teste )

# Avaliar o modelo
print( "Acurácia do modelo - Gini............:", accuracy_score( y_teste, y_pred_gini ) )
print( "Matriz de Confusão - Gini............:\n", confusion_matrix( y_teste, y_pred_gini ) )
print( "Relatório de Classificação - Gini....:\n", classification_report( y_teste, y_pred_gini ) )

print( "Acurácia do modelo - Entropia........:", accuracy_score( y_teste, y_pred_entropia ) )
print( "Matriz de Confusão - Entropia........:\n", confusion_matrix( y_teste, y_pred_entropia ) )
print( "Relatório de Classificação - Entropia:\n", classification_report( y_teste, y_pred_entropia ) )

# Matriz de Confusão
def plot_confusion_matrix( y_true, y_pred, title ):
    cm = confusion_matrix( y_true, y_pred )
    sns.heatmap( 
        cm, annot=True, fmt='d', cmap='Blues', 
        xticklabels=['Não Sobreviveu', 'Sobreviveu'], 
        yticklabels=['Não Sobreviveu', 'Sobreviveu']
    )
    plt.xlabel( 'Previsto' )
    plt.ylabel( 'Real' )
    plt.title( title )
    plt.show( )

plot_confusion_matrix( y_teste, y_pred_gini, "Matriz de Confusão - Gini" )
plot_confusion_matrix( y_teste, y_pred_entropia, "Matriz de Confusão - Entropia" )

# Árvores de Decisão
def plot_decision_tree( modelo, title ):
    plt.figure( figsize=(15, 10) )
    tree.plot_tree(
        modelo,
        feature_names = X_treino.columns,
        class_names   = ['Não Sobreviveu', 'Sobreviveu'],
        filled        = True,
        rounded       = True
    )
    plt.title( title )
    plt.show( )

plot_decision_tree( modelo_gini, "Árvore de Decisão - Critério Gini" )
plot_decision_tree( modelo_entropia, "Árvore de Decisão - Critério Entropy" )

# Importância das features
def plot_feature_importance( modelo, X_treino ):
    importancias = modelo.feature_importances_
    features     = pd.DataFrame( {'Feature': X_treino.columns, 'Importância': importancias} )
    features     = features.sort_values( by='Importância', ascending=False )
    return features

print( "Importância das Features - Gini" )
print( plot_feature_importance( modelo_gini, X_treino ) )

print( "\nImportância das Features - Entropia" )
print( plot_feature_importance( modelo_entropia, X_treino ) )

