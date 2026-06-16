# Escrever um programa que crie um vetor de 100 elementos na memória onde 
#     vetor[i] = 2 * i + 1. 
# Após a última posição do vetor criado, escrever a soma de todos os valores armazenados do vetor.
# Use o MARS para verificar a quantidade de instruções conforme o tipo (ULA, Desvios, Mem ou Outras)

.data
    vetor: .space 400
    soma:  .word  0

.text
.globl main
main:
    ori $t0, $zero, 0x1001  # $t0 = 0x00001001
    sll $t0, $t0  , 16      # $t0 = 0x10010000 -> onde começa a memoria de dados

    ori $t1, $zero, 0       # endereco = 0
    ori $t2, $zero, 0       # i        = 0
    ori $t3, $zero, 100     # n        = 100
    ori $t4, $zero, 0       # soma     = 0

    loop:
        sll  $t5, $t2, 1    # $t5 = 2 * i
        addi $t5, $t5, 1    # $t5 = 2 * i + 1

        add  $t6, $t0, $t1  # $t6 = $t0 + $t1 -> endereço do vetor[i]
        sw   $t5, 0($t6)    # vetor[i] = 2 * i + 1
        
        addi $t1, $t1, 4    # endereco = endereco + 4
        add  $t4, $t4, $t5  # soma = soma + vetor[i]
        addi $t2, $t2, 1    # i = i + 1

        bne  $t2, $t3, loop # if i != n goto loop

    sw $t4, 400($t0)        # MEM[400] = soma

# EOF