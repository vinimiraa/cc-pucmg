/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios07 - v0.0. - 02 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios07 Exercicios07.c
 *      Windows: gcc -o Exercicios07 Exercicios07.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios07
 *      Windows: Exercicios07
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio0711();
void exercicio0712();
void exercicio0713();
void exercicio0714();
void exercicio0715();
void exercicio0716();
void exercicio0717();
void exercicio0718();
void exercicio0719();
void exercicio0720();
void exercicio07E1();
void exercicio07E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios07 - v0.0");

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
        case  1: exercicio0711(); break;
        case  2: exercicio0712(); break;
        case  3: exercicio0713(); break;
        case  4: exercicio0714(); break;
        case  5: exercicio0715(); break;
        case  6: exercicio0716(); break;
        case  7: exercicio0717(); break;
        case  8: exercicio0718(); break;
        case  9: exercicio0719(); break;
        case 10: exercicio0720(); break;
        case 11: exercicio07E1(); break;
        case 12: exercicio07E2(); break;
        default:
            printf("\n%s\n", "ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0 );

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
    printf("%s\n", "  1 - Exercicio 0711");
    printf("%s\n", "  2 - Exercicio 0712");
    printf("%s\n", "  3 - Exercicio 0713");
    printf("%s\n", "  4 - Exercicio 0714");
    printf("%s\n", "  5 - Exercicio 0715");
    printf("%s\n", "  6 - Exercicio 0716");
    printf("%s\n", "  7 - Exercicio 0717");
    printf("%s\n", "  8 - Exercicio 0718");
    printf("%s\n", "  9 - Exercicio 0719");
    printf("%s\n", " 10 - Exercicio 0720");
    printf("%s\n", " 11 - Exercicio 07E1");
    printf("%s\n", " 12 - Exercicio 07E2");
    printf("\n");
} // fim menuOpcoes()

