# Considere o seguinte programa: 
#     y = x – z + 300000
# Faça um programa que calcule o valor de y conhecendo os valores de x e z. Os valores de x e z estão armazenados na 
# memória e, na posição imediatamente a seguir, o valor de y deverá ser escrito, ou seja:
#     .data
#     x: .word 100000
#     z: .word 200000
#     y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.

.data
    x: .word 100000
    z: .word 200000
    y: .word 0

.text
main:
    ori $t0, $zero, 0x1001 # $t0 = 0x00001001
    sll $t0, $t0  , 16     # $t0 = 0x10010000 -> onde começa a memoria de dados

    lw  $t1, 0($t0)        # $t1 = $t0[0] = x
    lw  $t2, 4($t0)        # $t2 = $t0[1] = z

    sub $t3, $t1, $t2      # $t3 = x - z
    ori $t4, $t4, 0x493E   # $t4 = $t4 + 0x493E
    sll $t4, $t4, 4        # $t4 = $t4 << 4
    add $t3, $t3, $t4      # $t3 = $t3 + 300000

    sw  $t3, 8($t0)        # y = $t0[2] = $t3

# EOF
