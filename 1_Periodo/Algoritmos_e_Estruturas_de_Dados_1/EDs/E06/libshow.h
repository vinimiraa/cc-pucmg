/**
    Biblioteca Show - IO - Console Input/Output library.
    PUC-Minas - ICEI
    @author  Vinícius Miranda de Araújo
    @version 0.1 - 2023-2b

    LIBSHOW - v2023-2_0.1 - 22 / 08 / 2023
    Author: Vinícius Miranda de Araújo

*/

// ---------------------- lista de dependencias

#include <stdio.h>   // para entradas e saidas
#include <stdlib.h>  // para a biblioteca padrao
#include <stddef.h>  // para definicoes basicas
#include <stdbool.h> // para definicoes logicas
#include <string.h>  // para cadeias de caracteres
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas

// ---------------------- redefinicoes uteis

#ifndef _SHOW_H_
#define _SHOW_H_

#define print printf
#define scan scanf
#define fprint fprintf
#define fscan fscanf

// ---------------------- definicoes de constantes

// #define PI 3.14159265358979323846
// #define E 2.71828182845904523536
const long double PI = 3.14159265358979323846; // definir valor de pi
const long double E = 2.71828182845904523536;  // definir valor do numero de Euler
const int STR_SIZE = 80;                       // definir tamanho padrao para caracteres

// ---------------------- definicoes de variaveis globais

// ---------------------- para entradas e saidas

/**
    Metodo para limpar a entrada de dados padrao.
*/
void flush()
{
    int x = 0;
    do
    {
        x = getchar();
    } while (x != EOF && x != '\n');
    clearerr(stdin); // reiniciar o estado de EOF
} // end flush ( )

/**
    Metodo para identificar o programa.
    @param name Nome do programa.
*/
void id(const char *const name)
{
    print("\n");
    print("%s\n", name);
    print("%s\n", "Autor: Vinicius Miranda de Araujo - 812839");
    print("\n");
} // end id ( )

/*
    Metodo para limpar o terminal
*/
void clear()
{
    system("cls"); // only for windows
} // end clear ( )

// ---------------------- entrada e leitura de dados

/**
    Funcao para ler valor inteiro do teclado.
    @return Valor lido.
    @param  text Mensagem a ser exibida antes da leitura.
*/
int readint(const char *const text)
{
    int x = 0;
    print("%s", text);
    scan("%d", &x);
    flush();
    return (x);
} // end readint ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return Valor lido.
    @param  text Mensagem a ser exibida antes da leitura.
*/
float readfloat(const char *const text)
{
    float x = 0.0;
    print("%s", text);
    scan("%f", &x);
    flush();
    return (x);
} // end readfloat ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return Valor lido.
    @param  text Mensagem a ser exibida antes da leitura.
*/
double readdouble(const char *const text)
{
    double x = 0.0;
    print("%s", text);
    scan("%lf", &x);
    flush();
    return (x);
} // end readdouble ( )

/**
    Funcao para ler valor logico do teclado.
    @return Valor lido.
    @param  text Mensagem a ser exibida antes da leitura.
    OBS.:   Usar zero (0) para falso e
            diferente de zero para verdadeiro
*/
bool readbool(const char *const text)
{
    int x = 0;
    print("%s", text);
    scan("%d", &x);
    flush();
    return (x != 0);
} // end readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return Valor lido.
    @param  text Mensagem a ser exibida antes da leitura.
*/
char readchar(const char *const text)
{
    char x = '0';
    print("%s", text);
    x = getchar();
    flush();
    return (x);
} // end readchar ( )

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text - mensagem a ser exibida antes da leitura
 */
char *readstring(const char *const text)
{
    char *word = (char *)malloc((STR_SIZE + 1) * sizeof(char));
    print("%s", text);
    scan("%80[^\n]", word); // ler cadeia de caracteres
    flush();
    return (word);
} // end readString ( )

// ---------------------- outros procedimentos

