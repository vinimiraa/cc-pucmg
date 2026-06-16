#ifndef _INTARRAY_HPP_
#define _INTARRAY_HPP_

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

typedef struct s_intArray { int length; int *data; } intArray; 

typedef intArray* ref_intArray;

bool exist_intArray( intArray* array )
{
    bool result = false;
    if( array != nullptr &&  array->data != nullptr )
    {
        result = true;
    }
    return ( result );
} // end exist_intArray ( )

intArray* new_intArray( int size )
{
    intArray* array = new intArray;
    if( array )
    {
        array->length = 0;
        array->data = nullptr;
        if( size > 0 )
        {
            array->length = size;
            array->data = new int[size];
            if( array->data != nullptr )
            {
                for( int x = 0; x < array->length; x = x + 1 )
                {
                    *(array->data+x) = 0;
                } // end for
            } // end if
        } // end if
    } // end if
    return ( array );
} // end new_intArray ( )

void delete_intArray( intArray* array )
{
    if( array != nullptr )
    {
        if ( array->data != nullptr )
        {    
            delete[] array->data;
        }
        delete array;
    } // end if
} // end delete_intArray ( )

void print_intArray( intArray* array )
{
    unsigned int x = 0;
    if( exist_intArray( array ) )
    {
        cout << endl;
        for( x = 0; (int)x < array->length; x = x + 1 )
        {
            cout << x << ": " << *(array->data+x) << endl;
        } // end for
    } // end if
} // end print_intArray ( )

intArray* read_intArray( )
{
    intArray* array = nullptr;
    int size = 0;
    
    do
    {
        cout << "Tamanho do arranjo: ";
        cin >> size;
    }while( size <= 0 );
    
    array = new_intArray( size );
    
    if( array != nullptr )
    {
        if( array->data == nullptr )
        {
            size = 0;
        }
        else
        {
            for( int x = 0; x < array->length; x = x + 1 )
            {
                cout << "[" << x  << "]" << " = ";
                cin >> *(array->data+x);
            } // end for
        } // end if
    } // end if
    
    return ( array );
    
} // end read_intArray ( )
    

/**  
    Funcao para comparar arranjos de inteiros 
    por meio de apontadores. 
    @return zero, se forem iguais; 
            negativo, se o valor da diferenca for menor e estiver no primeiro arranjo 
            positivo, se o valor da diferenca for maior e estiver no primeiro arranjo 
    @param p - apontador para inicio do primeiro  arranjo 
    @param q - apontador para inicio do segundo arranjo 
*/ 
int intArray_cmp ( ref_intArray p, ref_intArray q )
{
    unsigned int x = 0;
    int diff = 0;

    if( p && q )
    {
        if( p->length == q->length )
        {
            for ( x = 0; (int)x < p->length; x = x + 1 )
            {
                diff = *(p->data + x) - *(q->data + x);
                if (diff != 0)
                {
                    return ( diff );
                } // end if
            } // end for
            return ( 0 );
        } // end if    
    } // end if

    return ( -69 );

} // end intArray_cmp ( )
/* VSCODE NÃO MOSTRA 0 QUANDO p E q SAO IGUAIS ???????
int intArray_cmp_2 ( ref_intArray p, ref_intArray q )
{
    unsigned int x = 0;
    int z = -69;
    if( p && q )
    {
        if( p->length == q->length )
        {
            while( *(p->data+x) && *(q->data+x) && !( *(p->data+x) - *(q->data+x) != 0 ) )
            {
                x = x + 1;
            } // end while
            if( *(p->data+x) - *(q->data+x) != 0 )
                { z = *(p->data+x) - *(q->data+x); }
            else
                { z = 0; }
        } // end if    
    } // end if
    return ( z );
} // end intArray_cmp_2 ( )
*/
/**  
    Funcao para juntar arranjos de inteiros 
    por meio de apontadores. 
    @return apontador para inicio do arranjo com a uniao 
    @param p - apontador para inicio do primeiro  arranjo 
    @param q - apontador para inicio do segundo arranjo 
*/ 
ref_intArray intArray_cat ( ref_intArray p, ref_intArray q )
{
    intArray* result = nullptr;
    unsigned int x = 0;
    unsigned int y = 0;

    if( exist_intArray( p ) && exist_intArray( q ) )
    {
        if( p->length > 0 && q->length > 0 )
        {
            result = new_intArray( p->length + q->length );

            if( exist_intArray( result ) )
            {
                while( *(p->data+x) ) 
                {
                    *(result->data+x) = *(p->data+x); 
                    x = x + 1;
                } // end while

                while( *(q->data+y) ) 
                { 
                    *(result->data+x) = *(q->data+y); 
                    x = x + 1; 
                    y = y + 1; 
                } // end while

                x = 0;
                y = 0;
            } // end if
        } // end if
    } // end if

    return ( result );

} // end intArray_cat ( )

