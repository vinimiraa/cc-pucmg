public class Test_List extends List {
    public static void main(String[] args) throws Exception 
    {
        System.out.println("==== LISTA LINEAR ====");
        List lista = new List();
        int x1, x2, x3;

        lista.insertFirst(1);
        lista.insertFirst(0);
        lista.insertLast(2);
        lista.insertLast(3);
        lista.insert(4, 3);
        lista.insert(5, 2);

        System.out.print("Apos insercoes: ");
        lista.print();

        x1 = lista.removeFirst( );
        x2 = lista.removeLast( );
        x3 = lista.remove(2);

        System.out.print("Apos remocoes (" + x1 + ", " + x2 + ", " + x3 + "):");
        lista.print();
    } // end main ( )
} // end class