void metodo0711(char *filename, int n, int x)
{
    FILE *arquivo = fopen(filename, "wt");

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
    
        while( n > 0 )
        {
            if( x % 3 == 0 && isOdd(x) )
            {
                fprint(arquivo, "%d\n", x);
                n = n - 1;
            }
            x = x + 3;
        }
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo01.
 */
void exercicio0711()
{
    // identificacao
    id("Exercicio 0711:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0711("RESULTADO01.TXT", n, 9);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0711

void metodo0712_a(FILE *arquivo,int n, int x)
{
    if( n > 0 )
    {   
        if(x % 7 == 0 && isOdd(x))
        {
            metodo0712_a(arquivo, n - 1, x + 7);
            fprint(arquivo,"%d\n", x);
        }
        else
            metodo0712_a(arquivo, n, x + 7);
    }
}
void metodo0712(char *filename, int n)
{
    FILE *arquivo = fopen(filename, "wt");

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        metodo0712_a(arquivo, n, 21);
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo02.
 */
void exercicio0712()
{
    // identificacao
    id("Exercicio 0712:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0712("RESULTADO02.TXT", n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0712

void metodo0713(char *filename, int n, int x)
{
    FILE *arquivo = fopen(filename, "wt");
    int i = 0;

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        for( i = 0; i < n; i = i + 1)
        {
            fprint(arquivo, "%d\n", x);
            x = x * 7;
        }
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo03.
 */
void exercicio0713()
{
    // identificacao
    id("Exercicio 0713:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0713("RESULTADO03.TXT", n, 1);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0713

void metodo0714_a(FILE *arquivo, int n, double nume, double deno )
{
    if( n > 0 )
    {
        metodo0714_a(arquivo, n - 1, nume, deno * 7);
        fprint(arquivo, "%lf\n",nume/deno); 
    }
}
void metodo0714(char *filename, int n)
{
    FILE *arquivo = fopen(filename, "wt");

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        metodo0714_a(arquivo, n, 1.0, 1.0);    
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo04.
 */
void exercicio0714()
{
    // identificacao
    id("Exercicio 0714:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0714("RESULTADO04.TXT", n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0714

void metodo0715(char *filename, int x, int n)
{
    FILE *arquivo = fopen(filename, "wt");
    int i = 0;
    int p = 0;

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        for( i = 0; i < n; i = i + 1)
        {
            fprint(arquivo, "%lf \n",1.0/pow(x,p));
            p = p + 1;
        }
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }
    
    fclose(arquivo);
}
/**
 * Metodo05.
 */
void exercicio0715()
{
    // identificacao
    id("Exercicio 0715:");

    // programa
    int x = 0;
    int n = 0;
    x = readint("Digite um valor: ");
    n = readint("Digite uma quantidade : ");

    metodo0715("RESULTADO05.TXT", x, n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0715

void metodo0716(char *filename,int n)
{
    FILE *arquivo1 = fopen(filename, "rt"); // arquivo a ser lido
    FILE *arquivo2 = fopen("RESULTADO06.TXT", "wt"); // novo arquivo

    double soma = 0.0;
    double x    = 0.0; 
    int    y    = 0;
    double array[n]; 

    if( arquivo1 == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo para leitura!");
    else
    {
        fscanf(arquivo1, "%lf", &x);
        array[y] = x;
        while ( !feof(arquivo1) && y < n)
        {
            y = y + 1;
            fscan(arquivo1, "%lf", &x);
            array[y] = x;
        }
        print("\n%s\n", "Dados lidos do arquivo com sucesso!");
    } 

    for(int i = 0; i < n; i = i + 1)
        soma = soma + array[i]; 

    if ( arquivo2 == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo para gravar!");
    else
    {
        fprint(arquivo2, "%d\n", n);
        fprint(arquivo2, "%lf\n", soma);
        print("\n%s\n", "Dados gravados com sucesso!");
    }

    fclose(arquivo1);
    fclose(arquivo2);
}
/**
 * Metodo06.
 */
void exercicio0716()
{
    // identificacao
    id("Exercicio 0716:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0716("RESULTADO05.TXT",n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0716

void metodo0717(char *filename, int n)
{
    FILE *arquivo1 = fopen(filename, "rt");
    FILE *arquivo2 = fopen("RESULTADO07.TXT", "wt");

    double soma = 0.0;
    double x    = 0.0;
    int    i    = 0.0;
    double array[n];

    if( arquivo1 == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo para leitura!");
    else
    {
        fscan(arquivo1, "%lf", &x);
        array[i] = x; // array[0]
        while ( !feof(arquivo1) && i < n )
        {
            i = i + 1; // proxima posicao
            fscan(arquivo1, "%lf", &x);
            array[i] = x; 
        }
        print("\n%s\n", "Dados lidos do arquivo com sucesso!");
    }

    for( i = 0; i < n; i = i + 1)
        soma = soma + array[i];

    if( arquivo2 == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo para gravar!");
    else
    {
        fprint(arquivo2, "%d\n", n);     // quantidade
        fprint(arquivo2, "%lf\n", soma); // soma
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo1);
    fclose(arquivo2);
}
/**
 * Metodo07.
 */
void exercicio0717()
{
    // identificacao
    id("Exercicio 0717:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0717("RESULTADO04.TXT", n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0717

void metodo0718(char *filename,int n)
{
    FILE *arquivo = fopen(filename, "wt");

    int z = 0;
    int i = 1;

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        while ( n > 0 )
        {
            z = fibonacci(i);
            if( z % 2 == 0)
            {
                fprint(arquivo, "%d\n", z);
                n = n - 1; 
            }
            i = i + 1;
        }   
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo08.
 */
void exercicio0718()
{
    // identificacao
    id("Exercicio 0718:");

    // programa
    int n = 0;
    n = readint("Digite uma quantidade: ");

    metodo0718("RESULTADO08.TXT",n);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0718

void metodo0719(char* filename, char* palavra)
{
    FILE *arquivo = fopen(filename, "wt");
    int count = 0;
    int tamanho = strlen(palavra);

    for(int i = 0; i < tamanho; i = i + 1)
    {
        if( isUpper(palavra[i]) )
            count = count + 1;
    }

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        fprint(arquivo,"%s\n", palavra);
        fprint(arquivo,"%d\n", count);
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo09.
 */
void exercicio0719()
{
    // identificacao
    id("Exercicio 0719:");

    // programa
    char *palavra = 0;
    palavra = readstring("Digite uma cadeia de caracteres: ");

    metodo0719("RESULTADO09.TXT",palavra);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0719

void metodo0720(char* filename, char* palavra)
{
    FILE* arquivo = fopen(filename, "wt");
    int count = 0;
    int tamanho = strlen(palavra);

    for(int i = 0; i < tamanho; i = i + 1)
    {
        if( isDigit(palavra[i]) )
        {    
            if(palavra[i] >= '5')
            {
                count = count + 1;
            }
        }
    }

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        fprint(arquivo,"%s\n", palavra);
        fprint(arquivo,"%d\n", count);
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo10.
 */
void exercicio0720()
{
    // identificacao
    id("Exercicio 0720:");

    // programa
    char* palavra = 0;
    palavra = readstring("Digite uma cadeia de caracteres: ");

    metodo0720("RESULTADO10.TXT", palavra);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio0720

void metodo07E1_a(FILE* arquivo, int x, int divisor)
{
    if (x < 0)
    {
        x = (-1) * x;
    } 

    if( divisor <= x )
    {
        metodo07E1_a(arquivo, x, divisor + 1);
        if( x % divisor == 0 )
        {
            fprint(arquivo, "%d\n", divisor);
        }
    }
}
void metodo07E1(char* filename, int x)
{
    FILE * arquivo = fopen(filename, "wt");

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir arquivo!");
    else
    {
        metodo07E1_a(arquivo, x, 1);
        print("\n%s\n", "Dados gravados no arquivo com sucesso!");
    }

    fclose(arquivo);
}
/**
 * Metodo11.
 */
void exercicio07E1()
{
    // identificacao
    id("Exercicio 07E1:");

    // programa
    int x = 0;
    x = readint("Digite um valor: ");

    metodo07E1("RESULTADOE1.TXT", x);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio07E1

int metodo07E2( char* filename )
{
    FILE * arquivo = fopen(filename, "rt");

    char palavra[80];
    int count = 0;

    if( arquivo == NULL )
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo!");
    else
    {
        fgets( palavra, 80, arquivo );
        if(palavra[0] == 'd' || palavra[0] == 'D')
                count = count + 1;
        // print("%s\n", palavra);

        while (!feof(arquivo) && fgets( palavra, 80, arquivo ) != NULL)
        {
            // print("%s\n", palavra);
            if(palavra[0] == 'd' || palavra[0] == 'D')
            {
                count = count + 1;
            }
        }
        // print("%d\n", count);
    }

    fclose(arquivo);

    return (count);
}
/**
 * Metodo12.
 */
void exercicio07E2()
{
    // identificacao
    id("Exercicio 07E2:");

    // programa
    int resultado = metodo07E2("RESULTADOE2.TXT");

    print("%d%s\n", resultado, " palavras comecam com (d) ou (D) no arquivo RESULTADOE2.TXT");

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
    clear();
} // fim exercicio07E2