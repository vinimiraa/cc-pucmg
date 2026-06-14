/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 *
 *  Codigo Base: https://ideone.com/DSUOsi
 *
 *  compilar: $ gcc tarefa14.c -fopenmp -o quicksort 
 *  executar: $ ./quicksort.exe > seq_output.txt
 *  excutar:  $ time ./quicksort
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low  --> Starting index,
 * high  --> Ending index
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
       at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        #pragma omp task shared(arr)
        quickSort(arr, low, pi - 1);
        
        #pragma omp task shared(arr)
        quickSort(arr, pi + 1, high);

        #pragma omp taskwait
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int i, n = 10000000;
    int *arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        arr[i] = rand() % n;

    omp_set_num_threads(2);

    #pragma omp parallel
    {
        #pragma omp single
        quickSort(arr, 0, n - 1);
    }
    // printf("Sorted array: \n");
    // printArray(arr, n);
    return 0;
}

/*
Tempo Sequencial:
real    0m5.792s
user    0m0.000s
sys     0m0.030s

Tempo Paralelo:
real    0m6.646s
user    0m0.030s
sys     0m0.045s

Speedup = 5.792 / 6.646
Speedup ~ 0.87
Como deu 0,87x, a versão paralela ficou 13% mais lenta que a sequencial.
*/