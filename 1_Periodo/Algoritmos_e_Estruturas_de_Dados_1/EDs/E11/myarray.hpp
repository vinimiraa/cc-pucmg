/*
    myarray.hpp   - v0.0. - 31 / 10 / 2023
    Author: Vinicius Miranda de Araujo
*/

// ----------------------------------------------- definicoes globais

#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler       arquivo
using std::ofstream; // para gravar arquivo

#include <time.h>
template <typename T>
class Array
{
private: // area reservada
    int length;
    T *data;
    T optional;

    void alloc ( int n )
    {
        if( n > 0 )
        {
            length = n;
            data = new T[length];
        }
        else
        {
            length = 0;
        }
    }
    
public: // area aberta

    // construtor padrao
    Array( )
    {
        length = 0;
        data = nullptr; 
        optional = 0;
    } // end constructor

    Array( int n )
    {
        // definir valores iniciais
        length = 0;
        data = nullptr;
        optional = 0;
        alloc ( length );
    } // end constructor

    Array(int n, T initial)
    {
        // definir valores iniciais
        optional = initial;
        length = 0;
        data = nullptr;

        // reservar area
        alloc( n );
    } // end constructor

    void free()
    {
        if (data != nullptr)
        {
            delete (data);
            data = nullptr;
        } // end if
    } // end free ( )

