/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q10 - 11 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac PalindromoRec.java
 *       Windows: javac PalindromoRec.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java PalindromoRec
 *       Windows: java PalindromoRec
 *   
*/

class PalindromoRec
{
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

    /**
     *  Funcao para verificar se uma string e' um palindromo.
     *  @return true se palindromo, false caso contrario.
     *  @param s - String
     *  @param x - Int: primeiro caractere.
     *  @param y - Int: ultimo caractere.
    */
    public static boolean isPalindromoRec ( String s, int x, int y )
    {
        if( x < s.length()/2 )
        {
            if( (int)s.charAt(x) == (int)s.charAt(y) )
            {
                return ( isPalindromoRec(s, ++x, --y) );
            }
            else
            {
                return ( false );
            } // end if
        } // end if
        return ( true );
    } // end isPalindromo ( )

    /**
     *  Funcao para verificar se uma string e' um palindromo.
     *  @return true se palindromo, false caso contrario.
     *  @param s - String
    */
    public static boolean isPalindromo( String s )
    {
        return ( isPalindromoRec( s, 0, s.length()-1 ) );
    } // end isPalindromo ( )

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
                if( isPalindromo( entrada ) )
                {
                    MyIO.println( "SIM" );
                }
                else
                {
                    MyIO.println( "NAO" );
                } // end if
            } // end if
        } while ( isFim( entrada ) == false ); // end do while
    } // end main ( )
} // end class