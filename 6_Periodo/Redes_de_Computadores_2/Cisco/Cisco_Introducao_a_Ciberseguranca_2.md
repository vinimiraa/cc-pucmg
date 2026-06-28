# Introdução à Cibersegurança - 2.

## Tipos de Malware

Os criminosos digitais usam muitos tipos diferentes de software mal-intencionado, ou malware, para realizar suas atividades. Abreviação de “Malicious Software” (software mal-intencionado), o malware é qualquer código que pode ser usado para roubar dados, ignorar controles de acesso, causar danos  ou comprometer um sistema

### SPYWARE

Projetado para rastrear e espionar você, o spyware monitora sua atividade on-line e pode registrar todas as teclas que você pressiona no teclado, bem como capturar quase todos os dados, incluindo informações pessoais confidenciais, como detalhes bancários online. O spyware faz isso modificando as configurações de segurança dos dispositivos.

Muitas vezes, o spyware se junta ao software legítimo ou a cavalos de Troia.

### ADWARE

O adware é frequentemente instalado com algumas versões de software e é projetado para fornecer anúncios automaticamente a um usuário, na maioria das vezes em um navegador da Web. Você sabe quando vê! É difícil ignorar quando você se depara com anúncios pop-up constantes na tela.

É comum o adware vir com spyware.

### BACKDOOR

Esse tipo de malware é usado para obter acesso não autorizado, ignorando os procedimentos normais de autenticação para acessar um sistema. Como resultado, os hackers podem obter acesso remoto a recursos em uma aplicação e emitir comandos de sistema remoto.

Um backdoor funciona em segundo plano e é difícil de detectar.

### AMEAÇAS DE

Malware projetado para manter um sistema de computador, ou os dados incluídos nele, presos até que o pagamento seja feito. O ransomware geralmente funciona criptografando os dados para que você não possa acessá-los.

Algumas versões de ransomware podem tirar proveito de vulnerabilidades específicas do sistema para bloqueá-lo. O ransomware é frequentemente disseminado por e-mails de phishing que o incentivam a baixar um anexo mal-intencionado ou uma vulnerabilidade de software.

### SCAREWARE

Este é um tipo de malware que usa táticas de "medo" para induzi-lo a tomar uma ação específica. O Scareware consiste principalmente em janelas com estilo de sistema operacional que aparecem para alertar que seu sistema está em risco e precisa executar um programa específico para que ele retorne à operação normal.

Se você concordar em executar o programa específico, seu sistema será infectado por malware.

### ROOTKIT

Esse malware foi projetado para modificar o sistema operacional para criar um backdoor, que os invasores podem usar para acessar seu computador remotamente. A maioria dos rootkits utiliza as vulnerabilidades do software para escalonar privilégios e modificar arquivos de sistema.

Também é comum os rootkits modificarem a computação forense do sistema e as ferramentas de monitoramento, o que os torna muito difíceis de ser detectados. Na maioria dos casos, um computador infectado por um rootkit precisa ser apagado e qualquer software necessário reinstalado.

### VIRUS

Um vírus é um tipo de programa de computador que, quando executado, se replica e se anexa a outros arquivos executáveis, como um documento, ao inserir seu próprio código. A maioria dos vírus necessita de ativação do usuário final e pode ser ativada em uma hora ou data específica.

Os vírus podem ser relativamente inofensivos, como aqueles que exibem uma imagem divertida. Ou podem ser destrutivos, como os que modificam ou excluem dados.

Os vírus também podem ser programados para se modificar e evitar a detecção. Agora, a maioria dos vírus é espalhada por unidades de USB, discos ópticos, compartilhamentos de rede  ou e-mail.

### CAVALO DE TRÓIA

Esse malware realiza operações mal-intencionadas mascarando sua verdadeira intenção. Pode parecer legítimo, mas é, de fato, muito perigoso. Os cavalos de troia exploram os privilégios de usuário e são encontrados com mais frequência em arquivos de imagem, arquivos de áudio ou jogos.

Ao contrário dos vírus, os cavalos de troia não se replicam automaticamente, mas agem como um engodo para enganar o software mal-intencionado e passar por usuários desavisados.

### WORMS

