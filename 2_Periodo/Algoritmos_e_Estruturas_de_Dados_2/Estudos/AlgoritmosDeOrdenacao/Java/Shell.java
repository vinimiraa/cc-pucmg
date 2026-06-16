public class Shell extends Generate 
{
    public Shell ( )
    {
        super ( );
    }

    public Shell ( int length )
    {
        super( length );
    }

    /**
     * <p>Algoritmo de Inserção modificado para ser utilizado no ShellSort.</p>
     *  
     *  @param startIndex : posição inicial do sub-arranjo.
     *  @param gap : valor do intervalor entre sub-arranjos.
     */
    void insertion( int startIndex, int gap, MyLog log )
    {
        for( int i = ( gap + startIndex ); i < length; i = i + gap ) 
        {
            int key = array[i];
            int j = i - gap;
            log.incrementMoves(2);
            while( ( j >= 0 ) && ( array[j] > key ) ) 
            {
                array[j+gap] = array[j];
                j = j - gap;
                log.incrementMoves(2);
                log.incrementComparisons();
            } // end while
            log.incrementComparisons();
            array[j+gap] = key;
            log.incrementMoves();
        } // end for
    } // insertion ( )

    /**
     *  <p>Shell Sort é uma melhoria do Insertion Sort, que compara elementos
     *  distanciados por um intervalo maior e então reduz gradualmente esse
     *  intervalo. Isso produz uma lista quase ordenada, facilitando a ordenação
     *  final.</p>
     * 
     *  <p>Complexidade: Depende do intervalo escolhido. Melhor caso é O(n*log(n)), médio e pior caso variam. </p>
     *  <p>Número de comparações e movimentações: Geralmente menor do que o Insertion Sort.                   </p> 
     */
    @Override
    public void sort( MyLog log ) 
    {
        int gap = 1;
        do { 
            gap = (gap * 3) + 1; 
            log.incrementMoves();
            log.incrementComparisons();
        } while( gap < length ); // end do while
        do 
        {
            gap = gap / 3;
            log.incrementMoves();
            for( int startIndex = 0; startIndex < gap; startIndex = startIndex + 1 ) {
                insertion( startIndex, gap, log );
            } // end for
            log.incrementComparisons();
        } while( gap != 1 ); // end do while
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Shell array = new Shell( 100 );
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
