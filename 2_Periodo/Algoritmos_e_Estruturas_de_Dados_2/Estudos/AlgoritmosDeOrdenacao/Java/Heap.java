public class Heap extends Generate 
{
    public Heap ( )
    {
        super ( );
    }

    public Heap ( int length )
    {
        super( length );
    }

    public void build ( int size, MyLog log )
    {
        for( int i = size; i > 1 && array[i] > array[i/2]; i /= 2 ) {
            swap( i, i/2 );
            log.incrementMoves(3);
            incrementComparisons();
        }
    } // end build ( )

    public void rebuild ( int size, MyLog log )
    {
        int i = 1;
        while( i <= (size/2) )
        {
            incrementComparisons();
            int child = getLargestChild( i, size, log );
            if( array[i] < array[child] )
            {
                swap(i, child);
                i = child;
                incrementMoves(4);
                incrementComparisons();
            }
            else {
                i = size;
            }
        }
    } // end rebuild ( )

    public int getLargestChild ( int i, int size, MyLog log )
    {
        int child = -1;
        int left = 2*i;
        int right = 2*i+1;
        if( left == size || array[left] > array[right] ) {
            child = left;
            log.incrementComparisons();
        } 
        else {
            child = right;
            log.incrementComparisons();
        }
        log.incrementComparisons();
        return ( child );
    } // end getLargestChild ( )

    @Override
    public void sort( MyLog log ) 
    {
        //Alterar o vetor ignorando a posicao zero
        int[] temp = new int[length+1];
        log.incrementSubArrays();
        for( int i = 0; i < length; i++ ) {
            temp[i+1] = array[i];
            log.incrementMoves();
        }
        array = temp;

        //Contrucao do heap
        for( int size = 2; size <= length; size++ ) {
            build ( size, log );
        }

        //Ordenacao propriamente dita
        int size = length;
        while( size > 1 )
        {
            log.incrementComparisons();
            swap( 1, size-- );
            log.incrementMoves(3);
            rebuild ( size, log );
        } 

        //Alterar o vetor para voltar a posicao zero
        temp = array;
        array = new int[length];
        log.incrementMoves(2);
        for( int i = 0; i < length; i++ ) {
            array[i] = temp[i+1];
            log.incrementMoves();
        }
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Heap array = new Heap( 100 );
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
}
