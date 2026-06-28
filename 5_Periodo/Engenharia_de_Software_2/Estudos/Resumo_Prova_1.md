
## 1. Introdução
### 1.1. Engenharia de Software

- Software engineering is an engineering discipline that is concerned with all aspects of software production.

- A engenharia de software é uma disciplina de engenharia que se preocupa com todos os aspectos da produção de software, desde os estágios iniciais da especificação do sistema até a manutenção do sistema depois que ele entra em uso.

### 1.2. Processos de Software

- Software ==specification==, where customers and engineers define the software that is to be produced and the constraints on its operation.  
- Software ==development==, where the software is designed and programmed.  
- Software ==validation==, where the software is checked to ensure that it is what the customer requires.  
- Software ==evolution==, where the software is modified to reflect changing customer and market requirements.

### 1.3. O que afeta o software

- Heterogeneity
	- systems are required to operate as distributed systems across networks that include different types of computer and mobile devices
- Business and social change
	- need to be able to change their existing software and to rapidly develop new software
- Security and trust
	- As software is intertwined with all aspects of our lives, it is essential that we can trust that software
- Scale
	- Software has to be developed across a very wide range of scales
	
### 1.4. Tipos de Aplicação

- Stand-alone applications
	- application systems that run on a local computer, include all necessary functionality and do not need to be connected to a network
- Interactive transaction-based applications
	- applications that execute on a remote computer and are accessed by users from their own PCs or terminals
- Embedded control systems
	- software control systems that control and manage hardware devices
- Batch processing systems
	- business systems that are designed to process data in large batches, process large numbers of individual inputs to create corresponding outputs
- Entertainment systems
	- systems that are primarily for personal use and which are intended to entertain the user
- Systems for modeling and simulation
	- systems that are developed by scientists and engineers to model physical processes or situations
- Data collection systems
	- systems that collect data from their environment using a set of sensors and send that data to other systems for processing
- Systems of systems
	- systems that are composed of a number of other software systems

## 2. Processos de Software

- Conjunto estruturado de atividades necessárias para desenvolver um sistema de software.
- Especificação
	- definição do que o sistema deve fazer;  
- Desenho e implementação
	- definição da organização do sistema e implementação do sistema; 
- Validação
	- verificar se faz o que o cliente deseja;  
- Evolução
	- mudar o sistema em resposta às mudanças nas necessidades dos clientes.

### 2.2. Descrição dos Processos

As descrições do processo também podem incluir:  
- Produtos, são os resultados de uma atividade de processo;  
- Funções, que refletem as responsabilidades das pessoas envolvidas no processo;  
- Pré e pós-condições, que são afirmações verdadeiras antes e depois de uma atividade de processo ter sido promulgada ou um produto produzido

### 2.3. Processos ágeis e orientados por planos

- Processos orientados a planos são processos em que todas as atividades do processo são planejadas com antecedência e o progresso é medido em relação a esse plano
- Nos processos ágeis, o planejamento é incremental e é mais fácil alterar o processo para refletir as mudanças nos requisitos do cliente

### 2.2. Modelos de processo de software

- Cascata
	- Orientado por plano. 
	- Fases separadas e distintas de especificação e desenvolvimento
- Desenvolvimento incremental
	- Especificação, desenvolvimento e validação são intercalados. Pode ser orientado por planos ou ágil
- Integração e configuração
	- O sistema é montado a partir de componentes configuráveis existentes. Pode ser orientado por planos ou ágil

#### 2.2.1. Modelo em Cascata

- Análise e definição de requisitos  
- Projeto de sistema e software  
- Implementação e testes unitários  
- Integração e teste de sistema  
- Operação e manutenção

- A principal desvantagem do modelo em cascata é a dificuldade de acomodar a mudança após o processo estar em andamento. Em princípio, uma fase deve ser concluída antes de passar para a próxima fase

- O modelo em cascata é usado principalmente para grandes projetos de engenharia de sistemas em que um sistema é desenvolvido em vários locais

#### 2.2.2. Modelo de Desenvolvimento Incremental

