# Comunicação entre Processos

Permite que processos executando em diferentes máquinas, possivelmente em diferentes redes, cooperem para realizar uma tarefa comum. Este conceito contrasta fortemente com sistemas monolíticos, onde a comunicação se dá através de mecanismos simples como funções e variáveis globais.

## **Introdução aos Serviços de Rede e Modelos de Comutação**

A comunicação em rede baseia-se em esquemas de comutação que definem como os dados trafegam. O _broadcast_ é o método mais simples, em que tudo é enviado para todos os nós. 

- A _comutação de circuitos_ estabelece um canal dedicado de comunicação entre as partes antes que os dados sejam transmitidos. 
- Já a _comutação de pacotes_, base da internet moderna, opera sob um sistema de armazenamento e encaminhamento, onde os dados são quebrados em pacotes que trafegam pela rede de forma independente, com base nas informações de origem e destino contidas em seus cabeçalhos. Roteadores examinam esses endereços e tomam decisões de encaminhamento para que os pacotes cheguem ao seu destino.

### **O Modelo Cliente/Servidor**

O modelo cliente-servidor é a arquitetura mais predominante para estruturar aplicações distribuídas. Nele, os papéis são bem definidos:

- O **servidor** é um programa passivo que provê um serviço ou recurso específico. Ele é normalmente inicializado no _boot_ do sistema e fica aguardando, indefinidamente, por requisições de clientes.
    
- O **cliente** é um programa ativo que precisa utilizar um recurso disponibilizado na rede. Ele é quem inicia a comunicação, procurando ativamente pelo servidor que oferece o serviço desejado.
    

É crucial notar que servidor e cliente são _papéis_ e não necessariamente _máquinas_. Eles podem residir na mesma máquina ou em quaisquer pontos da rede. 

Um servidor que fica permanentemente ativo é frequentemente chamado de _daemon_ e possui um endereço bem conhecido. 

A interação entre cliente e servidor é regida por um **protocolo**, um conjunto estrito de regras que define os comandos aceitos e o formato das mensagens trocadas.

#### **Pilhas de Protocolos: OSI e TCP/IP**

Para gerenciar a complexidade da comunicação em rede, os sistemas usam pilhas de protocolos organizadas em camadas. O **Modelo OSI** (Open Systems Interconnection) é um modelo de referência teórico com sete camadas:

1. **Física:** Define os meios físicos (elétrico, rádio, laser).
    
2. **Enlace de Dados:** Controla a comunicação entre nós diretamente conectados (Ethernet, Wi-Fi).
    
3. **Rede:** Roteia pacotes através de redes diferentes (IP, ICMP).
    
4. **Transporte:** Controla a comunicação fim-a-fim, garantindo confiabilidade (TCP, UDP).
    
5. **Sessão:** Gerencia diálogos e sincronização entre aplicações.
    
6. **Apresentação:** Trata da representação dos dados (criptografia, conversão de formatos - TLS).
    
7. **Aplicação:** Oferece serviços diretamente às aplicações do usuário (HTTP, SMTP, FTP).
    

Na prática, a internet é construída sobre o **Modelo TCP/IP** (ou UDP/IP), mais simples e prático. O **IP** (Internet Protocol) atua na camada de rede e é responsável por endereçar e rotear pacotes entre máquinas. O **TCP** (Transmission Control Protocol) e o **UDP** (User Datagram Protocol) atuam na camada de transporte. O TCP é orientado a conexão, garantindo entrega ordenada e sem erros. O UDP é não-orientado a conexão, não garantindo entrega ou ordem, mas oferecendo menor overhead e latência.

### **Endereçamento**

Para que processos se comuniquem, precisam ser endereçados de maneira única. Um processo é identificado por um par **(Endereço IP, Número de Porta)**. O endereço IP (32 bits no IPv4, 128 bits no IPv6) identifica a máquina na rede. A porta (usualmente 16 bits em UNIX) identifica o processo ou serviço específico dentro daquela máquina. As portas de 0 a 1023 são reservadas para serviços bem conhecidos (ex: 80 para HTTP). O sistema operacional mantém uma lista dos serviços ativos, e funções como `getservbyname()` permitem que clientes descubram a porta de um servidor baseado em seu nome.

### **Troca de Mensagens: A Primitiva Fundamental**

A comunicação em sistemas distribuídos é baseada na troca de mensagens, implementada através de duas primitivas de baixo nível: `send` (enviar) e `receive` (receber). Essas primitivas podem operar de duas modalidades:

- **Síncrona (Bloqueante):** Um `send` só completa quando o destinatário executar um `receive`. Um `receive` bloqueia o processo até que uma mensagem chegue. É simples de programar, mas pode subutilizar a CPU.
    
- **Assíncrona (Não-bloqueante):** O `send` copia a mensagem para um buffer do _kernel_ e retorna imediatamente. O `receive` fornece um buffer para ser preenchido em _background_, e o processo é notificado via _polling_ ou interrupção. Oferece melhor desempenho, mas é mais complexo de implementar.
    

