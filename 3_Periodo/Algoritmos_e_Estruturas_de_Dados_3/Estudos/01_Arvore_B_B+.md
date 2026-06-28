# Árvores B e B+

## Árvore B

- A ordem da árvore diz qual é o número máximo de filhos que cada página pode ter.
	
- Uma página nada mais é do que o nó da árvore B

### Regras

- Cada página (exceto a raiz) deve ter pelo menos 50% de ocupação;
	
- O número de filhos de cada página (exceto as folhas) deve ser igual ao seu número de chaves mais um;
	
- Todas as folhas estão no mesmo nível (a árvore cresce para cima).

### Inserção

- Conceito:
	
	- Se o elemento couber na página, basta inclui-lo de forma ordenada.
		
	- Se não couber, a página deve ser dividida em duas e o elemento do meio deve ser promovido.
	
- Algoritmo:
	
	1. Localize a folha em que a chave deve ser inserida;
	2. Se a chave couber na folha, inseri a chave e termine;
	3. Se não couber,
		1. Crie uma nova folha;
		2. Mova a metade superior das chaves para essa nova folha;
		3. Se a chave a ser inserida for menor que a primeira chave da segunda (nova) folha,
			1. Insira a nova chave na folha antiga (da esquerda);
			2. Promova a maior chave dessa folha antiga, com o ponteiro direito para a nova folha;
		4. Senão,
			1. Insira a nova chave na nova folha (da direita);
			2. Promova a menor chave dessa nova folha, com o ponteiro direito para a nova folha;
	4. Se a chave promovida não couber na página pai, repita o algoritmo a partir do passo 2 acima.
	
### Remoção

- Conceito:
	
	1. Caso 1: se o elemento ESTIVER em uma folha e a folha mantiver 50% de ocupação, basta removê-lo.
		
	2. Caso 2: se o elemento NÃO ESTIVER em uma folha, trocá-lo pelo seu antecessor.
		
	3. Caso 3: se a folha ficar com menos de 50% de ocupação, mas a página irmã puder ceder uma chave.
		
	4. Caso 4: se a folha ficar com menos de 50% de ocupação e as páginas irmãs não puderem ceder uma chave.

- Algoritmo:
	
	ETAPA 1 - Remoção da chave em uma folha
	
	1. Localize a chave a ser removida.
	2. Se ela estiver em uma folha,
		1. Então remova a chave.
		2. Senão remova a chave e coloque em seu lugar a sua chave antecessora (descendente de maior valor da sub-árvore 
		   esquerda, que está em uma folha). Trate a exclusão como se fosse dessa chave antecessora em uma folha.
	
	ETAPA 2 - Cessão de chave de alguma folha adjacente
	
	3. Se a folha tiver ficado com menos de 50% de ocupação,
		1. Então veja se a folha adjacente direita (se existente) pode ceder uma chave.
			1. Se puder, faça a rotação.
		2. Se não puder, veja se a folha adjacente esquerda (se existente) pode ceder uma chave.
			1. Se puder, faça a rotação.
	
	ETAPA 3 - Fusão
	
	4. Se a folha ainda estiver com menos de 50% de ocupação e nenhuma folha adjacente puder ceder uma chave,
		1. Se existir uma folha adjacente direita, faça a fusão entre as folhas.
		2. Se não existir, faça a fusão com a folha adjacente esquerda.
	5. Na fusão, a chave que divide as duas folhas deve ser demovida (descer para a folha resultante da fusão).
	
	ETAPA 4 - Propagação
	
	6. Se, após a fusão, a página pai ficar com menos de 50 de ocupação, voltar à ETAPA 2 considerando essa página.
		
	7. As fusões podem ser propagadas até a raiz se necessário. Se a raiz tiver só dois filhos que precisarem ser 
	   fundidos, então a árvore terá sua altura reduzida.


## Árvore B+

- Todas as chaves são armazenadas nas folhas.
	
- Cada folha aponta para a próxima folha (para permitir a leitura sequencial).
	
- As folhas podem possuir uma estrutura diferente das páginas não folhas, por serem as únicas páginas a carregarem dados.

### Inserção

- Mesmas regras da árvore B.
	
- Se ocorrer divisão de página, a chave deve ser mantida na folha e copiada para cima.

### Remoção

- Mesmas regras da árvore B, inclusive de redistribuição e fusão.
	
- As chaves removidas das folhas não precisam ser removidas das outras páginas.

### Busca

- Mesmas regras da árvore B, mas as chaves devem ser localizadas apenas nas folhas.


## Árvore B vs Árvore B+

- B : adequada para situações em que fazemos apenas buscas aleatórias por alguma entidade específica.
	
- B+ : quando precisamos recuperar várias entidades, precisamos de uma estrutura que seja eficiente nas buscas aleatórias, mas que também ofereça a possibilidade de leituras sequenciais.