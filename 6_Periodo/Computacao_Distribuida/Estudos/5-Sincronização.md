# Sincronização em Sistemas Distribuídos

## Introdução à Sincronização de Processos

A sincronização é um dos pilares fundamentais, juntamente com a comunicação, para o correto funcionamento de qualquer aplicação. 

Processos são considerados cooperantes quando afetam ou são afetados por outros processos, podendo compartilhar um espaço de endereçamento lógico (como threads) ou arquivos. O acesso concorrente a dados compartilhados por esses processos pode levar a inconsistências, exigindo mecanismos para garantir a integridade dos dados.

Um exemplo clássico que ilustra esse problema é o caso produtor/consumidor, onde dois processos acessam um buffer compartilhado. Isoladamente, os algoritmos de produção e consumo são corretos, mas quando executados em paralelo, podem gerar condições de corrida (race conditions), levando a resultados inconsistentes. A região de código onde um processo acessa dados compartilhados é chamada de **seção crítica**. Para resolver o problema de acesso concorrente, qualquer solução para a seção crítica deve satisfazer três requisitos essenciais:

- **Exclusão mútua**: Se um processo está executando em sua seção crítica, nenhum outro processo pode executar na sua.
    
- **Progressão**: Se nenhum processo está na seção crítica e vários desejam entrar, apenas aqueles que desejam entrar podem participar da decisão de quem entrará a seguir, e essa decisão não pode ser adiada indefinidamente.
    
- **Espera limitada**: Deve existir um limite superior para o número de vezes que outros processos são permitidos a entrar na seção crítica após um processo ter feito uma requisição para entrar, evitando assim starvation (adiamento indefinido).
    

Em sistemas centralizados, soluções como semáforos, monitores e variáveis de condição são implementadas usando memória compartilhada. No entanto, em sistemas distribuídos, onde não há memória compartilhada, a sincronização deve ser realizada através da troca de mensagens, implementada por algoritmos distribuídos. Esta mudança de paradigma introduz complexidades significativas, pois até mesmo determinar a ordem relativa de dois eventos (se o evento A ocorreu antes, depois ou concorrentemente com o evento B) torna-se uma tarefa não trivial.

## Sincronização Física de Relógios

A medição do tempo é crucial em sistemas computacionais, seja para marcar a ocorrência de eventos ou para medir intervalos. Em um sistema centralizado, obter um horário consistente é simples, pois há um único relógio e o núcleo do sistema operacional pode fornecer o tempo para todos os processos. Em contraste, em um sistema distribuído, alcançar um consenso sobre o tempo entre várias máquinas independentes é um desafio complexo.

Historicamente, o tempo foi medido com base na astronomia, definindo um **dia solar** como o intervalo entre dois trânsitos solares consecutivos. No entanto, em meados do século XX, descobriu-se que a rotação da Terra não é constante, sofrendo uma desaceleração gradual devido a efeitos de maré e ao atrito atmosférico. Esta variação tornou a definição astronômica do segundo imprecisa para aplicações científicas modernas.

A invenção do **relógio atômico** em 1948 revolucionou a cronometragem. Este dispositivo mede o tempo com base em transições eletrônicas ultra-estáveis no átomo de césio-133, sendo definido que **1 segundo solar médio equivale a 9.192.631.770 transições** do césio-133. Isso permitiu a criação de uma escala de tempo extremamente precisa e independente das variações da rotação terrestre, conhecida como **Tempo Atômico Internacional (TAI)**.

Com base no TAI, mas com correções ocasionais (os "segundos bissextos" ou leap seconds) para manter o alinhamento aproximado com o dia solar médio, foi estabelecido o **Tempo Universal Coordenado (UTC)**, que serve como padrão global para a medição civil do tempo. O UTC é disseminado globalmente através de várias fontes, incluindo transmissões de rádio de ondas curtas (como o serviço WWV operado pelo NIST nos EUA) e sinais de satélites, como os do **Sistema de Posicionamento Global (GPS)**, que utilizam relógios atômicos a bordo e permitem a triangulação precisa baseada em diferenças de tempo.

