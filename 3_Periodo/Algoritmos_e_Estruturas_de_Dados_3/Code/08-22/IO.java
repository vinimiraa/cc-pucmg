import java.io.File;
import java.time.LocalDate;

public class IO {

    public static void main(String[] args) {
        Arquivo<Cliente> arqClientes;
        Cliente c1 = new Cliente("José Alves", "12345678901", 3245.21F, LocalDate.of(1998, 4, 21));
        Cliente c2 = new Cliente("Ana Rodrigues", "09876543210", 4267.98F, LocalDate.of(2003, 8, 15));
        Cliente c3 = new Cliente("Carlos Mourão", "56439593721", 2854.23F, LocalDate.of(2001, 1, 7));

        try {

            // apaga o arquivo atual
            File f = new File(".\\dados\\clientes.db");
            f.delete();

            arqClientes = new Arquivo<>("clientes.db", Cliente.class.getConstructor());
            arqClientes.create(c1);
            arqClientes.create(c2);
            arqClientes.create(c3);

            Cliente c = arqClientes.read(3);
            if (c != null)
                System.out.println(c);
            else
                System.out.println("\nCliente não encontrado!");

            c = arqClientes.read(1);
            if (c != null)
                System.out.println(c);
            else
                System.out.println("\nCliente não encontrado!");

            c2.nome = "Mariana Rodrigues";
            arqClientes.update(c2);
            c = arqClientes.read(2);
            if (c != null)
                System.out.println(c);
            else
                System.out.println("\nCliente não encontrado!");

            arqClientes.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}