/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * A01 - v0.0. - 24 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o A01 A01.c
 *      Windows: gcc -o A01 A01.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./A01
 *      Windows: A01
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio01();
void exercicio02();
void exercicio03();
void exercicio04();
void exercicio05();
void exercicio06();
void exercicio07();
void exercicio08();
void exercicio09();
void exercicio10();


// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: A01 - v0.0");

        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch (opcao)
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;
        default:
            pause("ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

    return (0);
}

// -------------------------- definicao de metodos

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    printf("\n");
    printf("%s\n\n", "Escolha alguma das opcoes a seguir:");
    printf("%s\n", "  0 - Encerrar programa");
    printf("%s\n", "  1 - Exercicio 01");
    printf("%s\n", "  2 - Exercicio 02");
    printf("%s\n", "  3 - Exercicio 03");
    printf("%s\n", "  4 - Exercicio 04");
    printf("%s\n", "  5 - Exercicio 05");
    printf("%s\n", "  6 - Exercicio 06");
    printf("%s\n", "  7 - Exercicio 07");
    printf("%s\n", "  8 - Exercicio 08");
    printf("%s\n", "  9 - Exercicio 09");
    printf("%s\n", " 10 - Exercicio 10");
    printf("\n");
} // fim menuOpcoes()

int somaDivisorImpar( int x )
{
    int divisor = 1;
    int soma = 0;

    while( x >= divisor )
    {
        if( x % divisor == 0 && divisor % 2 != 0 )
        {
            soma = soma + divisor;
        }
        divisor = divisor + 1;
    }

    return (soma);
}
/**
 * Metodo01.
 */
