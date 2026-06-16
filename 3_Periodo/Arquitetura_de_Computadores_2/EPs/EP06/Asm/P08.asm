# Inicialmente escreva um programa que faça:
#     $8 = 0x12345678.
# A partir do registrador $8 acima, usando apenas instruções lógicas (or, ori, and, andi, xor, xori) 
# e instruções de deslocamento (sll, srl e sra), você deverá obter os seguintes valores nos respectivos 
# registradores:
#     $9  = 0x12
#     $10 = 0x34
#     $11 = 0x56
#     $12 = 0x78

.text
main:
    ori  $8 , $zero, 0x1234 # $8  = 0x00001234
    sll  $8 , $8   , 16     # $8  = 0x12340000
    ori  $8 , $8   , 0x5678 # $8  = 0x12345678
    sra  $9 , $8   , 24     # $9  = $8 >> 24
    sra  $10, $8   , 16     # $10 = $10 >> 16
    andi $10, $10  , 0xFF   # $10 = andi( 0x00001234, 0x000000FF ) -> mascarando os bits
    sra  $11, $8   , 8      # $11 = $8 >> 8
    andi $11, $11  , 0xFF   # $11 = andi( 0x00123456, 0x000000FF ) -> mascarando os bits
    andi $12, $8   , 0xFF   # $11 = andi( 0x12345678, 0x000000FF ) -> mascarando os bits

# EOF
