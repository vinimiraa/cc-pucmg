# a =2;
# b =3;
# c =4;
# d =5;
# x = (a+b) - (c+d);
# y = a – b + x;
# b = x – y;
# add, addi, sub, lógicas

.text
main:
	ori  $s0, $zero, 2   # a  = 2
	ori  $s1, $zero, 3   # b  = 3
	ori  $s2, $zero, 4   # c  = 4
	ori  $s3, $zero, 5   # d  = 5
	add  $t0, $s0  , $s1 # t1 = a  + b
	add  $t1, $s2  , $s3 # t2 = c  + d
	sub  $t0, $t0  , $t1 # t1 = t1 - t2
	sub  $t2, $s0  , $s1 # t3 = a  - b  
	add  $t2, $t2  , $t0 # t3 = t3 + t1
	sub  $s1, $t0  , $t2 # b  = t1 - t3
	
# EOF
