/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios09 - v0.0. - 18 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios09 Exercicios09.c
 *      Windows: gcc -o Exercicios09 Exercicios09.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios09
 *      Windows: Exercicios09
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

const int MAX_SIZE = 10;

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio0911();
void exercicio0912();
void exercicio0913();
void exercicio0914();
void exercicio0915();
void exercicio0916();
void exercicio0917();
void exercicio0918();
void exercicio0919();
void exercicio0920();
void exercicio09E1();
void exercicio09E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios09 - v0.0");

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
            exercicio0911();
            break;
        case 2:
            exercicio0912();
            break;
        case 3:
            exercicio0913();
            break;
        case 4:
            exercicio0914();
            break;
        case 5:
            exercicio0915();
            break;
        case 6:
            exercicio0916();
            break;
        case 7:
            exercicio0917();
            break;
        case 8:
            exercicio0918();
            break;
        case 9:
            exercicio0919();
            break;
        case 10:
            exercicio0920();
            break;
        case 11:
            exercicio09E1();
            break;
        case 12:
            exercicio09E2();
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
    printf("%s\n", "  1 - Exercicio 0911");
    printf("%s\n", "  2 - Exercicio 0912");
    printf("%s\n", "  3 - Exercicio 0913");
    printf("%s\n", "  4 - Exercicio 0914");
    printf("%s\n", "  5 - Exercicio 0915");
    printf("%s\n", "  6 - Exercicio 0916");
    printf("%s\n", "  7 - Exercicio 0917");
    printf("%s\n", "  8 - Exercicio 0918");
    printf("%s\n", "  9 - Exercicio 0919");
    printf("%s\n", " 10 - Exercicio 0920");
    printf("%s\n", " 11 - Exercicio 09E1");
    printf("%s\n", " 12 - Exercicio 09E2");
    printf("\n");
} // fim menuOpcoes()

void readDoubleMatrix( int row,int col, double matrix[][MAX_SIZE] )
{
    int x = 0;
    int y = 0;
    double z = 0;
    string text = allocchar(STR_SIZE);

    for (x = 0; x < row; x = x + 1)
    {
        for (y = 0; y < col; y = y + 1)
        {
            strcpy(text, STR_EMPTY);
            do
            {
            z = readdouble(concat(
                concat(concat(text, inttostr(x)), ", "),
                concat(concat(text, inttostr(y)), " : ")));
            }while( z < 0 );
            matrix[x][y] = z;
        }
        print("\n");
    }
} // end readDoubleMatrix ( )
void printDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;

    for (x = 0; x < row; x = x + 1)
    {
        for (y = 0; y < col; y = y + 1)
        {
            print("%.2lf\t", matrix[x][y]);
        }
        printf("\n");
    }
} // end printDoubleMatrix ( )
/**
 * Metodo01.
 */
