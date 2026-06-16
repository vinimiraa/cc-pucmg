public class DoubleLinkedList extends DoubleCell 
{
	private DoubleCell first;
	private DoubleCell last;

	public DoubleLinkedList( ) 
    {
		first = new DoubleCell();
		last = first;
	} // end DOubleLikedList ( )

	public void print ( ) 
    {
		System.out.print( "[ " );
		for( DoubleCell i = first.next; i != null; i = i.next ) {
			System.out.print( " ("+i.data+") " );
		} // end for
		System.out.println( "] " );
	} // end print ( )

	public void printReverse ( ) 
    {
		System.out.print("[ ");
		for( DoubleCell i = last; i != first; i = i.prev ) {
			System.out.print( " ("+i.data+") " );
        } // end for
		System.out.println( "] " );
	} // end printReverse ( )

	public boolean search ( int value ) 
    {
		boolean resp = false;
		for( DoubleCell i = first.next; i != null; i = i.next ) 
        {
            if( i.data == value )
            {
                resp = true;
                i = last;
            } // end if
		} // end for
		return ( resp );
	} // end search ( )

    public int length ( ) 
    {
        int length = 0; 
        for( DoubleCell i = first; i != last; i = i.next, length++ );
        return ( length );
    } // end length ( )

	public void insertFirst ( int value ) 
    {
		DoubleCell tmp = new DoubleCell( value );
        tmp.prev = first;
        tmp.next = first.next;
        first.next = tmp;
        if( first == last ) {
            last = tmp;
        }
        else {
            tmp.next.prev = tmp;
        } // end if
        tmp = null;
	} // end insertFirst ( )

	public void insertLast ( int value ) 
    {
		last.next = new DoubleCell( value );
        last.next.prev = last;
		last = last.next;
	} // end insertLast ( )

	public int removeFirst ( ) throws Exception 
    {
		if( first == last ) {
			throw new Exception("Erro ao remover (vazia)!");
		} // end if

        DoubleCell tmp = first;
		first = first.next;
		int resp = first.data;
        tmp.next = first.prev = null;
        tmp = null;
		return ( resp );
	}

	public int removeLast ( ) throws Exception 
    {
		if( first == last ) {
			throw new Exception( "Erro ao remover (vazia)!" );
		} 
        int resp = last.data;
        last = last.prev;
        last.next.prev = null;
        last.next = null;
		return ( resp );
	} // end removeLast ( )

    public void insert ( int value, int index ) throws Exception 
    {
        int length = length( );
        if( index < 0 || index > length ) {
			throw new Exception( "Erro ao inserir posicao (" + index + " / length = " + length + ") invalida!" );
        } else if( index == 0 ) {
            insertFirst( value );
        } else if( index == length ) {
            insertLast( value );
        } 
        else 
        {
	        // Caminhar ate a posicao anterior a insercao
            DoubleCell i = first;
            for( int j = 0; j < index; j++, i = i.next );
        
            DoubleCell tmp = new DoubleCell( value );
            tmp.prev = i;
            tmp.next = i.next;
            tmp.prev.next = tmp.next.prev = tmp;
            tmp = i = null;
        } // end if
    } // end insert ( )

	public int remove ( int index ) throws Exception 
    {
        int resp;
        int length = length( );
		if( first == last ) {
			throw new Exception( "Erro ao remover (vazia)!" );
        } else if( index < 0 || index >= length ) {
            throw new Exception( "Erro ao remover (posicao " + index + " / " + length + " invalida!" );
        } else if( index == 0 ) {
            resp = removeFirst( );
        } else if( index == length - 1 ) {
            resp = removeLast( );
        } 
        else 
        {
	    	// Caminhar ate a posicao anterior a insercao
            DoubleCell i = first.next;
            for(int j = 0; j < index; j++, i = i.next);
        
            i.prev.next = i.next;
            i.next.prev = i.prev;
            resp = i.data;
            i.next = i.prev = null;
            i = null;
        } // end if
		return ( resp );
	} // end remove ( )
} // end class 
