/*
    Exemplo1100 - v0.0. - 31 / 10 / 2023
    Author: Vinicius Miranda de Araujo

 */
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres

// ----------------------------------------------- definicoes globais

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
} // end pause ( )

// ----------------------------------------------- classes / pacotes

#include "myarray.hpp"

using namespace std;

// ----------------------------------------------- metodos

/**
    Method_00 - nao faz nada.
 */
void method_00()
{
    // nao faz nada
} // end method_00 ( )

/**
    Method_01 - Mostrar certa quantidade de valores.
 */
void method_01()
{
    // identificar
    cout << "\nMethod_01 - v0.0\n" << endl;

    // definir dados
    Array<int> int_array(5, 0);
    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);

    // mostrar dados
    int_array.print();

    // reciclar espaco
    int_array.free();

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_01 ( )

/**
    Method_02.
 */
void method_02()
{
    // identificar
    cout << endl << "Method_02 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array ( 5, 0 ); 

    // ler dados 
    int_array.read  ( ); 

    // mostrar dados 
    int_array.print ( ); 

    // reciclar espaco 
    int_array.free ( );

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_02 ( )

/**
    Method_03.
 */
void method_03()
{
    // identificar
    cout << endl << "Method_03 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array ( 5, 0 ); 

    // ler dados 
    int_array.read  ( ); 

    // mostrar dados 
    int_array.fprint ( "INT_ARRAY1.TXT" ); 

    // reciclar espaco 
    int_array.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_03 ( )

/**
    Method_04.
 */
void method_04()
{
    // identificar
    cout << endl << "Method_04 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array ( 5, 0 );
    
    // ler dados 
    int_array.fread ( "INT_ARRAY1.TXT" ); 

    // mostrar dados 
    int_array.print ( ); 

    // reciclar espaco 
    int_array.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_04 ( )

/**
    Method_05.
 */
void method_05()
{
    // identificar
    cout << endl << "Method_05 - v0.0" << endl;

    // definir dados 
    int other [ ] = { 1, 2, 3, 4, 5 }; 
    Array  <int> int_array ( 5, other );
    
    // mostrar dados 
    cout << "\nCopia\n" << endl;
    int_array.print (  );

    // reciclar espaco 
    int_array.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_05 ( )

/**
    Method_06.
 */
void method_06()
{
    // identificar
    cout << endl << "Method_06 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array1 ( 1, 0 ); 

    // ler dados 
    int_array1.fread ( "INT_ARRAY1.TXT" );
    
    // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_array1.print ( ); 

    // criar   copia 
    Array <int> int_array2 ( int_array1 ); 

    // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_array2.print ( ); 

    // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_06 ( )

/**
    Method_07.
 */
void method_07()
{
    // identificar
    cout << endl << "Method_07 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array1 ( 1, 0 ); 
    Array  <int> int_array2 ( 1, 0 ); 
    
    // ler dados 
    int_array1.fread ( "INT_ARRAY1.TXT" ); 
    
    // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_array1.print ( ); 
    
    // copiar  dados 
    int_array2 = int_array1; 
    
    // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_array2.print ( ); 

    // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( );

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
    Method_08.
 */
void method_08()
{
    // identificar
    cout << endl << "Method_08 - v0.0" << endl;

    // definir dados 
    int   other [ ] = { 1, 2, 3 }; 
    Array <int> int_array1 ( 3, other ); 
    Array <int> int_array2 ( 3, other ); 
    // int x;
    
    // mostrar dados 
    cout << endl; 
    cout << "Array_1"; 
    int_array1.print ( ); 
    
    // mostrar dados 
    cout << "Array_2"; 
    int_array2.print ( ); 
    
    // mostrar comparacao 
    cout << "Igualdade = " << (int_array1==int_array2) << endl; 
    
    // alterar dado 
    int_array2.set ( 0, (-1) ); 
    
    // mostrar dados 
    cout << endl; 
    cout << "Array_1" << endl; 
    int_array1.print ( ); 
    cout << "Array_2" << endl; 
    int_array2.print ( ); 
    
    // mostrar comparacao 
    cout << "Igualdade = " << (int_array1==int_array2) << endl; 
    
    // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
    Method_09.
 */
void method_09()
{
    // identificar
    cout << endl << "Method_09 - v0.0" << endl;

    // definir dados 
    Array  <int> int_array1 ( 1, 0 ); 
    Array  <int> int_array2 ( 1, 0 ); 
    Array  <int> int_array3 ( 1, 0 );
    
    // ler dados 
    int_array1.fread ( "INT_ARRAY1.TXT" ); 
    
    // copiar  dados 
    int_array2 = int_array1; 
    
    // somar   dados 
    int_array3 = int_array2 + int_array1; 
    
    // mostrar dados 
    cout << endl; 
    cout << "Original" << endl; 
    int_array1.print ( ); 
    
    // mostrar dados 
    cout << "Copia"    << endl; 
    int_array2.print ( ); 
    
    // mostrar dados 
    cout << "Soma"     << endl; 
    int_array3.print ( ); 
    
    // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( );  
    int_array3.free ( ); 

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_09 ( )

/**
    Method_10.
 */
void method_10()
{
    // identificar
    cout << endl << "Method_10 - v0.0" << endl;

    // definir dados 
    int other [ ] = { 1, 2, 3, 4, 5 }; 
    Array  <int> int_array ( 5, other ); 
    int x; 
    
    // mostrar dados 
    cout << "\nAcesso externo" << endl; 
    for ( x=0; x<int_array.getLength( ); x=x+1 ) 
    { 
        cout << endl << setw( 3 ) << x << " : " << int_array [ x ]; 
    } // fim repetir 
    cout << endl << "\nFora dos limites:"; 
    cout << endl << "[-1]: " << int_array.get(-1) << endl; 
    cout << endl << "[" << int_array.getLength( ) << "]: " << int_array [ int_array.getLength( ) ] << endl; 

    // reciclar espaco 
    int_array.free ( );

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_10 ( )

// ----------------------------------------------- acao principal

/**
    Funcao principal.
    @return codigo de encerramento
*/
int main( void )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n    " << endl;

        // mostrar opcoes
        cout << "Opcoes        " << endl;
        cout << " 0 - parar       " << endl;
        cout << " 1 - mostrar dados inteiros em arranjo  " << endl;
        cout << " 2 -        " << endl;
        cout << " 3 -        " << endl;
        cout << " 4 -        " << endl;
        cout << " 5 -        " << endl;
        cout << " 6 -        " << endl;
        cout << " 7 -        " << endl;
        cout << " 8 -        " << endl;
        cout << " 9 -        " << endl;
        cout << "10 -        " << endl;

        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
        switch (x)
        {
        case 0:
            method_00();
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
            break;
        default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    } while (x != 0);

    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )

/* 
---------------------------------------------- documentacao complementar 

---------------------------------------------- notas / observacoes / comentarios 

---------------------------------------------- previsao de testes 

---------------------------------------------- historico 

Versao  Data      Modificacao 
0.1     31/10      esboco 

---------------------------------------------- testes 

Versao  Teste 
0.1     01. ( OK )  identificacao de programa
*/