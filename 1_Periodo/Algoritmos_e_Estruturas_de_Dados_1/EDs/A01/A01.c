/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * VDA01 - v0.0. - 17 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o VDA01 VDA01.c
 *      Windows: gcc -o VDA01 VDA01.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./VDA01
 *      Windows: VDA01
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void questao01();
void questao02();
void questao03();
void questao04();
void questao05();
void questao06();
void questao07();
void questao08();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: VDA01 - v0.0");

        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch (opcao)
        {
        case 0:
            printf("\n%s\n", "Programa Encerrado...");
            break;
        case 1:
            questao01();
            break;
        case 2:
            questao02();
            break;
        case 3:
            questao03();
            break;
        case 4:
            questao04();
            break;
        case 5:
            questao05();
            break;
        case 6:
            questao06();
            break;
        case 7:
            questao07();
            break;
        case 8:
            questao08();
            break;
        default:
            printf("\n%s\n", "ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

    // encerrar
    pause("Aperte ENTER para continuar!");

    return (0);
}

// -------------------------- definicao de metodos

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    printf("\n");
    printf("%s\n\n", "Escolha alguma das opcoes a seguir:");
    printf("%s\n", "  0 - Encerrar programa");
    printf("%s\n", "  1 - Questao 01");
    printf("%s\n", "  2 - Questao 02");
    printf("%s\n", "  3 - Questao 03");
    printf("%s\n", "  4 - Questao 04");
    printf("%s\n", "  5 - Questao 05");
    printf("%s\n", "  6 - Questao 06");
    printf("%s\n", "  7 - Questao 07");
    printf("%s\n", "  8 - Questao 08");
    printf("\n");
} // fim menuOpcoes()

int f1a( int x, int y, int z )
{
    int w = 0;
    while( x < y-1 )
    { 
        x = x + 1;
        if( x % 2 == 0 && x % z == 0 )
        { printf( "%d ", x ); w = w + 1; }
    }
    return (w);
}
/**
 * Metodo01.
 */
void questao01()
{
    // identificacao
    id("Questao 01:");

    // programa

    printf( "> %d\n", f1a(12,45,3) );

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao01

int f2a( char *text, char c, char d, int y)
{
    for ( int x = strlen(text)-1; x >= 0; x = x - 1 )
    {
        if( c == text[x] && y > 0 )
        { text[x] = d; y = y - 1; if( y == 0 ) x = 0; }
    }
    return (y);
}
/**
 * Metodo02.
 */
void questao02()
{
    // identificacao
    id("Questao 02:");

    // programa

    char s[10] = "batata";
    int d = f2a( s, 'a', 'A', 2 );

    printf("%d [%s]\n", d, s);

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao02

int f3a( int x )
{
    int y = 0, z = 0;
    while( x > 0 )
    { z = x % 10; if( z % 2 != 0 ) y = y * 10 + x % 10; x = x / 10; }
    return (y);
}
/**
 * Metodo03.
 */
void questao03()
{
    // identificacao
    id("Questao 03:");

    // programa

    printf( "%d\n", f3a(123456) );

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao03

int f4a( int x )
{
    int w = 6;
    while( x-1 > 0 )
    {
        w = w + 1;
        if( w % 7 == 0) { if( w%10%2 != 0 )
            printf("%d ", w); w = w + 13; } x = x - 1;
    }
    return ( w + 1 );
}
/**
 * Metodo04.
 */
void questao04()
{
    // identificacao
    id("Questao 04:");

    // programa

    printf( "> %d\n", f4a(5) );

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao04

int f5a( int x, int y, int z )
{
    if( x > 0 )
    { z = z + y; y = y + 2; x = x - 1; z = f5a(x,y,z); }
    return (z);
}
/**
 * Metodo05.
 */
void questao05()
{
    // identificacao
    id("Questao 05:");

    // programa

    printf( "f5a(2,1,0) =  3 -> %d\n", f5a(2,1,0) );
    printf( "f5a(3,1,0) =  8 -> %d\n", f5a(3,1,0) );
    printf( "f5a(4,1,0) = 18 -> %d\n", f5a(4,1,0) );
    printf( "f5a(5,1,0) = 25 -> %d\n", f5a(5,1,0) );

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao05

bool norep(char *palavra)
{
    bool resultado = true;
    int contador = 0;

    int n = strlen(palavra);

    for( int i = 0; i < n; i++ )
    {
        char c = palavra[i];
        for( int j = i+1; j < n; j++ )
        {
            if(c == palavra[j])
                contador++;
        }
    }

    if( contador > 0 )
    { resultado = false; }

    return (resultado);
}
/**
 * Metodo06.
 */
void questao06()
{
    // identificacao
    id("Questao 06:");

    // programa
    int contador = 0;
    char palavra[80];

    while( contador < 2 )
    {   
        printf("%s", "Palavra = ");
        scanf("%s", palavra);

        if( norep(palavra) )
            contador++; 
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao06

void f7_a(int n)
{
    if(n > 0)
    {
        f7_a(n-1);

        for (int i = 1; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void f7_b(int n)
{
    if(n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");

        f7_b(n-1);
    }
}
/**
 * Metodo07.
 */
void questao07()
{
    // identificacao
    id("Questao 07:");

    // programa
    int n = 0;
    
    print("%s", "Quantidade = ");
    scanf( "%d", &n );

    f7_a(n); //mostrar do comeco ate a metade menos um
    f7_b(n); //mostrar da metada ate o final
    
    getchar();
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim questao07

double somar( int n )
{
    double soma = 0.0;
    double nume = 1.0, deno = 0.0;
    for( int i = 0; i < n; i++ )
    {   
        deno = pow(3,i);
        soma = soma + nume/deno;
        
        if(nume==1)
        {   nume++;  }
        else
        {   nume = nume + 4;    }
    }
    return (soma);
}
/**
 * Metodo08.
 */
void questao08()
{
    // identificacao
    id("Questao 08:");

    // programa
    int n = 0;
    double resultado = 0.0;

    printf("%s", "Numero = ");
    scanf( "%d", &n );

    if( n % 2 != 0)
        resultado = somar(n+2) - somar(n);
    else if ( n % 2 == 0)
        resultado = somar(n-1);

    printf("\n%lf\n", resultado);

    // encerrar
    pause("Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim questao08
