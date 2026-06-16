/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *
 *  Codigo Base: https://ideone.com/DSUOsi
 *
 *  compilar: $ gcc tarefa9.c -fopenmp -o silly_sort
 *  executar: $ time ./silly_sort.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i, j, n = 30000;
    
    // Allocate input, output and position arrays
    int *in = (int *)calloc(n, sizeof(int));
    int *pos = (int *)calloc(n, sizeof(int));
    int *out = (int *)calloc(n, sizeof(int));

    #pragma omp parallel num_threads(2)
    {
        // Initialize input array in the reverse order
        #pragma omp for
        for (i = 0; i < n; i++)
            in[i] = n - i;

        // Print input array
        //   for(i=0; i < n; i++)
        //      printf("%d ",in[i]);

        // Silly sort
        // #pragma omp for private(j)
        // #pragma omp for private(j) schedule(dynamic, 100)
        // #pragma omp for private(j) schedule(guided, 100)
        #pragma omp for private(j) schedule(static)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (in[i] > in[j])
                    pos[i]++;

        // Move elements to final position
        #pragma omp for
        for (i = 0; i < n; i++)
            out[pos[i]] = in[i];

        // print output array
        //   for(i=0; i < n; i++)
        //      printf("%d ",out[i]);

        // Check if answer is correct
        #pragma omp for
        for (i = 0; i < n; i++)
            if (i + 1 != out[i])
            {
                printf("test failed\n");
                exit(0);
            }
    }

    printf("test passed\n");
}

/*

Teste Sequencial:
test passed
real    0m1.021s
user    0m0.045s
sys     0m0.030s

Teste Paralelo (Sem escalonamento):
test passed
real    0m0.677s
user    0m0.015s
sys     0m0.030s

Teste Paralelo (Estático):
test passed
real    0m0.615s
user    0m0.031s
sys     0m0.077s

Teste Paralelo (Dinâmico, 100):
test passed
real    0m0.548s
user    0m0.015s
sys     0m0.031s

Teste Paralelo (Guiado, 100):
test passed
real    0m0.633s
user    0m0.015s
sys     0m0.046s

*/