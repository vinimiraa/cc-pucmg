# Escreva um programa que leia um valor A da memória, identifique se o número é negativo ou não e encontre o seu módulo. 
# O valor deverá ser reescrito sobre A.

.data
    a: .word -10

.text
.globl main
main:
    ori $t0, $zero, 0x1001
    sll $t0, $t0, 16

    lw $t1, 0($t0)

    sra $t1, $t1, 31
    beq $t1, $zero, is_positive
    sub $t1, $zero, $t1

    is_positive:
        sw $t1, 0($t0)

# EOF
