# Lista 6

- Prof. Mark Alan Junho Song
- Vinícius Miranda de Araújo - 812839

1. Métodos de alocação de arquivos em disco por alocação contígua, encadeada e indexada:

	a. Facilidade de Inserção e Remoção:
	
| Método    | Inserção                                                              | Remoção                                       |
| --------- | --------------------------------------------------------------------- | --------------------------------------------- |
| Contígua  | Depende de encontrar um espaço contíguo livre grande o suficiente     | Pode gerar fragmentação externa.              |
| Encadeada | Basta alocar um novo bloco livre e ajustar o ponteiro no último bloco | Remove o bloco e corrige o ponteiro anterior. |
| Indexada  | Adiciona a entrada no bloco-índice para novos blocos.                 | Remove a referência no bloco-índice.          |
	b. Rapidez no acesso a registro
	
| Método    | Desempenho                                                                                    |
| --------- | --------------------------------------------------------------------------------------------- |
| Contígua  | Acesso sequencial e randômico muito eficiente, pois blocos estão lado a lado.                 |
| Encadeada | Lento para acesso randômico (precisa seguir ponteiro a ponteiro). Sequencial razoável.        |
| Indexada  | Acesso randômico rápido: basta consultar o bloco-índice. Leitura sequencial também eficiente. |
	c. Formas de acesso possíveis:
	
| Método    | Sequencial | Randômico                                                |
| --------- | ---------- | -------------------------------------------------------- |
| Contígua  | Suportado  | Suportado (muito eficiente)                              |
| Encadeada | Suportado  | **Praticamente inviável** (tem que seguir toda a cadeia) |
| Indexada  | Suportado  | Suportado                                                |
	d. Necessidade de armazenamento de informações adicionais para manutenção do arquivo:
	
| Método    | Informações                                                                                          |
| --------- | ---------------------------------------------------------------------------------------------------- |
| Contígua  | Armazena apenas o início e o tamanho do arquivo.                                                     |
| Encadeada | Cada bloco deve conter um ponteiro para o próximo bloco; em FAT, as entradas são mantidas em tabela. |
| Indexada  | Cada arquivo precisa de um bloco-índice contendo a lista completa dos blocos usados.                 |
	e. Fragmentação interna e externa:
	
| Método    | Interna                                                    | Externa                                  |
| --------- | ---------------------------------------------------------- | ---------------------------------------- |
| Contígua  | Pode ocorrer (último bloco pode não ser totalmente usado). | Alta (buracos entre arquivos).           |
| Encadeada | Interna baixa (quase sem desperdício).                     | Nenhuma (blocos podem ficar espalhados). |
| Indexada  | Interna baixa (apenas no bloco-índice).                    | Nenhuma externa.                         |

2. No acesso com DMA, a CPU apenas configura o controlador DMA informando o endereço de memória, o setor do disco e o tamanho da transferência. O driver traduz o pedido para a controladora de disco, que localiza o setor fisicamente e envia os dados pelo barramento. O DMA então copia esses dados diretamente para a RAM sem envolver a CPU. Quando termina, ele gera uma interrupção avisando que a transferência foi concluída. Assim, a CPU participa apenas do início e do fim do processo, deixando o trabalho pesado para o DMA, a controladora e os barramentos.

3. A FAT é uma tabela no disco em que cada entrada representa um bloco e indica qual é o próximo bloco do arquivo, formando uma cadeia. No método de alocação encadeada, ela substitui os ponteiros internos dos blocos, permitindo que o sistema siga a sequência do arquivo apenas consultando a tabela, sem precisar acessar cada bloco fisicamente. Assim, a FAT funciona como um “mapa” centralizado dos arquivos encadeados.

4. Com 300 rpm (200 ms por rotação), cada setor passa a cada 25 ms. A latência inicial é de 100 ms. Se a transferência demora 15 ms, a controladora perde os setores seguintes e precisa esperar uma rotação inteira para cada bloco, elevando o tempo total para ~1700 ms. O interleaving simples reorganiza os setores para dar tempo de processamento, reduzindo para ~300 ms. Com tempo de transferência de 40 ms, perde-se até os setores intercalados, exigindo interleaving duplo, que espaça ainda mais os setores e reduz o tempo para cerca de 700 ms.

5. Manter o início do arquivo no mesmo bloco do i-node reduz o número de seeks, pois metadados e primeiros dados são lidos juntos. Isso acelera a abertura do arquivo e melhora bastante o desempenho sobretudo para arquivos pequenos, que muitas vezes cabem inteiros nos blocos próximos ao i-node.