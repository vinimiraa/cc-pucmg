/*
 Exemplo000 - v0.0. - 10 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo000 exemplo000.c
 Windows: gcc -o exemplo000 exemplo000.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo000
 Windows: exemplo000
*/

#include <stdio.h>   // para as entradas e saidas
#include <stdlib.h>  // para outras funcoes de uso geral
#include <math.h>    // para operacoes matematicas
#include "my_lib.h"  // para funcoes proprias
#include "my_def.h"  // para definicoes globais, constantes ...
#include <stdbool.h> // para definicoes booleanas
#include <string.h>
#include <ctype.h>

void metodo01()
{
    // identificar
    printf("\n%s\n", "EXEMPLO0101 - PRIMEIRO EXEMPLO EM C");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo02()
{
    // identificar
    // (dependente do sistema operacional)
    system("cls"); // ( Windows ) para limpar a tela
                   // system ( "clear" ); // ( Linux ) para limpar a tela
    printf("\n%s\n", "EXEMPLO0102 - PRIMEIRO EXEMPLO EM C");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void clrscr() { system("cls"); } // para Windows
void metodo03()
{
    // identificar
    printf("\n%s\n", "EXEMPLO0103 - PRIMEIRO EXEMPLO EM C");
    // (dependente do sistema operacional)
    clrscr(); // para limpar a tela
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo04()
{
    // identificar
    printf("\n%s\n", "EXEMPLO0104 - PRIMEIRO EXEMPLO EM C");
    printf("\n"); // para mudar de linha (="\n")
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\n"); // para mudar de linha
                  // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo05()
{
    // identificar
    printf("\n%s\n", "EXEMPLO0105 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\nEXEMPLOS DE VALORES : ");
    printf("\nCARACTERE : %c", 'A'); // letra ou simbolo
    printf("\nINTEIRO : %d", 10);    // valor sem parte fracionaria
    printf("\nREAL : %f", 3.1415);   // valor com parte fracionaria
                                     // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo06()
{
    double PI = 3.1415;
    // identificar
    printf("\n%s\n", "EXEMPLO0106 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\nEXEMPLOS DE VALORES : ");
    printf("\nCARACTERE : %c", 'A'); // letra ou simbolo
    printf("\nINTEIRO : %d", 10);    // valor sem parte fracionaria
    printf("\nREAL : %f", PI);       // emprego de macro
                                     // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo07()
{
    // definicao de constante (local)
    const float PI = 3.14; // com nome e tipo (melhor)
                           // identificar
    printf("\n%s\n", "EXEMPLO0107 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\nEXEMPLOS DE VALORES : ");
    printf("\nCARACTERE : %c", 'A'); // letra ou simbolo
    printf("\nINTEIRO : %d", 10);    // valor sem parte fracionaria
    printf("\nREAL : %f", PI);       // constante real
                                     // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo08()
{
    // definicao de constante
    const float PI = 3.14; // com nome e tipo (melhor)
                           // definicao de variavel real
    float X = 10.01;       // com atribuicao de valor inicial
                           // identificar
    printf("\n%s\n", "EXEMPLO0108 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\nEXEMPLOS DE VALORES : ");
    printf("\nCARACTERE : %c", 'A'); // letra ou simbolo
    printf("\nINTEIRO : %d", 10);    // valor sem parte fracionaria
    printf("\nREAL : %f", PI);       // constante real
    printf("\nREAL : %f", X);        // variavel real
                                     // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo09()
{
    // definicao de constante
    const float PI = 3.14;
    // definicao de variavel real
    float X = 10.01;
    // definicao de variavel inteira
    int I = 10;
    // identificar
    printf("\n%s\n", "EXEMPLO0109 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : Vinicius Miranda de Araujo");
    printf("\nEXEMPLOS DE VALORES : ");
    printf("\nINTEIRO : %i", I);
    printf("\nREAL : %f", X);
    printf("\nREAL : %f", PI);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo10()
{
    // definicao de constante
    const float PI = 3.14;
    // definicao de variavel real
    float X = 10.01;
    // definicao de variavel inteira
    int I = 10;
    // definicao de variavel caractere
    char N = '\n'; // mudar de linha
                   // identificar
    printf("\n%s\n", "EXEMPLO0106 - PRIMEIRO EXEMPLO EM C");
    printf("\n%s\n", "MATRICULA: 812839 ALUNO : __________________");
    printf("%c%s", N, "EXEMPLOS DE VALORES : ");
    printf("%c%s%i", N, "INTEIRO : ", I);
    printf("%c%s%f", N, "REAL : ", X);
    printf("%c%s%f", N, "REAL : ", PI);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo11()
{
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR INTEIRO
    // VARIAVEL:
    int X = 0;
    // identificar
    printf("EXEMPLO0201 - LER E IMPRIMIR UM VALOR INTEIRO");
    printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
    scanf("%d", &X);
    getchar(); // limpar a entrada de dados
    printf("\nO VALOR DIGITADO FOI: %d", X);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo12()
{
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR REAL
    // VARIAVEL:
    float X = 0.0;
    // identificar
    printf("EXEMPLO0202 - LER E IMPRIMIR UM VALOR REAL");
    printf("\nFORNECER UM VALOR REAL QUALQUER: ");
    scanf("%f", &X);
    getchar(); // limpar a entrada de dados
    printf("\nO VALOR DIGITADO FOI: %f", X);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo13()
{
    // PROGRAMA PARA LER E IMPRIMIR UM CARACTERE
    // VARIAVEL:
    char X = '0';
    // identificar
    printf("EXEMPLO0203 - LER E IMPRIMIR UM CARACTERE");
    printf("\nFORNECER UM CARACTERE QUALQUER: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    printf("\nO VALOR DIGITADO FOI: %c", X);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo14()
{
    // PROGRAMA PARA LER E IMPRIMIR, NO MAXIMO, 10 CARACTERES
    // VARIAVEL:
    char X[10];
    // identificar
    printf("EXEMPLO0204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES");
    printf("\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: ");
    scanf("%s", X); // OBS.: NAO usar o (&) para caracteres !
    getchar();      // limpar a entrada de dados
    printf("\nFOI DIGITADO: %s", X);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo15()
{
    // PROGRAMA PARA LER E SOMAR DOIS VALORES INTEIROS
    // VARIAVEIS:
    int X = 0, Y = 0, Z = 0;
    // identificar
    printf("EXEMPLO0205 - LER E SOMAR DOIS VALORES INTEIROS");
    printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
    scanf("%d", &X);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
    scanf("%d", &Y);
    getchar(); // limpar a entrada de dados
    Z = X + Y;
    printf("\nA SOMA DOS DOIS = %d", Z);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo16()
{
    // PROGRAMA PARA LER E SUBTRAIR DOIS VALORES REAIS
    // VARIAVEIS:
    float X = 0.0, Y = 0.0, Z = 0.0;
    // identificar
    printf("EXEMPLO0206 - LER E SUBTRAIR DOIS VALORES REAIS");
    printf("\nFORNECER UM VALOR REAL QUALQUER: ");
    scanf("%f", &X);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER OUTRO VALOR REAL QUALQUER: ");
    scanf("%f", &Y);
    getchar(); // limpar a entrada de dados
    Z = X - Y;
    printf("\nA DIFERENCA ENTRE OS DOIS = %f", Z);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo17()
{
    // PROGRAMA PARA OPERAR VALORES LOGICOS
    // VARIAVEIS:
    bool X = false, Y = false, Z = false;
    // identificar
    printf("EXEMPLO0207 - OPERAR VALORES LOGICOS");
    X = true;
    Y = false;
    Z = X || Y; // X ou Y
    printf("\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z);
    Z = X && Y; // X e Y
    printf("\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z);
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para espera
}
void metodo18()
{
    // PROGRAMA PARA CALCULAR A VELOCIDADE DE UM VEICULO
    // VARIAVEIS:
    float D = 0.0, // Distancia
        T = 0.0,   // Tempo
        V = 0.0;   // Velocidade
                   // identificar
    printf("EXEMPLO0208 - CALCULAR A VELOCIDADE DE UM VEICULO");
    printf("\nFORNECER UMA DISTANCIA QUALQUER EM METROS: ");
    scanf("%f", &D);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: ");
    scanf("%f", &T);
    getchar(); // limpar a entrada de dados
    V = D / T;
    printf("\nV = D / T = %f%s", V, " m/s ");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo19()
{
    // PROGRAMA PARA COMPARAR CARACTERES COM UMA SENHA
    // CONSTANTE:
    const char SENHA[5] = "XXXX";
    // VARIAVEL:
    char S[10];
    // identificar
    printf("EXEMPLO0209 - COMPARAR CARACTERES COM UMA SENHA");
    printf("\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: ");
    scanf("%s", S); // OBS.: NAO usar o (&) para caracteres !
    getchar();      // limpar a entrada de dados
    printf("\nA COMPARACAO COM A SENHA = %d", (strcmp(S, SENHA) == 0) ? 1 : 0);
    // strcmp(S1,S2) compara S1 com S2
    // igual a 0: S1 = S2 => 1 ( verdadeiro )
    // diferente: S1 <> S2 => 0 ( falso )
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo20()
{
    // PROGRAMA PARA CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
    // CONSTANTE:
    const double PI = 3.14;
    // VARIAVEIS:
    double ARCO = 0.0,
           COSSENO = 0.0,
           SENO = 0.0,
           TANGENTE = 0.0;
    // identificar
    printf("EXEMPLO0210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO");
    printf("\nFORNECER O VALOR DO SENO: ");
    scanf("%lf", &SENO);
    getchar();                          // limpar a entrada de dados
    COSSENO = sqrt(1.0 - pow(SENO, 2)); // raiz quadrada
    TANGENTE = SENO / COSSENO;
    ARCO = atan(TANGENTE); // arcotangente
    printf("\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO * 180.0 / PI));
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo21()
{
    // PROGRAMA PARA LER UM VALOR INTEIRO E VERIFICAR SE E' ZERO
    // VARIAVEL:
    int X = 0;
    printf("EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO");
    printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
    scanf("%d", &X);
    getchar(); // limpar a entrada de dados
    if (X == 0)
        printf("\nO VALOR DIGITADO FOI ZERO");
    else
        printf("\nO VALOR DIGITADO NAO FOI ZERO");
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo22()
{
    // PROGRAMA PARA LER UM REAL E TESTAR SE DIFERENTE DE ZERO
    // VARIAVEL:
    float X = 0.0;
    printf("EXEMPLO302 - LER E TESTAR UM VALOR REAL");
    printf("\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: ");
    scanf("%f", &X);
    getchar(); // limpar a entrada de dados
    if (X != 0.0)
        printf("\nO VALOR DIGITADO FOI DIFERENTE DE ZERO");
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo23()
{
    // PROGRAMA PARA LER CARACTERE E VERIFICAR SE E' UM ALGARISMO
    // VARIAVEL:
    char X = '0';
    printf("EXEMPLO303 - LER E TESTAR UM CARACTERE");
    printf("\nFORNECER UM ALGARISMO QUALQUER: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    if (X >= '0' && X <= '9')
    {
        printf("\nO VALOR DIGITADO FOI UM ALGARISMO");
        printf("\nO ALGARISMO DIGITADO FOI: %c", X);
    } // if ALGARISMO
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo24()
{
    // PROGRAMA PARA LER CARACTERE E TESTAR SE NAO E' ALGARISMO
    // VARIAVEL:
    char X = '0';
    printf("EXEMPLO304 - LER E TESTAR CARACTERE");
    printf("\nFORNECER UM CARACTERE QUALQUER: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    if (!(X >= '0' && X <= '9'))
    {
        printf("\nNAO FOI DIGITADO UM ALGARISMO");
        printf("\nFOI DIGITADO O CARACTERE: %c", X);
    } // if NAO ALGARISMO
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo25()
{
    // PROGRAMA PARA LER E TESTAR A IGUALDADE DE DOIS INTEIROS
    // VARIAVEIS:
    int X = 0, Y = 0;
    printf("EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS");
    printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
    scanf("%d", &X);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
    scanf("%d", &Y);
    getchar(); // limpar a entrada de dados
    if (X == Y)
        printf("\nDOIS VALORES IGUAIS");
    else
    {
        printf("\n%d", X);
        printf(" DIFERENTE DE ");
        printf("%d", Y);
    }
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo26()
{
    // PROGRAMA PARA LER E TESTAR DOIS VALORES REAIS
    // VARIAVEIS:
    double X = 0.0, Y = 0.0;
    printf("EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS");
    printf("\nFORNECER UM VALOR REAL QUALQUER: ");
    scanf("%lf", &X);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER OUTRO VALOR REAL QUALQUER: ");
    scanf("%lf", &Y);
    getchar(); // limpar a entrada de dados
    if (!(X == Y))
    {
        printf("\n%lf", X);
        printf(" DIFERENTE DE ");
        printf("%lf", Y);
    }
    else
    {
        printf("VALORES IGUAIS");
    } // if VALORES DIFERENTES
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo27()
{
    // PROGRAMA PARA TRATAR ALTERNATIVAS COM VALORES LOGICOS
    // VARIAVEIS:
    int X = 0, Y = 0;
    bool Z = false;
    printf("EXEMPLO307 - TRATAR VALORES LOGICOS");
    printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
    scanf("%d", &X);
    getchar(); // limpar a entrada de dados
    printf("\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
    scanf("%d", &Y);
    getchar(); // limpar a entrada de dados
    Z = (X == Y);
    if (Z)
        printf("VALORES IGUAIS");
    else
        printf("VALORES DIFERENTES");
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo28()
{
    // PROGRAMA PARA LER E TESTAR UMA LETRA
    // VARIAVEL:
    char X = '0';
    printf("EXEMPLO308 - LER E TESTAR UMA LETRA");
    printf("\nFORNECER UMA LETRA QUALQUER: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    if (X >= 'A' && X <= 'Z')
        printf("FOI DIGITADA UMA LETRA MAIUSCULA");
    else if (X >= 'a' && X <= 'z')
        printf("FOI DIGITADA UMA LETRA MINUSCULA");
    else
        printf("NAO FOI DIGITADA UMA LETRA");
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo29()
{
    // PROGRAMA PARA COMPARAR CARACTERES < , = , >
    // VARIAVEL:
    char X = '0';
    printf("EXEMPLO309 - COMPARAR CARACTERES < , = , >");
    printf("\nFORNECER UM DOS CARACTERES CITADOS: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    switch (X)
    {
    case '>':
        printf("FOI DIGITADO O SINAL DE MAIOR");
        break;
    case '=':
        printf("FOI DIGITADO O SINAL DE IGUAL");
        break;
    case '<':
        printf("FOI DIGITADO O SINAL DE MENOR");
        break;
    default:
        printf("FOI DIGITADO UM OUTRO CARACTERE QUALQUER");
    } // COMPARACAO DE X COM < , = , >
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo30()
{
    // PROGRAMA PARA IDENTIFICAR CARACTERES
    // VARIAVEL
    char X = '0';
    printf("EXEMPLO310 - IDENTIFICAR CARACTERES");
    printf("\nFORNECER UM CARACTERE QUALQUER: ");
    scanf("%c", &X);
    getchar(); // limpar a entrada de dados
    switch (X)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("FOI DIGITADO UMA VOGAL");
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        printf("FOI DIGITADO UM ALGARISMO");
        printf("\nO NUMERO CORRESPONDENTE = %d", (X - 48));
        break;
    default:
        printf("FOI DIGITADO UM OUTRO CARACTERE QUALQUER");
    } // IDENTIFICACAO DE UM CARACTERE
    printf("\nPRESSIONAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo31()
{
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
    int X = 0,
        CONTADOR = 0;
    // identificar
    printf("EXEMPLO0401 - LER E IMPRIMIR 03 VALORES INTEIROS");
    printf("\n"); // mudar de linha
    CONTADOR = 1;
    while (CONTADOR <= 3) // REPETIR
    {
        printf("\n"); // mudar de linha
        printf("%d. FORNECER UM VALOR INTEIRO : ", CONTADOR);
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        CONTADOR = CONTADOR + 1;
    } // ENQUANTO ( CONTADOR <= 3 )
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo32()
{
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
    int X = 0, N = 0, CONTADOR = 0;
    // identificar
    printf("EXEMPLO0402 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
    printf("\nFORNECER O NUMERO DE VEZES (N) : ");
    scanf("%d", &N);
    getchar(); // limpar a entrada de dados
    CONTADOR = 1;
    while (CONTADOR <= N)
    {
        printf("\n%d", CONTADOR);
        printf(" FORNECER UM VALOR INTEIRO QUALQUER : ");
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        CONTADOR = CONTADOR + 1;
    } // ENQUANTO ( CONTADOR <= N )
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo33()
{
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
    int X = 0, N = 0;
    // identificar
    printf("EXEMPLO0403 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
    printf("\nFORNECER O NUMERO DE VEZES (N) : ");
    scanf("%d", &N);
    getchar();    // limpar a entrada de dados
    while (N > 0) // REPETIR
    {
        printf("\n%d", N);
        printf(" FORNECER UM VALOR INTEIRO QUALQUER : ");
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        N = N - 1;
    } // ENQUANTO N > 0
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo34()
{
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
    int X = 0,
        CONTADOR = 0;
    // identificar
    printf("EXEMPLO0404 - LER E IMPRIMIR 03 VALORES INTEIROS\n");
    for (CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR + 1)
    {
        printf("\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR);
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
    } // PARA CONTADOR EM [1:3]
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo35()
{
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
    int X = 0,
        N = 0,
        CONTADOR = 0;
    // identificar
    printf("EXEMPLO0405 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
    printf("\nFORNECER O NUMERO DE VEZES (N) : ");
    scanf("%d", &N);
    getchar(); // limpar a entrada de dados
    for (CONTADOR = 1; CONTADOR <= N; CONTADOR++)
    {
        printf("\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR);
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d", X);
    } // PARA CONTADOR EM [1:N]
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo36()
{
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
    // VARIAVEIS :
    int X = 0,
        CONTADOR = 0;
    // identificar
    printf("EXEMPLO0406 - LER E IMPRIMIR 03 VALORES INTEIROS\n");
    CONTADOR = 1;
    do // REPETIR
    {
        printf("\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR);
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        CONTADOR = CONTADOR + 1;
    } while (CONTADOR <= 3); // ATE' ( CONTADOR > 3 )
                             // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo37()
{
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
    // VARIAVEIS :
    int X = 0,
        CONTADOR = 0;
    // identificar
    printf("EXEMPLO0407 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
    printf("\nFORNECER O NUMERO DE VEZES (N) : ");
    scanf("%d", &CONTADOR);
    getchar(); // limpar a entrada de dados
    do         // REPETIR
    {
        printf("\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR);
        scanf("%d", &X);
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        CONTADOR = CONTADOR - 1;
    } while (CONTADOR > 0); // ATE' ( CONTADOR <= 3 )
                            // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo38()
{
    // PROGRAMA PARA LER E IMPRIMIR INTEIROS DIFERENTES DE ZERO
    // VARIAVEL :
    int X = 0;
    // identificar
    printf("EXEMPLO0408 - LER E IMPRIMIR INTEIROS NAO NULOS\n");
    printf("\nFORNECER UM VALOR INTEIRO (0 = PARAR) : ");
    scanf("%d", &X);
    getchar();     // limpar a entrada de dados
    while (X != 0) // REPETIR
    {
        printf("\nO VALOR DIGITADO FOI : %d\n", X);
        printf("\nDIGITE UM VALOR INTEIRO QUALQUER : ");
        scanf("%d", &X);
    } // ENQUANTO X DIFERENTE DE ZERO
      // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo39()
{
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
    // VARIAVEL :
    int X = 0;
    // identificar
    printf("EXEMPLO0409 - PARA LER UM INTEIRO NAO NULO\n");
    printf("\nFORNECER UM VALOR DIFERENTE DE ZERO : ");
    scanf("%d", &X);
    getchar();     // limpar a entrada de dados
    while (X == 0) // REPETIR
    {
        printf("\nFORNECER UM VALOR DIFERENTE DE ZERO : ");
        scanf("%d", &X);
        getchar(); // limpar a entrada de dados
    }              // ENQUANTO X IGUAL A ZERO
    printf("\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo40()
{
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
    // VARIAVEL :
    int X = 0;
    // identificar
    printf("EXEMPLO0410 - LER UM INTEIRO NAO NULO\n");
    do // REPETIR
    {
        printf("\nFORNECER UM VALOR DIFERENTE DE ZERO : ");
        scanf("%d", &X);
        getchar();    // limpar a entrada de dados
    } while (X == 0); // ATE' X DIFERENTE DE ZERO
    printf("\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n");
    // encerrar
    printf("\n%s\n", "APERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P1(void)
{
    printf("\n");
    printf("\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS");
    printf("\n");
} // fim procedimento P1( )
void metodo41()
{
    // PROGRAMA PARA CHAMADA DE PROCEDIMENTO SEM PARAMETROS
    // identificar
    printf("EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO");
    P1(); // chamada ao procedimento
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo42()
{
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
    // identificar
    printf("EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n");
    for (int X = 1; X <= 5; X = X + 1)
        P1(); // chamar 5 vezes
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P1_2(void)
{
    int X = 0;
    X = X + 1; // AVANCAR O CONTEXTO
    printf("\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X);
    printf("\n");
    if (X < 5)
        P1_2(); // CHAMAR O PROCEDIMENTO RECURSIVAMENTE
    printf("\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X);
    X = X - 1; // RETORNAR AO CONTEXTO ANTERIOR
    getchar(); // para esperar
} // fim procedimento P1( )
void metodo43()
{
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
    // identificar
    printf("EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n");
    P1_2(); // OBSERVAR A RECURSIVIDADE !
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P1_3(int X)
{
    printf("\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X);
    if (X < 5)
        P1_3(X + 1); // chamar recursivamente com parametro
    printf("\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X);
    getchar(); // para esperar
} // fim procedimento P1( )
void metodo44()
{
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
    // identificar
    printf("EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n");
    P1_3(1); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P1_4(int X)
{
    printf("\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X);
    if (X > 1)
        P1_4(X - 1);
    printf("\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X);
    getchar(); // para esperar
} // fim procedimento P1( )
void metodo45()
{
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR VALOR
    // identificar
    printf("EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n");
    P1_4(5); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P2(int X); // PROTOTIPO DE PROCEDIMENTO
void P1_5(int X)
{
    printf("CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X);
    if (X < 5)
        P2(X);
    printf("RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X);
    getchar(); // para esperar
} // fim do procedimento P1( )
void P2(int X)
{
    printf("CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X);
    X = X + 1;
    printf("RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X);
    getchar(); // para esperar
    P1_5(X);
} // fim do procedimento P2( )
void metodo46()
{
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
    // identificar
    printf("EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n");
    P1_5(1); // OBSERVAR RECURSIVIDADE INDIRETA !
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P1_6(int *X)
{
    *X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
    printf("\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X);
    if (*X < 5)
        P1_6(X);
    printf("\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X);
    *X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
    getchar();   // para esperar
} // fim procedimento P1( )
void metodo47()
{
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
    // VARIAVEL LOCAL
    int X;
    // identificar
    printf("EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n");
    X = 0;
    P1_6(&X); // OBSERVAR REPETICAO FINITA !
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void P2_1(int X); // PROTOTIPO DE PROCEDIMENTO
void P1_7(int X)
{
    X = X + 1;
    printf("CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X);
    if (X < 4)
    {
        P1_7(X);
        P2_1(X);
    }
    printf("\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X);
    getchar(); // para esperar
} // fim do procedimento P1( )
void P2_1(int X)
{
    printf("CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X);
    if (X > 1)
        P2_1(X - 1);
    printf("RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X);
    getchar(); // para esperar
} // fim procedimento P2( )
void metodo48()
{
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
    // identificar
    printf("EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n");
    P1_7(1);
    printf("\n");
    // encerrar
    printf("\nAPERTAR <Enter> PARA TERMINAR.");
    getchar(); // para esperar
}
void metodo49()
{
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
    // identificar
    println("EXEMPLO0509 - USO DE MODULOS");
    // encerrar
    pause("APERTAR <Enter> PARA TERMINAR.");
}
void metodo50()
{
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
    // VARIAVEIS :
    chars text = "MUDAR DE LINHA";
    // identificar
    println("EXEMPLO0510 - USO DE MODULOS");
    printf("%c", EOL);
    printf("%s%c", text, EOL);
    // encerrar
    pause("PRESSIONAR <Enter> PARA TERMINAR.");
}

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
    printf(" 1 - Metodo01     26 - Metodo26\n");
    printf(" 2 - Metodo02     27 - Metodo27\n");
    printf(" 3 - Metodo03     28 - Metodo28\n");
    printf(" 4 - Metodo04     29 - Metodo29\n");
    printf(" 5 - Metodo05     30 - Metodo30\n");
    printf(" 6 - Metodo06     31 - Metodo31\n");
    printf(" 7 - Metodo07     32 - Metodo32\n");
    printf(" 8 - Metodo08     33 - Metodo33\n");
    printf(" 9 - Metodo09     34 - Metodo34\n");
    printf("10 - Metodo10     35 - Metodo35\n");
    printf("11 - Metodo11     36 - Metodo36\n");
    printf("12 - Metodo12     37 - Metodo37\n");
    printf("13 - Metodo13     38 - Metodo38\n");
    printf("14 - Metodo14     39 - Metodo39\n");
    printf("15 - Metodo15     40 - Metodo40\n");
    printf("16 - Metodo16     41 - Metodo41\n");
    printf("17 - Metodo17     42 - Metodo42\n");
    printf("18 - Metodo18     43 - Metodo43\n");
    printf("19 - Metodo19     44 - Metodo44\n");
    printf("20 - Metodo20     45 - Metodo45\n");
    printf("21 - Metodo21     46 - Metodo46\n");
    printf("22 - Metodo22     47 - Metodo47\n");
    printf("23 - Metodo23     48 - Metodo48\n");
    printf("24 - Metodo24     49 - Metodo49\n");
    printf("25 - Metodo25     50 - Metodo50\n");
    printf("     0 - Encerrar programa ");
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
        case 1: // executar metodo 01
            metodo01();
            break;
        case 2:
            metodo02();
            break;
        case 3:
            metodo03();
            break;
        case 4:
            metodo04();
            break;
        case 5:
            metodo05();
            break;
        case 6:
            metodo06();
            break;
        case 7:
            metodo07();
            break;
        case 8:
            metodo08();
            break;
        case 9:
            metodo09();
            break;
        case 10:
            metodo10();
            break;
        case 11:
            metodo11();
            break;
        case 12:
            metodo12();
            break;
        case 13:
            metodo13();
            break;
        case 14:
            metodo14();
            break;
        case 15:
            metodo15();
            break;
        case 16:
            metodo16();
            break;
        case 17:
            metodo17();
            break;
        case 18:
            metodo19();
            break;
        case 20:
            metodo20();
            break;
        case 21:
            metodo21();
            break;
        case 22:
            metodo22();
            break;
        case 23:
            metodo23();
            break;
        case 24:
            metodo24();
            break;
        case 25:
            metodo25();
            break;
        case 26:
            metodo26();
            break;
        case 27:
            metodo27();
            break;
        case 28:
            metodo28();
            break;
        case 29:
            metodo29();
            break;
        case 30:
            metodo30();
            break;
        case 31:
            metodo31();
            break;
        case 32:
            metodo32();
            break;
        case 33:
            metodo33();
            break;
        case 34:
            metodo34();
            break;
        case 35:
            metodo35();
            break;
        case 36:
            metodo36();
            break;
        case 37:
            metodo37();
            break;
        case 38:
            metodo38();
            break;
        case 39:
            metodo39();
            break;
        case 40:
            metodo40();
            break;
        case 41:
            metodo41();
            break;
        case 42:
            metodo42();
            break;
        case 43:
            metodo43();
            break;
        case 44:
            metodo44();
            break;
        case 45:
            metodo45();
            break;
        case 46:
            metodo46();
            break;
        case 47:
            metodo47();
            break;
        case 48:
            metodo48();
            break;
        case 49:
            metodo49();
            break;
        case 50:
            metodo50();
            break;
        default: // comportamento padrao
            printf("\nERRO: Opcao invalida.\n");
            break;
        } // end switch

        if (opcao == 0)
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