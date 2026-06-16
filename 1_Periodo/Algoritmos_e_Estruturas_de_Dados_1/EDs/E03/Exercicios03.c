/*
 Exercicios03 - v0.0. - 11 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o Exercicios03 Exercicios03.c
 Windows: gcc -o Exercicios03 Exercicios03.c
 Para executar em terminal (janela de comandos):
 Linux : ./Exercicios03
 Windows: Exercicios03
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// declaracao de variaveis globais
const int STR_SIZE = 80; // tamanho maximo da string

// declaracao das funcoes secundarias
void identificacao();
void menuOpcoes();
void exercicio0311();
void exercicio0312();
void exercicio0313();
void exercicio0314();
void exercicio0315();
void exercicio0316();
void exercicio0317();
void exercicio0318();
void exercicio0319();
void exercicio0320();
void exercicio03E1();
void exercicio03E2();

// funcao principal
int main (void)
{
    int opcao = 0;
    // mostrar identificacao do autor e programa
    identificacao();

    do{
        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        printf("\n Opcao = ");
        scanf( "%d" , &opcao );
        getchar(); // limpar entrada de dados

        // estetica
        printf( "\n======== Opcao %d ========\n", opcao );

        // executar a opcao escolhida
        switch (opcao)
        {
        case  0:                  break;
        case  1: exercicio0311(); break;
        case  2: exercicio0312(); break;
        case  3: exercicio0313(); break;
        case  4: exercicio0314(); break;
        case  5: exercicio0315(); break;
        case  6: exercicio0316(); break;
        case  7: exercicio0317(); break;
        case  8: exercicio0318(); break;
        case  9: exercicio0319(); break;
        case 10: exercicio0320(); break;
        case 11: exercicio03E1(); break;
        case 12: exercicio03E2(); break;
        default:
            printf( "\nERRO: OPCAO INVALIDA\n\n" );
            break;
        } // fim switch

        // estetica
        if( opcao == 0 ){
            printf("\n     Programa Encerrado     \n\n");
        }

        // estetica
        printf( "====== Fim Opcao %d ======\n\n", opcao );

    }while (opcao != 0);

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();

    return (0);
}

// definicao das funcoes secundarias

void identificacao()
{
    printf("\n");
    printf("%s\n", "Exercicios03 - Programa - v0.0");
    printf("%s\n", "Autor: Vinicius Miranda de Araujo - 812839");
    printf("\n");
} // fim identificacao()

void menuOpcoes()
{
    printf("Escolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0311\n");
    printf("  2 - Exercicio 0312\n");
    printf("  3 - Exercicio 0313\n");
    printf("  4 - Exercicio 0314\n");
    printf("  5 - Exercicio 0315\n");
    printf("  6 - Exercicio 0316\n");
    printf("  7 - Exercicio 0317\n");
    printf("  8 - Exercicio 0318\n");
    printf("  9 - Exercicio 0319\n");
    printf(" 10 - Exercicio 0320\n");
    printf(" 11 - Exercicio 03E1\n");
    printf(" 12 - Exercicio 03E2\n");
} // fim menuOpcoes()

void exercicio0311()
{
    // identificacao
    printf( "\nExercicio 0311:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, tam = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for( i = 0; i < tam; i++ )
    {
        if( ( 64 < palavra[i]) && (palavra[i] < 91) )
        {
            printf( "O caracter (%c) e MAIUSCULO\n" , palavra[i] );
        }
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0311

void exercicio0312()
{
    // identificacao
    printf( "\nExercicio 0312:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, count = 0, tam = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for( i = 0; i < tam; i++ )
    {
        if( (palavra[i] > 64) && (palavra[i] < 91) )
        {
            printf( "O caracter (%c) e MAIUSCULO\n" , palavra[i] );
            count++;
        }
    }

    printf( "\nHa em \"%s\" %d caracteres maiusculos\n", palavra, count );

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0312

void exercicio0313()
{
    // identificacao
    printf( "\nExercicio 0313:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, count = 0, tamanho = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tamanho = strlen(palavra);

    for( i = tamanho - 1; i >= 0; i=i-1 ) // for( int i = tamanho; tamanho >= 0; i=i-1)
    {
        if( ('A' <= palavra[i]) && (palavra[i] <= 'Z') )
        {
            printf( "O caracter (%c) e MAIUSCULO\n" , palavra[i] );
            count++;
        }
    }

    printf( "\nHa em \"%s\" %d caracteres maiusculos\n", palavra, count );

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0313

void exercicio0314()
{
    // identificacao
    printf( "\nExercicio 0314:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, count = 0, tamanho = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tamanho = strlen(palavra);
    
    for( i = 0; i < tamanho; i=i+1 )
    {
        if( isalpha(palavra[i] ) ) 
        {
            printf( "O caracter (%c) e uma letra\n" , palavra[i] );
            count++;
        }    
    }

    printf( "\nEm \"%s\" %d caracteres sao letras\n", palavra, count );
    // isalpha => if( ('A' <= palavra[i] && palavra[i] <= 'Z') || ('a' <= palavra[i] && palavra[i] <= 'z')) 
    // islower => if( 'a' <= palavra[i] && palavra[i] <= 'z' )
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0314

void exercicio0315()
{
    // identificacao
    printf( "\nExercicio 0315:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, count = 0, tamanho = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tamanho = strlen(palavra);
    
    for( i = tamanho - 1; i >= 0; i=i-1 ) 
    {
        if( isdigit(palavra[i]) ) // isdigit => if( '0' <= palavra[i] && palavra[i] <= '9' )
        {
            printf( "O caracter (%c) e um digito\n" , palavra[i] );
            count++;
        }
    }

    printf( "\nEm \"%s\" %d caracteres sao digitos\n", palavra, count );
    // isdigit => if( '0' <= palavra[i] && palavra[i] <= '9' )
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0315

void exercicio0316()
{
    // identificacao
    printf( "\nExercicio 0316:\n\n" );

    // programa
    char palavra [STR_SIZE];
    int i = 0, count = 0, tamanho = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tamanho = strlen(palavra);
    
    for( i = tamanho - 1; i >= 0; i=i-1 ) 
    {
        if( !( isdigit(palavra[i]) || isalpha(palavra[i]) ) )
        {
            printf( "O caracter (%c) nao e digito nem letra\n" , palavra[i] );
            count++;
        }
    }

    printf( "\nEm \"%s\" %d caracteres nao sao digitos nem letras\n", palavra, count );
    // isdigit => if( '0' <= palavra[i] && palavra[i] <= '9' )
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0316

void exercicio0317()
{
    // identificacao
    printf( "\nExercicio 0317:\n\n" );

    // programa
    int a = 0, b = 0, n = 0, i = 0;
    int count = 0;

    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%d" , &a ); 
    getchar();

    printf( "Insira o valor final do intervalo: " );
    scanf( "%d" , &b ); 
    getchar();

    printf( "Insira a quantidade de valores: " );
    scanf( "%d" , &n );
    getchar();
    printf( "\n" );

    int x[n]; // vetor
    for( i = 0; i < n; i=i+1 )
    {
        printf( "Digite o valor: " );
        scanf( "%d" , &x[i] );
        getchar();
    }
    printf( "\n" );
    for( i = 0; i < n; i++ )
    {
        if( (x[i] % 5 == 0) && (a <= x[i] && x[i] <= b) )
        {
            printf( "O numero (%d) e multiplo de 5 e esta dento do intervalo [ %d : %d ]\n" , x[i], a, b );
            count++;
        }
    }

    printf( "\n(%d) valores sao multiplos de 5 e pertecema ao intervalo\n", count );

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0317

void exercicio0318()
{
    // identificacao
    printf( "\nExercicio 0318:\n\n" );

    // programa
    int a = 0, b = 0, n = 0, i = 0;
    int count = 0;

    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%d" , &a ); 
    getchar();

    printf( "Insira o valor final do intervalo: " );
    scanf( "%d" , &b ); 
    getchar();

    printf( "Insira a quantidade de valores: " );
    scanf( "%d" , &n );
    getchar();
    printf( "\n" );

    int x[n]; // vetor

    for( i = 0; i < n; i=i+1 )
    {
        printf( "Digite o valor: " );
        scanf( "%d" , &x[i] );
        getchar();
    }
    printf( "\n" );

    for( i = 0; i < n; i++ )
    {
        if( (x[i] % 3 == 0) && (x[i] % 5 != 0) && (a <= x[i] && x[i] <= b) )
        {
            printf( "O numero (%d) e multiplo de 3, nao e multiplo de 5 e esta dento do intervalo [ %d : %d ]\n" , x[i], a, b );
            count++;
        }
    }
    printf( "\n(%d) valores sao multiplos de 3, nao sao multiplos de 5 e pertecema ao intervalo\n", count );
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0318

void exercicio0319()
{
    // identificacao
    printf( "\nExercicio 0319:\n\n" );

    // programa
    double a = 0.0, b = 0.0;
    int n = 0, i = 0, count = 0;
    
    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%lf" , &a ); 
    getchar();

    printf( "Insira o valor final do intervalo: " );
    scanf( "%lf" , &b ); 
    getchar();

    if( a >= b )
    {
        printf( "\nERRO: A valores invalidos! Certifique-se de que a < b! \n" );
    }
    else
    {
        printf( "Insira a quantidade de valores: " );
        scanf( "%d" , &n );
        getchar();
        printf( "\n" );

        double x[n];

        for( i = 0; i < n; i=i+1 )
        {
            printf( "Digite o valor: " );
            scanf( "%lf" , &x[i] );
            getchar();
        }
        printf( "\n" );

        for ( i = 0; i < n; i++)
        {
            if( a < x[i] && x[i] < b )
            {
                int inteiro = (int)x[i];
                if( inteiro % 2 == 1 )
                {
                    printf( "(%.2lf) e impar e pertece ao intervalo\n" , x[i] );
                    count++;
                }
                
            }
        }
        
        printf( "\n%d valores com partes inteiras impares pertencem ao intervalo\n" , count );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0319

void exercicio0320()
{
    // identificacao
    printf( "\nExercicio 0320:\n\n" );

    // programa
    double a = 0.0, b = 0.0;
    int i = 0, n = 0, count = 0;

    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%lf" , &a ); 
    getchar();

    printf( "Insira o valor final do intervalo: " );
    scanf( "%lf" , &b ); 
    getchar();


    if( a <= 0 || a >= 1 || b <= 0 || b >= 1 || a >= b ) //
    {
        printf( "\n%s\n" , "ERRO: O valor e inicial e final nao sao maiores que 0 e menores que 1" );
    }
    else
    {
        printf( "Insira a quantidade de valores: " );
        scanf( "%d" , &n );
        getchar();
        printf( "\n" );

        double x[n];

        for( i = 0; i < n; i=i+1 )
        {
            printf( "Digite o valor: " );
            scanf( "%lf" , &x[i] );
            getchar();
        } 
        printf( "\n" );

        for( i = 0; i < n; i=i+1 )
        {
            x[i] = x[i] - (int)x[i];
        }

        for ( i = 0; i < n; i++)
        {
            if( x[i] < a || x[i] > b ) // nao pertence ao intervalo
            {
                printf( "(%.2lf) nao pertece ao intervalo\n" , x[i] );
                count++;
            }
        }
        
        printf( "\n%d valores tem partes fracionarias que nao pertencem ao intervalo\n" , count );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0320

void exercicio03E1()
{
    // identificacao
    printf( "\nExercicio 03E1:\n\n" );

    // programa
    char linha[STR_SIZE];
    int i = 0;

    printf( "Digite uma linha:\n" );
    fgets(linha, sizeof(linha), stdin);

    for( i = 0; linha[i] != '\0'; i++ )
    {
        if( !(isalnum(linha[i])) && !(isspace(linha[i])) )
        {
            printf( "%c%s\n" , linha[i], " nao e alfanumerico." );
        }
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio03E1

void exercicio03E2()
{
    // identificacao
    printf( "\nExercicio 03E2:\n\n" );

    // programa
    char palavra[STR_SIZE];
    int i = 0, tam = 0, var = 0;

    printf( "Digite uma sequencia de caracteres:\n" );
    scanf( "%s" , palavra );

    tam = strlen(palavra);

    for( i = 0; i < tam; i++ )
    {
        if( isalpha(palavra[i]) )
        {
            var = 0;
        }
        else
        {
            var = 1;
        }
    }

    if(var)
    {
        printf("\nA cadeia de caracteres \"%s\" so tem simbolos\n" , palavra);
    }
    else
    {
        printf("\nA cadeia de caracteres \"%s\" tem letra(s)\n" , palavra);
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio03E2