/**  
    Funcao para procurar pela primeira ocorrencia de valor em arranjo 
    por meio de apontador. 
    @return apontador para a primeira ocorrência; NULL, caso contrario 
    @param a - apontador para arranjo de inteiros 
    @param x - valor ser procurado 
*/ 
ref_intArray intArray_seek ( ref_intArray a, int value )
{
    unsigned int x = 0;
    intArray* result = 0;

    if( exist_intArray( a ) )
    {
        while ( *(a->data+x) )
        {
            if( *(a->data+x) == value )
            {
                result = new_intArray( a->length - x );

                for ( int i = x, b = 0; i < a->length; i = i + 1, b = b + 1 )
                {
                    *(result->data+b) = *(a->data+i);
                }

                return (  result );
            } // end if
            x = x + 1;
        } // end while
    } // end if

    return ( nullptr );

} // end intArray_seek ( )

/**  
    Funcao para separar sequencia de valores em arranjo 
    por meio de apontador. 
    @return apontador para inicio da sequencia de inteiros; NULL, caso contrario 
    @param a     - apontador para arranjo de inteiros 
    @param start - posicao inicial 
    @param size  - quantidade de dados 
*/ 
ref_intArray intArray_sub ( ref_intArray a, int start, int size )
{
    unsigned int x = 0;
    int y = 0;
    intArray* result = nullptr;
    
    if( exist_intArray( a ) )
    {
        result = new_intArray( size - start );

        if( exist_intArray( result ) )
        {
            for( x = start, y = 0; y <= result->length; x = x + 1, y = y + 1 )
            {
                *(result->data+y) = *(a->data+x);
            } // end for
        } // end if
    } // end if

    return ( result );

} // end intArray_sub ( )

/**  
    Funcao para intercalar arranjos de inteiros 
    por meio de apontadores. 
    @return apontador para inicio do arranjo com a uniao 
    @param p - apontador para inicio do primeiro  arranjo 
    @param q - apontador para inicio do segundo arranjo 
*/ 
ref_intArray intArray_merge ( ref_intArray p, ref_intArray q )
{
    unsigned int x = 0;
    unsigned int y = 1;
    intArray* result = nullptr;

    if( exist_intArray( p ) && exist_intArray( q ) )
    {
        result = new_intArray( p->length + q->length );

        if( exist_intArray( result ) )
        {
            while( *(p->data+x) && *(q->data+x) )
            {
                *(result->data+y-1) = *(p->data+x);
                *(result->data+y)   = *(q->data+x);
                x = x + 1;
                y = y + 2;
            } // end while

            while( *(p->data+x) )
            {
                *(result->data+y-1) = *(p->data+x);
                x = x + 1;
                y = y + 1;
            } // end while

            while( *(q->data+x) )
            {
                *(result->data+y-1) = *(q->data+x);
                x = x + 1;
                y = y + 1;
            } // end while
        } // end if
    } // end if

    return ( result );

} // end intArray_merge ( )

/**  
    Funcao para intercalar arranjos de inteiros em ordem crescente 
    por meio de apontadores. 
    @return apontador para inicio do arranjo com a uniao 
    @param p - apontador para inicio do primeiro  arranjo 
    @param q - apontador para inicio do segundo arranjo 
*/ 
ref_intArray intArray_mergeUp ( ref_intArray p, ref_intArray q )
{
    unsigned int x = 0;
    unsigned int y = 1;
    intArray* result = nullptr;

    if( exist_intArray( p ) && exist_intArray( q ) )
    {
        result = new_intArray( p->length + q->length );

        if( exist_intArray( result ) )
        {
            while( *(p->data+x) && *(q->data+x) )
            {
                if( *(p->data+x) < *(q->data+x) )
                {
                    *(result->data+y-1) = *(p->data+x);
                    *(result->data+y)   = *(q->data+x);
                }
                else
                {
                    *(result->data+y-1) = *(q->data+x);
                    *(result->data+y)   = *(p->data+x);
                }
                x = x + 1;
                y = y + 2;
            } // end while

            while( *(p->data+x) )
            {
                *(result->data+y-1) = *(p->data+x);
                x = x + 1;
                y = y + 1;
            } // end while

            while( *(q->data+x) )
            {
                *(result->data+y-1) = *(q->data+x);
                x = x + 1;
                y = y + 1;
            } // end while
        } // end if
    } // end if

    return ( result );

} // end intArray_mergeUp ( )

#endif