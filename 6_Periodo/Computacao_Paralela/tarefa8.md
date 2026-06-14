/**
 * Computacao Paralela
 * 812939 - Vinicius Miranda de Araujo
 */

## Questão 1

Em relação as políticas de escalonamento do OpenMP, podemos afirmar que:

I. A política estática procura dividir o número de blocos de iterações (chunk) do laço de repetição igualmente entre as threads.

II. A política dinâmica é geralmente mais eficiente que a estática para aplicações desbalanceadas.

II. A diferença principal da política guiada para a estática é a diminuição do tamanho do bloco de iterações (chunk) ao longo da execução.

IV. Na política dinâmica, quanto menor o tamanho do bloco de iterações (chunk), mais balanceada fica a aplicação.

V. Na política dinâmica, quanto menor o tamanho do bloco de iterações (chunk), mais rápida fica a aplicação.

> Resposta: apenas I, II e IV são afirmativas corretas

## Questão 2

Em relação a resolução de condições de disputa em OpenMP, podemos afirmar que:

I. A implementação de uma operação de redução usando a diretiva "omp critical" tem desempenho muito inferior a da diretiva "omp reduction". 

II. Uma variável que nunca é modificada em iterações diferentes do laço de repetição deve ser declarada como privada.

III. A diretiva "omp critical" garante que um trecho de código é acessado por apenas uma thread de cada vez.

IV. A diretiva "shared" cria uma cópia de uma variável compartilhada para cada thread.

V. Quando uma variável é declarada como privada (private), é como se ela tivesse sido declarada dentro do laço de repetição, mas apenas uma vez para cada thread.

> Resposta: apenas II, III e V são afirmativas corretas

## Questão 3

O padrão paralelo Reduce combina elementos de entrada, dois a dois, por meio de um operador, até gerar um único elemento de saída, que é o resumo de todos os outros. Este operador de redução precisa necessariamente ser:

> Resposta: pelo menos associativo