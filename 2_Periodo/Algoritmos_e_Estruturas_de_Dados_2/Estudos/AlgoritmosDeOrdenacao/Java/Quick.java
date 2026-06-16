public class Quick extends Generate 
{
    public Quick ( )
    {
        super ( );
    }

    public Quick ( int length )
    {
        super( length );
    }

    /**
     *  <p>Quick Sort é um algoritmo de ordenação eficiente que divide o array em
     *  partições, selecionando um elemento como pivô, e rearranjando os elementos
     *  de modo que os menores que o pivô fiquem à sua esquerda e os maiores à sua
     *  direita.<p>
     *  
     *  <p>Complexidade: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.            </p>
     *  <p>Número de comparações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso.   </p> 
     *  <p>Número de movimentações: O(n*log(n)) no caso médio e melhor caso, O(n^2) no pior caso. </p>
     * 
     *  @param left : primeira posição do arranjo.
     *  @param right : ultima posição do arranjo.
     */
    public void quickSort ( int left, int right, MyLog log ) 
    {
        int i = left, j = right;
        int pivot = array[(left + right)/2];
        log.incrementMoves(3);

        while( i <= j ) 
        {
            log.incrementComparisons();
            while( array[i] < pivot ) {
                i++;
                log.incrementComparisons();
            } // end while
            while( array[j] > pivot ) {
                j--;
                log.incrementComparisons();
            } // end while
            if( i <= j ) {
                log.incrementComparisons();
                swap( i, j );
                log.incrementMoves(3);
                i++;
                j--;
            } // end if
        } // end while
        if( left < j ) {
            quickSort( left, j, log );
            log.incrementComparisons();
        } // end if
        if( i < right ) {
            quickSort( i, right, log );
            log.incrementComparisons();
        } // end if
    } // end quickSort ( )

    @Override
    public void sort ( MyLog log )
    {
        quickSort( 0, length-1, log );
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Quick array = new Quick( 100 );
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
