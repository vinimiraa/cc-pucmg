import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.time.LocalDate;

public class Arquivo {
    final int TAM_CABECALHO = 4;
    RandomAccessFile arquivo;
    String nomeArquivo;

    public Arquivo(String na) throws IOException {
        File d = new File(".\\dados");
        if (!d.exists())
            d.mkdir();

        this.nomeArquivo = ".\\dados\\" + na;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");
        if (arquivo.length() < TAM_CABECALHO) {
            // inicializa o arquivo, criando seu cabecalho
            arquivo.writeInt(0);
        }
    }

    public int create(Cliente c) throws IOException {
        arquivo.seek(0);
        int proximoID = arquivo.readInt() + 1;
        arquivo.seek(0);
        arquivo.writeInt(proximoID);
        c.setId(proximoID);
        arquivo.seek(arquivo.length());
        arquivo.writeInt(c.id);
        arquivo.writeUTF(c.nome);
        arquivo.write(c.cpf.getBytes());
        arquivo.writeFloat(c.salario);
        arquivo.writeInt((int) c.nascimento.toEpochDay());
        return c.id;
    }

    public Cliente read(String cpf) throws IOException {
        Cliente c;
        byte[] aux;
        arquivo.seek(TAM_CABECALHO);
        while (arquivo.getFilePointer() < arquivo.length()) {
            c = new Cliente();
            aux = new byte[11];

            c.id = arquivo.readInt();
            c.nome = arquivo.readUTF();
            arquivo.read(aux);
            c.cpf = new String(aux);
            c.salario = arquivo.readFloat();
            c.nascimento = LocalDate.ofEpochDay(arquivo.readInt());
            if (c.cpf.compareTo(cpf) == 0)
                return c;
        }
        return null;
    }

    public void close() throws IOException {
        arquivo.close();
    }

}
