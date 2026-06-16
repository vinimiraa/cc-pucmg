#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_value(void* data, size_t type_size)
{
    if (type_size == sizeof(int)) {
        printf("%d ", *((int*)data));
    } 
    else if (type_size == sizeof(double)) {
        printf("%lf ", *((double*)data));
    } 
    else if (type_size == sizeof(char)) {
        printf("%c ", *((char*)data));
    } 
    else {
        printf("Tipo não suportado\n");
    }
}

void swap(void* value1, void* value2, size_t type_size)
{
    void* temp = malloc(type_size);
    // temp = value1
    memcpy(temp, value1, type_size);
    // value2 = value1
    memcpy(value1, value2, type_size);
    // value2 = temp
    memcpy(value2, temp, type_size);
}

// ======================================================

void** create_matrix(int r, int c, size_t type_size) 
{
    void** new_matrix = (void**)malloc(r * sizeof(void*));
    for(int i = 0; i < r; i++) {
        new_matrix[i] = calloc(c, type_size);
    }

    return new_matrix;
}

void free_matrix(int r, void** matrix) 
{
    if(matrix) 
    {
        for(int i = 0; i < r; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

void print_matrix(int r, int c, void** m, size_t type_size)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            print_value(m[i] + j * type_size, type_size);
        }
        printf("\n");
    }
    printf("\n");
}

// ======================================================

void* create_array(int n, size_t type_size) 
{
    void* new_array = (void*)calloc(n, type_size);
    return new_array;
}

void free_array(int n, void* a) 
{
    if(a) {
        free(a);
    }
}

void print_array(int n, void* a, size_t type_size)
{
    for (int i = 0; i < n; i++) {
        print_value(a + i * type_size, type_size);
    }
    printf("\n");
}

#endif
