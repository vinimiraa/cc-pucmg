## Fundamentos de Sistemas Distribuídos

Um **Sistema Distribuído (SD)** é fundamentalmente definido como uma coleção de computadores independentes que se apresenta ao usuário como um sistema único e coerente. Esses componentes, que podem estar geograficamente dispersos, coordenam suas ações e compartilham recursos exclusivamente por meio da **troca de mensagens** através de uma rede de computadores.

A principal motivação para sua construção é o **compartilhamento de recursos**, que pode ser de hardware ou de software, permitindo que esses recursos sejam acessados de maneira eficiente e conveniente por diversos usuários.

### Desafios

- A **Heterogeneidade** é um dos primeiros obstáculos, manifestando-se na diversidade de redes (com diferentes protocolos, velocidades e confiabilidade), hardware (com distintas arquiteturas e representações de dados), sistemas operacionais (com APIs e modelos de concorrência variados), linguagens de programação (com modelos de dados e gerenciamento de memória distintos) e até mesmo em implementações de diferentes desenvolvedores, que podem não aderir rigidamente a padrões.
- **Segurança**
- **Escalabilidade** (a capacidade do sistema de crescer e lidar com carga adicional)
- **Gerenciamento de Falhas** (garantir que o sistema continue operante mesmo com defeitos parciais)
- **Concorrência** (coordenar o acesso simultâneo a recursos compartilhados)
- **Transparência** (esconder do usuário a complexidade e distribuição do sistema).

### Caracteristicas
- A **Concorrência** é uma norma, em que múltiplos processos executam simultaneamente em diferentes máquinas, muitas vezes competindo por acesso a recursos compartilhados, o que exige mecanismos de sincronização robustos
- **Ausência de um Relógio Global**, o que significa que a coordenação entre processos deve ser feita apenas pela troca de mensagens, introduzindo incertezas relacionadas a atrasos na rede
- Devem ser **Extensíveis**, permitindo que extensões de hardware (como novos periféricos) e software (como novos serviços e protocolos) sejam facilmente integradas ao sistema através de interfaces públicas e bem definidas
- A **Tolerância a Falhas** é uma propriedade crucial, alcançada através de técnicas como redundância de hardware (ex.: bancos de dados replicados) e mecanismos de recuperação por software, que visam manter a consistência dos dados mesmo diante de falhas.

###  Propriedades Críticas

Servem como metas de projeto para um SD eficaz.

- A **Transparência** é a mais abrangente, pois busca esconder a natureza distribuída do sistema do usuário e do programador de aplicações, fazendo-o parecer um sistema centralizado. Se desdobra em vários tipos:
	- **Transparência de Acesso:** o acesso a objetos remotos e locais é feito da mesma maneira.
	- **Transparência de Localização:** acessa-se um recurso sem precisar saber onde ele está fisicamente.
	- **Transparência de Concorrência:** múltiplos usuários podem acessar recursos compartilhados sem interferência mútua.
	- **Transparência de Replicação:** o uso de múltiplas cópias de um recurso é invisível.
	- **Transparência de Falha:** as falhas são mascaradas sempre que possível.
	- **Transparência de Migração:** os recursos podem se mover sem afetar a operação.
	- **Transparência de Desempenho:** o sistema se reconfigura para manter a performance.
	- **Transparência de Escala:** o sistema pode expandir sem mudar sua estrutura.
- A **Flexibilidade** está intimamente ligada à modularidade da arquitetura do software do sistema. 
	- Modelos baseados em **micronúcleo**, que fornecem apenas mecanismos mínimos de comunicação e gerenciamento de processos, são preferíveis aos **núcleos monolíticos**, pois permitem que serviços sejam adicionados, modificados ou reparados sem parar todo o sistema.
- **Confiabilidade** engloba:
	- **Disponibilidade** (o sistema está pronto para uso quando necessário)
	- **Exatidão** (o sistema opera corretamente, um desafio em ambientes com replicação)
	- **Segurança** (proteção contra acesso não autorizado e verificação da origem das mensagens)
	- **Tolerância a Falhas**
	- **Escalabilidade** é a capacidade de o sistema manter seu desempenho à medida que o número de usuários e recursos aumenta. 
		- Para alcançá-la, utilizam-se técnicas como replicação, caching e múltiplos servidores, evitando-se ao máximo pontos centralizados (como um único servidor ou tabela) que possam se tornar gargalos.

### Elementos de um SD
- Um **Sistema de Nomes** (como o DNS) é essencial para permitir que recursos sejam localizados e compartilhados de forma independente de sua localização física. O DNS, por exemplo, traduz nomes de domínio legíveis para humanos em endereços IP numéricos através de um processo hierárquico e distribuído de consultas. 
- A **Comunicação** é o elemento vital, e seu desempenho e confiabilidade são determinantes para o sucesso ou fracasso do sistema. 
- A **Estrutura de Software** deve ser modular, com serviços bem definidos que possam interoperar sem duplicação de funções. 
- A **Alocação de Carga de Trabalho** visa otimizar o uso dos recursos de processamento e comunicação para obter um bom desempenho global.
- A **Manutenção de Consistência** é um problema complexo e multifacetado, envolvendo:
	- consistência de atualizações (atomicidade)
	- de réplicas (cópias idênticas)
	- de cache (propagação de modificações)
	- de falha (evitar falhas em cascata)
	- de relógio (sincronização física e lógica)
	- de interface de usuário (evitar inconsistências visuais devido a atrasos).

### SDs Abertos

São aqueles que oferecem serviços seguindo regras padronizadas, descritas em protocolos. Essas regras são formalizadas usando uma **Linguagem de Definição de Interface (IDL)**, que permite que processos de diferentes fornecedores e implementações se comuniquem e interoperem com base em um contrato comum. 

Essa interoperabilidade é viabilizada pelo **Middleware**, uma camada de software crucial que se situa entre os sistemas operacionais e as aplicações. O middleware abstrai a heterogeneidade subjacente de hardware, redes e sistemas operacionais, oferecendo aos desenvolvedores uma plataforma única e transparente para a construção de aplicações distribuídas. Exemplos comuns incluem CORBA, Java RMI, Web Services e APIs RESTful.