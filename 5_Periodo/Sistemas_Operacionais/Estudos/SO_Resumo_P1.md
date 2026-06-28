# Resumo: Prova 1 de Sistemas Operacionais

## Conceitos

- Sistema Operacional:
	- Um programa que age como intermediário entre o usuário e o hardware, facilitando o uso dos recursos.
	- Controla e coordena o uso do hardware entre as diversas aplicações dos usuários.
- Programa de controle:
	- Controla a execução dos programas e operações de I/O.
- Kernel:
	- Programa executando ininterruptamente (todos os demais são aplicações). Modo kernel ou supervisor.
- Hardware:
	- Provê recursos básicos de computação (CPU, memória, dispositivos de I/O).
- Programas Aplicativos:
	- Definem a forma com a qual os recursos são usados para resolverem os problemas dos usuários (compiladores, bancos de dados, editores, etc.).
- Usuários:
	- Pessoas, dispositivos, outros computadores.

## Interrupções

- Os SO modernos são baseados em interrupções.
- O SO preserva o estado da CPU, armazenando os valores dos registradores e o contador de programa.
- Outras interrupções ficam desabilitadas até que a interrupção seja processada.
- Uma exceção ou trap é uma interrupção gerada por software que sinaliza um erro ou requisição do usuário.

## Acesso Direto a Memória (DMA)

- Usado para permitir a dispositivos de I/O de alta velocidade transmitirem informação em velocidade comparável à da memória.

## Estrutura de Armazenamento

- Memória Principal:
	- Única grande área de memória acessada diretamente pela CPU.
- Memória Secundária:
	- Extensão da memória principal, não volátil.
- Sistemas de Armazenamento são organizados hierarquicamente, por:
	- Velocidade
	- Custo
	- Volatilidade
- Caching:
	- Cópia de informação em diferentes níveis de memória.

## Proteção de Hardware

- Um bit acrescentado ao hardware permite diferenciar dois modos de operação:
	1.  Modo Usuário (bit 1):
		- Execução a favor do usuário.
	2.  Modo Monitor/Modo supervisor/Modo Sistema (bit 0):
		- Execução a favor do SO.
- Quando uma interrupção ou exceção acontece, o hardware muda para o modo monitor.
- Instruções privilegiadas só podem ser executadas em modo monitor

## Proteção de I/O

- Todas as instruções de I/O são instruções privilegiadas.  
- Devem garantir que um programa usuário não tenha controle do computador em modo monitor.
- Operações de I/O devem ser solicitadas ao SO.

## Proteção de Memória

- A proteção pode ser feita com o auxílio de 2 registradores que determinam a faixa legal de memória que pode ser acessada pelo programa usuário (espaço de endereçamento):  
	- Registrador base:
		- Menor endereço físico legal.
	- Registrador de limite:
		- Tamanho da faixa legal.
- A memória fora do espaço de endereçamento fica protegida.
- Quando executando em modo monitor, o SO tem acesso irrestrito à memória.  
- As instruções de load para os registradores de base e limite são instruções privilegiadas.

## Proteção de CPU  

- Timer (temporizador):
	- Interrompe o computador após um período de tempo específico, para garantir o controle do SO.
	- O Timer é decrementado a cada pulso de clock.
	- Quando o timer atinge o valor 0, uma interrupção ocorre.
	- Carregar o timer é uma instrução privilegiada.
- O Timer é também utilizado para implementar o compartilhamento da CPU.

## Arquitetura do Sistema

- Chamadas ao Sistema (System calls):
	- Método usado por um processo para requisitar uma determinada ação ao S.O.

---

## Processo

- Um programa em execução
- Execução deve ser sequencial.
- Possui:
	- Contador de Programa (PC - Program Counter)
	- Pilha (S - Stack)
	- Seção de Dados (DT - Data)
- Estados:
	- Novo: O processo está sendo criado.
	- Em execução: Instruções estão sendo executadas.
	- Em espera: O processo espera por um evento.
	- Pronto: O processo está esperando para ser atribuído a um processador.
	- Encerrado: O processo terminou sua execução.

## Bloco de Controle de Processos (PCB)

- Armazena informação associada com cada processo, como:
	- Estado do processo
	- Contador de Programa
	- Registradores da CPU
	- Informações de escalonamento de CPU
	- Informações de gerência de memória
	- Informações de contabilidade
	- Informações de status de I/O

## Filas de Escalonamento

- Fila de Jobs:
	- Conjunto de todos os processos do sistema.  
- Fila de processos prontos:
	- Conjunto de todos os processos residindo em memória, prontos e esperando para serem executados.  
- Filas de dispositivos:
	- Processos esperando por um dispositivo de I/O  
- O processo migra entre as diversas filas.

## Escalonadores

- De longo prazo (Escalonador de Jobs):
	- Seleciona quais processos devem ser levados para a memória, na fila de processos prontos.
	- São invocados menos frequentemente
	- Podem ser mais lentos
- De curto prazo (Escalonador de CPU):
	- Seleciona qual processo deve ser executado e alocado à CPU.
	- São invocados mais frequentemente.
	- Devem ser rápidos
- Swapping:
	- Inserção e remoção do processo na memória.
## Troca de Contexto

- Overhead:
	- Tempo necessário para a troca de contexto, é um gasto extra de tempo, pois nada útil é feito.
- Quando a CPU recebe novo processo, o estado do processo anterior deve ser salvo e o estado do novo processo carregado.

---

