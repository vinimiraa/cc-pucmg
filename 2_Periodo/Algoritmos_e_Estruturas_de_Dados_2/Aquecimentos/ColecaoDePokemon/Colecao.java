/*  -------------------------- Documentacao
*  Pontificia Universidade Catolica de Minas Gerais
*  Curso de Ciencia da Computacao
*  Algoritmos e Estruturas de Dados II
*   
*  Colecao de Pokemon - Warm-Up - 18 / 03 / 2024
*  Author: Vinicius Miranda de Araujo
*   
*  Para compilar em terminal (janela de comandos):
*       Linux : javac Colecao.java
*       Windows: javac Colecao.java
*   
*  Para executar em terminal (janela de comandos):
*       Linux : java Colecao
*       Windows: java Colecao
*   
*/

public class Colecao
{
    /**
     *  Funcao principal.
     *  @param args
     */
    public static void main ( String[ ] args )
    {
        int quantidade = 0;
        String[] pokemonsCapturados;
        int total = 151;

        // ler a quantidade e criar um arranjo
        quantidade = MyIO.readInt();
        pokemonsCapturados = new String[quantidade];

        // ler o nome do pokemon e guardar no arranjo
        for( int x = 0; x < quantidade; x = x + 1 )
        {
            String nomePokemon = MyIO.readLine();
            pokemonsCapturados[x] = nomePokemon;
        } // end for

        // odernar o arranjo
        insertionSort( pokemonsCapturados );

        // subtrair do total, e, se for igual, enquanto for igual nao subtraio
        for( int x = 1; x < quantidade; x = x + 1 )
        {
            int y = x;
            while( (y < quantidade) && ( pokemonsCapturados[y].equals(pokemonsCapturados[y - 1]) ) )
            {
                y++;
            } // end while
            x = y;
            total--;
        } // end for

        MyIO.println( "Falta(m) " + total + " pomekon(s)." );
    } // end main ( )

    /**
     *  Funcao para ordenar strings em ordem crescente.
     *  @param array - Arranjo de strings.
     */
    private static void insertionSort( String[] array )
    {
        for( int x = 1; x < array.length; x = x + 1 ) 
        {
            String temp = array[x];
            int y = x - 1;
            while( (y >= 0) && (array[x].compareTo(temp) > 0) )
            {
                array[y + 1] = array[y];
                y--;
            } // end while
            array[y + 1] = temp;
        } // end for
    } // end insertionSort ( )
    
} // end class
