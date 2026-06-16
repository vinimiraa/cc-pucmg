/*
    Contato.hpp - v0.0. - 22 / 11 / 2023
    Author: Vinícius Miranda de Araújo
*/

#ifndef _MYSTRING_HPP_
#define _MYSTRING_HPP_

// dependencias
#include "libshow.hpp"  // Minha Biblioteca
#include "Erro.hpp"     // Classe de Tratamento de Erro

using std::cin;         // para entrada
using std::cout;        // para saida
using std::endl;        // para mudar de linha
using std::setw;        // para definir espacamento
using std::string;      // para cadeia de caracteres
using std::ifstream;    // para ler arquivo
using std::ofstream;    // para gravar arquivo


class MyString : public Erro
{
private:

    string s;

public:

    /**
     *  Construtor Padrão
    */
    MyString ( void )
    {
        this->s = "0";
    } // end construtor ( padrão )

    /**
     *  Construtor Alternativo
    */
    MyString ( std::string text )
    {
        this->s = text;
    } // end construtor ( alternativo )

    /**
     *  Método para atribuir conteúdo a String
    */
    void setString( std::string s )
    {
        this->s = s;
    } // end setString ( );

    /**
     *  Método para pegar conteúdo da String
    */
    std::string getString( )
    {
        return ( this->s );
    } // end getString ( )

    /**
     *  Método para converter String para Inteiro.
     *  @return Numero Inteiro.
    */
    int getInt( )
    {
        int  num      = 0;     // resposta;
        int  casas    = 1;     // quantidade de numeros;
        int  ponto    = -1;    // posicao da string em que o ponto esta;
        bool temPonto = false; // TRUE: tem ponto, logo real; FALSE: nao tem ponto, logo inteiro;
        bool sinal    = true;  // TRUE: positivo; FALSE: negativo;
        bool temSinal = false; // TRUE: tem sinal; FALSE: nao tem sinal;

        if ( s.empty( ) )
        {
            setErro( 1 );
            return ( -1 );
        }
        else
        {
            // testar se a string tem sinal ou ponto
            for (int x = 0; x < (int)s.size(); x = x + 1)
            {
                if ( s[0] == '-' || s[0] == '+' )
                {
                    temSinal = true;
                    if ( s[0] == '-' )
                    {
                        sinal = false;
                    }
                    else if ( s[0] == '+' )
                    {
                        sinal = true;
                    }
                }
                if ( s[x] == '.' ) 
                {
                    temPonto = true;
                    ponto = x;
                }
                else if( isAlpha( s[x] ) )
                {
                    setErro( 1 );
                    return ( -1 );
                }
            } // end for

            // converter para inteiro
            if ( temPonto && temSinal )
            {
                for ( int x = ponto - 1; x >= 1; x = x - 1 )
                {
                    num = num + ( ( s[x] - 48 ) * casas );
                    casas = casas * 10;
                } // end for
            } 
            else if ( temPonto )
            {
                for ( int x = ponto - 1; x >= 0; x = x - 1 )
                {
                    num = num + ( ( s[x] - 48 ) * casas );
                    casas = casas * 10;
                } // end for
            }
            else if ( temSinal )
            {
                for ( int x = s.size() - 1; x >= 1; x = x - 1 )
                {
                    num = num + ( ( s[x] - 48 ) * casas );
                    casas = casas * 10;
                } // end for
            }
            else
            {
                for ( int x = s.size() - 1; x >= 0; x = x - 1 )
                {
                    num = num + ( ( s[x] - 48 ) * casas );
                    casas = casas * 10;
                } // end for
            }
        } // end if

        if ( sinal )
            return ( num );
        else
            return ( num * (-1) );

    } // end getInt ( )

