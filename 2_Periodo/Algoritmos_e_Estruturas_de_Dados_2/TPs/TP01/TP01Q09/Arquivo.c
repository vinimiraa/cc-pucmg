/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q09 - 13 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o Arquivo Arquivo.c
 *       Windows: gcc -o Arquivo Arquivo.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./Arquivo
 *       Windows: Arquivo
 *   
*/

// ---------------------------------------- Dependencias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>  // location specific settings

// ---------------------------------------- Metodos

/**
 *  Funcao para formatar um numero real e printar para o Verde.
 *  Logica: Converter de double para char e manipular os caracteres. Se for '0' substituir por '\0' e se for '.' o
 *  numero e' inteiro, entao tirar o '.' tambem.
 *  @param input - double: Numero real a ser formatado.
*/
void formattedDouble( double input )
{
    char *buffer = (char*) malloc( (80+1) * sizeof( char ) ); 
    sprintf( buffer, "%.10lf", input );
    int length = strlen( buffer );
    while( length > 0 && ( buffer[length-1] == '0' || buffer[length-1] == '.' ) )
    {
        if( buffer[length-1] == '.' )
        {
            buffer[length-1] = '\0';
            length = 0;
        } // end if
        buffer[length-1] = '\0'; 
        length = length - 1;
    } // end while
    printf( "%s\n", buffer );
} // end formatDouble ( )

/**
 *  Funcao para escrever numero real no arquivo.
 *  @param n - int: Quantidade de numeros a serem escritos.
 *  @param filename - char*: Nome do arquivo.
*/
void writeDoubleToFile( int n, char* filename )
{
    FILE *file = fopen( filename, "w+b" );
    for( int x = 0; x < n; x = x + 1 )
    {
        double input = 0.0;
        scanf( "%lf", &input );
        fwrite( &input, sizeof(double), 1, file );
    }
    fclose( file );
} // end writeDoubleToFile ( )

/**
 *  Funcao para ler numero real do arquivo.
 *  @param n - int: Quantidade de numeros no arquivo.
 *  @param filename - char*: Nome do arquivo.
*/
void readDoubleFromFile( int n, char* filename )
{
    FILE *file = fopen( filename, "rb" );
    double value = 0.0;
    if( file == NULL )
    {
        printf( "\n%s\n", "ERRO: Nao foi possivel abrir o arquivo" );
    }
    else
    {
        for( int pointer = 0; pointer < n; pointer = pointer + 1 )
        {
            fseek( file, (n - pointer - 1) * sizeof(double) , SEEK_SET);
            fread( &value, sizeof(double), 1 ,file );
            formattedDouble( value );
        } // end for
    } // end if
    fclose( file );
} // end readDoubleFromFile ( )

int main ( int argc, char* argv[] )
{
    setlocale( LC_NUMERIC, "en_US.UTF-8" );

    int   n        = 0;
    char *filename = "ARQUIVO.TXT";

    scanf( "%d", &n );
    
    writeDoubleToFile( n, filename );

    readDoubleFromFile( n, filename );
} // end main ( )