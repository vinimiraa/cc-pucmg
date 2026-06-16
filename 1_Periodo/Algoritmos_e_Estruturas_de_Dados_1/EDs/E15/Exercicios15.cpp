/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios15 - v0.0. - 27 / 11 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios15 Exercicios15.cpp
 *      Windows: gcc -o Exercicios15 Exercicios15.cpp
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios15
 *      Windows: Exercicios15
 *
 */

// -------------------------- lista de dependencias

#include "libs/libshow.hpp"
#include "libs/cstring.hpp"
#include "libs/intArray.hpp"

using namespace std;

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 *  Metodo01.
 */
void exercicio1511( void )
{
    // identificacao
    id( "Exercicio 1511:" );

    // programa
    char s[] = "ABCD";
    String s0;
    String s1( s );
    char c = 0;
    
    s0.set_str( readstring( "Digite uma string: " ) );
    c = readchar( "Digite o novo caractere: " );
    
    cout << endl;
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;
    
    s0.str_push_back_2( c );
    s1.str_push_back( c );
    
    cout << "S0 Push Back: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1 Push Back: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1511 (  )

/**
 *  Metodo02.
 */
void exercicio1512( void )
{
    // identificacao
    id( "Exercicio 1512:" );

    // programa
    char s[] = "ABCD";
    String s0;
    String s1( s );
    
    s0.set_str( readstring( "Digite uma string: " ) );
    
    cout << endl;
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;
    
    s0.str_pop_back( );
    s1.str_pop_back( );
    
    cout << "S0 Pop Back: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1 Pop Back: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1512 (  )

/**
 *  Metodo03.
 */
void exercicio1513( void )
{
    // identificacao
    id( "Exercicio 1513:" );

    // programa
    char s[] = "ABCD";
    String s0;
    String s1( s );
    char c = 0;
    
    s0.set_str( readstring( "Digite uma string: " ) );
    c = readchar( "Digite o novo caractere: " );
    
    cout << endl;
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;

    s0.str_push_front( c );
    s1.str_push_front( c );
    
    cout << "S0 Push Front: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1 Push Front: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1513 (  )

/**
 *  Metodo04.
 */
void exercicio1514( void )
{
    // identificacao
    id( "Exercicio 1514:" );

    // programa
    char s[] = "ABCD";
    String s0;
    String s1( s );
    
    s0.set_str( readstring( "Digite uma string: " ) );
    
    cout << endl;
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;

    s0.str_pop_front( );
    s1.str_pop_front( );
    
    cout << "S0 Pop Front: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1 Pop Front: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1514 (  )

/**
 *  Metodo05.
 */
void exercicio1515( void )
{
    // identificacao
    id( "Exercicio 1515:" );

    // programa
    char s[] = "ABCD";
    char *a = nullptr;
    String s0;
    String s1( s );
    char c = 0;

    s0.set_str( readstring( "Digite uma string: " ) );
    c = readchar( "Digite o caractere a ser procurado: " );
    
    cout << endl;
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;
    
    a = s0.str_chr( c );
    
    if( a )
        cout << "S0: " << a << endl;
    else
        cout << "S0: []" << endl;
    
    a = s1.str_chr( c );
    
    if( a )
        cout << "S1: " << a << endl;
    else
        cout << "S1: []" << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1515 (  )

/**
 *  Metodo06.
 */
void exercicio1516( void )
{
    // identificacao
    id( "Exercicio 1516:" );

    // programa
    char s[] = "ABCD";
    char *a = nullptr;
    String s0;
    String s1( s );
    char c = 0;

    s0.set_str( readstring( "Digite uma string: " ) );
    c = readchar( "Digite um delimitador: " );
    
    cout << "S0: " << s0.get_str() << " ( " << s0.get_size() << "/" << s0.get_capacity() << " ) " << endl;
    cout << "S1: " << s1.get_str() << " ( " << s1.get_size() << "/" << s1.get_capacity() << " ) " << endl << endl;
    
    a = s0.str_tok( c );
    
    if( a )
        cout << "S0: " << a << endl;
    else
        cout << "S0: []" << endl;
    
    a = s1.str_tok( c );
    
    if( a )
        cout << "S1: " << a << endl;
    else
        cout << "S1: []" << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1516 (  )

/**
 *  Metodo07.
 */
void exercicio1517( void )
{
    // identificacao
    id( "Exercicio 1517:" );

    // programa
    intArray* array1 = nullptr;
    intArray* array2 = nullptr;
    int x = 0;
    
    cout << "Arranjo 1: " << endl;
    array1 = read_intArray( ); cout << endl;
    cout << "Arranjo 2: " << endl;
    array2 = read_intArray( ); cout << endl;
    
    x = intArray_cmp( array1, array2 );
    
    cout << "Comparacao = " <<  x << endl;
    
    delete_intArray( array1 );
    delete_intArray( array2 );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1517 (  )

/**
 *  Metodo08.
 */
void exercicio1518( void )
{
    // identificacao
    id( "Exercicio 1518:" );

    // programa
    intArray* array1 = nullptr;
    intArray* array2 = nullptr;
    intArray* concat = nullptr;
    
    cout << "Arranjo 1: " << endl;
    array1 = read_intArray( ); cout << endl;
    cout << "Arranjo 2: " << endl;
    array2 = read_intArray( ); cout << endl;
    
    concat = intArray_cat( array1, array2 );
    
    cout << "Arranjos Concatenados: " << endl;
    print_intArray( concat );
    
    delete_intArray( array1 );
    delete_intArray( array2 );
    delete_intArray( concat );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1518 (  )

/**
 *  Metodo15.
 */
void exercicio1519( void )
{
    // identificacao
    id( "Exercicio 1519:" );

    // programa
    intArray* array1 = nullptr;
    intArray* array2 = nullptr;
    int x = 0;
    
    cout << "Arranjo 1: " << endl;
    array1 = read_intArray( );
    cout << endl;

    array2 = new_intArray( array1->length );

    x = readint( "Digite o valor a ser procurado: ");
    
    array2 = intArray_seek( array1, x );
    
    if( array2 )
    {
        cout << endl << "Arranjo para a primeira ocorrencia: ";
        print_intArray( array2 );
    }
    else
        cout << endl << "array[]" << endl;
    
    delete_intArray( array1 );
    delete_intArray( array2 );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1519 (  )

/**
 *  Metodo10.
 */
void exercicio1520( void )
{
    // identificacao
    id( "Exercicio 1520:" );

    // programa
    intArray* array1 = nullptr;
    intArray* result = nullptr;
    int start = 0, end = 0;

    array1 = read_intArray( ); cout << endl;
    start = readint( "Digite a posicao inicial: " );
    end = readint( "Digite a posicao final: " );

    result = intArray_sub( array1, start, end );

    cout << endl << "Sequencia separada: ";
    print_intArray( result );

    delete_intArray( array1 );
    delete_intArray( result );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1520 (  )

/**
 *  Metodo11.
 */
void exercicio15E1( void )
{
    // identificacao
    id( "Exercicio 15E1:" );

    // programa
    intArray* array1 = nullptr;
    intArray* array2 = nullptr;
    intArray* result = nullptr;

    cout << "Arranjo 1: " << endl;
    array1 = read_intArray( ); cout << endl;
    cout << "Arranjo 2: " << endl;
    array2 = read_intArray( ); cout << endl;

    result = intArray_merge( array1, array2 );

    cout << "Arranjos Intercalados: "; 
    print_intArray( result );

    delete_intArray( array1 );
    delete_intArray( array2 );
    // delete_intArray( result );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio15E1 (  )

/**
 *  Metodo12.
 */
void exercicio15E2( void )
{
    // identificacao
    id( "Exercicio 15E2:" );

    // programa
    intArray* array1 = nullptr;
    intArray* array2 = nullptr;
    intArray* result = nullptr;

    cout << "Arranjo 1: " << endl;
    array1 = read_intArray( ); cout << endl;
    cout << "Arranjo 2: " << endl;
    array2 = read_intArray( ); cout << endl;

    result = intArray_mergeUp( array1, array2 );

    cout << "Arranjos Intercalados em Ordem Crescente: "; 
    print_intArray( result );

    delete_intArray( array1 );
    delete_intArray( array2 );
    delete_intArray( result );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio15E2 (  )

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 1511    " << std::endl;
    std::cout << "  2 - Exercicio 1512    " << std::endl;
    std::cout << "  3 - Exercicio 1513    " << std::endl;
    std::cout << "  4 - Exercicio 1514    " << std::endl;
    std::cout << "  5 - Exercicio 1515    " << std::endl;
    std::cout << "  6 - Exercicio 1516    " << std::endl;
    std::cout << "  7 - Exercicio 1517    " << std::endl;
    std::cout << "  8 - Exercicio 1518    " << std::endl;
    std::cout << "  9 - Exercicio 1519    " << std::endl;
    std::cout << " 10 - Exercicio 1520    " << std::endl;
    std::cout << " 11 - Exercicio 15E1    " << std::endl;
    std::cout << " 12 - Exercicio 15E2    " << std::endl;
    std::cout << std::endl;
} // fim menuOpcoes()

// -------------------------- definicao do metodo principal

int main( void )
{
    int opcao = 0;

    do
    {
        // limpar a saida de dados
        clearscreen(  );

        // mostrar identificacao do autor e programa
        id( "Programa: Exercicios15 - v0.0" );

        // mostrar menu de opcoes
        menuOpcoes(  );

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch ( opcao )
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            exercicio1511(  );
            break;
        case 2:
            exercicio1512(  );
            break;
        case 3:
            exercicio1513(  );
            break;
        case 4:
            exercicio1514(  );
            break;
        case 5:
            exercicio1515(  );
            break;
        case 6:
            exercicio1516(  );
            break;
        case 7:
            exercicio1517(  );
            break;
        case 8:
            exercicio1518(  );
            break;
        case 9:
            exercicio1519(  );
            break;
        case 10:
            exercicio1520(  );
            break;
        case 11:
            exercicio15E1(  );
            break;
        case 12:
            exercicio15E2(  );
            break;
        default:
            pause( "ERRO: opcao invalida" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}
