# Roteiro de Apresentação

## Slide 1 -- Capa

Olá a todos.

Hoje iremos apresentar o artigo _Narwhal and Tusk: A DAG-based Mempool and Efficient BFT Consensus_, publicado na conferência EuroSys em 2022.

Esse trabalho foi desenvolvido por pesquisadores da Mysten Labs e de instituições acadêmicas e aborda um tema extremamente relevante para a área de sistemas distribuídos e blockchain: como aumentar significativamente o desempenho de uma rede sem comprometer a segurança, a consistência dos dados e a tolerância a falhas.

Nos últimos anos, aplicações descentralizadas passaram a exigir cada vez mais capacidade de processamento. Entretanto, muitas arquiteturas tradicionais ainda enfrentam limitações importantes de escalabilidade. O artigo propõe uma abordagem inovadora para superar esses desafios, separando a disseminação das transações do mecanismo de consenso.

Durante a apresentação, vamos entender o contexto do problema, a solução proposta pelos autores, os principais componentes da arquitetura, os resultados obtidos experimentalmente e as conclusões do trabalho.

---

## Slide 2 -- Introdução

Para compreender a motivação do artigo, precisamos observar a evolução das blockchains e dos sistemas distribuídos modernos.

Originalmente, sistemas como Bitcoin foram projetados priorizando segurança e descentralização. No entanto, à medida que novas aplicações surgiram, como contratos inteligentes, finanças descentralizadas e aplicações Web3, tornou-se necessário processar um volume muito maior de transações.

O problema é que aumentar o desempenho não é simples. Quanto maior o número de participantes da rede, maior também é a quantidade de mensagens trocadas entre eles. Isso gera atrasos, consumo de banda e gargalos de comunicação.

Além disso, esses sistemas precisam continuar funcionando corretamente mesmo quando alguns participantes falham ou agem de forma maliciosa. Portanto, existe um equilíbrio delicado entre desempenho, segurança e tolerância a falhas.

É justamente nesse contexto que surge a proposta apresentada pelos autores.

---

## Slide 3 -- Contextualização

O trabalho está inserido no contexto dos protocolos Byzantine Fault Tolerant, conhecidos como protocolos BFT.

O termo 'Bizantino' faz referência ao chamado Problema dos Generais Bizantinos, que descreve a dificuldade de obter consenso entre participantes que podem transmitir informações incorretas ou agir de forma maliciosa.

Em sistemas distribuídos, protocolos BFT permitem que a rede continue funcionando corretamente mesmo quando parte dos nós apresenta falhas.

Diversos protocolos foram desenvolvidos para resolver esse problema, como PBFT, HotStuff e Tendermint.

Embora sejam seguros, muitos desses protocolos apresentam limitações quando o número de participantes aumenta. Em geral, eles dependem de um líder responsável por coordenar as decisões da rede.

Essa dependência cria gargalos que dificultam a escalabilidade e reduzem o desempenho em cenários reais.

---

## Slide 4 -- Problema Abordado

A principal observação feita pelos autores é bastante interessante.

Tradicionalmente, acredita-se que o consenso seja o maior gargalo das blockchains. No entanto, após analisar diversos protocolos modernos, os autores concluíram que o verdadeiro problema está na disseminação das transações.

Antes de serem confirmadas, as transações precisam ser compartilhadas entre todos os validadores da rede. Em muitos protocolos, essa troca de informações acontece diversas vezes, gerando redundância e desperdício de recursos.

Consequentemente, o sistema passa mais tempo distribuindo dados do que efetivamente realizando o consenso.

A proposta do artigo é separar completamente essas duas funções.

Enquanto uma camada especializada será responsável por disseminar as transações de maneira eficiente, o mecanismo de consenso ficará encarregado apenas de ordenar essas informações.

---

## Slide 5 -- Narwhal

A primeira contribuição do artigo é o Narwhal.

O Narwhal pode ser entendido como um mempool avançado. O mempool é a estrutura responsável por armazenar e distribuir transações antes que elas sejam confirmadas pela rede.

A principal inovação está no uso de uma estrutura chamada DAG, ou Grafo Acíclico Direcionado.

Enquanto uma blockchain tradicional organiza blocos em uma sequência linear, o DAG permite que vários blocos sejam criados e referenciados simultaneamente.

Cada bloco contém um conjunto de transações e referências para blocos produzidos anteriormente.

Isso cria uma estrutura capaz de registrar relações causais entre os eventos da rede e permite que diferentes participantes trabalhem em paralelo.

Como resultado, a disseminação de dados torna-se mais rápida e eficiente.

