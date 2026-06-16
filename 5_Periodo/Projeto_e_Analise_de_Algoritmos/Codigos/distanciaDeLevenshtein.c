#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) MIN(MIN(a, b), c)

void printMatrix(int r, int c, int** m)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int levenshteinDistance(char* x, char* y)
{
    printf("ED(%s, %s)\n\n", x, y);

    int x_len = strlen(x);
    int y_len = strlen(y);

    if(x_len == 0 || y_len == 0) return 0;
    
    // Alocação da matriz
    int** distance = (int**) malloc((x_len+1) * sizeof(int*));
    for(int i = 0; i <= x_len; i++) {
        distance[i] = (int*) calloc(y_len+1, sizeof(int));
    }

    // Inicializa primeira linha e coluna
    for (int i = 0; i <= x_len; i++)
        distance[i][0] = i;
    for (int j = 0; j <= y_len; j++)
        distance[0][j] = j;

    printf("Tabela Inicial\n");
    printMatrix(x_len+1, y_len+1, distance);
    
    // Preenche a tabela
    for(int i = 1; i <= x_len; i++)
    {
        for(int j = 1; j <= y_len; j++)
        {
            if(x[i-1] == y[j-1]) {
                distance[i][j] = distance[i-1][j-1]; // nenhum custo
            } else {
                distance[i][j] = MIN3(
                    distance[i-1][j] + 1, 
                    distance[i][j-1] + 1, 
                    distance[i-1][j-1] + 1
                );
            }
        }
    }
    
    printf("Tabela Final\n");
    printMatrix(x_len+1, y_len+1, distance);

    return distance[x_len][y_len];
}

// Para Vizualizacao: https://phiresky.github.io/levenshtein-demo/
// gcc distanciaDeLevenshtein.c
int main(void)
{
    char strlist[4][10];
    strcpy(strlist[0], "abc");
    strcpy(strlist[1], "cbd");
    strcpy(strlist[2], "kitten");
    strcpy(strlist[3], "sitting");

    printf("R: %d\n", levenshteinDistance(strlist[0], strlist[1]));
    printf("-------------------\n");
    printf("R: %d\n", levenshteinDistance(strlist[2], strlist[3]));
    return 0;
}