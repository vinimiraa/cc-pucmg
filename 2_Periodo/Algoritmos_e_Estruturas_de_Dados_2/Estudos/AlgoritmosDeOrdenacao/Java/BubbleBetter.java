public class BubbleBetter extends Generate
{
    public BubbleBetter ( )
    {
        super ( );
    }

    public BubbleBetter ( int length )
    {
        super( length );
    }

    /**
     *  <p>Bubble Sort é um algoritmo de ordenação simples, que percorre repetidamente
     *  a lista, compara elementos adjacentes e os troca se estiverem na ordem
     *  errada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    @Override
    public void sort ( MyLog log )
    {
        boolean swapped = true;
        for( int i = 0; i < length-1 && swapped; i++ )
        {
            swapped = false;
            for( int j = 0; j < length-i-1; j++ )
            {
                if( array[j] > array[j+1] )
                {
                    swap( j, j+1 );
                    log.incrementMoves(3);
                    log.incrementComparisons();
                    swapped = true;
                } // end if
            } // end for
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        BubbleBetter array = new BubbleBetter( 100 );
        MyLog log = new MyLog( );

        array.fillRandom();

        System.out.println("\nArray antes de ordenar:");
        array.print();

        log.startTimer();
        array.sort( log );
        log.endTimer();

        System.out.println("\nArray após ordenar:");
        array.print();

        log.printMetrics();
    } // end main ( )
} // end class

