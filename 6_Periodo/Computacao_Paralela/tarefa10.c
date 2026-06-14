/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *
 *  Codigo Base: https://ideone.com/JU5CfV
 *
 *  compilar: $ gcc tarefa10.c -fopenmp -lm -o sieve
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

// SEQUENCIAL
// 5761455

//  Performance counter stats for './sieve':

//             683.26 msec task-clock:u                     #    0.997 CPUs utilized             
//                  0      context-switches:u               #    0.000 /sec                      
//                  0      cpu-migrations:u                 #    0.000 /sec                      
//              24483      page-faults:u                    #   35.832 K/sec                     
//         2858827297      cycles:u                         #    4.184 GHz                         (85.37%)
//          201676320      stalled-cycles-frontend:u        #    7.05% frontend cycles idle        (85.37%)
//         3563634293      instructions:u                   #    1.25  insn per cycle            
//                                                   #    0.06  stalled cycles per insn     (85.71%)
//          443184680      branches:u                       #  648.630 M/sec                       (85.95%)
//            5973765      branch-misses:u                  #    1.35% of all branches             (85.96%)
//         1363510315      L1-dcache-loads:u                #    1.996 G/sec                       (85.95%)
//          113425033      L1-dcache-load-misses:u          #    8.32% of all L1-dcache accesses   (85.70%)
//    <not supported>      LLC-loads:u                                                           
//    <not supported>      LLC-load-misses:u                                                     

//        0.685365042 seconds time elapsed

//        0.615760000 seconds user
//        0.067973000 seconds sys

// --------------------------

// PARALELO
// 5761455

//  Performance counter stats for './sieve':

//            2686.06 msec task-clock:u                     #    8.606 CPUs utilized             
//                  0      context-switches:u               #    0.000 /sec                      
//                  0      cpu-migrations:u                 #    0.000 /sec                      
//              24518      page-faults:u                    #    9.128 K/sec                     
//        10955708699      cycles:u                         #    4.079 GHz                         (85.30%)
//          595425427      stalled-cycles-frontend:u        #    5.43% frontend cycles idle        (85.31%)
//         3007545548      instructions:u                   #    0.27  insn per cycle            
//                                                   #    0.20  stalled cycles per insn     (85.42%)
//          509603142      branches:u                       #  189.722 M/sec                       (85.36%)
//            6752394      branch-misses:u                  #    1.33% of all branches             (86.44%)
//          830350646      L1-dcache-loads:u                #  309.134 M/sec                       (86.69%)
//          113906152      L1-dcache-load-misses:u          #   13.72% of all L1-dcache accesses   (85.48%)
//    <not supported>      LLC-loads:u                                                           
//    <not supported>      LLC-load-misses:u                                                     

//        0.312118218 seconds time elapsed

//        2.565167000 seconds user
//        0.107713000 seconds sys