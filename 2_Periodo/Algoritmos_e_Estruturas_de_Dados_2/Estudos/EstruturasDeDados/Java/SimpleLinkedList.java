public class SimpleLinkedList extends SimpleCell
{
    private SimpleCell first;
    private SimpleCell last;

    SimpleLinkedList ( )
    {
        first = new SimpleCell ( );
        last = first;
    } // end LinkedList ( )

	public void print( ) 
    {
		System.out.print("[");
        for( SimpleCell i = first.next; i != null; i = i.next ) {
            System.out.print( " ("+i.data+") " );
        } // end for
        System.out.println("]");
    } // end print ( )

    public boolean search ( int value ) 
    {
        boolean resp = false;
        for( SimpleCell i = first.next; i != null; i = i.next ) 
        {
            if( i.data == value )
            {
                resp = true;
                i = last;
            } // end if
        } // end for
        return ( resp );
    } // end search ( )

    public int length( ) 
    {
        int length = 0; 
        for( SimpleCell i = first; i != last; i = i.next, length++ );
        return ( length );
    } // end length ( )

	public void insertFirst ( int value ) 
    {
		SimpleCell temp = new SimpleCell(value);
        temp.next = first.next;
		first.next = temp;
		if( first == last ) {                 
			last = temp;
		} // end if
        temp = null;
	} // end insertFirst ( )

	public void insertLast ( int value ) 
    {
		last.next = new SimpleCell( value );
		last = last.next;
	} // end insertLast ( )

	public int removeFirst ( ) throws Exception 
    {
		if( first == last ) {
			throw new Exception( "Erro ao remover (vazia)!" );
		} // end if

        SimpleCell temp = first;
		first = first.next;
		int resp = first.data;
        temp.next = null;
        temp = null;
		return ( resp );
	} // end remmoveFirst ( )

	public int removeLast ( ) throws Exception 
    {
		if( first == last ) {
			throw new Exception( "Erro ao remover (vazia)!" );
		} // end if

		// Caminhar ate a penultima celula:
        SimpleCell i;
        for( i = first; i.next != last; i = i.next );

        int resp = last.data; 
        last = i; 
        i = last.next = null;
        
		return ( resp );
	} // end removeLast ( )

    public void insert ( int value, int index ) throws Exception 
    {
        int tamanho = length( );

        if( index < 0 || index > tamanho ) {
            throw new Exception( "Erro ao inserir posicao (" + index + " / tamanho = " + tamanho + ") invalida!" );
        } else if( index == 0 ) {
            insertFirst( value );
        } else if( index == tamanho ) {
            insertLast( value );
        } 
        else 
        {
	    	// Caminhar ate a posicao anterior a insercao
            SimpleCell i = first;
            for(int j = 0; j < index; j++, i = i.next);
        
            SimpleCell temp = new SimpleCell(value);
            temp.next = i.next;
            i.next = temp;
            temp = i = null;
        } // end if
    } // end insert ( )

	public int remove ( int index ) throws Exception 
    {
        int resp = -1;
        int tamanho = length( );

        if( first == last ) {
            throw new Exception( "Erro ao remover (vazia)!" );
        } else if( index < 0 || index >= tamanho ) {
            throw new Exception( "Erro ao remover (posicao " + index + " / " + tamanho + " invalida!" );
        } else if( index == 0 ) {
            resp = removeFirst( );
        } else if( index == tamanho - 1 ) {
            resp = removeLast( );
        } 
        else 
        {
            // Caminhar ate a posicao anterior a insercao
            SimpleCell i = first;
            for( int j = 0; j < index; j++, i = i.next );
            
            SimpleCell temp = i.next;
            resp = temp.data;
            i.next = temp.next;
            temp.next = null;
            i = temp = null;
        } // end if

		return ( resp );
	} // end remove ( )

} // end class
