# Inteligência Artificial - 17/02/2025
# 812839 - Vinícius Miranda de Araújo
# Lista 01 - Exercício 04

import numpy as np
import pandas as pd
from collections import Counter

class Planilha:
    def __init__(self, caminho):
        self.dataframe = pd.read_csv(caminho)
        self.atributos = self.dataframe.columns.tolist()
    # __init__( )

    def entropia(self, coluna):
        serie_temporal = self.dataframe[coluna]
        contador = Counter(serie_temporal)
        total = len(serie_temporal)

        entropia = 0.0
        for contagem in contador.values():
            frequencia = contagem / total
            entropia += frequencia * np.log2(frequencia)

        entropia = -entropia
        return entropia
    # entropia ( )

    def ganho(self, coluna):
        total = len(self.dataframe)
        entropia_total = self.entropia('Conclusao')
        valores = self.dataframe[coluna].value_counts()

        entropia_condicional = 0
        for valor in valores.index:
            subconjunto = self.dataframe[self.dataframe[coluna] == valor]
            proporcao = len(subconjunto) / total
            entropia_condicional += proporcao * self.entropia('Conclusao')

        return entropia_total - entropia_condicional
    # ganho ( )

    def raiz(self):
        ganhos = {coluna: self.ganho(coluna) for coluna in self.atributos}
        return max(ganhos, key=ganhos.get)
    # raiz ( )

    def segundo_nivel(self):
        raiz = self.raiz()
        ganhos = {coluna: self.ganho(coluna) for coluna in self.atributos}
        ganhos.pop(raiz)
        return max(ganhos, key=ganhos.get)
    # segundo_nivel ( )

    def arvore(self):
        raiz = self.raiz()
        segundo = self.segundo_nivel()
        print(f"Raiz: {raiz}")
        print(f"Segundo nível: {segundo}")
    # arvore ( )
# Planilha

if __name__ == "__main__":
    planilha = Planilha('C:/Users/vinic/OneDrive/Área de Trabalho/CC-PUCMG/IA/Lista_01/restaurante.csv')
    for atributo in planilha.atributos:
        print(f"Ganho de informação ({atributo}): {planilha.ganho(atributo)}")
    planilha.arvore()
# if __name__ == "__main__"