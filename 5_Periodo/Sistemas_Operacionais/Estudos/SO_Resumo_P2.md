# Resumo: Sistemas Operacionais - Prova 2

## Gerência de Memória

Todo programa precisa ser carregado na memória principal para ser executado pelo processador. Como há vários programas disputando esse espaço, o sistema operacional precisa decidir **como e onde armazenar cada processo**, de modo eficiente e seguro.

Quando vários programas estão prontos para execução, mas não cabem todos ao mesmo tempo na memória, eles ficam aguardando na **fila de entrada**, armazenados no disco, até que haja espaço disponível. Assim, o sistema operacional deve equilibrar o uso da memória física entre diferentes processos, mantendo o máximo possível de desempenho.

### Espaço de Endereçamento

- **Endereço lógico (ou virtual)**: gerado pela CPU.
- **Endereço físico**: posição real na memória.

	O programa só lida com endereços lógicos, sem saber o endereço físico real.
	
	A conversão entre os dois é feita por um componente de hardware chamado **MMU (Memory Management Unit)**. Esse dispositivo acrescenta automaticamente um valor de deslocamento, definido pelo sistema operacional, a cada endereço lógico, produzindo o endereço físico.

### Swapping

O **swapping** é uma técnica que consiste em remover temporariamente um processo da memória e armazená-lo em disco, trazendo-o de volta quando precisar continuar a execução. Essa estratégia é útil quando a memória está cheia, pois libera espaço para outros processos.

- Variante: **Roll out, roll in**, processos de baixa prioridade são retirados para dar lugar a processos mais prioritários.

### Alocação de Memória

A memória principal normalmente é dividida em duas partes: uma para o **sistema operacional**, geralmente localizada na parte inferior, e outra para os **processos dos usuários**, na parte superior.

#### Alocação Contígua

Um método simples é a **alocação contígua**, onde cada processo ocupa um bloco contínuo de endereços de memória. Esse método pode ser feito com uma única partição (um processo por vez) ou com **partições múltiplas**, onde vários processos são armazenados simultaneamente em diferentes blocos.

O problema surge quando os processos terminam e deixam espaços vazios de tamanhos diferentes, chamados **buracos**. Para decidir onde colocar novos processos, o sistema pode usar diferentes estratégias:

- **First-Fit:** escolhe o primeiro buraco suficientemente grande.
- **Best-Fit:** escolhe o menor buraco que caiba o processo.
- **Worst-Fit:** escolhe o maior buraco disponível.

> As duas primeiras costumam ter melhor desempenho e aproveitamento de memória.

#### Fragmentação

Com o tempo, a alocação contígua tende a gerar **fragmentação**, ou seja, pequenas regiões livres espalhadas pela memória.  

A **fragmentação externa** ocorre quando há espaço livre suficiente, mas não de forma contígua. Já a **fragmentação interna** acontece quando o espaço reservado é maior que o necessário, deixando parte da partição ociosa.

Uma forma de reduzir a fragmentação externa é a **compactação**, que rearranja o conteúdo da memória, movendo os processos para que toda a área livre fique contígua. Essa operação, no entanto, só é possível se o sistema permitir **realocação dinâmica** dos processos durante a execução.

> - **Externa**: há memória livre suficiente, mas não contígua.
> - **Interna**: sobra dentro da partição alocada.
> - **Compactação**: reorganiza a memória para reduzir fragmentação externa

### Paginação

Para evitar a limitação da alocação contígua, os sistemas modernos utilizam a **paginação**.

Nessa técnica, tanto a memória física quanto a memória lógica são divididas em blocos de tamanho fixo: **quadros** (frames) e **páginas**, respectivamente. Assim, um processo pode ser armazenado em qualquer lugar da memória, contíguo ou não, bastando que suas páginas sejam mapeadas corretamente.

Cada processo possui uma **tabela de páginas**, que indica em qual quadro de memória física está cada página lógica. Essa tradução é feita pela **MMU** automaticamente.

Para acelerar o processo, existe uma pequena memória especial chamada **TLB (Translation Lookaside Buffer)**, que guarda os mapeamentos mais usados, evitando o acesso repetido à tabela completa.

> - Divide a memória física em **quadros (frames)** e a memória lógica em **páginas** do mesmo tamanho.
> - Cada processo tem uma **tabela de páginas**, que mapeia endereços lógicos → físicos.
> - Evita fragmentação externa, mas pode gerar **fragmentação interna**.

#### Proteção e Paginação de Vários Níveis

Cada página tem associado um **bit válido/inválido**, indicando se ela pertence ou não ao processo. Isso impede que um processo acesse áreas de memória que não são suas.

> - Válido $\to$ página pertence ao processo.
> - Inválido $\to$ acesso ilegal.