## Escalonamento de CPU

- A utilização máxima de CPU é obtida através de multiprogramação. Com um só processador, nunca haverá mais de um processo em execução.
- Ciclos de surtos de CPU e/ou I/O:
	- A execução de um processo consiste na alternância entre um ciclo de execução de CPU e um ciclo de espera de I/O.
- Critérios de escalonamento (características para comparação de algoritmos):
	- Utilização de CPU:
		- Manter a CPU o mais ocupada possível.
	- Throughput:
		- \# de processos que completam sua execução por unidade de tempo  
	- Tempo de retorno:
		- Quantidade de tempo para executar um processo.
	- Tempo de espera:
		- Quantidade de tempo que um processo gasta na fila de processos prontos.
	-  Tempo de resposta:
		- Quantidade de tempo gasto entre a requisição e a produção da primeira resposta.
- Critérios de Otimização:
	- Máxima utilização de CPU.
	- Máximo throughput.
	- Mínimo tempo de retorno.
	- Mínimo tempo de espera.
	- Mínimo tempo de resposta.
### First Come, First Served (FCFS).

- Os processos são executados em ordem de chegada independente da prioridade ou tempo de execução.
### Shortest Job First (SJF):

- Associa a cada processos o tamanho do seu próximo surto de CPU. Usa estes valores para escalonar o processo com o menor tempo
- Preemptivo:
	- Se um novo processo chegar com um tempo de surto de CPU menor que o tempo restante do processo sendo executado, é feita a troca. Este esquema é conhecido como Menor-tempo-restante-primeiro (SRTF).
- Não Preemptivo:
	- Uma vez que a CPU é dada ao processo, não pode ser retirada até completar seu surto.
### Por Prioridade.

- Um número de prioridade (inteiro) é associado com cada processo.
- A CPU é alocada para o processo com maior prioridade (menor valor é equivalente ao maior prioridade).
- SJF é um escalonamento por prioridade, onde a prioridade é dada pelo tempo de surto.
- Problema de Starvation, isto é, processos com baixa prioridade podem nunca serem executados.
### Round Robin (RR).

- Cada processo recebe uma pequena unidade de tempo de CPU (time quantum), geralmente 10-100 ms. Após este tempo, o processo é retirado e inserido no fim da fila de prontos.
- Se existirem n processos na fila de prontos e o quantum for q, cada processo terá 1/n de tempo de CPU em parcelas de no máximo q unidades de tempo por vez. Nenhum processo de no máximo q unidades de tempo por vez. Nenhum processo esperará mais que (n-1)\*q unidades de tempo.

---

## Deadlock

- Um deadlock pode ocorrer se $4$ condições existirem ao mesmo tempo, essas são necessárias, mas não suficientes:
	- Exclusão Mútua: 
		- Apenas um processo por vez pode usar o recurso.
	- Posse e espera: 
		- Um processo em posse de pelo menos um recurso está esperando por recursos adicionais mantidos por outros processos.
	- Não preempção: 
		- Um recurso só pode ser liberado voluntariamente pelo processo que o mantém, após ter completado sua tarefa.
	- Espera circular: 
		- Existe um conjunto ${P_0, P_1, \cdots, P_n}$ de processos em espera tal que $P_0$ espera por recurso mantido por $P_1$, $P_1$ espera por recurso mantido por $P_2, \cdots, P_{n–1}$ espera por recurso mantido por $P_n$, e $P_n$ espera por recurso mantido por $P_0$.

### Grafo de Alocação de Recurso

- Grafo $G = (V, E)$ e direcionado, onde:
	- $V = \{P, R\}$
		- $P = \{P_1, \cdots, P_+n\}$ = conjunto de todos os processos.
		- $R = \{R_1, \cdots, R_n\}$ = conjunto de todos os recursos.
	- $E$:
		- Aresta de pedido (processo solicita algo): $P_i \to R_j$.
		- Aresta de atribuição (processo possui algo): $R_i \to P_j$.
	- Se acíclico, então não possui deadlock
	- Se cíclico:
		- Se apenas uma instância por tipo de recurso, há deadlock.
		- Se várias instâncias por tipo de recurso, há possibilidade de deadlock.

### Tratamento de Deadlock

- Garantir que o sistema nunca entrará em estado de deadlock.  
- Permitir que o sistema entre em deadlock e este seja recuperado.
- Ignorar o problema e fingir que deadlocks nunca acontecerão:
	- Usados pela maioria do SO, incluindo o UNIX.

---

## Programação Concorrente

- `cobegin/coend`: 
	- Rotinas podem ser executadas em paralelo, mas o sistema de hardware/software que decide.
- Concorrentes:
	- Processos com potencial para execução paralela.
- Notações e técnicas para expressar potencial paralelismo.
- Resolver problemas de sincronização e comunicação.

## Semáforo

- Resolve problemas de programação paralela.
- Operações permitidas:
	- `wait(semaforo)`
	- `signal(semaforo)`
	
```
wait(semaforo):
	if( semaforo > 0 )
		semaforo -= 1
	else
		supenderProcesso()
```

```
signal(semaforo):
	if(temProcessoSuspenso())
		acordarProcesso()
	else
		semaforo += 1
```

- `wait(s)` e `signal(s)` são operações primitivas como `Load` e `Store`.
	- São mutuamente exclusivas quando atuam no mesmo semáforo.
	- `signal(s)` não especifica que processo é acordado quando mais de um processo está suspenso no mesmo semáforo.