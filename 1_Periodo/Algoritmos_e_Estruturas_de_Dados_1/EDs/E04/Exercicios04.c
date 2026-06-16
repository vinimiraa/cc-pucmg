/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 * 
 * Exercicios04 - v0.0. - 23 / 08 / 2023
 * Author: Vinicius Miranda de Araujo
 * 
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios04 Exercicios04.c
 *      Windows: gcc -o Exercicios04 Exercicios04.c
 * 
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios04
 *      Windows: Exercicios04
 * 
*/

// -------------------------- lista de dependencias

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

const   int  STR_SIZE     =  80 ;   // definir tamanho padrao para caracteres

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void identificacao();
void menuOpcoes();
void exercicio0411();
void exercicio0412();
void exercicio0413();
void exercicio0414();
void exercicio0415();
void exercicio0416();
void exercicio0417();
void exercicio0418();
void exercicio0419();
void exercicio0420();
void exercicio04E1();
void exercicio04E2();

// -------------------------- definicao do metodo principal

int main (void)
{
  int opcao = 0;
  // mostrar identificacao do autor e programa
  identificacao();

  do{
    // mostrar menu de opcoes
    menuOpcoes();

    // ler opcao do teclado
    printf( "\n %s" , "Opcao = ");
    scanf( "%d" , &opcao ); 
    getchar(); // limpar entrada de dados

    // estetica
    printf( "\n======== Opcao %d ========\n", opcao );

    // executar a opcao escolhida
    switch (opcao)
    {
      case  0:                  break;
      case  1: exercicio0411(); break;
      case  2: exercicio0412(); break;
      case  3: exercicio0413(); break;
      case  4: exercicio0414(); break;
      case  5: exercicio0415(); break;
      case  6: exercicio0416(); break;
      case  7: exercicio0417(); break;
      case  8: exercicio0418(); break;
      case  9: exercicio0419(); break;
      case 10: exercicio0420(); break;
      case 11: exercicio04E1(); break;
      case 12: exercicio04E2(); break;
      default:
        printf( "\n   %s\n\n" , "ERRO: opcao invalida" );
        break;
    } // fim switch
        
    // estetica
    if( opcao == 0 ){
        printf( "\n%s\n\n" , "     Programa Encerrado     ");
    }

    // estetica
    printf( "====== Fim Opcao %d ======\n\n", opcao );

  }while (opcao != 0);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para terminar!" );
  getchar();

  return (0);
}

// -------------------------- definicao de metodos

/**
  * Identificacao do Autor e Programa
  */
void identificacao()
{
  printf("\n");
  printf("%s\n", "Exercicios04 - Programa - v0.0");
  printf("%s\n", "Autor: Vinicius Miranda de Araujo - 812839");
  printf("\n");
} // fim identificacao()

/**
  * Menu de opcoes
  */
void menuOpcoes()
{
  printf( "%s\n\n" , "Escolha alguma das opcoes a seguir:");
  printf( "%s\n" , "  0 - Encerrar programa");
  printf( "%s\n" , "  1 - Exercicio 0411");
  printf( "%s\n" , "  2 - Exercicio 0412");
  printf( "%s\n" , "  3 - Exercicio 0413");
  printf( "%s\n" , "  4 - Exercicio 0414");
  printf( "%s\n" , "  5 - Exercicio 0415");
  printf( "%s\n" , "  6 - Exercicio 0416");
  printf( "%s\n" , "  7 - Exercicio 0417");
  printf( "%s\n" , "  8 - Exercicio 0418");
  printf( "%s\n" , "  9 - Exercicio 0419");
  printf( "%s\n" , " 10 - Exercicio 0420");
  printf( "%s\n" , " 11 - Exercicio 04E1");
  printf( "%s\n" , " 12 - Exercicio 04E2");
} // fim menuOpcoes()

/**
  * Metodo01.
  */
