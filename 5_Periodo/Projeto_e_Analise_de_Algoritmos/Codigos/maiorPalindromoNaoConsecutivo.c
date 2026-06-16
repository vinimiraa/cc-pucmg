#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

char* longestPalindrome(char* string) 
{
    int n = strlen(string);

    char* reversed = (char*)malloc((n+1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        reversed[i] = string[n - 1 - i];
    }
    reversed[n] = '\0';
    
    // A matriz L armazenara o tamanho do maior palindromo encontrado até cada posicao
    int** L = (int**) malloc((n+1) * sizeof(int*));

    // A matriz directions armazenara as direcoes usadas para reconstruir o palindromo
    // 0 = nenhum movimento, 1 = diagonal (match), 2 = cima, 3 = esquerda
    int** directions = (int**) malloc((n+1) * sizeof(int*));
    
    for(int i = 0; i <= n; i++)
    {
        L[i] = (int*) calloc((n+1), sizeof(int));
        directions[i] = (int*) calloc((n+1), sizeof(int));
    }
    
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            // Se os caracteres da string original e reversa forem iguais
            if(string[i - 1] == reversed[j - 1]) 
            {
                L[i][j] = L[i-1][j-1] + 1; // Aumenta o tamanho do palindromo
                directions[i][j] = 1;      // Direcao diagonal (match)
            }
            // Se os caracteres sao diferentes, escolhemos o valor maximo entre cima ou esquerda
            else if (L[i - 1][j] >= L[i][j - 1]) 
            {
                L[i][j] = L[i - 1][j]; // Mantém o maior valor vindo de cima
                directions[i][j] = 2;  // Direcao de cima
            } else 
            {
                L[i][j] = L[i][j - 1]; // Mantém o maior valor vindo da esquerda
                directions[i][j] = 3;  // Direcao da esquerda
            }
        }
    }
    
    int len = L[n][n];

    // reconstruir o palindromo, comecando da ultima celula e indo para tras
    char* palindrome = (char*) calloc((len+1), sizeof(char));
    palindrome[len] = '\0';

    int i = n, j = n;
    int pos = len - 1;
    while (i > 0 && j > 0) 
    {
        if (directions[i][j] == 1)  // Direção diagonal (match)
        {
            palindrome[pos] = string[i - 1]; // Adiciona o caractere correspondente ao palíndromo
            pos--;
            i--;
            j--;
        } else if (directions[i][j] == 2) { // Direção de cima
            i--;
        } else { // Direção da esquerda
            j--;
        }
    }

    return palindrome;
}

// gcc maiorPalindromoNaoConsecutivo.c
int main(int argc, char* argv[])
{
    printf("palindromo = %s\n", longestPalindrome("ACGTGTCAAAATCG"));
    return 0;
}
