# Considere a seguinte instrução iniciando um programa:
#     ori $8, $0, 0x01
# Usando apenas instruções reg-reg lógicas e/ou instruções de deslocamento (sll, srl, sra), continuar o 
# programa de forma que ao final, tenhamos o seguinte conteúdo no registrador $8:
#     $8 = 0xFFFFFFFF

.text
main:
    solucao_1:
        ori $8, $zero, 0x01   # $8 = 0x00000001
        ori $8, $8   , 0xFFFF # $8 = 0x0000FFFF
        sll $8, $8   , 16     # $8 = 0xFFFF0000
        ori $8, $8   , 0xFFFF # $8 = 0xFFFFFFFF
    
    solucao_2:
        ori  $8, $zero, 0x01   # $8 = 0x00000001
        addi $8, $8   , -2     # $8 = 0xFFFFFFFF
        
# EOF
