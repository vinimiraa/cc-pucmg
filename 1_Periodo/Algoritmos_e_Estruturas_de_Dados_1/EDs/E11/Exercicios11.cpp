/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios11 - v0.0. - 31 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios11 Exercicios11.cpp
 *      Windows: gcc -o Exercicios11 Exercicios11.cpp
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios11
 *      Windows: Exercicios11
 *
 */

// -------------------------- lista de dependencias

#include <libshow.hpp>
#include "myarray.hpp"

using namespace std;

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 *  Metodo01.
 */
void exercicio1111( void )
{
    // identificacao
    id( "Exercicio 1111:" );

    // programa
    Array<int> arranjo; // classe
    int a = 0, b = 0; // intervalos
    string filename = "DADOS.TXT";

    a =  readint( "Digite o inicio do intervalo: " );
    b =  readint( "Digite o final do intervalo : " );
    arranjo.setLength( readint( "Digite o tamanho do arranjo: " ) );

    if( a > b )
    {
        cout << endl << "ERRO: Limites do Intervalo Invalidos." << endl;
    }
    else
    {
        arranjo.RandomIntGenerate( a, b );

        arranjo.print( );

        arranjo.fprint( filename );

        cout << endl << "Dados gravados em " << filename << "." << endl;
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1111 (  )

/**
 *  Metodo02.
 */
void exercicio1112( void )
{
    // identificacao
    id( "Exercicio 1112:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    int maior = 0;
    
    arranjo.fread ( filename );

    maior = arranjo.searchFirstEven( );

    arranjo.print( );
    
    cout << "O maior valor par do arquivo " << filename << " e = " << maior << "." << endl;

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1112 (  )

/**
 *  Metodo03.
 */
void exercicio1113( void )
{
    // identificacao
    id( "Exercicio 1113:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    int menor = 0;

    arranjo.fread( filename );

    menor = arranjo.searchFirstOdd( );

    arranjo.print( );

    cout << "O menor valor impar do arquivo " << filename << " e = " << menor << "." << endl;
    
    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1113 (  )

/**
 *  Metodo04.
 */
void exercicio1114( void )
{
    // identificacao
    id( "Exercicio 1114:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    int soma = 0;
    int a= 0, b = 0;

    arranjo.fread( filename );

    a = readint( "Digite o inicio do intervalo: " );
    b = readint( "Digite o final do intervalo : " );

    if ( a > b )
    {
        cout << endl << "ERRO: Limites do Intervalo Invalidos." << endl;
    }
    else
    {
        soma = arranjo.addInterval( a, b );
        arranjo.print( );
        cout << endl << "Soma dos valores do arranjo entre as posicoes dadas e = " << soma << endl;
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1114 (  )

/**
 *  Metodo05.
 */
void exercicio1115( void )
{
    // identificacao
    id( "Exercicio 1115:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    double media = 0.0;
    int a = 0, b = 0;

    arranjo.fread( filename );

    a = readint( "Digite o inicio do intervalo: " );
    b = readint( "Digite o final do intervalo : " );

    if ( a > b )
    {
        cout << endl << "ERRO: Limites do Intervalo Invalidos." << endl;
    }
    else
    {
        media = arranjo.averageInterval( a, b );
        arranjo.print( );
        cout << endl << "A media dos valores do arranjo entre as posicoes dadas e = " << media << endl;
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1115 (  )

/**
 *  Metodo06.
 */
void exercicio1116( void )
{
    // identificacao
    id( "Exercicio 1116:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    
    arranjo.fread( "DADOS.TXT" );

    arranjo.print( );

    if ( arranjo.positives( ) )
    {
        cout << "O arranjo so tem valores positivos." << endl;
    }
    else
    {
        cout << "O arranjo tem valor negativo." << endl;
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1116 (  )

/**
 *  Metodo07.
 */
void exercicio1117( void )
{
    // identificacao
    id( "Exercicio 1117:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    
    arranjo.fread( "DADOS.TXT" );

    arranjo.print( );

    if ( arranjo.isCrescent( ) )
    {
        cout << "Os valores do arranjo estao em ordem crescente." << endl;
    }
    else
    {
        cout << "Os valores do arranjo nao estao em ordem." << endl;
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1117 (  )

/**
 *  Metodo08.
 */
void exercicio1118( void )
{
    // identificacao
    id( "Exercicio 1118:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";
    int a = 0, b = 0; // intervalos
    int x = 0;        // valor
    
    arranjo.fread( "DADOS.TXT" );

    a = readint( "Digite o inicio do intervalo: " );
    b = readint( "Digite o final do intervalo : " );
    x = readint( "Digite o valor a ser procurado: " );

    arranjo.print( );

    if ( a > b )
    {
        cout << endl << "ERRO: Limites do Intervalo Invalidos." << endl;
    }
    else
    {
        if ( arranjo.searchInterval( x, a, b ) )
        {
            cout << "O valor esta presente no arranjo entre as duas posicoes indicadas." << endl;
        }
        else
        {
            cout << "O valor nao esta presente no arranjo entre as duas posicoes indicadas." << endl;
        }
    }

    arranjo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1118 (  )

/**
 *  Metodo11.
 */
void exercicio1119( void )
{
    // identificacao
    id( "Exercicio 1119:" );

    // programa
    Array<int> arranjo;
    Array<int> novo;
    string filename = "DADOS.TXT";
    int a = 0, b = 0; // intervalos
    int k = 0;        // constante

    arranjo.fread( filename );

    a = readint( "Digite o inicio do intervalo: " );
    b = readint( "Digite o final do intervalo : " );
    k = readint( "Digite a constante: " );

    if ( a > b )
    {
        cout << endl << "ERRO: Limites do Intervalo Invalidos." << endl;
    }
    else
    {
        novo = arranjo.scalar( k, a, b );
        novo.print( );
    }

    arranjo.free();
    novo.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1119 (  )

/**
 *  Metodo10.
 */
void exercicio1120( void )
{
    // identificacao
    id( "Exercicio 1120:" );

    // programa
    Array<int> arranjo;
    string filename = "DADOS.TXT";

    arranjo.fread( filename );

    cout << "Antes da Ordenacao:" << endl;
    arranjo.print( );

    arranjo.sortUp( );

    cout << "Depois de Ordenar:" << endl;
    arranjo.print( );

    arranjo.free( );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1120 (  )

/**
 *  Metodo11.
 */
void exercicio11E1( void )
{
    // identificacao
    id( "Exercicio 11E1:" );

    // programa
    int other1 [ ] = { 1, 2, 3, 4, 5 };
    int other2 [ ] = { 1, 2, 6, 4, 5 };
    Array<int> arranjo1( 5, other1 );
    Array<int> arranjo2( 5, other2 );

    cout << "Arranjo 1: " << endl;
    arranjo1.print( );
    cout << "Arranjo 2: " << endl;
    arranjo2.print( );

    if ( arranjo1 != arranjo2 )
    {
        cout << "Os arranjos sao diferentes em pelo menos uma posicao." << endl;
    }
    else
    {
        cout << "Os arranjos sao iguais em todas as posicoes." << endl;
    }

    arranjo1.free( );
    arranjo2.free( );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio11E1 (  )

/**
 *  Metodo12.
 */
void exercicio11E2( void )
{
    // identificacao
    id( "Exercicio 11E2:" );

    // programa
    Array<int> arranjo1;
    Array<int> arranjo2;
    Array<int> arranjo3;

    arranjo1.fread( "DADOS.TXT" );

    arranjo2 = arranjo1.scalar( 3, 0, arranjo1.getLength( ) );

    arranjo3 = arranjo1 - arranjo2;

    cout << "Arranjo 1: " << endl;
    arranjo1.print( );
    
    cout << "Arranjo 2: " << endl;
    arranjo2.print( );

    cout << "Diferenca: Arranjo 1 menos Arranjo 2:" << endl;
    arranjo3.print( );

    arranjo1.free( );
    arranjo2.free( );
    arranjo3.free( );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio11E2 (  )

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 1111    " << std::endl;
    std::cout << "  2 - Exercicio 1112    " << std::endl;
    std::cout << "  3 - Exercicio 1113    " << std::endl;
    std::cout << "  4 - Exercicio 1114    " << std::endl;
    std::cout << "  5 - Exercicio 1115    " << std::endl;
    std::cout << "  6 - Exercicio 1116    " << std::endl;
    std::cout << "  7 - Exercicio 1117    " << std::endl;
    std::cout << "  8 - Exercicio 1118    " << std::endl;
    std::cout << "  9 - Exercicio 1119    " << std::endl;
    std::cout << " 10 - Exercicio 1120    " << std::endl;
    std::cout << " 11 - Exercicio 11E1    " << std::endl;
    std::cout << " 12 - Exercicio 11E2    " << std::endl;
    std::cout << std::endl;
} // fim menuOpcoes()

// -------------------------- definicao do metodo principal

int main( void )
{
    int opcao = 0;

    do
    {
        clearscreen(  );

        // mostrar identificacao do autor e programa
        id( "Programa: Exercicios11 - v0.0" );

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
            exercicio1111(  );
            break;
        case 2:
            exercicio1112(  );
            break;
        case 3:
            exercicio1113(  );
            break;
        case 4:
            exercicio1114(  );
            break;
        case 5:
            exercicio1115(  );
            break;
        case 6:
            exercicio1116(  );
            break;
        case 7:
            exercicio1117(  );
            break;
        case 8:
            exercicio1118(  );
            break;
        case 9:
            exercicio1119(  );
            break;
        case 10:
            exercicio1120(  );
            break;
        case 11:
            exercicio11E1(  );
            break;
        case 12:
            exercicio11E2(  );
            break;
        default:
            pause( "ERRO: opcao invalida!" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}