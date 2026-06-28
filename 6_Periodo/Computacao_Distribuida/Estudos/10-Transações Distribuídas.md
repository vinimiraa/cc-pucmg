## **Transações Distribuídas**

### **Introdução e Conceitos Fundamentais**

Uma **transação** é uma unidade lógica de trabalho que agrupa uma sequência de operações, garantindo que todas sejam executadas com sucesso ou nenhuma delas tenha seu efeito registrado. Esse conceito é fundamental para manter a **consistência** e a **integridade** dos dados em sistemas computacionais, mesmo na ocorrência de falhas. Do ponto de vista do cliente, uma transação representa uma transição de um estado consistente para outro estado consistente do sistema. O cliente interage com a transação por meio de operações que marcam seu início e fim, como openTransaction(), closeTransaction() e abortTransaction().

As propriedades das transações são conhecidas pelo acrônimo **ACID**:

- **Atomicidade**: Garante que todas as operações de uma transação sejam realizadas ou nenhuma delas. É o princípio do "tudo ou nada".
- **Consistência**: Assegura que a transação leve o sistema de um estado válido para outro estado válido, respeitando todas as regras de integridade.
- **Isolamento**: As execuções de transações concorrentes não interferem umas nas outras, devendo ser equivalentes a uma execução serial.
- **Durabilidade**: Uma vez confirmadas (commit), as alterações realizadas pela transação tornam-se permanentes e sobrevivem a falhas posteriores.

### **Problemas de Concorrência e Controle**

Em ambientes com múltiplas transações executando concorrentemente, surgem problemas que podem comprometer a consistência dos dados. Um dos mais clássicos é o **problema da atualização perdida (lost update)**, que ocorre quando duas transações leem o mesmo valor antigo de um dado e, com base nele, calculam e escrevem um novo valor. O resultado final reflete apenas a atualização da última transação a escrever, "perdendo" o efeito da outra. 

A solução para esse e outros problemas de concorrência (como leituras sujas e leituras não repetíveis) é garantir que a **execução concorrente seja serialmente equivalente**. Isso significa que o efeito final da execução simultânea de várias transações deve ser idêntico ao de alguma execução em que elas são processadas uma após a outra, em ordem serial. Para atingir essa equivalência serial, são utilizados **protocolos de controle de concorrência**.

### **Protocolos de Controle de Concorrência**

Os principais protocolos são:

- **Travamento (Locking) com Two-Phase Locking (2PL)**: As transações adquirem locks (travas) nos dados que precisam acessar. No 2PL, uma transação não pode solicitar novos locks após liberar o primeiro lock, dividindo sua execução em uma fase de crescimento (aquisição de locks) e uma fase de redução (liberação de locks). Esse protocolo garante serialidade.
- **Esquema de Muitos Leitores/Um Escritor**: Permite que múltiplas transações leiam um objeto simultaneamente (lock compartilhado) ou que uma única transação escreva (lock exclusivo), mas não ambos ao mesmo tempo. A compatibilidade de locks é gerida por uma matriz que define se uma solicitação de lock deve ser concedida, posta em espera ou negada.
- **Controle de Concorrência Otimista**: Assume que conflitos são raros. As transações prosseguem sem aquisição de locks e, na fase de commit, é verificado se ocorreram conflitos. Se houver, uma ou mais transações são abortadas.
- **Ordenação por Timestamp**: Cada transação recebe um timestamp único. As operações são ordenadas por essa marca temporal, e qualquer operação que chegue "tarde demais" (violando a ordem serial) é abortada.

O **deadlock** é um risco inerente aos esquemas de travamento. Ele ocorre quando um conjunto de transações está bloqueado, cada uma esperando por um lock que outra transação do conjunto detém. A detecção e a recuperação de deadlocks (geralmente abortando uma das transações) são necessárias para resolver essa situação.

## **Transações Distribuídas e o Protocolo Two-Phase Commit (2PC)**

Uma **transação distribuída** é aquela cujas operações são executadas em múltiplos servidores ou nós de uma rede. O grande desafio é garantir a **atomicidade global**: todos os participantes devem confirmar a transação (commit) ou todos devem abortá-la.

