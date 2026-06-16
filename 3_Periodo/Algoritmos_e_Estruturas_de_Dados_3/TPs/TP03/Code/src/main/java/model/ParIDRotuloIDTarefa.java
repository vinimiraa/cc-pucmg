package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroArvoreBMais;

/**
 *  ParIDRotuloIDTarefa: Classe que representa um par de ID Rotulo e ID Tarefa.
 *  Implementa a interface RegistroArvoreBMais.
 *  <p>Extende a classe RegistroArvoreBMais.</p>
 *  
 *  @see RegistroArvoreBMais
 *  @see ParIDRotuloIDTarefa
 *  @see ArvoreBMais
 */
public class ParIDRotuloIDTarefa implements RegistroArvoreBMais<ParIDRotuloIDTarefa> 
{
    private int idRotulo; // chave
    private int idTarefa;    // valor
    private final short TAMANHO = 8;  // tamanho em bytes

    public ParIDRotuloIDTarefa( ) {
        this(-1, -1);
    } // ParIDRotuloIDTarefa ( )

    public ParIDRotuloIDTarefa( int idRotulo ) {
        this( idRotulo, -1 );
    } // ParIDRotuloIDTarefa ( )

    public ParIDRotuloIDTarefa( int idRotulo, int idTarefa ) 
    {
        this.idRotulo = idRotulo;
        this.idTarefa = idTarefa;
    } // ParIDRotuloIDTarefa ( )

    public int getIDRotulo( ) {
        return idRotulo;
    } // getIDRotulo ( )

    public int getIDTarefa( ) {
        return idTarefa;
    } // getIDTarefa ( )

    @Override
    public ParIDRotuloIDTarefa clone( )
    {
        ParIDRotuloIDTarefa clone = null;
        try {
            clone = new ParIDRotuloIDTarefa( this.idRotulo, this.idTarefa );
        } catch( Exception e ) {
            e.printStackTrace( );
        } // try-catch
        return clone;
    } // clone ( )

    // public int compareTo( ParIDRotuloIDTarefa other )
    // {
    //     if( this.idRotulo != other.idRotulo ) {
    //         return this.idRotulo - other.idRotulo;
    //     } else {
    //         return this.idTarefa == -1 ? 0 : this.idTarefa - other.idTarefa;
    //     } // if
    // } // compareTo ( )

    public int compareTo( ParIDRotuloIDTarefa other ) 
    {
        if( this.idRotulo == -1 || other.idRotulo == -1 ) {
            return 0;                                      // Busca ampla, ignora Rotulo
        } else if( this.idRotulo != other.idRotulo ) {
            return this.idRotulo - other.idRotulo;         // Compara Rotulos
        } else if( this.idTarefa == -1 || other.idTarefa == -1 ) {
            return 0;                                      // Busca específica por Rotulo, ignora tarefa
        } else {
            return this.idTarefa - other.idTarefa;         // Compara tarefas
        } // if
    } // compareTo ( )

    public short size( ) {
        return this.TAMANHO;
    } // size ( )

    public String toString( ) {
        return String.format("%3d", this.idRotulo) + ";" + String.format("%3d", this.idTarefa);
    } // toString ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.idRotulo);
        dos.writeInt(this.idTarefa);

        return (baos.toByteArray());
    } // toByteArray ( )

    public void fromByteArray( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        this.idRotulo = dis.readInt( );
        this.idTarefa = dis.readInt( );
    } // fromByteArray ( )

} // ParIDRotuloIDTarefa