Os relógios de hardware dos computadores, tipicamente baseados em cristais de quartzo, são muito menos precisos que os atômicos e estão sujeitos ao **clock drift** (deriva do relógio), em que o relógio local gradualmente adianta ou atrasa em relação ao tempo real. Em média, um relógio de computador pode derivar cerca de um segundo a cada 11,6 dias. Portanto, o objetivo da **sincronização física de relógios** é manter os relógios de um conjunto de máquinas sincronizados dentro de um limite tolerável ε, ou seja, $|C_i - C_j| < \varepsilon$ para quaisquer duas máquinas $i$ e $j$. Isto é crítico para sistemas de tempo real e de missão crítica.

### Algoritmos de Sincronização Física

- **Algoritmo de Cristian (1989):** Um algoritmo simples em que um cliente solicita o tempo atual a um servidor de tempo confiável (que mantém o UTC). O cliente calcula o **tempo de propagação (TP)** da mensagem para estimar e ajustar seu relógio. Se $T_e$ é o momento de envio da solicitação, $T_r$ é o momento de recebimento da resposta, e $I$ é o tempo de processamento no servidor (geralmente insignificante), então $TP ≈ (T_r - T_e) / 2$. O cliente define seu novo tempo como $CUTC + TP$. Um problema crítico é que se o cliente estiver adiantado, simplesmente retroceder o relógio violaria a monotonicidade do tempo (a ideia de que o tempo sempre avança). A solução é ajustar o relógio gradativamente, diminuindo lentamente a sua taxa de avanço até que a correção seja absorvida. O **Network Time Protocol (NTP)** é a implementação prática e robusta desta ideia na Internet.
    
- **Network Time Protocol (NTP):** Padronizado pela IETF (RFC 1129 e outros), o NTP é um dos serviços mais antigos e estáveis da Internet. Baseia-se numa **arquitetura hierárquica em camadas (strata)**. Servidores **Stratum 0** são os dispositivos de mais alta precisão, como relógios atômicos ou receptores GPS. Servidores **Stratum 1** são computadores sincronizados diretamente com um Stratum 0. Servidores **Stratum 2** sincronizam com Stratum 1, e assim por diante, até o Stratum 15. Esta hierarquia fornece escalabilidade, resiliência e precisão. O NTP utiliza UDP e algoritmos sofisticados para trocar mensagens de tempo entre clientes e servidores, filtrando atrasos de rede e calculando compensações de relógio de forma estatisticamente robusta.
    
- **Algoritmo de Berkeley:** Diferente do modelo cliente-servidor passivo do NTP, neste algoritmo um servidor de tempo central (ou _daemon_) é ativo. Periodicamente, ele consulta o tempo de todas as outras máquinas no grupo. Em seguida, calcula a **média** dos tempos recebidos (ignorando outliers) e, ao invés de informar o tempo absoluto, informa a cada máquina o **deslocamento** (offset) pelo qual seu relógio deve ser ajustado. O servidor também ajusta seu próprio relógio com base nesse cálculo. Este método é eficaz para sincronizar um grupo fechado de máquinas onde não há acesso a uma fonte de tempo externa autoritativa.
    
- **Reference Broadcast Synchronization (RBS):** Este algoritmo foi projetado para redes _wireless_ e sensores, visando economia de energia. Ele não assume que qualquer nó conheça o tempo real absoluto, focando apenas na **sincronização relativa** entre os nós. Um nó transmite uma mensagem de referência (beacon) para seus vizinhos. Cada nó receptor registra o horário local em que recebeu a mensagem. Os nós então trocam esses horários de recepção entre si. O deslocamento de tempo entre dois nós, $p$ e $q$, é calculado como a média das diferenças entre seus tempos de recepção para várias mensagens de beacon. Dessa forma, cada nó pode manter uma tabela de offsets em relação aos seus vizinhos sem precisar alterar constantemente seu próprio relógio físico, economizando energia.
    

## Sincronização Lógica e Ordenação de Eventos

