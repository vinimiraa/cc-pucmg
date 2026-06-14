/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *  
 *  Codigo Base: https://ideone.com/JU5CfV
 *  
 *  compilar: $ gcc tarefa3.c -fopenmp -lm -o sieve
 *  executar: $ time ./sieve.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <omp.h>

int sieveOfEratosthenes(int n)
{
    int primes = 0;
    bool *prime = (bool *)malloc((n + 1) * sizeof(bool));
    int sqrt_n = sqrt(n);

    memset(prime, true, (n + 1) * sizeof(bool));

    for (int p = 2; p <= sqrt_n; p++)
    {
        if (prime[p] == true)
        {
            #pragma omp parallel for
            for (int i = p * 2; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    #pragma omp parallel for reduction (+ : primes)
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            primes++;
        }
    }

    return (primes);
}

int main()
{
    int n = 100000000;
    printf("%d\n", sieveOfEratosthenes(n));
    return 0;
}

// Teste Sequencial:
// 5761455
// real    0m1.429s
// user    0m0.061s
// sys     0m0.061s

// Teste Paralelo:
// 5761455
// real    0m0.340s
// user    0m0.061s
// sys     0m0.031s