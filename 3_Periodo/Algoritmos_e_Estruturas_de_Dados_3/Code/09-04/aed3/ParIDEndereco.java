package aed3;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class ParIDEndereco implements aed3.RegistroHashExtensivel<ParIDEndereco> {
    
    private int id;   // chave
    private long endereco;    // valor
    private final short TAMANHO = 12;  // tamanho em bytes

    public ParIDEndereco() {
        this.id = -1;
        this.endereco = -1;
    }

    public ParIDEndereco(int id, long end) {
        this.id = id;
        this.endereco = end;
    }

    public int getId() {
        return id;
    }

    public long getEndereco() {
        return endereco;
    }

    @Override
    public int hashCode() {
        return this.id;
    }

    public short size() {
        return this.TAMANHO;
    }

    public String toString() {
        return "("+this.id + ";" + this.endereco+")";
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(this.id);
        dos.writeLong(this.endereco);
        return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        this.id = dis.readInt();
        this.endereco = dis.readLong();
    }

}
