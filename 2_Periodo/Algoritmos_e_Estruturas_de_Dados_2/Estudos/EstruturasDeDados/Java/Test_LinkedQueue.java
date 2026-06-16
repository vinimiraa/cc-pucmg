
class Test_LinkedQueue 
{
    public static void main(String[] args) throws Exception 
    {
        System.out.println("==== FILA FLEXIVEL ====");
        LinkedQueue fila = new LinkedQueue();
        int x1, x2, x3;

        fila.insert(5);
        fila.insert(7);
        fila.insert(8);
        fila.insert(9);

        System.out.println("Apos insercoes(5, 7, 8, 9): ");
        fila.print();

        x1 = fila.remove();
        x2 = fila.remove();

        System.out.println("Apos remocoes (" + x1 + ", " + x2 + "):");
        fila.print();

        fila.insert(3);
        fila.insert(4);

        System.out.println("Apos insercoes(3, 4): ");
        fila.print();

        x1 = fila.remove();
        x2 = fila.remove();
        x3 = fila.remove();

        System.out.println("Apos remocoes (" + x1 + ", " + x2 + ", " + x3 + "):");
        fila.print();

        fila.insert(4);
        fila.insert(5);

        System.out.println("Apos insercoes(4, 5): ");
        fila.print();

        x1 = fila.remove();
        x2 = fila.remove();

        System.out.println("Apos remocoes (" + x1 + ", " + x2 + "):");
        fila.print();

        fila.insert(6);
        fila.insert(7);

        System.out.println("Apos insercoes(6, 7): ");
        fila.print();

        x1 = fila.remove();

        System.out.println("Apos remocao (" + x1 + "): ");
        fila.print();
    } // end main ( )
} // end class