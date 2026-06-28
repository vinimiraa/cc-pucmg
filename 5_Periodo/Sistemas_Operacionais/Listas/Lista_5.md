## Lista 5

- Prof. Mark Alan Junho Song
- 812839 - Vinícius Miranda de Araújo

- **Questão 1**
	- **1.1:**
		O endereçamento de 12 bits significa que o endereço virtual pode variar de 0 até $2^{12} - 1 = 4095$, ou seja, podemos endereçar até 4096 posições de memória.
	
		4 bits identificam as entradas na tabela de páginas, ou seja, a tabela de páginas pode ter até $2^4 = 16$ entradas.
	
		O número de páginas será determinado pelo número de bits utilizados para identificar a página. Já que temos 4 bits para as entradas na tabela de páginas, isso significa que a memória virtual é dividida em 16 páginas.
	- **1.2:**
		O total de endereços virtuais é $2^{12} = 4096$ bytes.
		Como a memória está dividida em **16 páginas**, o tamanho de cada página será:
    	$$\text{Tamanho de cada página} = \frac{4096 \text{ bytes}}{16 \text{páginas}} = 256 \text{ bytes/página}.$$
	- **1.3:**
		- Endereço 1030
			Em binário, 1030 é $0000010000001110_2$.
		    Os primeiros 4 bits (0000) indicam a página.
		    Os 8 bits seguintes (01000011) indicam o deslocamento.
		    Página: 0000 (página 0).
		    Deslocamento: 1030 - (0 $\times$ 256) = 1030.
			Endereço real: Página 0, deslocamento 1030.
		- Endereço 519:
			Em binário, 519 é $00100000111_2$.
			Os primeiros 4 bits (0010) indicam a página.
			Os 8 bits seguintes (0011111) indicam o deslocamento.
			Página: 0010 (página 2).
			Deslocamento: 519 - (2 $\times$ 256) = 519 - 512 = 7.
			Endereço real: Página 2, deslocamento 7.

- **Questão 2:**
	Para simular a conversão de endereços virtuais em endereços físicos, usamos um sistema de paginação de um nível, onde o endereço virtual é dividido em dois campos: o número da página (8 bits) e o deslocamento dentro da página (8 bits), já que cada página e cada quadro têm 256 bytes. O número da página é utilizado para buscar o quadro correspondente na tabela de páginas e, em seguida, o deslocamento é mantido para calcular o endereço físico. Por exemplo, se o endereço virtual é 1234, ele é dividido em número da página e deslocamento, e, após consultar a tabela de páginas, o quadro físico é encontrado e combinado com o deslocamento para gerar o endereço físico final.

- **Questão 3:**
	- **3.1:** Com a política MRU, a página 0 será substituída, pois foi a mais recentemente utilizada.
	- **3.2:** Com FIFO, a página 0 será substituída, pois foi a primeira a entrar.
	- **3.3:** A página 1 foi a menos recentemente utilizada, pois foi referenciada pela última vez em 260.
	- **3.4:** Com a política de Segunda Chance, a página 1 será substituída, pois seu bit R foi 0 e foi a mais antiga.

- **Questão 4:**

- FIFO

|Passo|Referência| Quadros   |Faltas de Página|
| --- | -------- | --------- | -------------- |
|1    | 0        | 0         | Sim            |
|2    | 1        | 0, 1      | Sim            |
|3    | 7        | 0, 1, 7   | Sim            |
|4    | 2        | 0, 1, 7, 2| Sim            |
|5    | 3        | 1, 7, 2, 3| Sim            |
|6    | 2        | 1, 7, 3, 2| Não            |
|7    | 7        | 1, 7, 3, 2| Não            |
|8    | 1        | 1, 7, 3, 2| Não            |
|9    | 0        | 7, 3, 2, 0| Sim            |
|10   | 3        | 7, 2, 0, 3| Não            |

- LRU:

| Passo | Referência | Quadros    | Faltas de Página |
| ----- | ---------- | ---------- | ---------------- |
| 1     | 0          | 0          | Sim              |
| 2     | 1          | 0, 1       | Sim              |
| 3     | 7          | 0, 1, 7    | Sim              |
| 4     | 2          | 0, 1, 7, 2 | Sim              |
| 5     | 3          | 1, 7, 2, 3 | Sim              |
| 6     | 2          | 1, 7, 3, 2 | Não              |
| 7     | 7          | 1, 3, 2, 7 | Não              |
| 8     | 1          | 3, 2, 7, 1 | Não              |
| 9     | 0          | 2, 7, 1, 0 | Sim              |
| 10    | 3          | 7, 1, 0, 3 | Não              |