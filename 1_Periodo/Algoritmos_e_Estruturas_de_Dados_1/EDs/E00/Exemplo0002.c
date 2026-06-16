/*
 Exemplo0002 - v0.0. - 10 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0002 exemplo0002.c
 Windows: gcc -o exemplo0002 exemplo0002.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0002
 Windows: exemplo0002
*/

// dependencias
#include <stdio.h>  // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main(int argc, char *argv[])
{
    // definir dados / resultados
    int opcao = 0;
    // identificar
    printf("%s\n", "Exemplo0002 - Programa = v0.0");
    printf("%s\n", "Autor: Vinicius Miranda de Araujo");
    printf("\n"); // mudar de linha
                  // acoes
                  // ler a opcao do teclado
    printf("\n%s", "Opcao = ");
    scanf("%d", &opcao);
    getchar(); // para limpar a entrada de dados
               // para mostrar a opcao lida
    printf("\n%s%d", "Opcao = ", opcao);
    // encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar();  // aguardar por ENTER
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
  Versao Teste
  0.0 01. ( OK ) identificacao de programa
  0.1 01. ( OK ) identificacao de programa
  0.2 01. ( OK ) identificacao de programa
                 leitura e exibicao de inteiro
  */
 