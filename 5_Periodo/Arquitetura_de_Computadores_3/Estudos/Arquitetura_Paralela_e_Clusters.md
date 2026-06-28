# Arquiteturas Paralelas e Clusters

O estudo de Arquiteturas Paralelas e Clusters aborda como sistemas computacionais utilizam múltiplos processadores para aumentar desempenho e escalabilidade. O conteúdo se organiza em três eixos principais: classificação das arquiteturas, modelos de memória (compartilhada e distribuída) e métricas de desempenho.

## 1. Classificação das Arquiteturas Paralelas (Taxonomia de Flynn)

A Taxonomia de Flynn classifica arquiteturas paralelas segundo o número de fluxos de instruções (I) e de dados (D):

1. **SISD (Single Instruction, Single Data)**  
    Representa as máquinas von Neumann, que executam uma instrução sobre um único fluxo de dados.
    
2. **SIMD (Single Instruction, Multiple Data)**  
    Corresponde às máquinas Array. Uma mesma instrução é aplicada simultaneamente a vários dados. É onde ocorre o processamento vetorial, que opera sobre vetores, em contraste com processadores escalares.
    
3. **MISD (Multiple Instruction, Single Data)**  
    Não possui representantes conhecidos.
    
4. **MIMD (Multiple Instruction, Multiple Data)**  
    É a categoria mais ampla, reunindo multiprocessadores e multicomputadores. Divide-se em arquiteturas de memória compartilhada e memória distribuída.

## 2. Arquiteturas MIMD: Memória Compartilhada (Multiprocessadores)

Nesta abordagem, os processadores compartilham o mesmo espaço de endereçamento. A programação paralela utiliza variáveis compartilhadas e threads, com interfaces como **Pthreads** e **OpenMP**.

### 2.1 Modelos de Organização de Memória

- **UMA (Uniform Memory Access)**:  
    A memória é centralizada e o tempo de acesso é uniforme para todos os processadores.
    
- **NUMA (Non-Uniform Memory Access)**:  
    A memória é distribuída entre os processadores. NUMA melhora escalabilidade, reduz problemas de concorrência e diminui custos de acesso que existem em UMA.

### 2.2 Subtipos de NUMA

- **CC-NUMA**: coerência de cache garantida por hardware.
    
- **NCC-NUMA**: não possui coerência de cache garantida por hardware.
    
- **SC-NUMA**: coerência implementada por software.
    
- **COMA**: a memória principal funciona como uma grande cache.

### 2.3 Coerência de Cache

O uso de caches aumenta o desempenho, mas causa inconsistências quando um processador altera dados armazenados em outras caches. Para manter a coerência, utilizam-se mecanismos:

- **Snooping**: controladores de cache monitoram o barramento.
    
    - _Write-invalidate_: invalida cópias nas outras caches.
        
    - _Write-update_: atualiza as cópias nas outras caches.
        
- **Protocolos por diretório**: o diretório registra onde cada bloco está replicado e envia comandos de consistência apenas às caches envolvidas.
    
- **Protocolos de estados (MSI, MESI, MOESI)**:  
    Utilizam estados como Inválido (I), Compartilhado (S), Exclusivo (E), Modificado (M) e Owner (O).

### 2.4 Limitações

A memória compartilhada não possui escalabilidade total devido ao aumento de contenção e complexidade da coerência de cache conforme o número de nós cresce.

## 3. Arquiteturas MIMD: Memória Distribuída (Multicomputadores e Clusters)

Arquiteturas com memória privada utilizam múltiplos espaços de endereçamento, sendo classificadas como **NORMA**. São altamente escaláveis.

### 3.1 Clusters de Computadores

Um cluster é um conjunto de computadores autônomos conectados por redes de alto desempenho, operando como um único recurso.

**Características:**

- Escalabilidade absoluta e incremental.
    
- Alta disponibilidade.
    
- Bom custo-benefício.

**Comunicação:**  
Os nós se comunicam por **passagem de mensagens**, usando interfaces como **MPI** ou **PVM**.

**Aplicações:**  
Processamento paralelo, gerenciamento de bancos de dados e servidores web.

**Exemplos citados:**  
Atlas, Fênix e Santos Dumont (com Xeon e GPUs Nvidia Tesla V100/A100).  
Também podem existir clusters pequenos, como Raspberry Pi.

Clusters não enfrentam o problema de coerência de cache, mas dependem de comunicação via rede entre diferentes espaços de memória.

## 4. Métricas de Desempenho e Leis de Escalabilidade

O desempenho de sistemas paralelos é analisado principalmente por **Ganho (Speedup)** e **Eficiência**.

### 4.1 Ganho (Speedup)

$$S_p = \frac{T_1}{T_p}$$ 
Compara o tempo de execução serial com o tempo usando P processadores.

- O ganho é linear quando o sistema roda P vezes mais rápido com P processadores.
    
- Ganhos superlineares são possíveis, sendo o uso de cache uma explicação sugerida.

### 4.2 Eficiência

$$\text{Eficiência} = \frac{S_p}{P} = \frac{T_1}{P \cdot T_p}$$

Avalia o quanto os processadores estão sendo aproveitados.

### 4.3 Leis de Escalabilidade

- **Lei de Amdahl (Escalabilidade Forte)**  
    O tamanho do problema é fixo. O ganho é limitado pela fração não paralelizável do código.
    
- **Lei de Gustafson-Barsis (Escalabilidade Fraca)**  
    O tamanho do problema aumenta proporcionalmente ao número de processadores. Se a parte serial cresce lentamente ou permanece constante, o ganho aumenta com P.

### 4.4 Fatores que prejudicam desempenho

- Rede (em clusters).
    
- Desequilíbrio de carga entre nós.
    
- Regiões sequenciais na aplicação.

## Conclusão

Arquiteturas paralelas e clusters baseiam-se na Taxonomia de Flynn e dividem-se em modelos com memória compartilhada ou distribuída. Multiprocessadores facilitam a programação, mas enfrentam limitações de escalabilidade e coerência de cache. Clusters oferecem alta escalabilidade por meio de memória distribuída e comunicação por passagem de mensagens. O desempenho desses sistemas é analisado por métricas de speedup e eficiência, influenciadas pelas Leis de Amdahl e Gustafson-Barsis e por fatores como comunicação e carga de trabalho.