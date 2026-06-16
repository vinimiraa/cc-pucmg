# y = { x^3 + 1    se x >  0
#     { x^4 - 1    se x <= 0
# Os valores de x devem ser lidos da primeira posição livre da memória e o valor de y deverá ser
# escrito na segunda posição livre.

.data
    x: .word -2

.text
.globl main
main:
    ori $t0, $zero, 0x1001       # $t0 = 0x00001001
    sll $t0, $t0 , 16            # $t0 = 0x10010000 -> onde começa a memória de dados

    lw $s0, 0($t0)               # $s0 = x

    mult $s0, $s0                # x^2
    mflo $s2                     # $s2 = x^2

    mult $s2, $s0                # x^3
    mflo $s3                     # $s3 = x^3

    mult $s3, $s0                # x^4
    mflo $s4                     # $s4 = x^4

    slt $t1, $zero, $s0          # $t1 = 1 se $s0 > 0 (x > 0)
    beq $t1, $zero, menor        # if $s0 <= 0 goto menor

    addi $t2, $s3, 1             # $t2 = x^3 + 1
    sw $t2, 4($t0)               # $t0[1] = x^3 + 1
    j fim                        # goto fim

    menor:
        addi $t3, $s4, -1        # $t3 = x^4 - 1
        sw $t3, 4($t0)           # $t0[1] = x^4 - 1

    fim:
# EOF
