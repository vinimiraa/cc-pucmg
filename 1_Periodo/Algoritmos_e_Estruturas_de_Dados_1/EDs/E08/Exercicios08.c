/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados I
 *   
 *  Exercicios08 - v0.0. - 12 / 10 / 2023
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o Exercicios08 Exercicios08.c
 *       Windows: gcc -o Exercicios08 Exercicios08.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./Exercicios08
 *       Windows: Exercicios08
 *   
 */  

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio0811();
void exercicio0812();
void exercicio0813();
void exercicio0814();
void exercicio0815();
void exercicio0816();
void exercicio0817();
void exercicio0818();
void exercicio0819();
void exercicio0820();
void exercicio08E1();
void exercicio08E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios08 - v0.0");

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
        case 1:
            exercicio0811();
            break;
        case 2:
            exercicio0812();
            break;
        case 3:
            exercicio0813();
            break;
        case 4:
            exercicio0814();
            break;
        case 5:
            exercicio0815();
            break;
        case 6:
            exercicio0816();
            break;
        case 7:
            exercicio0817();
            break;
        case 8:
            exercicio0818();
            break;
        case 9:
            exercicio0819();
            break;
        case 10:
            exercicio0820();
            break;
        case 11:
            exercicio08E1();
            break;
        case 12:
            exercicio08E2();
            break;
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
    printf("%s\n", "  1 - Exercicio 0811");
    printf("%s\n", "  2 - Exercicio 0812");
    printf("%s\n", "  3 - Exercicio 0813");
    printf("%s\n", "  4 - Exercicio 0814");
    printf("%s\n", "  5 - Exercicio 0815");
    printf("%s\n", "  6 - Exercicio 0816");
    printf("%s\n", "  7 - Exercicio 0817");
    printf("%s\n", "  8 - Exercicio 0818");
    printf("%s\n", "  9 - Exercicio 0819");
    printf("%s\n", " 10 - Exercicio 0820");
    printf("%s\n", " 11 - Exercicio 08E1");
    printf("%s\n", " 12 - Exercicio 08E2");
    printf("\n");
} // fim menuOpcoes()

void readintArray(int n, int array[])
{
    int x = 0;
    int y = 0;
    string text = allocchar(STR_SIZE);
    
    for (x = 0; x < n; x = x + 1)
    {
        strcpy(text, "");
        do{
            y = readint( concat( concat(text, inttostr(x)), " : " ) );
        }while ( isNegative(y) || isEven(y) );
        array[x] = y;
    }
} // end readIntArray ( )
/**
 * Metodo01.
 */
