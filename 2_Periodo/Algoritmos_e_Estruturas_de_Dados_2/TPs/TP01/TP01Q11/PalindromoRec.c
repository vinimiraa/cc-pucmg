/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q11 - 12 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o PalindromoRec PalindromoRec.c
 *       Windows: gcc -o PalindromoRec PalindromoRec.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./PalindromoRec
 *       Windows: PalindromoRec
 *   
*/

// ---------------------------------------- Dependencias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
 *  @param s - char*: string.
 *  @param s - int: primeiro caractere.
 *  @param y - int: ultimo caractere.
*/
bool isPalindromoRec ( char *s, int x, int y )
{
    if( x < strlen(s)/2 )
    {
        if( s[x] == s[y] )
        {
            return ( isPalindromoRec(s, ++x, --y) );
        }
        else
        {
            return ( false );
        } // end if
    } // end if
    return ( true );
} // end isPalindromoRec ( )

/**
 *  Funcao para verificar se uma string e' um palindromo.
 *  @return true se palindromo, false caso contrario.
 *  @param s - char*: string.
*/
bool isPalindromo( char* s )
{
    return ( isPalindromoRec( s, 0, strlen(s)-1 ) );
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
        } // end if
        free( entrada );
    } while ( !isFim( entrada ) );
    
    return ( 0 );
} // end main ( )