/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q14 - 22 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac AlgebraBooleanaRec.java
 *       Windows: javac AlgebraBooleanaRec.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java AlgebraBooleanaRec
 *       Windows: java AlgebraBooleanaRec
 *   
*/

public class AlgebraBooleanaRec 
{
    /**
     *  Funcao prinicipal.
     *  @param args
     */
    public static void main( String[] args )
    {
        MyIO.setCharset("UTF-8");
        String entrada = "";

        do 
        {
            entrada = MyIO.readLine();
            if( !isEquals( entrada, "0" ) )
            {
                if( solveEquation( entrada ) )
                {
                    MyIO.println( "1" );
                }
                else
                {
                    MyIO.println( "0" );
                } // end if
            } // end if
        } while ( !isEquals( entrada, "0" ) ); // end do while
    } // end main ( )

    /**
     *  Funcao para tratar a expressao para fazer a algebra booleana.
     *  @param input - String.
     *  @return String tratada.
     */
    public static String treatment( String input )
    {
        String expressao = "";
        int n = 0;

        n = input.charAt(0) - 48; // capturar quantos bits serao utilizados

        expressao = removeBlank( input );                              // remover espacos em branco
        expressao = replaceAll( "and", 'a', expressao );  // trocar "and" por 'a'
        expressao = replaceAll( "or" , 'o', expressao  ); // trocar "or" por 'o'
        expressao = replaceAll( "not", 'n', expressao );  // trocar "not" por 'n'

        // trocar 'A', 'B' e 'C' por seus respectivos bits
        for( int x = 0; x < n; x = x + 1 )
        {
            char c = (char)('A'+x);
            char newC = expressao.charAt(x+1); 
            expressao = replaceAll( c, newC, expressao );
        } // end for
        
        // pegar apenas a expressao logica
        expressao = subString(expressao, n+1, expressao.length() );

        return ( expressao );
    } // end algebraBooleana ( )

    /**
     *  Funcao para identificar e resolver a expressao.
     *  @param input - String.
     *  @return String: expressao resolvida.
     */
    public static String solveExp( String input )
    {
        int inputLen = input.length();
        char operation = input.charAt( 0 );
        boolean flag = true;
        switch( operation ) 
        {
            case 'a':
                flag = true;
                for( int y = 2; y < inputLen && flag; y = y + 1 )
                {
                    if( input.charAt(y) == '0' )
                    {
                        flag = false;
                        return ( "0" );
                    } // end if
                } // end for
                return ( "1" );
            case 'o':
                flag = false;
                for( int y = 2; y < inputLen && !flag; y = y + 1 )
                {
                    if( input.charAt(y) == '1' )
                    {
                        flag = true;
                        return ( "1" );
                    } // end if
                } // end for
                return ( "0" );
            case 'n':
                if( input.charAt(2) == '0' )
                {
                    return ( "1" );
                }
                else
                {
                    return ( "0" );
                } // end if
            default:
                return ( "" );
        } // end switch
    } // end solveExp ( )

    /**
     *  Funcao para chamar a funcao recursiva solvaEquationRec
     *  @param input - String.
     *  @return String: equacao resolvida.
     */
    public static boolean solveEquation( String input )
    {
        String expressao = treatment( input );
        return ( solveEquationRec( expressao ) );
    } // end solve Equation

    /**
     *  Funcao para resolver toda a equacao.
     *  @param input - String.
     *  @return String: equacao resolvida.
     */
    public static boolean solveEquationRec( String input )
    {
        if( input.contains( "(" ) )
        {
            int start = input.lastIndexOf( '(' );
            int end   = input.indexOf( ')', start );
            
			String subExp = subString( input, start-1, end+1 );			
			String resultString = solveExp( subExp );

            input = subString( input, 0, start-1 ) + 
                        resultString + 
                        subString( input, end+1, input.length() );	

            return ( solveEquationRec( input ) );
        } 
        else
        {
            return ( isEquals(input, "1") );   
        }// end if
    } // end solveEquationRec ( )

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
        for( int x = start; x < end && x < s.length(); x = x + 1 )
        {
            result += s.charAt(x);
        } // end for
        return ( result );
    } // end subString ( )

    /**
     *  Funcao para remover os espacos em branco na string.
     *  @param input - String.
     *  @return String sem espacos sem branco.
     */
    public static String removeBlank( String input )
    {
        String result = "";
        for( int x = 0; x < input.length(); x = x + 1 )
        {
            if( input.charAt(x) != ' ' )
            {
                result = result + input.charAt(x);
            } // end if
        } // end for
        return ( result );
    } // end removeBlank ( )

    /**
     *  Funcao para substituir uma ocorrencia de string por um caractere.
     *  @param base - Object: ocorrencia a ser trocada.
     *  @param newChar - Char: Novo caractere.
     *  @param input - String.
     *  @return String alterada.
     */
    public static String replaceAll( Object base, char newChar, String input ) 
    {
		String result = "";
		int inputLen = input.length();
        String baseString = base.toString();
		int baseLen = baseString.length();
		for( int x = 0; x < inputLen; x = x + 1 ) 
        {
			boolean ok = x < inputLen - baseLen + 1;
            boolean match = isEquals( subString( input, x, x + baseLen ), baseString );
			if( ok && match ) 
            {
				result += newChar;
				x += baseLen - 1;
			} 
            else 
            {
				result += input.charAt(x);
			} // end if
		} // end for
		return ( result );
	} // end replaceAll ( )

} // end class
