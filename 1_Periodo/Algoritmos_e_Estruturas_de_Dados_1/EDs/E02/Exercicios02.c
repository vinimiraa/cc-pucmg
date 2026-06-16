/*
 Exercicios02 - v0.0. - 11 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o Exercicios02 Exercicios02.c
 Windows: gcc -o Exercicios02 Exercicios02.c
 Para executar em terminal (janela de comandos):
 Linux : ./Exercicios02
 Windows: Exercicios02
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// declaracao das funcoes secundarias
void identificacao();
void menuOpcoes();
void exercicio0211();
void exercicio0212();
void exercicio0213();
void exercicio0214();
void exercicio0215();
void exercicio0216();
void exercicio0217();
void exercicio0218();
void exercicio0219();
void exercicio0220();
void exercicio02E1();
void exercicio02E2();

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
        case  1: exercicio0211(); break;
        case  2: exercicio0212(); break;
        case  3: exercicio0213(); break;
        case  4: exercicio0214(); break;
        case  5: exercicio0215(); break;
        case  6: exercicio0216(); break;
        case  7: exercicio0217(); break;
        case  8: exercicio0218(); break;
        case  9: exercicio0219(); break;
        case 10: exercicio0220(); break;
        case 11: exercicio02E1(); break;
        case 12: exercicio02E2(); break;
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
    printf("%s\n", "Exercicios02 - Programa - v0.0");
    printf("%s\n", "Autor: Vinicius Miranda de Araujo - 812839");
    printf("\n");
} // fim identificacao()

void menuOpcoes()
{
    printf("Escolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0211\n");
    printf("  2 - Exercicio 0212\n");
    printf("  3 - Exercicio 0213\n");
    printf("  4 - Exercicio 0214\n");
    printf("  5 - Exercicio 0215\n");
    printf("  6 - Exercicio 0216\n");
    printf("  7 - Exercicio 0217\n");
    printf("  8 - Exercicio 0218\n");
    printf("  9 - Exercicio 0219\n");
    printf(" 10 - Exercicio 0220\n");
    printf(" 11 - Exercicio 02E1\n");
    printf(" 12 - Exercicio 02E2\n");
} // fim menuOpcoes()

void exercicio0211()
{
    // identificacao
    printf( "\nExercicio 0211:\n\n" );

    // programa
    int x = 0;

    printf( "Digite um numero: " );
    scanf( "%d" , &x );
    getchar();
    printf( "\n" );

    if( x % 2 == 0 )
    {
        printf( "O numero %d e par\n" , x );
    } else {
        printf( "O numero %d e impar\n" , x );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0211

void exercicio0212()
{
    // identificacao
    printf( "\nExercicio 0212:\n\n" );

    // programa
    int x = 0;

    printf( "Digite um numero: " );
    scanf( "%d" , &x );
    getchar();
    printf( "\n" );

    
    if( x % 2 == 0 ) // par
    {
        if( x > 15 ) 
        {
            printf( "O numero %d e par e maior que 15\n" , x );
        }
        else
        {
            printf( "O numero %d e par e menor que 15 \n" , x ); 
        }
    }

    if( x % 2 != 0 ) // impar
    {
        if( x < -15 )
        {
            printf( "O numero %d e impar e menor que -15\n" , x );
        }
        else
        {
            printf( "O numero %d e impar e maior que -15\n" , x );
        }
    }
    
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0212

void exercicio0213()
{
    // identificacao
    printf( "\nExercicio 0213:\n\n" );

    // programa
    int x = 0;

    printf( "Digite um numero: " );
    scanf( "%d" , &x );
    getchar();
    printf( "\n" );

    if( 25 < x && x < 65 )
    {
        printf( "O numero (%d) esta dentro do intervalo (25:65)\n", x );
    }
    else
    {
        printf( "O numero (%d) esta fora do intervalo (25:65)\n" , x );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0213

void exercicio0214()
{
    // identificacao
    printf( "\nExercicio 0214:\n\n" );

    // programa
    int x = 0;

    printf( "Digite um numero: " );
    scanf( "%d" , &x );
    getchar();
    printf( "\n" );

    if( 20 <= x && x <= 60 )
    {
        printf( "O numero (%d) esta dentro do intervalo [20:60]\n" , x );
    } else {
        printf( "O numero (%d) esta fora do intervalo [20:60]\n" , x);
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0214

void exercicio0215()
{
    // identificacao
    printf( "\nExercicio 0215:\n\n" );

    // programa
    int x = 0;

    printf( "Digite um numero: " );
    scanf( "%d" , &x );
    getchar();
    printf( "\n" );

    if ((x >= 15 && x <= 30) && (x > 25 && x < 50)) {
        printf( "O x pertence à interseção dos intervalos [15:30] e (25:50).\n" );
    }
    else if ( x >= 15 && x <= 30 ) {
        printf("O x pertence apenas ao intervalo [15:30].\n");
    }
    else if ( x > 25 && x < 50 ) {
        printf("O x pertence apenas ao intervalo (25:50).\n");
    }
    else {
        printf( "O x não pertence a nenhum dos intervalos.\n" );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0215

void exercicio0216()
{
    // identificacao
    printf( "\nExercicio 0216:\n\n" );

    // programa
    int x = 0, y = 0;

    printf( "Digite o primeiro numero: " );
    scanf( "%d" , &x );
    getchar();

    printf( "Digite o segundo numero: " );
    scanf( "%d" , &y );
    getchar();
    printf( "\n" );

    if( x % 2 == 0 )
    {
        if( y % 2 != 0 )
        {
            printf( "O (%d) e par e (%d) e impar\n" , x , y );
        }
        else 
        {
            printf( "O (%d) e par e (%d) e par\n" , x , y );
        }
    } 
    else
    {
        if( y % 2 != 0 )
        {
            printf( "O (%d) e impar e (%d) e impar\n" , x , y );
        }
        else 
        {
            printf( "O (%d) e impar e (%d) e par\n" , x , y );
        }
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0216

void exercicio0217()
{
    // identificacao
    printf( "\nExercicio 0217:\n\n" );

    // programa
    int x = 0, y = 0;

    printf( "Digite o primeiro numero: " );
    scanf( "%d" , &x );
    getchar();

    printf( "Digite o segundo numero: " );
    scanf( "%d" , &y );
    getchar();
    printf( "\n" );
    // primeiro numero
    if( x % 2 != 0 )
    {
        if( x < 0 )
        {
            printf("O numero (%d) impar e negativo\n" , x );
        }
        else
        {
            printf("O numero (%d) impar e positivo\n" , x );
        }
    }
    else
    {
        if( x < 0 )
        {
            printf("O numero (%d) par e negativo\n" , x );
        }
        else
        {
            printf("O numero (%d) par e positivo\n" , x );
        }
    }
    // segundo numero
    if( y % 2 == 0 )
    {
        if( y > 0 )
        {
            printf("O numero (%d) par e positivo\n" , y);
        }
        else
        {
            printf("O numero (%d) par e negativo\n" , y);
        }
    }
    else
    {
        if( y > 0 )
        {
            printf("O numero (%d) impar e positivo\n" , y);
        }
        else
        {
            printf("O numero (%d) impar e negativo\n" , y);
        }
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0217

void exercicio0218()
{
    // identificacao
    printf( "\nExercicio 0218:\n\n" );

    // programa
    double x = 0, y = 0;

    printf( "Digite o primeiro numero: " );
    scanf( "%lf" , &x );
    getchar();

    printf( "Digite o segundo numero: " );
    scanf( "%lf" , &y );
    getchar();
    printf( "\n" );

    if( ( y < x ) || ( y == x ) || ( y > (2 * x) ) )
    {
        if( y < x )
            printf( "(%lf) e menor que (%lf)\n" , y , x );
        else if( y == x )
            printf( "(%lf) e igual a (%lf)\n" , y , x );
        else
            printf( "(%lf) e maior que o dobro de (%lf)\n" , y , x );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0218

void exercicio0219()
{   
    // identificacao
    printf( "\nExercicio 0219:\n\n" );

    // programa
    double x = 0, y = 0, z = 0;

    printf( "Digite o primeiro numero: " );
    scanf( "%lf" , &x );
    getchar();

    printf( "Digite o segundo numero: " );
    scanf( "%lf" , &y );
    getchar();

    printf( "Digite o terceiro numero: " );
    scanf( "%lf" , &z );
    getchar();
    printf( "\n" );

    if( x != y)
    {
        if( (x < z) && (z < y) )
        {
            printf( "(%lf) esta entre (%lf) e (%lf)\n" , z , x , y );
        } else
        {
            printf( "(%lf) nao esta entre (%lf) e (%lf)\n" , z , x , y );
        }
    } else
    {
        printf( "(%lf) e (%lf) sao iguais logo (%lf) nao esta entre eles\n" , x , y , z );
    }
    
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0219

void exercicio0220()
{
    // identificacao
    printf( "\nExercicio 0220:\n\n" );

    // programa
    double x = 0, y = 0, z = 0;

    printf( "Digite o primeiro numero: " );
    scanf( "%lf" , &x );
    getchar();

    printf( "Digite o segundo numero: " );
    scanf( "%lf" , &y );
    getchar();

    printf( "Digite o terceiro numero: " );
    scanf( "%lf" , &z );
    getchar();
    printf( "\n" );

    if( (x != y) && (x != z) && (z!=y) )
    {
        if( !( (x < z) && (z < y) ) )
        {
            printf( "(%lf) nao esta entre (%lf) e (%lf)\n" , z , x , y );
        } 
        else
        {
            printf( "(%lf) esta entre (%lf) e (%lf)\n" , z , x , y );
        }
    } 
    else
    {
        if( (x == y) || (y == z) )
            printf( "Dois numeros sao iguais\n" );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0220

void exercicio02E1()
{
    // identificacao
    printf( "\nExercicio 02E1:\n\n" );

    // programa
    char a, b, c;

    printf( "Digite o primeiro caracter: " );
    scanf( "%c" , &a );
    getchar();

    printf( "Digite o segundo caracter: " );
    scanf( "%c" , &b );
    getchar();

    printf( "Digite o terceiro caracter: " );
    scanf( "%c" , &c );
    getchar();
    printf( "\n" );

    if( (a == b) || (a == c) )
    {
        printf( "O primeiro caracter e igual a outro\n" );
    }
    else
    {
        if( ( (b < a) && (a < c) ) || ( (b > a) && ( a > c) ) )
        {
            printf("O caracter (%c) esta entre (%c) e (%c)\n" , a , b , c );
        } else
        {
            printf( "O caracter (%c) nao esta entre (%c) e (%c)\n" , a , b , c );
        }
    } 

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio02E1

void exercicio02E2()
{
    // identificacao
    printf( "\nExercicio 02E2:\n\n" );

    // programa
    char a, b, c;

    printf( "Digite o primeiro caracter: " );
    scanf( "%c" , &a );
    getchar();

    printf( "Digite o segundo caracter: " );
    scanf( "%c" , &b );
    getchar();

    printf( "Digite o terceiro caracter: " );
    scanf( "%c" , &c );
    getchar();
    printf( "\n" );

    if( b != c )
    {
        if( !( ( (b < a) && (a < c) ) || ( (b > a) && ( a > c) ) ) )
        {
            printf("O caracter (%c) esta fora do intervalo ( %c : %c )\n" , a , b , c );
        } else
        {
            printf( "O caracter (%c) esta dentro do intervalo ( %c : %c )\n" , a , b , c );
        }
    }
    else
    {
        printf( "Ha dois caracteres iguais\n" );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio02E2
