.data
    x: .word 2
    y: .word 5
    k: .word -1

.text
.globl main
main:
    lui $t0, 0x1001        # $t0 = 0x00001001
    lw  $s0, 0($t0)               # $s0 = x
    lw  $s1, 4($t0)               # $s1 = y
    or  $a0, $s0, $zero           # $a0 = x
    or  $a1, $s1, $zero           # $a1 = y
    jal pow
    sw  $v0, 8($t0)               # Salva o resultado em k
    j fim
    
pow:
    ori $v0, $zero, 1             # $v0 = k = 1 (inicializando k)
    or  $t1, $zero, $a1           # $t1 = y (contador)
    f:
        beq $t1, $zero, end      # Se y == 0 goto end
        ori $t2, $zero, 0        # $t2 = 0 (inicializando x)
        or  $t3, $zero, $v0      # $t3 = k (valor atual de k para multiplicação)
        mul:
            add  $t2, $t2, $a0    # $t2 = $t2 + x
            addi $t3, $t3, -1     # $t3 = $t3 - 1
            bne  $t3, $zero, mul  # Se $t3 != 0 goto mul
        or  $v0, $t2, $zero      # $v0 = $t2 (atualiza k)
        addi $t1, $t1, -1        # y = y - 1
        j f                      # goto f
    end:
        jr $ra

fim:
# EOF
