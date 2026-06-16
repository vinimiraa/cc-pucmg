/*
    Exemplo0800 - v0.0. - 12 / 10 / 2023
    Author: Vinicius Miranda de Araujo
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
    printIntArray - Mostrar arranjo com valores inteiros.
    @param n      - quantidade de valores
    @param array  - grupo de valores inteiros
 */
void printIntArray(int n, int array[])
{
    // definir dado local
    int x = 0;

    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // mostrar valor
        IO_printf("%2d: %d\n", x, array[x]);
    } // end for
} // end printIntArray ( )

/**
    Method_01 - Mostrar certa quantidade de valores.
 */
void method_01()
{
    // definir dado
    int array[] = {1, 2, 3, 4, 5};

    // identificar
    IO_id("Method_01 - v0.0");

    // executar o metodo auxiliar
    printIntArray(5, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_01 ( )

/**
    readIntArray  - Ler arranjo com valores inteiros.
    @param n      - quantidade de valores
    @param array  - grupo de valores inteiros
 */
void readIntArray(int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);

    // ler e guardar valores em arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // ler valor
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(
            IO_concat(text, IO_toString_d(x)), " : "));
        // guardar valor
        array[x] = y;
    } // end for
} // end readIntArray ( )

/**
    Method_02.
 */
void method_02()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array[n];

    // identificar
    IO_id("Method_02 - v0.0");

    // ler dados
    readIntArray(n, array);

    // mostrar dados
    IO_printf("\n");
    printIntArray(n, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_02 ( )

/**
    fprintIntArray  - Gravar arranjo com valores inteiros.
    @param fileName - nome do arquivo
    @param n        - quantidade de valores
    @param array    - grupo de valores inteiros
 */
void fprintIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;

    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", n);

    // gravar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%d\n", array[x]);
    } // end for

    // fechar arquivo
    fclose(arquivo);
} // end fprintIntArray ( )

/**
    Method_03.
 */
void method_03()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array[n];

    // identificar
    IO_id("Method_03 - v0.0");

    // ler dados
    readIntArray(n, array);

    // mostrar dados
    IO_printf("\n");
    fprintIntArray("ARRAY1.TXT", n, array);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_03 ( )

/**
    freadArraySize  - Ler tamanho do arranjo com valores inteiros.
    @return quantidade de valores lidos
    @param fileName - nome do arquivo
 */
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // end if

    // retornar dado lido
    return (n);
} // end freadArraySize ( )

/**
    freadIntArray   - Ler arranjo com valores inteiros.
    @param fileName - nome do arquivo
    @param n        - quantidade de valores
    @param array    - grupo de valores inteiros
 */
void freadIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);

    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            // ler valor
            IO_fscanf(arquivo, "%d", &y);
            // guardar valor
            array[x] = y;
            // passar ao proximo
            x = x + 1;
        } // end while
    }     // end if

} // end freadIntArray ( )

/**
    Method_04.
 */
void method_04()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Method_04 - v0.0");

    // ler dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\n");
        printIntArray(n, array);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_04 ( )

/**
    copyIntArray - Copiar arranjo com valores inteiros.
    @param n     - quantidade de valores
    @param copy  - copia do grupo de valores inteiros
    @param array - grupo de valores inteiros
 */
void copyIntArray(int n, int copy[], int array[])
{
    // definir dados locais
    int x = 0;

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    else
    {
        // copiar valores em arranjo
        for (x = 0; x < n; x = x + 1)
        {
            // copiar valor
            copy[x] = array[x];
        } // end for
    }     // end if
} // end copyIntArray ( )

/**
    Method_05.
 */
void method_05()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Method_05 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_05 ( )

/**
    sumIntArray    - Somar valores em arranjo com inteiros.
    @return            - soma dos valores
    @param n        - quantidade de valores
    @param array  - grupo de valores inteiros
 */
int sumIntArray(int n, int array[])
{
    // definir dados locais
    int soma = 0;
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        soma = soma + array[x];
    } // end for
      // retornar resposta
    return (soma);
} // end sumIntArray ( )

/**
    Method_06.
 */
void method_06()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Method_06 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar a soma dos valores no arranjo
        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_06 ( )

/**
    isAllZeros   - Testar valores inteiros em arranjo.
    @return      - true, se todos os dados forem iguais a zero; false, caso contrario
    @param n     - quantidade de valores
    @param array - grupo de valores inteiros
*/
bool isAllZeros(int n, int array[])
{
    // definir dados locais
    bool result = true;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array[x] == 0);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end isAllZeros ( )

