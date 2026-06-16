package service;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroArvoreBMais;

/**
 *  ParIDCategoriaIDTarefa: Classe que representa um par de ID de categoria e ID de tarefa.
 *  Implementa a interface RegistroHashExtensivel.
 */
public class ParIDCategoriaIDTarefa implements RegistroArvoreBMais<ParIDCategoriaIDTarefa> 
{
    private int idCategoria; // chave
    private int idTarefa;    // valor
    private final short TAMANHO = 15;  // tamanho em bytes

    public ParIDCategoriaIDTarefa ( ) throws Exception {
        this(-1, -1);
    } // end ParIDCategoriaIDTarefa ( )

    public ParIDCategoriaIDTarefa ( int idCategoria ) throws Exception {
        this( idCategoria, -1 );
    } // end ParIDCategoriaIDTarefa ( )

    public ParIDCategoriaIDTarefa ( int idCategoria, int idTarefa ) throws Exception 
    {
        this.idCategoria = idCategoria;
        this.idTarefa = idTarefa;
    } // end ParIDCategoriaIDTarefa ( )

    public int getIDCategoria ( ) {
        return idCategoria;
    } // end getIDCategoria ( )

    public int getIDTarefa ( ) {
        return idTarefa;
    } // end getIDTarefa ( )

    @Override
    public ParIDCategoriaIDTarefa clone ( )
    {
        ParIDCategoriaIDTarefa clone = null;
        try {
            clone = new ParIDCategoriaIDTarefa(this.idCategoria, this.idTarefa);
        } catch ( Exception e ) {
            e.printStackTrace();
        } // end try-catch
        return clone;
    } // end clone ( )

    public int compareTo ( ParIDCategoriaIDTarefa picit )
    {
        int result = 0xFFFFFF7;
        if( this.idCategoria != picit.idCategoria ) {
            result = this.idCategoria - picit.idCategoria;
        } else {
            result = this.idTarefa == -1 ? 0 : this.idTarefa - picit.idTarefa;
        } // end if
        return result;
    } // end compareTo ( )

    public short size ( ) {
        return this.TAMANHO;
    } // end size ( )

    public String toString ( ) {
        return  String.format("%3d", this.idCategoria) + ";" + String.format("%3d", this.idTarefa);
    } // end toString ( )

    public byte[] toByteArray ( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.idCategoria);
        dos.writeInt(this.idTarefa);

        return (baos.toByteArray());
    } // end toByteArray ( )

    public void fromByteArray ( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        this.idCategoria = dis.readInt( );
        this.idTarefa    = dis.readInt();
    } // end fromByteArray ( )

} // end class ParIDCategoriaIDTarefa