O protocolo **Two-Phase Commit (2PC)** é o mecanismo mais utilizado para garantir essa atomicidade em transações distribuídas. Ele envolve um **coordenador** (geralmente o nó que iniciou a transação) e vários **participantes** (os outros nós envolvidos).

### **Fases do 2PC**

1. **Fase 1 - Votação**:

	- O coordenador envia uma mensagem canCommit? (ou prepare) para todos os participantes.
	- Cada participante prepara a transação localmente (escrevendo registros no log de recuperação) e decide se pode confirmar.
	- Se um participante pode confirmar, responda Yes; caso contrário, responda No e aborte localmente.
	- O participante que vota Yes entra em um estado de **incerteza** e fica bloqueado, aguardando a decisão final. Ele não pode abortar ou confirmar unilateralmente.

3. **Fase 2 - Decisão (Commit ou Abort)**:

	- O coordenador coleta todas as respostas.
	- **Se todos votaram** **Yes**: O coordenador decide pelo commit. Ele registra a decisão em seu log e envia uma mensagem doCommit para todos os participantes.
	- **Se qualquer participante votou** **No**: O coordenador decide pelo abort. Ele registra a decisão e envia uma mensagem doAbort (ou Global_Abort) para todos.
	- Os participantes que recebem doCommit efetuam o commit local, registram a confirmação no log e enviam um ack (reconhecimento) ao coordenador.
	- Os participantes que recebem doAbort efetuam o abort local, registram no log e enviam um ack.
	- Quando o coordenador recebe todos os acks, ele registra o final da transação (end_of_transaction) em seu log.

### **Tratamento de Falhas no 2PC**

O 2PC deve lidar robustamente com falhas de processos e de comunicação. O protocolo utiliza **timeouts** e **registros em log estável** para se recuperar.

- **Falha de um Participante durante a Fase 1**: Se não responder, o coordenador assume um voto No após um timeout e aborta a transação.
- **Falha do Coordenador durante a Fase 2**: Se o coordenador falha após enviar prepare mas antes de enviar a decisão, os participantes que votaram Yes ficam bloqueados em estado de incerteza. Eles devem permanecer assim até se recuperarem e consultarem o coordenador ou outro participante para descobrir o resultado final.
- **Falha de um Participante após votar** **Yes**: Ao se recuperar, o participante consulta seu log. Se encontrar um registro commit ou abort, execute a ação correspondente (redo ou undo). Se estiver no estado uncertain (incerto), deve consultar o coordenador ou outros participantes para descobrir o resultado da transação e finalizá-la localmente.

O 2PC é um protocolo **bloqueante**. Se o coordenador falhar após enviar mensagens prepare e antes de registrar a decisão, os participantes que votaram Yes ficarão bloqueados indefinidamente até que o coordenador se recupere. Técnicas como o **2PC de três fases (3PC)** foram propostas para eliminar esse bloqueio, mas introduzem maior complexidade e overhead de mensagens.

## **Implementações e Considerações Práticas**

Sistemas de Gerenciamento de Banco de Dados (SGBD) distribuídos comerciais, como Oracle, Microsoft SQL Server e IBM DB2, implementam nativamente suporte a transações distribuídas e o protocolo 2PC.

Além dos SGBDs, os **Monitores de Transação (TP Monitors)**, como Microsoft Transaction Server (MTS), BEA Tuxedo e Java Transaction Service (JTS), são componentes essenciais em arquiteturas de três camadas. Suas principais funções são:

- Garantir a atomicidade de transações distribuídas que envolvem múltiplos recursos (ex: dois bancos de dados diferentes), geralmente atuando como o coordenador do protocolo 2PC.
- Gerenciar a concorrência e o pooling de conexões, multiplexando a carga de acesso aos SGBDs para melhorar a escalabilidade e o desempenho.

Em resumo, as transações distribuídas e o protocolo 2PC são pilares para a construção de sistemas distribuídos confiáveis e consistentes, assegurando que operações complexas, que abrangem múltiplos sistemas independentes, sejam executadas de forma atomica e durável, mesmo na presença de falhas.