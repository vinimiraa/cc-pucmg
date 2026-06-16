# Instalar dependência
# $ pip install mlxtend
# https://rasbt.github.io/mlxtend/user_guide/frequent_patterns/apriori/
# https://rasbt.github.io/mlxtend/user_guide/frequent_patterns/association_rules/

# Importar dependências
import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

# Ler .cvs
df = pd.read_csv( 'supermercado.csv', sep=';', encoding='utf-8')
print( "DataFrame:" )
print( df )
print( "DataFrame (linhas, colunas):" )
print( df.shape )
print( "// ------------------------------------------------- //")

# Transformando o DataFrame em uma lista de transações
items = list(df.columns.values)
transactions_list = []
for index, row in df.iterrows():
    transaction = []
    for i in range(len(items)):
        if row.iloc[i] == 'Sim':
            transaction.append(items[i])
    transactions_list.append(transaction)
print( "Lista de Transações:" )
print( transactions_list )
print( "// ------------------------------------------------- //")

# Codificando para o formato esperado
te = TransactionEncoder()
te_ary = te.fit(transactions_list).transform(transactions_list)
df = pd.DataFrame(te_ary, columns=te.columns_)
print( "DataFrame Codificado:" )
print( df )
print( "// ------------------------------------------------- //")

## Selecionando e Filtrando Resultados

# ItemSets
frequent_itemsets = apriori(df, min_support=0.3, use_colnames=True)
frequent_itemsets['length'] = frequent_itemsets['itemsets'].apply(lambda x: len(x))
print( "ItemSets:" )
print( frequent_itemsets )
print( "// ------------------------------------------------- //")

# Regras
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.8)
print( "Regras:" )
print( rules )
print( "// ------------------------------------------------- //")

item_mapping = {index: product for index, product in enumerate(items)}
print("Regras geradas:")
for index, row in rules.iterrows():
    antecedent_items = [item_mapping.get(item, item) for item in row['antecedents']]
    consequent_items = [item_mapping.get(item, item) for item in row['consequents']]
    antecedent_items = [str(item) for item in antecedent_items]
    consequent_items = [str(item) for item in consequent_items]
    print(f"Quem leva {', '.join(antecedent_items)} leva {', '.join(consequent_items)}")
