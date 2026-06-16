/**
    Biblioteca Show - IO - Console Input/Output library.
    PUC-Minas - ICEI
    @author  Vinícius Miranda de Araújo
    @version 0.1 - 2023-2b

    LIBSHOW - v2023-2_0.1 - 31 / 10 / 2023
    Author: Vinícius Miranda de Araújo
*/

// ---------------------- lista de dependencias

#include <iostream>    // para entradas e saidas
#include <fstream>     // para arquivos
#include <sstream>     // para conversoes
#include <string>      // para cadeias de caracteres
#include <iomanip>     // para formatacao de entradas e saidas

#include <cstdio>      // para entradas e saida
#include <cstdlib>     // para a biblioteca padrao
#include <cstring>     // para cadeias de caracteres

#include <stddef.h>    // para definicoes basicas
#include <stdarg.h>    // para tratar argumentos
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo

// ---------------------- redefinicoes para apontamentos

#ifndef __REFS__
#define __REFS__

#define nullptr   NULL    // para compatibilizar com C++
#define null      NULL    // para generalizar

// #define addr(p)  (&(p))   // para obter endereco
// #define deref(p) (*(p))   // para obter conteudo de endereco
// #define val(p)   (*(p))   // para obter conteudo apontado

// #define ref       *       // para passar parametro por referencia
//                           // (na assinatura)
// #define var       &       // para passar parametro por referencia
//                           // (na chamada)

#endif

// ---------------------- redefinicoes uteis

#ifndef _SHOW_HPP_
#define _SHOW_HPP_

#define  AND              &&
#define  OR               ||
#define  NOT              !
#define  XOR              ^

// ---------------------- definicoes de constantes

const   bool FALSE        = false;  // definir constante
const   bool TRUE         = true ;  // definir constante

const   char EOS          = '\0';   // definir fim de cadeia de caracteres
const   char EOL          = '\n';   // definir mudanca de linha
const   char ENDL []      = "\n";   // definir mudanca de linha
const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia
const   int  STR_SIZE     =  80 ;   // definir tamanho padrao para caracteres
const   int  MAX_SIZE     = 10  ;   // definir tamanho padrao para matrizes

// ---------------------- definicoes de tipos

// typedef char*   chars  ;         // definir cadeia  de caracteres
// typedef int*    ints   ;         // definir arranjo de inteiros
// typedef double* doubles;         // definir arranjo de reais
// typedef bool*   bools  ;         // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

// ---------------------- definicoes de funcoes e procedimentos

// ---------------------- para tratamento de erros

// ---------------------- para entradas e saidas

/**
    Metodo para limpar a saida de dados padrao.
 */
void clearscreen( void )
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
        system ( "cls"   ); // para Windows - OBS: NAO RECOMENDADO !
    #elif defined(__linux__)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #elif defined(__APPLE__) && defined(__MACH__)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #elif defined(unix) || defined(__unix__) || defined(__unix)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #else
        #error Unknown_OS
    #endif
} // end clearscreen ( )

/**
    Metodo para limpar a entrada de dados padrao.
 */
void flush ( void )
{
    char x = '0';
    do { x = getchar( ); } while ( '\n' != x );
} // end flush ( )

/**
    Metodo para identificar o programa e a autoria.
    @param text - mensagem a ser exibida
 */
void id ( std::string text )
{
    std::cout << std::endl;
    std::cout << text << std::endl;
    std::cout << "Autor: Vinicius Miranda de Araujo - 812839" << std::endl;
    std::cout << std::endl;
} // end id ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
} // end pause ( )

/**
    Metodo para mostrar uma linha com certo texto.
    @param text1 - primeira cadeia
 */
void print ( std::string text1 )
{
    std::cout << text1;
} // end print ( )

/**
    Metodo para mostrar uma linha com certo texto
    e mudar de linha.
    @param text1 - primeira cadeia
 */
void println ( std::string text1 )
{
    std::cout << text1 << std::endl;
} // end println ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int readint ( std::string text )
{
    int x = 0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x );
} // end readint ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double readdouble ( std::string text )
{
    double x = 0.0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x );
} // end readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float readfloat ( std::string text )
{
    float x = 0.0;
    std::cout << text;
    std::cin >> std::skipws >> x;
    std::cin.clear ( );
    return ( x );
} // end readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    @note   Usar o valor zero para falso, e diferente de zero para verdadeiro
 */
bool readbool ( std::string text )
{
    int x = 0;
    std::cout << text;
    std::cin  >> std::skipws >> x;
    std::cin.clear ( );
    return ( x!=0 );
} // end readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char readchar ( std::string text )
{
    char x = '0';
    std::cout << text;
    do
    {
        std::cin.get ( x );
        std::cin.clear ( );
    }
    while ( x == '\n' );
    return ( x );
} // end readchar ( )

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param  text - mensagem a ser exibida antes da leitura
 */
