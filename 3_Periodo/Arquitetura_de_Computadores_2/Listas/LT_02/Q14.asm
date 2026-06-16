.data
array: .word 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

.text
.globl main
main:
	lui $t0, 0x1001
	
	ori $s0, $zero, 20              # size = 0 (tamanho do array)
	ori $t1, $zero, 0               # i = 0
	do_1: 
		ori $t2, $zero, 0           # j = 0
		do_2:
			sll  $t3, $t2, 2        # t3 = j * 4
			add  $t4, $t0, $t3      # t4 = & MEM[j]
			lw   $s1, 0($t4)        # s1 = MEM[j]
			lw   $s2, 4($t4)        # s2 = MEM[j+1]
			slt  $t5, $s2, $s1      # ( s2 < s1 ) ? t5 = 1 : t5 = 0
			beq  $t5, $zero, jmm    # if( t5 == 0 ) goto jmm
			or   $t6, $s1, $zero    # temp = s1
			sw   $s2, 0($t4)        # MEM[j] = s2
			sw   $t6, 4($t4)        # MEM[j+1] = s1
		jmm:
			addi $t2, $t2, 1        # j = j + 1
		while_2:	
			addi $t7, $s0, -1       # t7 = size - 1
			bne  $t2, $t7, do_2     # if( j != size-1 ) goto do_2
		imm:
			addi $t1, $t1, 1        # i = i + 1
	while_1:
		bne $t1, $s0, do_1          # if( i != size ) goto do_1

# EOF
