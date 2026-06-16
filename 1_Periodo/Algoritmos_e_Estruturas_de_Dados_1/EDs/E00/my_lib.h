// Digitar o conteudo abaixo em um arquivo com o nome io.h :
// ------------------------------------ my_lib.h
// bibliotecas de funcoes auxiliares
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral

void pause ( char message [ ] )
{
 printf ( "\n%s", message );
 getchar ( ); // para esperar
} // fim pause ( )
void println ( char text [ ] )
{ printf ( "%s\n", text ); }