Esse é um tipo de malware que se replica para se espalhar de um computador para outro. Ao contrário de um vírus, que requer um programa host para ser executado, os worms podem ser executados por si próprios. Além da infecção inicial do host, eles não exigem a participação do usuário e podem se espalhar rapidamente pela rede.

Os worms compartilham padrões semelhantes: eles exploram vulnerabilidades do sistema, têm uma maneira de se propagar e contêm código mal-intencionado (payload) para causar danos a redes ou sistemas de computador.

Os worms são responsáveis por alguns dos ataques mais devastadores na Internet. Em 19 horas, o worm infectou mais de 300.000 servidores em 2001.

---

## Engenharia social

Engenharia social – manipulação do indivíduo para executar ações ou divulgar informações confidenciais Os engenheiros sociais frequentemente dependem da boa vontade das pessoas para ajuda, mas também miram nos pontos fracos. Por exemplo, um invasor ligará para um funcionário autorizado com um problema urgente que exija acesso imediato à rede e apelará para a vaidade, ganância ou invocação de autoridade do funcionário usando técnicas de remoção  de nome para obter esse acesso.

- **Pretexting**
	Isso ocorre quando um invasor liga para um indivíduo e mente para ele na tentativa de obter acesso a dados privilegiados.
	Por exemplo, fingir que precisa dos dados pessoais ou financeiros de uma pessoa para confirmar sua identidade.
- **Tailgating**
	Isso ocorre quando um invasor segue rapidamente uma pessoa autorizada até um local físico seguro.
- **Algo por algo (Quid pro quo)**
	É quando um hacker solicita informações pessoais de uma pessoa em troca de algo, como um brinde gratuito.


## Negação de Serviço

Os ataques de negação de serviço (DoS) são um tipo de ataque de rede que é relativamente simples de realizar, mesmo por um invasor não qualificado. Um ataque de negação de serviço (DoS) resulta em algum tipo de interrupção de serviço aos usuários, dispositivos ou aplicações.

- Quantidade Esmagadora de Tráfego
	Quando uma rede, host ou aplicativo recebe uma enorme quantidade de dados a uma taxa que não consegue processar. Isso causa uma desaceleração na transmissão ou resposta ou uma falha em um dispositivo ou serviço.
- Pacotes Maliciosamente Formatados
	Um pacote é uma coleta de dados que flui entre uma fonte e um computador receptor ou aplicativo através de uma rede, como a Internet. Quando um pacote formatado de forma mal-intencionada é enviado, o receptor não será capaz de tratá-lo.
	Por exemplo, um invasor encaminha pacotes com erros que não podem ser identificados pelo aplicativo ou encaminha pacotes formatados incorretamente.

> Os ataques de negação de serviço (DoS) são considerados um grande risco porque podem facilmente interromper a comunicação e causar perda significativa de tempo e dinheiro.


## DoS Distribuída

Um ataque de negação de serviço distribuída (DDoS) é semelhante a um  ataque de negação de serviço (DoS), mas é proveniente de várias fontes coordenadas. Por exemplo:

- Um invasor cria uma rede (botnet) de hosts infectados chamados zumbis, que são controlados por sistemas de tratamento.
- Os computadores zumbis examinam e infectam constantemente mais hosts, criando mais zumbis.
- Quando está pronto, o hacker instrui os sistemas controlador para fazer com que o botnet de zumbis execute um ataque de negação de serviço distribuído (DDoS).


## Botnet

Um computador bot normalmente é infectado por visitar um site, abrir um anexo de e-mail ou abrir um arquivo de mídia infectado. Uma botnet é um grupo de robôs (bots), conectados pela Internet, com a capacidade de ser controlado por um indivíduo ou grupo mal-intencionado. Ela pode ter dezenas de milhares, ou até centenas de milhares, de bots que normalmente são controlados por meio de um servidor de comando e controle.

Esses robôs podem ser ativados para distribuir malware, lançar ataques de DDoS, distribuir e-mail de spam ou executar ataques de senha de força bruta. Os cibercriminosos freqüentemente alugam botnets para terceiros para fins nefastos.

Muitas empresas. como a Cisco, força as atividades de rede por meio de filtros de tráfego de botnet para identificar qualquer local de botnet.


## Ataques On-Path

