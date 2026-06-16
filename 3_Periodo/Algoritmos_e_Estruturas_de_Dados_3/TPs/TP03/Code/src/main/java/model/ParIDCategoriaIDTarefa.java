package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroArvoreBMais;

/**
 *  ParIDCategoriaIDTarefa: Classe que representa um par de ID Categoria e ID Tarefa.
 *  Implementa a interface RegistroArvoreBMais.
 *  <p>Extende a classe RegistroArvoreBMais.</p>
 *  
 *  @see RegistroArvoreBMais
 *  @see ParIDCategoriaIDTarefa
 *  @see ArvoreBMais
 */
public class ParIDCategoriaIDTarefa implements RegistroArvoreBMais<ParIDCategoriaIDTarefa> 
{
    private int idCategoria; // chave
    private int idTarefa;    // valor
    private final short TAMANHO = 8;  // tamanho em bytes

    public ParIDCategoriaIDTarefa( ) {
        this(-1, -1);
    } // ParIDCategoriaIDTarefa ( )

    public ParIDCategoriaIDTarefa( int idCategoria ) {
        this( idCategoria, -1 );
    } // ParIDCategoriaIDTarefa ( )

    public ParIDCategoriaIDTarefa( int idCategoria, int idTarefa ) 
    {
        this.idCategoria = idCategoria;
        this.idTarefa = idTarefa;
    } // ParIDCategoriaIDTarefa ( )

    public int getIDCategoria( ) {
        return idCategoria;
    } // getIDCategoria ( )

    public int getIDTarefa( ) {
        return idTarefa;
    } // getIDTarefa ( )

    @Override
    public ParIDCategoriaIDTarefa clone( )
    {
        ParIDCategoriaIDTarefa clone = null;
        try {
            clone = new ParIDCategoriaIDTarefa( this.idCategoria, this.idTarefa );
        } catch( Exception e ) {
            e.printStackTrace( );
        } // try-catch
        return clone;
    } // clone ( )

    // public int compareTo( ParIDCategoriaIDTarefa other )
    // {
    //     if( this.idCategoria != other.idCategoria ) {
    //         return this.idCategoria - other.idCategoria;
    //     } else {
    //         return this.idTarefa == -1 ? 0 : this.idTarefa - other.idTarefa;
    //     } // if
    // } // compareTo ( )

    public int compareTo( ParIDCategoriaIDTarefa other ) 
    {
        if( this.idCategoria == -1 || other.idCategoria == -1 ) {
            return 0;                                      // Busca ampla, ignora categoria
        } else if( this.idCategoria != other.idCategoria ) {
            return this.idCategoria - other.idCategoria;   // Compara categorias
        } else if( this.idTarefa == -1 || other.idTarefa == -1 ) {
            return 0;                                      // Busca específica por categoria, ignora tarefa
        } else {
            return this.idTarefa - other.idTarefa;         // Compara tarefas
        } // if
    } // compareTo ( )

    public short size( ) {
        return this.TAMANHO;
    } // size ( )

    public String toString( ) {
        return  String.format("%3d", this.idCategoria) + ";" + String.format("%3d", this.idTarefa);
    } // toString ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.idCategoria);
        dos.writeInt(this.idTarefa);

        return (baos.toByteArray());
    } // toByteArray ( )

    public void fromByteArray( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        this.idCategoria = dis.readInt( );
        this.idTarefa    = dis.readInt();
    } // fromByteArray ( )

} // ParIDCategoriaIDTarefa
