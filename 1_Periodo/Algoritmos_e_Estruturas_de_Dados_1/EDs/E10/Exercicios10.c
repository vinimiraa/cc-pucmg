/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios10 - v0.0. - 26 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios10 Exercicios10.c
 *      Windows: gcc -o Exercicios10 Exercicios10.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios10
 *      Windows: Exercicios10
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio1011();
void exercicio1012();
void exercicio1013();
void exercicio1014();
void exercicio1015();
void exercicio1016();
void exercicio1017();
void exercicio1018();
void exercicio1019();
void exercicio1020();
void exercicio10E1();
void exercicio10E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios10 - v0.0");

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
            exercicio1011();
            break;
        case 2:
            exercicio1012();
            break;
        case 3:
            exercicio1013();
            break;
        case 4:
            exercicio1014();
            break;
        case 5:
            exercicio1015();
            break;
        case 6:
            exercicio1016();
            break;
        case 7:
            exercicio1017();
            break;
        case 8:
            exercicio1018();
            break;
        case 9:
            exercicio1019();
            break;
        case 10:
            exercicio1020();
            break;
        case 11:
            exercicio10E1();
            break;
        case 12:
            exercicio10E2();
            break;
        default:
            pause("ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

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
    printf("%s\n", "  1 - Exercicio 1011");
    printf("%s\n", "  2 - Exercicio 1012");
    printf("%s\n", "  3 - Exercicio 1013");
    printf("%s\n", "  4 - Exercicio 1014");
    printf("%s\n", "  5 - Exercicio 1015");
    printf("%s\n", "  6 - Exercicio 1016");
    printf("%s\n", "  7 - Exercicio 1017");
    printf("%s\n", "  8 - Exercicio 1018");
    printf("%s\n", "  9 - Exercicio 1019");
    printf("%s\n", " 10 - Exercicio 1020");
    printf("%s\n", " 11 - Exercicio 10E1");
    printf("%s\n", " 12 - Exercicio 10E2");
    printf("\n");
} // fim menuOpcoes()

typedef struct s_intArray
{
    int  length;
    int* data  ;
    int  ix    ;
} intArray;

int RandomIntGenerate( int a, int b )
{
    int x = 0;
    while( x < a || b < x )
    {
        x = rand() % 100;
    } // end while
    return( x );
} // end RandomIntGenerate ( )

void printIntArray( intArray array )
{
    
    if ( array.data )
    {
        for ( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            print( "%2d: %d\n", array.ix, array.data[array.ix] );
        } // end for
    } // end if
} // end printIntArray ( )

void fprintIntArray( string fileName, intArray array )
{
    FILE *arquivo = fopen( fileName, "wt" );
    
    fprint( arquivo, "%d\n", array.length );
    
    if ( array.data )
    {
        for ( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            fprint( arquivo, "%d\n", array.data[array.ix] );
        } // end for
    } // end if

    fclose( arquivo );
} // end fprintIntArray ( )

/**
 * Metodo01.
 */
