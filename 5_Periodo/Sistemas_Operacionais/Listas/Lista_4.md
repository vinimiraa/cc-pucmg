## Lista 4

- Prof. Mark Alan Junho Song
- 812839 - Vinícius Miranda de Araújo

- **Questão 1**
	
	Com 2 segmentos de memória, cada processo ocupa um segmento. Quando um processo está realizando I/O, o outro pode usar a CPU. Em média, 50% do tempo será desperdiçado, porque, durante a execução de I/O de ambos os processos, a CPU ficará ociosa.
    
	Com 4 segmentos de memória, a probabilidade de todos os processos estarem em I/O simultaneamente diminui. A chance de todos estarem esperando I/O ao mesmo tempo é (0,5)4=0,0625(0,5)^4 = 0,0625(0,5)4=0,0625, ou seja, 6,25% do tempo da CPU será desperdiçado.

- **Questão 2:**

	A execução de uma instrução leva 1 microsegundo, e se uma falta de página ocorre a cada k instruções, o tempo adicional para resolver a falta é N microsegundos.
	
	- Tempo total de execução de uma instrução = Tempo para executar a instrução + (Probabilidade de falha de página $\times$ Tempo de resolução da falha).
	
	A probabilidade de uma falha de página ocorrer a cada k instruções é $\frac{1}{k}$​.
	
	Portanto, o **gasto efetivo** para executar uma instrução será:
	
	$$1 + \frac{N}{k} \, \text{microsegundos}$$
	
	Isso significa que, quanto menor k, ou seja, quanto mais frequentemente as falhas de página ocorrerem, maior será o custo efetivo da instrução.

- **Questão 3:**

| Passo | Referência | Estado das Páginas (em memória) | FIFO (Faltas) | LRU (Faltas) |
| ----- | ---------- | ------------------------------- | ------------- | ------------ |
| 1     | 0          | [0]                             | 1ª falta      | 1ª falta     |
| 2     | 1          | [0, 1]                          | 2ª falta      | 2ª falta     |
| 3     | 7          | [0, 1, 7]                       | 3ª falta      | 3ª falta     |
| 4     | 2          | [0, 1, 7, 2]                    | 4ª falta      | 4ª falta     |
| 5     | 3          | [1, 7, 2, 3]                    | 5ª falta      | 5ª falta     |
| 6     | 2          | [1, 7, 2, 3]                    | Nenhuma       | Nenhuma      |
| 7     | 7          | [1, 7, 2, 3]                    | Nenhuma       | Nenhuma      |
| 8     | 1          | [1, 7, 2, 3]                    | Nenhuma       | Nenhuma      |
| 9     | 0          | [7, 2, 3, 0]                    | 6ª falta      | 6ª falta     |
| 10    | 3          | [2, 3, 0, 7]                    | Nenhuma       | 7ª falta     |

- **Questão 4:**
	
	O espaço de endereçamento total disponível é de 65.536 bytes, com páginas de 4.096 bytes.
	- O número de páginas disponíveis seria:
	   $$\frac{65.536 \, \text{bytes}}{4.096 \, \text{bytes/página}} = 16 \, \text{páginas}.$$
	
	- **Código:** 32.768 bytes
	- **Dados:** 16.386 bytes
	- **Pilha:** 15.870 bytes
    
	O total necessário é:
	$$32.768 + 16.386 + 15.870 = 65.024 \, \text{bytes}.$$
	
	Portanto, o programa caberá no espaço de endereçamento reservado de 65.536 bytes, já que o programa usa 65.024 bytes.
	
	Se as páginas forem diminuídas para 512 bytes, o número de páginas necessárias para o programa será:
	
	$$\frac{65.024 \, \text{bytes}}{512 \, \text{bytes/página}} \approx 127 \, \text{páginas}.$$

	Neste caso, o programa não caberá no espaço reservado de 16 páginas, pois seriam necessárias 127 páginas para acomodar os dados.

- **Questão 5:**
	
	- O número de páginas depende dos 4 campos?  
	    Não. O número de páginas depende da quantidade de bits alocados para os campos que determinam a tradução do endereço (como os campos a, b, c). O campo d especifica o deslocamento dentro de uma página, mas não altera o número de páginas.
	    
	- O espaço de endereçamento virtual depende dos 4 campos?  
	    Sim. O espaço de endereçamento virtual depende do número total de bits nos 4 campos. O conjunto de todos os campos define o endereço completo que o processador pode acessar, o que afeta diretamente o espaço de endereçamento.
	    
	- O tamanho da página depende de quais campos?  
	    O tamanho da página depende somente do campo d, que representa o deslocamento dentro de uma página. O número de bits alocados para o campo d define o tamanho da página. Quanto maior o número de bits em d, maior será o tamanho da página.
