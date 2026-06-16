/*
 Exemplo00E - v0.0. - 10 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo00E exemplo00E.c
 Windows: gcc -o exemplo00E exemplo00E.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo00E
 Windows: exemplo00E
*/
// dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdlib.h>  // para outras funcoes de uso geral
#include <math.h>    // para operacoes matematicas
#include <stdbool.h> // para definicoes booleanas
#include <ctype.h>   // para definicoes com strings
#include <string.h>  // para definicoes com strings
#include <fcntl.h>   // para arquivos
#include "my_lib.h"  // para funcoes proprias
#include "my_def.h"  // para definicoes globais, constantes ...

void CONTAR(int X)
{
    if (X > 0)
    {
        printf("\n%d\n", X);
        CONTAR(X - 1);
    }
} // fim procedimento CONTAR( )
void metodo51()
{
    // PROGRAMA PARA CONTAR 5 10 ATE' 1, RECURSIVAMENTE
    // identificar
    printf("EXEMPLO0602 - CONTAR DE 5 A 1 RECURSIVAMENTE\n");
    CONTAR(5);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo52()
{
    // PROGRAMA PARA CONTAR 5 10 ATE' 1, RECURSIVAMENTE
    // identificar
    printf("EXEMPLO0602 - CONTAR DE 5 A 1 RECURSIVAMENTE\n");
    CONTAR(5);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void PARES_1(int X)
{
    if (X > 0)
    {
        if (X % 2 == 0)
        {
            PARES_1(X - 2);
            printf("\n%d\n", X);
        }
        else
            PARES_1(X - 1);
    }
} // fim procedimento PARES_1 ( )
void metodo53()
{
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES_1
    // identificar
    printf("EXEMPLO0603 - MOSTRAR OS PARES_1 <= 10\n");
    PARES_1(10);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void PARES_2(int X)
{
    if (X > 0)
    {
        PARES_2(X - 1);
        printf("\n%d %c %d\n", X, " ", 2 * X);
    }
} // fim procedimento PARES_2 ( )
void metodo54()
{
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES_2
    // identificar
    printf("EXEMPLO0604 - MOSTRAR OS 5 PRIMEIROS PARES_2\n");
    PARES_2(5);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void PARES_3(int X, int *S)
{
    if (X > 0)
    {
        PARES_3(X - 1, S);
        *S = *S + 2 * X;
    }
    else
        S = 0;
} // fim procedimento PARES_3 ( )
void metodo55()
{
    // PROGRAMA RECURSIVO PARA SOMAR PARES_3
    // DADO:
    int SOMA;
    // identificar
    printf("EXEMPLO0605 - SOMAR OS 5 PRIMEIROS PARES_3\n");
    PARES_3(5, &SOMA);
    printf("\nSOMA DOS 5 PRIMEIROS PARES_3 = %d\n", SOMA);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
int PARES_4(int X)
{
    // DADO:
    int S = 0;
    if (X > 0)
        S = 2 * X + PARES_4(X - 1);
    else
        S = 0;
    return (S);
} // fim funcao PARES_4 ( )
void metodo56()
{
    // PROGRAMA RECURSIVO PARA SOMAR PARES_4
    // DADO :
    int SOMA = 0;
    // identificar
    printf("EXEMPLO0606 - SOMAR OS 5 PRIMEIROS PARES_4\n");
    SOMA = PARES_4(5);
    printf("\nSOMA DOS 5 PRIMEIROS PARES_4 = %d\n", SOMA);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
int PARES_5(int X)
{
    // DADO :
    int S = 0;
    if (X > 0)
        if (X % 2 == 0)
            S = 1 + PARES_5(X - 2);
        else
            S = PARES_5(X - 1);
    else
        S = 0;
    return (S);
} // fim funcao PARES_5 ( )
void metodo57()
{
    // PROGRAMA RECURSIVO PARA CONTAR PARES_5
    // identificar
    printf("EXEMPLO0607 - CONTAR OS PARES_5 <= 10\n");
    printf("\nPARES <= 10 = %d\n", PARES_5(10));
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
typedef char STRING30[30];
bool PROCURAR_1(char LETRA, STRING30 S, int POSICAO)
{
    // DADO :
    bool R = false;
    if (POSICAO <= strlen(S))
        R = (S[POSICAO] == LETRA) || PROCURAR_1(LETRA, S, POSICAO + 1);
    else
        R = false;
    return (R);
} // fim funcao PROCURAR_1 ( )
void metodo58()
{
    // PROGRAMA RECURSIVO PARA ACHAR A POSICAO DE UMA LETRA
    // DADO :
    char L = '_';
    STRING30 S = "";
    // identificar
    printf("EXEMPLO0608 - PROCURAR_1 UMA LETRA EM UMA SENTENCA\n");
    printf("\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ");
    gets(S);
    printf("\nFORNECER UMA LETRA PARA SER PROCURADA : ");
    L = getchar();
    getchar(); // para limpar a entrada de dados
    printf("\nRESPOSTA = %d\n", PROCURAR_1(L, S, 0));
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
int PROCURAR_2(char LETRA, STRING30 S, int POSICAO)
{
    // DADO :
    int R = 0;
    if (POSICAO <= strlen(S))
        if (S[POSICAO] == LETRA)
            R = POSICAO + 1; // a primeira posicao e' 0 !
        else
            R = PROCURAR_2(LETRA, S, POSICAO + 1);
    else
        R = 0;
    return (R);
} // fim funcao PROCURAR_2 ( )
void metodo59()
{
    // PROGRAMA RECURSIVO PARA PROCURAR_2 UMA LETRA
    // DADO :
    char L = '_';
    STRING30 S = "";
    // identificar
    printf("EXEMPLO0609 - POSICAO DE UMA LETRA EM UMA SENTENCA\n");
    printf("\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ");
    gets(S);
    printf("\nFORNECER UMA LETRA PARA SER PROCURADA : ");
    L = getchar();
    getchar(); // para limpar a entrada de dados
    printf("\nRESPOSTA = %d\n", PROCURAR_2(L, S, 0));
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
int PROCURAR_3(char LETRA, STRING30 S, int POSICAO)
{
    // DADO :
    int R = 0;
    if (POSICAO <= strlen(S))
        if (S[POSICAO] == LETRA)
            R = 1 + PROCURAR_3(LETRA, S, POSICAO + 1);
        else
            R = PROCURAR_3(LETRA, S, POSICAO + 1);
    else
        R = 0;
    return (R);
} // fim funcao PROCURAR_3 ( )
void metodo60()
{
    // PROGRAMA RECURSIVO PARA PROCURAR_3 OCORRENCIAS DE UMA LETRA
    // DADO :
    char L = '_';
    STRING30 S = "";
    printf("EXEMPLO0610 - PROCURAR_3 OCORRENCIAS DE UMA LETRA\n");
    printf("\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : ");
    gets(S);
    printf("\nFORNECER UMA LETRA PARA SER PROCURADA : ");
    L = getchar();
    getchar(); // para limpar a entrada de dados
    printf("\nRESPOSTA = %d\n", PROCURAR_3(L, S, 0));
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo61()
{
    typedef int TABELA[10];
    // PROGRAMA PARA LER UMA TABELA DE INTEIROS
    // VARIAVEIS:
    TABELA V;
    int X = 0;
    // identificar
    printf("EXEMPLO0701 - LER UM TABELA DE 10 INTEIROS\n");
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
    { // a primeira posicao e' zero !
        printf("\nFORNECER O %d o. INTEIRO : ", (X + 1));
        scanf("%d", &V[X]);
        getchar(); // para limpar a entrada de dados
    }              // FIM REPETIR
    printf("\nVETOR LIDO: \n");
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
    {
        printf("%d ", V[X]);
    } // FIM REPETIR
      // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo62()
{
    typedef int TABELA[10];
    // PROGRAMA PARA SOMAR UMA TABELA DE INTEIROS
    // VARIAVEIS :
    TABELA V;
    int X = 0,
        SOMA = 0;
    // identificar
    printf("EXEMPLO0702 - SOMAR UM TABELA DE 10 INTEIROS\n");
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
    {
        printf("\nFORNECER O %do. INTEIRO : ", (X + 1));
        scanf("%d", &V[X]);
        getchar(); // para limpar a entrada de dados
    }              // FIM REPETIR
    SOMA = 0;
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
        SOMA = SOMA + V[X];
    printf("\nSOMA = %d", SOMA);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo63()
{
    typedef int TABELA[10];
    // PROGRAMA PARA CALCULAR A MEDIA DE UMA TABELA DE INTEIROS
    // VARIAVEIS :
    TABELA V;
    float MEDIA = 0.0;
    int X = 0,
        SOMA = 0;
    // identificar
    printf("EXEMPLO0703 - MEDIA DE UMA TABELA DE 10 INTEIROS\n");
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
    {
        printf("\nFORNECER O %do. INTEIRO : ", (X + 1));
        scanf("%d", &V[X]);
        getchar(); // para limpar a entrada de dados
    }              // FIM REPETIR
    SOMA = 0;
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 10; X++)
        SOMA = SOMA + V[X];
    MEDIA = SOMA / 10.0;
    printf("\nMEDIA = %f\n", MEDIA);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo64()
{
    typedef char STRING10[10];
    // PROGRAMA PARA LER UMA PALAVRA
    // VARIAVEIS :
    STRING10 PALAVRA;
    int X = 0;
    // identificar
    printf("EXEMPLO0704 - LER UMA PALAVRA\n");
    printf("\nFORNECER UMA PALAVRA (NO MAXIMO 09 LETRAS) : ");
    gets(PALAVRA);
    printf("\nLETRAS DA PALAVRA LIDA : ");
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < strlen(PALAVRA); X++)
        printf("%c ", PALAVRA[X]);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo65()
{
    typedef char STRING10[10];
    // PROGRAMA PARA PROCURAR LETRA EM PALAVRA
    // VARIAVEIS :
    STRING10 PALAVRA;
    char LETRA = '_';
    int X = 0;
    bool ACHAR = false;
    // identificar
    printf("EXEMPLO0705 - PROCURAR LETRA EM UMA PALAVRA\n");
    printf("\nDIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : ");
    gets(PALAVRA);
    printf("\nFORNECER A LETRA A SER PROCURADA : ");
    LETRA = getchar();
    getchar(); // para limpar a entrada de dados
    ACHAR = false;
    X = 0;
    // REPETIR PARA CADA POSICAO
    while (X < strlen(PALAVRA) && !ACHAR)
    {
        if (PALAVRA[X] == LETRA)
            ACHAR = true;
        else
            X = X + 1;
    } // FIM REPETIR
    if (ACHAR)
        printf("LETRA ENCONTRADA");
    else
        printf("LETRA NAO ENCONTRADA");
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo66()
{
    typedef double POLINOMIO[10 + 1]; // posicoes de 0:10
                                      // PROGRAMA PARA AVALIAR UM POLINOMIO
                                      // VARIAVEIS :
    POLINOMIO P;
    int Y = 0, N = 0;
    double X = 0.0, PX = 0.0;
    // identificar
    printf("EXEMPLO0706 - LER COEFICIENTES DE UM POLINOMIO\n");
    printf("\nFORNECER O GRAU DO POLINOMIO : ");
    scanf("%d", &N);
    getchar(); // para limpar a entrada de dados
               // REPETIR PARA CADA POSICAO
    for (Y = 0; Y <= N; Y++)
    {
        printf("\nFORNECER O %do. COEFICIENTE : ", (Y + 1));
        scanf("%lf", &P[Y]);
        getchar(); // para limpar a entrada de dados
    }              // FIM REPETIR
    printf("\nFORNECER O PONTO DE AVALIACAO : ");
    scanf("%lf", &X);
    getchar(); // para limpar a entrada de dados
    PX = 0.0;
    // REPETIR PARA CADA POSICAO
    // DA ULTIMA ATE' A PRIMEIRA
    for (Y = N; Y >= 0; Y--)
        PX = PX * X + P[Y];
    printf("\nP(%lf) = %lf", X, PX);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo67()
{
    typedef int VETOR[3]; // X,Y,Z
                          // PROGRAMA PARA AVALIAR O COMPRIMENTO DE UM VETOR
                          // VARIAVEIS :
    VETOR V;
    int X = 0;
    double SOMA = 0.0;
    // identificar
    printf("EXEMPLO0707 - COMPRIMENTO DE UM VETOR\n");
    printf("\nFORNECER O VALOR DE X : ");
    scanf("%d", &V[0]);
    getchar(); // para limpar a entrada de dados
    printf("\nFORNECER O VALOR DE Y : ");
    scanf("%d", &V[1]);
    getchar(); // para limpar a entrada de dados
    printf("\nFORNECER O VALOR DE Z : ");
    scanf("%d", &V[2]);
    getchar(); // para limpar a entrada de dados
    SOMA = 0.0;
    // REPETIR PARA CADA POSICAO
    for (X = 0; X < 3; X++)
        SOMA = SOMA + V[X] * V[X];
    printf("\nCOMPRIMENTO = %lf", sqrt(SOMA));
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo68()
{
    typedef int MATRIZ[2][2];
    // PROGRAMA PARA LER UMA MATRIZ
    // VARIAVEIS :
    MATRIZ M;
    int X = 0, Y = 0;
    // identificar
    printf("EXEMPLO0708 - LER UMA MATRIZ INTEIRA 2x2\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < 2; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < 2; Y++)
        {
            printf("\nFORNECER ELEMENTO %d, %d : ", (X + 1), (Y + 1));
            scanf("%d", &M[X][Y]);
            getchar(); // para limpar a entrada de dados
        }              // FIM REPETIR
    }                  // FIM REPETIR
    printf("\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < 2; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < 2; Y++)
            printf("%d ", M[X][Y]);
        printf("\n");
    } // FIM REPETIR
      // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo69()
{
    typedef int MATRIZ[2][2];
    // PROGRAMA PARA MONTAR A TRANSPOSTA DE UMA MATRIZ
    // VARIAVEIS :
    MATRIZ M, // MATRIZ ORIGINAL
        MT;   // MATRIZ TRANSPOSTA
    int X = 0, Y = 0;
    // identificar
    printf("EXEMPLO0709 - TRANSPOR UMA MATRIZ INTEIRA 2x2\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < 2; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < 2; Y++)
        {
            printf("\nFORNECER ELEMENTO %d, %d : ", (X + 1), (Y + 1));
            scanf("%d", &M[X][Y]);
            getchar(); // para limpar a entrada de dados
            MT[Y][X] = M[X][Y];
        } // FIM REPETIR
    }     // FIM REPETIR
    printf("\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < 2; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < 2; Y++)
            printf("%d ", M[X][Y]);
        printf("\n");
    } // FIM REPETIR
      // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo70()
{
#define ORDEM 3
    typedef int MATRIZ[ORDEM][ORDEM];
    // PROGRAMA PARA MOSTRAR A DIAGONAL DE UMA MATRIZ
    // VARIAVEIS :
    MATRIZ M;
    int X = 0, Y = 0;
    // identificar
    printf("EXEMPLO0710 - MOSTRAR A DIAGONAL DE UMA MATRIZ\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < ORDEM; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < ORDEM; Y++)
        {
            printf("\nFORNECER ELEMENTO %d, %d : ", (X + 1), (Y + 1));
            scanf("%d", &M[X][Y]);
            getchar(); // para limpar a entrada de dados
        }              // FIM REPETIR
    }                  // FIM REPETIR
    printf("\n");
    // REPETIR PARA CADA LINHA
    for (X = 0; X < ORDEM; X++)
    { // REPETIR PARA CADA COLUNA
        for (Y = 0; Y < ORDEM; Y++)
        {
            if (X == Y) // SE ESTIVER NA DIAGONAL
                printf("%d ", M[X][Y]);
        } // FIM REPETIR
    }     // FIM REPETIR
          // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo71()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P1, P2, P3;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0801 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P1.X, &P1.Y, &P1.Z);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &P2.X, &P2.Y, &P2.Z);
    getchar(); // para limpar a entrada de dados
    P3.X = P2.X - P1.X;
    P3.Y = P2.Y - P1.Y;
    P3.Z = P2.Z - P1.Z;
    D = sqrt(pow(P3.X, 2.0) +
             pow(P3.Y, 2.0) +
             pow(P3.Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo72()
{
    typedef struct SPONTOS
    {
        float X, Y, Z;
    } PONTOS;
    // PROGRAM PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P1, P2;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0802 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P1.X, &P1.Y, &P1.Z);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &P2.X, &P2.Y, &P2.Z);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P2.X - P1.X, 2.0) +
             pow(P2.Y - P1.Y, 2.0) +
             pow(P2.Z - P1.Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo73()
{
    typedef struct SPONTOS
    {
        float X, Y, Z;
    } PONTOS;
    typedef PONTOS VETOR[2];
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    VETOR V;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0803 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &V[0].X, &V[0].Y, &V[0].Z);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &V[1].X, &V[1].Y, &V[1].Z);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(V[1].X - V[0].X, 2.0) +
             pow(V[1].Y - V[0].Y, 2.0) +
             pow(V[1].Z - V[0].Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo74()
{
    typedef double PONTOS[3]; // X, Y, Z
    typedef struct SVETOR
    {
        PONTOS P1, P2;
    } VETOR;
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    VETOR V;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0804 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &V.P1[0], &V.P1[1], &V.P1[2]);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &V.P2[0], &V.P2[1], &V.P2[2]);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(V.P2[0] - V.P1[0], 2.0) +
             pow(V.P2[1] - V.P1[1], 2.0) +
             pow(V.P2[2] - V.P1[2], 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo75()
{
    typedef struct SPONTO
    {
        double X, Y, Z;
    } PONTO;
    typedef struct SPONTOS
    {
        PONTO P1, P2;
    } PONTOS;
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0805 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &P.P2.X, &P.P2.Y, &P.P2.Z);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P.P2.X - P.P1.X, 2.0) +
             pow(P.P2.Y - P.P1.Y, 2.0) +
             pow(P.P2.Z - P.P1.Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo76()
{
    typedef struct SPONTO
    {
        double X, Y, Z;
    } PONTO;
    typedef double VETOR[3]; // X, Y, Z
    typedef struct SPONTOS
    {
        PONTO P1;
        VETOR P2;
    } PONTOS;
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0806 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &P.P2[0], &P.P2[1], &P.P2[2]);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P.P2[0] - P.P1.X, 2.0) +
             pow(P.P2[1] - P.P1.Y, 2.0) +
             pow(P.P2[2] - P.P1.Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo77()
{
    typedef double VETOR[3]; // X, Y, Z
    typedef VETOR PONTOS[2];
    // PROGRAMA PARA CALCULAR
    // A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0807 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2]);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2]);
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P[1][0] - P[0][0], 2.0) +
             pow(P[1][1] - P[0][1], 2.0) +
             pow(P[1][2] - P[0][2], 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo78()
{
    typedef double VETOR1[3]; // X, Y, Z
    typedef VETOR1 VETOR[2];
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    VETOR P;
    double D = 0.0;
    printf("EXEMPLO0808 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2]);
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    getchar(); // para limpar a entrada de dados
    scanf("%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2]);
    D = sqrt(pow(P[1][0] - P[0][0], 2.0) +
             pow(P[1][1] - P[0][1], 2.0) +
             pow(P[1][2] - P[0][2], 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo79()
{
    typedef struct SPONTO
    {
        double X, Y, Z;
    } PONTO;
    typedef PONTO VETOR[2]; // X, Y, Z
                            // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
                            // DADOS:
    VETOR P;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0809 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf%lf%lf", &(P[0].X), &(P[0].Y), &(P[0].Z));
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf%lf%lf", &(P[1].X), &(P[1].Y), &(P[1].Z));
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P[1].X - P[0].X, 2.0) +
             pow(P[1].Y - P[0].Y, 2.0) +
             pow(P[1].Z - P[0].Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo80()
{
    typedef struct SPONTO
    {
        double X, Y, Z;
    } PONTO;
    typedef struct SPONTOS
    {
        PONTO P1, P2;
    } PONTOS;
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
    // DADOS:
    PONTOS P;
    double D = 0.0;
    // identificar
    printf("EXEMPLO0810 - DISTANCIA ENTRE PONTOS\n");
    printf("\n ENTRE COM O PRIMEIRO PONTO : \n ");
    scanf("%lf%lf%lf", &(P.P1.X), &(P.P1.Y), &(P.P1.Z));
    getchar(); // para limpar a entrada de dados
    printf("\n ENTRE COM O SEGUNDO PONTO : \n ");
    scanf("%lf%lf%lf", &(P.P2.X), &(P.P2.Y), &(P.P2.Z));
    getchar(); // para limpar a entrada de dados
    D = sqrt(pow(P.P2.X - P.P1.X, 2.0) +
             pow(P.P2.Y - P.P1.Y, 2.0) +
             pow(P.P2.Z - P.P1.Z, 2.0));
    printf("\n DISTANCIA = %lf", D);
    // encerrar
    printf("\n\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo81()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0901 - GRAVAR COORDENADAS DE PONTOS \n");
    A = fopen("PONTOS1.TXT", "wt");
    for (X = 1; X <= 2; X++)
    {
        printf("\nENTRE COM AS COORDENADAS DE UM PONTO : \n");
        scanf("%lf%lf%lf", &P.X, &P.Y, &P.Z);
        getchar(); // para limpar a entrada de dados
        fprintf(A, "%lf %lf %lf\n", P.X, P.Y, P.Z);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo82()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA LER ARQUIVO DE PONTOS
    // VARIAVEIS :
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0902 - LER ARQUIVO DE PONTOS \n");
    A = fopen("PONTOS1.TXT", "rt");
    for (X = 1; X <= 2; X++)
    {
        fscanf(A, "%lf%lf%lf", &P.X, &P.Y, &P.Z);
        printf("\nPONTO %d : %lf %lf %lf", X, P.X, P.Y, P.Z);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo83()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0903 - GRAVAR COORDENADAS DE PONTOS \n");
    A = fopen("PONTOS2.DAT", "wb");
    for (X = 1; X <= 2; X++)
    {
        printf("\nENTRE COM AS COORDENADAS DE UM PONTO : \n");
        scanf("%lf%lf%lf", &P.X, &P.Y, &P.Z);
        getchar(); // para limpar a entrada de dados
        fwrite(&P, sizeof(PONTOS), 1, A);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo84()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA LER ARQUIVO DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0904 - LER ARQUIVO DE PONTOS \n");
    A = fopen("PONTOS2.DAT", "rb");
    for (X = 1; X <= 2; X++)
    {
        fread(&P, sizeof(PONTOS), 1, A);
        printf("\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo85()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA COPIAR O ARQUIVO COM COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A1, *A2;
    // identificar
    printf("EXEMPLO0905 - COPIAR COORDENADAS DE PONTOS \n");
    A1 = fopen("PONTOS1.TXT", "rt");
    A2 = fopen("NOVO1.DAT", "wb");
    for (X = 1; X <= 2; X++)
    {
        fscanf(A1, "%lf%lf%lf\n", &P.X, &P.Y, &P.Z);
        fwrite(&P, sizeof(PONTOS), 1, A2);
        printf("\nCOPIADO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z);
    } // FIM REPETIR
    fclose(A1);
    fclose(A2);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo86()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0906 - ACRESCENTAR COORDENADAS DE PONTOS \n");
    A = fopen("PONTOS2.DAT", "r+b");
    while (!feof(A))
        fread(&P, sizeof(PONTOS), 1, A); // LER ATE' O FIM DE ARQUIVO
    fseek(A, 0L, SEEK_CUR);              // MARCAR A POSICAO
    for (X = 3; X <= 4; X++)
    {
        printf("\nENTRE COM AS COORDENADAS DE OUTRO PONTO (%d): \n", X);
        scanf("%lf%lf%lf", &P.X, &P.Y, &P.Z);
        getchar(); // para limpar a entrada de dados
        fwrite(&P, sizeof(PONTOS), 1, A);
    }                                // FIM REPETIR
    fseek(A, 0L, SEEK_SET);          // VOLTAR AO INICIO
    fread(&P, sizeof(PONTOS), 1, A); // LER O PRIMEIRO DO ARQUIVO
    while (!feof(A))
    {
        printf("\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z);
        fread(&P, sizeof(PONTOS), 1, A); // LER ATE' O FIM DE ARQUIVO
    }                                    // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo87()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0907 - ACRESCENTAR COORDENADAS DE PONTOS \n");
    A = fopen("PONTOS1.TXT", "at");
    for (X = 1; X <= 2; X++)
    {
        printf("\nENTRE COM AS COORDENADAS DE OUTRO PONTO : \n");
        scanf("%lf%lf%lf", &P.X, &P.Y, &P.Z);
        getchar(); // para limpar a entrada de dados
        fprintf(A, "%Lf %Lf %Lf", P.X, P.Y, P.Z);
        fprintf(A, "%s", "\n");
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo88()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA PROCURAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P,
        PROCURADO;
    bool ACHAR = false;
    FILE *A;
    // identificar
    printf("EXEMPLO0908 - PROCURAR COORDENADAS DE PONTOS \n");
    printf("\nENTRE COM AS COORDENADAS DO PONTO A PROCURAR : \n");
    scanf("%lf%lf%lf", &PROCURADO.X, &PROCURADO.Y, &PROCURADO.Z);
    ACHAR = false;
    A = fopen("PONTOS1.TXT", "rt");
    fscanf(A, "%lf %lf %lf", &P.X, &P.Y, &P.Z);
    while (!feof(A) && !ACHAR)
    {
        if (P.X == PROCURADO.X && P.Y == PROCURADO.Y && P.Z == PROCURADO.Z)
            ACHAR = true;
        fscanf(A, "%lf%lf%lf", &P.X, &P.Y, &P.Z);
    } // FIM REPETIR
    fclose(A);
    if (ACHAR)
        printf("\nCOORDENADAS ENCONTRADAS");
    else
        printf("\nCOORDENADAS NAO ENCONTRADAS");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo89()
{
    typedef struct SPONTOS
    {
        float X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA ALTERAR COORDENADAS DE PONTOS
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0909 - ALTERAR COORDENADAS DE PONTOS \n");
    A = fopen("PONTOS2.DAT", "r+b");
    for (X = 1; X <= 2; X++)
    {
        fseek(A, (X - 1) * sizeof(PONTOS), SEEK_SET); // o primeiro e' zero
        fread(&P, sizeof(PONTOS), 1, A);
        printf("\nATUAL %d : %6.2Lf %6.2Lf %6.2Lf\n", X, P.X, P.Y, P.Z);
        printf("\nENTRE COM AS NOVAS COORDENADAS DO PONTO : \n");
        scanf("%lf%lf%lf", &P.X, &P.Y, &P.Z);
        getchar(); // para limpar a entrada de dados
        fseek(A, (X - 1) * sizeof(PONTOS), SEEK_SET);
        fwrite(&P, sizeof(PONTOS), 1, A);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo90()
{
    typedef struct SPONTOS
    {
        double X, Y, Z;
    } PONTOS;
    // PROGRAMA PARA LER ARQUIVO DE PONTOS DIRETAMENTE
    // DADOS:
    PONTOS P;
    int X = 0;
    FILE *A;
    // identificar
    printf("EXEMPLO0910 - LER ARQUIVO DE PONTOS DIRETAMENTE \n");
    A = fopen("PONTOS2.DAT", "r");
    for (X = 2; X > 0; X--)
    {
        fseek(A, (X - 1) * sizeof(PONTOS), SEEK_SET); // o primeiro e' zero
        fread(&P, sizeof(PONTOS), 1, A);
        printf("\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z);
    } // FIM REPETIR
    fclose(A);
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo91()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
    // DADOS:
    CELULA P;
    P.VALOR = 0;
    P.LINK = NULL;
    // identificar
    printf("EXEMPLO1001 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &P.VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", P.VALOR, P.LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo92()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
    // DADOS:
    CELULA *P;                      // APONTADOR PARA CELULA
    P = malloc(1 * sizeof(CELULA)); // RESERVAR ESPACO
    (*P).VALOR = 0;
    (*P).LINK = NULL;
    // identificar
    printf("EXEMPLO1002 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &(*P).VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", (*P).VALOR, (*P).LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

void metodo93()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
    // DADOS:
    CELULA *P;                      // APONTADOR PARA CELULA
    P = malloc(1 * sizeof(CELULA)); // RESERVAR ESPACO
    P->VALOR = 0;                   // OUTRA NOTACAO
    P->LINK = NULL;
    // identificar
    printf("EXEMPLO1003 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &P->VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", P->VALOR, P->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

void metodo94()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
    // DADOS:
    CELULA *P;                     // APONTADOR PARA CELULA
    P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
    P->VALOR = 0;                  // OUTRA NOTACAO
    P->LINK = NULL;
    // identificar
    printf("EXEMPLO1004 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &P->VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", P->VALOR, P->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

void metodo95()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *
        REF_CELULA;
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
    // DADOS:
    REF_CELULA P;                  // APONTADOR PARA CELULA
    P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
    P->VALOR = 0;                  // OUTRA NOTACAO
    P->LINK = NULL;
    // identificar
    printf("EXEMPLO1005 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &P->VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", P->VALOR, P->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

void metodo96()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *
        REF_CELULA;
    REF_CELULA NEW_CELULA1(int INICIAL)
    {
        REF_CELULA P;                  // APONTADOR PARA CELULA
        P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
        P->VALOR = INICIAL;            // OUTRA NOTACAO
        P->LINK = NULL;
        return (P);
    }                              // fim funcao NEW_CELULA ( )
                                   // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
                                   // DADOS:
    REF_CELULA P = NEW_CELULA1(0); // APONTADOR PARA CELULA
                                   // identificar
    printf("EXEMPLO1006 - MONTAR CELULA \n");
    printf("VALOR = ");
    scanf("%d", &P->VALOR);
    getchar();
    printf("VALOR = %d LINK = %p\n", P->VALOR, P->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

void metodo97()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *REF_CELULA;
    REF_CELULA NEW_CELULA2(int INICIAL)
    {
        REF_CELULA P;                  // APONTADOR PARA CELULA
        P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
        P->VALOR = INICIAL;            // OUTRA NOTACAO
        P->LINK = NULL;
        return (P);
    }                               // fim funcao NEW_CELULA ( )
                                    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
                                    // DADOS:
    REF_CELULA P1 = NEW_CELULA2(0); // APONTADOR PARA CELULA
    REF_CELULA P2 = NEW_CELULA2(0); // APONTADOR PARA CELULA
                                    // identificar
    printf("EXEMPLO1007 - MONTAR CELULAS \n");
    printf("P1: VALOR = ");
    scanf("%d", &P1->VALOR);
    getchar();
    printf("P2: VALOR = ");
    scanf("%d", &P2->VALOR);
    getchar();
    printf("P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK);
    printf("P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK);
    P1->LINK = P2; // ligar uma celula a outra
    printf("P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK);
    printf("P2: VALOR = %d LINK = %p\n",
           P1->LINK->VALOR, P1->LINK->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo98()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *REF_CELULA;
    REF_CELULA NEW_CELULA3(int INICIAL)
    {
        REF_CELULA P;                  // APONTADOR PARA CELULA
        P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
        P->VALOR = INICIAL;            // OUTRA NOTACAO
        P->LINK = NULL;
        return (P);
    }                               // fim funcao NEW_CELULA ( )
                                    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
                                    // DADOS:
    REF_CELULA P1 = NEW_CELULA3(0); // APONTADOR PARA CELULA
    REF_CELULA P2 = NEW_CELULA3(0); // APONTADOR PARA CELULA
                                    // identificar
    printf("EXEMPLO1008 - MONTAR CELULAS \n");
    printf("P1: VALOR = ");
    scanf("%d", &P1->VALOR);
    getchar();
    printf("P2: VALOR = ");
    scanf("%d", &P2->VALOR);
    getchar();
    printf("P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK);
    printf("P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK);
    P1->LINK = P2; // ligar uma celula a outra
    P2 = NEW_CELULA3(0);
    printf("P3: VALOR = ");
    scanf("%d", &P2->VALOR);
    getchar();
    P1->LINK->LINK = P2; // ligar 'a terceira
    printf("P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK);
    printf("P2: VALOR = %d LINK = %p\n",
           P1->LINK->VALOR, P1->LINK->LINK);
    printf("P3: VALOR = %d LINK = %p\n",
           P1->LINK->LINK->VALOR, P1->LINK->LINK->LINK);
    printf("\n");
    // encerrar
    printf("\nAPERTAR<Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo99()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *REF_CELULA;
    REF_CELULA NEW_CELULA4(int INICIAL)
    {
        REF_CELULA P;                  // APONTADOR PARA CELULA
        P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
        P->VALOR = INICIAL;            // OUTRA NOTACAO
        P->LINK = NULL;
        return (P);
    }                               // fim funcao NEW_CELULA ( )
                                    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
                                    // DADOS:
    REF_CELULA P1 = NEW_CELULA4(0); // APONTADOR PARA CELULA
    REF_CELULA P2 = NEW_CELULA4(0); // APONTADOR PARA CELULA
                                    // identificar
    printf("EXEMPLO1009 - MONTAR CELULAS \n");
    printf("P1: VALOR = ");
    scanf("%d", &P1->VALOR);
    getchar();
    printf("P2: VALOR = ");
    scanf("%d", &P2->VALOR);
    getchar();
    printf("P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK);
    printf("P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK);
    P1->LINK = P2; // ligar uma celula a outra
    P2 = NEW_CELULA4(0);
    printf("P3: VALOR = ");
    scanf("%d", &P2->VALOR);
    getchar();
    P1->LINK->LINK = P2; // ligar 'a terceira
    P2 = P1;             // comecar no primeiro
    while (P2 != NULL)
    { // mostrar valor
        printf("VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK);
        P2 = P2->LINK; // passar ao proximo
    }                  // end while
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}
void metodo100()
{
    typedef struct S_CELULA
    {
        int VALOR;
        struct S_CELULA *LINK;
    } CELULA;
    typedef struct S_CELULA *REF_CELULA;
    REF_CELULA NEW_CELULA5(int INICIAL)
    {
        REF_CELULA P;                  // APONTADOR PARA CELULA
        P = calloc(1, sizeof(CELULA)); // OUTRA FORMA DE RESERVAR
        P->VALOR = INICIAL;            // OUTRA NOTACAO
        P->LINK = NULL;
        return (P);
    }                     // fim funcao NEW_CELULA ( )
                          // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
                          // DADOS:
    REF_CELULA P1 = NULL; // APONTADOR ESTRUTURAL
    REF_CELULA P2 = NULL; // APONTADOR DE SERVICO
    int x = 0, y = 0;
    // identificar
    printf("EXEMPLO1010 - MONTAR CELULAS \n");
    printf("VALOR = ");
    scanf("%d", &x);
    getchar();
    P1 = NEW_CELULA5(x); // montar o primeiro
    for (y = 0; y < 4; y = y + 1)
    {
        printf("VALOR = ");
        scanf("%d", &x);
        getchar();
        P2 = P1;                 // comecar no primeiro
        while (P2->LINK != NULL) // procurar o ultimo
            P2 = P2->LINK;
        P2->LINK = NEW_CELULA5(x); // anexar mais outro
    }                             // end for
    P2 = P1;                      // comecar no primeiro
    while (P2 != NULL)
    { // mostrar valor
        printf("VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK);
        P2 = P2->LINK; // passar ao proximo
    }                  // end while
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR");
    getchar(); // para esperar
}

// ------------------------------------------------ fim metodos principais

void identificacao()
{
    printf("\n");
    printf("Exemplo000 - Programa = v0.0\n");
    printf("Autor: Vinicius Miranda de Araujo\n");
    printf("\n");
}
void menu()
{
    // para mostrar opcoes
    printf("Escolha alguma das opcoes a seguir:\n\n");
    printf("51 - Metodo51     76 - Metodo76\n");
    printf("52 - Metodo52     77 - Metodo77\n");
    printf("53 - Metodo53     78 - Metodo78\n");
    printf("54 - Metodo54     79 - Metodo79\n");
    printf("55 - Metodo55     80 - Metodo80\n");
    printf("56 - Metodo56     81 - Metodo81\n");
    printf("57 - Metodo57     82 - Metodo82\n");
    printf("58 - Metodo58     83 - Metodo83\n");
    printf("59 - Metodo59     84 - Metodo84\n");
    printf("60 - Metodo61     85 - Metodo85\n");
    printf("61 - Metodo61     86 - Metodo86\n");
    printf("62 - Metodo62     87 - Metodo87\n");
    printf("63 - Metodo63     88 - Metodo88\n");
    printf("64 - Metodo64     89 - Metodo89\n");
    printf("65 - Metodo65     90 - Metodo90\n");
    printf("66 - Metodo66     91 - Metodo91\n");
    printf("67 - Metodo67     92 - Metodo92\n");
    printf("68 - Metodo68     93 - Metodo93\n");
    printf("69 - Metodo09     94 - Metodo94\n");
    printf("70 - Metodo71     95 - Metodo95\n");
    printf("71 - Metodo71     96 - Metodo96\n");
    printf("72 - Metodo72     97 - Metodo97\n");
    printf("73 - Metodo73     98 - Metodo98\n");
    printf("74 - Metodo74     99 - Metodo99\n");
    printf("75 - Metodo75    100 - Metodo100\n");
    printf("     0 - Encerrar programa "      );
}
/*
 Funcao principal
*/
int main()
{
    int opcao = 0;

    identificacao();

    do
    {
        // para mostrar opcoes
        menu();
        // ler a opcao do teclado
        printf("\n%s", "Opcao = ");
        scanf("%d", &opcao);
        getchar(); // para limpar a entrada de dados
        // para mostrar a opcao lida
        printf("\n============   %s %d   ============\n\n", "Opcao", opcao);
        // escolher acao dependente da opcao
        switch (opcao)
        {
        case 0: // nao fazer nada
            break;
        case 51: // executar metodo 01
            metodo51();
            break;
        case 52:
            metodo52();
            break;
        case 53:
            metodo53();
            break;
        case 54:
            metodo54();
            break;
        case 55:
            metodo55();
            break;
        case 56:
            metodo56();
            break;
        case 57:
            metodo57();
            break;
        case 58:
            metodo58();
            break;
        case 59:
            metodo59();
            break;
        case 60:
            metodo60();
            break;
        case 61:
            metodo61();
            break;
        case 62:
            metodo62();
            break;
        case 63:
            metodo63();
            break;
        case 64:
            metodo64();
            break;
        case 65:
            metodo65();
            break;
        case 66:
            metodo66();
            break;
        case 67:
            metodo67();
            break;
        case 68:
            metodo69();
            break;
        case 70:
            metodo70();
            break;
        case 71:
            metodo71();
            break;
        case 72:
            metodo72();
            break;
        case 73:
            metodo73();
            break;
        case 74:
            metodo74();
            break;
        case 75:
            metodo75();
            break;
        case 76:
            metodo76();
            break;
        case 77:
            metodo77();
            break;
        case 78:
            metodo78();
            break;
        case 79:
            metodo79();
            break;
        case 80:
            metodo80();
            break;
        case 81:
            metodo81();
            break;
        case 82:
            metodo82();
            break;
        case 83:
            metodo83();
            break;
        case 84:
            metodo84();
            break;
        case 85:
            metodo85();
            break;
        case 86:
            metodo86();
            break;
        case 87:
            metodo87();
            break;
        case 88:
            metodo88();
            break;
        case 89:
            metodo89();
            break;
        case 90:
            metodo90();
            break;
        case 91:
            metodo91();
            break;
        case 92:
            metodo92();
            break;
        case 93:
            metodo93();
            break;
        case 94:
            metodo94();
            break;
        case 95:
            metodo95();
            break;
        case 96:
            metodo96();
            break;
        case 97:
            metodo97();
            break;
        case 98:
            metodo98();
            break;
        case 99:
            metodo99();
            break;
        case 100:
            metodo100();
            break;
        default: // comportamento padrao
            printf("\nERRO: Opcao invalida.\n");
            break;
        } // end switch
        
        if(opcao == 0)
        {
            printf("Programa Encerrado!\n");
        } // end if

        printf("\n============ %s %d ============\n\n", "Fim Opcao", opcao);
    } while (opcao != 0);
    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar(); // aguardar por ENTER

    return (0); // voltar ao SO (sem erros)
} // end main ( )

/*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) 0.5
  b.) -0.5
  c.) 1.23456789
  ---------------------------------------------- historico
  Versao Data Modificacao
  0.1 __/__ esboco
  0.2 __/__ mudanca de versao
  ---------------------------------------------- testes
  Versao Teste
  0.0 00. ( OK ) identificacao de programa
  0.1 01. ( OK ) identificacao de programa
  0.2 02. ( OK ) identificacao de programa
  leitura e exibicao de inteiro
  0.3 03. ( OK ) identificacao de programa
  leitura e exibicao mediante escolha
  0.4 04. ( OK ) identificacao de programa
  leitura e exibicao mediante escolha
  0.5 05. ( OK ) identificacao de programa
  leitura e exibicao mediante escolha com repeticao
*/