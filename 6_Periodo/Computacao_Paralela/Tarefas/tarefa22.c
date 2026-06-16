/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *
 *  Codigo Base: https://ideone.com/ZFAs0e
 *
 *  compilar: $ gcc tarefa22.c -fopenmp -o mm -O3
 *  executar: $ time ./mm
 * 
 *  Teste Sequencial:
 *  7.48s user 
 *  0.08s system 
 *  100% cpu 
 *  7.566 total
 * 
 *  Teste Paralelo Multicore:
 *  36.40s user 
 *  0.27s system 
 *  1142% cpu 
 *  3.209 total
 * 
 *  Teste Paralelo GPU:
 *  20.96s user
 *  0.14s system 
 *  1144% cpu 
 *  1.843 total
 * 
 *  Métricas GPU (nvprof):
 *  A execução GPU depende de ambiente com suporte OpenMP offloading. 
 *  No ambiente WSL utilizado, não foram detectados dispositivos OpenMP 
 *  (omp_get_num_devices = 0), portanto a execução GPU não foi medida
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void mm(double *a, double *b, double *c, int width)
{
    // SEQUENCIAL
    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         double sum = 0;
    //         for (int k = 0; k < width; k++)
    //         {
    //             double x = a[i * width + k];
    //             double y = b[k * width + j];
    //             sum += x * y;
    //         }
    //         c[i * width + j] = sum;
    //     }
    // }
    
    // MULTICORE
    // #pragma omp parallel for
    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         double sum = 0;
    //         for (int k = 0; k < width; k++)
    //         {
    //             double x = a[i * width + k];
    //             double y = b[k * width + j];
    //             sum += x * y;
    //         }
    //         c[i * width + j] = sum;
    //     }
    // }

    // GPU
    #pragma omp target data map(to: a[0:width*width], b[0:width*width]) map(from: c[0:width*width])
    {
        #pragma omp target teams distribute parallel for collapse(2)
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                double sum = 0;
                #pragma omp simd reduction(+:sum)
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
