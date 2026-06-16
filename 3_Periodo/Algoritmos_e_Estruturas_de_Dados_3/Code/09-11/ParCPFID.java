import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class ParCPFID implements aed3.RegistroHashExtensivel<ParCPFID> {
    
    private String cpf; // chave
    private int id;     // valor
    private final short TAMANHO = 15;  // tamanho em bytes

    public ParCPFID() {
        this.cpf = "00000000000";
        this.id = -1;
    }

    public ParCPFID(String cpf, int id) throws Exception {
        // Certifique-se de que o CPF contém exatamente 11 dígitos
        if (cpf.length() != 11 || !cpf.matches("\\d{11}")) {
            throw new IllegalArgumentException("CPF deve conter exatamente 11 dígitos numéricos.");
        }
        this.cpf = cpf;
        this.id = id;
    }

    public String getCpf() {
        return cpf;
    }

    public int getId() {
        return id;
    }

 
    @Override
    public int hashCode() {
        return hash(this.cpf);
    }

    public short size() {
        return this.TAMANHO;
    }

    public String toString() {
        return "("+this.cpf + ";" + this.id+")";
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.write(this.cpf.getBytes());
        dos.writeInt(this.id);
        return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        byte[] b = new byte[11];
        dis.read(b);
        this.cpf = new String(b);
        this.id = dis.readInt();
    }

    public static int hash(String cpf) throws IllegalArgumentException {
        // Certifique-se de que o CPF contém exatamente 11 dígitos
        if (cpf.length() != 11 || !cpf.matches("\\d{11}")) {
            throw new IllegalArgumentException("CPF deve conter exatamente 11 dígitos numéricos.");
        }

        // Converter o CPF para um número inteiro longo
        long cpfLong = Long.parseLong(cpf);

        // Aplicar uma função de hash usando um número primo grande
        int hashValue = (int) (cpfLong % (int)(1e9 + 7));

        // Retornar um valor positivo
        return Math.abs(hashValue);
    }


}
