# Escreva um programa que avalie a expressão:
# (x * y) / z.
# Use
# x = 1600000 (=0x186A00),
# y = 80000 (=0x13880),
# z = 400000 (=0x61A80).
# Inicializar os registradores com os valores acima.

.data
	x: .word 0x186A00
	y: .word 0x13880
	z: .word 0x61A80
	
.text
.globl main
main:
	ori  $s0, $0, 0x186A  # $s0 = 0x0000186A
	ori  $s1, $0, 0x1388  # $s1 = 0x00001388
	ori  $s2, $0, 0x61A8  # $s2 = 0x000061A8
	mult $s0, $s1         # $s0 * $s1 = 0x186A__ * 0x1388_ = 0xXXXX___
	mflo $t0              #
	div  $t0, $s2         # $t0 / $s2 = 0xXXXX___ / 0x61A8_ = 0xXXXX__
	mflo $t0              #
	sll  $t0, $t0, 8      #
	
# EOF
