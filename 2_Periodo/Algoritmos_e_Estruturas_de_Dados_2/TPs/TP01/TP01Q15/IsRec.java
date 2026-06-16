/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q15 - 12 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac IsRec.java
 *       Windows: javac IsRec.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java IsRec
 *       Windows: java IsRec
 *   
*/

public class IsRec 
{
    /**
     *  Funcao principal.
     *  @param args
     */
    public static void main( String[] args ) 
    {
        String entrada = "";
        String i1 = "", i2 = "", i3 = "", i4 = "";
        do 
        {
            entrada = MyIO.readLine();
            if( !isFim( entrada ) )
            {
                if( isVogal( entrada ) ) 
                {
                    i1 = "SIM";
                } 
                else 
                {
                    i1 = "NAO";
                } // end if

                if( isConsoante( entrada ) ) 
                {
                    i2 = "SIM";
                } 
                else 
                {
                    i2 = "NAO";
                } // end if

                if( isInteger( entrada ) ) 
                {
                    i3 = "SIM";
                } 
                else 
                {
                    i3 = "NAO";
                } // end if

                if( isReal( entrada ) ) 
                {
                    i4 = "SIM";
                } 
                else 
                {
                    i4 = "NAO";
                }  // end if
                MyIO.println( i1 + " " + i2 + " " + i3 + " " + i4 );
            } // end if
        } while ( isFim( entrada ) == false ); // end do while
    } // end main ( )

    /**
     *  Funcao para verificar se a entrada e' igual a "FIM" 
     *  @param s - String
     *  @return true se fim, false caso contrario.
     */
    public static boolean isFim( String s )
    {
        boolean result = false;
        if( s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isFim ( )
    
    // Funcao para verificar se e' o caractere e maiusculo
    public static boolean isUpper( char c )
    {
        boolean result = false;
        if( 'A' <= c && c <= 'Z' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isUpper ( )
    
    // Funcao para verificar se e' o caractere e minusculo
    public static boolean isLower( char c )
    {
        boolean result = false;
        if( 'a' <= c && c <= 'z' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isLower ( )

    // Funcao para verificar se e' o caractere e digito
    public static boolean isDigit( char c )
    {
        boolean result = false;
        if( '0' <= c && c <= '9' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isDigit ( )

    // Funcao para converter o caractere para minusculo
    public static char toLower( char c )
    {
        char result = c;
        if( isUpper(c) )
        {
            result = (char)(result + 32);
        } // end if
        return ( result );
    } // end toLower ( )

    // Funcao para verificar se e' o caractere e letra
    public static boolean isAlpha( String s )
    {
        boolean result = false;
        for( int x = 0; x < s.length(); x = x + 1 )
        {
            char c = s.charAt( x );
            if( isLower(c) || isUpper(c) )
            {
                result = true;
            } // end if
        } // end for
        return (result);
    } // end isAlpha ( )

    // Funcao para verificar se e' o caractere e vogal
    public static boolean isCharVogal( char c )
    {
        boolean result = false;
        char a = toLower(c);
        if( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' )
        {
            result = true;
        } // end if
        return ( result );
    } // end isCharVogal ( )

    /**
     *  Funcao para verificar se a string e composta apenas por vogais.
     *  @param s - String.
     *  @return true se so' tem vogais, false caso contrario.
     */
    public static boolean isVogalRec( String s, int x )
    {
        if( x < s.length() )
        {
            char c = s.charAt( x );
            if( !isCharVogal( c ) )
            {
                return ( false );
            } 
            else
            {
                return ( isVogalRec(s, x+1) );
            }// end if
        } // end if
        else
        {
            return ( true );
        }// end if
    } // end isVogalRec ( )

    public static boolean isVogal( String s )
    {
        boolean result = false;
        if( isAlpha(s) )
        {
            result = isVogalRec(s, 0);
        } // end if
        return ( result );
    } // end isVogal ( )

    /**
     *  Funcao para verificar se a string e composta apenas por consoantes.
     *  @param s - String.
     *  @return true se so' tem consoantes, false caso contrario.
     */
    public static boolean isConsoanteRec( String s, int x )
    {
        if( x < s.length( ) )
        {
            char c = s.charAt( x );
            if( isCharVogal( c ) )
            {
                return ( false );
            }
            else
            {
                return ( isConsoanteRec(s, x+1) );
            } // end if
        }
        else
        {
            return ( true );
        }// end if
    } // end isConsoanteRec ( )

    public static boolean isConsoante( String s )
    {
        boolean result = false;
        if( isAlpha(s) )
        {
            result = isConsoanteRec(s, 0);
        } // end if
        return ( result );
    } // end isConsoante ( )

    /**
     *  Funcao para verificar se a string e composta por numeros e e' inteira.
     *  @param s - String.
     *  @return true se numero inteiro, false caso contrario.
     */
    public static boolean isIntegerRec( String s, int x )
    {
        if( x < s.length( ) )
        {
            char c = s.charAt( x );
            if( !isDigit( c ) )
            {
                return ( false );
            } // end if
            else
            {
                return isIntegerRec(s, x+1);
            } // end if
        }
        else
        {
            return ( true );
        } // end if
    } // end isIntegerRec ( )

    public static boolean isInteger( String s )
    {
        return ( isIntegerRec(s, 0) );
    } // end isInteger ( )

    /**
     *  Funcao para verificar se a string e composta por numeros e e' real.
     *  @param s - String.
     *  @param x - Int: posicao inicial.
     *  @param ponto - Int: quantidade de ponto.
     *  @return true se numero real, false caso contrario.
     */
    public static boolean isRealRec( String s, int x, int ponto )
    {
        if( x < s.length() )
        {
            char c = s.charAt( x );
            if( isDigit( c ) )
            {
                return ( isRealRec(s, x+1, ponto) );
            } 
            else if( c =='.' || c == ',' )
            {
                ponto = ponto + 1;
                return ( isRealRec(s, x+1, ponto) );
            }
            else
            {
                return ( false );
            }// end if
        }
        else
        {
            if( ponto <= 1 )
            {
                return ( true );
            }
            else
            {
                return ( false );
            } // end if
        } // end if
    } // end isRealRec ( )

    public static boolean isReal( String s )
    {
        return ( isRealRec(s, 0, 0) );
    } // end isReal ( )

} // end class