Os invasores no caminho interceptam ou modificam as comunicações entre dois dispositivos, como um navegador e um servidor da Web, para coletar informações ou se passar por um dos dispositivos.

Esse tipo de ataque também é chamado de ataque **homem no meio** ou **homem no celular**.

- Man in the middle
	Um ataque de MitM acontece quando um criminoso digital assume o controle de um dispositivo sem o conhecimento do usuário. Com esse nível de acesso, o invasor pode interceptar e capturar informações do usuário antes de transmiti-las ao seu destino desejado. Esses tipos de ataques costumam ser usados para roubar informações financeiras.
- Man in the mobile
	Uma variação do man-in-middle, MitMo é um tipo de ataque usado para assumir o controle do dispositivo móvel de um usuário. Quando infectado, o dispositivo móvel é instruído a capturar informações confidenciais do usuário e enviá-las aos invasores. O ZeuS é um exemplo de pacote de malware com recursos MitMo. Ele permite que os invasores capturem silenciosamente as mensagens SMS de verificação de duas etapas enviadas aos usuários.


## SEO Poisoning

Você provavelmente já ouviu falar em otimização de mecanismos de pesquisa ou SEO, que, em termos simples, visa melhorar o site de uma empresa para que obtenha maior visibilidade nos resultados dos mecanismos de pesquisa.

Mecanismos de pesquisa como o Google funcionam apresentando uma lista de páginas da Web para usuários com base em suas consultas de pesquisa. Essas páginas da Web são classificadas de acordo com a relevância de seu conteúdo.

Embora muitas empresas legítimas se especializem em otimizar sites para melhor posicioná-los, os invasores tiram proveito de termos de pesquisa populares e usam o SEO para empurrar sites maliciosos para posições mais altas nos resultados de pesquisa. Esta técnica é chamada de envenenamento de SEO.

O objetivo mais comum do envenenamento de SEO é aumentar o tráfego para sites maliciosos que podem hospedar malware ou tentar engenharia social.


## Ataques de senha

Inserir um nome de usuário e senha é uma das formas mais populares de autenticação em um site. Portanto, descobrir a senha é uma maneira fácil para os criminosos digitais obterem acesso às informações mais importantes.

### PASSWORD SPRAING

Essa técnica tenta obter acesso a um sistema ao “pulverizar” algumas senhas usadas com frequência em um grande número de contas. Por exemplo, um criminoso digital usa 'Password123' com muitos nomes de usuário antes de tentar novamente com uma segunda senha comumente usada, como 'qwerty'.

Essa técnica permite que o criminoso não seja detectado ao evitar bloqueios de conta frequentes.

### ATAQUE DE DICIONARIO

Um hacker tenta sistematicamente cada palavra de um dicionário ou uma lista de palavras usadas com frequência como senha, na tentativa de invadir uma conta protegida por senha.

### ATAQUE DE FORCA BRUTA

A forma mais simples e mais usada de obter acesso a um site protegido por senha, os ataques de força bruta veem um invasor usando todas as combinações possíveis de letras, números e símbolos no espaço de senha até acertar.

### ATAQUE DE ARCO IRIS

As senhas em um sistema de computador não são armazenadas como texto sem formatação, mas como valores de hash (valores numéricos que identificam exclusivamente  os dados). Uma tabela do arco-íris é um grande dicionário de hashes pré-computados e as senhas das quais eles foram calculados.

Ao contrário de um ataque de força bruta que precisa calcular cada hash, um ataque do arco-íris compara o hash de uma senha com os armazenados na tabela do arco-íris. Quando um invasor encontra uma correspondência, ele identifica a senha usada para criar o hash.

### INTERCEPTACAO DE TRAFEGO

Texto sem formatação ou senhas sem criptografia podem ser facilmente lidas por outras pessoas e máquinas interceptando comunicações.

Se você armazenar uma senha em texto claro e legível, qualquer pessoa que tenha acesso à sua conta ou dispositivo, autorizado ou não autorizado, poderá lê-la.


## Ameaças persistentes avançadas

Advanced Persistent Threat (APT) – uma operação multi-fase, longo prazo, furtiva e avançada contra um alvo específico. Por essas razões, um invasor geralmente não tem o conjunto de habilidades, os recursos ou a persistência para realizar APTs.

