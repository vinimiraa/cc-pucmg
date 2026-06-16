#include <stdio.h>
#include <stdlib.h>

void p( int* array, int tam )
{
    if( array != NULL )
    {
        printf( "[ " );
        for( int i = 0; i < tam; i++ )
        {
            printf( "%d ", array[ i ] );
        } // for
        printf( "]\n" );
    } // if
} // p ( )

int f( int* array, int tam )
{
    int soma = 0;
    if( array != NULL )
    {
        for( int i = 0; i < tam; i++ )
        {
            if( i % 2 == 0 ) {
                array[ i ] = 2*i - 1;
            } else {
                array[ i ] = i;
            } // if
            soma += array[ i ];
        } // for
    }
    return ( soma );
} // f ( )

int main( void )
{
    int tam = 10;
    int* array = (int*) malloc( tam * sizeof( int ) );

    printf( "Soma: %d\n", f( array, tam ) );
    p( array, tam );
    
    free( array );

    return ( 0 );
} // main ( )