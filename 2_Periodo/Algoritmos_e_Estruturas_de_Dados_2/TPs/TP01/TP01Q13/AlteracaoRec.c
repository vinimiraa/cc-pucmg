/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q13 - 04 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o AlteracaoRec AlteracaoRec.c
 *       Windows: gcc -o AlteracaoRec AlteracaoRec.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./AlteracaoRec
 *       Windows: AlteracaoRec
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
 *  Funcao para gerar um caractere aleatorio.
 *  @return caractere aleatorio.
 */
char randomChar( )
{
    char c = ( char )( 'a' + abs(  rand( ) % 26 ) );
    return ( c );
} // end randomChar ( )

/**
 *  Funcao para substituir todas as ocorrencias da primeira letra na string pela segunda. 
 *  @param input - char*.
 *  @param c1 - char.
 *  @param c2 - char.
 *  @param x - int.
 *  @return nova string.
 */
char* randomChangeRec ( char* input, char c1, char c2, int x )
{
    int length = strlen( input );
    if( x < length )
    {
        if( input[x] == c1 )
        {
            input[x] = c2;
            randomChangeRec( input, c1, c2, x+1 );
        }
        else
        {
            randomChangeRec( input, c1, c2, x+1 );
        } // end if
    } // end if
    return ( input );
} // end randomChange ( )

/**
 *  Funcao para chamar a funcao recursiva.
 *  @param intput - char*.
 *  @return nova string.
*/
char* randomChange( char * input )
{
    char c1 = randomChar( );
    char c2 = randomChar( );
    // printf( "c1 = %c c2 = %c" , c1, c2 );
    char* string = randomChangeRec( input, c1, c2, 0 );
    return ( string );
} // end randomChange ( )

/**
 *  Funcao para ler linha da entrada padrao.
 *  @return string.
*/
char* readLine( )
{
    char *string = (char*) calloc ( 1100+1, sizeof(char) );
    if( string != NULL )
    {
        fgets( string, 1000+1, stdin );
        unsigned int length = strlen( string );
        if( length > 0 && string[length-1] == '\n' )
        {
            string[length-1] = '\0';
        } // end if
    } // end if
    return ( string ); 
} // end readLine ( )

/**
 *  Funcao Principal
 *  @param argc
 *  @param argv
*/
int main( int argc, char const *argv[] )
{
    srand( 4 );
    char *entrada[1000];
    int numEntrada = 0;

    do
    {
        entrada[numEntrada] = readLine( );
    } while ( !isFim( entrada[numEntrada++] ) ); // end do while
    numEntrada--;
    
    for( int x = 0; x < numEntrada; x++)
    {
        printf( "%s\n", randomChange(entrada[x]) );
    } // end for
    
    if( entrada != NULL )
    {
        for( int x = 0; x <= numEntrada; x = x + 1 )
        {
            free( entrada[x] );
        } // end for
    } // end if
    return ( 0 );
} // end main ( )
