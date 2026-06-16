/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *  
 *  Codigo Base: https://ideone.com/JU5CfV
 *  
 *  compilar: $ gcc tarefa20.c -o sieve -O3 -lm -fopenmp  
 *  executar: $ time ./sieve
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

    #pragma omp target data map(tofrom: prime[0:n+1])
    {
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

        #pragma omp parallel for reduction(+:primes)
        for (int p = 2; p <= n; p++)
        {
            if (prime[p])
            {
                primes++;
            }
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
// 0.40s user
// 0.08s system
// 0.489 total

// Teste Multicore:
// 5761455
// 2.51s user 
// 0.10s system 
// 0.312 total

// Teste GPU:
// 5761455 
// 2.59s user 
// 0.10s system 
// 0.315 total