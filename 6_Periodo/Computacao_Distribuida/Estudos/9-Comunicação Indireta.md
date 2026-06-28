# **Comunicação Indireta em Sistemas Distribuídos**

A comunicação indireta é um paradigma fundamental em sistemas distribuídos, no qual as entidades se comunicam por meio de um intermediário, ao invés de através de interação direta. Esse modelo oferece desacoplamento espacial e temporal, o que significa que os remetentes não precisam conhecer a identidade dos destinatários (desacoplamento espacial) e os participantes não precisam coexistir no mesmo intervalo de tempo para que a comunicação ocorra (desacoplamento temporal). Essa característica é crucial para ambientes dinâmicos, móveis e de larga escala, onde a disponibilidade e a localização dos processos podem variar constantemente.

O desacoplamento espacial facilita a substituição de componentes em caso de falha, oferece transparência em relação à duplicação e migração de serviços e permite a escalabilidade do sistema. Já o desacoplamento temporal é particularmente vantajoso em cenários com conectividade intermitente, como em aplicações móveis ou em ambientes com restrições de rede, onde os processos podem se desconectar e reconectar sem prejudicar a comunicação.

No entanto, a introdução de intermediários na comunicação indireta traz desafios, como aumento da complexidade do sistema e potencial impacto no desempenho. Como observado por Jim Gray, "não há um problema de desempenho que não possa ser resolvido pela eliminação de um nível de indireção", o que ressalta a importância de equilibrar os benefícios do desacoplamento com a eficiência do sistema.

**Principais Paradigmas de Comunicação Indireta**

1. **Comunicação em Grupo**
	- Envolve o envio de uma mensagem para um grupo, que é então entregue a todos os seus membros. Esse modelo é construído sobre abstrações como multicast IP ou redes de sobreposição (_overlay networks_), e o remetente não precisa conhecer os destinatários individuais.
	- **Características importantes:**
		- _Grupos fechados:_ Apenas membros podem enviar mensagens ao grupo. Comum em coordenação de servidores replicados.
		- _Grupos abertos:_ Qualquer processo pode enviar mensagens ao grupo. Útil para entrega de eventos a múltiplos interessados.
		- _Garantias de entrega:_ Incluem integridade (entrega correta e sem duplicações), validade (entrega eventual) e acordo (entrega para todos ou para nenhum membro).
		- _Ordenação de mensagens:_ Pode ser FIFO (preserva a ordem de envio por remetente), causal (preserva a relação "happens-before") ou total (todas as mensagens são entregues na mesma ordem para todos).
	- O gerenciamento de membros é essencial, tratando de ingressões, saídas e falhas, e notificando o grupo sobre mudanças. Ferramentas como o _JGroups_ oferecem suporte a canais de comunicação confiáveis e pilhas de protocolos flexíveis para implementar esses serviços.

2. **Modelo Publish-Subscribe**
	- Neste modelo, os _publishers_ publicam eventos em um serviço de eventos (_Event Service - ES_), e os _subscribers_ expressam interesse em tipos específicos de eventos. O ES é responsável por fazer o casamento entre eventos e assinaturas.
	- **Modelos de assinatura:**
		- _Baseado em canal:_ Os publicadores publicam em canais nomeados, e os assinantes recebem todos os eventos do canal.
		- _Baseado em tópico:_ Os eventos possuem um campo de tópico, e as assinaturas selecionam tópicos de interesse, muitas vezes organizados hierarquicamente.
		- _Baseado em conteúdo:_ As assinaturas especificam restrições sobre múltiplos campos dos eventos, usando uma linguagem de consulta.
		- _Baseado em tipo:_ Utiliza tipos de objetos para definir assinaturas, integrando-se naturalmente com linguagens orientadas a objetos.
	- **Implementação e roteamento:**
		- Pode ser centralizada ou distribuída, com uma rede de _brokers_.
		- Estratégias de roteamento incluem _flooding_ (envio para todos os nós), _filtering_ (encaminhamento seletivo com base em assinaturas), _rendez-vous_ (particionamento do espaço de eventos) e uso de _DHTs_ (tabelas hash distribuídas) em redes P2P.
		- Aplicações típicas incluem sistemas financeiros, feeds RSS, trabalho cooperativo, computação ubíqua e monitoramento.

