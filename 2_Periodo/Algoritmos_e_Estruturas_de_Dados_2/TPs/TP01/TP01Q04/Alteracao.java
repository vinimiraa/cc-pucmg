/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q04 - 26 / 02 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Alteracao.java
 *       Windows: javac Alteracao.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Alteracao
 *       Windows: java Alteracao
 *   
*/

import java.util.Random;

public class Alteracao 
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
     *  Funcao para gerar um caractere aleatorio.
     *  @return caractere aleatorio.
     */
    public static char randomChar( )
    {
        Random gerador = new Random( 4 );
        char c = ( char )( 'a' + ( Math.abs( gerador.nextInt( ) ) % 26 ) );
        return ( c );
    } // end randomChar ( )

    /**
     *  Funcao para substituir todas as ocorrencias da primeira letra na string pela segunda. 
     *  @param s - String.
     *  @return nova string.
     */
    public static String randomChange( String s )
    {
        String result = "";
        char c1 = randomChar( ); // primeira letra
        char c2 = randomChar( ); // segunda letra
        int length = s.length( );
        for( int x = 0; x < length; x = x + 1 )
        {
            char c0 = s.charAt(x);
            if( s.charAt(x) == c1 )
            {
                result = result + c2;
            }
            else
            {
                result = result + c0;
            } // end if
        } // end for
        return ( result );
    } // end alteracaoAleatoria ( )

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
            MyIO.println( randomChange( entrada[x] ) );
        } // end for
    } // end main ( )
} // end class
