public class Selection extends Generate
{
    public Selection ( )
    {
        super ( );
    }

    public Selection ( int length )
    {
        super( length );
    }

    /**
     *  <p>Selection Sort é um algoritmo de ordenação que divide a lista em duas partes:
     *  uma parte ordenada e outra não ordenada. Ele seleciona repetidamente o menor
     *  elemento da parte não ordenada e o move para o final da parte ordenada.</p>
     *  
     *  <p>Complexidade: O(n^2) no pior caso.             </p> 
     *  <p>Número de comparações: O(n^2). -> n^2/2 - n/2  </p>
     *  <p>Número de movimentações: O(n). -> 3(n-1)       </p>
     */
    @Override
    public void sort( MyLog log ) 
    {
        for( int i = 0; i < length - 1; i++ ) 
        {
            int minIndex = i;
            log.incrementMoves();
            for( int j = i + 1; j < length; j++ ) 
            {
                if( array[j] < array[minIndex] ) {
                    minIndex = j;
                    log.incrementComparisons();
                    log.incrementMoves();
                } // end if
            } // end for
            swap( i, minIndex );
            log.incrementMoves(3);
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Selection array = new Selection( 100 );
        MyLog log = new MyLog();

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
}
