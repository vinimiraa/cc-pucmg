/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q02 - 22 / 02 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o Palindromo Palindromo.c
 *       Windows: gcc -o Palindromo Palindromo.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./Palindromo
 *       Windows: Palindromo
 *   
*/

// ---------------------------------------- Dependencias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>   // wide-character types
#include <locale.h>  // location specific settings

// ---------------------------------------- Metodos

/**
 *  Funcao para verificar se a entrada e' igual a "FIM" 
 *  @param s - char*.
 *  @return true se fim, false caso contrario.
 */
bool isFim( char* s )
{
    bool result = false;
    if( strcmp( s, "FIM" ) == 0 )
    {
        result = true;
    }
    return ( result );
} // end isFim ( )

/**
 *  Funcao para verificar se uma string e' um palindromo.
 *  @return true se palindromo, false caso contrario.
 *  @param s - char*.
*/
bool isPalindromo ( char *s )
{
    bool result = true;
    int x = 0, y = 0;
    unsigned int length = strlen( s );

    for ( x = 0, y = length-1; x < length/2; x=x+1, y=y-1 )
    {
        if ( s[x] != s[y] ) // verificar se o primeiro caractere e' diferente do ultimo
        {
            result = false;  
            x = length; // interromper a repeticao
        } // end if
    } // end for
    return ( result );
} // end isPalindromo ( )

/**
 *  Funcao para ler linha da entrada padrao.
 *  @return string.
*/
char* readLine( )
{
    char *string = (char*) calloc ( 1000+1, sizeof(char) );
    if( string != NULL )
    {
        fgets( string, 1000+1, stdin );
        unsigned int length = strlen( string );
        // if( length > 0 && ( string[length-1] == '\n' || string[length-1] == '\r') )
        if( length > 0 && string[length-1] == '\n' )
        {
            string[length-1] = '\0';
        } // end if
    } // end if
    return ( string ); 
} // end readLine ( )

/**
 *  Funcao Principal
 *  @param agrc
 *  @param agrv
*/
int main( int argc, char const *argv[] )
{
    setlocale(LC_CTYPE, "UTF-8"); // setCharset
    char* entrada = NULL;

    do
    {
        entrada = readLine( );

        if( !isFim( entrada ) )
        {
            if( isPalindromo( entrada ) )
            {
                printf( "SIM\n" );
            }
            else
            {
                printf( "NAO\n" );
            } // end if
            free( entrada );
        } // end if
    } while ( !isFim( entrada ) );
    
    return ( 0 );
} // end main ( )
