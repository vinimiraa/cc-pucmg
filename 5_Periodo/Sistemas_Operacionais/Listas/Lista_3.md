## Lista 3

- Prof. Mark Alan Junho Song
- 812839 - Vinícius Miranda de Araújo

**Questão 1. Explique o conceito de alocação contígua de memória.**

A alocação contígua de memória é uma técnica que aloca um bloco consecutivo na memória para um processo ou arquivo. A memória principal é dividida em duas: área do Sistema Operacional (SO), geralmente na parte baixa da memória e junto com o vetor de instruções, e a área do Usuário, mantido na parte alta da memória.

---
**Questão 2. Qual a função da MMU na gerência de memória?**

A *Memory Manegement Unit* (MMU) é responsável pela tradução (ou mapeamento) do endereço virtual para o endereço físico.

---
**Questão 3. Qual a diferença entre endereço físico e virtual?**

O endereço virtual é aquele gerado pela CPU ao executar um programa e o endereço físico é o endereço real na memória principal, é o que é visto pela unidade de memória.

---
**Questão 4. Se todos os processos que precisam executar não cabem na memória, o que pode ser feito? Explique a ideia de swapping.**

O que precisa ser executado é levado para a memória e o que não precisa é retirado. A ideia do *swapping* é que um processo pode ser removido temporariamente da memória para um dispositivo auxiliar e trazido de volta a memória quando for retomar a sua execução. 

---
**Questão 5. Explique o problema da fragmentação externa. Como solucionar o problema?**

O problema da fragmentação externa ocorre por causa da alocação contígua de memória, pois existe a memória suficiente para alocar o processo, mas ela não é contígua. Para resolver a fragmentação deve-se realizar a desfragmentação (ou compactação), que consiste em deslocar todo o conteúdo da memória para que toda a memória livre fique contígua.

---
**Questão 6. O que acontece quando um processo excede o tamanho alocado da sua área de crescimento?**

O processo, ao exceder o tamanho alocado da sua área de crescimento, ultrapassa o limite permito invadindo a área alocada de outro processo. O SO, para proteger a memória de outros processos e do próprio sistema, encerra o processo e gera o (~~famoso~~) erro de *segmentation fault*.

---
**Questão 7. O sistema operacional mantém uma lista de espaços livres na memória física. Sempre que um novo processo é criado esta lista é percorrida e usada. Quais as formas de percorrer a lista, ou seja, de alocar um bloco na memória para o processo?**

As formas de alocar um bloco na memória são:

- *First-Fit*: Aloca o primeiro buraco grande o suficiente.
- *Best-Fit*: Aloca o menor buraco grande o suficiente, deve pesquisar toda a lista, a não ser que esteja ordenada.
- *Worst-Fit*: Aloca o maior buraco.

Buraco = bloco de memória disponível (espaço livre).

---
**Questão 8. Considere um sistema cuja gerência de memória é feita através de partições variáveis. Inicialmente, existem os seguintes blocos: 10K, 4K, 20K, 18K, 7K, 9K, 12K e 13K, nessa ordem. Desenhe a memória e mostre como os blocos serão ocupados pelos processos de tamanho: 5K, 10K, 15K, 8K, 3K, 7K e 6K. Considere essa ordem de solicitação. Simule os seguintes algoritmos:**

**a. First-fit**

| MEMORIA | BLOCOS ALOCADOS | LIVRE |
| ------- | --------------- | ----- |
| 10k     | 5k - 3k         | 2k    |
| 4k      | -               | 4k    |
| 20k     | 10k - 8k        | 2k    |
| 18k     | 15k             | 3k    |
| 7k      | 7k              | 0k    |
| 9k      | 6k              | 3k    |
| 12k     | -               | 12k   |
| 13k     | -               | 13k   |

**b. Best-fit**

| MEMORIA | BLOCOS ALOCADOS | LIVRE |
| ------- | --------------- | ----- |
| 10k     | 10k             | 0k    |
| 4k      | -               | 4k    |
| 20k     | -               | 20k   |
| 18k     | 15k - 3k        | 0k    |
| 7k      | 5k              | 2k    |
| 9k      | 8k              | 1k    |
| 12k     | 7k              | 5k    |
| 13k     | 6k              | 7k    |

**c. Worst-fit**

| MEMORIA | BLOCOS ALOCADOS | LIVRE |
| ------- | --------------- | ----- |
| 10k     | 7k              | 3k    |
| 4k      | -               | 4k    |
| 20k     | 5k - 15k        | 0k    |
| 18k     | 10k             | 8k    |
| 7k      | -               | 7k    |
| 9k      | 6k              | 3k    |
| 12k     | 3k              | 9k    |
| 13k     | 8k              | 5k    |
