# x = o maior inteiro possível;
# y = 300000 = 493e0;
# z = x - 4y
# sll, srl e sra

.text
main:
	ori $s0, $zero, 0x7FFF # x = maior inteiro de 16 bits positivo
	ori $t0, $zero, 0x493E # t1 = 0x493E
	sll $s1, $t0  , 4      # y = t1 << 4b
	sll $t1, $s1  , 2      # t1 = y << 2b
    sub $s2, $s0  , $t1    # z = x - t1

# EOF
