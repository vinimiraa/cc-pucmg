/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *
 *  Codigo Base: https://ideone.com/ZFAs0e
 *
 *  compilar: $ gcc tarefa4.c -fopenmp -o mm
 *  executar: $ time ./mm.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void mm(double *a, double *b, double *c, int width)
{
    for (int i = 0; i < width; i++)
    {
        #pragma omp parallel for
        for (int j = 0; j < width; j++)
        {
            double sum = 0;
            for (int k = 0; k < width; k++)
            {
                double x = a[i * width + k];
                double y = b[k * width + j];
                sum += x * y;
            }
            c[i * width + j] = sum;
        }
    }
}

int main()
{
    int width = 2000;
    double *a = (double *)malloc(width * width * sizeof(double));
    double *b = (double *)malloc(width * width * sizeof(double));
    double *c = (double *)malloc(width * width * sizeof(double));

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a[i * width + j] = i;
            b[i * width + j] = j;
            c[i * width + j] = 0;
        }
    }

    mm(a, b, c, width);

    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         printf("\n c[%d][%d] = %f", i, j, c[i * width + j]);
    //     }
    // }
}

// Sequencial
// real    0m25.142s
// user    0m0.045s
// sys     0m0.030s
//
// Paralelo
// real    0m4.222s
// user    0m0.045s
// sys     0m0.000s