char* readstring ( std::string text )
{
    std::string buffer;
    char* tmp = (char*) calloc ( 80+1, sizeof(char) ) ;

    std::cout << text  ;
    std::cin  >> buffer;
    flush ( );

    strcpy ( tmp, buffer.c_str( ) );
    return ( &(tmp[0]) );
} // end readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param  text - mensagem a ser exibida antes da leitura
 */
char* readln ( std::string text )
{
    std::string buffer;
    char* tmp = (char*) calloc ( 80+1, sizeof(char) );

    std::cout << text ;
    std::getline ( std::cin, buffer, '\n' );

    strcpy ( tmp, buffer.c_str( ) );
    return ( &(tmp[0]) );
} // end readln ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size quantidade de dados
 */
int* new_int ( int size )
{
    return ( (int*) malloc ( (size) * sizeof(int) ) );
} // end new_int ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size quantidade de dados
 */
double* new_double ( int size )
{
    return ( (double*) malloc ( (size) * sizeof(double) ) );
} // end new_double ( )

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size quantidade de dados
 */
char* new_char ( int size )
{
    return ( (char*) malloc ( (size+1) * sizeof(char) ) );
} // end new_char ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size quantidade de dados
 */
bool* new_bool ( int size )
{
    return ( (bool*) malloc ( (size) * sizeof(bool) ) );
} // end new_bool ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
std::string concat ( std::string text1, std::string text2 )
{                               // reservar area
    std::string buffer = text1+text2;
    return ( buffer );
} // end concat ( )

/**
    Funcao para converter inteiro para caracteres.
    @return cadeia com o resultado
    @param x     - valor inteiro
 */
std::string tostring ( int x )
{         
    std::ostringstream buffer;
    buffer << x;
    return  ( buffer.str ( ) );
} // end tostring ( )

/**
    Funcao para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
std::string tostring ( double x )
{
    std::ostringstream buffer;
    buffer << x;
    return  ( buffer.str ( ) );
} // end tostring ( )

/**
    Funcao para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
std::string tostring ( std::string x )
{
    std::ostringstream buffer;
    buffer << x;
    return  ( buffer.str ( ) );
} // end tostring ( )

/**
    Funcao para converter valor logico para caracteres.
    @return cadeia com o resultado
    @param x     - valor logico
 */
std::string tostring ( bool x )
{
    std::ostringstream buffer;
    buffer << x;
    return  ( buffer.str ( ) );
} // end tostring ( )

/**
    Funcao para converter caractere para caracteres.
    @return cadeia com o resultado
    @param x     - caractere
 */
std::string tostring ( char x )
{                             // variante do printf( )
    std::ostringstream buffer;
    buffer << x;
    return  ( buffer.str ( ) );
} // end tostring ( )

/**
    Funcao para obter simbolo de certa posicao 
    em cadeia de caracteres.
    @return simbolo, se existir; '\0', caso contrario
    @param  text  - cadeia de caracteres
    @param  index - posicao desejada
 */
char charAt ( char* text, int index )
{
    char x = '\0';
    if ( text && 0 <= index && index < (int)strlen(text) )
    {  x = text [ index ]; }
    return ( x );
} // end charAt ( )

/**
    Funcao para ver o fatorial de um numero.
    @return Fatorial do numero.
    @param number Numero a ser lido.
*/
int factorial(int x)
{
    if( (x == 0) || (x == 1) )
    {
        return ( 1 );
    }
    else
    {
        return ( x * factorial( x - 1) );
    }
    return ( 0 );
} // end factorial ( )

/**
    Funcao para ver o numero na n-esima posicao de fibonacci.
    @return Numero de Fibonacci na posicao N.
    @param N posicao do numero.
*/
int fibonacci ( int n )
{
    int resposta = 0;
    if ( n == 1 || n == 2 )
        {
        resposta = 1;
        }
    else
    {
        if ( n > 2 )
        {
            resposta = fibonacci (n - 1) + fibonacci (n - 2);
        } 
    } 
    return ( resposta );
} // end Fibonacci ( )

/**
    Funcao para ver a quantidade de divisores de um numero.
    @return Quantidade de divisores.
    @param number Numero a ser lido.
*/
int dividers(int x)
{
    int divisor = 1;
    int count = 0;
    if (x < 0)
    {
        x = (-1) * x;
    } // end if
    while (divisor <= x)
    {
        if (x % divisor == 0)
        {
            count = count + 1;
        } // end if
        divisor = divisor + 1;
    } // end while
    return (count);
} // end dividers ( )

/**
    Funcao para ver se o numero e par.
    @return true se par; falso caso contrario.
    @param  number Numero a ser lido.
*/
bool isEven(int x)
{
    bool result = false;
    if (x % 2 == 0)
    {
        result = true;
    } // end if
    return (result);
} // end isEven ( )