Devido à complexidade e ao nível de habilidade necessários para realizar esse ataque, um APT geralmente é bem financiado e normalmente tem como alvo organizações ou nações por motivos comerciais ou políticos.

Seu principal objetivo é implantar malware personalizado em um ou mais sistemas do alvo e permanecer lá sem ser detectado.

---

## Vulnerabilidades de segurança

_Vulnerabilidades de segurança_ são qualquer tipo de defeito de software ou hardware. Um programa escrito para tirar proveito de uma vulnerabilidade de segurança conhecida é conhecido como _exploit_. Um criminoso digital pode usar uma exploração contra uma vulnerabilidade para realizar um _ataque_, cujo objetivo é obter acesso a um sistema, aos dados que hospeda ou a um recurso específico.

### Vulnerabilidades de Hardware

Vulnerabilidades de hardware são frequentemente introduzidas por falhas de projeto de hardware. Por exemplo, o tipo de memória chamado RAM  consiste basicamente em muitos capacitores (um componente que pode conter uma carga elétrica) instalados muito próximos um do outro. No entanto, logo foi descoberto que, devido à sua proximidade, as mudanças aplicadas a um desses capacitores poderiam influenciar os capacitores vizinhos. Com base nessa falha, foi criado um exploit chamado Rowhammer. Ao acessar (martelar) repetidamente uma linha de memória, a exploração do Rowhammer aciona interferências elétricas que eventualmente corrompem  os dados armazenados na RAM.

#### Meltdown e Spectre

Os pesquisadores de segurança do Google descobriram Meltdown e Spectre, duas vulnerabilidades de hardware que afetam quase todas as unidades de processamento central (CPUs) lançadas desde 1995 em desktops, laptops, servidores, smartphones,  dispositivos inteligentes e serviços em nuvem.

Os invasores que exploram essas vulnerabilidades podem ler toda a memória de um determinado sistema (Meltdown), bem como os dados manipulados por outras aplicações (Spectre). As explorações de vulnerabilidade Meltdown e Spectre são conhecidas como ataques de canal lateral (as informações são obtidas com a implementação de um sistema de computador). Eles têm a capacidade de comprometer grandes quantidades de dados de memória, porque os ataques podem ser executados várias vezes em um sistema com muito pouca possibilidade de uma falha ou outro erro.

As vulnerabilidades de hardware são específicas para modelos do dispositivo e geralmente não são exploradas por tentativas comprometedoras aleatórias. Embora as explorações de hardware sejam mais comuns em ataques altamente direcionados, a proteção contra malware tradicional e uma boa segurança física são proteção suficiente para o usuário comum.


### Vulnerabilidades de Software

As vulnerabilidades de software geralmente são introduzidas por erros no sistema operacional ou no código do aplicativo.

Categorizando as vulnerabilidades de software

A maioria das vulnerabilidades de segurança de software se enquadra em várias categorias principais.

#### ESTOURO DE BUFFER

Os buffers são áreas de memórias alocadas a um aplicativo. Uma vulnerabilidade ocorre quando os dados são gravados além dos limites de um buffer. Ao alterar os dados além dos limites de um buffer, o aplicativo pode acessar a memória alocada para outros processos. Isso pode levar a uma falha do sistema ou  comprometimento de dados ou fornecer escalonamento de privilégios.

#### ENTRADA NAO VALIDADA

Os programas geralmente exigem entrada de dados, mas esses dados recebidos podem ter conteúdo malicioso, projetado para forçar o programa a se comportar de maneira não intencional.

Por exemplo, considere um programa que recebe uma imagem para processamento. Um usuário mal-intencionado pode criar um arquivo de imagem com dimensões de imagem inválidas. As dimensões criadas de forma mal-intencionada podem forçar o programa a alocar buffers de tamanhos incorretos e inesperados.

#### CONDICAO DE CORRIDA

Esta vulnerabilidade descreve uma situação em que a saída de um evento depende de saídas ordenadas ou cronometradas. Uma condição de corrida se torna uma fonte de vulnerabilidade quando os eventos ordenados ou cronometrados necessários não ocorrem na ordem correta ou na sincronização apropriada.

