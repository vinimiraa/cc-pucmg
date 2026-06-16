.text
.globl main
main:
    lui $t0, 0x1001           # Base do vetor Fibonacci na memória
    ori $s0, $zero, 100       # Total de Termos (100)
    ori $s1, $zero, 1         # Termo 1
    ori $s2, $zero, 1         # Termo 2
    sw  $s1, 0($t0)           # fib[0] = 1
    sw  $s2, 4($t0)           # fib[1] = 1
    ori $t1, $zero, 2         # Qtd de Termos Atual (índice atual no vetor)
    loop:
        beq $t1, $s0, fim         # if( qtdTermos == totalTermos ) goto fim
                                  # Calcula o próximo termo
        add $s3, $s1, $s2         # s3 = termo anterior + termo atual
                                  # Armazena o termo atual no vetor
        sll $t2, $t1, 2           # t2 = deslocamento em bytes (indice * 4)
        add $t3, $t0, $t2         # t3 = endereço para fib[qtdTermos]
        sw  $s3, 0($t3)           # fib[qtdTermos] = s3
                                  # Atualiza os termos anteriores
        or $s1, $s2, $zero        # s1 = s2 (termo atual vira termo anterior)
        or $s2, $s3, $zero        # s2 = s3 (novo termo vira termo atual)
        addi $t1, $t1, 1          # qtdTermos++
        j loop
fim:
