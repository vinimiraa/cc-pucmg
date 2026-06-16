import java.io.File;
import java.time.LocalDate;


public class IO {

public static void main(String[] args) {
    ArquivoCliente arqClientes;
    Cliente c1 = new Cliente("José Alves", "12345678901", 3245.21F, LocalDate.of(1998, 4, 21));
    Cliente c2 = new Cliente("Ana Rodrigues", "09876543210", 4267.98F, LocalDate.of(2003, 8, 15));
    Cliente c3 = new Cliente("Carlos Mourão", "56439593721", 2854.23F, LocalDate.of(2001, 1, 7));

try {

    // apaga o arquivo atual
    (new File(".\\dados\\clientes.db")).delete();
    (new File(".\\dados\\clientes.hash_d.db")).delete();
    (new File(".\\dados\\clientes.hash_c.db")).delete();


    arqClientes = new ArquivoCliente();
    arqClientes.create(c1);
    arqClientes.create(c2);
    arqClientes.create(c3);

    System.out.println("\nOperação 1: Ler o cliente de ID 3");
    Cliente c = arqClientes.read(3);
    if(c!=null)
        System.out.println(c);
    else  
        System.out.println("\nCliente não encontrado!");

    System.out.println("\nOperação 2: Ler o cliente de ID 1");
    c = arqClientes.read(1);
    if(c!=null)
        System.out.println(c);
    else  
        System.out.println("\nCliente não encontrado!");

    System.out.println("\nOperação 3: Alterar o nome do cliente de ID 2");
    c2.nome = "Mariana Rodrigues";
    arqClientes.update(c2);
    c = arqClientes.read(2);
    if(c!=null)
        System.out.println(c);
    else  
        System.out.println("\nCliente não encontrado!");

    System.out.println("\nOperação 4: Apagar o cliente de ID 1");
    arqClientes.delete(1);
    c = arqClientes.read(1);
    if(c!=null)
        System.out.println(c);
    else  
        System.out.println("\nCliente não encontrado!");

    arqClientes.close();

} catch(Exception e) {
    e.printStackTrace();
}

}

}