void exercicio1011()
{
    // identificacao
    id("Exercicio 1011:");

    // programa
    int a = 0, b = 0; // intervalos
    int x = 0;        // valor a ser gerado
    intArray array;   // arranjo
    
    a            = readint( "Digite o limite inicial do intervalo: " );
    b            = readint( "Digite o limite final do intervalo  : " );
    array.length = readint( "Digite a quantidade de valores: "       );

    if( a > b )
    { 
        print( "\n%s\n", "ERRO: Valor inicial maior que o valor final." );
    }
    else
    {
        array.data = (int*) malloc ( array.length * sizeof(int) );

        for( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            x = RandomIntGenerate( a, b );
            array.data[array.ix] = x;

        } // end for

        fprintIntArray( "ARRANJO.TXT", array );

        print( "\n%s\n", "Dados gravados no arquivo \"ARRANJO.TXT\". " );
    } // end if

    if( array.data )
    {
        free(array.data);
        array.data = NULL;
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1011

intArray readArrayFromFile( string fileName )
{

    FILE *arquivo = fopen( fileName, "rt" );
    static intArray array;

    if (arquivo)
    {
        fscan( arquivo, "%d", &array.length ); fgetc( arquivo );

        if (array.length <= 0)
        {
            print( "\n%s\n", "ERRO: Tamanho invalido." );
            array.length = 0; 
        }
        else
        {
            array.data = (int*) malloc ( array.length * sizeof(int) );
            
            if ( array.data )
            {
                array.ix = 0; // posicao 0
                while (!feof(arquivo) && array.ix < array.length)
                {
                    fscan(arquivo, "%d", &(array.data[array.ix]));
                    fgetc( arquivo );
                    array.ix = array.ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if
    
    fclose( arquivo );
    
    return (array);
} // end readArrayFromFile ( )

bool searchIntArray( int value, intArray array )
{
    bool resultado = false;
    
    array.ix = 0;
    while ( array.ix < array.length && !resultado )
    {
        if( value == array.data[array.ix] ) 
        {
            resultado = true;
        } // end if
        array.ix = array.ix + 1;
    } // end while

    return ( resultado );
} // end searchIntArray ( )

/**
 * Metodo02.
 */
void exercicio1012()
{
    // identificacao
    id("Exercicio 1012:");

    // programa
    intArray array; // arranjo
    int x = 0;

    array = readArrayFromFile("ARRANJO.TXT");
    
    x = readint ( "Digite o valor a ser procurado: " );

    if ( searchIntArray( x, array ) )
    {
        print( "\n%s\n", "O valor esta no arranjo que esta no arquivo \"ARRANJO.TXT\"." );
    }
    else
    {
        print( "\n%s\n", "O valor nao esta no arranjo que esta no arquivo \"ARRANJO.TXT\".." );
    } // end if

    if( array.data )
    {
        free( array.data );
        array.data = NULL;
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1012

bool intArrayCompare( intArray array1, intArray array2 )
{
    bool resultado = true;
    
    if( array1.length <= 0 || array2.length <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho Invalido." );
    }
    else
    {
        if( array1.length == array2.length )
        {
            array1.ix = 0;
            while ( array1.ix < array1.length /*&& !resultado*/ )
            {
                if( array1.data[array1.ix] != array2.data[array1.ix] )
                {
                    resultado = false;
                } // end if
                array1.ix = array1.ix + 1;
            } // end while
        } // end if
    } // end if

    return ( resultado );
} // end intArrayCompare ( )

/**
 * Metodo03.
 */
void exercicio1013()
{
    // identificacao
    id("Exercicio 1013:");

    // programa
    intArray arranjo1;
    intArray arranjo2;

    arranjo1 = readArrayFromFile( "ARRANJO1.TXT" );
    arranjo2 = readArrayFromFile( "ARRANJO2.TXT" );
    
    print( "%s\n", "Arranjo 1:" );
    printIntArray(arranjo1);
    print("\n%s\n", "Arranjo 2:" );
    printIntArray(arranjo2);

    if( intArrayCompare(arranjo1,arranjo2) )
    {
        print( "\n%s\n", "Os arranjos sao iguais." );
    }
    else
    {    
        print( "\n%s\n", "Os arranjos sao diferentes." );
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1013

intArray intArrayAdd( intArray array1, int k, intArray array2 )
{
    static intArray soma;
    
    if( array1.length <= 0 || array2.length <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho Invalido." );
    }
    else
    {
        if( array1.length == array2.length )
        {
            soma.data = (int*) malloc ( array1.length * sizeof(int) );
            soma.length = array1.length;
            
            if ( soma.data )
            {
                for( soma.ix = 0; soma.ix < soma.length; soma.ix = soma.ix + 1 )
                {
                    soma.data[soma.ix] = array1.data[soma.ix] + array2.data[soma.ix] * k;
                } // end for
            } // end for
        } // end if
    } // end if

    return ( soma );
} // end intArrayAdd ( )

/**
 * Metodo04.
 */
void exercicio1014()
{
    // identificacao
    id("Exercicio 1014:");

    // programa
    intArray arranjo1;
    intArray arranjo2;
    intArray soma;

    arranjo1 = readArrayFromFile( "ARRANJO1.TXT" );
    arranjo2 = readArrayFromFile( "ARRANJO2.TXT" );
    
    soma = intArrayAdd( arranjo1, 1, arranjo2 );

    print( "%s\n", "Soma do arranjo gravado em \"ARRANJO1.TXT\" com o arranjo gravado em \"ARRANJO2.TXT\": " );
    printIntArray( soma );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1014

bool isArrayDecrescent( intArray array )
{
    bool resultado = true;

    if( array.data )
    {
        array.ix = 1;
        while ( array.ix < array.length /*&& !resultado*/ )
        {
            if( array.data[array.ix-1] <= array.data[array.ix] )
            {
                resultado = false;
            } // end if
            // printf( "%d %d %d %d\n", array.ix, array.data[array.ix-1], array.data[array.ix], resultado ); 
            array.ix = array.ix + 1;
        } // end while
    } // end if

    return ( resultado );
} // end isArrayDecrescent ( )

/**
 * Metodo05.
 */
void exercicio1015()
{
    // identificacao
    id("Exercicio 1015:");

    // programa
    intArray arranjo;

    arranjo = readArrayFromFile( "ARRANJO1.TXT" );
    
    print( "%s\n", "Arranjo:" );
    printIntArray ( arranjo );
    
    if( isArrayDecrescent( arranjo ) )
    {
        print( "\n%s\n", "O arranjo e decrescente." );
    }
    else
    {
        print( "\n%s\n", "O arranjo nao e decrescente." );
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1015

typedef struct s_intMatrix
{
    int row;
    int col;
    int** data;
    int ix,iy;
} intMatrix;

void printIntMatrix( intMatrix* matrix )
{
    if (matrix != NULL && matrix->data != NULL)
    {
        for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1)
            {
                printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
            } // end for
            printf("\n");
        } // end for
    } // end if
} // end printIntArray ( )

intMatrix* intMatrix_new( int rows, int cols )
{
    intMatrix *matrix = (intMatrix*) malloc ( 1 * sizeof(intMatrix) );
    
    if( matrix != NULL )
    {
        matrix->row = 0;
        matrix->col = 0;
        matrix->data = NULL;
        
        if ( rows > 0 && cols > 0 )
        {
            matrix->row = rows;
            matrix->col = cols;
            matrix->data = malloc( rows * sizeof(int*) );
            
            if ( matrix->data )
            {
                for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
                {
                    matrix->data[matrix->ix] = (int*) malloc( cols * sizeof(int) );
                } // end for
            } // end if
        } // end if
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if
    return ( matrix );
} // end intMatrix_new

intMatrix* readMatrixFromFile( string filename )
{
    intMatrix* matrix = NULL;
    int rows = 0;
    int cols = 0;
    FILE *arquivo = fopen( filename, "rt" );
    
    if ( arquivo == NULL )
    {
        print( "\n%s\n", "ERRO: Nao foi possivel abrir o aquivo." );
    }
    else
    {
        fscanf(arquivo, "%d", &rows); fgetc( arquivo );
        fscanf(arquivo, "%d", &cols); fgetc( arquivo );

        if (rows <= 0 || cols <= 0)
        {
            print( "\n%s\n", "ERRO: Tamanho invalido." );
        }
        else
        {

            matrix = intMatrix_new( rows, cols );

            if (matrix != NULL && matrix->data == NULL)
            {
                matrix->row = 0;
                matrix->col = 0;
                matrix->ix = 0;
                matrix->iy = 0;
            }
            else
            {
                if (matrix != NULL)
                {
                    matrix->ix = 0;
                    while ( !feof( arquivo ) && matrix->ix < matrix->row )
                    {
                        matrix->iy = 0;
                        while ( !feof( arquivo ) && matrix->iy < matrix->col )
                        {
                            fscanf( arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]) );
                            fgetc( arquivo );
                            matrix->iy = matrix->iy + 1;
                        } // end while
                        matrix->ix = matrix->ix + 1;
                    } // end while
                    matrix->ix = 0;
                    matrix->iy = 0;
                } // end if
            } // end if
        } // end if
    } // end if
    fclose ( arquivo );
    
    return (matrix);
} // end readMatrixFromFile ( ) 

intMatrix* matrixTranspose( intMatrix* matrix ) 
{
    intMatrix* aux = NULL;
    int rows = 0;
    int cols = 0;
    
    // printIntMatrix( matrix );
    
    if( matrix != NULL && matrix->data != NULL )
    {
        rows = matrix->col;
        cols = matrix->row;
        
        // printf("%d %d\n" , rows, cols );
        aux = intMatrix_new( rows, cols );
        
        if( aux != NULL && aux->data != NULL )
        {
            aux->ix = 0;
            while( aux->ix < aux->row )
            {
                aux->iy = 0;
                while( aux->iy < aux->col )
                {
                    // printf( "%d %d %d\n", matrix->ix, matrix->iy, matrix->data[matrix->iy][matrix->ix] );
                    // aux->data[aux->ix][aux->iy] = matrix->data[matrix->iy][matrix->ix]; // antes
                    aux->data[aux->ix][aux->iy] = matrix->data[aux->iy][aux->ix];          // agora
                    aux->iy = aux->iy + 1;
                } // end while
                aux->ix = aux->ix + 1;
            } // end while
        } // end if
    } // end if
    
    return ( aux ) ;
} // end matrixTranspose ( )

void free_intMatrix( intMatrix* matrix )
{
    if (matrix != NULL)
    {
        if (matrix->data != NULL)
        {
            for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
            {
                free(matrix->data[matrix->ix]);
            } // end for
            free(matrix->data);
        } // end if
        free(matrix);
    } // end if
} // end free_int_Matrix ( )

/**
 * Metodo06.
 */
void exercicio1016()
{
    // identificacao
    id("Exercicio 1016:");

    // programa
    intMatrix* matrix1 = NULL;
    intMatrix* transposed = NULL;
    
    matrix1 = readMatrixFromFile( "MATRIZ1.TXT" );
    
    if ( matrix1 != NULL )
    {
        transposed = matrixTranspose( matrix1 );

        if ( transposed != NULL )
        {    
            print( "%s\n", "Matriz:" );
            printIntMatrix( matrix1 );

            print( "\n%s\n", "Matriz Transposta:" );
            printIntMatrix( transposed );
        }
    }

    free_intMatrix( matrix1 );
    free_intMatrix( transposed );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1016

bool isZero_intMatrix ( intMatrix* matrix )
{
    bool resultado = true;

    if( matrix != NULL && matrix->data != NULL )
    {
        matrix->ix = 0;
        while( matrix->ix < matrix->row )
        {
            matrix->iy = 0;
            while( matrix->iy < matrix->col )
            {
                if( matrix->data[matrix->ix][matrix->iy] != 0 )
                {
                    resultado = false;
                } // end if
                matrix->iy = matrix->iy + 1;
            } // end while
            matrix->ix = matrix->ix + 1;
        } // end while
    } // end if

    return ( resultado );
} // end isZero_intMatrix ( )

/**
 * Metodo07.
 */
void exercicio1017()
{
    // identificacao
    id("Exercicio 1017:");

    // programa
    intMatrix* matriz = NULL;

    matriz = readMatrixFromFile( "MATRIZ1.TXT" );

    if( matriz != NULL )
    {
        printIntMatrix( matriz );

        if( isZero_intMatrix( matriz ) )
        {
            print( "\n%s\n", "A matriz so contem valores iguais a zero." );
        }
        else
        {
            print( "\n%s\n", "A matriz contem algum valor diferente de zero." );
        }
    }

    free_intMatrix( matriz );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1017

bool compare_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    bool resultado = true;

    if( matrix1 != NULL && matrix1->data != NULL &&
        matrix2 != NULL && matrix2->data != NULL )
    {
        if( matrix1->row == matrix2->row && matrix1->col == matrix2->col )
        {
            matrix1->ix = 0;
            while( matrix1->ix < matrix1->row )
            {
                matrix1->iy = 0;
                while( matrix1->iy < matrix1->col )
                {
                    if( matrix1->data[matrix1->ix][matrix1->iy] !=
                        matrix2->data[matrix1->ix][matrix1->iy] )
                    {
                        resultado = false;
                    } // end if
                    matrix1->iy = matrix1->iy + 1; 
                } // end while
                matrix1->ix = matrix1->ix + 1; 
            } // end while
        } // end if
    } // end if

    return ( resultado );
} // end compare_intMatrix ( )

/**
 * Metodo08.
 */
void exercicio1018()
{
    // identificacao
    id("Exercicio 1018:");

    // programa
    intMatrix* matriz1 = NULL;
    intMatrix* matriz2 = NULL;

    matriz1 = readMatrixFromFile( "MATRIZ1.TXT" );
    matriz2 = readMatrixFromFile( "MATRIZ2.TXT" );

    if( matriz1 != NULL && matriz2 != NULL )
    {
        print("%s\n", "Matriz 1:");
        printIntMatrix( matriz1 );

        print("\n%s\n", "Matriz 2:");
        printIntMatrix( matriz2 );

        if( compare_intMatrix( matriz1, matriz2 ) )
        {
            print( "\n%s\n", "As matrizes sao iguais." );
        }
        else
        {
            print( "\n%s\n", "As matrizes sao diferentes." );
        }
    }

    free_intMatrix( matriz1 );
    free_intMatrix( matriz2 );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1018 

intMatrix* add_intMatrix( intMatrix* matrix1, int k, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( matrix1 != NULL && matrix1->data != NULL &&
        matrix2 != NULL && matrix2->data != NULL )
    {
        if( matrix1->row == matrix2->row && matrix1->col == matrix2->col )
        {
            aux = intMatrix_new( matrix1->row, matrix1->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] = matrix1->data[aux->ix][aux->iy] +
                                                      matrix2->data[aux->ix][aux->iy] * k;
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end add_intMatrix ( )
/**
 * Metodo10.
 */
void exercicio1019()
{
    // identificacao
    id("Exercicio 1019:");

    // programa
    intMatrix* matriz1 = NULL;
    intMatrix* matriz2 = NULL;
    intMatrix* soma = NULL;
    int k = -1;

    matriz1 = readMatrixFromFile( "MATRIZ1.TXT" );
    matriz2 = readMatrixFromFile( "MATRIZ2.TXT" );

    if( matriz1 != NULL && matriz2 != NULL )
    {
        soma = add_intMatrix( matriz1, k, matriz2 );

        if ( soma != NULL )
        {
            print( "%s\n", "Soma da matriz gravada em \"MATRIZ1.TXT\" com a matriz gravado em \"MATRIZ2.TXT\": " );
            printIntMatrix( soma );
        }
    }

    free_intMatrix( matriz1 );
    free_intMatrix( matriz2 );
    free_intMatrix( soma );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1019


intMatrix* product_intMatrix( intMatrix* matrix1, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( matrix1 != NULL && matrix1->data != NULL &&
        matrix2 != NULL && matrix2->data != NULL )
    {
        if( matrix1->col == matrix2->row  ) 
        {
            aux = intMatrix_new( matrix1->row, matrix2->col );

            if( aux != NULL )
            {
                aux->ix = 0;
                while( aux->ix < aux->row )
                {
                    aux->iy = 0;
                    while( aux->iy < aux->col )
                    {
                        aux->data[aux->ix][aux->iy] = 0;

                        matrix1->ix = 0;
                        while( matrix1->ix < matrix1->col )
                        {
                            aux->data[aux->ix][aux->iy] +=  matrix1->data[aux->ix][matrix1->ix] *
                                                            matrix2->data[matrix1->ix][aux->iy];
                            matrix1->ix = matrix1->ix + 1;
                        } // end while
                        aux->iy = aux->iy + 1;
                    } // end while
                    aux->ix = aux->ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end product_intMatrix ( )

intMatrix* product_intMatrix_a( intMatrix* matrix1, intMatrix* matrix2 )
{
    intMatrix* aux = NULL;

    if( matrix1 != NULL && matrix1->data != NULL &&
        matrix2 != NULL && matrix2->data != NULL )
    {
        if( matrix1->col == matrix2->row  ) 
        {
            aux = intMatrix_new( matrix1->row, matrix2->col );

            if( aux != NULL )
            {
                for ( aux->ix = 0; aux->ix < aux->row; aux->ix++ )
                {
                    for ( aux->iy = 0; aux->iy < aux->col; aux->iy++ )
                    {
                        aux->data[aux->ix][aux->iy] = 0; 
                        for ( matrix1->ix = 0; matrix1->ix < matrix1->col; matrix1->ix++ )
                        {
                            aux->data[aux->ix][aux->iy] +=  matrix1->data[aux->ix][matrix1->ix] * 
                                                            matrix2->data[matrix1->ix][aux->iy];
                        } // end for
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if

    return ( aux );
} // end product_intMatrix ( )
/**
 * Metodo10.
 */
void exercicio1020()
{
    // identificacao
    id("Exercicio 1020:");

    // programa
    intMatrix* matrix1 = NULL;
    intMatrix* matrix2 = NULL;
    intMatrix* produto = NULL;

    matrix1 = readMatrixFromFile( "MATRIZ1.TXT" );
    matrix2 = readMatrixFromFile( "MATRIZ2.TXT" );

    if( matrix1 != NULL && matrix2 != NULL )
    {
        produto = product_intMatrix( matrix1, matrix2 );

        if( produto != NULL )
        {    print( "%s\n", "Produto da matriz gravada em \"MATRIZ1.TXT\" com a matriz gravado em \"MATRIZ2.TXT\": " );
            printIntMatrix( produto );
        }
    }

    free_intMatrix( matrix1 );
    free_intMatrix( matrix2 );
    free_intMatrix( produto );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1020

int get_intArray( intArray* array, int index)
{
    int value = -1;

    if( array->data && (0 <= index && index < array->length) )
    {
        value = array->data[ index ];
    } // end if

    return (value);
} // end  get_intArray ( )

void set_intArray( intArray* array, int index, int value )
{

    if( array->data && (0 <= index && index < array->length) )
    {
        array->data[ index ] = value;
    } // end if

} // end set_intArray ( )

void intArray_init( intArray* a, int n, int initial_value )
{
    int x = 0;

    if ( n > 0 )
    {
        a->length = n;
        a->data = malloc( a->length * sizeof( int ) );
        if ( a->data )
        {
            for ( x = 0; x < a->length; x = x + 1 )
            {
                a->data[x] = initial_value;
            }
        } // end if
   } // end if
} // end intArray_init ( )

intArray* new_intArray( int n, int initial_value )
{
    // int x = 0;
    intArray* a = NULL;

    if ( n > 0 )
    {
        a = malloc( 1 * sizeof( intArray ) );
        if ( a ) 
        {
            intArray_init( a, n, initial_value );
        } // end if
   } // end if
    return ( a );
} // end new_intArray ( )

void free_intArray ( intArray* a )
{

    if ( a )
    {
        a->length = 0;
        free ( a->data );
        a->data   = NULL;
        a         = NULL; 
    } // end if 
} // end intArray_delete ( )

void print_intArray( intArray* a )
{

    for (a->ix = 0; a->ix < a->length; a->ix = a->ix + 1)
    {
        printf("%2d: %d\n", a->ix, a->data[a->ix]);
    } // end for

} // end intArray_print ( )

intArray* readArrayFromFile_a( string filename )
{
    intArray* aux = NULL;
    int n = 0;
    int x = 0;
    FILE *arquivo = fopen(filename, "rt");

    if( arquivo == NULL )
    {
        print( "\n%s\n", "ERRO: Nao foi possivel abrir o arquivo" );
    }
    else
    {   
        fscan( arquivo, "%d", &n ); fgetc(arquivo);

        if( n > 0)
        {
            aux = new_intArray( n, 0 );

            if( aux != NULL )
            {
                for( aux->ix = 0; aux->ix < aux->length; aux->ix = aux->ix + 1 )
                {
                    fscan( arquivo, "%d", &x ); fgetc(arquivo);
                    aux->data[aux->ix] = x;
                } // end for
            } // end if
        } // end if
    } // end if

    fclose(arquivo);

    return ( aux );
} // readArrayFromFile_a ( )

void sortup_intArray( intArray* array )
{
    int  x     = 0;
    int  y     = 0;
    int  value = 0;

    if ( array )
    {
        for ( x = 1; x < array->length; x = x+1 )    // (n-1) vezes
        {
            for ( y = 1; y < array->length; y = y+1 ) // (n-1) testes
            {
                if ( get_intArray ( array, y-1 ) > get_intArray ( array, y ) )
                {
                    value        = get_intArray ( array, y );
                    set_intArray ( array, y, get_intArray ( array, y-1 ) );
                    set_intArray ( array, y-1, value );
                } // end if
            } // end for
       } // end if
    } // end for
} // end sortup_intArray ( )

/**
 * Metodo11.
 */
void exercicio10E1()
{
    // identificacao
    id("Exercicio 10E1:");

    // programa
    intArray* arranjo;

    arranjo = readArrayFromFile_a( "ARRANJO1.TXT" );

    if( arranjo != NULL)
    {
        sortup_intArray( arranjo );

        print( "%s\n", "Arranjo ordenado em ordem crescente:" );
        print_intArray( arranjo );
    }

    free_intArray( arranjo );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio10E1

bool isIdentity_intMatrix( intMatrix* matrix )
{
    bool resultado = true;

    if( matrix != NULL && matrix->data != NULL )
    {
        if( matrix->row == matrix->col )
        {
            for( matrix->ix = 0; matrix->ix < matrix->row; matrix->ix++ )
            {
                for( matrix->iy = 0; matrix->iy < matrix->row; matrix->iy++ )
                {
                    if( matrix->data[matrix->ix][matrix->ix] != 1)
                    {
                        if( matrix->data[matrix->ix][matrix->iy] != 0)
                        {
                            resultado = false;
                        } // end if
                    } // end if
                } // end for
            } // end for
        } // end if
    } // end if

    return ( resultado );
}
/**
 * Metodo12.
 */
void exercicio10E2()
{
    // identificacao
    id("Exercicio 10E2:");

    // programa
    intMatrix* matrix1 = NULL;
    intMatrix* matrix2 = NULL;
    intMatrix* produto = NULL;

    matrix1 = readMatrixFromFile( "MATRIZ1.TXT" );
    matrix2 = readMatrixFromFile( "MATRIZ2.TXT" );

    if ( matrix1 != NULL && matrix2 != NULL )
    {
        produto = product_intMatrix( matrix1, matrix2 );

        if( produto != NULL )
        {
            print( "%s\n", "Matriz Produto: " );
            printIntMatrix( produto );

            if( isIdentity_intMatrix( produto ) )
            {
                print( "\n%s\n", "O produto das duas matrizes e uma matriz identidade" );
            }
            else
            {
                print( "\n%s\n", "O produto das duas matrizes nao e uma matriz identidade" );
            }
        }
    }

    free_intMatrix( matrix1 );
    free_intMatrix( matrix2 );
    free_intMatrix( produto );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio10E2