    /**
     *  Metodo para converter String para Real.
     *  @return Numero Real.
    */
    double getDouble( )
    {
        double  num      = 0.0;   // resposta
        double  decimal  = 0.0;   // parte decimal do numero
        double  inteira  = 0.0;   // parte inteira do numero
        double  casas    = 1.0;   // quantidade de numeros;
        int     ponto    = -1;    // posicao da string em que o ponto esta;
        bool    temPonto = false; // TRUE: tem ponto, logo real; FALSE: nao tem ponto, logo inteiro;
        bool    sinal    = true;  // TRUE: positivo; FALSE: negativo;
        bool    temSinal = false; // TRUE: tem sinal; FALSE: nao tem sinal;

        if ( s.empty( ) )
        {
            setErro( 2 );
            return ( 0.0 );
        }
        else
        {
            // testar se a string tem sinal ou ponto
            for (int x = 0; x < (int)s.size(); x = x + 1)
            {
                if ( s[0] == '-' || s[0] == '+' )
                {
                    temSinal = true;
                    if ( s[0] == '-' )
                    {
                        sinal = false;
                    }
                    else if ( s[0] == '+' )
                    {
                        sinal = true;
                    }
                }
                if ( s[x] == '.' ) 
                {
                    temPonto = true;
                    ponto = x;
                }
                else if( isAlpha( s[x] ) )
                {
                    setErro( 2 );
                    return ( 0.0 );
                }
            } // end for

            // somar a parte decimal
            if( temPonto )
            {
                casas = 10.0;
                for( int x = ponto + 1; x < (int)s.size( ); x = x + 1 )
                {
                    decimal = decimal + ( s[x] - 48 ) / casas;
                    casas = casas * 10.0;
                } // end for
            } 
            else
            {
                ponto = s.size( );
            } // end if
            
            casas = 1.0;
            // somar a parte inteira
            if( temSinal )
            {
                for( int x = ponto-1; x >= 1; x = x - 1 )
                {
                    inteira = inteira + ( s[x] - 48 ) * casas;
                    casas = casas * 10.0;
                } // end for
            } 
            else
            {
                for( int x = ponto-1; x >= 0; x = x - 1 )
                {
                    inteira = inteira + ( s[x] - 48 ) * casas;
                    casas = casas * 10.0;
                } // end for
            } // end if

            num = inteira + decimal;
        } // end if

        if ( sinal )
            return ( num * (1.0) );
        else
            return ( num * (-1.0) );
        
    } // end getDouble ( )

    /**
     *  Método para converter String para maiusculo.
     *  @return String maiuscula.
    */
    std::string toUpperCase( std::string str )
    {
        for( int x = 0; x < (int)str.size( ); x = x + 1 )
        {
            str[x]= toUpper( str[x] );
        }
        return ( str );
    } // end toUpperCase ( )

    /**
     *  Método para converter String para minusculo.
     *  @return String minuscula.
    */
    std::string toLowerCase( std::string str )
    {
        for( int x = 0; x < (int)str.size( ); x = x + 1 )
        {
                str[x] = toLower( str[x] );
        }
        return ( str );
    } // end toLowerCase ( )

    /**
     *  Método para converter String para Boolean.
     *  @return True ou False.
    */
    bool getBoolean( )
    {
        bool result = false;

        if( s == "1" || s  == "T" || toLowerCase( s ) == "true" )
        {
            result = true;
        }
        else if( s == "0" || s == "F" || toLowerCase( s ) == "false" )
        {
            result = false;
        }
        else
        {
            setErro( 3 );
            result = false;
        } // end if

        return ( result );

    } // end getBoolean ( )

    /**
     *  Método para verificar se o texto está contido no conteúdo.
     *  @return TRUE se está contido; FALSE caso contrário. 
    */
    bool contains( std::string text )
    {
        bool result = false;
        /* // para posição fixa 
        if( text.size( ) > 0 && text.size( ) <= s.size( ) )
        {
            for( int x = 0; x < (int)s.size( ); x = x + 1 )
            {
                if( s[x] == text[0] )
                {
                    for( int y = x, z = 0; y < (int)text.size( ); y = y + 1, z = z + 1 )
                    {
                        if( s[y] == text[z] )
                        {
                            result = true;
                        }
                        else
                        {
                            result = false;
                        } // end if
                    } // end for
                } // end if
            } // end for
        } 
        else
        {
            setErro( 4 );
        }// end if */

        // para qualquer posição
        if( text.size( ) > 0 && text.size( ) <= s.size( ) )
        {
            for( int x = 0, y = 0; x < (int)s.size( ); x = x + 1 )
            {
                if( s[x] == text[y] )
                {
                    y = y + 1;
                } // end if
                if( y == (int)text.size( ) )
                {
                    result = true;
                } // end if
            } // end for
        } 
        else
        {
            setErro( 4 ); 
        } // end if

        return ( result );

    } // end contains ( )

