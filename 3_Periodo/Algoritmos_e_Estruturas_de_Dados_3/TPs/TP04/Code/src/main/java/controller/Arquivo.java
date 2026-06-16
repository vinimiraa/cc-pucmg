package controller;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

import interfaces.Registro;
import model.HashExtensivel;
import model.ParIDEndereco;

/**
 *  Classe Arquivo
 * 
 *  <p>Classe que representa um arquivo de registros.</p>
 *  <p>Implementa as operações de criação, leitura, atualização e exclusão de registros.</p>
 *  <p>Implementa um índice direto para acesso rápido aos registros.</p>
 * 
 *  @param <T> tipo do registro
 *  @see HashExtensivel
 *  @see Registro
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
        File d = new File(".\\data");
        if( !d.exists( ) ) {
            d.mkdir();
        } // if

        this.nomeArquivo = "data\\" + na;
        this.construtor = c;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");
        if( arquivo.length() < TAM_CABECALHO ) {
            arquivo.writeInt(0);
        } // if

        indiceDireto = new HashExtensivel<>
        (
            ParIDEndereco.class.getConstructor(), 
            4, 
            this.nomeArquivo + ".hashDict.idx",
            this.nomeArquivo + ".hashBuck.idx"
        );
    } // Arquivo ( )

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
    } // create ( )

    /**
     *  Le um registro do arquivo
     *  @param id id do registro a ser lido
     *  @return objeto lido
     *  @throws Exception
     */
    public T read ( int id ) throws Exception 
    {
        T obj;
        short tam;
        byte[] b;
        byte lapide;

        ParIDEndereco pid = indiceDireto.read(id);
        if( pid != null ) 
        {
            arquivo.seek(pid.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if( lapide == ' ' ) 
            {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if( obj.getId() == id ) {
                    return obj;
                } // if
            } // if
        } // if
        return null;
    } // read ( )

    /**
     *  Atualiza um registro no arquivo
     *  @param id id do registro a ser atualizado
     *  @return true se o registro foi atualizado, false caso contrário
     *  @throws Exception 
     */
    public boolean delete ( int id ) throws Exception 
    {
        boolean result = false;
        T obj;
        short tam;
        byte[] b;
        byte lapide;

        ParIDEndereco pie = indiceDireto.read(id);
        if( pie != null ) 
        {
            arquivo.seek(pie.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if( lapide == ' ' ) 
            {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if( obj.getId() == id ) 
                {
                    if( indiceDireto.delete(id) ) 
                    {
                        arquivo.seek(pie.getEndereco());
                        arquivo.write('*');
                        result = true;
                    } // if
                } // if
            } // if
        } // if
        return ( result );
    } // delete ( )

    /**
     *  Atualiza um registro no arquivo
     *  @param novoObj objeto a ser atualizado
     *  @return true se o registro foi atualizado, false caso contrário
     *  @throws Exception
     */
    public boolean update ( T novoObj ) throws Exception 
    {
        boolean result = false;
        T obj;
        short tam;
        byte[] b;
        byte lapide;

        ParIDEndereco pie = indiceDireto.read(novoObj.getId());
        if( pie != null ) 
        {
            arquivo.seek(pie.getEndereco());
            obj = construtor.newInstance();
            lapide = arquivo.readByte();
            if( lapide == ' ' ) 
            {
                tam = arquivo.readShort();
                b = new byte[tam];
                arquivo.read(b);
                obj.fromByteArray(b);
                if( obj.getId() == novoObj.getId() ) 
                {
                    byte[] b2 = novoObj.toByteArray();
                    short tam2 = (short)b2.length;

                    if( tam2 <= tam ) // sobrescreve o registro
                    {
                        arquivo.seek(pie.getEndereco()+3);
                        arquivo.write(b2);
                    }
                    else // move o novo registro para o fim
                    {
                        arquivo.seek(pie.getEndereco());
                        arquivo.write('*');
                        arquivo.seek(arquivo.length());
                        long novoEndereco = arquivo.getFilePointer();
                        arquivo.writeByte(' ');
                        arquivo.writeShort(tam2);
                        arquivo.write(b2);
                        indiceDireto.update(new ParIDEndereco(novoObj.getId(), novoEndereco));
                    } // if
                    result = true;
                } // if
            } // if
        } // if
        return ( result );
    } // update ( )

    /**
     *  Fecha o arquivo
     *  @throws IOException
     */
    public void close ( ) throws IOException {
        arquivo.close( );
    } // close ( )

} // Arquivo