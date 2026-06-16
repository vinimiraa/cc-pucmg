/*  -------------------------- Documentacao
*  Pontificia Universidade Catolica de Minas Gerais
*  Curso de Ciencia da Computacao
*  Algoritmos e Estruturas de Dados II
*   
*  Aquecimento - 19 / 02 / 2024
*  Author: Vinicius Miranda de Araujo
*   
*  Para compilar em terminal (janela de comandos):
*       Linux : javac LAB01Q01.java
*       Windows: javac LAB01Q01.java
*   
*  Para executar em terminal (janela de comandos):
*       Linux : java LAB01Q01
*       Windows: java LAB01Q01
*   
*/

public class LAB01Q01 
{
    /**
     *  Funcao para verificar se a entrada e' igual a "FIM" 
     *  @param s - String.
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
     *  Função para verificar se o caractere e' maiusculo.
     *  @param c - caractere.
     *  @return true se maiusculo, false caso contrario.
     */
    public static boolean isUpper( char c )
    {
        boolean result = false;
        if( 'A' <= c && c <= 'Z' )
        {
            result = true;
        }
        return ( result );
    } // end ifUpper ( )

    /**
     *  Funcao para contabilizar o numero de letras maiusculas em uma string.
     *  @param s - String.
     *  @return numero de maiusculas.
     */
    public static int countUppers( String s )
    {
        int result = 0;
        int x = 0;
        for( x = 0; x < s.length( ); x = x + 1 )
        {
            if( isUpper( s.charAt(x) ) )
            {
                result = result + 1;
            } // end if
        } // end for
        return ( result );
    } // end countUppers ( )

    /**
     *  Funcao principal.
     *  @param args
     */
    public static void main( String[] args )
    {
        String[] entrada = new String[1000];
        int numEntrada = 0;

        do 
        {
            entrada[numEntrada] = MyIO.readLine( );
        } while ( isFim( entrada[numEntrada++] ) == false ); // end do while
        numEntrada--;   

        for( int x = 0; x < numEntrada; x++){
            MyIO.println( countUppers(entrada[x]) );
        } // end for
    } // end main ( )
} // end class
