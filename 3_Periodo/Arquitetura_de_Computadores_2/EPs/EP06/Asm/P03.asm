# x = 3;
# y = 4 ;
# z = ( 15*x + 67*y)*4
# add, addi, sub, lógicas

.text
main:

	ori  $s0, $zero, 3    # x  = 3
	ori  $s1, $zero, 4    # y  = 4
	# 15 * x	
	add  $t1, $s0  , $s0  # t1 =   x +  x  = 2x
	add  $t1, $t1  , $t1  # t1 =  2x + 2x  = 4x
	add  $t1, $t1  , $t1  # t1 =  4x + 4x  = 8x
	add  $t1, $t1  , $t1  # t1 =  8x + 8x  = 16x
	sub  $t1, $t1  , $s0  # t1 = 16x -  x  = 15x
	# 67 * y
	add  $t2, $s1  , $s1  # t2 =   y +   y = 2y
	add  $t2, $t2  , $t2  # t2 =  2y +  2y = 4y
	add  $t2, $t2  , $t2  # t2 =  4y +  4y = 8y
	add  $t2, $t2  , $t2  # t2 =  8y +  8y = 16y
	add  $t2, $t2  , $t2  # t2 = 16y + 16y = 32y
	add  $t2, $t2  , $t2  # t2 = 32y + 32y = 64y
	add  $t2, $t2  , $s1  # t2 = 64y +   y = 65y
	add  $t2, $t2  , $s1  # t2 = 65y +   y = 66y 
	add  $t2, $t2  , $s1  # t2 = 66y +   y = 67y
	# 15x + 67y
	add  $t3, $t1  , $t2  # t3 = t1  + t2  = a
	# ( 15x + 67y ) * 4
	add  $t3, $t3  , $t3  # t3 = s   + a   = 2a
	add  $t3, $t3  , $t3  # t3 = 2a  + 2a  = 4a
	add  $s2, $zero, $t3  # z  = t3
	
# EOF
