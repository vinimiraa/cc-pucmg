# Considere a seguinte situação:
#     int ***x;
# Onde x contem um ponteiro para um ponteiro para um ponteiro para um inteiro. (tridimensional -> cubo)
# Nessa situação, considere que a posição inicial de memória contenha o inteiro em questão.
# Coloque todos os outros valores em registradores, use os endereços de memória que quiser dentro do espaço de 
# endereçamento do Mips.
# Resumo do problema:
#     k = MEM [ MEM [MEM [ x ] ] ].
# Crie um programa que implemente a estrutura de dados acima, leia o valor de K, o multiplique por 2 e o reescreva no 
# local correto conhecendo-se apenas o valor de x.

# *x     = &p2;
# *p2    = &p1;
# *p1    = &valor;
# *valor = valor;

.data
    x:     .word p2         # Terceiro ponteiro que aponta para 'p2' (***x)
    p2:    .word p1         # Segundo ponteiro que aponta para 'p1'
    p1:    .word valor      # Primeiro ponteiro que aponta para 'valor'
    valor: .word 10         # Inteiro inicial armazenado

.text
main:
    ori $t0, $zero, 0x1001 # $t0 = 0x00001001
    sll $t0, $t0  , 16     # $t0 = 0x10010000 -> onde começa a memoria de dados

    lw $t1, 0($t0)         # $t1 = MEM[$t0] -> p2
    lw $t2, 0($t1)         # $t2 = MEM[$t1] -> p1
    lw $t3, 0($t2)         # $t3 = MEM[$t2] -> valor
    lw $t4, 0($t3)         # $t4 = valor

    add $t4, $t4, $t4      # $t4 = k * 2

    sw $t4, 0($t3)         # MEM[$t3] = k * 2

# EOF