void exercicio0911()
{
    // identificacao
    id("Exercicio 0911:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];
    int L = 0;
    int C = 0;

    L = readint("Digite o numero de linhas : ");
    C = readint("Digite o numero de colunas: ");
    print("\n");
    
    if ( L > MAX_SIZE || C > MAX_SIZE ||
            L <= 0    ||     C <= 0     )
        print( "\n%s\n" , "ERRO: Tamanho invalido.");
    else
    {

        print( "%s\n", "Digite os valores da matriz: ");
        readDoubleMatrix(L,C,matriz);
        print( "%s\n", "Matriz: ");
        printDoubleMatrix(L,C,matriz);
    }
    
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0911

void fprintDoubleMatrix(string fileName, int row, int col, double matrix[][MAX_SIZE])
{
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0;
    int y = 0;
    double z = 0;

    fprint(arquivo, "%d\n", row);
    fprint(arquivo, "%d\n", col);

    for (x = 0; x < row; x = x + 1)
    {
        for (y = 0; y < col; y = y + 1)
        {
            z = matrix[x][y];
            fprint(arquivo, "%lf\n", z);
        }
    }

    fclose(arquivo);
} // end fprintDoubleMatrix ( )
void freadDoubleMatrix(string fileName, int row, int col, double matrix[][MAX_SIZE])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    double z = 0;
    FILE *arquivo = fopen(fileName, "rt");

    fscan(arquivo, "%d", &x);
    fscan(arquivo, "%d", &y);

    if (row <= 0 || row > x || col <= 0 || col > y)
    {
        print("\n%s\n","ERRO: Tamanho invalido.");
    }
    else
    {
        x = 0; // valor inicial
        while (!feof(arquivo) && x < row) // condicao
        {
            y = 0; // valor inicial
            while ( !feof(arquivo) && y < col ) // condicao
            {
                fscan(arquivo, "%lf", &z);
                matrix[x][y] = z;
                y = y + 1; // variacao 
            }
            x = x + 1; // variacao
        }
    }

    fclose(arquivo);
} // end freadDoubleMatrix ( )
/**
 * Metodo02.
 */
void exercicio0912()
{
    // identificacao
    id("Exercicio 0912:");

    // programa
    double matriz_1[MAX_SIZE][MAX_SIZE];
    double matriz_2[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz_1);

    // gravar no arquivo a matriz_1
    fprintDoubleMatrix("MATRIZ_01.TXT", L, C, matriz_1);
    print("%s\n", "Matriz gravada no arquivo \"MATRIZ_01.TXT\" com sucesso.");

    // ler a matriz_1 do arquivo para a matriz_2
    freadDoubleMatrix("MATRIZ_01.TXT", L, C, matriz_2);

    // mostrar matriz_2
    print("\n%s\n", "Matriz: ");
    printDoubleMatrix( L, C, matriz_2);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0912

void printDiagonalDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for(y = 0; y < col; y = y + 1)
            {
                if(x == y)
                {
                    z = matrix[x][x];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        }
    }
}
/**
 * Metodo03.
 */
void exercicio0913()
{
    // identificacao
    id("Exercicio 0913:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos da Diagonal Principal da matriz: ");
    printDiagonalDoubleMatrix(L, C, matriz);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0913

void printSDiagonalDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for(y = 0; y < col; y = y + 1)
            {
                if( y == row-1-x)
                {
                    z = matrix[x][row - 1 - x];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        } 
    }
}
/**
 * Metodo04.
 */
void exercicio0914()
{
    // identificacao
    id("Exercicio 0914:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos da Diagonal Secundaria da matriz: ");
    printSDiagonalDoubleMatrix(L, C, matriz);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0914

void printLDTriangleDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for (y = 0; y < col; y = y + 1)
            {
                if (x > y || x == y)
                {
                    z = matrix[x][y];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        }
    }
}
/**
 * Metodo05.
 */
void exercicio0915()
{
    // identificacao
    id("Exercicio 0915:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos Abaixo e na Diagonal Principal da matriz: ");
    printLDTriangleDoubleMatrix(L, C, matriz);
    
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0915

void printLUTriangleDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for (y = 0; y < col; y = y + 1)
            {
                if (x < y || x == y)
                {
                    z = matrix[x][y];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        }
    }
}
/**
 * Metodo06.
 */
void exercicio0916()
{
    // identificacao
    id("Exercicio 0916:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos Acima e na Diagonal Principal da matriz: ");
    printLUTriangleDoubleMatrix(L, C, matriz);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0916

void printSLDTriangleDoubleMatrix(int row, int col, double matrix[][col])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for (y = 0; y < col; y = y + 1)
            {
                if (y >= row - x || y == row-1-x)
                {
                    z = matrix[x][y];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        }
    }
}
/**
 * Metodo07.
 */
void exercicio0917()
{
    // identificacao
    id("Exercicio 0917:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos Abaixo e na Diagonal Secundaria da matriz: ");
    printSLDTriangleDoubleMatrix(L, C, matriz);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0917

void printSLUTriangleDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    double z = 0;
    
    if( row != col )
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
    else
    {
        for (x = 0; x < row; x = x + 1)
        {
            for (y = 0; y < col; y = y + 1)
            {
                if (x+y < row-1 || y == row-1-x)
                {
                    z = matrix[x][y];
                    print("%.2lf\t", z);
                }
                else
                    print("\t");
            }
            print("\n");
        }
    }
}
/**
 * Metodo08.
 */
void exercicio0918()
{
    // identificacao
    id("Exercicio 0918:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    print("\n%s\n", "Elementos Acima e na Diagonal Secundaria da matriz: ");
    printSLUTriangleDoubleMatrix(L, C, matriz);

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0918

bool allZerosLDTriangleDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    bool resultado = true;
    
    if( row != col )
    {
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
        resultado = false;
    }
    else
    {
        x = 0;
        while (x < row && resultado)
        {
            y = 0;
            while (y < col && resultado)
            {
                if(x > y)
                {
                    if( matrix[x][y] != 0 )
                        resultado = false;
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }

    return (resultado);
}
/**
 * Metodo09.
 */
void exercicio0919()
{
    // identificacao
    id("Exercicio 0919:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    printDoubleMatrix(L,C,matriz);

    if( allZerosLDTriangleDoubleMatrix(L,C,matriz) )
        print("\n%s\n", "Os valores abaixo da diagonal principal sao todos zeros: ");
    else
        print("\n%s\n", "Os valores abaixo da diagonal principal nao sao todos zeros: ");

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0919

bool allZerosLUTriangleDoubleMatrix(int row, int col, double matrix[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    bool resultado = true;
    
    if( row != col )
    {
        print("\n%s\n", "ERRO: Matriz nao e quadrada.");
        resultado = false;
    }
    else
    {
        x = 0;
        while (x < row && resultado)
        {
            y = 0;
            while (y < col && resultado)
            {
                if(x < y)
                {
                    if( matrix[x][y] != 0 )
                        resultado = false;
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }

    return (resultado);
}
/**
 * Metodo10.
 */
void exercicio0920()
{
    // identificacao
    id("Exercicio 0920:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];

    int L = 3;
    int C = 3;

    print("%s\n", "Digite os valores da matriz: ");
    readDoubleMatrix(L, C, matriz);

    printDoubleMatrix(L,C,matriz);

    if( allZerosLUTriangleDoubleMatrix(L,C,matriz) )
        print("\n%s\n", "Os valores acima da diagonal principal sao todos zeros: ");
    else
        print("\n%s\n", "Os valores acima da diagonal principal nao sao todos zeros: ");

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio0920

void transposeDoubleMatrix(int row, int col,
                        double matrix[][MAX_SIZE], double transposed[][MAX_SIZE])
{
    int x = 0;
    int y = 0;

    for (x = 0; x < row; x = x + 1)
    {
        for (y = 0; y < col; y = y + 1)
        {
            transposed[y][x] = matrix[x][y];
        }
    }
} // end transposeDoubleMatrix ( )
/**
 * Metodo11.
 */
void exercicio09E1()
{
    // identificacao
    id("Exercicio 09E1:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];
    double transposta[MAX_SIZE][MAX_SIZE];
    int L = 0;
    int C = 0;

    L = readint( "Digite a quantidade de linhas : " );
    C = readint( "Digite a quantidade de colunas: " );

    if( L > MAX_SIZE || L <= 0 || C > MAX_SIZE || C <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho invalido." );
    }
    else
    {
        print("\n%s\n", "Digite os valores da matriz: ");
        readDoubleMatrix(L, C, matriz);

        transposeDoubleMatrix(L, C, matriz, transposta);

        print( "\n%s\n" , "Matriz: ");
        printDoubleMatrix(L, C, matriz);

        print( "\n%s\n" , "Matriz Transposta: ");
        printDoubleMatrix(C, L, transposta);

        fprintDoubleMatrix("TRANSPOSTA_E1.TXT", C, L, transposta);
        print( "\n%s\n", "Matriz gravada no arquivo \"TRANSPOSTA_E1.TXT\"." );
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio09E1

void invertedDoubleMatrix( int row, int col, 
                        double matrix[][MAX_SIZE], double inverted[][MAX_SIZE])
{
    int x = 0;
    int y = 0;
    
    for (x = 0; x < row; x = x + 1)
    {
        for (y = 0; y < col; y = y + 1) 
        {
            inverted[y][x] = matrix[row - 1 - x][col - 1 - y];
        }
    }
    /*NAO FUNCIONA*/
    // int l = 0; 
    // int c = 0;

    // for( x = row-1, l = 0; x >= 0; x = x - 1, l++ )
    // {
    //     for( y = col-1, c = 0; y >= 0; y = y - 1, c++ )
    //     {
    //         inverted[l][c] = matrix[y][x];
    //     }
    // }
}
/**
 * Metodo12.
 */
void exercicio09E2()
{
    // identificacao
    id("Exercicio 09E2:");

    // programa
    double matriz[MAX_SIZE][MAX_SIZE];
    double invertida[MAX_SIZE][MAX_SIZE];
    int L = 0;
    int C = 0;

    L =  readint( "Digite a quantidade de linhas : " );
    C =  readint( "Digite a quantidade de colunas: " );

    if( L > MAX_SIZE || L <= 0 || C > MAX_SIZE || C <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho invalido." );
    }
    else
    {
        print("\n%s\n", "Digite os valores da matriz: ");
        readDoubleMatrix(L, C, matriz);

        invertedDoubleMatrix(L, C, matriz, invertida);

        print( "\n%s\n" , "Matriz: ");
        printDoubleMatrix(L, C, matriz);

        print( "\n%s\n" , "Matriz Invertida: ");
        printDoubleMatrix(C, L, invertida);

        fprintDoubleMatrix("INVERTIDA_E2.TXT", L, C, invertida);
        print( "\n%s\n", "Matriz gravada no arquivo \"INVERTIDA_E2.TXT\"." );
    }
    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio09E2