#### FRAGILIDADE NA PRATICA DE SEGURANCA

Sistemas e dados confidenciais podem ser protegidos por meio de técnicas como autenticação, autorização e criptografia. Os desenvolvedores devem manter o uso de técnicas de segurança e bibliotecas que já foram criadas, testadas e verificadas e não devem tentar criar seus próprios algoritmos de segurança. É provável que elas introduzam novas vulnerabilidades.

#### PROBLEMAS DE CONTROLE DE ACESSO

O controle de acesso é o processo de controlar quem faz o quê e abrange desde o gerenciamento do acesso físico ao equipamento até ditar quem tem acesso a um recurso, como um arquivo, e o que pode ser feito com ele, como ler ou alterar o arquivo. Muitas vulnerabilidades de segurança são criadas com o uso indevido de controles de acesso.

Quase todos os controles de acesso e as práticas de segurança poderão ser superados se o invasor tiver acesso físico ao equipamento de destino. Por exemplo, não importa as configurações de permissão em um arquivo, um hacker pode ignorar o sistema operacional e ler os dados diretamente do disco. Para proteger a máquina e os dados que ela contém, o acesso físico deve ser restrito e as técnicas de criptografia devem ser usadas para proteger dados contra roubo ou danos.



### Atualizações de software

O objetivo das atualizações de software é sempre estar atualizado e evitar a exploração de vulnerabilidades. A Microsoft, Apple  e outros fabricantes de sistemas operacionais lançam patches e atualizações quase todos os dias, e aplicativos como navegadores da web, aplicativos móveis e servidores da web são frequentemente atualizados pelas empresas ou organizações responsáveis ​​por eles.

Apesar de as empresas se esforçarem muito para encontrar e corrigir vulnerabilidades de software, novas vulnerabilidades são descobertas regularmente. Enquanto algumas empresas têm equipes de testes de penetração dedicadas para pesquisar, localizar e corrigir vulnerabilidades de software, antes que elas possam ser exploradas, os pesquisadores de segurança de terceiros também são especializados em descobrir essas vulnerabilidades.

O Project Zero do Google é um grande exemplo de tal prática. Depois de descobrir uma série de vulnerabilidades em vários softwares usados por usuários finais, o Google formou uma equipe permanente dedicada a encontrar vulnerabilidades de software. Você pode descobrir mais sobre a pesquisa de segurança do Google [aqui](https://bugs.chromium.org/p/project-zero/issues/list?can=1&redir=1).

---

## Criptomoeda

A criptomoeda é o dinheiro digital que pode ser usado para comprar produtos e serviços, usando técnicas de criptografia fortes para proteger transações on-line. Bancos, governos  e até mesmo empresas como a Microsoft e a AT&T  estão muito cientes de sua importância e estão entrando na onda das criptomoedas!

Os proprietários de moedas criptografadas guardam seu dinheiro em “carteiras” virtuais e criptografadas. Quando uma transação ocorre entre os proprietários de duas carteiras digitais, os detalhes são registrados em um sistema de contabilidade descentralizado de contabilidade ou blockchain. Isso significa que é realizado com certo grau de anonimato e é autogerenciado, sem interferência de terceiros , como bancos centrais ou entidades governamentais.

Aproximadamente a cada dez minutos, computadores especiais coletam dados sobre as últimas transações de criptomoeda, transformando-os em quebra-cabeças matemáticos para manter a confidencialidade.

Essas transações são então verificadas através de um processo técnico e altamente complexo conhecido como “mineração”. Essa etapa normalmente envolve um exército de “mineradores” trabalhando em PCs avançados para resolver quebra-cabeças matemáticos e autenticar transações.

Uma vez verificado, o razão é atualizado e copiado e disseminado eletronicamente em todo o mundo para qualquer pessoa que pertence à rede blockchain, concluindo com eficiência uma transação.


## Cryptojacking

O cryptojacking é uma ameaça emergente que se esconde no computador, telefone celular, tablet, laptop ou servidor do usuário, usando os recursos dessa máquina para "extrair" moedas criptografadas sem o consentimento ou conhecimento do usuário .

Muitas vítimas de cryptojacking nem sabiam que tinham sido invadidas até que fosse tarde demais!