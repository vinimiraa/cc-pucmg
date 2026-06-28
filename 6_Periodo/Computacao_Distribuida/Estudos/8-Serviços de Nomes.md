# **Serviços de Nomes em Sistemas Distribuídos**

Um serviço de nomes é um componente fundamental de qualquer sistema distribuído, atuando como um banco de dados distribuído cuja principal função é gerenciar o mapeamento entre **nomes** legíveis por humanos e os **atributos** dos recursos que eles representam. Esses recursos podem ser diversos, como hosts, impressoras, serviços, portas e outros objetos de software ou hardware. A operação central de um serviço de nomes é a **resolução de nomes**, que é o processo de consultar os atributos associados a um determinado nome. Outras operações essenciais incluem inserir novos nomes, remover nomes e listar os nomes existentes.

Existem dois tipos fundamentais de nomes: os **nomes textuais** (strings projetadas para leitura e memorização humana) e os **identificadores de sistema** (sequências de bits usadas pelo sistema por questões de eficiência). O vínculo entre um nome e o recurso que ele denota é chamado de **binding**.

## **Abordagens para Resolução de Nomes**

### **Nomeação Simpla: Broadcasting**

O _broadcasting_ é uma abordagem simples em que uma mensagem contendo o identificador do destinatário é enviada para todas as entidades da rede. Apenas a entidade que possui aquele identificador responde. Um protocolo clássico que usa essa abordagem é o **ARP (Address Resolution Protocol)**, usado para mapear endereços IP para endereços MAC em redes locais (LANs). A principal limitação do _broadcasting_ é a sua **falta de escalabilidade**. À medida que a rede cresce, o tráfego gerado torna-se excessivo e ineficiente, tornando-o inviável para redes extensas como a Internet. Além disso, ele requer que todas as entidades estejam sempre preparadas para responder a consultas.

### **Nomeação Simpla: Localização Nativa (Home Agent)**

Esta abordagem, inspirada no modelo de mobilidade do IP, introduz um agente fixo e conhecido, chamado de **agente nativo** (_home agent_). Toda comunicação é inicialmente direcionada para este agente, que é responsável por saber a localização atual do recurso móvel e encaminhar as requisições para seu endereço atual. O agente também informa ao requisitante a localização atual, permitindo que comunicações subsequentes ocorram diretamente. Este modelo é muito mais escalável que o _broadcasting_ e é a base de protocolos como o Mobile IP.

## **Nomeação Estruturada: O Domain Name System (DNS)**

O **DNS** é o serviço de nomes hierárquico e distribuído que é a espinha dorsal da Internet. Ele foi criado para superar as limitações do arquivo de hosts centralizado (/etc/hosts), que apresentava problemas críticos de escalabilidade, administração e exigia nomes de máquinas globalmente únicos.

### **Estrutura e Espaço de Nomes**

O DNS organiza seu espaço de nomes em uma **estrutura hierárquica em forma de árvore**, permitindo a descentralização da administração.

- **Domínio Raiz (Root-level domain)**: Representado por um ponto final (.). É gerenciado por 13 grupos de servidores raiz (de a.root-servers.net a m.root-servers.net).
- **Domínios de Primeiro Nível (Top-level domains - TLDs)**: São os domínios imediatamente abaixo da raiz. Incluem:

- **gTLDs (generic TLDs)**: .com, .org, .net, .edu, .gov, etc.
- **ccTLDs (country-code TLDs)**: .br, .uk, .fr, etc., representando países ou regiões.

- **Domínios de Segundo Nível (Second-level domains)**: São domínios registrados por organizações ou indivíduos sob um TLD (p.ex., pucminas.br, google.com). Esses domínios podem, por sua vez, ser divididos em **subdomínios** (p.ex., sd.pucminas.br).

### **Funcionamento e Tipos de Consulta**

O princípio de funcionamento do DNS baseia-se no conhecimento parcial. Cada servidor de nomes é **autoritativo** para uma ou mais zonas (partes contíguas do espaço de nomes) e conhece os endereços dos servidores responsáveis pelas zonas filhas (delegadas) e pelos servidores raiz.

- **Consulta Recursiva**: O cliente (ou _resolver_) envia a consulta a um servidor e espera que este retorne a resposta final (o endereço IP) ou uma mensagem de erro. O servidor assume a tarefa de consultar outros servidores em nome do cliente até encontrar a resposta.
- **Consulta Iterativa**: O servidor, se não tiver a resposta, retorna ao cliente a "melhor resposta possível", que geralmente é o endereço de um servidor mais próximo da zona autoritativa do nome desejado. Cabe então ao cliente consultar esse novo servidor. Os servidores raiz e TLD normalmente só realizam consultas iterativas.

