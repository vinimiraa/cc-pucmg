/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios06 - v0.0. - 25 / 09 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios06 Exercicios06.c
 *      Windows: gcc -o Exercicios06 Exercicios06.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios06
 *      Windows: Exercicios06
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio0611();
void exercicio0612();
void exercicio0613();
void exercicio0614();
void exercicio0615();
void exercicio0616();
void exercicio0617();
void exercicio0618();
void exercicio0619();
void exercicio0620();
void exercicio06E1();
void exercicio06E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios06 - v0.0");

        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch (opcao)
        {
        case 0:
            printf("\n%s\n", "Programa Encerrado...");
            break;
        case  1: exercicio0611(); break;
        case  2: exercicio0612(); break;
        case  3: exercicio0613(); break;
        case  4: exercicio0614(); break;
        case  5: exercicio0615(); break;
        case  6: exercicio0616(); break;
        case  7: exercicio0617(); break;
        case  8: exercicio0618(); break;
        case  9: exercicio0619(); break;
        case 10: exercicio0620(); break;
        case 11: exercicio06E1(); break;
        case 12: exercicio06E2(); break;
        default:
            printf("\n%s\n", "ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para terminar!");
    getchar();

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
    printf("%s\n", "  1 - Exercicio 0611");
    printf("%s\n", "  2 - Exercicio 0612");
    printf("%s\n", "  3 - Exercicio 0613");
    printf("%s\n", "  4 - Exercicio 0614");
    printf("%s\n", "  5 - Exercicio 0615");
    printf("%s\n", "  6 - Exercicio 0616");
    printf("%s\n", "  7 - Exercicio 0617");
    printf("%s\n", "  8 - Exercicio 0618");
    printf("%s\n", "  9 - Exercicio 0619");
    printf("%s\n", " 10 - Exercicio 0620");
    printf("%s\n", " 11 - Exercicio 06E1");
    printf("%s\n", " 12 - Exercicio 06E2");
    printf("\n");
} // fim menuOpcoes()

void metodo0611(int x,int n)
{
    // for(int i = 1; i <= n; i = i + 1)
    // {
    //     print("%d ", x);
    //     if(x % 2 != 0)
    //         x = x + 1;
    //     else
    //         x = x + 2;
    // }
    if(n >= 1) // teste / base
    {
        print("%d ", x);
        metodo0611(x+7, n-1);
    }
}
/**
 * Metodo01.
 */
