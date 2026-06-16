.data
A: .word 9               # Número 1
B: .word 98               # Número 2
C: .word 9               # Número 3
MEDIAN: .word 0           # Local para armazenar a mediana

.text
.globl main
main:
    lui $t0, 0x1001       # Endereço base dos números
    lw $s0, 0($t0)        # A
    lw $s1, 4($t0)        # B
    lw $s2, 8($t0)        # C

    # Verifica se A é a mediana
    slt $t1, $s0, $s1         # A < B ? 1 : 0
    slt $t2, $s2, $s0         # C < A ? 1 : 0
    and $t3, $t1, $t2         
    bne $t3, $zero, A_e_mediana # if( C < A && A < B ) goto A_e_mediana 

	slt $t1, $s0, $s2         # A < C ? 1 : 0
	slt $t2, $s1, $s0         # B < A ? 1 : 0
	and $t3, $t1, $t2
	bne $t3, $zero, A_e_mediana # if( B < A && A < C ) goto A_e_mediana 
	
	# Verifica se B é a mediana
    slt $t1, $s1, $s0         # B < A ? 1 : 0
    slt $t2, $s2, $s1         # C < B ? 1 : 0
    and $t3, $t1, $t2         
    bne $t3, $zero, B_e_mediana # if( C < B && B < A ) goto B_e_mediana 

    slt $t1, $s1, $s2         # B < C ? 1 : 0
    slt $t2, $s0, $s1         # A < B ? 1 : 0
    and $t3, $t1, $t2
    bne $t3, $zero, B_e_mediana # if( A < B && B < C ) goto B_e_mediana 

    # Caso contrário, C é a mediana
    j C_e_mediana

    A_e_mediana:
        sw $s0, 12($t0)       # Armazena A como mediana
        j end

    B_e_mediana:
        sw $s1, 12($t0)       # Armazena B como mediana
        j end

    C_e_mediana:
        sw $s2, 12($t0)       # Armazena C como mediana

    end:

