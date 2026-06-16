import java.time.LocalDate;

import aed3.Registro;

import java.io.IOException;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;

public class Cliente implements Registro {

    public int id;
    public String nome;
    public String cpf;
    public float salario;
    public LocalDate nascimento;
    public int idCategoria;

    public Cliente() {
        this(-1, "", "", 0F, LocalDate.now(), -1);
    }
    public Cliente(String n, String c, float s, LocalDate d, int t) {
        this(-1, n, c, s, d, t);
    }

    public Cliente(int i, String n, String c, float s, LocalDate d, int t) {
        this.id = i;
        this.nome = n;
        this.cpf = c;
        this.salario = s;
        this.nascimento = d;
        this.idCategoria = t;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public String getCpf() {
        return cpf;
    }

    public String toString() {
        return "\nID........: " + this.id +
               "\nNome......: " + this.nome +
               "\nCPF.......: " + this.cpf +
               "\nSalário...: " + this.salario +
               "\nNascimento: " + this.nascimento +
               "\nCategoria.: " + this.idCategoria;
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(this.id);
        dos.writeUTF(this.nome);
        dos.write(this.cpf.getBytes());
        dos.writeFloat(this.salario);
        dos.writeInt((int) this.nascimento.toEpochDay());
        dos.writeInt(this.idCategoria);
        return baos.toByteArray();
    }


    public void fromByteArray(byte[] b) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(b);
        DataInputStream dis = new DataInputStream(bais);

        byte[] cpf = new byte[11];
        this.id = dis.readInt();
        this.nome = dis.readUTF();
        dis.read(cpf);
        this.cpf = new String(cpf);
        this.salario = dis.readFloat();
        this.nascimento = LocalDate.ofEpochDay(dis.readInt());
        this.idCategoria = dis.readInt();
    }
}