Em sistemas grandes, as tabelas de páginas podem ficar muito extensas. Por isso, utilizam-se **tabelas de múltiplos níveis** (como 2, 3 ou 4 níveis), que dividem o mapeamento em partes menores, reduzindo o espaço necessário.

#### Páginas Compartilhadas

Alguns programas, como editores de texto ou compiladores, podem ter partes de código **compartilhadas** entre vários processos. Essas partes são marcadas como **somente leitura**, de modo que vários usuários possam utilizá-las simultaneamente sem conflito. Já os dados e códigos privados de cada processo permanecem isolados.

> - **Código compartilhado (read-only)**: usado por vários processos (ex: compiladores).
> - **Código/dados privados**: cada processo tem sua própria cópia.

---

## Memória Virtual

A **memória virtual** é uma extensão natural da paginação. Seu principal objetivo é permitir que o sistema operacional execute programas maiores do que a memória física disponível.

Para isso, apenas uma parte do programa precisa estar efetivamente carregada na memória em um dado momento. O restante pode permanecer armazenado em disco e ser trazido quando necessário.

Essa abordagem cria a ilusão de que existe uma grande memória disponível, mesmo quando a capacidade física é limitada.

> - **Memória Virtual** separa o espaço lógico (programa) do físico (RAM).
> - Permite que **apenas parte do programa** esteja em memória.
> - O **espaço lógico pode ser maior** que o espaço físico.

### Paginação sob Demanda

Na **paginação sob demanda**, uma página é carregada na memória **apenas quando é realmente acessada**. Isso reduz o número de operações de entrada e saída, economiza memória e permite que mais programas sejam executados simultaneamente.

> Vantagens:
> - Menos operações de I/O.
> - Menor uso de memória.
> - Melhor desempenho.

Quando o processador tenta acessar uma página que não está na memória, ocorre uma **falta de página (page fault)**. Nesse momento, o sistema operacional interrompe a execução, localiza a página no disco, carrega-a em um quadro livre e atualiza a tabela de páginas. Se não houver quadros disponíveis, será necessário substituir uma página existente.

> Page Fault:
> 
> 1. Ocorre quando uma página não está na memória.
> 2. O sistema operacional:
>     - Verifica se o endereço é válido.
>     - Seleciona um quadro livre.
>     - Carrega a página no quadro.
>     - Atualiza a tabela de páginas.

### Substituição de Páginas

Quando **não há quadros livres**, uma página deve ser removida (**swap out**). Deseja-se minimizar o número de **faltas de página**.

#### Algoritmos de Substituição

1. **FIFO (First-In, First-Out)**
    - Remove a página mais antiga.
    - Pode sofrer **anomalia de Belady** (mais quadros $\to$ mais faltas).
2. **Ótimo (OPT)**
    - Remove a página que **não será usada por mais tempo**.
    - Ideal teórico, usado apenas como referência.
3. **LRU (Least Recently Used)**
    - Remove a página **menos recentemente usada**.
    - Aproximação prática do algoritmo ótimo.
4. **Segunda Chance / Clock**
    - Variante de FIFO com **bit de referência**.
    - Dá uma “segunda chance” a páginas recentemente usadas.
5. **LFU / MFU**
    - **LFU**: remove a página menos usada.
    - **MFU**: remove a mais usada (supõe que já não será necessária).

### Alocação de Quadros

Os quadros de memória podem ser distribuídos de forma **fixa**, **proporcional** (de acordo com o tamanho do processo) ou **prioritária** (dando mais espaço a processos importantes).

- **Fixa**: cada processo recebe um número fixo de quadros.
- **Proporcional**: baseada no tamanho do processo.
- **Prioritária**: baseada na prioridade do processo.

### Substituição Global x Local

Na **substituição local**, um processo só substitui suas próprias páginas. Já na **substituição global**, pode remover páginas de outros processos, o que geralmente aumenta a eficiência, mas reduz o isolamento.

> - **Global**: um processo pode substituir páginas de outro.
> - **Local**: cada processo só substitui suas próprias páginas.

### Thrashing

Quando um processo tem **poucos quadros disponíveis**, ele pode gerar muitas faltas de página, gastando mais tempo trocando páginas com o disco do que executando instruções. Esse fenômeno é conhecido como **thrashing** e resulta em baixa utilização da CPU e queda de desempenho do sistema.

> - Ocorre quando há **muitas faltas de página**.
> - O processo passa mais tempo trocando páginas do que executando.
> - Reduz a **utilização da CPU**.

### Considerações

- O padrão de acesso de um programa influencia fortemente o desempenho.
- Acesso **por linha** pode causar muito mais faltas que acesso **por coluna**, dependendo da organização da memória.
  