void exercicio01()
{
    // identificacao
    id("Exercicio 01:");

    // programa
    int n = 0;
    int x = 0;

    n = readint("Digite um quantidade: ");
    print("\n");

    for( int  i = 0; i < n; i = i + 1 )
    {
        x = readint("Digite um valor: ");
        print("%s%d.\n\n", "A soma dos divisores impares desse valor = ", somaDivisorImpar(x) );
    }
    
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio01

bool isPrimo( int x )
{
    bool resultado = false;

    int divisor = 1;
    int contador = 0;

    if( x < 0 )
    {   x = x * (-1);   }

    while( x >= divisor )
    {
        if( x % divisor == 0 )
        {   contador = contador + 1; }

        divisor = divisor + 1;
    }

    if( contador == 2 )
    {   resultado = true;   }

    return (resultado);
}
/**
 * Metodo02.
 */
void exercicio02()
{
    // identificacao
    id("Exercicio 02:");

    // programa
    int n = 0;
    int x = 0;

    n = readint("Digite uma quantidade: ");
    print("\n");

    for( int i = 0; i < n; i = i + 1 )
    {
        x = readint("Digite um valor: ");

        if(isPrimo(x))
        {   print("%s\n\n", "O valor e um numero primo.");   }
        else
        {   print("%s\n\n", "O valor nao e um numero primo.");  }
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio02

bool isLogico(char c)
{
    bool resultado = false;

    if( c == '&' || c == '!' || c == '|')
    {   resultado = true;    }

    return (resultado);
}
bool isAritmetico(char c)
{
    bool resultado = false;

    if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {   resultado = true;   }

    return (resultado);
}
bool isRelacional(char c)
{
    bool resultado = false;

    if( c == '>' || c == '<' || c == '=')
    {   resultado = true;   }

    return (resultado);
}
bool isSeparador(char c)
{
    bool resultado = false;

    if( c == ' ' || c == '.' || c == ',' ||
        c == ';' || c == ':' || c == '_' )
    {   resultado = true;   }

    return (resultado);
}

/**
 * Metodo03.
 */
void exercicio03()
{
    // identificacao
    id("Exercicio 03:");

    // programa
    char palavra[80];
    int tamanho = 0;
    char c;

    print( "%s" , "Digite uma cadeia de caracteres: " );
    scan( "%s", palavra ); getchar();

    tamanho = strlen(palavra);

    for( int i = 0; i < tamanho; i = i + 1 )
    {
        c = palavra[i];
        if( isLogico (c) )
            print( "\n%c = %s\n" , c, "logico.");
        else if( isAritmetico (c) )
            print( "\n%c = %s\n" , c, "aritmetico.");
        else if ( isRelacional(c) )
            print( "\n%c = %s\n" , c, "relacional.");
        else if ( isSeparador (c) )
            print( "\n%c = %s\n" , c, "separador.");
        else
            print( "\n%c = %s\n" , c, "simbolo qualquer.");
    }
    
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio03

bool isMinusculo( char c )
{
    bool resultado = false;

    if( 'a' <= c && c <= 'z' )
    {   resultado = true;   }

    return (resultado);
}
bool isMaiuculo( char c )
{
    bool resultado = false;

    if( 'A' <= c && c <= 'Z' )
    {   resultado = true;   }

    return (resultado);
}
bool isDigito( char c )
{
    bool resultado = false;

    if( '0' <= c && c <= '9' )
    {   resultado = true;   }

    return (resultado);
}
bool isOperadores(char c)
{
    bool resultado = false;

    if( isRelacional(c) || isAritmetico(c) || isLogico(c) )
    {   resultado = true;   }

    return (resultado);
}
/**
 * Metodo04.
 */
void exercicio04()
{
    // identificacao
    id("Exercicio 04:");

    // programa
    char s[80];
    int tamanho = 0;
    char c;
    int contadorM = 0, contadorm = 0, contadord = 0, contadorO = 0, contadorS = 0;
    print( "%s" , "Digite uma cadeia de caracteres: " );
    scan( "%s", s ); getchar();

    tamanho = strlen(s);

    for( int i = 0; i < tamanho; i = i + 1 )
    {
        c = s[i];
        if( isMaiuculo(c) )
            contadorM = contadorM + 1;
        else if( isMinusculo(c)  )
            contadorm = contadorm + 1;
        else if( isDigito(c)     )
            contadord = contadord + 1;
        else if( isOperadores(c) )
            contadorO = contadorO + 1;
        else if( isSeparador(c)  )
            contadorS = contadorS + 1;
    }

    print("\n%s%d\n" , "Maiusculas  = " , contadorM);
    print("\n%s%d\n" , "Minusculas  = " , contadorm);
    print("\n%s%d\n" , "Digitos     = " , contadord);
    print("\n%s%d\n" , "Operadores  = " , contadorO);
    print("\n%s%d\n" , "Separadores = " , contadorS);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio04

double maiorMedia(double x, double y, double z)
{
    if( x > y && x > z )
        return (x);
    else if( y > x && y > z)
        return (y);
    else
        return (z);
}
/**
 * Metodo05.
 */
void exercicio05()
{
    // identificacao
    id("Exercicio 05:");

    // programa
    int    n = 0;
    double x = 0.0;
    double somaMenor  = 0.0, somaMedia  = 0.0, somaMaior  = 0.0;
    double mediaMenor = 0.0, mediaMedia = 0.0, mediaMaior = 0.0;
    int    contMenor  = 0  , contMedia  = 0  , contMaior  = 0  ;

    n = readint( "Digite uma quantidade: " );
    print("\n");

    for( int i = 0; i < n; i = i + 1 )
    {
        x = readdouble("Digite um valor: ");
        
        if( x < -13.25 )
        {   
            somaMenor = somaMenor + x;
            contMenor = contMenor + 1;
        }
        else
        {    if( -13.25 <= x && x <= 83.75 )
            {
                somaMedia = somaMedia + x;
                contMedia = contMedia + 1;
            }
            else
            {
                if( x > 83.75 )
                {
                    somaMaior = somaMaior + x;
                    contMaior = contMaior + 1;
                }
            }
        }
    }
    mediaMenor = somaMenor/contMenor;
    mediaMedia = somaMedia/contMedia;
    mediaMaior = somaMaior/contMaior;

    // print("mediaMenor = %lf mediaMedia = %lf mediaMaior = %lf\n", mediaMenor,mediaMedia,mediaMaior);

    print("\n%s %lf\n", "A maior media e =", 
            maiorMedia(mediaMenor,mediaMedia,mediaMaior) );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio05

double cuboInverso( int x )
{
    double valor = 0.0;

    if( x == 0 )
    {
        return (valor);
    }
    else
    {
        valor = 1/pow(x,3);
    }

    return (valor);
}
/**
 * Metodo06.
 */
void exercicio06()
{
    // identificacao
    id("Exercicio 06:");

    // programa
    int a = 0, b = 0;
    int x = 0;
    double soma = 0.0;

    a = readint( "Digite o inicio do intervalo: " ); 
    b = readint( "Digite o final do intervalo : " );

    do
    {
        x = readint( "Digite um valor: " );

        if( a < x && x < b )
        {
            if( x % 2 != 0 )
            {
                soma = soma + cuboInverso(x);
                // print("x = %d f(x) = %lf\n", x , cuboInverso(x));
            }
        }
    } while (x != -1 );
    
    print("\n%s %lf\n", "Soma do cubo dos inversos do impares =", soma);
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio06

/**
 * Metodo07.
 */
void exercicio07()
{
    // identificacao
    id("Exercicio 07:");

    // programa
    double a = 0, b = 0, x = 0;
    int dentro =0 , fora  = 0;
    int acima = 0, abaixo = 0;

    a = readdouble( "Digite o inicio do intervalo: " ); 
    b = readdouble( "Digite o final do intervalo : " );
    print("\n");

    do
    {
        x = readdouble( "Digite um valor: " );

        if( x != 0 )
        {
            if( a < x && x < b )
                dentro = dentro + 1;
            else
            {
                fora = fora + 1;

                if( x > b )
                {
                    acima = acima + 1;
                    // print("acima = %.2lf\n", x);
                }
                else
                {
                    abaixo = abaixo + 1;
                    // print("abaixo = %.2lf\n", x);
                }
            }
        }
    } while (x != 0 );

    print( "\n%s %d\n", "Valores dentro do intervalo:", dentro);
    print( "%s %d\n"  , "Valores fora do intervalo  :", fora  );
    // print( "%s %d\n"  , "Valores acima do intervalo  :", acima  );
    // print( "%s %d\n"  , "Valores abaixo do intervalo  :", abaixo  );

    if ( fora > 0 )
    {
        print( "\n%s %.2lf%%\n", "Porcentagem de valores acima do intervalo :", (double)acima / fora * 100 );
        print( "%s %.2lf%%\n"  , "Porcentagem de valores abaixo do intervalo:", (double)abaixo / fora * 100);
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio07

bool isCrescente(double x, double y, double z)
{
    bool resultado = false;

    if( x < y && x < z && y < z)
    {
        resultado = true;
    }

    return (resultado);
}
bool isDecrescente(double x, double y, double z)
{
    bool resultado = false;

    if( x > y && x > z && y > z)
    {
        resultado = true;
    }

    return (resultado);
}
double maiorIs(double x,double y, double z)
{
    if( x > y && x > z)
        return (x);
    else if( y > x && y > z)
        return (y);
    else
        return (z);
}
double menorIs(double x,double y, double z)
{
    if( x < y && x < z)
        return (x);
    else if( y < x && y < z)
        return (y);
    else
        return (z);
}
/**
 * Metodo08.
 */
void exercicio08()
{
    // identificacao
    id("Exercicio 08:");

    // programa
    double x = 0.0, y = 0.0, z = 0.0;

    x = readdouble( "Digite um valor X: " );
    y = readdouble( "Digite um valor Y: " );
    z = readdouble( "Digite um valor Z: " );

    if( isCrescente(x,y,z) )
        print("\n%s\n", "Os valores estao em ordem crescente.");
    else if ( isDecrescente(x,y,z) )
        print("\n%s\n", "Os valores estao em ordem decrescente.");
    else
    {
        if( menorIs(x,y,z) == maiorIs(x,y,z))
            print("\n%s\n", "O menor valor e o maior sao iguais." );
        else
        {
            print("\n%s %lf.\n", "O menor valor =", menorIs(x,y,z) );
            print("%s %lf.\n", "O maior valor =", maiorIs(x,y,z) );
        }
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio08

bool isCharCrescente(char x, char y, char z)
{
    bool resultado = false;

    if( x < y && x < z && y < z)
    {
        resultado = true;
    }

    return (resultado);
}
bool isCharDecrescente(char x, char y, char z)
{
    bool resultado = false;

    if( x > y && x > z && y > z)
    {
        resultado = true;
    }

    return (resultado);
}

/**
 * Metodo09.
 */
void exercicio09()
{
    // identificacao
    id("Exercicio 09:");

    // programa
    char x = 0, y = 0, z = 0;

    x = readchar( "Digite um caractere X: " );
    y = readchar( "Digite um caractere Y: " );
    z = readchar( "Digite um caractere Z: " );

    if( isCharCrescente(x,y,z) )
        print("\n%s\n", "Os caracteres estao em ordem crescente.");
    else if ( isCharDecrescente(x,y,z) )
        print("\n%s\n", "Os caracteres estao em ordem decrescente.");
    else
        print("\n%s\n", "Os caracteres nao estao em nenhuma ordem.");

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio09

bool isStrCrescente( string x, string y, string z )
{
    bool resultado = false;

    if( (strcmp(x,y) < 0) && (strcmp(x,z) < 0) && (strcmp(y,z) < 0) )
    {
        resultado = true;
    }

    return (resultado);
}
bool isStrDecrescente( string x, string y, string z )
{
    bool resultado = false;

    if( (strcmp(x,y) > 0) && (strcmp(x,z) > 0) && (strcmp(y,z) > 0) )
    {
        resultado = true;
    }

    return (resultado);
}

string menorStr(string x, string y, string z)
{
    if ( (strcmp(x,y) < 0) && (strcmp(x,z) < 0) )
        return (x);
    else if( (strcmp(y,x) < 0) && (strcmp(y,z) < 0) )
        return (y);
    else
        return (z);
}

string maiorStr(string x, string y, string z)
{
    if ( (strcmp(x,y) > 0) && (strcmp(x,z) > 0) )
        return (x);
    else if( (strcmp(y,x) > 0) && (strcmp(y,z) > 0) )
        return (y);
    else
        return (z);
}
/**
 * Metodo10.
 */
void exercicio10()
{
    // identificacao
    id("Exercicio 10:");

    // programa
    char x[80];
    char y[80];
    char z[80];

    printf("%s", "Digite uma cadeia de caracteres X: ");
    scanf("%s", x ); getchar();
    printf("%s", "Digite uma cadeia de caracteres Y: ");
    scanf("%s", y ); getchar();
    printf("%s", "Digite uma cadeia de caracteres Z: ");
    scanf("%s", z ); getchar();

    if( isStrCrescente(x,y,z) )
        printf("\n%s\n", "As cadeia de caracteres estao em ordem crescente.");
    else if ( isStrDecrescente(x,y,z) )
        printf("\n%s\n", "As cadeia de caracteres estao em ordem decrescente.");
    else
    {
        if( menorStr(x,y,z) == maiorStr(x,y,z))
            printf("\n%s\n", "O menor e a maior cadeia de caracteres sao iguais." );
        else
        {
            printf("\n%s %s\n", "A menor cadeia de caracteres =", menorStr(x,y,z) );
            printf("%s %s\n"  , "A maior cadeia de caracteres =", maiorStr(x,y,z) );
        }
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio10
