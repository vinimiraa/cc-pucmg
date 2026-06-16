# if( 50 <= x && x <= 100 ||
#    150 <= x && x <= 200 )

.data
	x: 201

.text
.globl main
main:
    lui $t0, 0x1001
	lw  $s0, 0($t0)
	ori $s1, $0, 0
	ori $s2, $0, 50
	ori $s3, $0, 100
	ori $s4, $0, 150
	ori $s5, $0, 200
	
	exp1:
        slt $t1, $s0, $s2   # if( x < 50 ) ? t1 = 1 : t1 = 0
        bne $t1, $0 , exp2  # if( t1 != 0 ) goto exp2
        
        slt $t2, $s3, $s0   # if( 100 < x ) ? t2 = 1 : t2 = 0
        bne $t2, $0, exp2   # if( t2 != 0 ) goto exp2
        
        ori $s1, $0, 1
        j fim

	exp2:
        slt $t1, $s0, $s4  # if( x < 150 ) ? t1 = 1 : t1 = 0
        bne $t1, $0, fim   # if( t1 != 0 ) goto fim
        
        slt $t2, $s5, $s0  # if( 200 < x ) ? t2 = 1 : t2 = 0
        bne $t2, $0, fim   # if( t2 != 0 ) goto fim
        
        ori $s1, $0, 1
        
fim:
