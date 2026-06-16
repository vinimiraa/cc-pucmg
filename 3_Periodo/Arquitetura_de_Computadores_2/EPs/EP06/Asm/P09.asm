# Considere a memória inicial da seguinte forma:
# .text
# .data
# x1: .word 15
# x2: .word 25
# x3: .word 13
# x4: .word 17
# soma: .word -1
# Escrever um programa que leia todos os números, calcule e substitua o valor da variável soma por este valor.
# lw, sw

.data
    x1:   .word 15
    x2:   .word 25
    x3:   .word 13
    x4:   .word 17
    soma: .word -1

.text
main:
    ori $t0, $zero, 0x1001 # $t0 = 0x00001001
    sll $t0, $t0  , 16     # $t0 = 0x10010000 -> onde começa a memoria de dados
    
    lw  $t1, 0 ($t0)       # $t1 = $t0[0] = x1
    lw  $t2, 4 ($t0)       # $t2 = $t0[1] = x2 -> de 4 em 4 bits
    lw  $t3, 8 ($t0)       # $t3 = $t0[2] = x3
    lw  $t4, 12($t0)       # $t4 = $t0[3] = x4
    
    add $t5, $t1, $t2      # $t5 = x1  + x2
    add $t5, $t5, $t3      # $t5 = $t5 + x3
    add $t5, $t5, $t4      # $t5 = $t5 + x4

    sw  $t5, 16($t0)       # soma = $t0[4] = $t5

# EOF
