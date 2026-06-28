# Resumo: Domain Name System (DNS)

- Banco de dados distribuído responsável pelo mapeamento entre os nomes e endereços IPs.
- Esquema de nomes hierárquico, baseado em domínio.
- Pode ser visto como um middleware para preencher um gap entre as aplicações e as outras camadas da rede.
- Normalmente, utilizado por aplicações (não usuário).
- Utiliza o protocolo UDP na porta 53.

- Espaço de nomes: 
	- define o conjunto de nomes possíveis.
	- Endereçamento na Internet é dividido em domínios que podem ser divididos em sub-domínios, etc.
	- Cada domínio controla a alocação de seus sub-domínios.
	- Nomes de domínio são insensíveis ao case (por exemplo, Edu = edu = EDU).
	- Para criarmos um novo sub-domínio, devemos pedir permissão ao domínio (No Brasil, o NIC.br).
- Registro de recursos: 
	- define os campos do banco de dados.
	- Cada domínio possui um conjunto de registros de recursos com os campos: $<Name,TTL,Class,Type,Value>$.
- Servidores de nome: 
	- contém registros de recursos e está preparado para receber requisições.
	- O espaço de nomes do DNS é dividido em zonas sem sobreposições:
		- Cada zona corresponde a uma parte da árvore.
		- Cada zona possui servidores de nomes que contêm informações sobre a zona.
	- Mapeamento:
		- Recursivo: o servidor DNS recebe a consulta e se responsabiliza por buscar a resposta completa, consultando outros servidores até resolver o nome
		- Não recursivo (iterativo): o servidor não busca toda a resposta, apenas indica outro servidor mais próximo da resposta final. Cabe ao cliente ou resolvedor seguir a cadeia de consultas.
- Resolvedor: 
	- é o processo presente na máquina do usuário que faz as requisições aos servidores de nome.

- DNS Dinâmico (DDNS):
	- Necessário quando o endereço IP de um servidor muda dinamicamente
	- Servidor de DNS dinâmico armazena nome e endereço IP atual de um servidor
	- Sempre que o endereço de um servidor atualiza ele informa ao servidor de DNS
	- Cliente requisita o endereço atual de um servidor ao servidor DNS