Para melhorar a eficiência e reduzir o tráfego, os servidores DNS utilizam **cache** extensivamente. As respostas obtidas de cache são marcadas como **"não autoritativas"** (_non-authoritative_). Cada entrada no cache possui um **TTL (Time-to-Live)**, determinado pela zona autoritativa, que define por quanto tempo a entrada pode ser reaproveitada antes de precisar ser atualizada.

### **Tipos de Servidores e Registros**

- **Servidor Primário (Master)**: Mantém os arquivos de zona originais e definitivos para um domínio. As alterações são feitas neste servidor.
- **Servidor Secundário (Slave)**: Obtém uma cópia dos arquivos de zona de um servidor primário (ou de outro secundário) através de uma **transferência de zona** (_zone transfer_). Fornece redundância, balanceamento de carga e reduz a latência para clientes em locais remotos.
- **Servidor de Cache (Resolver ou Recursive Resolver)**: Não é autoritativo para nenhum domínio. Sua função é realizar consultas recursivas em nome dos clientes e armazenar as respostas em cache. ISPs e empresas geralmente operam esses servidores para seus usuários.

O banco de dados DNS é composto por vários tipos de **registros de recursos (RR)**. Os principais são:

- **SOA (Start of Authority)**: Marca o início de uma zona e contém parâmetros administrativos, como o e-mail do administrador e tempos de atualização.
- **NS (Name Server)**: Identifica um servidor de nomes autoritativo para a zona.
- **A (Address)**: Mapeia um nome de host para um endereço IPv4.
- **AAAA**: Mapeia um nome de host para um endereço IPv6.
- **PTR (Pointer)**: Usado para _resolução reversa_, mapeando um endereço IP para um nome de host.
- **MX (Mail Exchanger)**: Especifica os servidores de e-mail (mail exchangers) para um domínio, definindo a prioridade de cada um.
- **CNAME (Canonical Name)**: Define um apelido (alias) para um nome de host canônico.

### **Funcionalidades Avançadas**

Conforme detalhado no livro de Coulouris, o DNS vai além do simples mapeamento nome-IP:

- **Resolução Reversa**: Mapeamento de endereços IP para nomes, crucial para ferramentas de diagnóstico como traceroute e para sistemas de autenticação e logging.
- **Balanceamento de Carga**: Atribuindo múltiplos registros A para o mesmo nome, o DNS pode distribuir requisições entre vários servidores.
- **Redirecionamento de Serviços**: Usando registros CNAME e MX, é possível redirecionar tráfego para diferentes serviços ou provedores de forma transparente para o usuário final.

## **O Windows Internet Name Service (WINS)**

O **WINS** é um serviço de nomes da Microsoft projetado para resolver **nomes NetBIOS** em redes IP. O NetBIOS é uma interface de programação de aplicações (API) mais antiga, da camada de sessão, usada por serviços de rede Microsoft tradicionais, como compartilhamento de arquivos e impressoras.

### **Diferenças Fundamentais entre WINS e DNS**

- **Namespace**: A diferença mais crítica é a estrutura do namespace. Enquanto o DNS é **hierárquico**, os nomes NetBIOS (geridos pelo WINS) são **planos** (_flat_), sem uma estrutura de domínios ou subdomínios. Isso limita severamente a escalabilidade do WINS.
- **Atualização**: No WINS, a atualização do banco de dados é **dinâmica e automática**. Os próprios clientes registram seus nomes e endereços IP no servidor WINS durante a inicialização (através de uma mensagem Name Registration), renovam-nos periodicamente (Name Renewal) e os liberam durante o desligamento (Name Release). No DNS tradicional, as atualizações eram majoritariamente estáticas e manuais, embora mecanismos dinâmicos como o **DNS Dinâmico (DDNS)** tenham sido padronizados posteriormente (RFC 2136) para fechar essa lacuna.
- **Arquitetura**: O WINS foi concebido como um serviço mais **centralizado** (embora possa ter replicação entre servidores), enquanto o DNS é inerentemente **distribuído** e descentralizado por design.

O WINS foi extremamente importante em redes Windows baseadas em NT4/2000/XP, mas seu uso diminuiu significativamente com a adoção do Active Directory, que é fortemente baseado no DNS padrão da Internet para todas as suas operações de localização de serviços.