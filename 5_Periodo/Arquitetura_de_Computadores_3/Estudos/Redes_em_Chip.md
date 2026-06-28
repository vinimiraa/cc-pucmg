# Redes-em-Chip (NoC)

As arquiteturas manycore, que utilizam dezenas ou centenas de núcleos em um único chip, dependem de um mecanismo de interconexão escalável que substitua os barramentos e as chaves crossbar usados em sistemas menores. Essa necessidade levou ao surgimento da **Rede-em-Chip (NoC – Network-on-Chip)**.

## 1. Motivação: O Problema do Fio

Em arquiteturas com muitos núcleos, o uso de barramentos e chaves crossbar torna-se inviável. Uma crossbar de grande dimensão, como 99×99, não é escalável. O fator limitante é o **comprimento do fio**, que gera:

1. **Atenuação do sinal**: o fio longo causa perda de dados.
    
2. **Atraso temporal (td)**: o atraso é proporcional ao quadrado do comprimento do fio. Quanto maior o fio, maior a resistência e menor o desempenho.
    

A evolução das interconexões substituiu os fios longos por **fios curtos** e, em vez de repetidores e latches, passou a usar **roteadores** distribuídos. Assim surge a NoC.

## 2. Características Fundamentais da NoC

A NoC torna as arquiteturas manycore viáveis por substituir a interconexão global por uma estrutura de rede interna ao chip. Suas principais propriedades são:

### 2.1 Estrutura

- A NoC é composta por **roteadores**, cada um contendo:
    
    - um crossbar interno,
        
    - portas de entrada e saída (Norte, Sul, Leste, Oeste),
        
    - buffers,
        
    - e um árbitro (arbiter).
        
- A comunicação ocorre por **pacotes de rede**.
    
- Os **links são curtos**, eliminando os problemas físicos dos fios longos.

### 2.2 Escalabilidade e Desempenho

- A NoC é **escalável**: o desempenho não se degrada com o aumento de núcleos porque os fios são ponto-a-ponto entre roteadores.
    
- A largura de banda **não diminui** conforme a rede cresce.
    
- As decisões de roteamento são **distribuídas**, evitando gargalos de um árbitro único, como ocorre no barramento.
    
- A **latência** depende das contenções nos roteadores, não do comprimento do fio.

### 2.3 Robustez e Funcionalidades

- Suporte a **Qualidade de Serviço (QoS)**.
    
- **Tolerância a falhas**.
    
- Uso de **protocolos de roteamento**, responsáveis pela entrega e confiabilidade dos pacotes.
    
- Diversas **topologias** possíveis, como Estrela, Árvore, Mesh, Torus, Hipercubo, Pipeline e Anel.

## 3. Topologias em NoC

As topologias definem como os roteadores e núcleos são organizados no chip.

### Exemplos citados no texto:

- **Estrela**: nós ligados a um ponto central.
    
- **Árvore**: estrutura hierárquica.
    
- **Mesh (malha)**: cada roteador conecta-se aos seus vizinhos Norte, Sul, Leste e Oeste; topologia comum em pesquisas.
    
- **Torus**: similar à Mesh, mas com conexões circulares nas bordas.
    
- **Hipercubo**: oferece caminhos de interconexão adicionais.
    
- **Pipeline**: estrutura linear.
    
- **Anel (Ring)**: investigada em chips de pesquisa.

Cada topologia apresenta uma estratégia de transferência (direta ou indireta) e pode usar roteamento descentralizado ou centralizado, dependendo da organização.

## 4. Aplicações em Arquiteturas Manycore

A NoC é empregada em processadores manycore que exigem múltiplos caminhos de comunicação entre núcleos e memórias. O texto cita exemplos reais e de pesquisa:

- **Fujitsu ARM A64FX**: utiliza uma NoC em sua arquitetura.
    
- **Kalray MPPA 256**: os clusters são conectados por NoC.
    
- **Intel Teraflop Research Chip**: estudou topologias Ring e Mesh em um chip com 80 núcleos.
    

O texto também destaca que, apesar de possuírem muitos núcleos, **GPUs não são classificadas como arquiteturas que demandam uma NoC**.

## 5. Desafios de Projeto

Assim como redes tradicionais, a NoC precisa lidar com problemas como:

- **Deadlock**: dependência cíclica que impede o avanço dos pacotes.
    
- **Livelock**: pacotes são continuamente retransmitidos sem alcançar o destino.
    
- **Starvation**: um recurso nunca é alocado a um fluxo devido à postergação contínua, especialmente em mecanismos de arbitragem.

## Conclusão

A Rede-em-Chip é o mecanismo que possibilita o crescimento das arquiteturas manycore. Ela resolve os limites físicos das interconexões tradicionais ao substituir fios longos por roteadores e links curtos, oferecendo escalabilidade, largura de banda estável, controle distribuído e múltiplas topologias. Com isso, a NoC se torna o elemento central para manter comunicações internas eficientes em chips com dezenas ou centenas de núcleos.