/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q03 - 26 / 02 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Ciframento.java
 *       Windows: javac Ciframento.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Ciframento
 *       Windows: java Ciframento
 *   
*/

public class Ciframento 
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
     *  Funcao para cifrar uma string.
     *  @param s - String.
     *  @return string cifrada.
     */
    public static String ciframento ( String s )
    {
        String cifra = "";
        int ascii = 0;
        for( int x = 0; x < s.length(); x = x + 1 )
        {
            ascii = s.charAt(x);
            cifra = cifra + (char)(ascii+3);
        } // end for
        return ( cifra );
    } // end Ciframento ( )

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
        } while( isFim( entrada[numEntrada++] ) == false ); // end do while
        numEntrada--;

        for( int x = 0; x < numEntrada; x = x + 1 )
        {
            MyIO.println( ciframento( entrada[x] ) );
        } // end for
    } // end main ( )
} // end class