void exercicio0611()
{
    // identificacao
    id("Exercicio 0611:");

    // programa
    int n = 0;
    n = readint("Digite um valor: ");

    print("\n%s\n", "Valores multiplos de 7, em ordem crescente, comecando no valor 7:");
    metodo0611(7,n);
    print("\n");

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0611

void metodo0612(int x, int n)
{
    if(n >= 1)
    {
        metodo0612( x + 7, n - 1 );
        print("%d ", x);
    }
}
/**
 * Metodo02.
 */
void exercicio0612()
{
    // identificacao
    id("Exercicio 0612:");

    // programa
    int n = 0;
    n = readint("Digite um valor: ");

    print("\n%s\n", "Multiplos de 7, em ordem decrescente, encerrando no valor 7:");
    metodo0612(7,n);
    print("\n");

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0612

void metodo0613(int x, int n)
{
    if(n >= 1)
    {
        print("1/%d ", x);
        if(x == 1)
            metodo0613( x + 6, n - 1 );
        else
            metodo0613( x + 7, n - 1 );
    }
}
/**
 * Metodo03.
 */
void exercicio0613()
{
    // identificacao
    id("Exercicio 0613:");

    // programa
    int n = 0;
    n = readint("Digite um valor: ");

    print("\n%s\n", "Valores da sequencia de inversos dos multiplos de 7, comecando em 1: ");
    metodo0613(1,n);
    print("\n");

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0613

void metodo0614(int x, int n)
{
    if(n > 1)
    {
        if(x % 7 == 0)
        {
            metodo0614(x + 7, n - 1);
            print("1/%d ", x);
        }
        else
            metodo0614(x + 1, n);
        if(x == 1)
        {
            print("1/1");
        }
    }
}
/**
 * Metodo04.
 */
void exercicio0614()
{
    // identificacao
    id("Exercicio 0614:");

    // programa
    int n = 0;
    n = readint("Digite um valor: ");

    print("\n%s\n", "Valores da sequencia de inversos dos multiplos de 7, terminando em 1: ");
    metodo0614(1,n);
    print("\n");

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0614

int metodo0615(int x, int y, int n)
{
    int soma = 0;
    if(n >= 1)
    {
        // print("\nAntes  : soma = %2d   x = %2d   n = %2d", soma, x, n);
        soma = x + metodo0615( x + y, y + 2, n - 1 );
        // print("\nDepois : soma = %2d   x = %2d   n = %2d", soma, x, n);
    }
    return ( soma );
}
/**
 * Metodo05.
 */
void exercicio0615()
{
    // identificacao
    id("Exercicio 0615:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    print("\n%s%d\n", "Soma de valores gerados pela adicao dos primeiros valores impares positivos ao valor 7 = ", 
                        metodo0615(7,1,n) );

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0615

double metodo0616(double nume, double deno, int n)
{
    double soma = 0.0;
    if(n > 0)
    {   
        // print("\nAntes  : nume = %.lf   deno = %.lf   n = %2d   soma = %lf",nume,deno,n,soma);
        if( (int)deno % 2 == 0 || deno == 7 )
        {
            soma = nume/deno + metodo0616(nume, deno + 7, n - 1); 
            // print("\nDentro : nume = %.lf   deno = %.lf   n = %2d   soma = %lf",nume,deno,n,soma);
        }
        else
            soma = 0 + metodo0616(nume, deno + 7, n);
    }
    return ( soma );
}
/**
 * Metodo06.
 */
void exercicio0616()
{
    // identificacao
    id("Exercicio 0616:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    print("\n%s%lf\n", "Soma dos inversos (1/x) dos primeiros valores pares positivos multiplos do valor 7 = ", 
                        metodo0616(1.0,7.0,n) );
                        
    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0616

void metodo0617(char* palavra, int tamanho)
{   
    if( palavra && tamanho >= 0 )
    {
        metodo0617(palavra,tamanho-1);
        if( isSpace(palavra[tamanho]) )
            print("\n0");
        else 
            print("\n%c", palavra[tamanho]);
    }
}
/**
 * Metodo07.
 */
void exercicio0617()
{
    // identificacao
    id("Exercicio 0617:");

    // programa
    char *palavra = 0;
    int tamanho = 0;
    palavra = readstring("Digite uma cadeia de caracteres: ");

    tamanho = strlen(palavra);

    metodo0617(palavra, tamanho);

    free(palavra);
    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0617

int metodo0618(char *palavra, int tamanho)
{
    int count = 0;
    if( palavra && tamanho >= 0 )
    {
        count = metodo0618(palavra, tamanho - 1); 
        if( isDigit(palavra[tamanho]) )
        {
            if( palavra[tamanho] % 2 == 0)
            {
                // print( "\n%c", palavra[tamanho] );
                count = count + 1;
            }
        }
    }
    return (count);
}
/**
 * Metodo08.
 */
void exercicio0618()
{
    // identificacao
    id("Exercicio 0618:");

    // programa
    char *palavra = 0;
    int tamanho = 0;
    int resultado = 0;
    palavra = readstring("Digte uma cadeia de caracteres: ");

    tamanho = strlen(palavra);

    resultado = metodo0618(palavra,tamanho);

    print("\n%s%d\n", "A quantidade de digitos pares que a cadeia de caracteres possui e = ",
                        resultado);

    free(palavra);
    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0618

int metodo0619(char *palavra, int tamanho)
{
    int count = 0;
    if(palavra && tamanho >= 0)
    {
        count = metodo0619(palavra, tamanho - 1);
        if(isUpper(palavra[tamanho]) && palavra[tamanho] > 'K')
        {
            count = count + 1;
        }
    }
    return (count);
}
/**
 * Metodo09.
 */
void exercicio0619()
{
    // identificacao
    id("Exercicio 0619:");

    // programa
    char *palavra = 0;
    int tamanho = 0;
    int resultado = 0;
    palavra = readstring("Digite uma cadeia de caracteres: ");

    tamanho = strlen(palavra);

    resultado = metodo0619(palavra,tamanho);

    print("\n%s%d\n", "A quantidade de maiusculas maiores que 'K' na cadeia de caracteres = ", resultado);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0619

int fibonacci ( int n )
{
    int resposta = 0;
    if ( n == 1 || n == 2 )
        {
        resposta = 1;
        }
    else
    {
        if ( n > 2 )
        {
            resposta = fibonacci (n - 1) + fibonacci (n - 2);
        } 
    } 
    return ( resposta );
} 
int metodo0620(int x, int y, int n)
{
    int soma = 0;
    int z = 0; 
    if( x <= n )
    {
        // print("\n1 : x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
        z =fibonacci(y);
        if( z % 2 == 0)  
        {   
            soma = soma + z;
            // print("\n1a : x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
            metodo0620(x + 1, y + 1, n);
            // print("\n2a: x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
        }
        else
        {
            // print("\n1b : x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
            metodo0620(x, y + 1, n); 
            // print("\n2b: x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
        }
        print("\n2: x = %2d   y = %2d   z = %2d   s = %2d", x,y,z,soma);
    }
    return (soma);
}
int metodo0620_a(int n)
{
    int z = 0;
    int y = 1;
    int x = 1;
    int soma = 0;

    /*Solucao usando for*/
    for(y = 1;x <= n; y = y + 1)
    {
        z = fibonacci(y);
        if( z % 2 == 0)
        {
            soma = soma + z;
            x = x + 1;
        }
    }
    return (soma);
}

int metodo0620_b(int n)
{
    int z = 0;
    int y = 1;
    int x = 1;
    int soma = 0;

    /*Solucao usando while*/
    while (x <= n)
    {
        z = fibonacci(y);
        if( z % 2 == 0)
        {
            soma = soma + z;
            x = x + 1;
        }
        y = y + 1;
    }
    return (soma);
}

/**
 * Metodo10.    
 */
void exercicio0620()
{
    // identificacao
    id("Exercicio 0620:");

    // programa
    int n = 0;
    int resultado = 0;
    int resultado_a = 0;
    int resultado_b = 0;
    n = readint("Digite uma quantidade: ");

    resultado = metodo0620(1,1,n);
    resultado_a = metodo0620_a(n);
    resultado_b = metodo0620_b(n);
    
    print("\n%s%d\n", "Metodo Recursivo: Soma = ", resultado);
    print("\n%s%d\n", "Metodo com for  : Soma = ", resultado_a);
    print("\n%s%d\n", "Metodo com while: Soma = ", resultado_b);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0620

int somarE1(int x,int n,int p)
{
    int soma = 1;
    if(n > 1)
    {
        // print("\nA: %d: x = %2d p = %2d s = %2d", n, x, p, soma);
        soma = pow(x,p) + somarE1( x, n - 1, p+2);
        // print("\nD: %d: x = %2d p = %2d s = %2d", n, x, p, soma);
    }
    return (soma);
}
int metodo06E1(int x, int n)
{
    int resultado = 0;
    resultado = somarE1(x,n,2);
    return (resultado);
}
/**
 * Metodo11.
 */
void exercicio06E1()
{
    // identificacao
    id("Exercicio 06E1:");

    // programa
    int x = 0;
    int n = 0;
    int resultado = 0;
    x = readint("Digite um valor: ");
    n = readint("Digite uma quantidade: ");

    resultado = metodo06E1(x,n);

    print("\n%s%d\n", "Soma = ", resultado);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio06E1

double somarE2(int n, double soma, double nume, double deno)
{
    if(n > 0)
    {
        if(nume == 1 && deno == 2)
        {
            // print("\n%d: %lf/%lf", n, nume, deno);
            soma = somarE2(n-1,
                            soma + (nume/factorial(deno)),
                            nume + 1,
                            deno + 1);
        }
        else
        {
            // print("\n%d: %lf/%lf", n, nume, deno);
            soma = somarE2(n-1,
                            soma + (nume/factorial(deno)),
                            nume + 2,
                            deno + 2);
        }
    }
    return (soma);
}
double metodo06E2(int n)
{
    double resultado = 0.0;
    if( n > 0 )
    {
        // print("%d: %lf", n, 1.0);
        resultado = somarE2(n-1,1.0,1.0,2.0);
    }
    return (resultado);
}
/**
 * Metodo12.
 */
void exercicio06E2()
{
    // identificacao
    id("Exercicio 06E2:");

    // programa
    int n = 0;
    double resultado = 0;
    n = readint("Digite a quantidade de termos: ");

    resultado = metodo06E2(n);

    print("\n%s%.12lf\n", "Soma = ", resultado);
    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio06E2