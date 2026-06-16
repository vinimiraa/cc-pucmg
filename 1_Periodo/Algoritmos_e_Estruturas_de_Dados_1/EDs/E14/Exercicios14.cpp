/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios14 - v0.0. - 22 / 11 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios14 Exercicios14.cpp
 *      Windows: gcc -o Exercicios14 Exercicios14.cpp
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios14
 *      Windows: Exercicios14
 *
 */

// -------------------------- lista de dependencias

#include "libs/libshow.hpp"
#include "libs/MyString.hpp"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 *  Metodo01.
 */
void exercicio1411( void )
{
    // identificacao
    id( "Exercicio 1411:" );

    // programa
    MyString s;
    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tInteiro: " << s.getInt( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1411 (  )

/**
 *  Metodo02.
 */
void exercicio1412( void )
{
    // identificacao
    id( "Exercicio 1412:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tReal: " << s.getDouble( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1412 (  )

/**
 *  Metodo03.
 */
void exercicio1413( void )
{
    // identificacao
    id( "Exercicio 1413:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tBoolean: " << s.getBoolean( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1413 (  )

/**
 *  Metodo04.
 */
void exercicio1414( void )
{
    // identificacao
    id( "Exercicio 1414:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    if( s.contains( readstring( "Digite a substring a ser procurada: " ) ) )
    {
        cout << endl << "A string esta contida na string original." << endl;
    }
    else
    {
        cout << endl << "A string nao esta contida na string original." << endl;
    }
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1414 (  )

/**
 *  Metodo05.
 */
void exercicio1415( void )
{
    // identificacao
    id( "Exercicio 1415:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tMaiuscula: " << s.toUpperCase( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1415 (  )

/**
 *  Metodo06.
 */
void exercicio1416( void )
{
    // identificacao
    id( "Exercicio 1416:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tMinuscula: " << s.toLowerCase( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1416 (  )

/**
 *  Metodo07.
 */
void exercicio1417( void )
{
    // identificacao
    id( "Exercicio 1417:" );

    // programa
    MyString s;
    char novo = '\0', original = '\0'; 

    s.setString( readstring( "Digite uma string: " ) );
    
    original = readchar( "Digite o caractere a ser trocado: " );

    novo = readchar( "Digite o novo caractere a ser colocado: " );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tNova String: " 
        << s.replace( original, novo ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1417 (  )

/**
 *  Metodo08.
 */
void exercicio1418( void )
{
    // identificacao
    id( "Exercicio 1418:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tCodificada: " << s.encrypt( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1418 (  )

/**
 *  Metodo14.
 */
void exercicio1419( void )
{
    // identificacao
    id( "Exercicio 1419:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << "\tDecodificada: " << s.decrypt( ) << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1419 (  )

/**
 *  Metodo10.
 */
void exercicio1420( void )
{
    // identificacao
    id( "Exercicio 1420:" );

    // programa
    MyString s( "abcdef ghijk lmnopqr" );
    string sequencia[10];

    int x = 0;

    x = s.split( sequencia );
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    cout << "String: " << "\""+s.getString( )+"\"" << endl;
    cout << "Quantidade de strings: " << x << endl << endl;

    for( int y = 0; y < x; y = y + 1 )
    {
        cout << concat( "s", concat( tostring(y),": " ) ) << sequencia[y] << endl;
    }

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1420 (  )

/**
 *  Metodo11.
 */
void exercicio14E1( void )
{
    // identificacao
    id( "Exercicio 14E1:" );

    // programa
    MyString s( "banana laranja abacaxi maracuja uva" );
    string sequencia[10];
    int x = 0;
    char c;
    
    c = readchar( "Digite um delimitador: " );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << endl << endl; 
    
    x = s.fragmentar( c, sequencia );

    cout << "Nova String: " << "\""+s.getString( )+"\"" << endl << endl;

    cout << "String Fragmentada: " << endl;
    for( int z = 0; z < x; z = z + 1 )
    {
        cout << concat( "s", concat( tostring(z),": " ) ) << sequencia[z] << endl;
    }
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio14E1 (  )

/**
 *  Metodo12.
 */
void exercicio14E2( void )
{
    // identificacao
    id( "Exercicio 14E2:" );

    // programa
    MyString s;

    s.setString( readstring( "Digite uma string: " ) );

    cout << endl << "String: " << "\""+s.getString( )+"\"" << endl << endl; 
    
    s.inverter( );

    cout << "Invertida: " << "\""+s.getString( )+"\"" << endl;
    
    if( s.hasErro( ) )
        cout << endl << s.getErroMsg( ) << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio14E2 (  )

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 1411    " << std::endl;
    std::cout << "  2 - Exercicio 1412    " << std::endl;
    std::cout << "  3 - Exercicio 1413    " << std::endl;
    std::cout << "  4 - Exercicio 1414    " << std::endl;
    std::cout << "  5 - Exercicio 1415    " << std::endl;
    std::cout << "  6 - Exercicio 1416    " << std::endl;
    std::cout << "  7 - Exercicio 1417    " << std::endl;
    std::cout << "  8 - Exercicio 1418    " << std::endl;
    std::cout << "  9 - Exercicio 1419    " << std::endl;
    std::cout << " 10 - Exercicio 1420    " << std::endl;
    std::cout << " 11 - Exercicio 14E1    " << std::endl;
    std::cout << " 12 - Exercicio 14E2    " << std::endl;
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
        id( "Programa: Exercicios14 - v0.0" );

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
            exercicio1411(  );
            break;
        case 2:
            exercicio1412(  );
            break;
        case 3:
            exercicio1413(  );
            break;
        case 4:
            exercicio1414(  );
            break;
        case 5:
            exercicio1415(  );
            break;
        case 6:
            exercicio1416(  );
            break;
        case 7:
            exercicio1417(  );
            break;
        case 8:
            exercicio1418(  );
            break;
        case 9:
            exercicio1419(  );
            break;
        case 10:
            exercicio1420(  );
            break;
        case 11:
            exercicio14E1(  );
            break;
        case 12:
            exercicio14E2(  );
            break;
        default:
            pause( "ERRO: opcao invalida" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}
