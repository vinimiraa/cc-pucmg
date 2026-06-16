public class Counting extends Generate 
{
    public Counting ( )
    {
        super ( );
    }

    public Counting ( int length )
    {
        super( length );
    }

    public int getLargest ( ) 
    {
        int result = array[0];
        for( int i = 0; i < length; i++ ) 
        {
            if( result < array[i] ) {
                result = array[i];
            }
        }
        return ( result );	
    } // end getLargest ( )

    @Override
    public void sort( MyLog log  ) 
    {
        //Array para contar o numero de ocorrencias de cada elemento
        int[] count = new int[getLargest( ) + 1];
        int[] ordenado = new int[length];
        log.incrementSubArrays(2);

        //Inicializar cada posicao do array de contagem 
        for( int i = 0; i < count.length; count[i] = 0, i++ );
        
        //Agora, o count[i] contem o numero de elemento iguais a i
        for( int i = 0; i < length; count[array[i]]++, log.incrementMoves(), i++ );

        //Agora, o count[i] contem o numero de elemento menores ou iguais a i
        for( int i = 1; i < count.length; count[i] += count[i-1], log.incrementMoves(), i++ );

        //Ordenando
        for( int i = length-1; i >= 0; ordenado[count[array[i]]-1] = array[i], count[array[i]]--, incrementMoves(), i-- );

        //Copiando para o array original
        for( int i = 0; i < length; array[i] = ordenado[i], incrementMoves(), i++ );
    } // end sort ( )

    public static void main( String[] args ) 
    {
        Counting array = new Counting( 100 );
        MyLog log = new MyLog( );

        array.fillDescending();

        System.out.println("\nArray antes de ordenar:");
        array.print();

        log.startTimer();
        array.sort( log );
        log.endTimer();

        System.out.println("\nArray após ordenar:");
        array.print();

        log.printMetrics( );
    } // end main ( )    
}
