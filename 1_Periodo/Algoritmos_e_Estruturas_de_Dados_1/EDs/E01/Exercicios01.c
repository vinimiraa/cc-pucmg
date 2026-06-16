/*
 Exercicios01 - v0.0. - 11 / 08 / 2023
 Author: Vinicius Miranda de Araujo

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o Exercicios01 Exercicios01.c
 Windows: gcc -o Exercicios01 Exercicios01.c
 Para executar em terminal (janela de comandos):
 Linux : ./Exercicios01
 Windows: Exercicios01
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// definicao de PI
#define PI ( 3.14159265358979323846 )

// declaracao das funcoes secundarias
void identificacao();
void menuOpcoes();
void exercicio0111();
void exercicio0112();
void exercicio0113();
void exercicio0114();
void exercicio0115();
void exercicio0116();
void exercicio0117();
void exercicio0118();
void exercicio0119();
void exercicio0120();
void exercicio01E1();
void exercicio01E2();

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
        case  1: exercicio0111(); break;
        case  2: exercicio0112(); break;
        case  3: exercicio0113(); break;
        case  4: exercicio0114(); break;
        case  5: exercicio0115(); break;
        case  6: exercicio0116(); break;
        case  7: exercicio0117(); break;
        case  8: exercicio0118(); break;
        case  9: exercicio0119(); break;
        case 10: exercicio0120(); break;
        case 11: exercicio01E1(); break;
        case 12: exercicio01E2(); break;
        default:
            printf( "\nERRO: OPCAO INVALIDA\n" );
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
    printf("%s\n", "Exercicios01 - Programa - v0.0");
    printf("%s\n", "Autor: Vinicius Miranda de Araujo - 812839");
    printf("\n");
} // fim identificacao()

void menuOpcoes()
{
    printf("Escolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0111\n");
    printf("  2 - Exercicio 0112\n");
    printf("  3 - Exercicio 0113\n");
    printf("  4 - Exercicio 0114\n");
    printf("  5 - Exercicio 0115\n");
    printf("  6 - Exercicio 0116\n");
    printf("  7 - Exercicio 0117\n");
    printf("  8 - Exercicio 0118\n");
    printf("  9 - Exercicio 0119\n");
    printf(" 10 - Exercicio 0120\n");
    printf(" 11 - Exercicio 01E1\n");
    printf(" 12 - Exercicio 01E2\n");
} // fim menuOpcoes()

void exercicio0111()
{
    // identificacao
    printf( "\nExercicio 0111:\n\n" );

    // programa
    int lado = 0, a = 0;

    printf( "Insira o valor do lado de um quadrado: " );
    scanf( "%d" , &lado );
    getchar();
    printf( "\n" );

    a = pow( (lado * 6) ,2);

    printf( "Area de um quadrado com lado 6x maior: %d\n" , a );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0111

void exercicio0112()
{
    // identificacao
    printf( "\nExercicio 0112:\n\n" );

    // programa
    int lado = 0;
    double ladoNovo = 0.0, perimetro = 0.0, area = 0.0;

    printf( "Insira o valor do lado de um quadrado: " );
    scanf( "%d", &lado );
    getchar();
    printf( "\n" );

    ladoNovo = lado / 3.0;

    perimetro = 4.0 * ladoNovo;

    area = pow(ladoNovo, 2.0);

    printf( "Perimetro de um quadrado com 1/3 do tamanho do lado: %lf\n" , perimetro );
    printf( "Area de um quadrado com 1/3 do tamanho do lado: %lf\n" , area );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0112

void exercicio0113()
{
    // identificacao
    printf( "\nExercicio 0113:\n\n" );

    // programa
    int base = 0, altura = 0;
    double r1 = 0.0, r2 = 0.0;

    printf( "Insira o valor da base de um retangulo: " );
    scanf( "%d", &base );
    getchar();

    printf( "Insira o valor da altura de um retangulo: " );
    scanf( "%d", &altura );
    getchar();
    printf( "\n" );

    r1 = (double)base * altura;

    r2 = r1 * 4;
    
    printf( "Area de um retangulo 4x maior: %lf\n" , r2 );
    
    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0113

void exercicio0114()
{
    // identificacao
    printf( "\nExercicio 0114:\n\n" );

    // programa
    int base = 0, altura = 0;
    double area = 0.0, perimetro = 0.0;

    printf( "Insira o valor da base de um retangulo: " );
    scanf( "%d", &base );
    getchar();

    printf( "Insira o valor da altura de um retangulo: " );
    scanf( "%d", &altura );
    getchar();
    printf( "\n" );

    area = ( base / 5.0 ) * ( altura / 5.0 );

    perimetro = 2.0 * ( base / 5.0 ) + 2.0 * ( altura / 5.0 );

    printf( "Area de um retangulo com 1/5 dos lados: %lf\n", area );

    printf( "Perimetro de um retangulo com 1/5 dos lados: %lf\n" , perimetro );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0114

void exercicio0115()
{
    // identificacao
    printf( "\nExercicio 0115:\n\n" );

    // programa
    double base = 0.0, altura = 0.0, area = 0.0; 

    printf( "Insira o valor da base de um triangulo: " );
    scanf( "%lf", &base );
    getchar();

    printf( "Insira o valor da altura de um triangulo: " );
    scanf( "%lf", &altura );
    getchar();
    printf( "\n" );

    area = ( base * ( altura / 2 ) ) / 2;

    printf( "Area de um trianguo com metade da altura: %lf\n" , area );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0115

void exercicio0116()
{
    // identificacao
    printf( "\nExercicio 0116:\n\n" );

    // programa
    double lado = 0.0, ladoNovo = 0.0, area = 0.0, perimetro = 0.0, altura = 0.0;

    printf( "Insira o valor do lado de um triangulo equilatero: " );
    scanf( "%lf" , &lado );
    getchar();
    printf( "\n" );

    ladoNovo = 2 * lado;

    altura = ( ladoNovo * sqrt(3) )/2;

    area = ( pow(ladoNovo,2) * sqrt(3) )/4;
    
    perimetro = ladoNovo * 3;

    printf( "A altura, area e o perimetro do triangulo com o dobro do lado: altura = %lf, area = %lf, perimetro = %lf\n" , altura , area , perimetro );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0116

void exercicio0117()
{
    // identificacao
    printf( "\nExercicio 0117:\n\n" );

    // programa
    double lado = 0.0, volume = 0.0;

    printf( "Insira o valor de um lado de um cubo: " );
    scanf( "%lf" , &lado );
    getchar();
    printf( "\n" );

    volume = pow( ( lado * 7 ) , 3 );

    printf( "O volume de um cubo com 7x a medida do lado: %lf\n" , volume );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0117

void exercicio0118()
{
    // identificacao
    printf( "\nExercicio 0118:\n\n" );

    // programa
    double comprimento = 0.0, largura = 0.0, altura = 0.0, volume = 0.0;

    printf( "Insira o valor do comprimento do paralelepipedo: " );
    scanf( "%lf" , &comprimento );
    getchar();

    printf( "Insira o valor da largura do paralelepipedo: " );
    scanf( "%lf" , &largura );
    getchar();

    printf( "Insira o valor da altura do paralelepipedo: " );
    scanf( "%lf" , &altura );
    getchar();
    printf( "\n" );

    volume = ( comprimento / 6 ) * ( largura / 6 ) * ( altura / 6 );

    printf( "O volume do solido com 1/6 desses valores e: %lf\n" , volume );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0118

void exercicio0119()
{   
    // identificacao
    printf( "\nExercicio 0119:\n\n" );

    // programa
    double raio = 0.0, area = 0.0;

    printf( "Insira o valor do raio de um circulo: " );
    scanf( "%lf" , &raio );
    getchar();
    printf( "\n" );

    area = ( PI * ( ( pow( raio,2 ) / 2 ) ) ) / 2;

    printf( "A area de um semicirculo com metade do raio e: %lf\n" , area );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0119

void exercicio0120()
{
    // identificacao
    printf( "\nExercicio 0120:\n\n" );

    // programa
    double raio = 0.0, volume = 0.0;

    printf( "Insira o valor do raio de uma esfera: " );
    scanf( "%lf" , &raio );
    getchar();
    printf( "\n" );
    
    volume = PI * pow(((3*raio)/8), 3) * 4/3;

    printf( "O volume de uma esfera com 3/8 do raio e: %lf\n" , volume );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio0120

void exercicio01E1()
{
    // identificacao
    printf( "\nExercicio 01E1:\n\n" );

    // programa
    double area = 0.0, raio = 0.0;

    printf( "Insira o valor da area de uma circunferencia: " );
    scanf( "%lf" , &area );
    getchar();
    printf( "\n" );

    raio = sqrt( (area / 3 ) / PI );

    printf( "O raio de uma circunferencia com 1/3 dessa area e: %lf\n" , raio );

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio01E1

void exercicio01E2()
{
    // identificacao
    printf( "\nExercicio 01E2:\n\n" );

    // programa
    double volume = 0.0, volumeNovo = 0.0, raio = 0.0, area = 0.0;

    printf( "Insira o valor do volume de uma esfera: " );
    scanf( "%lf" , &volume );
    getchar();
    printf( "\n" );

    volumeNovo = ( 3 * volume ) / 4;

    raio = cbrt( (volumeNovo * 3 * PI) / 4 );

    area = 4 * PI * pow( raio, 2 );

    printf( "O raio de 3/4 do volume da esfera e: %lf\n" , raio ); 

    printf( "A area da superficie da esfera e: %lf\n" , area ); 

    // encerrar
    printf( "\nAperte ENTER para terminar!\n" );
    getchar();
} // fim exercicio01E2