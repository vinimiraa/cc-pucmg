/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Avaliacao_02 - v0.0. - 20 / 11 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Avaliacao_02 Avaliacao_02.c
 *      Windows: gcc -o Avaliacao_02 Avaliacao_02.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Avaliacao_02
 *      Windows: Avaliacao_02
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void questao_01();
void questao_02();
void questao_03();
void questao_04();
void questao_05();
void questao_06();
void questao_07();
void questao_08();
void questao_09();
void questao_00();
void questao_01();
void questao_02();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Avaliação_02 - v0.0");

        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch (opcao)
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            questao_01();
            break;
        case 2:
            questao_02();
            break;
        case 3:
            questao_03();
            break;
        case 4:
            questao_04();
            break;
        case 5:
            questao_05();
            break;
        case 6:
            questao_06();
            break;
        case 7:
            questao_07();
            break;
        case 8:
            questao_08();
            break;
        default:
            pause("ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

    return (0);
}

// -------------------------- definicao de metodos

int q01( char* text )
{
    int x = strlen( text ) / 2, y = 0;
    if( text[x] == '-' ) x = x - 1;
    while( y < x && text[y] == text[x + y + 2] ) { y = y + 1; }
    return ( y-x );
}
/**
 * Metodo01.
 */
void questao_01()
{
    // identificacao
    id("Questao 01:");

    // programa
    printf( "Resultado = %d\n", q01( "teco-teco" ) ); 

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_01

void q02( int x, int n, int a[ ] )
{
    if( x < n/2 && a[x] - a[n/2 + x] < 0 )
    {
        a[0] = a[x]; a[x] = a[n/2 + x]; a[n/2 + x] = a[0]; a[0] = 0;
        q02( x+1, n, a );
    }
}
/**
 * Metodo02.
 */
void questao_02()
{
    // identificacao
    id("Questao 02:");

    // programa
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    int n = 8;
    int x = 1;

    q02( x, n, a );

    printf( "Resultado = " );
    for( int i = 0; i < n; i = i + 1 )
    {
        printf( "%d ", a[i] );
    }
    printf( "\n" );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_02

void q03( int m, int n, int a[ ][ n ] )
{
    int v = 0, w = 1, x = 1, y = 0;
    while( x < n )
    {   
        y = 0; v = a[x][y];
        while( y < n )
        {   a[x][y] = (-v*a[x-w][y] + a[x][y]); y = y + 1;   }
        x = x + 1; w = w + 1;
    }
}
/**
 * Metodo03.
 */
void questao_03()
{
    // identificacao
    id("Questao 03:");

    // programa
    int a[ ][ 3 ] = { {1,2,3}, {4,5,6}, {7,8,9} };

    q03( 3, 3, a );

    for( int x = 0; x < 3; x = x + 1 )
    {
        for( int y = 0; y < 3; y = y + 1 )
        {
            printf( "%d\t", a[x][y]);
        }
        printf("\n");
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_03

struct s { int nc; char *c; }a;
void q04( struct s c )
{
    int x = c.nc - 1;
    if ( x >= 0 )
    {
        c.c = calloc( c.nc + 1, sizeof( char ) );
        while( x >= 0 )
        {
            if( x % 2 != 0 && x != c.nc - 1 ) 
                c.c[x] = '-';
            else if( x % 2 == 0 ) 
                c.c[x] = '*'; 
            
            x = x - 1;
        }
        if( c.nc % 2 == 0 )
            printf( "%d %s\n", c.nc, c.c );
    }
}
/**
 * Metodo04.
 */
void questao_04()
{
    // identificacao
    id("Questao 04:");

    // programa
    int x = 0;
    for( x = 0; x < 9; x = x + 1 ) { a.nc = x; q04( a ); }

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_04

void q05( int *m, int *n )
{
    m[1] = *n;
    while( *n > 1 )
    {
        *m = *m + 1;
        *n = *n / 2; 
    }
}
/**
 * Metodo05.
 */
void questao_05()
{
    // identificacao
    id("Questao 05:");

    // programa
    int *m = malloc( 2 * sizeof( int ) ); int n = 129;

    m[0] = *m - *m; *( m + 1 ) = n;

    q05( m, &n );

    printf( "m = {%d,%d} n = %d\n", *m, m[1], n );
    
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_05

void q06( int n, int array[] )
{
    int maior1 = 0, maior2 = 0, aux = 0;
    if( n > 2 )
    {
        maior1 = array[0];
        maior2 = array[1];

        if ( maior1 < maior2 )
        {
            aux = maior1;
            maior1 = maior2;
            maior2 = aux;
        }

        for( int x = 2; x < n; x = x + 1 )
        {
            if ( array[x] > maior1 )
            {
                maior2 = maior1;
                maior1 = array[x];
            } else if ( array[x] > maior2 && array[x] != maior1 )
            {
                maior2 = array[x];
            }
        }
        printf( "Maior 1 = %d, Maior 2 = %d\n", maior1, maior2 );
    }
}
/**
 * Metodo06.
 */
void questao_06()
{
    // identificacao
    id("Questao 06:");

    // programa
    int a[ ] = { 3,1,5,2,4 };
    int b[ ] = { 3,1,5,2,5 };

    q06( 5, a );
    q06( 5, b );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_06

void q07( int row, int col, int matriz[ ][ col ] )
{
    int maior = 0;
    int aux = 0;

    int x = 0, y = 0;
    if( row > 0 && col > 0 )
    {
        for( x = 0; x < row; x = x + 1 )
        {
            maior = matriz[x][x];
            for( y = 0; y < col; y = y + 1 )
            {
                if (matriz[x][y] > maior)
                {
                    aux = matriz[x][x];
                    matriz[x][x] = matriz[x][y];
                    matriz[x][y] = aux;
                }
            }
        }
    }
}
/**
 * Metodo07.
 */
void questao_07()
{
    // identificacao
    id("Questao 07:");

    // programa
    int m[][3] = { {1,2,3}, {6,5,4}, {7,9,8} };

    printf("Original:\n");
    for( int x = 0; x < 3; x = x + 1 )
    {
        for( int y = 0; y < 3; y = y + 1 )
        {
            printf( "%d\t", m[x][y] );
        }
        printf( "\n" );
    }

    q07( 3, 3, m );

    printf("\nAlterada:\n");
    for( int x = 0; x < 3; x = x + 1 )
    {
        for( int y = 0; y < 3; y = y + 1 )
        {
            printf( "%d\t", m[x][y] );
        }
        printf( "\n" );
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_07

typedef struct s_Boleto
{
    int    dia;
    int    mes;
    int    ano;
    double val;
} Boleto;
/*
void fprint_Boletos( char* filename, Boleto boletos[ ] )
{
    FILE *file = fopen( filename, "wt" );

    for( int x = 0; x < 10; x = x + 1 )
    {
        fprintf( file, "%d\n" , boletos[x].dia );
        fprintf( file, "%d\n" , boletos[x].mes );
        fprintf( file, "%d\n" , boletos[x].ano );
        fprintf( file, "%lf\n", boletos[x].val );
    }

    fclose( file );
}

Boleto* fread_Boletos( char* filename )
{
    FILE *file = fopen( filename, "rt" );
    Boleto boletos[10];
    int x = 0, y = 0;
    int data = 0; double valor = 0.0;

    if( file == NULL )
    {
        printf( "\n%s\n", "ERRO: Unable to open the file." );
    }
    else
    {
        x = 0;
        while( !feof( file ) )
        {
            y = 0;
            while( y < 3 )
            {
                fscanf( file, "%d", &data ); fgetc( file );
                if( data / 1000 == 2 )
                    boletos[x].ano = data;
                else if( 1 <= data && data <= 12 )
                    boletos[x].mes = data;
                else
                    boletos[x].dia = data;
                y++;
            }
            fscanf( file, "%lf", &valor ); fgetc( file );
            boletos[x].val = valor;
        }

        fclose( file );
        return ( boletos );
        
    }
}
*/
/**
 * Metodo08.
 */
void questao_08()
{
    // identificacao
    id("Questao 08:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim questao_08

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
