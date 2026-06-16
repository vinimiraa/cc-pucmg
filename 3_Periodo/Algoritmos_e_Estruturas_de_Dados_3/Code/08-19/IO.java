import java.io.File;
import java.io.IOException;
import java.time.LocalDate;

public class IO {

    public static void main(String[] args) {
        Arquivo arqClientes;
        Cliente c1 = new Cliente("José Alves", "12345678901", 3245.21F, LocalDate.of(1998, 4, 21));
        Cliente c2 = new Cliente("Ana Rodrigues", "09876543210", 4267.98F, LocalDate.of(2003, 8, 15));
        Cliente c3 = new Cliente("Carlos Mourão", "56439593721", 2854.23F, LocalDate.of(2001, 1, 7));

        try {

            // apaga o arquivo atual
            File f = new File("clientes.db");
            f.delete();

            arqClientes = new Arquivo("clientes.db");
            arqClientes.create(c1);
            arqClientes.create(c2);
            arqClientes.create(c3);

            Cliente c = arqClientes.read("56439593721");
            if (c != null)
                System.out.println(c);
            else
                System.out.println("Cliente não encontrado!");

            c = arqClientes.read("12345678901");
            if (c != null)
                System.out.println(c);
            else
                System.out.println("Cliente não encontrado!");

            c = arqClientes.read("24334564234");
            if (c != null)
                System.out.println(c);
            else
                System.out.println("Cliente não encontrado!");

            arqClientes.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}