/**
    Method_07.
 */
void method_07()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array1[] = {0, 0, 0, 0, 0};
    int array2[] = {1, 2, 3, 4, 5};
    int array3[] = {1, 2, 0, 4, 5};

    // identificar
    IO_id("Method_07 - v0.0");

    // testar dados
    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros (array1) = %d", isAllZeros(n, array1));

    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros (array2) = %d", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros (array3) = %d", isAllZeros(n, array3));

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
    addIntArray   - Somar arranjos com inteiros.
    @return       - arranjo ocm a soma resultante
    @param n      - quantidade de valores
    @param array3 - soma de grupo de valores inteiros
    @param array1 - grupo de valores inteiros (1)
    @param k      - constante para multiplicar o segundo arranjo
    @param array2 - grupo de valores inteiros (2)
 */
void addIntArray(int n, int array3[],
                int array1[], int k, int array2[])
{
    // definir dados locais
    int x = 0;

    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        array3[x] = array1[x] + k * array2[x];
    } // end for
} // end addIntArray ( )

/**
    Method_08.
 */
void method_08()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Method_08 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        int sum[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);

        // operar soma de arranjos
        addIntArray(n, sum, array, (-2), other);

        // mostrar resultados
        IO_printf("\nSoma\n");
        printIntArray(n, sum);
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
    isEqual       - Testar arranjos com inteiros sao iguais.
    @return       - true, se todos os dados forem iguais; false, caso contrario
    @param n      - quantidade de valores
    @param array1 - grupo de valores inteiros (1)
    @param array2 - grupo de valores inteiros (2)
 */
bool isEqual(int n, int array1[], int array2[])
{
    // definir dados locais
    bool result = true;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array1[x] == array2[x]);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end isEqual ( )

/**
    Method_09.
 */
void method_09()
{
    // definir dados
    int n = 0; // quantidade de valores

    // identificar
    IO_id("Method_09 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);

        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));

        // modificar um valor
        other[0] = (-1) * other[0];

        // mostrar dados
        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);

        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_09 ( )

/**
    searchArray  - Procurar valor em arranjo com inteiros.
    @return      - true, se encontrar; false, caso contrario
    @param value - valor a ser procurado
    @param n     - quantidade de valores
    @param array - grupo de valores inteiros
*/
bool searchArray(int value, int n, int array[])
{
    // definir dados locais
    bool result = false;
    int x = 0;

    // mostrar valores no arranjo
    x = 0;
    while (x < n && !result)
    {
        // testar valor
        result = (value == array[x]);
        // passar ao proximo
        x = x + 1;
    } // end while

    // retornar resposta
    return (result);
} // end searchArray ( )

/**
    Method_10.
 */
void method_10()
{
    // definir dados
    int n = 0;     // quantidade de valores
    int value = 0; // valor a ser procurado

    // identificar
    IO_id("Method_10 - v0.0");

    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");

    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);

        // mostrar resultados de procuras
        value = array[0];
        IO_printf("\nProcurar por (%d) = %d\n",
                    value, searchArray(value, n, array));

        value = array[n / 2];
        IO_printf("\nProcurar por (%d) = %d\n",
                    value, searchArray(value, n, array));

        value = array[n - 1];
        IO_printf("\nProcurar por (%d) = %d\n",
                    value, searchArray(value, n, array));

        value = (-1);
        IO_printf("\nProcurar por (%d) = %d\n",
                    value, searchArray(value, n, array));
    } // end if

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_10 ( )

int main()
{
    // definir dado
    int x = 0;
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("Exemplo0800 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Method01");
        IO_println(" 2 - Method02");
        IO_println(" 3 - Method03");
        IO_println(" 4 - Method04");
        IO_println(" 5 - Method05");
        IO_println(" 6 - Method06");
        IO_println(" 7 - Method07");
        IO_println(" 8 - Method08");
        IO_println(" 9 - Method09");
        IO_println("10 - Method10");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            break;
        case 1:
            method_01();
            break;
        case 2:
            method_02();
            break;
        case 3:
            method_03();
            break;
        case 4:
            method_04();
            break;
        case 5:
            method_05();
            break;
        case 6:
            method_06();
            break;
        case 7:
            method_07();
            break;
        case 8:
            method_08();
            break;
        case 9:
            method_09();
            break;
        case 10:
            method_10();
            break;
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10] (",
                                IO_concat(IO_toString_d(x), ")")));
        } // end switch
    } while (x != 0);

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/