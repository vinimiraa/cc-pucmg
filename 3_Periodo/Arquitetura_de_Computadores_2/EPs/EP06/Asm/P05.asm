# x = 100000 = 0x186A0;
# y = 200000 = 0x30D40;
# z = x + y;
# sll, srl e sra

.text
main:
	ori $t1, $zero, 0x186A # t1 = 0x186A
	sll $s1, $t1  , 4      # x = t1 << 4b
	ori $t2, $zero, 0x30D4 # t2 = 0x30D4
	sll $s2, $t2  , 4      # y = t2 << 4b
	add $s3, $s1  , $s2    # z = x + y
	
# EOF
