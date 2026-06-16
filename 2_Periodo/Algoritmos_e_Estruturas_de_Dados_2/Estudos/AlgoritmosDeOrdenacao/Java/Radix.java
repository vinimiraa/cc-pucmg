public class Radix extends Generate 
{
    public Radix ( )
    {
        super ( );
    }

    public Radix ( int length )
    {
        super( length );
    }

    public int getLargest ( MyLog log ) 
    {
        int result = array[0];
        for( int i = 0; i < length; i++ ) 
        {
            if( result < array[i] ) {
                result = array[i];
                log.incrementComparisons();
                log.incrementMoves();
            }
        }
        return ( result );	
    } // end getLargest ( )

    public void sort ( int exp, MyLog log ) 
    {
        int[] count = new int[10];
        int[] output = new int[length];
        log.incrementSubArrays(2);
        //Inicializar cada posicao do array de contagem 
        for( int i = 0; i < 10; count[i] = 0, log.incrementMoves(), i++);

        //Agora, o count[i] contem o numero de elemento iguais a i
        for( int i = 0; i < length; i++ ) {
            count[(array[i]/exp) % 10]++;
            log.incrementComparisons();
        }

        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for( int i = 1; i < 10; i++ ) {
            count[i] += count[i-1];
            log.incrementMoves();
        }

        //Ordenando
        for( int i = length-1; i >= 0; i-- ) {
            output[count[(array[i]/exp) % 10] - 1] = array[i];
            count[(array[i]/exp) % 10]--;
            log.incrementComparisons();
            log.incrementMoves();
        }

        //Copiando para o array original
        for( int i = 0; i < length; i++ ) {
            array[i] = output[i];
            log.incrementMoves();
        }
    } // end sort ( )

    @Override
    public void sort ( MyLog log ) 
    {
        int max = getLargest( log );
        log.incrementMoves();
        for( int exp = 1; max/exp > 0; exp *= 10 ) {
            sort( exp, log );
        }
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Radix array = new Radix( 100 );
        MyLog log = new MyLog();

        array.fillDescending();

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
