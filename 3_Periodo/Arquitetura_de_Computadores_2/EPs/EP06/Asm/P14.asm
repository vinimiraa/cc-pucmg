# Escreva um programa que leia um valor A da memória, identifique se o número é par ou não. 
# Um valor deverá ser escrito na segunda posição livre da memória (0 para par e 1 para ímpar).

.data
    a: .word 10

.text
.globl main
main:
    ori $t0, $zero, 0x1001
    sll $t0, $t0  , 16

    lw  $t1, 0($t0)

    andi $t2, $t1  , 1
    beq  $t2, $zero, is_even
    ori  $t2, $zero, 1
    j end

    is_even:
        ori $t2, $zero, 0

    end:
        sw  $t2, 4($t0)

# EOF
