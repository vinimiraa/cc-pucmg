/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q01 - 19 / 02 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Palindromo.java
 *       Windows: javac Palindromo.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Palindromo
 *       Windows: java Palindromo
 *   
*/

class Palindromo
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
    */
    public static boolean isPalindromo ( String s )
    {
        boolean result = true;
        int x = 0, y = 0;
        
        for ( x = 0, y = s.length( )-1; x < s.length( )/2; x=x+1, y=y-1 )
        {
            if ( s.charAt(x) != s.charAt(y) ) // verificar se o primeiro caractere e' diferente do ultimo
            {
                result = false;  
                x = s.length( ); // interromper a repeticao
            } // end if
        } // end for
        return ( result );
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