/**
 *  Arquitetura de Computadores I - Guia_0101.java
 *  812839 - Vinicius Miranda de Araujo
*/
public class Guia_01 
{
    /**
     *  Contador de erros.
     */
    private static int errors = 0;

    /**
     *  Testar se dois valores sao iguais.
     *  @param x - primeiro valor
     *  @param y - segundo valor
     */
    public static void test_equals( Object x, Object y ) 
    {
        if ( ( "" + x ).compareTo( "" + y ) != 0 )
            errors = errors + 1;
    } // end test_equals ( )

    /**
     *  Exibir o total de erros.
     *  @return mensagem com o total de erros
     */
    public static String test_report( ) 
    {
        return ( "" + errors );
    } // end test_report ( )

    /**
     *  Converter valor decimal para binario.
     *  @return binario equivalente
     *  @param value - valor decimal
     */
    public static String dec2bin( int value ) 
    {
        int binary = 0;
        int bit = 0;
        int position = 1;

        while( value > 0 )
        {
            bit = value % 2;
            binary = binary + bit * position;
            value = value / 2;
            position = position * 10;
        } // end while

        return ( Integer.toString( binary ) );
    } // end dec2bin ( )

    /**
     *  Converter valor binario para decimal.
     *  @return decimal equivalente
     *  @param value - valor binario
     */
    public static int bin2dec( String value ) 
    {
        int length = 0;
        int decimal = 0;
        int bit = 0;

        length = value.length();
        for( int x = 0; x < length; x = x + 1 )
        {
            bit = Integer.parseInt(String.valueOf(value.charAt(x)));
            decimal = decimal + bit * (int)Math.pow(2, length-1-x);
        } // end for

        return ( decimal );
    } // end bin2dec ( )

    /**
     *  Converter valor decimal para base indicada.
     *  @return base para a conversao
     *  @param value - valor decimal
     */
    public static String dec2base( int value, int base ) 
    {
        // int result = 0;
        int bit = 0;
        int position = 1;
        char digit;
        StringBuilder result = new StringBuilder();

        while( value > 0 )
        {
            bit = value % base;
            if( bit > 9 )
            {
                digit = (char)( 'A' + ( bit - 10 ) );
                // result = result + ( digit - '0' ) * position;
                result.insert( 0, digit );
            }
            else
            {
                // result = result + bit * position;
                result.insert( 0, bit );
            } // end if
            value = value / base;
            position = position * 10;
        } // end for

        // return ( Integer.toString(result) );
        return ( result.toString( ) );
    } // end dec2base ( )

    /**
     *  Converter valor binario para base indicada.
     *  @return valor equivalente na base indicada
     *  @param value - valor binario
     *  @param base - para a conversao
     */
    public static String bin2base( String value, int base ) 
    {
        return ( dec2base( bin2dec( value ) , base ) );
    } // end bin2base ( )

    /**
     *  Converter valor em ASCII para hexadecimal.
     *  @return hexadecimal equivalente
     *  @param value - caractere(s) em codigo ASCII
     */
    public static String ASCII2hex( String value ) 
    {
        StringBuilder result = new StringBuilder( );
        int ascii = 0;
        String hex;

        for ( int x = 0; x < value.length() ; x = x + 1 )
        {
            ascii = (int) value.charAt( x );

            hex = dec2base(ascii, 16);

            result.append( hex ).append( " " );
            // result.insert(0, dec2base( (int)value.charAt(x) , 16));
        }
        return ( result.toString( ) );
    } // end ASCII2hex ( )

    /**
     *  Converter valor em hexadecimal para ASCII.
     *  @return caractere(s) em codigo ASCII
     *  @param value - hexadecimal equivalente(s)
     */
    public static String hex2ASCII( String value ) 
    {
        return ("0");
    } // end hex2ASCII ( )

    /**
     *  Acao principal.
     */
    public static void main( String[] args ) 
    {
        System.out.println( "Guia_01 - Java Tests "                );
        System.out.println( "812839 - Vinicius Miranda de Araujo " );
        System.out.println( );

        test_equals( dec2bin( 23  ), "10111"      );
        test_equals( dec2bin( 57  ), "111001"     );
        test_equals( dec2bin( 732 ), "1011011100" );
        test_equals( dec2bin( 321 ), "101000001"  );
        test_equals( dec2bin( 364 ), "101101100"  );
        System.out.println("1. errorTotalReport = " + test_report());

        test_equals( bin2dec( "10011"  ), 19 );
        test_equals( bin2dec( "11101"  ), 29 );
        test_equals( bin2dec( "10110"  ), 22 );
        test_equals( bin2dec( "101101" ), 45 );
        test_equals( bin2dec( "110011" ), 51 );
        System.out.println("2. errorTotalReport = " + test_report());
        
        test_equals( dec2base( 67 , 4  ), "1003" );
        test_equals( dec2base( 58 , 8  ), "72"   );
        test_equals( dec2base( 76 , 16 ), "4C"   );
        test_equals( dec2base( 157, 16 ), "9D"   );
        test_equals( dec2base( 735, 16 ), "2DF"  );
        System.out.println("3. errorTotalReport = " + test_report());

        test_equals( bin2base( "10111" , 4  ), "113" );
        test_equals( bin2base( "11110" , 8  ), "36"  );
        test_equals( bin2base( "100101", 16 ), "25"  );
        test_equals( bin2base( "101011", 8  ), "53"  );
        test_equals( bin2base( "101100", 4  ), "230" );
        System.out.println("4. errorTotalReport = " + test_report());

        test_equals( ASCII2hex( "PUC-M.G." ), "50 55 43 2D 4D 2E 47 2E " );
        test_equals( ASCII2hex( "2024-01"  ), "32 30 32 34 2D 30 31 "    );
        // test_equals( ASCII2hex( "Minas Gerais" ), 
        // "01001101 01101001 01101110 01100001 01110011 00100000 01000111 01100101 01110010 01100001 01101001 0111001");
        // test_equals(hex2ASCII("116 117 111 124 105"), "NOITE"); // OBS.: 116 e' o primeiro octal (0116)!
        test_equals( hex2ASCII( "54 61 72 64 65" ), "Tarde" ); // OBS.: 54 e' o primeiro hexadecimal (0x54)!
        System.out.println( "5. errorTotalReport = " + test_report( ) );

        System.out.print( "\n\nApertar ENTER para terminar." );
        try {
            System.console( ).readLine( );
            
        } catch ( Exception e ) {
            System.err.println( "Erro: leitura invalida." );
        }
    } // end main

} // end class
