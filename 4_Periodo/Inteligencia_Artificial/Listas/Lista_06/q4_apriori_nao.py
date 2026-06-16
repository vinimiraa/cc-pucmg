# Instalar dependência
# $ pip install apyori

# Importar dependências
import pandas as pd
from apyori import apriori

# Ler .cvs
df = pd.read_csv('supermercado.csv', sep=';', encoding='utf-8', header=None)
print( "DataFrame:" )
print( df )
print( "DataFrame (linhas, colunas):" )
print( df.shape )
print( "// ------------------------------------------------- //")

# Separando o cabeçalho dos dados
items = df.iloc[0, 1:].tolist()
transactions = df.iloc[1:].reset_index(drop=True)
print( "Itens:" )
print( items )
print( "Transações:" )
print( transactions )
print( "// ------------------------------------------------- //")

# Transformando o dataframe em uma lista de transações
transactions_list = []
for index, row in transactions.iterrows():
    transaction = []
    for i in range(len(items)):
        if row[i + 1] == 'Não':
            transaction.append(items[i])
    transactions_list.append(transaction)
transactions_list = sorted(transactions_list, key=lambda x: len(x))
print( "Lista de Transações:" )
for i in range(len(transactions_list)):
    print( transactions_list[i] )
print( "// ------------------------------------------------- //")

# Executando o Algoritmo Apriori e armazenando as regras obtidas
regras = apriori(transactions_list, min_support = 0.3, min_confidence = 0.8)
saida = list(regras)
print( "Quantidade de Regras Obtidas:" )
print( len(saida) )
print( "Regras Obtidas:" )
for i in range(len(saida)):
    print( saida[i] )
print( "// ------------------------------------------------- //")

# Transformando o resultado em um dataframe para facilitar a vizualização
antecedente = []
consequente = []
suporte = []
confianca = []
lift = []
regrasFinais = []
for resultado in saida:
    s = resultado[1]
    result_rules = resultado[2]
    for result_rule in result_rules:
        a = list(result_rule[0])
        b = list(result_rule[1])
        c = result_rule[2]
        l = result_rule[3]
        if 'nan' in a or 'nan' in b: continue
        if len(a) == 0 or len(b) == 0: continue
        antecedente.append(a)
        consequente.append(b)
        suporte.append(s)
        confianca.append(c)
        lift.append(l)
        regrasFinais = pd.DataFrame({
            'Antecedente': antecedente,
            'Consequente': consequente,
            'suporte': suporte,
            'confianca': confianca,
            'lift': lift
        })
print( "DataFrame das Regras: " )
print( regrasFinais )
print( "// ------------------------------------------------- //")

# Ordenando resultados pela métrica lift
print( "DataFrame das Regras Ordenada por 'lift': " )
regrasFinais.sort_values(by='lift', ascending =False)
print( regrasFinais )
