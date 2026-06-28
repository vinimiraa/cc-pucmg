# Arquiteturas Multicore, Manycore e Aceleradores Manycore

## 1. Origem das Arquiteturas Multicore

O surgimento dos processadores multicore é apresentado como uma resposta aos **limites físicos e arquiteturais** que impediram a continuidade da evolução dos processadores monocore. Dois limites são centrais:

### 1.1 Limite do Paralelismo de Instruções (ILP)

- Mesmo com processadores superescalares, o aumento de IPC (Instructions Per Cycle) tornou-se restrito.
    
- Na prática, o IPC dificilmente ultrapassava 2, pois os programas possuem paralelismo intrínseco limitado.
    
- Ganhos de ILP ficavam entre 10% e 30%.

### 1.2 Limite de Frequência (Power Wall)

- Devido ao fim do Dennard Scaling, tensões não podiam mais ser reduzidas proporcionalmente ao tamanho do transistor.
    
- Correntes de fuga e restrições térmicas impediram o aumento contínuo da frequência.
    
- A frequência ficou limitada a cerca de 4 GHz desde 2006, pois aumentos adicionais fariam o chip superaquecer.

## 2. Lei de Moore como Habilitadora

Embora não tenha relação com frequência, a Lei de Moore permitiu viabilizar o multicore porque:

- Aumentou a **capacidade de integração** de transistores.
    
- À medida que os transistores ficaram menores (ex.: 180 nm para 22 nm), tornou-se possível colocar **mais núcleos** no chip.

Diante da impossibilidade de explorar melhor o ILP e a frequência, o multicore surgiu como forma de explorar **Paralelismo em Nível de Thread (TLP)**, que podia gerar ganhos de 50% a 100%.

Arquiteturas como **Chip Multithreading (CMT)** refletem essa mudança ao combinar múltiplos núcleos superescalares.

## 3. Exemplos de Arquiteturas Multicore e Multithreading

Apresentam vários processadores que ilustram a adoção de TLP em diferentes gerações:

### 3.1 UltraSparc-T1 (Niagara 1) e Niagara II

- UltraSparc-T1:
    
    - 4 threads IMT por núcleo (32 threads ativas, 8 simultâneas).
        
    - Crossbar de 134,4 GB/s.
        
    - 4 canais DDR (23 GB/s).
        
    - Potência abaixo de 80 W.
        
- Niagara II:
    
    - 8 threads por núcleo (64 ativas, 16 simultâneas).
        
    - Execução em ordem.
        
    - Crossbar de 268,8 GB/s.

### 3.2 IBM Power 5

- Suporte a SMT com duas threads simultâneas por núcleo.
    
- Dois núcleos físicos, quatro lógicos.
    
- Ganhos limitados devido ao pouco compartilhamento de unidades de execução e alto uso de largura de banda de memória.

### 3.3 Intel Dual Core (Pentium D e Core Duo)

- Dois núcleos físicos.
    
- Sem SMT.

### 3.4 Intel Quad Core

- Formado pela integração de dois dual core.
    
- L2 compartilhado, sem SMT.

### 3.5 AMD Opteron (Quad Core Shanghai, Six Core Istanbul/Sao Paolo)

- Projetos multicore com HyperTransport e uso de caches L3 significativas.
### 3.6 Intel Core Ultra 9 285K

- Exemplo recente com 24 núcleos  
    (8 Performance-cores e 16 Efficient-cores).
    
- Total de 24 threads.

## 4. Arquiteturas Manycore

A arquitetura manycore representa a ampliação do conceito multicore, com **dezenas a centenas de núcleos** no mesmo chip.  
É tratada como unidade específica da disciplina, frequentemente associada a Redes-em-Chip (NoC).

### Características Gerais

1. **Número muito alto de núcleos**  
    Exemplos citados:
    
    - Epiphany-V: 1024 núcleos RISC e 64 MB de SRAM on-chip.
        
    - Intel Xeon Phi:
        
        - Knights Corner: 61 núcleos.
            
        - Knights Landing: 72 núcleos.
            
    - Fujitsu A64FX (Fugaku): manycore com NoC; o sistema completo alcança 7.299.072 núcleos.
        
    - Intel Teraflop Research Chip: 80 núcleos.
        
2. **Foco em paralelismo massivo**  
    Destina-se a aplicações paralelas com muitas comunicações.
    
3. **Uso de Rede-em-Chip (NoC)**  
    Necessária devido à inviabilidade de barramentos e crossbars com dezenas de núcleos.  
    Motivos:
    
    - Fios longos criam atenuação de sinal.
        
    - O atraso cresce com o quadrado do comprimento do fio.
        
    - Crossbars grandes não escalam (uma 9x9 já é complexa; uma 99x99 é impraticável).  
        A NoC resolve esses problemas com roteadores e comunicação por pacotes.

### Distinção entre Manycore e GPU

- GPUs têm milhares de núcleos (ex.: Titan V com 5120 núcleos), mas não implementam NoC como as arquiteturas manycore descritas.
    
- Por isso, são tratadas separadamente.

### Exemplos de NoC em Manycore

- Kalray MPPA 256.
    
- Fujitsu ARM A64FX.
    
- Manycore Research Chip da Intel (topologias mesh e ring).

## 5. Aceleradores Manycore

Apresentam os aceleradores Intel MIC e GPUs como exemplos:

### 5.1 Intel Xeon Phi (MIC)

- Knights Corner: 61 núcleos.
    
- Knights Landing: 72 núcleos.
    
- Projetados explicitamente como aceleradores manycore.

### 5.2 GPUs (NVIDIA)

Contagens citadas:

- GTX Titan (2017): 3840 núcleos.
    
- Titan V (2019): 5120 núcleos.

Apesar dos muitos núcleos, **não se enquadram como manycore com NoC**, sendo aceleradores focados em paralelismo de dados.

### 5.3 Outros Aceleradores

- NPUs, como o **Intel Gaussian & Neural Accelerator (GNA)**, para cargas de trabalho de IA em áudio e fala com baixo consumo.

## Conclusão

A passagem de monocore para multicore ocorreu porque:

- Não era possível aumentar ILP e frequência além de limites físicos.
    
- A Lei de Moore permitiu integrar vários núcleos no chip.
    
- O foco mudou do ILP para o TLP, com ganhos superiores.
    

O manycore representa a evolução natural desse caminho, exigindo NoCs para suportar dezenas a centenas de núcleos.  
Por fim, os aceleradores manycore e GPUs ilustram como o aumento de núcleos também se tornou fundamento em arquiteturas especializadas para processamento paralelo.
