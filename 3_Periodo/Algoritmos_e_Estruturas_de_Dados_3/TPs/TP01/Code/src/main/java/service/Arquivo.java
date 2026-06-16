package service;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

import interfaces.*;

/**
 *  Arquivo: Classe generica que representa um arquivo de registros.
 */
public class Arquivo<T extends Registro> 
{
    final int TAM_CABECALHO = 4;

    RandomAccessFile arquivo;
    String nomeArquivo;
    Constructor<T> construtor;

    HashExtensivel<ParIDEndereco> indiceDireto;

    public Arquivo ( String na, Constructor<T> c ) throws Exception 
    {
        File d = new File(".\\Codigo\\src\\main\\data");
        if ( !d.exists( ) ) {
            d.mkdir();
        } // end if

        this.nomeArquivo = ".\\Codigo\\src\\main\\data\\" + na;
        this.construtor = c;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");
        if (arquivo.length() < TAM_CABECALHO) {
            // inicializa o arquivo, criando seu cabecalho
            arquivo.writeInt(0);
        } // end if

        indiceDireto = new HashExtensivel<>(ParIDEndereco.class.getConstructor(), 4, this.nomeArquivo + ".d.idx",
                this.nomeArquivo + ".c.idx");
    } // end Arquivo ( )

    /**
     *  Cria um novo registro no arquivo
     *  @param obj objeto a ser inserido 
     *  @return id do registro criado
     *  @throws Exception 
     */
    public int create ( T obj ) throws Exception {
        arquivo.seek(0);
        int proximoID = arquivo.readInt() + 1;
        arquivo.seek( 0 );
        arquivo.writeInt(proximoID);
        obj.setId(proximoID);
        arquivo.seek(arquivo.length());

        long endereco = arquivo.getFilePointer();
        byte[] b = obj.toByteArray();

        arquivo.writeByte(' ');
        arquivo.writeShort(b.length);
        arquivo.write(b);

        indiceDireto.create(new ParIDEndereco(proximoID, endereco));
        return obj.getId( );
    } // end create ( )

    /**
     *  Le um registro do arquivo
     *  @param id id do registro a ser lido
     *  @return objeto lido
     *  @throws Exception
     */
    public T read ( int id ) throws Exception {
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        System.out.println("ID: " + id);
        ParIDEndereco pid = indiceDireto.read(id);
        if ( pid != null ) {
            arquivo.seek(pid.getEndereco());
            arquivo.seek(TAM_CABECALHO);
            while ( arquivo.getFilePointer() < arquivo.length() ) {
                obj = construtor.newInstance();
                lapide = arquivo.readByte();
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);

                if ( lapide == ' ' ) {
                    obj.fromByteArray(b);
                    if ( obj.getId() == id) {
                        return obj;
                    } // end if
                } // end if
            } // end while
        } // end if
        return null;
    } // end read ( )

    /**
     *  Atualiza um registro no arquivo
     *  @param id id do registro a ser atualizado
     *  @return true se o registro foi atualizado, false caso contrário
     *  @throws Exception 
     */
    public boolean delete ( int id ) throws Exception {
        boolean result = false;
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        Long endereco;
        arquivo.seek(TAM_CABECALHO);
        while ( arquivo.getFilePointer() < arquivo.length() ) {
            obj = construtor.newInstance();
            endereco = arquivo.getFilePointer();
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if ( lapide == ' ' ) {
                obj.fromByteArray(b);
                if (obj.getId() == id) {
                    arquivo.seek(endereco);
                    arquivo.write('*');
                    result = true;
                } // end if
            } // end if 
        } // end while
        return result;
    } // end delete ( )

    /**
     *  Atualiza um registro no arquivo
     *  @param novoObj objeto a ser atualizado
     *  @return true se o registro foi atualizado, false caso contrário
     *  @throws Exception
     */
    public boolean update ( T novoObj ) throws Exception {
        boolean result = false;
        T obj;
        short tam;
        byte[] b;
        byte lapide;
        ParIDEndereco pie = indiceDireto.read(novoObj.getId());
        if( pie!=null ) {
            arquivo.seek(pie.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();

            if( lapide==' ' ) {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);

                if( obj.getId()==novoObj.getId() ) {
                    byte[] b2 = novoObj.toByteArray();
                    short tam2 = (short)b2.length;

                    if( tam2 <= tam ) { // sobrescreve o registro
                        arquivo.seek(pie.getEndereco()+3);
                        arquivo.write(b2);
                    } else { // move o novo registro para o fim
                        arquivo.seek(pie.getEndereco());
                        arquivo.write('*');
                        arquivo.seek(arquivo.length());
                        long novoEndereco = arquivo.getFilePointer();
                        arquivo.writeByte(' ');
                        arquivo.writeShort(tam2);
                        arquivo.write(b2);
                        indiceDireto.update(new ParIDEndereco(novoObj.getId(), novoEndereco));
                    } // end if
                    result = true;
                } // end if
            } // end if
        } // end if
        return result;
    } // end update ( )

    /**
     *  Fecha o arquivo
     *  @throws IOException
     */
    public void close ( ) throws IOException {
        arquivo.close( );
    } // end close ( )

} // end class Arquivo
