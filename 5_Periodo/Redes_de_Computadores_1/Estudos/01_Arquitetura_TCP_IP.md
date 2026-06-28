# Resumo: Arquitetura TCP/IP

## Conceitos Básicos

- Baseada em uma pilha de camadas em que cada camada é responsável por tarefas específicas.
- Detalhes de especificação e implementação não fazem parte da arquitetura.
- Tarefas de cada camada são implementadas em protocolos, criando uma pilha de protocolos.
- Pilha de Camadas:
	- Separa tarefas, reduzindo a complexidade do projeto.
	- Cada camada oferece serviços para suas superiores e abstrai detalhes.
	- Cada camada acredita que se comunica diretamente com seu par na outra máquina.
- Comunicação virtual (horizontal) entre entidades pares é virtual e executada através do protocolo da camada.
- Comunicação real (vertical) é feita entre entidades na mesma hierarquia.
- Comunicação ocorre efetivamente na camada mais baixa através de um meio físico.

## Modelos de Referência

- ISO/OSI:
	- É um modelo teórico de referência, desenvolvido principalmente para padronização.
	- Possui 7 camadas:
		- Aplicação;
		- Apresentação;
		- Sessão;
		- Transporte;
		- Rede;
		- Enlace;
		- Física.
- TCP/IP:
	- É um modelo prático, criado a partir da implementação da Internet, com protocolos realmente usados.
	- Possui 4 camadas.
		- Aplicação;
		- Transporte;
		- Internet (Rede);
		- Enlace (também chamada de Acesso à Rede, Física, Interface Física ou Interface de Hardware).
- Organização em Camadas:
	- Física:
		- Transmissão de bits ("cospe bits").
		- Define interfaces elétricas, de sincronização e outras, pelas quais os bits são enviados como sinais pelos canais.
	- Enlace:
		- Responsável por enquadramento, controle de fluxo e controle de erro.
		- A palavra chave é "vizinho".
		- Endereço Ethernet, Físico ou MAC, representado em hexadecimal e separados por dois-pontos ou hífen, tem 6 Bytes, é único.
	- Rede:
		- Roteamento de pacotes.
		- Usa o protocolo IP (Internet Protocol) que tem as versões IPv4 e IPv6.
			- IPv4:
				- Cada endereço IP tem $32$ bits e é representado em quartetos de oito bits separados por um ponto. Assim, temos, $x_1 . x_2 . x_3 . x_4$, onde cada $x_i$ é número entre $0$ e $255$.
				- Endereços $127.x_2.x_3.x_4$ representam a máquina local ou (localhost).
		- Endereço IP definido pelo servidor de DHCP da rede ou manualmente pelo projetista. 
	- Transporte:
		- Comunicação fim a fim, gerenciando processos (serviços) de comunicação que rodam exclusivamente na origem e destino.
		- Usa os protocolos UDP (User Datagram Protocol) e TCP (Transmission Control Protocol).
		- Endereço é a porta, de 16 bits, que endereça todos os processos de comunicação de uma máquina.
		- Cada serviço disponível em uma máquina possui uma porta.
		- Endereço IP identifica cada máquina em uma rede e a porta, cada serviço em uma máquina.
		- A palavra chave é "processo".
	- Sessão:
		- Sincronização, verificação, recuperação e troca de dados.
	- Apresentação:
		- Representação de dados, por exemplo: criptografia, compactação.
	- Aplicação:
		- Por exemplo: HTTP, e-mail, FTP, áudio, vídeo e arquivos.
	- Distinção entre Camadas Superiores e Inferiores:
		- Camadas Superiores: 
			- ISO/OSI = {Aplicação, Apresentação, Sessão},  TCP/IP = {Aplicação}.
			- Usuários do serviço de transporte.
		- Camadas Inferiores:
			- ISO/OSI = {Transporte, Rede, Enlace, Física}, TCP/IP = {Transporte, Internet, Enlace}
			- Provedores de serviços de transporte.

## Métricas de Rede

- Latency (Latência):
	- É o tempo que um dado leva para ir da origem até o destino. Representa o “atraso” da comunicação.
- Bandwidth (Largura de Banda):
	- É a capacidade máxima do canal de comunicação, ou seja, a quantidade máxima de dados que pode ser transmitida por unidade de tempo.
- Throughput (Taxa de Dados):
	- É a quantidade efetiva de dados transmitidos por unidade de tempo.
- Jitter (Flutuação)
	- Variação no atraso entre pacotes de um fluxo de dados.
	- Afeta a qualidade de áudio e vídeo em aplicações como VoIP e streaming.
	- Causa o congestionamento na rede e a configuração inadequada de dispositivos.
- Reliability (Confiabilidade):
	- Capacidade da rede de manter a comunicação sem falhas ao longo do tempo.
	- Considera a disponibilidade da rede (uptime) e a capacidade de recuperação após falhas.
- Packet loss rate (Taxa de perda de pacotes):
	- Percentual de pacotes de dados que não chegam ao destino.
	- Afeta a qualidade em videoconferências, jogos online e streaming.
	- Causas: congestionamento, interferências e problemas de HW/roteamento.