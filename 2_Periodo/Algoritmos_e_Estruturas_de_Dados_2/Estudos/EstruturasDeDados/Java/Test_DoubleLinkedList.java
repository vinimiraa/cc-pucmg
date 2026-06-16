public class Test_DoubleLinkedList extends DoubleLinkedList
{
	public static void main( String[] args ) 
    {
		try {
			System.out.println("=== LISTA FLEXIVEL DUPLAMENTE ENCADEADA ===");
			DoubleLinkedList lista = new DoubleLinkedList( );

			System.out.print("Ao criar: ");
			lista.print();

			lista.insertFirst(1);
			lista.insertFirst(0);
			lista.insertLast(4);
			lista.insertLast(5);
			lista.insert(2, 2);
			lista.insert(3, 3);
			lista.insert(6, 6);
			lista.insert(-1, 0);
			lista.insertLast(7);
			lista.insertLast(8);

			System.out.print("Apos insercoes: ");
			lista.print();

			int x1 = lista.remove(3);
			int x2 = lista.remove(2);
			int x3 = lista.removeLast();
			int x4 = lista.removeFirst();
			int x5 = lista.remove(0);
			int x6 = lista.remove(4);
			lista.insertLast(9);

			System.out.print( "Apos remocoes (" +x1+ ", " +x2+ ", " +x3+ ", " +x4+ ", " +x5+ ", " +x6+ "): " );
			lista.print();
		} // end try
		catch( Exception erro ) {
			System.out.println( erro.getMessage( ) );
		} // end catch 
	} // end main ( )
} // end class

