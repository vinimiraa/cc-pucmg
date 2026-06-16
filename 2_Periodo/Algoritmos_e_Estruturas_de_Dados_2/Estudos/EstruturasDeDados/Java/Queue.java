public class Queue 
{
    protected int[] array;
    protected int   primeiro; // remover
    protected int   ultimo;   // inserir
        
    Queue( )
    {
        this( 5 );
    } // end Queue ( )
    
    Queue( int length )
    {
        array = new int[length+1];
        primeiro = ultimo = 0;
    } // end Queue ( )
    
    public void print( )
    {
        int x = primeiro;
        System.out.print( "[ " );
        while( x != ultimo )
        {
            System.out.print( array[x] + " " );
            x = (x + 1) % array.length;
        } // end while
        System.out.println( "]" );
    } // end print ( )

    public void insert( int value ) throws Exception
    {
        if (((ultimo + 1) % array.length) == primeiro)
        {
            throw new Exception("Erro!");
        }
        array[ultimo] = value;
        ultimo = (ultimo + 1) % array.length;
    } // end insert ( )

    public int remove( ) throws Exception
    {
        int value = 0;
        if( primeiro == ultimo )
        {
            throw new Exception("Erro!");
        } // end if
        value = array[primeiro];
        primeiro = (primeiro + 1) % array.length;

        return ( value );
    } // end remove ( )

} // end class 
