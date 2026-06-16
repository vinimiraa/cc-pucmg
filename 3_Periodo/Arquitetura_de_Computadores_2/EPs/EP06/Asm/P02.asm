# x = 1;
# y = 5*x + 15;
# add, addi, sub, lógicas

.text
main:
	ori  $s0, $zero, 1   # x  = 1
	add  $t1, $s0  , $s0 # t1 =  x +  x = 2x
	add  $t1, $t1  , $t1 # t1 = 2x + 2x = 4x
	add  $t1, $t1  , $s0 # t1 = 4x +  x = 5x 
	addi $s1, $t1  , 15  # y  = t1 + 15
	
# EOF