Para muitos problemas em sistemas distribuídos, conhecer a hora física exata é menos importante do que conhecer a **ordem causal dos eventos**. Leslie Lamport, em seu artigo seminal "Time, Clocks, and the Ordering of Events in a Distributed System" (1978), demonstrou que é possível ordenar eventos sem relógios físicos perfeitamente sincronizados, introduzindo os conceitos de **relação happens-before** e **relógios lógicos**.

### Relação Happens-Before

A relação "ocorre-antes" ($\to$) é uma ordem parcial que captura a causalidade entre eventos:

1. Se os eventos A e B ocorrem no mesmo processo e A é executado antes de B, então A **$\to$** B.
    
2. Se o evento A é o envio de uma mensagem e o evento B é a recepção dessa mesma mensagem, então A $\to$ B.
    
3. Se A $\to$ B e B $\to$ C, então A $\to$ C (propriedade transitiva).
    

Dois eventos que não estão relacionados por $\to$ (ou seja, nem A $\to$ B nem B $\to$ A) são ditos **concorrentes** (A || B). Isso significa que são causalmente independentes; nenhum influenciou o outro e não há como determinar qual ocorreu "primeiro" em um sentido absoluto.

### Relógios Lógicos de Lamport

Para implementar a relação happens-before, Lamport propôs **relógios lógicos**. Cada processo $P_i$ mantém um contador inteiro $C_i$, seu relógio lógico, que é incrementado antes da ocorrência de cada evento local. As regras para atualizar o relógio lógico são:

- **Regra 1:** Antes de executar um evento, $P_i$ executa $C_i := C_i + 1$.
    
- **Regra 2:** Quando o processo $P_i$ envia uma mensagem m, ele anexa a essa mensagem o timestamp $t = C_i$.
    
- **Regra 3:** Ao receber uma mensagem (m, t), o processo $P_j$ calcula $C_j := max(C_j, t) + 1$ e então entrega a mensagem à aplicação.
    

Essas regras garantem que se o evento A $\to$ B, então C(A) < C(B). A recíproca, no entanto, **não é verdadeira**: se C(A) < C(B), não se pode concluir que A $\to$ B, pois A e B podem ser eventos concorrentes. Os relógios de Lamport fornecem apenas uma **ordem total consistentemente com a causalidade**, mas não capturam a causalidade por completo. Para obter uma ordem total única entre todos os eventos, é comum complementar o timestamp lógico com um identificador único do processo (baseado no IP do processo, por exemplo), garantindo que timestamps de eventos concorrentes sejam únicos.

### Relógios Vetoriais

Para superar a limitação dos relógios de Lamport e capturar **completamente a relação de causalidade**, foram propostos os **relógios vetoriais**. Um relógio vetorial Vi para um sistema com N processos é um vetor de N inteiros, onde:

- Vi[i] é o número de eventos que ocorreram em Pi.
    
- Vi[j] (para j ≠ i) representa o conhecimento que Pi tem sobre o número de eventos ocorridos em Pj.
    

As regras de atualização são:

- **Inicialmente,** Vi[j] = 0 para todo i, j.
    
- **Antes de um evento em Pi,** Vi[i] := Vi[i] + 1.
    
- **Pi inclui t = Vi** em cada mensagem que envia.
    
- **Ao receber uma mensagem com timestamp t,** Pi faz Vi[j] := max(Vi[j], t[j]) para todo j, e então aplica a regra de incremento para o evento de recepção.
    

Com os relógios vetoriais, é possível determinar com precisão a relação causal entre quaisquer dois eventos:

- Se V(e) < V(e'), então e $\to$ e' (e é causalmente anterior a e').
    
- Se V(e) || V(e') (os vetores são incomparáveis: nem V(e) ≤ V(e') nem V(e') ≤ V(e)), então os eventos e e e' são concorrentes.
    

A principal desvantagem dos relógios vetoriais é o **overhead**, pois o tamanho do vetor é proporcional ao número de processos no sistema, o que pode se tornar custoso em termos de armazenamento e largura de banda de rede em sistemas muito grandes.