/*
 Exemplo00M - v0.0. - 11 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo00M exemplo00M.c
 Windows: gcc -o exemplo00M exemplo00M.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo00M
 Windows: exemplo00M
*/

// -------------------------------------------- Dependencias
#include <stdio.h>   // para as entradas e saidas
#include <stdlib.h>  // para outras funcoes de uso geral
#include <math.h>    // para operacoes matematicas
#include "my_lib.h"  // para funcoes proprias
#include "my_def.h"  // para definicoes globais, constantes ...
#include <stdbool.h> // para definicoes booleanas
#include <string.h>
#include <ctype.h>

// -------------------------------------------- Inicio Funcoes Principais
void metodo01()
{
    printf("\nMetodo01\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo02()
{
    printf("\nMetodo02\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo03()
{
    printf("\nMetodo03\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo04()
{
    printf("\nMetodo04\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo05()
{
    printf("\nMetodo05\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo06()
{
    printf("\nMetodo06\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo07()
{
    printf("\nMetodo07\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo08()
{
    printf("\nMetodo08\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo09()
{
    printf("\nMetodo09\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
void metodo10()
{
    printf("\nMetodo10\n");

    printf("\nAperte <ENTER> para terminar!");
    getchar();
}
// -------------------------------------------- Fim Funcoes Principais

/*
 Identificao: funcao para imprimir na tela a identificao deste programa
*/
void identificacao()
{
    printf("\n");
    printf("Exemplo00M - Programa = v0.0\n");
    printf("Autor: Vinicius Miranda de Araujo\n");
    printf("\n");
}

/*
 Funcao principal
*/
int main()
{

    identificacao();
    metodo01();
    metodo02();
    metodo03();
    metodo04();
    metodo05();
    metodo06();
    metodo07();
    metodo08();
    metodo09();
    metodo10();

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