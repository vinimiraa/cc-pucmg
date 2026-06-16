import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

public class Arquivo<T extends Registro> {
    final int TAM_CABECALHO = 4;
    RandomAccessFile arquivo;
    String nomeArquivo;
    Constructor<T> construtor;

    public Arquivo(String na, Constructor<T> c) throws IOException {
        File d = new File(".\\dados");
        if (!d.exists())
            d.mkdir();

        this.nomeArquivo = ".\\dados\\" + na;
        this.construtor = c;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");
        if (arquivo.length() < TAM_CABECALHO) {
            // inicializa o arquivo, criando seu cabecalho
            arquivo.writeInt(0);
        }
    }

    public int create(T obj) throws IOException {
        arquivo.seek(0);
        int proximoID = arquivo.readInt() + 1;
        arquivo.seek(0);
        arquivo.writeInt(proximoID);
        obj.setId(proximoID);
        arquivo.seek(arquivo.length());

        byte[] b = obj.toByteArray();
        arquivo.writeByte(' ');
        arquivo.writeShort(b.length);
        arquivo.write(b);

        return obj.getId();
    }

    public T read(int id) throws Exception {
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        arquivo.seek(TAM_CABECALHO);
        while (arquivo.getFilePointer() < arquivo.length()) {
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if (lapide == ' ') {
                obj.fromByteArray(b);
                if (obj.getId() == id)
                    return obj;
            }
        }
        return null;
    }

    public boolean delete(int id) throws Exception {
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        Long endereco;
        arquivo.seek(TAM_CABECALHO);
        while (arquivo.getFilePointer() < arquivo.length()) {
            obj = construtor.newInstance();
            endereco = arquivo.getFilePointer();
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if (lapide == ' ') {
                obj.fromByteArray(b);
                if (obj.getId() == id) {
                    arquivo.seek(endereco);
                    arquivo.write('*');
                    return true;
                }
            }
        }
        return false;
    }

    public boolean update(T novoObj) throws Exception {
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        Long endereco;
        arquivo.seek(TAM_CABECALHO);
        while (arquivo.getFilePointer() < arquivo.length()) {
            obj = construtor.newInstance();
            endereco = arquivo.getFilePointer();
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if (lapide == ' ') {
                obj.fromByteArray(b);
                if (obj.getId() == novoObj.getId()) {

                    byte[] b2 = novoObj.toByteArray();
                    short tam2 = (short) b2.length;

                    // sobrescreve o registro
                    if (tam2 <= tam) {
                        arquivo.seek(endereco + 3);
                        arquivo.write(b2);
                    }

                    // move o novo registro para o fim
                    else {
                        arquivo.seek(endereco);
                        arquivo.write('*');
                        arquivo.seek(arquivo.length());
                        arquivo.writeByte(' ');
                        arquivo.writeShort(tam2);
                        arquivo.write(b2);
                    }
                    return true;
                }
            }
        }
        return false;
    }

    public void close() throws IOException {
        arquivo.close();
    }

}