- O custo de acomodar as mudanças nos requisitos do cliente é reduzido
- É mais fácil obter feedback do cliente sobre o trabalho de desenvolvimento que foi feito
- É possível uma entrega e implantação mais rápidas de software útil para o cliente
- O processo não é visível
- A estrutura do sistema tende a se degradar à medida que novos incrementos são adicionados

#### 2.2.3. Modelo de Integração e Configuração

- Com base na reutilização de software em que os sistemas são integrados a partir de componentes existentes ou sistemas de aplicativos (às vezes chamados de sistemas COTS - Commercial-off-the-shelf)
- Os elementos reutilizados podem ser configurados para adaptar seu comportamento e funcionalidade aos requisitos do usuário
- A reutilização é agora a abordagem padrão para a construção de muitos tipos de sistema de negócios

### 2.3. Tipos de software reutilizável

- Sistemas de aplicativos autônomos (às vezes chamados de COTS) configurados para uso em um ambiente específico
- Coleções de objetos que são desenvolvidos como um pacote a ser integrado a uma estrutura de componente, como .NET ou J2EE
- Serviços da Web que são desenvolvidos de acordo com os padrões de serviço e que estão disponíveis para chamada remota
	- Um Web Service é uma função ou aplicação disponível na internet, que segue padrões (como HTTP, XML, JSON, SOAP ou REST) e pode ser chamada remotamente

## 3. Engenharia de Requisitos

- O processo de estabelecimento dos serviços que um cliente espera de um sistema e as restrições sob as quais ele opera e é desenvolvido.  
- Os requisitos do sistema são as descrições dos serviços e restrições do sistema que são gerados durante o processo de engenharia de requisitos.

### 3.1. O que é um requisito

- Pode variar de uma declaração abstrata de alto nível de um serviço ou de uma restrição do sistema a uma especificação funcional matemática detalhada

### 3.2. Tipos de requisitos

- Requisitos do usuário  
	- Declarações em linguagem natural, além de diagramas dos serviços que o sistema fornece e suas restrições operacionais. Escrito para clientes.
- Requisitos do sistema  
	- Um documento estruturado que estabelece descrições detalhadas das funções, serviços e restrições operacionais do sistema. Define o que deve ser implementado para que possa fazer parte de um contrato entre cliente e contratado

### 3.3. Stakeholders

- Qualquer pessoa ou organização que seja afetada pelo sistema de alguma forma e, portanto, que tenha um interesse legítimo

### 3.4. Requisitos funcionais e não funcionais

- Requisitos funcionais
	- Declarações de serviços que o sistema deve fornecer, como o sistema deve reagir a entradas específicas e como o sistema deve se comportar em situações específicas.  
	- Pode indicar o que o sistema deve e não deve fazer.
-  Requisitos não funcionais
	- Restrições nos serviços ou funções oferecidas pelo sistema, como restrições de tempo, restrições no processo de desenvolvimento, padrões, etc.
	- Geralmente se aplicam ao sistema como um todo, em vez de recursos ou serviços individuais.
-  Requisitos de domínio
	- Restrições no sistema do domínio de operação

---

## Projeto de Arquitetura

- O projeto arquitetônico está preocupado em entender como um sistema de software deve ser organizado e projetar a estrutura geral desse sistema.
- O projeto de arquitetura é o elo entre a fase de engenharia de requisitos e a de projeto (design), pois identifica os principais componentes estruturais de um sistema e as relações entre eles

### Padrões de Arquitetura

- Um padrão de arquitetura é uma descrição estilizada de boas práticas de design, que foi experimentada e testada em diferentes ambientes
#### MVC (Model-View-Controller)

- Separa a apresentação e a interações dos dados do sistema.
	- Model
		- onde ficam os dados e as regras de negócio
	- View
		- a interface com o usuário
	- Controller
		- recebe as ações do usuário coordena e decide quais dados mostrar na view.
- É utilizados quando há várias maneiras de visualizar e interagir com os dados.
- Separação de responsabilidades $\to$ manutenção e testes mais fáceis
#### Arquitetura em Camadas

- Organiza o sistema em camadas, com funcionalidades associada a cada uma.

#### Arquitetura de Repositorio
#### Arquitetura de Cliente/Servidor

#### Arquitetura Pipe & Filter

---



