# x = 3;
# y = 4 ;
# z = ( 15*x + 67*y)*4
# sll, srl, sra

.text
main:
	ori  $s0, $zero, 3   # x = 3
	ori  $s1, $zero, 4   # y = 4
	# 15*x
	sll	 $t1, $s0  , 4   #
	sub  $t1, $t1  , $s0 # t1 = t1 - x
	# 67*z
	sll  $t2, $s1  , 6   # 
	add  $t2, $t2  , $s1 #
	add  $t2, $t2  , $s1 #
	add  $t2, $t2  , $s1 #
	
# EOF