    /**
     *  Método para converter String para maiusculo.
     *  @return String maiuscula.
    */
    std::string toUpperCase( )
    {
        for( int x = 0; x < (int)s.size( ); x = x + 1 )
        {
            s[x]= toUpper( s[x] );
        } // end for
        return ( s );
    } // end toUpperCase ( )

    /**
     *  Método para converter String para minusculo.
     *  @return String minuscula.
    */
    std::string toLowerCase( )
    {
        for( int x = 0; x < (int)s.size( ); x = x + 1 )
        {
                s[x] = toLower( s[x] );
        } // end for
        return ( s );
    } // end toLowerCase ( )

    /**
     *  Método para trocar as ocorrências de um caractere por outro.
     *  @return String com os caracteres trocados.
    */
    std::string replace( char original, char novo )
    {
        std::string aux = s;
        if( aux.empty( ) )
        {
            setErro( 7 );
        }
        else
        {
            for( int x = 0; x < (int)aux.size( ); x = x + 1 )
            {
                if( aux[x] == original )
                {
                    aux[x] = novo;
                } // end if
            } // end for
        } // end if

        return ( aux );

    } // end replace ( )

    /**
     *  Método para codificar a string para a Cifra de César.
     *  @return String Codificada.
    */
    std::string encrypt( )
    {
        std::string aux = s;

        if( aux.empty( ) )
        {
            setErro( 8 );
        }
        else
        {
            for( int x  = 0; x < (int)aux.size( ); x = x + 1 )
            {
                if( isLower( aux[x] ) )
                {
                    if( aux[x] + 3 <= 122 )
                        aux[x] =  ( s[x] + 3 );
                    else
                        aux[x] = ( ( s[x] + 3 ) - 122 ) + 96;
                }
                else if( isUpper( aux[x] ) )
                {
                    if( aux[x] + 3 <= 90 )
                        aux[x] =  ( s[x] + 3 );
                    else
                        aux[x] = ( ( s[x] + 3 ) - 90 ) + 64;
                }
                else if( isDigit( aux[x] ) )
                {
                    if( aux[x] + 3 <= 57 )
                        aux[x] =  ( s[x] + 3 );
                    else
                        aux[x] = ( ( s[x] + 3 ) - 57 ) + 47;
                }
                else
                {
                    aux[x] = ( s[x] + 3 );
                } // end if
            } // end for
        } // end if

        return ( aux );

    } // end encrypt ( )

    /**
     *  Método para descodificar a Cifra de César para String.
     *  @return String Decodificada.
    */
    std::string decrypt( )
    {
        std::string aux = s;

        if( aux.empty( ) )
        {
            setErro( 9 );
        }
        else
        {
            for( int x  = 0; x < (int)aux.size( ); x = x + 1 )
            {
                if( isLower( aux[x] ) )
                {
                    if( aux[x] - 3 < 97 )
                        aux[x] = ( ( s[x] - 3 ) + 122 ) - 96;
                    else
                        aux[x] =  ( s[x] - 3 );
                }
                else if( isUpper( aux[x] ) )
                {
                    if( aux[x] - 3 < 65 )
                        aux[x] = ( ( s[x] - 3 ) + 90 ) - 64; 
                    else
                        aux[x] =  ( s[x] - 3 );
                }
                else if( isDigit( aux[x] ) )
                {
                    if( aux[x] - 3 < 48 )
                        aux[x] = ( ( s[x] - 3 ) + 57 ) - 47;
                    else
                        aux[x] =  ( s[x] - 3 );
                }
                else
                {
                    aux[x] = ( s[x] - 3 );
                } // end if
            } // end for
        } // end if

        return ( aux );

    } // end decrypt ( )