/**
    Funcao para ver a quantidade de divisores de um numero.
    @return QUantidade de divisores.
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

// ---------------------- checar dados

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
    Funcao para converter o caractere para maiusculo.
    @return maiuscula se miniscula; maiuscula caso contrario.
    @param  char Caractere a ser lido.
*/
char toUpper(char c)
{
    char a = 0;
    if (isLower(c))
    {
        c = c - 32;
        return (c);
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
    char a = 0;
    if (isUpper(c))
    {
        c = c + 32;
        return (c);
    } // end if
    return (a);
} // end toLower ( )

// ---------------------- estrutura de dados homogeneas

/**
    Funcao para mostrar na tela um vetor.
    @param  array Vetor.
    @param  size Quantidade de elementos do vetor.
*/
void printArray(int vetor[], int n)
{
    int i = 0;
    print("\n");
    for (i = 0; i < n; i = i + 1)
    {
        print("[ %2d ] ", vetor[i]);
    } // end for
    print("\n");
} // end printArray ( )

/**
    Funcao para inverter as posicoes de um vetor.
    @param  array Vetor.
    @param  size Quantidade de elementos do vetor.
*/
void reverseArray(int vetor[], int n)
{
    int i = 0;
    for (i = 0; i < n / 2; i++)
    {
        int aux = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = aux;
    } // end for
} // end reverseArray ( )

/**
    Funcao para retornar o maior elemento de um vetor.
    @param  array Vetor.
    @param  size Quantidade de elementos do vetor.
*/
int maxArray(int vetor[], int n)
{
    int i = 0, maior = 0;
    maior = vetor[0];
    for (i = 0; i < n; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        } // end if
    }     // end for
    return (maior);
} // end maxArray ( )

/**
    Funcao para retornar o menor elemento de um vetor.
    @param  array Vetor.
    @param  size Quantidade de elementos do vetor.
*/
int minArray(int vetor[], int n)
{
    int i = 0, menor = 0;
    menor = vetor[0];
    for (i = 0; i < n; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        } // end if
    }     // end for
    return (menor);
} // end maxArray ( )

/**
    Funcao para mostrar uma matriz.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void printMatrix(int row, int col, const int matrix[][col])
{
    int L = 0, C = 0;
    print("\n");
    for (L = 0; L < row; L = L + 1)
    {
        for (C = 0; C < col; C = C + 1)
        {
            print("[ %2d ] ", matrix[L][C]);
        } // end for
        print("\n");
    } // end for
    print("\n");
} // end printMatrix ( )

/**
    Funcao para mostrar os elementos da diagonal principal de uma matriz.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void leadingMatrix(int row, int col, int matriz[][col])
{
    int L = 0;
    print("\n");
    for (L = 0; L < row; L = L + 1)
    {
        print("[ %2d ] ", matriz[L][L]);
    } // end for
    print("\n");
} // end leadingMatrix ( )

/**
    Funcao para mostrar os elementos da diagonal secundaria de uma matriz.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void secondaryMatrix(int row, int col, int matrix[][col])
{
    int L = 0;
    print("\n");
    for (L = 0; L < row; L = L + 1)
    {
        print("[ %2d ] ", matrix[L][row - 1 - L]);
    } // end for
    print("\n");
} // end secondaryMatrix ( )

/**
    Funcao para mostrar os elementos abaixo da diagonal principal de uma matriz.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void inferiorMatrix(int row, int col, int matrix[][col])
{
    int L = 0, C = 0;
    print("\n");
    for (L = 0; L < row; L = L + 1)
    {
        for (C = 0; C < col; C = C + 1)
        {
            if (L > C)
            {
                print("[ %2d ] ", matrix[L][C]);
            } // end if
        }     // end for
    }         // end for
    print("\n");
} // end inferiorMatrix ( )

/**
    Funcao para mostrar os elementos acima da diagonal principal de uma matriz.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void superiorMatrix(int row, int col, int matrix[][col])
{
    int L = 0, C = 0;
    print("\n");
    for (L = 0; L < row; L = L + 1)
    {
        for (C = 0; C < col; C = C + 1)
        {
            if (L < C)
            {
                print("[ %2d ] ", matrix[L][C]);
            } // end if
        }     // end for
    }         // end for
    print("\n");
} // end superiorMatrix ( )

/**
    Funcao para mostrar uma matriz transposta.
    @param  row Numero de linhas da matriz.
    @param  col Numero de colunas da matriz.
    @param  matrix Matriz.
*/
void transposedMatrix(int row, int col, int matrix[][col])
{
    int L = 0, C = 0;
    int transp[col][row];
    print("\n");
    for (C = 0; C < col; C = C + 1)
    {
        for (L = 0; L < row; L = L + 1)
        {
            transp[C][L] = matrix[L][C];
            print("[ %2d ] ", transp[C][L]);
        } // end for
        print("\n");
    } // end for
    print("\n");
} // end transposedMatrix ( )

#endif