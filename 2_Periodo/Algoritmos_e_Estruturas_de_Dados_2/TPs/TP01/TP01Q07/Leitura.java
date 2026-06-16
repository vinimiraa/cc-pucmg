/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q07 - 14 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Leitura.java
 *       Windows: javac Leitura.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Leitura
 *       Windows: java Leitura
 *   
*/

import java.io.*;
import java.net.*;

public class Leitura 
{
    // caracteres especiais
    static final char[] especial = 
    {
        225, // á 0
        233, // é 1
        237, // í 2 
        243, // ó 3
        250, // ú 4
        224, // à 5
        232, // è 6
        236, // ì 7
        242, // ò 8 
        249, // ù 9
        227, // ã 10
        245, // õ 11
        226, // â 12
        234, // ê 13
        238, // î 14
        244, // ô 15
        251  // û 16
    };
    // vogais
    static int[] vogais;

    /**
     *  Funcao principal.
     *  @param args 
     */
    public static void main( String[] args ) 
    {
        MyIO.setCharset("UTF-8");
        String nome     = "" ;
        String endereco = "" ;
        String html     = "" ;
        int consoantes = 0, br = 0, table = 0;

        do
        {
            nome = MyIO.readLine();
            if( !isFim(nome) )
            {
                endereco = MyIO.readLine();
                html = getHtml(endereco);

                countVogais( html );
                consoantes = countConsoantes( html );
                br = countBr( html );
                table = countTable( html );

                vogais[0]  -= table;              // descontar o 'a' da palavra "table"
                vogais[1]  -= table;              // descontar o 'e' da palavra "table"
                consoantes -= ( 2*br + 3*table ); // descontar as consoantes das palavras "br" e "table"

                printVariaveis( );
                System.out.printf( "consoante(%s) " , consoantes );
                System.out.printf( "<br>(%s) " , br );
                System.out.printf( "<table>(%s) " , table );
                System.out.printf( "%s\n" , nome );
            } // end if
        } while( !isFim( nome ) ); // end while

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

    /**
     *  Funcao para contar a quantidade de vogais numa string.
     *  @param html - String.
     */
    public static void countVogais( String html ) 
    {
        vogais = new int[23];
        for (int x = 0; x < html.length(); x = x + 1) 
        {
            char c = html.charAt(x);
            if (c == 'a') vogais[0]++;
            else if (c == 'e') vogais[1]++;
            else if (c == 'i') vogais[2]++;
            else if (c == 'o') vogais[3]++;
            else if (c == 'u') vogais[4]++;
            else if (isEspecial(c)) 
            {
                for( int y = 0; y < especial.length; y = y + 1 ) 
                {
                    if( c == especial[y] ) 
                    {
                        vogais[y + 5]++;
                        break;
                    } // end if
                } // end for
            } // end if
        } // end for
    } // end countVogais ( )
    
    public static boolean isEspecial( char c ) 
    {
        for (int x = 0; x < especial.length; x = x + 1) 
        {
            if( c == especial[x] ) 
            {
                return ( true );
            } // end if
        } // end for
        return ( false );
    } // end isEspecial

    /**
     *  Funcao para contar a quantidade de consoantes numa string. 
     *  @param html - String.
     *  @return Quantidade de consoantes.
     */
    public static int countConsoantes( String html )
    {
        int result = 0;
        String consoantes = "bcdfghjklmnpqrstvwxyz";
        for( int x = 0; x < consoantes.length(); x = x + 1 )
        {
            char consoantechar = consoantes.charAt(x);
            for( int y = 0; y < html.length(); y = y + 1 )
            {
                char htmlchar = html.charAt(y);
                if( htmlchar == consoantechar )
                {
                    result++;
                } // end if
            } // end for
        } // end for
        return ( result );
    } // end countConsoantes ( )

    /**
     *  Funcao para contar a quantidade de tags <br> no html.
     *  @param html - String.
     *  @return Quantidade de tags <br>
     */
    public static int countBr( String html )
    {
        int result = 0 ;
        for( int x  = 0; x < html.length()-4; x = x + 1 )
        {
            if( isEquals( subString(html, x, x+4), "<br>" ) )
            {
                result++;
            } // end if
        } // end for
        return ( result );
    } // end countBr ( )

    /**
     *  Funcao para contar a quantidade de tags <table> no html.
     *  @param html - String.
     *  @return Quantidade de tags <table>
     */
    public static int countTable( String html )
    {
        int result = 0 ;
        for( int x  = 0; x < html.length()-7; x = x + 1 )
        {
            if( isEquals( subString(html, x, x+7), "<table>") )
            {
                result++;
            } // end if
        } // end for
        return ( result );
    } // end countTable ( )

    // Funcao para imprimir as vogais
    public static void printVariaveis( )
    {
        System.out.printf( "a(%s) "  ,                vogais[ 0] );
        System.out.printf( "e(%s) "  ,                vogais[ 1] );
        System.out.printf( "i(%s) "  ,                vogais[ 2] );
        System.out.printf( "o(%s) "  ,                vogais[ 3] );
        System.out.printf( "u(%s) "  ,                vogais[ 4] );
        System.out.printf( "%c(%s) " , especial[ 0] , vogais[ 5] );
        System.out.printf( "%c(%s) " , especial[ 1] , vogais[ 6] );
        System.out.printf( "%c(%s) " , especial[ 2] , vogais[ 7] );
        System.out.printf( "%c(%s) " , especial[ 3] , vogais[ 8] );
        System.out.printf( "%c(%s) " , especial[ 4] , vogais[ 9] );
        System.out.printf( "%c(%s) " , especial[ 5] , vogais[10] );
        System.out.printf( "%c(%s) " , especial[ 6] , vogais[11] );
        System.out.printf( "%c(%s) " , especial[ 7] , vogais[12] );
        System.out.printf( "%c(%s) " , especial[ 8] , vogais[13] );
        System.out.printf( "%c(%s) " , especial[ 9] , vogais[14] );
        System.out.printf( "%c(%s) " , especial[10] , vogais[15] );
        System.out.printf( "%c(%s) " , especial[11] , vogais[16] );
        System.out.printf( "%c(%s) " , especial[12] , vogais[17] );
        System.out.printf( "%c(%s) " , especial[13] , vogais[18] );
        System.out.printf( "%c(%s) " , especial[14] , vogais[19] );
        System.out.printf( "%c(%s) " , especial[15] , vogais[20] );
        System.out.printf( "%c(%s) " , especial[16] , vogais[21] ); 
    } // end printVariaveis ( )

    // --------------------------------------------------------- Minha refacao de funcoes ja existentes no java

    /**
     *  Funcao para pegar parte de uma string.
     *  @param s - String toda.
     *  @param start - Int: Comeco.
     *  @param end - Int: fim.
     *  @return String
     */
    public static String subString( String s, int start, int end )
    {
        String result = "";
        for( int x = start; x < end; x = x + 1 )
        {
            char c = s.charAt(x);
            result = result + c;
        } // end for
        return ( result );
    } // end subString ( )

    /**
     *  Funcao para verficar em qual posicao da string um caractere esta'.
     *  @param find - char: caractere a ser procurado.
     *  @param s - String: Onde o caractere sera' procurado.
     *  @return posicao da ocorrencia
     */
    public static int indexOf( char find, String s )
    {
        int index = -1;
        for( int x = 0; x < s.length(); x =  x + 1 )
        {
            char c = s.charAt(x);
            if( c == find )
            {
                index = x;
                x = s.length();
            } // end if
        } // end for
        return ( index );
    } // end indexOf ( )

    /**
     *  Funcao para verificar se duas strings sao iguais.
     *  @param obj1 - String.
     *  @param obj2 - String.
     *  @return true se iguais, false caso contrario.
     */
    public static boolean isEquals( String obj1, String obj2 )
    {
        boolean result = true;
        if( obj1.length() != obj2.length() )
        {
            result = false;
        }
        else
        {
            for( int x = 0; x < obj1.length() && result; x = x + 1 )
            {
                if( obj1.charAt(x) != obj2.charAt(x) )
                {
                    result = false;
                } // end if
            } // end for
        } // end if
        return ( result );
    } // end isEquals ( )

    // --------------------------------------------------------- Funcao Disponibilizada pelo Professor

    /**
     *  Funcao para pegar o conteudo de um html e converter para string.
     *  @param endereco - String: url do site.
     *  @return 
     */
    public static String getHtml( String endereco )
    {
        URL url;
        InputStream is = null;
        BufferedReader br;
        String resp = "", line;
        try 
        {
            url = new URL(endereco);
            is = url.openStream();  // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while( ( line = br.readLine() ) != null ) 
            {
                resp += line + "\n";
            } // end while
        } 
        catch( MalformedURLException mue ) 
        {
            mue.printStackTrace();
        } 
        catch( IOException ioe ) 
        {
            ioe.printStackTrace();
        } // end try catch
        try 
        {
            is.close();
        } 
        catch (IOException ioe) 
        {
         // nothing to see here
        } // end try catch
        return ( resp );
    } // end getHtml ( )
} // end class