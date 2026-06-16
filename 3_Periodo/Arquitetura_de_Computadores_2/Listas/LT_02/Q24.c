#include <stdio.h>
#include <stdlib.h>

int square( int x )
{
    return ( x * x );
} // square ( )

int create( int* array, int tam )
{
    int soma = 0;
    if( array != NULL )
    {
        if( tam > 30 ) {
            tam = 30;
        }
        for( int i = 0; i < tam; i++ ) 
        {
            if( i % 2 == 0 ) {
                array[ i ] = square( i )*2 + 2*i + 1;
            }
            else {
                array[ i ] = square( i );
            }
            soma += array[ i ];
        }
    }
    return ( soma );
} // create ( )

void p( int* array, int tam )
{
    if( array != NULL )
    {
        printf( "[ " );
        for( int i = 0; i < tam; i++ ) {
            printf( "%d ", array[ i ] );
        }
        printf( "]\n" );
    }   
} // p ( )

int main( void )
{
    int tam = 10;
    int* array = (int*) malloc( tam * sizeof( int ) );

    int soma = create( array, tam );
    printf( "Soma: %d\n", soma );
    p( array, tam );

    return ( 0 );
} // main ( )