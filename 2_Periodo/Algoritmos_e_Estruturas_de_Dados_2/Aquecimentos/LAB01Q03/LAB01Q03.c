/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados I
 *  
 *  LAB01Q03 - v0.0. - 23 / 08 / 2023
 *  Author: Vinicius Miranda de Araujo
 *  
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o LAB01Q03 LAB01Q03.c
 *       Windows: gcc -o LAB01Q03 LAB01Q03.c
 *  
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./LAB01Q03
 *       Windows: LAB01Q03
 *  
*/

// ------------------------------------- Dependencias

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ------------------------------------- Metodos

/**
 *  Funcao para verificar se a entrada e' igual a "FIM" 
 *  @param s - char*.
 *  @return true se fim, false caso contrario.
 */
bool isFim ( const char *s )
{
    bool result = false;
    if( strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M' )
    {
        result = true;
    } // end if
    return ( result );
} // end isFim ( )

/**
 *  Função para verificar se o caractere e' maiusculo.
 *  @param c - caractere.
 *  @return true se maiusculo, false caso contrario.
 */
bool isUpper( char c )
{
    bool result = false;
    if( 'A' <= c && c <= 'Z' )
    {
        result = true;
    }
    return ( result );
} // end ifUpper ( )

/**
 *  Funcao para contabilizar o numero de letras maiusculas em uma string.
 *  @param s - char*.
 *  @return numero de maiusculas.
 */
int countUppers( const char *s )
{
    int result = 0;
    int length = strlen( s );
    int x = 0;
    for( x = 0; x < length; x = x + 1 )
    {
        if( isUpper( s[x] ) )
        {
            result = result + 1;
        } // end if
    } // end for
    return ( result );
} // end countUppers ( )

/**
 *  Funcao principal.
 *  @param argc
 *  @param argv
 */
int main( int argc, char const *argv[] )
{
    char **entrada = NULL;
    int numEntrada = 0;

    entrada = (char**) calloc ( 100, sizeof( char* ) );
    if( entrada != NULL )
    {
        for( int x = 0; x < 100; x = x + 1 )
        {
            entrada[x] = (char*) calloc ( 80, sizeof(char) );
        } // end for
    } // end if

    do
    {
        fgets( entrada[numEntrada], 80, stdin );

        size_t length = strlen(entrada[numEntrada]);

		if( length > 0 && entrada[numEntrada][length-1] == '\n' ) 
        {
            entrada[numEntrada][length-1] = '\0';
		} // end if

    } while ( !isFim( entrada[numEntrada++] ) ); // end do while
    numEntrada--;
    
    for( int x = 0; x < numEntrada; x++){
            printf( "%d\n", countUppers(entrada[x]) );
    } // end for
    
    if( entrada != NULL )
    {
        for( int x = 0; x < 100; x = x + 1 )
        {
            free( entrada[x] );
        } // end for
        free( entrada );
    } // end if

    return ( 0 );
} // end main