---

## Slide 6 -- Funcionamento

O funcionamento do Narwhal ocorre em rodadas, chamadas de rounds.

Durante cada rodada, os validadores recebem transações dos usuários, agrupam essas transações em blocos e compartilham esses blocos com os demais participantes.

Para garantir que os dados realmente estejam disponíveis para toda a rede, os blocos recebem certificados assinados por pelo menos dois terços dos validadores.

Matematicamente, essa condição é representada por 2f + 1 assinaturas, onde f representa o número máximo de participantes maliciosos que o sistema consegue tolerar.

Esses certificados fornecem uma garantia muito importante: qualquer bloco certificado continuará disponível futuramente e não poderá ser alterado sem ser detectado.

Dessa forma, o Narwhal garante integridade, disponibilidade e resistência a falhas bizantinas.

Outra característica relevante é que a disseminação das transações continua ocorrendo mesmo quando o consenso está temporariamente parado. Isso evita que a rede fique ociosa durante períodos de instabilidade.

---

## Slide 7 -- Escalabilidade

Além da eficiência do DAG, os autores propõem uma arquitetura chamada Primary-Worker.

Cada validador é dividido em dois tipos de componentes.

O primeiro é o Primary, responsável por coordenar informações de controle e participar do consenso.

O segundo são os Workers, responsáveis pelo processamento e compartilhamento das transações.

Essa divisão permite que tarefas pesadas relacionadas aos dados sejam executadas separadamente das tarefas de consenso.

Na prática, isso significa que é possível aumentar a capacidade do sistema simplesmente adicionando mais Workers.

Os experimentos mostram que o throughput cresce quase linearmente com o aumento do número de Workers, demonstrando excelente escalabilidade.

---

## Slide 8 -- Tusk

A segunda contribuição apresentada no artigo é o protocolo Tusk.

O Tusk utiliza toda a infraestrutura construída pelo Narwhal para realizar o consenso.

Diferentemente de muitos protocolos tradicionais, ele é totalmente assíncrono.

Isso significa que ele não depende de limites conhecidos para atrasos de comunicação na rede.

O protocolo utiliza um mecanismo chamado random coin compartilhado para introduzir aleatoriedade no processo de tomada de decisão.

Essa técnica ajuda os participantes a chegarem a um acordo mesmo em situações nas quais as mensagens sofrem atrasos imprevisíveis.

Outro aspecto importante é que o Tusk não exige troca adicional de mensagens além das já utilizadas pelo Narwhal.

Isso reduz significativamente a sobrecarga de comunicação e contribui para o elevado desempenho observado nos experimentos.

---

## Slide 9 -- Resultados

Para validar a proposta, os autores realizaram diversos experimentos em um ambiente distribuído na AWS, utilizando validadores localizados em diferentes regiões geográficas.

Os resultados foram bastante expressivos.

Como referência, o protocolo HotStuff tradicional alcançou aproximadamente 1.800 transações por segundo.

Quando combinado com o Narwhal, o throughput ultrapassou 130 mil transações por segundo, mantendo latência inferior a dois segundos.

O protocolo Tusk apresentou resultados ainda melhores, atingindo aproximadamente 160 mil transações por segundo.

Em cenários com múltiplos Workers por validador, o sistema chegou próximo de 600 mil transações por segundo.

Além disso, mesmo quando alguns participantes falhavam ou apresentavam comportamento adverso, o sistema continuava funcionando com desempenho elevado.

Esses resultados demonstram que a arquitetura proposta consegue combinar escalabilidade, eficiência e robustez.

---

## Slide 10 -- Conclusões

Como conclusão, os autores defendem que o principal gargalo das blockchains modernas não é o consenso em si, mas a disseminação eficiente das transações.

Ao separar essas duas responsabilidades, Narwhal e Tusk conseguem explorar melhor os recursos da rede e atingir níveis de desempenho muito superiores aos observados em protocolos tradicionais.

O Narwhal fornece uma infraestrutura altamente eficiente para distribuição de dados, enquanto o Tusk utiliza essa infraestrutura para realizar consenso assíncrono de forma escalável.

O impacto desse trabalho foi significativo tanto na pesquisa quanto na indústria. Diversas ideias apresentadas no artigo influenciaram diretamente blockchains modernas, como Aptos e Sui.

Portanto, a principal contribuição do artigo é demonstrar que repensar a arquitetura dos sistemas distribuídos pode gerar ganhos substanciais de throughput, escalabilidade e tolerância a falhas.

Muito obrigado pela atenção.

Agora estamos à disposição para responder perguntas.