void exercicio0811()
{
    // identificacao
    id("Exercicio 0811:");

    // programa
    int n = 0;
    n = readint("Digite um tamanho: "); print("\n");
    int array[n];

    if( n <= 0 )
    {
        print("%s\n", "ERRO: tamanho invalido");
    }
    else
    {
        readintArray(n,array);
        printArray(n,array);
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0811

int freadArraySize(string fileName)
{
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");

    fscan(arquivo, "%d", &n);
    if (n <= 0)
    {
        print("\n%s\n","ERRO: Valor invalido.");
        n = 0;
    }
    fclose(arquivo);

    return (n);
} // end freadArraySize ( )
void freadIntArray(string fileName, int n, int array[])
{
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");

    fscan(arquivo, "%d", &x);
    if (n <= 0 || n > x)
    {
        print("\n%s\n","ERRO: Tamanho invalido.");
    }
    else
    {
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            fscan(arquivo, "%d", &y);
            array[x] = y;
            x = x + 1;
        }
    }

    fclose(arquivo);
} // end freadIntArray ( )
/**
 * Metodo02.
 */
void exercicio0812()
{
    // identificacao
    id("Exercicio 0812:");

    // programa
    int n     = 0;
    int count = 0;
    int x     = 0;
    FILE *arquivo = fopen("DADOS02.TXT", "wt");
    
    //ler tamanho do array
    n = freadArraySize("ARRAY02.TXT");
    if( n <= 0 )
    {
        print("\n%s\n", "ERRO: Tamanho Invalido.");
    }
    else
    {
        int array[n];
        //ler os numeros do array
        freadIntArray("ARRAY02.TXT", n, array);
        print("\n%s\n", "Dados lidos do arquivo ARRAY02.TXT.");
        // saber quantos satisfazem a condicao
        for(int i = 0; i < n; i++)
        {
            if( isPositive(array[i]) && isOdd(array[i]) )
                count++;
        }
        //mostrar quantos satisfazem a condicao
        fprint(arquivo, "%d\n", count);
        //mostrar os numeros q satisfazem a condicao
        for(int i = 0; i < n; i++)
        {
            x = array[i];
            if( isPositive(x) && isOdd(x) )
            {
                fprint(arquivo,"%d\n", x);
            }
        }
        print("\n%s\n", "Dados gravados no arquivo DADOS02.TXT.");
    }
    fclose(arquivo);

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0812

int randnum(int a, int b)
{
    int x = 0;
    while( x < a || b < x )
    {
        x = rand() % 100;
    }
    return(x);
}
/**
 * Metodo03.
 */
void exercicio0813()
{
    // identificacao
    id("Exercicio 0813:");

    // programa
    int a = 0; //limite inicial
    int b = 0; //limite final 
    int n = 0; //quantidade de elementos
    int x = 0; //valor aleatorio
    int i = 0; //variavel para utilizar no arranjo
    FILE *arquivo = fopen("DADOS03.TXT", "wt");
    srand( time(NULL) );
    
    a = readint("Digite o limite inicial do intervalo: "          );
    b = readint("Digite o limite final do intervalo  : "          );
    n = readint("Digite a quantidades de elementos no intervalo: ");

    if( a > b )
    {
        print("\n%s\n", "ERRO: Limite Inicial Maior que o Limite Final");
    }
    else
    {
        int array[n];
        fprint(arquivo, "%d\n", n);
        for( i = 0; i < n; i++ )
        {
            x = randnum(a,b);
            array[i] = x;
            fprint(arquivo,"%d\n", array[i] );
        }
        print("\n%s\n", "Dados gravados no arquivo DADOS03.TXT.");
        // while(n > i)
        // {
        //     x = rand() % 120;
        //     if(inClosedInterval(x,a,b))
        //     {
        //         array[i] = x;
        //         fprint(arquivo, "%d\n", array[i]);
        //         i++;
        //     }
        // }
    }

    fclose(arquivo);
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0813

int minoddArray(int n, int array[])
{
    int menor = 0;
    int i     = 0;
    menor = array[0];
    for( i  = 0; i < n; i = i + 1)
    {
        if( (array[i] < menor) && (array[i] % 2 != 0) )
        {
            menor = array[i];
        }
    }
    return (menor);
}
/**
 * Metodo04.
 */
void exercicio0814()
{
    // identificacao
    id("Exercicio 0814:");

    // programa
    int n = 0;
    int x = 0;

    n = freadArraySize("DADOS03.TXT");

    int array[n];

    freadIntArray("DADOS03.TXT", n, array);

    x = minoddArray(n,array);
    print("%s%d\n", "O menor valor impar do arquivo DADOS03.TXT = ", x);
    
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0814

int maxevenArray(int n, int array[])
{
    int maior = 0;
    int i     = 0;
    maior = array[0];
    for( i = 0; i < n; i = i + 1 )
    {
        if( (array[i] > maior) && (array[i] % 2 == 0) )
        {
            maior = array[i];
        }
    }
    return (maior);
}
/**
 * Metodo05.
 */
void exercicio0815()
{
    // identificacao
    id("Exercicio 0815:");

    // programa
    int n = 0;
    int x = 0;

    n = freadArraySize("DADOS03.TXT");

    int array[n];

    freadIntArray("DADOS03.TXT", n, array);

    x = maxevenArray(n,array);
    print("%s%d\n", "O maior valor par do arquivo DADOS03.TXT = ", x);

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0815

double findmedia(int n, int array[])
{
    double media = 0.0;
    double soma = 0.0;
    for(int i = 0; i < n; i = i + 1)
    {
        soma = soma + array[i];
    }
    media = soma / n;
    return ( media );
}
/**
 * Metodo06.
 */
void exercicio0816()
{
    // identificacao
    id("Exercicio 0816:");

    // programa
    FILE *arquivo1 = fopen("MEDIAMENOR.TXT", "wt");
    FILE *arquivo2 = fopen("MEDIAMAIOR.TXT", "wt");

    int n = 0, count1 = 0, count2 = 0;
    double media = 0.0;

    n = freadArraySize("DADOS03.TXT");

    if( n <= 0 )
    {
        print("\n%s\n", "ERRO: Tamanho invalido.");
    }
    else
    {
        int array[n];

        freadIntArray("DADOS03.TXT", n, array);

        media = findmedia(n,array);
        // print("%.5lf", media);
        //contar quantos dados sao maiores ou iguais e menores que a media
        for(int i = 0; i < n; i = i + 1)
        {
            if(array[i] < media)
            {
                count1++;
            } 
            else
            if( array[i] >= media)
            {
                count2++;
            }
        }
        fprint(arquivo1, "%d\n", count1); // quant. maior ou igual a media
        fprint(arquivo2, "%d\n", count2); // quant. menor que a media
        for(int i = 0; i < n; i = i + 1)
        {
            if(array[i] < media)
            {
                fprint(arquivo1, "%d\n", array[i]);
            } 
            else
            if( array[i] >= media)
            {
                fprint(arquivo2, "%d\n", array[i]);
            }
        }
        print("\n%s\n", "Os dados do arquivo DADOS03.TXT que sao menores que a media foram gravados no arquivo MEDIAMENOR.TXT");
        print("\n%s\n", "Os dados do arquivo DADOS03.TXT que sao maiores que a media foram gravados no arquivo MEDIAMAIOR.TXT");
    }

    fclose(arquivo1);
    fclose(arquivo2);

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0816

bool isDecrescente(int n,int array[])
{
    bool resultado = true;
    for(int i = 0; i < n - 1; i++)
    {
        if( array[i] < array[i + 1] )
            resultado = false;
    }
    return ( resultado );
}
/**
 * Metodo07.
 */
void exercicio0817()
{
    // identificacao
    id("Exercicio 0817:");

    // programa
    int array1[10]; //= {10,9,8,7,6,5,4,3,2,1};
    int array2[] = {10,9,8,7,6,5,4,3,2,1};

    srand( time(NULL) );
    for( int i = 0; i < 10; i = i + 1)
    {
        array1[i] = rand() % 110;
    }

    print("%s\n", "Arranjo 1: ");
    printArray(10, array1);

    print("%s\n", "Arranjo 2: ");
    printArray(10, array2);

    if( isDecrescente(10,array1) )
        printf("\n%s\n", "O arranjo 1 esta ordenado de forma decrescente."    );
    else
        printf("\n%s\n", "O arranjo 1 nao esta ordenado de forma decrescente.");
    
    if( isDecrescente(10,array2) )
        printf("\n%s\n", "O arranjo 2 esta ordenado de forma decrescente."    );
    else
        printf("\n%s\n", "O arranjo 2 nao esta ordenado de forma decrescente.");

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0817

bool findnum(int x,int p, int n, int array[])
{
    bool resultado =  false;
    for(int i = p;i < n; i = i + 1)
    {
        if(array[i] == x)
            resultado = true;
    }
    return (resultado);
}
/**
 * Metodo08.
 */
void exercicio0818()
{
    // identificacao
    id("Exercicio 0818:");

    // programa
    int x = 0;
    int n = 0;
    int p = 0; // alterar a posicao inicial para se comecar a procura

    n = freadArraySize("DADOS03.TXT");

    int array[n];

    freadIntArray("DADOS03.TXT", n, array);

    x =readint("Digite o valor a ser procurado: ");

    if( findnum(x, p, n, array) )
        print("\n%s%d\n", "O valor existe no arquivo DADOS03.TXT a partir da posicao ", p);
    else
        print("\n%s%d\n", "O valor nao existe no arquivo DADOS03.TXT a partir da posicao ", p);

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0818

int whereisnum(int x, int p, int n, int array[])
{
    int resultado = 0;

    for(int i = p; i < n; i = i + 1)
    {
        if(array[i] == x)
            resultado = i;
    }

    return (resultado);
}
/**
 * Metodo09.
 */
void exercicio0819()
{
    // identificacao
    id("Exercicio 0819:");

    // programa
    int x = 0;
    int n = 0;
    int p = 0; // alterar a posicao inicial para se comecar a procura
    int resultado = 0;

    n = freadArraySize("DADOS03.TXT");

    int array[n];

    freadIntArray("DADOS03.TXT", n, array);
    
    printArray(n,array); 

    x =readint("Digite o valor a ser procurado: ");

    if(findnum(x,p,n,array))
    {
        resultado = whereisnum(x,p,n,array);
        print("\n%s%d\n", "O valor procurado pode ser encontrada no arranjo na posicao ", resultado);
    }
    else
    {
        print("\n%s\n", "O valor nao esta` no arranjo ou a posicao inicial de procura e` maior, logo nao e possivel encontra-lo.");
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0819

int howmanynum(int x, int p, int n, int array[])
{
    int contador = 0;

    for(int i = p; i < n; i = i + 1)
    {
        if(array[i] == x)
            contador = contador + 1;
    }

    return (contador);
}
/**
 * Metodo10.
 */
void exercicio0820()
{
    // identificacao
    id("Exercicio 0820:");

    // programa
    int x = 0;
    int n = 0;
    int p = 0; // alterar a posicao inicial para se comecar a procura
    int resultado = 0;

    n = freadArraySize("DADOS03.TXT");

    int array[n];

    freadIntArray("DADOS03.TXT", n, array);
    
    printArray(n,array); 

    x =readint("Digite o valor a ser procurado: ");

    if(findnum(x,p,n,array))
    {
        resultado = howmanynum(x,p,n,array);
        print("\nO valor (%d) aparece %d vez(es) no arranjo\n", x, resultado);
    }
    else
    {
        print("\n%s\n", "O valor nao esta` no arranjo ou a posicao inicial de procura e` maior, logo nao e possivel encontra-lo.");
    }
    
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio0820

/*
    Quantidade de Divisores
*/
int hmdividers( int x )
{
    int count   = 0;
    int divisor = 1;

    if ( x < 0 )
    {
        x = ( -1 ) * x;
    } // end if

    while ( divisor <= x )
    {
        if ( x % divisor == 0 )
        {
            count = count + 1;
        } // end if
        divisor = divisor + 1;
    } // end while

    return ( count );
} // end hmdividers ( )
/*
    Guardar os divisores de um numero em um arranjo
*/
void dividersArray( int x, int array[] )
{
    int divisor = 1;
    int i       = 0;

    while ( divisor <= x )
    {
        if ( x % divisor == 0 )
        {
            array[i] = divisor;
            i++;
        } // end if
        divisor = divisor + 1;
    } // end while

} // end dividersArray();
/**
    fprintIntArray  - Gravar arranjo com valores inteiros.
    @param fileName - nome do arquivo
    @param n        - quantidade de valores
    @param array    - grupo de valores inteiros
 */
void fprintIntArray( string fileName, int n, int array[] )
{
    // definir dados locais
    FILE *arquivo = fopen( fileName, "wt" );
    int x = 0;

    // gravar quantidade de dados
    fprint( arquivo, "%d\n", n );

    // gravar valores no arranjo
    for ( x = 0; x < n; x = x + 1 )
    {
        // gravar valor
        fprint( arquivo, "%d\n", array[x] );
    } // end for

    // fechar arquivo
    fclose( arquivo );
} // end fprintIntArray ( )
/**
 * Metodo11.
 */
void exercicio08E1()
{
    // identificacao
    id( "Exercicio 08E1:" );

    // programa
    int x = 0;
    int n = 0;

    x = readint( "Digite um numero: " ); // Ler o numero

    n = hmdividers( x ); // quantos divisores tem o numero
    
    int array[n]; // declarar um arranjo para essa quantidade

    dividersArray( x, array ); // guardar no arranjo os divisores

    printArray( n, array ); // mostrar na tela o arranjo
    
    fprintIntArray( "DIVISORES.TXT", n, array ); // gravar em um arquivo a quantidade e o arranjo

    print( "\n%s\n", "A quantidade de divisores e os divisores foram gravados no arquivo DIVISORES.TXT." );

    // encerrar
    pause( "Aperte ENTER para continuar!" );
    clear( );
} // fim exercicio08E1

/*
    Ler uma cadeia de caracteres de um arquivo e guardar em um arranjo
*/
void freadString(string filename, int n, char strArray[][STR_SIZE])
{
    FILE *arquivo = fopen( filename, "rt" );
    int i = 0;

    if( arquivo == NULL )
    {
        print("\n%s\n", "ERRO: Nao foi possivel abrir o arquivo.");
    }
    else
    {
        fscan(arquivo,"%d", &n); // ler a quantidade de palavras
        if( n > 100 || n <= 0 )
        {
            print("\n%s\n", "ERRO: Tamanho invalido");
        }
        else
        {   
            for( i = 0; i <= n; i++)
            {
                if( fgets(strArray[i], STR_SIZE, arquivo) == NULL) // ler as palavras
                {
                    i = n;
                } // end if
            } // end for
        } // end if
    } // end if
    
    fclose(arquivo);

} // end freadString ( )

/*
    Mostrar na tela as palavras que n comecam com D ou d
*/
void nothaveD(int n, char strArray[][STR_SIZE])
{
    int count = 0;

    print("\n%s\n", "Palavras que nao comecam com \'d\' ou \'D\':");
    for( int i = 1; i <= n; i++)
    {
        if(strArray[i][0] != 'd' && strArray[i][0] != 'D')
        {
            print("%2d: %s", i, strArray[i]);
            count++;
        }
    }
}
/**
 * Metodo12.
 */
void exercicio08E2()
{
    // identificacao
    id("Exercicio 08E2:");

    // programa
    const int MAX_WORDS = 100;
    char array[MAX_WORDS][STR_SIZE];
    int n = 0;

    n = freadArraySize("PALAVRAS.TXT");

    if( n <= 0 || n > 100 )
    {
        print("\n%s\n", "ERRO: Tamanho Invalido");
    }
    else
    {
        freadString("PALAVRAS.TXT", n, array);

        print("%s\n", "Todas as palavras: ");
        for(int i = 1; i <= n; i = i + 1)
        {
            print("%2d: %s",i, array[i]);
        }
        nothaveD(n, array);
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
    clear();
} // fim exercicio08E2