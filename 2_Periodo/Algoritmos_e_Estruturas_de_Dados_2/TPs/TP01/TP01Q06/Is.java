/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q06 - 26 / 02 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Is.java
 *       Windows: javac Is.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Is
 *       Windows: java Is
 *   
*/

public class Is 
{
    /**
     *  Funcao principal.
     *  @param args
     */
    public static void main( String[] args )
    {
        MyIO.setCharset("UTF-8");
        String entrada = "";
        do 
        {
            entrada = MyIO.readLine();
            if( !isFim( entrada ) )
            {
                MyIO.print( isVogal    (entrada) ? "SIM "  : "NAO "  );
                MyIO.print( isConsoante(entrada) ? "SIM "  : "NAO "  );
                MyIO.print( isInteger  (entrada) ? "SIM "  : "NAO "  );
                MyIO.print( isReal     (entrada) ? "SIM\n" : "NAO\n" );
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
    public static boolean isVogal( String s )
    {
        boolean result = true;
        int x = 0;
        if( isAlpha( s ) )
        {
            while( x < s.length() && result )
            {
                char c = s.charAt( x );
                if( !isCharVogal( c ) )
                {
                    result = false;
                } // end if
                x = x + 1;
            } // end while
        } 
        else
        {
            result = false;
        }// end if
        return ( result );
    } // end isVogal ( )

    /**
     *  Funcao para verificar se a string e composta apenas por consoantes.
     *  @param s - String.
     *  @return true se so' tem consoantes, false caso contrario.
     */
    public static boolean isConsoante( String s )
    {
        boolean result = true;
        int x = 0;
        if( isAlpha( s ) )
        {
            while( x < s.length( ) && result )
            {
                char c = s.charAt( x );
                if( isCharVogal( c ) )
                {
                    result = false;
                } // end if
                x = x + 1;
            } // end while
        }
        else
        {
            result = false;
        }// end if
        return ( result );
    } // end isConsoante ( )

    /**
     *  Funcao para verificar se a string e composta por numeros e e' inteira.
     *  @param s - String.
     *  @return true se numero inteiro, false caso contrario.
     */
    public static boolean isInteger( String s )
    {
        boolean result = true;
        for( int x = 0; x < s.length( ); x = x + 1 )
        {
            char c = s.charAt( x );
            if( !isDigit( c ) )
            {
                result = false;
                x = s.length( );
            } // end if
        } // end for
        return ( result );
    } // end isInteger ( )

    /**
     *  Funcao para verificar se a string e composta por numeros e e' real.
     *  @param s - String.
     *  @return true se numero real, false caso contrario.
     */
    public static boolean isReal( String s )
    {
        boolean result = false;
        int count = 0;
        int ponto = 0;
        for( int x = 0; x < s.length( ); x = x + 1 )
        {
            char c = s.charAt( x );
            if( isDigit( c ) )
            {
                count++;
            } 
            else if( c =='.' || c == ',' )
            {
                ponto++;
            }// end if
        } // end for
        if( count > 0 && ponto <= 1 )
        {
            result = true;
        } // end if
        return ( result );
    } // end isReal ( )

} // end class
