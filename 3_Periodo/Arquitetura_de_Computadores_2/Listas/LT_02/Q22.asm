.text
.globl main
main:
	lui  $t0, 0x1001        # Endereço Base do Array
	or   $a0, $zero, $t0    # $a0 = Endereço Base
	addi $a1, $zero, 10     # $a1 = Quantidade de Elementos
	jal  function           # Chama a função
	or   $s0, $zero, $v0    # Copia a soma retornada para $s0
	j fim

function:
    or $v0, $zero, $zero    # soma = 0
    or $t1, $zero, $zero    # i = 0
    loop:
        beq  $t1, $a1, end      # Se i == n, encerra
        andi $t2, $t1, 1        # t2 = i % 2
        beq  $t2, $zero, par    # Se i % 2 == 0, goto par
        impar:
            sw   $t1, 0($a0)    # Salva i no Array
            add  $v0, $v0, $t1  # soma += array[i]
            j inc
        par:
            sll  $t3, $t1, 1    # i * 2 
            addi $t3, $t3, -1   # i * 2 - 1
            sw   $t3, 0($a0)    # Salva i no Array
            add  $v0, $v0, $t3  # soma += array[i]
        inc:
            addi $t1, $t1, 1    # i++
            addi $a0, $a0, 4    # &array[i] = &array[i] + 4
            j loop
    end:
        jr $ra
fim: