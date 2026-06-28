# Programação Paralela -- Conceitos e Fundamentos

A programação paralela consiste em executar várias partes de um problema simultaneamente, utilizando múltiplos recursos computacionais, como núcleos de CPU, GPUs ou até diferentes máquinas conectadas em rede. Seu principal objetivo é reduzir o tempo de execução e permitir a resolução de problemas cada vez maiores e mais complexos.

Diferentemente da programação sequencial, em que uma instrução é executada após a outra, a programação paralela explora a existência de operações independentes, permitindo que elas sejam executadas ao mesmo tempo. Entretanto, isso também introduz desafios relacionados à sincronização, comunicação entre processos e compartilhamento de recursos.

# Padrões de Programação Paralela

Os padrões de programação paralela são estratégias reutilizáveis que descrevem maneiras comuns de organizar a execução concorrente de um algoritmo. Eles representam soluções genéricas para problemas recorrentes em computação paralela, facilitando o desenvolvimento e tornando os programas mais escaláveis e eficientes.

## Padrão Map

O padrão **Map** é um dos mais simples e mais utilizados em programação paralela. Sua ideia central é aplicar a mesma operação sobre um conjunto de elementos de forma independente.

Suponha, por exemplo, um vetor contendo milhares de números. Se desejarmos elevar todos os elementos ao quadrado, cada elemento poderá ser processado separadamente, sem necessidade de interação com os demais.

Matematicamente:

```
Entrada:  [1,2,3,4]
Operação: x²
Saída:    [1,4,9,16]
```

Como cada elemento é independente, diferentes threads ou processadores podem trabalhar simultaneamente sobre diferentes partes dos dados.

Esse padrão é muito utilizado em:

- Processamento de imagens;
- Machine Learning;
- Computação científica;
- Big Data;
- Operações matriciais.

Uma das principais vantagens do padrão Map é a ausência de dependência entre os elementos, o que o torna altamente paralelizável.

---

## Padrão Reduce

Enquanto o Map produz vários resultados independentes, o padrão **Reduce** possui a função oposta: combinar diversos resultados em um único valor.

Considere um vetor:

```
[2,4,6,8]
```

Desejamos obter a soma dos elementos:

```
2 + 4 + 6 + 8 = 20
```

Na abordagem sequencial, essa soma é realizada elemento por elemento. Em uma implementação paralela, diferentes threads podem calcular somas parciais:

```
Thread 1: 2 + 4 = 6

Thread 2: 6 + 8 = 14
```

Posteriormente:

```
6 + 14 = 20
```

Essa organização em forma de árvore reduz significativamente o tempo de processamento.

As operações mais comuns em Reduce são:

- Soma;
- Produto;
- Máximo;
- Mínimo;
- Média;
- Operações lógicas.

---

## Padrão Pipeline

O padrão Pipeline organiza o processamento em estágios sucessivos, semelhantes a uma linha de produção industrial.

Considere um sistema de processamento de imagens:

1. Leitura da imagem;
2. Aplicação de filtros;
3. Compressão;
4. Armazenamento.

Cada estágio pode trabalhar simultaneamente em diferentes imagens. Enquanto uma imagem está sendo filtrada, outra pode estar sendo lida e uma terceira pode estar sendo gravada.

Esse padrão aumenta a utilização dos recursos computacionais e é amplamente empregado em:

- Processadores modernos;
- Streaming de vídeo;
- Sistemas embarcados;
- Processamento em tempo real.

---

## Padrão Divide and Conquer

O padrão Divide and Conquer (Dividir para Conquistar) consiste em decompor um problema em subproblemas menores, resolvê-los independentemente e, posteriormente, combinar os resultados.

Um exemplo clássico é o Merge Sort.

Inicialmente, o vetor é dividido:

```
[8 4 7 2 6 1]
```

Depois:

```
[8 4 7]     [2 6 1]
```

Cada parte pode ser ordenada em paralelo e, ao final, os resultados são combinados.

Esse padrão é muito utilizado em:

- Merge Sort;
- Quick Sort;
- Multiplicação de matrizes;
- Busca em árvores.

---

## Padrão Fork-Join

No modelo Fork-Join existe inicialmente apenas uma thread principal. Em determinado momento, ela cria várias threads de execução (fork), distribui as tarefas e, ao final, espera que todas terminem (join).

```
Main
│
├── Thread 1
├── Thread 2
├── Thread 3
└── Thread 4
```

Após a conclusão:

```
Join --> Main
```

Esse modelo é a base do OpenMP.


# Introdução ao OpenMP

OpenMP (Open Multi-Processing) é uma API para programação paralela em arquiteturas de memória compartilhada. Ela oferece um conjunto de diretivas, bibliotecas e variáveis de ambiente que permitem adicionar paralelismo em programas escritos em C, C++ e Fortran.

Seu principal objetivo é simplificar a programação paralela em máquinas multicore.

Ao invés de criar threads manualmente, basta inserir diretivas no código.

Por exemplo:

```c
#pragma omp parallel
```

faz com que o programa crie automaticamente um conjunto de threads.

## Modelo Fork-Join

O OpenMP utiliza o modelo Fork-Join.

