import aed3.*;

public class ArquivoCliente extends aed3.Arquivo<Cliente> {

    Arquivo<Cliente> arqClientes;
    HashExtensivel<ParCPFID> indiceIndiretoCPF;

    public ArquivoCliente() throws Exception {
        super("clientes", Cliente.class.getConstructor());
        indiceIndiretoCPF = new HashExtensivel<>(
            ParCPFID.class.getConstructor(), 
            4, 
            ".\\dados\\indiceCPF.hash_d.db", 
            ".\\dados\\indiceCPF.hash_c.db"
        );
    }

    @Override
    public int create(Cliente c) {
        int id = super.create(c);
        indiceCPF.create(c.getCPF(), id);
        return id;
    }
    
}
