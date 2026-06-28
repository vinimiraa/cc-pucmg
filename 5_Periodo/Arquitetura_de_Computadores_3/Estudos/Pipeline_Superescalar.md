# Pipeline Superescalar de Instruções

O pipeline superescalar representa uma evolução do pipeline escalar tradicional. Enquanto o pipeline escalar divide a execução de uma instrução em vários estágios para permitir que **N instruções avancem simultaneamente**, o pipeline superescalar busca **aumentar o desempenho** executando **várias instruções por ciclo** usando **múltiplas unidades de execução**. Nesse modelo, é o hardware que identifica o paralelismo existente no fluxo de instruções.

## 1. Motivação e Limitações

O objetivo central da superescalaridade é aumentar o IPC (instruções por ciclo). Contudo, mesmo com mecanismos avançados, o IPC obtido na prática costuma ser apenas pouco maior que 2. Essa limitação ocorre porque os programas possuem um paralelismo intrínseco limitado, o que restringe quantas instruções independentes podem ser executadas simultaneamente.

## 2. Problemas Fundamentais da Execução Superescalar

Ao tentar executar várias instruções ao mesmo tempo, surgem desafios que o hardware precisa resolver:

### a) Conflitos de acesso a recursos

A memória é um exemplo típico de recurso compartilhado que pode ser acessado por instruções simultâneas.

### b) Dependências de dados

Existem três tipos citados no texto:

- **Dependências verdadeiras:** quando uma instrução depende do resultado produzido por outra.
    
- **Antidependências:** dependências falsas causadas pela reutilização de registradores (Write-After-Read).
    
- **Dependências de saída:** também falsas, ocorrem quando múltiplas instruções tentam escrever no mesmo registrador visível (Write-After-Write).

As dependências falsas só se tornam um problema em processadores superescalares.

### c) Dependências de controle

Originam-se de instruções de desvio, que impedem saber de imediato qual é a próxima instrução válida.

Para lidar com esses desafios, o processador superescalar precisa verificar continuamente se uma instrução pode ou não avançar, garantindo que a execução fora de ordem mantenha a correção dos resultados.

## 3. Execução Fora de Ordem (Out-of-Order)

Processadores superescalares possuem **capacidade de look-ahead**. Isso significa que, se a execução de uma instrução é impedida por um conflito, o processador examina instruções posteriores e seleciona as independentes para execução. Esse mecanismo permite a execução fora de ordem, desde que o resultado final do programa permaneça correto.

## 4. Despacho e Terminação

No pipeline superescalar, dois estágios são centrais:

- **Despacho:** envio de instruções para as unidades funcionais.
    
- **Terminação:** escrita dos resultados nos registradores.

Três formas de coordenar esses dois processos:

### 4.1 Despacho em ordem, terminação em ordem

- O despacho só ocorre quando todas as instruções previamente despachadas forem finalizadas.
    
- O despacho é congelado caso a unidade funcional esteja ocupada ou precise de múltiplos ciclos.
    
- Desempenho do exemplo: **IPC = 1.0**.

### 4.2 Despacho em ordem, terminação fora de ordem

- O despacho continua mesmo que a instrução anterior ainda esteja executando.
    
- O despacho ainda pode ser congelado por conflitos de recursos ou dependências verdadeiras.
    
- A terminação fora de ordem exige controle mais complexo, incluindo tratamento de interrupções e verificação correta das dependências.
    
- Desempenho do exemplo: **IPC = 1.2**.

### 4.3 Despacho fora de ordem, terminação fora de ordem

- O objetivo é evitar congelamentos de despacho causados por conflitos ou dependências.
    
- A decodificação é isolada da execução pela introdução de uma **janela de instruções**, que funciona como um buffer.
    
- As instruções dentro da janela podem ser enviadas às unidades funcionais independentemente da ordem em que foram buscadas.
    
- Isso permite que o estágio de decodificação opere continuamente.
    
- Desempenho do exemplo: **IPC = 1.5**.
    

Essa abordagem está associada ao uso de renomeação de registradores e aos métodos utilizados pelo Algoritmo de Tomasulo.

## 5. Mecanismos Avançados Necessários

Para que o pipeline superescalar funcione, são empregadas várias estruturas que permitem identificar dependências, eliminar dependências falsas e reorganizar a execução.

### 5.1 Janela de Instruções

É um buffer que armazena instruções pendentes de execução.  
Só são despachadas da janela quando seus operandos estão disponíveis.  
Quando algum operando ainda não está pronto, associa-se a ele um identificador (tag).

### 5.2 Estações de Reserva

Implementam uma janela de instruções distribuída.  
Cada unidade de execução possui sua própria estação de reserva, onde instruções aguardam a disponibilidade de operandos.  
Quando um valor é produzido, ele é propagado diretamente para as estações, substituindo as tags.

### 5.3 Renomeação de Registradores

Remove antidependências e dependências de saída.  
O processador utiliza um banco interno de registradores maior que o banco visível, permitindo renomear registradores temporariamente.  
Assim, instruções que escrevem no mesmo registrador visível podem ser executadas simultaneamente sem conflito.

### 5.4 Algoritmo de Tomasulo

Combina dois elementos centrais:

- Estações de reserva distribuídas.
    
- Renomeação de registradores.  

### 5.5 Buffer de Reordenamento (Reorder Buffer)

Organizado como FIFO.  
Para cada instrução que escreve em registrador, o buffer recebe uma posição no momento da decodificação.  
Quando o resultado fica pronto, ele é escrito no buffer e enviado simultaneamente para as estações de reserva.  
O buffer assegura que a escrita final no estado do programa ocorra **em ordem**, mesmo que a execução tenha ocorrido **fora de ordem**.

## 6. Integração com Outros Tópicos da Disciplina

A arquitetura superescalar serve como base para outras unidades, como as arquiteturas de suporte a multithreading, incluindo técnicas como SMT, que dependem da capacidade do hardware superescalar de explorar paralelismo.
