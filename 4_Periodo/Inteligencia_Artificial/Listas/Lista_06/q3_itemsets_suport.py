# Instalar dependência
# $ pip install apyori

# Importar dependências
import pandas as pd
from itertools import combinations
from collections import Counter

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

total_transacoes = len(transactions)

todas_combinacoes = []
# Para cada transação, pega os itens com "Sim" e gera combinações de 1 até N
for _, row in transactions.iterrows():
    itens_presentes = [items[i] for i in range(len(items)) if row[i + 1] == 'Sim']
    # Gera combinações (itemsets) de tamanho 1 até o total presente na transação
    for tamanho in range(1, len(itens_presentes) + 1):
        for combinacao in combinations(sorted(itens_presentes), tamanho):
            todas_combinacoes.append(combinacao)

# Conta quantas vezes cada combinação apareceu
contagem = Counter(todas_combinacoes)

# Imprime itemsets organizados por tamanho e seu suporte
print( "Suporte de cada ItemSets:" )
ultimo_tamanho = 0
for itemset, qtd in sorted(contagem.items(), key=lambda x: (len(x[0]), x[0])):
    tamanho = len(itemset)
    if tamanho != ultimo_tamanho:
        print(f"\nItemset {tamanho}:")
        ultimo_tamanho = tamanho
    suporte = qtd / total_transacoes
    print(f"\t{list(itemset)} -> suporte: {suporte} ({qtd}/{total_transacoes})")