### **Marshalling e Unmarshalling**

Dados em memória têm formatos específicos de cada arquitetura (little-endian, big-endian, tamanho de tipos). Para transmiti-los, é necessário convertê-los para um formato padrão da rede. Este processo é chamado de **marshalling** (ou "empacotamento"). O processo inverso, de reconstruir a estrutura de dados na máquina de destino a partir do formato da rede, é o **unmarshalling** (ou "desempacotamento"). Fazer isso manualmente é tedioso e propenso a erros.

Existem duas abordagens principais para descrever os dados:

- **Tipagem Implícita (Ex: XDR, NDR):** Apenas os dados são transmitidos. O receptor deve saber antecipadamente a estrutura. Requer uma linguagem de definição de interface (IDL) e um compilador.
    
- **Tipagem Explícita (Ex: JSON, XML):** O tipo de cada campo é transmitido junto com os dados, tornando as mensagens autodescritivas, porém potencialmente mais verbosas.
    

### **Chamada Remota de Procedimento (RPC)**

Para tornar a programação distribuída mais natural, abstrações de alto nível foram criadas para "esconder" a complexidade da troca de mensagens. A mais notável é a **Chamada Remota de Procedimento (RPC)**, que permite que um cliente invoque um procedimento em um servidor remoto como se fosse uma chamada local.

A arquitetura RPC baseia-se em **stubs** (esqueletos) gerados automaticamente por um compilador (como o `rpcgen` do Sun RPC) a partir de uma interface definida em uma IDL (como XDR).

- O **stub do cliente** se passa pelo procedimento local. Ele é responsável por fazer o _marshalling_ dos argumentos (_marshalling_), empacotá-los em uma mensagem de requisição e enviá-la ao servidor via módulo de comunicação. Na volta, faz o _unmarshalling_ do resultado.
    
- O **módulo de comunicação** lida com problemas de rede, como retransmissões e _timeouts_.
    
- No servidor, um **despachante** (_dispatcher_) recebe a requisição, identifica o procedimento correto com base em um ID e a encaminha para o **stub do servidor** correspondente.
    
- O **stub do servidor** faz o _unmarshalling_ dos argumentos, chama o procedimento real de serviço, faz o _marshalling_ do resultado e envia a resposta de volta.
    

#### **Vantagens e Desafios do RPC**

O RPC introduz o **princípio da separação de privilégios**, em que o código remoto é executado com privilégios potencialmente diferentes do cliente, aumentando a segurança. No entanto, chamadas RPC são ordens de grandeza mais lentas que chamadas locais devido ao overhead de _marshalling_, comunicação de rede e tratamento de falhas.

Três desafios centrais do RPC são:

1. **Passagem de Parâmetros:** A passagem por referência é complexa, pois endereços de memória locais são sem significado no servidor. Soluções incluem usar semântica de copiar/restaurar (valor/resultado) ou simplesmente proibir passagem por referência (como no Sun RPC, que só permite passagem por valor).
    
2. **Ligação (_Binding_):** Como o cliente descobre o servidor? Pode ser feito de forma estática (endereço no código) ou dinâmica, usando um serviço de diretório (como o _portmapper_).
    
3. **Semântica de Chamada:** Em um ambiente com falhas, quantas vezes um procedimento é executado?
    
    - **Exactly-Once (Exatamente Uma Vez):** Ideal, mas impossível de garantir em certos cenários de falha.
        
    - **At-Least-Once (Pelo Menos Uma Vez):** O cliente retransmite até receber uma resposta. Adequado para operações **idempotentes** (que podem ser executadas múltiplas vezes sem efeitos colaterais, como uma consulta).
        
    - **At-Most-Once (No Máximo Uma Vez):** O servidor usa um cache de IDs de requisição para detectar e ignorar duplicatas. É a semântica usada pelo Sun RPC. Adequado para operações **não-idempotentes** (com efeitos colaterais, como uma transferência bancária).
        

Finalmente, a **segurança** é um aspecto crítico. Mecanismos de autenticação variam desde nenhuma, autenticação básica de usuário UNIX, até métodos mais robustos baseados em chaves criptográficas (DES) ou integração com protocolos como Kerberos.

#### Exmplo

- Passo 1:
	- Chamada local soma (x, y)
- Passo 2:
	- Stub do cliente “captura” chamada e realiza o marshalling de seus parâmetros
- Passo 3:
	- Envio de mensagem com os parâmetros
- Passo 4:
	- Recebimento da mensagem na máquina remota e chamada ao stub do servidor
- Passo 5
	- Stub do servidor realiza o unmarshalling do parâmetros e chama o procedimento remoto
- Passo 6:
	- Execução do procedimento remoto
- Passo 7:
	- Stub do servidor realiza o marshalling do resultado
- Passo 8:
	- Envio da mensagem com o resultado
- Passo 9:
	- Recebimento do resultado e chamada ao stub do cliente
- Passo 10:
	- Stub do cliente realiza o unmarshalling do resultado e retorna o mesmo ao cliente