    /**
     *  Método para separar todas as sequencias de caracteres separadas por espaços em branco.
     *  @return quantidade de sequencias de caracteres identificadas, se houver; zero, caso contrario.
    */
    int split( std::string sequencia[ ] )
    {
        int result = 0;
        std::string aux = "";

        if( s.empty( ) )
        {
            setErro( 10 );
        }
        else
        {
            for( int x = 0; x < (int)s.size( ); x = x + 1 )
            {
                if( !isSpace( s[x] ) )
                {
                    aux = aux + s[x];
                }
                else
                {
                    sequencia[result] = aux;
                    aux = "";
                    result = result + 1;
                } // end if
            } // end for

            if( !aux.empty( ) )
            {
                sequencia[result] = aux;
                result = result + 1;
            } // end if
        } // end if

        return ( result );

    } // end split ( )

    /**
     *  Método para fragmentar o conteúdo usando um delimitador à escolha, diferente de espaço em branco.
     *  @return quantidade de sequencias de caracteres identificadas, se houver.
    */
    int fragmentar( char c, std::string sequencia[ ] )
    {
        std::string aux = "";
        int y = 0;

        if( s.empty( ) )
        {
            setErro( 11 );
        }
        else
        {
            // colocar o delimitador nos espaços em branco
            for( int x = 0; x < (int)s.size( ); x = x + 1 )
            {
                if( isSpace( s[x] ) )
                {
                    s[x] = c;
                } // end if
            } // end for

            // guardar no arranjo cada string até o novo delimitador
            for( int x = 0; x < (int)s.size( ); x = x + 1 )
            {
                if( s[x] != c )
                {
                    aux = aux + s[x];
                }
                else
                {
                    sequencia[y] = aux;
                    aux = "";
                    y = y + 1;
                } // end if
            } // end for

            if( !aux.empty( ) )
            {
                sequencia[y] = aux;
                y = y + 1;
            } // end if
        } // end if

        return ( y );

    } // end fragmentar ( )

    /**
     *  Método para inverter a ordem dos símbolos na cadeia de caracteres.
    */
    void inverter( )
    {
        char temp;

        if( s.empty( ) )
        {
            setErro( 12 );
        }
        else
        {
            for( int x = 0; x < (int)s.size( )/2; x = x + 1 )
            {
                temp = s[x];
                s[x] = s[ s.size( ) - ( x + 1 ) ];
                s[ s.size( ) - ( x + 1 ) ] = temp;
            } // end for
        } // end if
        
    } // end inverter ( )

    std::string getErroMsg()
    {
        std::string erroMsg = "";

        switch( getErro( ) )
        {
            case 0: 
                erroMsg = NO_ERROR; 
                break;
            case 1: 
                erroMsg = "[ERRO] Nao foi possivel converter para inteiro."; 
                break;
            case 2: 
                erroMsg = "[ERRO] Nao foi possivel converter para real."; 
                break;
            case 3: 
                erroMsg = "[ERRO] Nao foi possivel converter para valor logico."; 
                break;
            case 4: 
                erroMsg = "[ERRO] Nao foi possivel encontrar a substring."; 
                break;
            case 7: 
                erroMsg = "[ERRO] Nao foi possivel trocar um caractere por outro."; 
                break;
            case 8: 
                erroMsg = "[ERRO] Nao foi possivel codificar a string."; 
                break;
            case 9: 
                erroMsg = "[ERRO] Nao foi possivel decodificar a string."; 
                break;
            case 10:
                erroMsg = "[ERRO] Nao foi possivel separar as cadeias de caractere.";
                break;
            case 11:
                erroMsg = "[ERRO] Nao foi possivel fragmentar.";
                break;
            case 12:
                erroMsg = "[ERRO] Nao foi possivel inverter.";
                break;
            default: 
                erroMsg = "Codigo de erro invalido."; 
                break;
        }

        return ( erroMsg );

    } // end getErroMsg ( )

}; // end class MyString

#endif
