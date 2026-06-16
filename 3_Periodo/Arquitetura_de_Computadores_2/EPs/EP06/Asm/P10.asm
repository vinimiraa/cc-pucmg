# Considere o seguinte programa: 
#     y = 127x – 65z + 1
# Faça um programa que calcule o valor de y conhecendo os valores de x e z. Os valores de x e z estão armazenados na 
# memória e, na posição imediatamente a seguir, o valor de y deverá ser escrito, ou seja:
#     .data
#     x: .word 5
#     z: .word 7
#     y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa
# lw, sw

.data
    x: .word 5
    z: .word 7
    y: .word 0

.text
main:
    ori $t0, $zero, 0x1001 # $t0 = 0x00001001
    sll $t0, $t0  , 16     # $t0 = 0x10010000 -> onde começa a memoria de dados

    lw  $t1, 0($t0)        # $t1 = $t0[0] = x
    lw  $t2, 4($t0)        # $t2 = $t0[1] = z

    calcular_127x:
        sll  $t3, $t1, 7   # $t3 = x << 7
        sub  $t3, $t3, $t1 # $t3 = $t3 - x
    
    calcular_65z:
        sll  $t4, $t2, 6   # $t4 = z << 6
        add  $t4, $t4, $t2 # $t4 = $t4 + z

    calcular_exp:
        add  $t4, $t4, $t3 # $t4 = 65z + 127x
        addi $t4, $t4, 1   # $t4 = $t4 + 1

    sw  $t4, 8($t0)        # y = $t0[2] = $t4

# EOF
