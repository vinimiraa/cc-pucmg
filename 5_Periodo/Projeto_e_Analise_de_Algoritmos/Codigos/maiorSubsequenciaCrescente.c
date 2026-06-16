#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

/**
 *  Q1 - Lista de Exercicios
 *  LIS - Longest Increasing Subsequence
 */

// Ordenacao Topologica
int lis_topological_sort(int n, int* x)
{
    if(n == 0) return 0;

    // matriz de adjacencia
    int** adj_matrix = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        adj_matrix[i] = (int*) calloc(n, sizeof(int));
    }
    
    // graus de entrada
    int* indegree = (int*) calloc(n, sizeof(int));

    // aresta i -> j se i < j e x[i] < x[j]
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(x[i] < x[j]) 
            {
                adj_matrix[i][j] = 1;
                indegree[j]++;
            }
        }
    }

    // fila
    int* queue = (int*) calloc(n, sizeof(int));
    int head = 0, tail = 0;

    // insere nós com indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) queue[tail++] = i;
    }
    
    // BFS topologica (Kahn's algorithm)
    int layers = 0;
    while(head < tail)
    {
        int size = tail - head; // quantidade de nós na camada
        layers++; 
        for(int s = 0; s < size; s++)
        {
            int u = queue[head++]; // nó atual
            // Para cada vizinho de u
            for(int v = 0; v < n; v++)
            {
                if(adj_matrix[u][v]) 
                {
                    indegree[v]--;
                    if (indegree[v] == 0) queue[tail++] = v;
                }
            }
        }
    }

    return layers;
}

// ======================================================

// Bottom-Up
int lis_iterative_memo(int n, int* x)
{
    if(n == 0) return 0;

    int* dp = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
    }
    
    int best = 1;
    for(int i = 1; i < n; i++) 
    {
        for(int j = 0; j < i; j++) 
        {
            if(x[j] <= x[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > best) best = dp[i];
    }

    return best;
}

int main(int argc, char* argv[])
{
    int x[] = {4, 6, 5, 9, 1};
    int x_len = 5;

    printf("lis_topological_sort = %d\n", lis_topological_sort(x_len, x));
    printf("lis_iterative_memo   = %d\n", lis_iterative_memo(x_len, x));
    return 0;
}