5. **Filas de Mensagens (Message-Oriented Middleware - MOM)**
	- Oferecem um serviço ponto a ponto por meio de filas, onde produtores enviam mensagens e consumidores as recebem.
	- **Características:**
		- _Desacoplamento temporal:_ As mensagens são persistentes e armazenadas até o consumo.
		- _Estilos de recepção:_ Bloqueante, não-bloqueante (_polling_) ou por notificação.
		- _Metadados e corpo:_ As mensagens possuem cabeçalho com informações como prioridade e destino, e um corpo opaco.
		- _Funcionalidades avançadas:_ Transações, transformação de dados, integração com bancos de dados e segurança.
	- Implementações podem ser centralizadas ou distribuídas. Exemplos incluem IBM WebSphere MQ, Microsoft MSMQ, e Oracle Streams AQ. O padrão _Java Message Service (JMS)_ unifica o acesso a sistemas de filas e publish-subscribe em Java.

7. **Memória Compartilhada Distribuída (DSM)**
	
	- Fornece a abstração de uma memória compartilhada entre nós que não compartilham memória física. Os processos acessam a DSM por meio de operações de leitura e escrita em seus espaços de endereçamento.
	- **Vantagens em relação à troca de mensagens:**
		- Elimina a necessidade de _marshalling_ explícito para estruturas de dados compartilhadas.
		- Suporta ponteiros e referências diretamente.
	- **Desafios:**
		- Controle de concorrência e consistência devem ser gerenciados pelo _runtime_ da DSM.
		- Pode introduzir overhead de sincronização.
		- DSM persistente permite desacoplamento temporal, mantendo o estado além do tempo de vida dos processos.

9. **Espaços de Tuplas**

	- Baseado no modelo de comunicação generativa, em que processos se comunicam indiretamente ao inserir (_write_), ler (_read_) ou remover (_take_) tuplas de um espaço compartilhado.
	- **Características:**
		- _Tuplas são imutáveis:_ Modificações são feitas substituindo tuplas.
		- _Acesso associativo:_ As operações usam padrões para casar com tuplas baseadas em seu conteúdo.
		- _Não-determinismo:_ Se múltiplas tuplas casam, uma é escolhida não deterministicamente.
	- **Implementação distribuída:**
		- Envolve replicação e protocolos para garantir consistência durante operações _write_, _read_ e _take_, incluindo o uso de travas e multicast para coordenação.
		- Exemplos como _JavaSpaces_ oferecem operações para manipulação de entradas com suporte a transações e notificações.

**Comparação entre os Paradigmas**

Cada paradigma possui trade-offs entre escalabilidade, expressividade e overhead:

- **Comunicação em grupo** e **publish-subscribe** são baseados em comunicação e podem escalar bem com infraestrutura adequada, mas variam em expressividade (por exemplo, publish-subscribe baseado em conteúdo é mais expressivo que grupos).
- **Filas de mensagens** oferecem desacoplamento temporal forte e garantias de persistência, mas são tipicamente ponto a ponto.
- **DSM** e **espaços de tuplas** são baseados em estado, o que facilita o compartilhamento de dados complexos, mas impõe desafios de escalabilidade devido à necessidade de manter consistência.

O endereçamento associativo, presente em espaços de tuplas e em publish-subscribe baseado em conteúdo, permite casamento de padrões baseado no conteúdo, em vez de identificadores explícitos, oferecendo maior flexibilidade.

**Conclusão**

A comunicação indireta é um pilar para a construção de sistemas distribuídos flexíveis, resilientes e escaláveis. A escolha do paradigma adequado depende dos requisitos de acoplamento, consistência, escalabilidade e expressividade da aplicação. Compreender as características e trade-offs de cada abordagem é essencial para projetar soluções eficientes e robustas em ambientes distribuídos modernos.