# Escrever um programa que leia dois números da memória, a primeira e segunda posições respectivamente (os coloque em 
# $s0 e $s1) e determine a quantidade de bits significantes de cada um. Coloque as respostas em $t0 e $t1, a partir desse 
# resultado faça a multiplicação. Caso o número de bits significantes de ambos seja menor do que 32 a resposta deverá 
# estar apenas em $s2, caso contrário a resposta estará em $s2 e $s3 (LO e HI respectivamente).

.data
    x: .word 3
    y: .word 2
    k: .word -1

.text
.globl main
main:
    ori $t0, $zero, 0x1001   # $t0 = 0x00001001
    sll $t0, $t0 , 16        # $t0 = 0x10010000 -> onde começa a memória de dados

    lw  $s0, 0($t0)          # Carrega x em $s0
    lw  $s1, 4($t0)          # Carrega y em $s1

    ori $t1, $zero, 0        # $t1 = 0 = contador de bits significativos de x
    ori $t2, $zero, 0        # $t2 = 0 = contador de bits significativos de y

    or  $t3, $zero, $s0               # $t3 = x
    count_x:
        beq  $t3, $zero, count_y      # if $t3 == 0 goto count_y
        srl  $t3, $t3, 1              # $t3 = $t3 >> 1
        addi $t1, $t1, 1              # $t1++
        j count_x                     # goto count_x

    count_y:
        or $t3, $zero, $s1            # $t3 = y
    count_y_loop:
        beq  $t3, $zero, multiply     # if $t3 == 0 goto multiply
        srl  $t3, $t3, 1              # $t3 = $t3 >> 1
        addi $t2, $t2, 1              # $t2++
        j count_y_loop                # goto count_y_loop

    multiply:
        mult $t1, $t2                 # $s0 * $s1
        mflo $s2                      # $s2 = LO
        mfhi $s3                      # $s3 = HI

        slti $t5, $t1, 32             # Se $t1 < 32, $t5 = 1
        slti $t6, $t2, 32             # Se $t2 < 32, $t6 = 1
        and  $t7, $t5, $t6            # $t7 = 1 se ambos têm menos de 32 bits significativos

        beq  $t7, $zero, store_hi_lo  # if $t7 == 0 goto store_hi_lo
        sw   $s2, 8($t0)              # Se $t7 é 1, armazena apenas em $s2
        j end                         # goto end

    store_hi_lo:
        sw   $s2, 8($t0)              # Armazena parte baixa em posição k
        sw   $s3, 12($t0)             # Armazena parte alta em posição k + 4

    end:
    
# EOF 
