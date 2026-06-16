/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  Teclado Quebrado - Warm-Up - 18 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o Teclado Teclado.c
 *       Windows: gcc -o Teclado Teclado.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./Teclado
 *       Windows: Teclado
 *   
*/

// ---------------------------------------- Dependencias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ---------------------------------------- Metodos

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

char *substring( int start, int end, char *string )
{
    int len = strlen( string );
    int x = 0, y = 0;
    char* result = (char*) calloc ( len+4, sizeof(char) );
    for( x = start, y = 0; x < end; x = x + 1, y = y + 1 )
    {
        result[y] = string[x];
    } // end for
    result[y] = '\0';
    return ( result );
} // end substring ( )

void findBrackets( int* start, int* end, char *string )
{
    int len = strlen( string );
    *start = -1; *end = -1;
    for( int x = 0; x < len; x = x + 1 )
    {
        if( string[x] == '[' )
        {
            *start = x;
            while( string[x] != ']' )
            {
                x = x + 1;
            } // end while
            *end = x;
            x = len;
        } // end if
    } // end for
} // end findBracktes ( )

char* concat ( const char * const text1, const char * const text2 )
{                               // reservar area
    char *buffer = (char*) malloc ( (strlen(text1) + strlen(text2) + 1) * sizeof(char) );
    strcpy ( buffer, text1 );
    strcat ( buffer, text2 );
    return ( buffer );
} // end concat ( )

int main( )
{
    char *input = NULL;
    char *sub   = NULL;
    int start = 0, end = 0;
    int len = 0;
    
    do
    {
        free(input);                                       
        input = readLine( );                               // ler a string
        len = strlen( input );                             // pegar o tamanho da string lida
        findBrackets( &start, &end, input );               // achar as posicoes de '[' e ']', respectivamente
        sub = substring( start+1, end, input );            // pegar a string dentro dos cochetes
        char *part1 = substring(0, start, input);          // pegar a string do comeco ate '['  
        char *part2 = substring(end+1, len, input);        // pegar a string do ']' ate o fim
        char *result = concat(sub, concat(part1, part2));  // concatenar a string dentro dos colchtes com as duas anteriores
        printf("%s\n", result);                            // printar o resultado
        free(result);                                      // liberar espaco de memoria do resultado
        start = 0; end = 0;                                // reiniciar o contador do inicio e fim dos colchetes
    } while ( input[0] != '\0' && input[0] != '\n' );
    
    return ( 0 );
} // end main ( )

