package aed3;


import java.io.File;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

public class Arquivo<T extends Registro> {
    final int TAM_CABECALHO = 4;
    RandomAccessFile arquivo;
    String nomeArquivo;
    Constructor<T> construtor;
    HashExtensivel<ParIDEndereco> indiceDireto;

    public Arquivo(String na, Constructor<T> c) throws Exception {
        File d = new File(".\\dados");
        if(!d.exists())
            d.mkdir();

        this.nomeArquivo = ".\\dados\\"+na+".db";
        this.construtor = c;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");
        if(arquivo.length()<TAM_CABECALHO) {
            // inicializa o arquivo, criando seu cabecalho
            arquivo.writeInt(0);
        }

        indiceDireto = new HashExtensivel<>(
            ParIDEndereco.class.getConstructor(), 
            4, 
            ".\\dados\\"+na+".hash_d.db", 
            ".\\dados\\"+na+".hash_c.db"
        );
    }

    public int create(T obj) throws Exception {
        arquivo.seek(0);
        int proximoID = arquivo.readInt()+1;
        arquivo.seek(0);
        arquivo.writeInt(proximoID);
        obj.setId(proximoID);
        arquivo.seek(arquivo.length());
        long endereco = arquivo.getFilePointer();

        byte[] b = obj.toByteArray();
        arquivo.writeByte(' ');
        arquivo.writeShort(b.length);
        arquivo.write(b);

        indiceDireto.create(new ParIDEndereco(proximoID, endereco));
        
        return obj.getId();
    }
    
    public T read(int id) throws Exception {
        T obj;
        short tam;
        byte[] b;
        byte lapide;

        ParIDEndereco pid = indiceDireto.read(id);
        if(pid!=null) {
            arquivo.seek(pid.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if(lapide==' ') {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if(obj.getId()==id)
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

        ParIDEndereco pie = indiceDireto.read(id);
        if(pie!=null) {
            arquivo.seek(pie.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if(lapide==' ') {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if(obj.getId()==id) {
                    if(indiceDireto.delete(id)) {
                        arquivo.seek(pie.getEndereco());
                        arquivo.write('*');
                        return true;
                    }
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
        ParIDEndereco pie = indiceDireto.read(novoObj.getId());
        if(pie!=null) {
            arquivo.seek(pie.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if(lapide==' ') {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if(obj.getId()==novoObj.getId()) {

                    byte[] b2 = novoObj.toByteArray();
                    short tam2 = (short)b2.length;

                    // sobrescreve o registro
                    if(tam2 <= tam) {
                        arquivo.seek(pie.getEndereco()+3);
                        arquivo.write(b2);
                    }

                    // move o novo registro para o fim
                    else {
                        arquivo.seek(pie.getEndereco());
                        arquivo.write('*');
                        arquivo.seek(arquivo.length());
                        long novoEndereco = arquivo.getFilePointer();
                        arquivo.writeByte(' ');
                        arquivo.writeShort(tam2);
                        arquivo.write(b2);
                        indiceDireto.update(new ParIDEndereco(novoObj.getId(), novoEndereco));
                    }
                    return true;
                }
            }
        }
        return false;
    }

    

    public void close() throws Exception {
        arquivo.close();
        indiceDireto.close();
    }


}
