# Para a expressão a seguir, escreva um programa que calcule o valor de k:
# k = x * y (Você deverá realizar a multiplicação através de somas!)
# O valor de x deve ser lido da primeira posição livre da memória e o valor de y deverá lido da segunda posição livre.
# O valor de k, após calculado, deverá ainda ser escrito na terceira posição livre da memória.

.data
	x: .word 10
	y: .word 10
	k: .word -1
	
.text
.globl main
main:
	ori $t0, $zero, 0x1001    # $t0 = 0x00001001
	sll $t0, $t0 , 16         # $t0 = 0x10010000 -> onde começa a memoria de dados
	
	lw $t1, 0($t0)            # $t1 = x
	lw $t2, 4($t0)            # $t2 = y
	
	loop:
		add $t3, $t3, $t1     # k = k + x
		addi $t2, $t2, -1     # y = y -1
		bne $t2, $zero, loop  # if y != 0 goto loop
		sw $t3, 8($t0)        # $t0[8] = $t3
# EOF