Inicialmente existe apenas uma thread:

```
Master Thread
```

Ao encontrar uma região paralela:

```c
#pragma omp parallel
```

ocorre o fork:

```
Master

├── Thread 1
├── Thread 2
├── Thread 3
└── Thread 4
```

Quando a região paralela termina, ocorre o join:

```
Master
```

---

## Paralelização de Laços

Grande parte do ganho de desempenho em OpenMP é obtido pela paralelização de loops.

Código sequencial:

```c
for(int i = 0; i < n; i++) {
    c[i] = a[i] + b[i];
}
```

Versão paralela:

```c
#pragma omp parallel for
for(int i = 0; i < n; i++) {
    c[i] = a[i] + b[i];
}
```

Cada thread executa uma parte das iterações.

Se existirem 4 threads e 1000 elementos, cada thread poderá processar aproximadamente 250 elementos.


# Arquiteturas Paralelas

A classificação mais conhecida das arquiteturas paralelas foi proposta por Flynn.

## SISD

Single Instruction Single Data.

Corresponde aos computadores tradicionais, onde uma única instrução atua sobre um único conjunto de dados.

A execução é totalmente sequencial.

---

## SIMD

Single Instruction Multiple Data.

Uma mesma instrução é aplicada simultaneamente sobre vários dados.

Por exemplo:

```
A = [1 2 3 4] +
B = [5 6 7 8]
```

Uma única instrução pode realizar:

```
[6 8 10 12]
```

Esse modelo é utilizado em:

- AVX;
- SSE;
- GPUs;
- Processamento vetorial.

---

## MIMD

Multiple Instruction Multiple Data.

Cada processador executa instruções diferentes sobre conjuntos distintos de dados.

É o modelo predominante em sistemas multicore e supercomputadores.

Exemplos:

- CPUs multicore;
- Clusters;
- Sistemas distribuídos.

---

## Arquiteturas de Memória Compartilhada

Em arquiteturas de memória compartilhada, todos os processadores acessam a mesma memória principal.

```
CPU1
CPU2
CPU3
 ↓
 RAM
```

As vantagens são:

- Programação mais simples;
- Comunicação implícita;
- Menor complexidade.

As desvantagens incluem:

- Concorrência sobre a memória;
- Limitação na escalabilidade.

OpenMP trabalha nesse modelo.

---

## Arquiteturas de Memória Distribuída

Cada processador possui sua própria memória.

```
CPU1 ↔ CPU2 ↔ CPU3

RAM1   RAM2   RAM3
```

Os processadores se comunicam por troca de mensagens.

Esse modelo apresenta grande capacidade de expansão e é utilizado em supercomputadores e clusters.

MPI é baseado nesse tipo de arquitetura.

# Shared, Private, Critical, Atomic e Reduction

Em OpenMP, as variáveis podem possuir diferentes formas de compartilhamento.

## Shared

Uma variável shared é compartilhada entre todas as threads.

Todas acessam exatamente a mesma posição de memória.

Isso pode gerar condições de corrida (race conditions), quando duas threads tentam modificar simultaneamente o mesmo valor.

---

## Private

Uma variável private possui uma cópia exclusiva para cada thread.

As alterações realizadas por uma thread não interferem nas demais.

Esse mecanismo é importante para variáveis temporárias e contadores locais.

---

## Critical

A diretiva critical cria uma região crítica, permitindo que apenas uma thread execute determinado trecho de código por vez.

Isso elimina condições de corrida, mas reduz o paralelismo.

---

## Atomic

Atomic é semelhante ao critical, porém protege apenas uma única operação de leitura e escrita.

Por possuir menor overhead, é geralmente mais eficiente que critical.

---

## Reduction

Reduction é utilizado quando várias threads produzem resultados parciais que precisam ser combinados.

Cada thread possui uma variável local:

```
soma1
soma2
soma3
soma4
```

Ao final:

```
soma = soma1+soma2+soma3+soma4
```

Essa abordagem evita conflitos de acesso e melhora o desempenho.


# Avaliação de Desempenho de Aplicações Paralelas

Avaliar desempenho é fundamental para verificar se a paralelização realmente trouxe benefícios.

## Speedup

O speedup mede quantas vezes a execução paralela é mais rápida do que a sequencial.

Definido por:

```
Speedup = Tserial / Tparalelo
```

Se:

- Serial = 20 s
- Paralelo = 5 s

Então:

```
Speedup = 4
```

Significa que o programa ficou quatro vezes mais rápido.

---

## Eficiência

A eficiência mede o aproveitamento dos processadores.

```
Eficiência = Speedup / Número de Processadores
```

Se utilizarmos oito processadores e obtivermos speedup igual a quatro:

```
Eficiência = 4/8 = 50%
```

Isso indica que metade do potencial computacional está sendo aproveitada.

---

## Escalabilidade

Escalabilidade representa a capacidade do sistema de continuar apresentando ganhos à medida que mais processadores são adicionados.

Idealmente:

```
2 CPUs --> Speedup 2

4 CPUs --> Speedup 4

8 CPUs --> Speedup 8
```

