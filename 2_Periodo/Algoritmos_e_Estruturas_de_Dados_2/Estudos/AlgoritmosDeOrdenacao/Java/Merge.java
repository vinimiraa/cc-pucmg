public class Merge extends Generate 
{
    public Merge ( )
    {
        super ( );
    }

    public Merge ( int length )
    {
        super( length );
    }

    /**
     *  Algoritmo que intercala os elementos entre as posicoes left e right
     *  @param int left inicio do array a ser ordenado
     *  @param int mid posicao do mid do array a ser ordenado
     *  @param int right fim do array a ser ordenado
     */ 
    public void intercalar ( int left, int mid, int right, MyLog log )
    {
        int n1, n2, i, j, k;

        //Definir tamanho dos dois subarrays
        n1 = mid-left+1;
        n2 = right - mid;

        int[] a1 = new int[n1+1];
        int[] a2 = new int[n2+1];
        log.incrementSubArrays(2);
        //Inicializar primeiro subarray
        for( i = 0; i < n1; i++ ) {
            a1[i] = array[left+i];
            log.incrementMoves();
        }
        
        //Inicializar segundo subarray
        for( j = 0; j < n2; j++ ) {
            a2[j] = array[mid+j+1];
            log.incrementMoves();
        }

        //Sentinela no final dos dois arrays
        a1[i] = a2[j] = 0x7FFFFFFF;
        log.incrementMoves(2);

        //Intercalacao propriamente dita
        for( i = j = 0, k = left; k <= right; k++ ) {
            array[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
            log.incrementMoves();
            log.incrementComparisons();
        }
    } // end intercalar ( )

    /**
     * Algoritmo de ordenacao Mergesort.
     * @param int left inicio do array a ser ordenado
     * @param int right fim do array a ser ordenado
     */
    private void mergesort (int left, int right, MyLog log ) 
    {
        if( left < right )
        {
            log.incrementComparisons();
            int mid = (left + right) / 2;
            log.incrementMoves();
            mergesort( left, mid, log );
            mergesort( mid + 1, right, log );
            intercalar( left, mid, right, log );
        }
    } // end mergesort ( )

    @Override
    public void sort( MyLog log ) 
    {
        mergesort(0, length-1, log);
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Merge array = new Merge( 100 );
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