/**
    Funcao para ver se o numero e impar.
    @return true se impar; falso caso contrario.
    @param  number Numero a ser lido.
*/
bool isOdd(int x)
{
    bool result = false;
    if (x % 2 != 0)
    {
        result = true;
    } // end if
    return (result);
} // end isOdd ( )

/**
    Funcao para ver se o numero e primo.
    @return true se primo; falso caso contrario.
    @param  number Numero a ser lido.
*/
bool isPrime(int x)
{
    bool result = false;
    if (dividers(x) == 2)
    {
        result = true;
    } // end if
    return (result);
} // end isPrime ( )

/**
    Funcao para ver se o numero e positivo.
    @return true se positivo; falso caso contrario.
    @param  number Numero a ser lido.
*/
bool isPositive(int x)
{
    bool result = false;
    if (x >= 0)
    {
        result = true;
    } // end if
    return (result);
} // end isPositive ( )

/**
    Funcao para ver se o numero e negativo.
    @return true se negativo; falso caso contrario.
    @param  number Numero a ser lido.
*/
bool isNegative(int x)
{
    bool result = false;
    if (x < 0)
    {
        result = true;
    } // end if
    return (result);
} // end isNegative ( )

/**
    Funcao para ver se o caractere e maiusculo.
    @return true se maiuscula; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isUpper(char c)
{
    bool result = false;
    if ('A' <= c && c <= 'Z')
    {
        result = true;
    } // end if
    return (result);
} // end isUpper ( )

/**
    Funcao para ver se o caractere e minusculo.
    @return true se minuscula; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isLower(char c)
{
    bool result = false;
    if ('a' <= c && c <= 'z')
    {
        result = true;
    } // end if
    return (result);
} // end isLower ( )

/**
    Funcao para ver se o caractere e numero.
    @return true se digito; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isDigit(char c)
{
    bool result = false;
    if ('0' <= c && c <= '9')
    {
        result = true;
    } // end if
    return (result);
} // end isDigit ( )

/**
    Funcao para ver se o caractere e letra.
    @return true se letra; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isAlpha(char c)
{
    bool result = false;
    if (isLower(c) || isUpper(c))
    {
        result = true;
    } // end if
    return (result);
} // end isAlpha ( )

/**
    Funcao para ver se o caractere e letra ou numero.
    @return true se letra ou digito; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isAlnum(char c)
{
    bool result = false;
    if (isAlpha(c) || isDigit(c))
    {
        result = true;
    } // end if
    return (result);
} // end isAlnum ( )

/**
    Funcao para ver se o caractere e um espaco em branco.
    @return true se espaco; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isSpace(char c)
{
    bool result = false;
    if (c == ' ')
    {
        result = true;
    } // end if
    return (result);
} // end isSpace ( )

/**
    Funcao para ver se o caractere e pontuacao.
    @return true se pontuacao; falso caso contrario.
    @param  char Caractere a ser lido.
*/
bool isPunct(char c)
{
    bool result = false;
    if (('!' <= c && c <= '/') || (':' <= c && c <= '@') || ('[' <= c && c <= '`') || ('{' <= c && c <= '~'))
    {
        result = true;
    } // end if
    return (result);
} // end isPunct ( )

/**
    Funcao para verificar se o numero esta dentro do intervalo aberto.
    @return true se dentro do intervalo; falso caso contrario.
    @param x numero a ser verificado.
    @param a extrema esquerda do intervalo.
    @param b extrema direita do intervalo.
*/
bool inOpenInterval(double x, double a, double b)
{
    bool result = true;
    if (a >= x || x >= b) // !inOpenInterval(x) = (a < x || x < b)
    {
        result = false;
    } // end if
    return (result);
} // end inOpenInterval ( )

/**
    Funcao para verificar se o numero esta dentro do intervalo fechado.
    @return true se dentro do intervalo; falso caso contrario.
    @param x numero a ser verificado.
    @param a extrema esquerda do intervalo.
    @param b extrema direita do intervalo.
*/
bool inClosedInterval(double x, double a, double b)
{
    bool result = true;
    if (a > x || x > b) // !inClosedInterval(x) = (a <= x || x <= b)
    {
        result = false;
    } // end if
    return (result);
} // end inClosedInterval ( )

/**
    Funcao para converter o caractere para maiusculo.
    @return maiuscula se miniscula; maiuscula caso contrario.
    @param  char Caractere a ser lido.
*/
char toUpper(char c)
{
    char a = c;
    if (isLower(c))
    {
        a = a - 32;
        return (a);
    }
    return (a);
} // end toUpper ( )

/**
    Funcao para converter o caractere para maiusculo.
    @return miniscula se maiuscula; miniscula caso contrario.
    @param  char Caractere a ser lido.
*/
char toLower(char c)
{
    char a = c;
    if (isUpper(a))
    {
        a = a + 32;
        return (a);
    } // end if
    return (a);
} // end toLower ( )

#endif