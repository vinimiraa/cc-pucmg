import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from yellowbrick.classifier import ConfusionMatrix
from imblearn.over_sampling import SMOTE
from skopt import BayesSearchCV
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
test_data['Sex'] = encoder.transform( test_data['Sex'] )

# Preenchendo valores ausentes
training_data['Age'] = training_data['Age'].fillna( training_data['Age'].median( ) )
test_data['Age'] = test_data['Age'].fillna( test_data['Age'].median( ) )

training_data['Fare'] = training_data['Fare'].fillna( training_data['Fare'].median( ) )
test_data['Fare'] = test_data['Fare'].fillna( test_data['Fare'].median( ) )

# Separar variáveis independentes e dependentes
X_treino = training_data.drop( columns = columns_to_drop + ['Survived'], axis = 1 ) # X_treino = colunas de treino
y_treino = training_data['Survived']                                                # y_treino = coluna de resposta

X_teste = test_data.drop( columns = columns_to_drop + ['Survived'], axis = 1 ) # X_teste = colunas de teste
y_teste = test_data['Survived']                                                # y_teste = coluna de resposta

# Balenceamento dos dados com SMOTE
smote = SMOTE( random_state = 42 )
X_resampled, y_resampled = smote.fit_resample( X_treino, y_treino )

print( "Antes do balanceamento  - X:\n", X_treino.value_counts( ) )
print( "Depois do balanceamento - X:\n", X_resampled.value_counts( ) )

print( "Antes do balanceamento  - y:\n", y_treino.value_counts( ) )
print( "Depois do balanceamento - y:\n", y_resampled.value_counts( ) )

# ------------------------------------
# --- Descobrir melhores hiperparâmetros
# ------------------------------------

# Hiperparâmetros Random Forest
rf_params = {
    'n_estimators': (50, 200),
    'max_depth': (2, 10),
    'max_features': ['sqrt', 'log2'],
    'min_samples_split': (2, 10)
}

# Otimização Random Forest
rf_modelo = BayesSearchCV(
    RandomForestClassifier( ), 
    search_spaces = rf_params, 
    cv = 5, 
    n_jobs = -1, 
    verbose = 1,
    random_state = 42
)
rf_modelo.fit( X_resampled, y_resampled )
print( "Melhores hiperparâmetros   - Random Forest:", rf_modelo.best_params_ )

# ------------------------------------
# --- Treinar o Modelo
# ------------------------------------

# Treinar modelo final com os melhores hiperparâmetros
rf_modelo_final = RandomForestClassifier( **rf_modelo.best_params_, random_state = 42 )
rf_modelo_final.fit( X_resampled, y_resampled )

# ------------------------------------
# --- Testar e Avaliar o Modelo
# ------------------------------------

# Fazer previsões
rf_pred = rf_modelo_final.predict( X_teste )

# Avaliar o modelo
print( "Acurácia do modelo         - RandomForest:"  , accuracy_score( y_teste, rf_pred ) )
print( "Matriz de Confusão         - RandomForest:\n", confusion_matrix( y_teste, rf_pred ) )
print( "Relatório de Classificação - RandomForest:\n", classification_report( y_teste, rf_pred ) )

# Matriz de Confusão
def plot_confusion_matrix( modelo, X_treino, y_treino, X_teste, y_teste ):
    cm = ConfusionMatrix( modelo )
    cm.fit( X_treino, y_treino )
    cm.score( X_teste, y_teste )
    cm.show( )
# plot_confusion_matrix( )

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
# plot_decision_tree( )

# Importância das features
def plot_feature_importance( modelo, X_treino ):
    importancias = modelo.feature_importances_
    features     = pd.DataFrame( {'Feature': X_treino.columns, 'Importância': importancias} )
    features     = features.sort_values( by='Importância', ascending=False )
    print( features )
# plot_feature_importance( )

print( "\nImportância dos Atributos - Random Forest" )
plot_feature_importance( rf_modelo_final, X_resampled )