    void setLength( int n )
    {
        if( n > 0 )
        {
            alloc( n );
        }
    } // end setLength ( )

    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        } // end if
    } // end set ( )

    int getLength ( ) 
    { 
        return ( length ); 
    } // end getLength ( ) 

    T get(int position)
    {
        T value = optional;

        if (0 <= position && position < length)
        {
            value = data[position];
        } // end if

        return (value);
    } // end get ( )

    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : " << setw(9) << data[x] << endl;
        } // end for
        cout << endl;
    } // end print ( )

    void read ( ) 
    { 
        cout << endl; 
        for ( int x = 0; x < length; x=x+1 ) 
        { 
            cout << setw( 3 ) << x << " : "; 
            cin   >> data[ x ]; 
       } // end for 
        cout << endl; 
    } // end read ( )

    void fprint ( string fileName ) 
    { 
        ofstream afile;  // output file 
        afile.open ( fileName ); 
        afile << length << endl; 
        for ( int x = 0; x < length; x=x+1 ) 
        { 
            afile << data[ x ] << endl; 
        } // end for 
        afile.close ( ); 
    } // end fprint ( ) 

    void fread ( string fileName ) 
    { 
        ifstream afile; // input file 
        int n = 0; 
        afile.open ( fileName ); 
        afile >> n; 
        if ( n <= 0 ) 
        { 
            cout << "\nERROR: Invalid length.\n" << endl; 
        } 
        else 
        { 
            // guardar a quantidade de dados 
            length  = n; 
            // reservar area 
            data    = new T [ n ]; 
            // ler dados 
            for ( int x = 0; x < length; x=x+1 ) 
            { 
                afile >> data[ x ]; 
            } // end for 
       } // end if 
        afile.close ( ); 
    } // end fread ( )

    void RandomIntGenerate( int a, int b )
    {
        int x = 0;
        int i = 0;
        
        i = 0;
        while ( i < length )
        {
            x = 0;
            while( x < a || b < x )
            {
                x = rand() % 110;
            }
            data[i] = x;
            i = i + 1;
        }
    } // end RandomIntGenerate

    int searchFirstEven( )
    {
        T maior = 0;
        int x = 0;
        
        for( x = 0; x < length; x = x + 1 )
        {
            if( data[x] % 2 == 0 )
            {
                if( data[x] > maior )
                {    
                    maior = data[x];
                }
            }
        }

        return ( maior );
    } // searchFirstEven

    int searchFirstOdd( )
    {
        T menor = optional;
        int contador = 0;
        T* aux = new T[length];
        
        for( int x  = 0, y = 0; x < length; x = x + 1 )
        {
            if( data[x] % 2 != 0 )
            {
                aux[y] = data[x];
                // cout << x << " : " << aux[y] << endl;
                y = y + 1;
                contador = contador + 1;
            }
        }

        menor = aux[0];
        for( int x = 0; x < contador; x = x + 1 )
        {
            if( aux[x] < menor )
            {
                menor = aux[x];
            }
        }

        return ( menor );
        delete(aux);
    } // end searchFirstOdd

    T addInterval( T inicio, T fim )
    {
        T soma = optional;
        int x = 0;
        
        if ( inicio >= 0 && fim < length && inicio <= fim )
        {
            for( x = inicio; x < fim; x = x + 1 )
            {
                soma = soma + data[x];
                // cout << x << " : " << data[x] << endl;
            }
        }
        return ( soma );
    } // end addInterval ( )

    double averageInterval( T inicio, T fim )
    {
        double media = 0.0;
        T quantidade = 0;
        T soma = 0;

        if ( inicio >= 0 && fim <= length && inicio <= fim )
        {
            quantidade = fim - inicio;
            soma  = addInterval( inicio, fim );
            media =  soma / (double)quantidade; 
        }

        return ( media );
    } // end averageInterval ( )

    bool positives( )
    {
        bool resposta = true;
        
        int x = 0;
        while( x < length )
        {
            if(data[x] < 0 )
            {
                resposta = false;
            }
            x = x + 1;
        }

        return ( resposta );
    } // end positives ( )

    bool isCrescent( )
    {
        bool resposta = true;
        int x = 0;

        x = 1;
        while( x < length )
        {
            if( data[x-1] > data[x] )
            {
                resposta = false;
            }
            x = x + 1;
        }

        return ( resposta ); 
    } // end isCrescent ( )

    bool searchInterval( T value, T inicio, T fim )
    {
        bool resposta = false;
        int x = 0;
        
        if ( inicio >= 0 && fim <= length && inicio <= fim )
        {
            x = 0;
            while( x < length && !resposta )
            {
                if( data[x] == value && (inicio <= data[x] && data[x] < fim) )
                {
                    resposta = true;
                }
                else
                {
                    resposta = false;
                }
                x = x + 1;
            }
        }
        return ( resposta );
    } // end searchInterval ( )

    Array scalar( T k, T inicio, T fim)
    {
        Array aux(*this); 
        int x = 0;

        if ( inicio >= 0 && fim <= length && inicio <= fim )
        {
            for ( x = inicio; x < fim; x = x + 1 )
            {
                aux.data[x] = aux.data[x] * k; //
            }
        }

        return ( aux );
    } // end scalar ( )

    void sortUp( )
    {
        int x = 0, y = 0;
        int value = 0;

        for ( x = 1; x < length; x = x+1 )    // (n-1) vezes
        {
            for ( y = 1; y < length; y = y+1 ) // (n-1) testes
            {
                if ( get ( y-1 ) > get ( y ) )
                {
                    value = get ( y );
                    set ( y, get ( y-1 ) );
                    set ( y-1, value );
                } // end if
            } // end for
        } // end for
    }

    // contrutor baseado em copia 
    Array ( int length, int other [ ] ) 
    { 
        if ( length <= 0 ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            // criar copia 
            this->length = length; 
            // reservar area 
            data   = new T [ this->length ]; 
            // ler dados 
            for ( int x = 0; x < this->length; x=x+1 ) 
            { 
                data [ x ] = other [ x ]; 
            } // end for 
       } // end if 
    } // end constructor ( )

    Array ( const Array& other ) 
    { 
        if ( other.length <= 0 ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            // criar copia 
            length = other.length; 
            // reservar area 
            data    = new T [ other.length ]; 
            // ler dados 
            for ( int x = 0; x < length; x=x+1 ) 
            { 
                data [ x ] = other.data [ x ]; 
            } // end for 
       } // end if 
    } // end constructor ( )

    Array& operator= ( const Array <T> other ) 
    { 
        if ( other.length <= 0 ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            this->length = other.length; 
            this->data    = new T [ other.length ]; 
            for ( int x = 0; x < this->length; x=x+1 ) 
            { 
                data [ x ] = other.data [ x ]; 
            } // end for 
        } // end if 
        return ( *this ); 
    } // end operator= ( )

    bool operator== ( const Array <T> other ) 
    { 
        bool result = false; 
        int  x = 0; 
        if ( other.length == 0 || length != other.length ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            x = 0;  
            result = true; 
            while ( x < this->length && result ) 
            { 
                result = result &&  (data [ x ] == other.data [ x ] ); 
                x = x + 1; 
            } // end while 
        } // end if 
        return ( result ); 
    } // end operator== ( )

    bool operator!=(const Array<T> &other)
    {
        bool result = false;
        int x = 0;

        if (length != other.length)
        {
            return true;
        }
        else
        {
            for ( x = 0; x < length; x = x + 1 )
            {
                if (data[x] != other.data[x])
                {
                    return true;
                }
            }
        }

        return ( result );
    } // end operator!= ( )

    Array& operator+ ( const Array <T> other ) 
    { 
        static Array <T> result ( other ); 
        if ( other.length <= 0 ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            for ( int x = 0; x < this->length; x=x+1 ) 
            { 
                result.data [ x ] = result.data [ x ] + this->data [ x ]; 
            } // end for 
        } // end if 
        return ( result ); 
    } // end operator+ ( ) 

    Array& operator- ( const Array <T> other ) 
    { 
        static Array <T> result ( other ); 
        if ( other.length != length ) 
        { 
            cout << "\nERROR: Missing data.\n" << endl; 
        } 
        else 
        { 
            for ( int x = 0; x < this->length; x=x+1 ) 
            { 
                result.data [ x ] = this->data [ x ] - result.data [ x ]; 
            } // end for 
        } // end if 
        return ( result ); 
    } // end operator- ( ) 

    T& operator[]( const int position ) 
    { 
        static T value = optional; 
        if ( position < 0 || length <= position ) 
        { 
            cout << endl << "\nERROR: Invalid position.\n" << endl; 
        } 
        else 
        { 
            value = data [ position ]; 
        } // end if 
        return ( value ); 
    } // end operator [ ]

};

#endif