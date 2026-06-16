#include <stdio.h>
#include <stdlib.h>

void array_print( int* array, int size ) 
{
    if( array != NULL )
    {
        for( int i = 0; i < size; i = i + 1 )
        {
            printf( "%d ", array[i] );
        } // for
        printf( "\n" );
    } // if
} // array_print

void array_init( int* array, int size )
{
    if( array != NULL )
    {
        for( int i = 0; i < size; i = i + 1 )
        {
            array[i] = size - i;
        } // for
    } // if
} // array_init

void sort_bubble_orig( int* array, int size )
{
    if( array != NULL )
    {
        for( int i = 0; i < size; i = i + 1 )
        {
            for( int j = 0; j < size - 1; j = j + 1 )
            {
                if( array[j] > array[j + 1] )
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                } // if
            } // for
        } // for
    } // if	
} // sort_bubble_orig

void sort_bubble( int* array, int size )
{
    if( array != NULL)
    {
        int i = 0;
        do
        {
            int j = 0;
            do
            {
                if( array[j] > array[j + 1] )
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                } // if
                j = j + 1;
            } while( j != size - 1 );
            i = i + 1;
        } while( i != size );
    } // if
} // sort_bubble

int main( void )
{
    int size = 100;
    int* a1 = (int*) malloc( size * sizeof( int ) );
    int* a2 = (int*) malloc( size * sizeof( int ) );

    printf( "Array Inicial 1:\n" );
    array_init( a1, size );
    array_print( a1, size );

    printf( "\nArray Inicial 2:\n" );
    array_init( a2, size );
    array_print( a2, size );

    sort_bubble_orig( a1, size );
    sort_bubble( a2, size );

    printf( "\nBubble Sort Original:\n" );
    array_print( a1, size );

    printf( "\nBubble Sort Modificado para Compilador:\n" );
    array_print( a2, size );

    return ( 0 );
} // main