public class Test_LinkedStack 
{
	public static void main ( String[] args ) 
    {
		try {
			System.out.println(" ==== PILHA FLEXIVEL ====");
			LinkedStack pilha = new LinkedStack();
            int x1, x2, x3;

			pilha.insert(0);
			pilha.insert(1);
			pilha.insert(2);
			pilha.insert(3);
			pilha.insert(4);
			pilha.insert(5);

			System.out.print("Apos insercoes: ");
			pilha.print();

			x1 = pilha.remove();
			x2 = pilha.remove();
			x3 = pilha.remove();

			System.out.print("Apos as remocoes (" + x1 + "," + x2 + "," + x3 + "): ");
			pilha.print();

		}
		catch(Exception erro) {
			System.out.println(erro.getMessage());
		}
	} // end main ( )
} // end class

