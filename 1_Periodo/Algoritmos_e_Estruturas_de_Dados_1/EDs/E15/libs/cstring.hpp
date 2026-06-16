#ifndef _CSTRING_HPP_
#define _CSTRING_HPP_

#include <iostream>
using std::cout;
using std::endl;

class String
{
    private:
    unsigned int   size  ; // tamanho efetivo
    int            length; // capacidade
    char*          data  ; // string
    
    public:
    
    String( void )
    {
        size = 0;
        length = 80;
        data = new char[length+1];
    } // default
    /*
    String( unsigned int x )
    {
        size = x;
        length = 80;
        data = new char[length+1];
    } // alternative
    
    ~String()
    {
        size = 0;
        length = 0;
        delete[] data;
    }
    */
    int get_size( )
    {
        return ( this->size );
    } // end get_size ( )
    
    int get_capacity( ) 
    {
        return ( this->length );
    } // end get_capacity ( )
    
    const char* get_str( )
    {
        return ( this->data );
    } // end get_str ( )
    /*
    void str_print( )
    {
        if( !data )
            cout << "\n" << "_" << endl;
        else
            while( *data ) { cout << *data; data = data + 1; }
    } // end str_print ( )

    void str_print( char* s )
    {
        if( !s )
            cout << "\n" << "_" << endl;
        else
            while( *s ) { cout << *s; s = s + 1; }
    } // end str_print ( )
    */
    int str_len( )
    {
        unsigned int x = 0;
        while( *(data+x) ) { x = x + 1; }
        return ( x );
    } // end str_len ( )
    
    int str_len( char* s )
    {
        unsigned int x = 0;
        while( *(s+x) ) { x = x + 1; }
        return ( x );
    } // end str_len ( )
        
    void str_cpy( char* s )
    {
        unsigned int x = 0;
        if( s )
        {
            while( *(s+x) ) { *(data+x) = *(s+x); x = x + 1; }
            *(data+x) = '\0';
        } // end if
    } // end str_cpy ( )
    
    char* str_cpy( char* r, char* s )
    {
        unsigned int x = 0;
        if( s )
        {
            while( *(s+x) ) { *(r+x) = *(s+x); x = x + 1; }
            *(r+x) = '\0';
        } // end if
        return ( r );
    } // end str_cpy ( )
    
    char* str_dup( char* s )
    {
        char* r = nullptr;
        unsigned int x = 0;
        if( s )
        {
            r = new char[str_len(s)+1];
            while( *(s+x) ) { *(r+x) = *(s+x); x = x + 1; }
        }
        return ( r );
    } // end str_dup ( )
    
    void set_str( char* s )
    {
        unsigned int x = 0;
        if( s )
        {
            while( *(s+x) ) { *(data+x) = *(s+x); x = x + 1; }
            *(data+x) = '\0';
            size = str_len( s );
        } // end if
    } // end set_str ( )

    /**  
        Funcao para acrescentar caractere ao final de uma cadeia  
        por meio de apontador. 
    */ 
    void str_push_back( char c )
    {
        unsigned int x = 0;
        char* aux = data;
        if( data && (int)size < length )
        {
            while( *(data+x ) )
            {
                x = x + 1;
            } // end while
            *(data+x) = c;
            size = size + 1;
            *(data+x+1) = '\0';
        } // end if
        data = aux;
    } // end str_push_back ( )
    
    /**  
        Funcao para acrescentar caractere ao final de uma cadeia  
        por meio de apontador. 
    */
    void str_push_back_2(char c)
    {
        if (data && (int)size < length)
        {
            char* end = data + size;
            *end = c;
            size = size + 1;
            *(end + 1) = '\0'; 
        } // end if
    } // end str_push_back_2
    
    /**  
        Funcao para remover caractere do final de uma cadeia  
        por meio de apontador. 
    */
    void str_pop_back( )
    {
        if( data && size > 0 )
        {
            char* last = data + size - 1;
            *last = '\0';
            size = size - 1;
        } // end if
    } // end str_pop_back ( )
    
    /**  
        Funcao para acrescentar caractere ao início de uma cadeia  
        por meio de apontador. 
    */
    void str_push_front( char c )
    {
        unsigned int x = 0;
        if( data && (int)size < length ) 
        {
            for( x = size; x > 0; x = x - 1 )
            {
                *(data+x) = *(data+x-1);
            } // end for
            *(data+x) = c;
            size = size + 1;
            *(data+size) = '\0';
        } // end if
    } // end str_push_front ( )
    
    /**  
        Funcao para remover caractere do início de uma cadeia  
        por meio de apontador. 
    */
    void str_pop_front( )
    {
        unsigned int x = 0;
        if( data && size > 0 )
        {
            *(data+size) = '\0';
            for( x = 0; x < size; x = x + 1 )
            {
                *(data+x) = *(data+x+1); 
            } // end for
            *(data+size-1) = '\0';
            size = size - 1;
            
        } // end if
    } // end str_pop_front ( )
    
    /**  
        Funcao para procurar pela primeira ocorrencia de caractere em cadeia 
        por meio de apontador. 
    */
    char* str_chr( char c )
    {
        unsigned int x = 0;
        if( data )
        {
            while( *(data+x) )
            {
                if( *(data+x) == c )
                {
                    return ( (data+x) );
                } // end if
                x = x + 1;
            } // end while
        } // end if
        return ( nullptr);
    } // end str_chr ( ) 
    
    /**  
        Funcao para separar caracteres ate' a ocorrencia de delimitador em cadeia 
        por meio de apontador. 
    */
    char* str_tok( char delimiter )
    {
        unsigned int x = 0;
        char* tok = nullptr;
        if( data )
        {
            while( *(data+x) && *(data+x) != delimiter ) 
            {
                x = x + 1;
            } // end while
            
            if( *(data+x) == delimiter )
            {
                tok = new char[x+1];
                for( unsigned int y = 0; y < x; y = y + 1 )
                {
                    *(tok+y) = *(data+y);
                } // end for
                *(tok+x) = '\0';
                return ( tok );
            } // end if
        } // end if
        return ( nullptr );
    } // end str_tok ( )

    String( char* text )
    {
        size = str_len( text );
        length = 80;
        data = new char[length+1];
        data = str_cpy( data, text );
    } // alternative
        
}; // end class

#endif