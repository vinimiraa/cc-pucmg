public class LinkedQueue extends SimpleCell
{
	private SimpleCell first;
	private SimpleCell last;

	public LinkedQueue ( ) 
    {
		first = new SimpleCell( );
		last = first;
	} // end LinkedQueue ( )

	public void insert ( int x ) 
    {
		last.next = new SimpleCell(x);
		last = last.next;
	} // end insert ( )

	public int remove ( ) throws Exception 
    {
		if( first == last ) {
			throw new Exception( "Erro ao remover!" );
		} // end if
        SimpleCell tmp = first;
		first = first.next;
		int resp = first.data;
        tmp.next = null;
        tmp = null;
		return ( resp );
	} // end remove ( )

	public void print ( ) 
    {
		System.out.print( "[ " );
		for( SimpleCell i = first.next; i != null; i = i.next ) {
			System.out.print( " ("+i.data+") " );
		}
		System.out.println( "] " );
	} // end print ( )
} // end class

