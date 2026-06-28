# Arquitetura de Suporte Multithreading em Hardware

A Arquitetura de Suporte Multithreading (em hardware) estuda como o processador executa **múltiplos fluxos de instruções (threads)** com o objetivo de **aumentar a vazão** e melhorar o desempenho. Esse tema é se relaciona diretamente ao funcionamento de pipelines escalares e superescalares.

## 1. Classificação Geral do Suporte Multithreading

Classificam o multithreading em:

### Explícito

O hardware é planejado para manter o contexto de múltiplas threads.

### Implícito

Corresponde ao **Multithreading Especulativo**.

## 2. Multithreading Explícito

Divide-se em duas abordagens principais:

### 2.1 Multithreading Vertical

Inclui **Interleaved Multithreading (IMT)** e **Block Multithreading (BMT)**.  
Nessa abordagem, as threads avançam **uma de cada vez** no pipeline, e o processador alterna entre elas para ocultar latências.

#### a) **Interleaved Multithreading (IMT)**

- O processador alterna a execução entre threads **a cada ciclo de relógio**.
    
- Exemplos mencionados:
    
    - **UltraSparc-T1 (Niagara 1)**: 4 threads por núcleo, 32 ativas, 8 simultâneas.
        
    - **Niagara II**: 8 threads por núcleo, 64 ativas, 16 simultâneas.
        
- As instruções são executadas **em ordem**.

#### b) **Block Multithreading (BMT)**

- O processador executa uma thread até ocorrer um evento de alta latência (como um cache miss).
    
- Nesse momento, troca para outra thread.
    
- Possui a desvantagem de **esvaziar o pipeline (flushing)** ao alternar threads.
    

#### Observação sobre o desempenho do Vertical

- Tanto o IMT quanto o BMT introduzem **atrasos na execução** das threads, o que não ocorre no SMT.

### 2.2 Multithreading Horizontal

Representado pelo **Simultaneous Multithreading (SMT)**.

No Horizontal, múltiplas threads podem ter instruções executadas **no mesmo ciclo**, aproveitando o paralelismo do pipeline superescalar.

## 3. Simultaneous Multithreading (SMT)

O SMT é um mecanismo que opera **sobre um pipeline superescalar** e tem como objetivo transformar o desempenho baseado em **IPC (Instruções por Ciclo)** em **vazão de threads**.

### Benefícios do SMT

- **Aumento de vazão** de threads.
    
- **Ilusão de múltiplos núcleos**, pois várias threads avançam juntas em um único pipeline.
    
- **Evita esvaziamento de pipeline**, presente no BMT.
    
- **Não introduz atraso** na execução das threads, como ocorre no IMT e no BMT.

### Desafios do SMT

A implementação impõe complexidade à microarquitetura:

- Ampliação do **tamanho da arquitetura**.
    
- Necessidade de um **banco de registradores muito grande** para guardar o contexto das threads.
    
- Necessidade de **gerenciar a divisão de recursos** e evitar que **conflitos de cache** degradem o desempenho.

### Exemplo: IBM Power 5

- Suportava 2 threads simultâneas por núcleo.
    
- Não obteve melhoria significativa de desempenho.
    
- Motivos apresentados:
    
    - Poucas unidades de execução compartilhadas entre as threads.
        
    - Alto consumo da largura de banda de memória.
        
- Frequentemente funcionava com apenas uma thread ativa por núcleo.

## 4. Arquiteturas Híbridas

O **SMT pode ser combinado com IMT** em chips multi-core.
Motivações:

- Melhorar o desempenho em cargas de trabalho gerais.
    
- Reduzir a complexidade de arquiteturas superescalares puras.

## 5. CMT (Chip Multithreading)

No contexto de arquiteturas multi-core:

- Cada núcleo contém um **pipeline superescalar**.
    
- Cada núcleo executa múltiplas threads.
    
- Representa paralelismo em nível de thread maior do que o oferecido por um único pipeline superescalar com SMT.

A CMT aparece como múltiplos núcleos superescalares executando diferentes threads (por exemplo, A, B, C, D).

O UltraSparc-T1, embora não rotulado diretamente como CMT, segue esse modelo, pois tem vários núcleos e cada um utiliza IMT.

## Conclusão

O suporte a multithreading em hardware amplia significativamente a capacidade de um processador ao permitir que múltiplas threads compartilhem ou alternem o uso dos recursos do pipeline. Os mecanismos verticais (IMT e BMT) tratam threads como instruções alternadas no pipeline, enquanto o mecanismo horizontal (SMT) permite execução simultânea de instruções de várias threads em um pipeline superescalar. Além disso, arquiteturas multi-core que utilizam multithreading em cada núcleo (CMT) ampliam ainda mais o paralelismo.
