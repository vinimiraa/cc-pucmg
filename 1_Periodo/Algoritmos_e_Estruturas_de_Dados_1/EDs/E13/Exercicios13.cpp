/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios13 - v0.0. - 16 / 11 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios13 Exercicios13.cpp
 *      Windows: gcc -o Exercicios13 Exercicios13.cpp
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios13
 *      Windows: Exercicios13
 *
 */

// -------------------------- lista de dependencias

#include "libshow.hpp"
#include "Contato.hpp"

using namespace std;

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 *  Metodo01.
 */
void exercicio1311( void )
{
    // identificacao
    id( "Exercicio 1311:" );

    // programa
    Contato* pessoa1 =  new Contato( );
    
    pessoa1->readName( "Nome = " );
        
    cout << "Nome = \"" << pessoa1->getNome() << "\"" << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1311 (  )

/**
 *  Metodo02.
 */
void exercicio1312( void )
{
    // identificacao
    id( "Exercicio 1312:" );

    // programa
    Contato* pessoa1 =  new Contato( );
    
    pessoa1->readPhone( "Telefone = " );
        
    cout << "Telefone = \"" << pessoa1->getFone() << "\"" << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1312 (  )

/**
 *  Metodo03.
 */
void exercicio1313( void )
{
    // identificacao
    id( "Exercicio 1313:" );

    // programa
    Contato* pessoa1 =  new Contato( );
    
    pessoa1->readPhone( "Telefone = " );
    
    if( pessoa1->isValidPhone( ) )
        cout << "Telefone = \"" << pessoa1->getFone() << "\"" << endl;
    else
        cout << "Telefone Invalido." << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1313 (  )

/**
 *  Metodo04.
 */
void exercicio1314( void )
{
    // identificacao
    id( "Exercicio 1314:" );

    // programa
    Contato* pessoa1 = new Contato( );
    
    pessoa1->readFromFile( "Pessoa1.txt" );
    
    cout << "Pessoa1 - " << pessoa1->toString( ) << endl;
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1314 (  )

/**
 *  Metodo05.
 */
void exercicio1315( void )
{
    // identificacao
    id( "Exercicio 1315:" );
    
    // programa
    Contato* pessoa1 = new Contato( );
    
    pessoa1->writeToFile( "Pessoa1.txt" );
    
    pessoa1->readFromFile( "Pessoa1.txt" );
    
    cout << "Pessoa1 - " << pessoa1->toString( ) << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1315 (  )

/**
 *  Metodo06.
 */
void exercicio1316( void )
{
    // identificacao
    id( "Exercicio 1316:" );

    // programa
    Contato* contato1 = new Contato ( "Joao", "91234-5678", "4002-8922" );
    Contato* contato2 = new Contato ( "Lucas", "91234-5678", "" );
    Contato* contato3 = new Contato ( "Miguel", "", "4002-8922" );
    Contato* contato4 = new Contato ( "Vitor", "", "" );
    Contato* contato5 = new Contato ( "", "", "" );
    
    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Contato2 - " << contato2->toString( ) << endl;
    cout << "Contato3 - " << contato3->toString( ) << endl;
    cout << "Contato4 - " << contato4->toString( ) << endl;
    cout << "Contato5 - " << contato5->toString( ) << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1316 (  )

/**
 *  Metodo07.
 */
void exercicio1317( void )
{
    // identificacao
    id( "Exercicio 1317:" );

    // programa
    Contato* contato1 = new Contato ( "Joao", "91234-5678", "4002-8922" );
    Contato* contato2 = new Contato ( "Jose", "91234-5678", "" );
    Contato* contato3 = new Contato ( "Pedro", "", "4002-8922" );
    Contato* contato4 = new Contato ( "Marcos", "", "" );
    
    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Contato 1 = " << contato1->phone( ) << " telefone(s)." << endl << endl;
    
    cout << "Contato2 - " << contato2->toString( ) << endl;
    cout << "Contato 2 = " << contato2->phone( ) << " telefone(s)." << endl << endl;
    
    cout << "Contato3 - " << contato3->toString( ) << endl;
    cout << "Contato 3 = " << contato3->phone( ) << " telefone(s)." << endl << endl;
    
    cout << "Contato4 - " << contato4->toString( ) << endl;
    cout << "Contato 4 = " << contato4->phone( ) << " telefone(s)." << endl << endl;
    
    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1317 (  )

/**
 *  Metodo08.
 */
void exercicio1318( void )
{
    // identificacao
    id( "Exercicio 1318:" );

    // programa
    Contato* contato1 = new Contato( "Jose", "91234-5678", "" );

    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl << endl;

    contato1->setPhone2a( "97777-3333" );

    cout << endl << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1318 (  )

/**
 *  Metodo13.
 */
void exercicio1319( void )
{
    // identificacao
    id( "Exercicio 1319:" );

    // programa
    Contato* contato1 = new Contato( "Jose", "91234-5678", "4002-8922" );

    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl << endl;

    contato1->setPhone2b( "97777-3333" );

    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1319 (  )

/**
 *  Metodo10.
 */
void exercicio1320( void )
{
    // identificacao
    id( "Exercicio 1320:" );

    // programa
    Contato* contato1 = new Contato( "Jose", "91234-5678", "4002-8922" );

    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl << endl;

    contato1->setPhone2c( "" );

    cout << "Contato1 - " << contato1->toString( ) << endl;
    cout << "Telefone(s) = " << contato1->phone( ) << endl << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1320 (  )

/**
 *  Metodo11.
 */
void exercicio13E1( void )
{
    // identificacao
    id( "Exercicio 13E1:" );

    // programa
    Contato contato;

    contato.setPhones("91234-5678");
    contato.setPhones("4002-8922");

    cout << "Quantidade de telefones: " << contato.getXp() << endl;

    cout << "Telefones: ";
    for (int i = 0; i < contato.getXp(); i++)
    {
        cout << contato.getPhones(i) << " ";
    }
    cout << endl;

    contato.removePhones(0);

    cout << endl << "Quantidade de telefones: " << contato.getXp() << endl;

    cout << "Telefones: ";
    for (int i = 0; i < contato.getXp(); i++)
    {
        cout << contato.getPhones(i) << " ";
    }
    cout << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio13E1 (  )

/**
 *  Metodo12.
 */
void exercicio13E2( void )
{
    // identificacao
    id( "Exercicio 13E2:" );

    // programa
    Contato contato1;
    Contato* contato2 = new Contato("Lucas", "99876-5432", "2298-2004",
                                    "Rua Residencial, 789", "Avenida Profissional, 654");

    contato1.setPhones("91234-5678");
    contato1.setPhones("4002-8922");

    contato1.setERes("Rua Residencial, 123");
    contato1.setECom("Avenida Profissional, 456");

    cout << "Contato 1: " << endl << endl;
    cout << "Telefones: ";
    for (int i = 0; i < contato1.getXp(); i++)
    {
        cout << contato1.getPhones(i) << " ";
    }
    cout << endl;

    cout << "Endereco Residencial: " << contato1.getERes() << endl;
    cout << "Endereco Profissional: " << contato1.getECom() << endl;

    cout << endl << "Contato 2 - " << contato2->toString2( ) << endl;

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio13E2 (  )

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 1311    " << std::endl;
    std::cout << "  2 - Exercicio 1312    " << std::endl;
    std::cout << "  3 - Exercicio 1313    " << std::endl;
    std::cout << "  4 - Exercicio 1314    " << std::endl;
    std::cout << "  5 - Exercicio 1315    " << std::endl;
    std::cout << "  6 - Exercicio 1316    " << std::endl;
    std::cout << "  7 - Exercicio 1317    " << std::endl;
    std::cout << "  8 - Exercicio 1318    " << std::endl;
    std::cout << "  9 - Exercicio 1319    " << std::endl;
    std::cout << " 10 - Exercicio 1320    " << std::endl;
    std::cout << " 11 - Exercicio 13E1    " << std::endl;
    std::cout << " 12 - Exercicio 13E2    " << std::endl;
    std::cout << std::endl;
} // fim menuOpcoes ( )

// -------------------------- definicao do metodo principal

int main( void )
{
    int opcao = 0;

    do
    {
        // limpar a saida de dados
        clearscreen(  );

        // mostrar identificacao do autor e programa
        id( "Programa: Exercicios13 - v0.0" );

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
            exercicio1311(  );
            break;
        case 2:
            exercicio1312(  );
            break;
        case 3:
            exercicio1313(  );
            break;
        case 4:
            exercicio1314(  );
            break;
        case 5:
            exercicio1315(  );
            break;
        case 6:
            exercicio1316(  );
            break;
        case 7:
            exercicio1317(  );
            break;
        case 8:
            exercicio1318(  );
            break;
        case 9:
            exercicio1319(  );
            break;
        case 10:
            exercicio1320(  );
            break;
        case 11:
            exercicio13E1(  );
            break;
        case 12:
            exercicio13E2(  );
            break;
        default:
            pause( "ERRO: opcao invalida" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}