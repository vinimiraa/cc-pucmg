public class LinkedStack 
{
	private SimpleCell topo;

	public LinkedStack ( ) {
		topo = null;
	} // end LinkedStack ( )

	public void insert ( int x ) 
	{
		SimpleCell tmp = new SimpleCell(x);
		tmp.next = topo;
		topo = tmp;
		tmp = null;
	} // end insert ( )

	public int remove ( ) throws Exception 
	{
		if( topo == null ) {
			throw new Exception("Erro ao remover!");
		} // end if
		int resp = topo.data;
		SimpleCell tmp = topo;
		topo = topo.next;
		tmp.next = null;
		tmp = null;
		return ( resp );
	} // end remove ( )

	public void print ( ) 
	{
		System.out.print("[ ");
		for( SimpleCell i = topo; i != null; i = i.next ) {
			System.out.print( " ("+i.data+") " );
		}
		System.out.println("] ");
	} // end print ( )

	public int getSum ( ) {
		return getSum( topo );
	} // end getSum ( )

	private int getSum ( SimpleCell i ) 
	{
		int resp = 0;
		if( i != null ) {
			resp += i.data + getSum(i.next);
		} // end if
		return ( resp );
	} // end getSum ( )

	public int getMax ( ) 
	{
		int max = topo.data;
		for(SimpleCell i = topo.next; i != null; i = i.next )
		{
			if( i.data > max ) {
				max = i.data;
			} // end if
		} // end for
		return ( max );
	} // end getMax ( )

	public void printStack( ) {
		printStack( topo );
	} // end printStack ( )

	private void printStack( SimpleCell i ) 
	{
		if( i != null ) 
		{
			printStack( i.next );
			System.out.println( "" + i.data );
		} // end if
	} // end printStack 
} // end class 