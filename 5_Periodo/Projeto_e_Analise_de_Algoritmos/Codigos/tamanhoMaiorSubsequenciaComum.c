#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs_recursive(char* x, char* y, int i, int j)
{
    if(i == 0 || j == 0)
        return 0;
    
    if(x[i-1] == y[j-1])
        return 1 + lcs_recursive(x, y, i-1, j-1);
    
    return MAX(
        lcs_recursive(x, y, i-1, j),
        lcs_recursive(x, y, i, j-1)
    );
}

// ======================================================

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

int lcs_iterative(int n, int m, char* x, char* y)
{
    int** L = (int**) malloc((n+1) * sizeof(int));
    for(int i = 0; i <= n; i++) {
        L[i] = (int*) calloc((m+1), sizeof(int));
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i-1] == y[j-1]) {
                L[i][j] = 1 + L[i-1][j-1];
            } else {
                L[i][j] = MAX(L[i-1][j], L[i][j-1]);
            }
        }
    }

    // printMatrix(n+1, m+1, L);

    return L[n][m];
}

// ======================================================

int** memo;

void create_memoization(int n, int m)
{
    memo = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) 
    {
        memo[i] = (int*) malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++) {
            memo[i][j] = -1;
        }
    }
}

void free_memoization(int n)
{
    if(memo)
    {
        for (int i = 0; i <= n; i++)
            free(memo[i]);
        free(memo);
    }
}

int lcs_recursive_memoization(char* x, char* y, int i, int j)
{
    if (i == 0 || j == 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (x[i - 1] == y[j - 1])
        memo[i][j] = 1 + lcs_recursive_memoization(x, y, i - 1, j - 1);
    else
        memo[i][j] = MAX(
            lcs_recursive_memoization(x, y, i - 1, j),
            lcs_recursive_memoization(x, y, i, j - 1)
        );

    return memo[i][j];
}

// gcc tamanhoMaiorSubsequenciaComum.c
// ./a.exe ABCD AEBD
// ./a.exe 12231 2322131
// ./a.exe 2322131 12231
int main(int argc, char *argv[])
{
    int ret = 0;
    if(argc < 3)
    {
        printf("Erro: %s <str1> <str2>");
        ret = -1;
    }
    else 
    {
        char* x = argv[1];
        char* y = argv[2];
        int x_len = strlen(x);
        int y_len = strlen(y);
        create_memoization(x_len, y_len);
        printf("lcs_recursive = %d\n", lcs_recursive(x, y, x_len, y_len));
        printf("lcs_iterative = %d\n", lcs_iterative(x_len, y_len, x, y));
        printf("lcs_recursive_memo = %d\n", lcs_recursive_memoization(x, y, x_len, y_len));
        free_memoization(x_len);
    }

    return ret;
}