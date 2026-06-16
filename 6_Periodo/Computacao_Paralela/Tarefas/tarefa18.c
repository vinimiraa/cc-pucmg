/**
 *  Computacao Paralela
 *  812939 - Vinicius Miranda de Araujo
 * 
 *  compilar: $ gcc -O3 -fopt-info-vec-missed tarefa18.c -o devec
 */


#include <stdio.h>
#include <stdlib.h>

volatile int global = 0;

int foo(int x)
{
    global += x;
    return x * 2;
}

int main()
{
    int n = 1000;

    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));

    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i];

        if (a[i] % 2 == 0)
        {
            b[i] = a[i];
        }

        a[i] += foo(b[i]);
    }

    printf("%d\n", a[10]);

    free(a);
    free(b);

    return 0;
}

// tarefa18.c:16:12: missed: not vectorized: volatile type: global.0_1 ={v} global;
// tarefa18.c:16:12: missed: not vectorized: volatile type: global ={v} _2;
// tarefa18.c:27:23: missed: couldn't vectorize loop
// tarefa18.c:27:23: missed: not vectorized: unsupported control flow in loop.
// tarefa18.c:24:14: missed: statement clobbers memory: a_19 = malloc (4000);
// tarefa18.c:25:14: missed: statement clobbers memory: b_21 = malloc (4000);
// tarefa18.c:16:12: missed: not vectorized: volatile type: global.0_31 ={v} global;
// tarefa18.c:16:12: missed: not vectorized: volatile type: global ={v} _32;
// tarefa18.c:39:5: missed: statement clobbers memory: printf ("%d\n", _13);
// tarefa18.c:41:5: missed: statement clobbers memory: free (a_19);
// tarefa18.c:42:5: missed: statement clobbers memory: free (b_21);