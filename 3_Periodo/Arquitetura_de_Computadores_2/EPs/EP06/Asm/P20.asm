# y = { x^4 + x^3 - 2x^2    se x for par
#     { x^5 - x^3 + 1       se x for impar
# Os valores de x devem ser lidos da primeira posição livre da memória e o valor de y deverá ser escrito 
# na segunda posição livre.

.data
    x: .word 3

.text
.globl main
main:
    ori $t0, $zero, 0x1001     # $t0 = 0x00001001
    sll $t0, $t0, 16           # $t0 = 0x10010000 (início da memória de dados)

    lw $s0, 0($t0)             # Carrega x em $s0

    ori $t1, $zero, 2          # $t1 = 2
    
    div $s0, $t1               # Divide x por 2
    mfhi $s1                   # $s1 = resto de x / 2 (0 se par, != 0 se ímpar)

    mult $s0, $s0              # x^2
    mflo $s2                   # $s2 = x^2
    
    mult $s2, $s0              # x^3
    mflo $s3                   # $s3 = x^3

    mult $s2, $s2              # x^4
    mflo $s4                   # $s4 = x^4

    mult $s4, $s0              # x^5
    mflo $s5                   # $s5 = x^5

    bne $s1, $zero, impar_case # Se $s1 != 0 (x é ímpar), vá para impar_case

    par_case:
        add $t2, $s4, $s3      # $t2 = x^4 + x^3

        add $t3, $s2, $s2      # $t3 = 2 * x^2

        sub $t4, $t2, $t3      # $t4 = x^4 + x^3 - 2*x^2
        sw $t4, 4($t0)         # Armazena y na segunda posição da memória
        j end                  # Fim do programa

    impar_case:
        sub $t5, $s5, $s3      # $t5 = x^5 - x^3
        addi $t6, $t5, 1       # $t6 = x^5 - x^3 + 1
        sw $t6, 4($t0)         # Armazena y na segunda posição da memória

    end:
# EOF