void exercicio0411(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0411:" );

  // programa
  double a = 0.0, b = 0.0;
  int i = 0, n = 0, countD = 0, countF = 0;

  printf( "Insira o valor inicial para o intervalo: " );
  scanf( "%lf" , &a );
  getchar();
  
  printf( "Insira o valor final para o intervalo: " );
  scanf( "%lf" , &b );
  getchar();

  printf( "Insira a quantidade de valores dentro intervalo: " );
  scanf( "%d" , &n );
  getchar();
  printf( "\n" );

  double x[n];

  for( i = 0; i < n; i++ )
  {
    printf( "%d: " , i+1 );
    scanf( "%lf" , &x[i] );
    getchar();
  }

  for( i = 0; i < n; i++)
  {
    if( a <= x[i] && x[i] <= b )
    {
      countD++;
    }   // end if
    else
    {
      if( x[i] < a || b < x[i] )
      {
        countF++;
      } // end if
    }   // end else
  }     // end for

  printf( "\n(%d) valores estao dentro do intervalo e (%d) estao fora\n" , countD, countF );

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0411

/**
  * Metodo02.
  */
void exercicio0412(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0412:" );
  // programa
  char palavra[STR_SIZE];
  int i = 0, tamanho = 0, count = 0;

  printf( "Digite uma palavra: " );
  scanf( "%s" , palavra );
  getchar();

  tamanho = strlen(palavra);

  for ( i = 0; i < tamanho; i++)
  {
    if( isupper(palavra[i]) )
    {
      if( palavra[i] > 'K' )
      {
        count++;
      } // end if
    }   // end if
  }     // end for
  
  printf( "\n(%d) letras maiusculas sao maiores do que \'K\'\n", count );
  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0412

/**
  * Metodo03.
  */
void metodo0413(const char *text)
{
  int i = 0, count = 0;

  int tamanho = strlen(text);

  for ( i = 0; i < tamanho; i++)
  {
    if( isupper(text[i]) )
    {
      if( text[i] > 'K' )
      {
        count++;
      } // end if
    }   // end if
  }     // end for
  
  printf( "\n(%d) letras maiusculas sao maiores do que \'K\'\n", count );
}
void exercicio0413(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0413:" );

  // programa
  char palavra[STR_SIZE];

  printf( "Digite uma palavra: " );
  scanf( "%s" , palavra );
  getchar();

  metodo0413(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0413

/**
  * Metodo04.
  */
void metodo0414(const char *text)
{
  int i = 0;

  int tamanho = strlen(text);
  
  printf( "\n%s\n\n", "Letras Maiusculas Maiores do que K:" );  
    
  for ( i = 0; i < tamanho; i++)
  {
    if( isupper(text[i]) )
    {
      if( text[i] > 'K' )
      {
        printf( "%c\n" , text[i] );
      } // end if
    }   // end if
  }     // end for
}
void exercicio0414(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0414:" );

  // programa
  char palavra[STR_SIZE];

  printf( "Digite uma palavra: " );
  scanf( "%s" , palavra );
  getchar();

  metodo0414(palavra);
  
  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0414

/**
  * Metodo05.
  */
void metodo0415(const char * text)
{
  int count = 0, i = 0;
  int tam = strlen(text);
  
  for( i = 0; i < tam; i=i+1 )
  {
    if( 'A' < text[i] && text[i] < 'Z')
    { 
      if( text[i] > 'K' )
      {
        count++;
      } // end if
    }   // end if
    else
    {
      if( 'a' < text[i] && text[i] < 'z' )
      {
        if( text[i] > 'k' )
        {
          count++;
        } // end if
      }   // end if
    }     // end else
  } 
  
  printf ( "\n\"%s\" tem %d letras maiores que \"K\"\n" , text, count );
}
void exercicio0415(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0415:" );

  // programa
  char palavra[STR_SIZE];  
    
  printf( "%s\n" , "Digite uma palavra:" );
  scanf( "%s" , palavra );
  getchar();
    
  metodo0415(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0415

/**
  * Metodo06.
  */
void metodo0416(const char * text)
{
  int i = 0;
  int tam = strlen(text);
  
  printf( "\n%s\n\n", "Letras Maiores do que \"k\" e \"K\":" ); 
  
  for( i = 0; i < tam; i=i+1 )
  {
    if( 'A' < text[i] && text[i] < 'Z')
    { 
      if( text[i] > 'K' )
      {
        printf( "%c\n", text[i] );
      } // end if
    }   // end if
    else
    {
      if( 'a' < text[i] && text[i] < 'z' )
      {
        if( text[i] > 'k' )
        {
          printf( "%c\n", text[i] );
        } // end if
      }   // end if
    }     // end else
  } 
}
void exercicio0416(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0416:" );

  // programa
  char palavra[STR_SIZE];  
    
  printf( "%s\n" , "Digite uma palavra:" );
  scanf( "%s" , palavra );
  getchar();
    
  metodo0416(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0416

/**
  * Metodo07.
  */
void metodo0417(const char *text)
{
  int count = 0, i = 0;
  int tam = strlen(text);
    
  for( i = 0; i < tam; i++ )
  {
    if( isdigit(text[i]) )
    {
      if( text[i] % 2 != 0 )
      {
        count++;
      }
    }
  }
  
  printf( "\n(%d) digitos sao impares na cadeia de caracteres\n" , count );
}
void exercicio0417(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0417:" );

  // programa
  char palavra[STR_SIZE];  
    
  printf( "%s" , "Digite uma palavra:\n" );
  scanf( "%s" , palavra );
  getchar();
    
  metodo0417(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0417

/**
  * Metodo08.
  */
void metodo0418(const char *text)
{
  int i = 0;
  int tam = strlen(text);  
  
  printf( "\n%s\n\n" , "Os simbolos que nao sao alfanumericos sao:" );
    
  for( i = 0; i < tam; i++ )
  {
    if( !isalnum(text[i]) )
    {
      printf("%c\n" , text[i] );
    }
  }
}
void exercicio0418(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0418:" );

  // programa
  char palavra[STR_SIZE];  
    
  printf( "%s" , "Digite uma palavra:\n" );
  scanf( "%s" , palavra );
  getchar();
    
  metodo0418(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0418

/**
  * Metodo09.
  */
void metodo0419(const char *text)
{
  int i = 0;
  int tam = strlen(text);  
  
  printf( "\n%s\n\n" , "Os simbolos que sao alfanumericos sao:" );
    
  for( i = 0; i < tam; i++ )
  {
    if( isalnum(text[i]) )
    {
      printf("%c\n" , text[i] );
    }
  }
}
void exercicio0419(void)
{   
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0419:" );

  // programa
  char palavra[STR_SIZE];  
    
  printf( "%s" , "Digite uma palavra:\n" );
  scanf( "%s" , palavra );
  getchar();
    
  metodo0419(palavra);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0419

/**
  * Metodo10.
  */
int nAlNum(const char *text)
{
  int count = 0;
  int tam = strlen(text);

  for( int i = 0; i < tam; i++ )
  {
    if( isalnum(text[i]) )
    {
      count++;
    }
  }
  return (count);
}
void metodo0420(int n)
{
  char sequencia[STR_SIZE];
  int i = 0, total = 0;
  int alphanum = 0;

  for( i = 0; i < n; i++ )
  {
    printf( "Sequencia %d: ", i+1 );
    scanf( "%80[^\n]" , sequencia);
    getchar();

    alphanum = nAlNum(sequencia);
    printf( "\nNa sequencia \"%s\" ha %d simbolos alfanumericos.\n\n", sequencia, alphanum );

    total = total + alphanum;
  }

  printf( "Total acumulado de simbolos alfanumericos: %d\n", total );
}
void exercicio0420(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 0420:" );

  // programa
  int n = 0;

  printf( "%s" , "Digite a quantidade de sequencias a serem lidas: " );
  scanf( "%d", &n );
  getchar();
  printf( "\n" );

  metodo0420(n);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio0420

/**
  * Metodo11.
  */
int isAlNum(const char *text)
{
  int count = 0;
  int tam = strlen(text);

  for( int i = 0; i < tam; i++ )
  {
    if( isalnum(text[i]) || isspace(text[i]) )
    {
      count++;
    }
  }
  return (count);
}
void metodo04E1(int n)
{
  char sequencia[STR_SIZE];
  int alphanum = 0;
  int total = 0;

  for( int i = 0; i < n; i++ )
  {
    printf( "%d: ", i+1 );
    scanf( "%80[^\n]" , sequencia );
    getchar();

    alphanum = isAlNum(sequencia);
    printf( "\nNa sequencia \"%s\" ha %d simbolos alfanumericos.\n\n", sequencia, alphanum );
    total = total + alphanum;  
  }
  printf( "\n(%d) simbolos sao alfanumericos, incluindo espacos em branco\n" , total );
}
void exercicio04E1(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 04E1:" );


  // programa
  int n;

  printf( "%s", "Insira a quantidade de sequencias a serem lidas: " );
  scanf( "%d", &n );
  getchar();
  printf( "\n" );

  metodo04E1(n);

  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio04E1

/**
  * Metodo12.
  */
void metodo04E2(const char *text1, const char *text2)
{ 
  int count1 = 0;
  int tam1 = strlen(text1);
  int count2 = 0;
  int tam2 = strlen(text2);
  for( int i = 0; i < tam1; i=i+1 )
  {
    if( isdigit(text1[i]) )
    {
      count1 = count1 + 1;
    }
  }
  for( int j = 0; j < tam2; j=j+1 )
  {
    if( isdigit(text2[j]) )
    {
      count2 = count2 + 1;
    }
  }
         if( count1 > count2 ) {
    printf("%s\n" , "A primeira sequencia possui maior quantidade de digitos do que a segunda");
  } else if( count2 > count1 ) {
    printf("%s\n" , "A segunda sequencia possui maior quantidade de digitos do que a primeira");
  } else {
    printf("%s\n" , "A primeira e a segunda sequencia tem quantidades iguais de digitos");
  }
}
void exercicio04E2(void)
{
  // identificacao
  printf( "\n%s\n\n" , "Exercicio 04E2:" );

  // programa
  char sequencia1[STR_SIZE];
  char sequencia2[STR_SIZE];
  
  printf( "Digite a primeira sequencia: " );
  scanf( "%80[^\n]" , sequencia1 );
  getchar();

  printf( "Digite a segunda sequencia: " );
  scanf( "%80[^\n]" , sequencia2 );
  getchar();
  printf( "\n" );

  metodo04E2(sequencia1, sequencia2);
  // encerrar
  printf( "\n%s\n" , "Aperte ENTER para continuar!" );
  getchar();
} // fim exercicio04E2
