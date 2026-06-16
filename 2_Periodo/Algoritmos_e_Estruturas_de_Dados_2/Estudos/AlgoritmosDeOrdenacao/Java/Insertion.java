public class Insertion extends Generate 
{
    public Insertion ( )
    {
        super ( );
    }

    public Insertion ( int length )
    {
        super( length );
    }

    /**
     *  <p>Insertion Sort é um algoritmo de ordenação que constrói uma lista ordenada
     *  um item por vez, movendo cada novo item para a posição correta na lista
     *  ordenada.</p> 
     *  
     *  <p>Complexidade: O(n^2) no pior caso, O(n) no melhor caso. </p>
     *  <p>Número de comparações: O(n^2).                          </p>
     *  <p>Número de movimentações: O(n^2).                        </p>
     */
    @Override
    public void sort( MyLog log )
    {
        for( int i = 1; i < length; i = i + 1 ) 
        {
            int key = array[i];
            int j = i - 1;
            while( ( j >= 0 ) && ( array[j] > key ) ) 
            {
                array[j+1] = array[j]; // deslocamento
                log.incrementMoves();
                j--;
                log.incrementComparisons();
            } // end while
            log.incrementComparisons();
            array[j+1] = key;
            log.incrementMoves();
        } // end for
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Insertion array = new Insertion( 100 );
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
