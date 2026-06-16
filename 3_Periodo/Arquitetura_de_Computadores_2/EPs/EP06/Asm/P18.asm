# Para a expressão a seguir, escreva um programa que calcule o valor de k:
# k = x^y
# Obs: Você poderá utilizar o exercício anterior.
# O valor de x deve ser lido da primeira posição livre da memória e o valor de y deverá lido da segunda posição livre.
# O valor de k, após calculado, deverá ainda ser escrito na terceira posição livre da memória.
# Dê um valor para x e y (dê valores pequenos !!) e use o MARS para verificar a quantidade de instruções conforme o tipo
# (ULA, Desvios, Mem ou Outras)

.data
    x: .word 2
    y: .word 5
    k: .word -1

.text
.globl main
main:
    ori $t0, $zero, 0x1001        # $t0 = 0x00001001
    sll $t0, $t0 , 16             # $t0 = 0x10010000 -> onde começa a memória de dados
        
    lw  $s0, 0($t0)               # $s0 = x
    lw  $s1, 4($t0)               # $s1 = y
    
    ori $s2, $zero, 1             # $s2 = k = 1 (inicializando k)
    or  $t2, $zero, $s1           # $t2 = y (contador)

	pow:     
		beq  $t2, $zero, end      # Se y == 0 goto end

		ori  $t3, $zero, 0        # $t3 = 0 (inicializando x)
		or   $t4, $zero, $s2      # $t4 = k (valor atual de k para multiplicação)
		
	mul:     
		add  $t3, $t3, $s0        # $t3 = $t3 + x
		addi $t4, $t4, -1         # $t4 = $t4 - 1
		bne  $t4, $zero, mul      # Se $t4 != 0 goto mul
		
		or   $s2, $t3, $zero      # $s2 = $t3 (atualiza k)
		addi $t2, $t2, -1         # y = y - 1
		j pow                     # goto pow

	end:
		sw $s2, 8($t0)            # Salva o resultado em k

# EOF