Entretanto, limitações de comunicação e sincronização impedem que isso ocorra perfeitamente.

---

## Lei de Amdahl

A Lei de Amdahl estabelece que o ganho máximo de desempenho é limitado pela parcela sequencial do programa.

Mesmo com infinitos processadores, uma parte não paralelizável continuará sendo executada em série.

Consequentemente, existe um limite teórico para o speedup.

---

## Lei de Gustafson

A Lei de Gustafson considera que, ao aumentar a quantidade de processadores, também é possível aumentar o tamanho do problema.

Essa visão é mais adequada para supercomputadores e aplicações científicas.


# Paralelismo de Tarefas

No paralelismo de tarefas, diferentes atividades são executadas simultaneamente.

Exemplo:

- Uma thread lê arquivos;
- Outra realiza processamento;
- Outra envia informações pela rede.

As tarefas são diferentes entre si.

Isso difere do paralelismo de dados, no qual várias threads executam exatamente a mesma operação sobre diferentes conjuntos de dados.


# Algoritmos Paralelos

Um algoritmo paralelo é aquele projetado para explorar simultaneamente múltiplos processadores.

Exemplos clássicos:

- Soma de vetores;
- Busca paralela;
- Merge Sort paralelo;
- Multiplicação de matrizes;
- Algoritmos de ordenação;
- FFT (Fast Fourier Transform).

O objetivo principal é diminuir a complexidade temporal efetiva através da divisão do trabalho.


# Vetorização

Vetorização consiste em executar uma mesma instrução sobre vários dados ao mesmo tempo.

Ela explora o modelo SIMD.

Em vez de realizar:

```
1+5
2+6
3+7
4+8
```

individualmente, o processador executa uma única instrução vetorial capaz de produzir:

```
6 8 10 12
```

As extensões SIMD mais importantes são:

- SSE (128 bits);
- AVX (256 bits);
- AVX-512 (512 bits).

A vetorização é uma forma de paralelismo em nível de instrução e é amplamente utilizada em:

- Processamento multimídia;
- Álgebra linear;
- Inteligência Artificial;
- Computação científica.


# Programação para GPU com OpenMP

A partir da versão 4.5, OpenMP passou a permitir a execução de código em GPUs.

Esse recurso é chamado de **offloading**, pois o processamento é transferido da CPU para a GPU.

O programador utiliza diretivas semelhantes às usadas em CPU:

```c
#pragma omp target teams distribute parallel for
```

A CPU envia os dados para a memória da GPU, milhares de threads executam o cálculo e os resultados retornam para a CPU.

Essa abordagem fornece maior portabilidade em comparação com CUDA.


# Introdução à Programação para GPU com CUDA

CUDA (Compute Unified Device Architecture) é a plataforma de programação paralela desenvolvida pela NVIDIA para exploração das GPUs.

Enquanto CPUs possuem poucos núcleos muito sofisticados, GPUs possuem milhares de núcleos mais simples, capazes de executar enormes quantidades de operações em paralelo.

Os programas executados na GPU são chamados de kernels.

As threads são organizadas em:

- Threads;
- Blocos (Blocks);
- Grades (Grids).

Essa hierarquia permite distribuir milhões de operações simultaneamente.


# Padrões de Programação Paralela em CUDA

Os padrões Map e Reduce são amplamente empregados em CUDA.

Além deles, existem padrões específicos.

## Stencil

Cada elemento depende dos seus vizinhos.

Muito utilizado em:

- Simulação numérica;
- Processamento de imagens;
- Métodos de diferenças finitas.

---

## Tiling

Os dados são carregados para a memória compartilhada da GPU (shared memory), reduzindo acessos à memória global.

Essa técnica melhora significativamente o desempenho.


# Programação com Passagem de Mensagens em MPI

MPI (Message Passing Interface) é um padrão utilizado em sistemas de memória distribuída.

Cada processo possui sua própria memória e se comunica explicitamente através de mensagens.

Ao contrário do OpenMP, que utiliza threads, MPI trabalha com processos independentes.

As funções fundamentais são:

- `MPI_Init()`: inicialização;
- `MPI_Finalize()`: encerramento;
- `MPI_Comm_rank()`: identificador do processo;
- `MPI_Comm_size()`: quantidade total de processos.

As operações de comunicação incluem:

- `MPI_Send()`;
- `MPI_Recv()`;
- `MPI_Bcast()`;
- `MPI_Scatter()`;
- `MPI_Gather()`;
- `MPI_Reduce()`.

MPI é a principal tecnologia utilizada em:

- Clusters;
- Supercomputadores;
- Computação científica de larga escala.

# Comparação entre OpenMP, CUDA e MPI

| Característica | OpenMP | CUDA | MPI |
|----------------|--------|------|-----|
| Arquitetura | Memória compartilhada | GPU | Memória distribuída |
| Unidade de execução | Threads | Threads da GPU | Processos |
| Comunicação | Implícita | Implícita | Mensagens |
| Escalabilidade | Média | Alta | Muito alta |
| Complexidade | Baixa | Média | Alta |
| Aplicações | CPUs multicore | GPUs NVIDIA | Clusters e supercomputadores |
