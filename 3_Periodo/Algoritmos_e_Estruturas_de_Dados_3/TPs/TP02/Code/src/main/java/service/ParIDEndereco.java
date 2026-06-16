package service;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroHashExtensivel;

/**
 *  ParIDEndereco: Classe que representa um par de ID e Endereco.
 *  Implementa a interface RegistroHashExtensivel.
 */
public class ParIDEndereco implements RegistroHashExtensivel<ParIDEndereco> 
{
    private int id;
    private long endereco;
    private final short TAMANHO = 12; // tamanho em bytes

    public ParIDEndereco ( ) 
    {
        this.id = -1;
        this.endereco = -1;
    } // end ParIDEndereco ( )

    public ParIDEndereco ( int id, long end ) 
    {
        this.id = id;
        this.endereco = end;
    } // end ParIDEndereco ( )

    public int getId ( ) {
        return id;
    } // end getId ( )

    public long getEndereco ( ) {
        return endereco;
    } // end getEndereco ( )

    @Override
    public int hashCode ( ) {
        return this.id;
    } // end hashCode ( )

    public short size ( ) {
        return this.TAMANHO;
    } // end size ( )

    public String toString ( ) {
        return "(" + this.id + ";" + this.endereco + ")";
    } // end toString ( )

    public byte[] toByteArray ( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.id);
        dos.writeLong(this.endereco);
        
        return ( baos.toByteArray() );
    } // end toByteArray ( )

    public void fromByteArray ( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        this.id = dis.readInt();
        this.endereco = dis.readLong();
    } // end fromByteArray ( )
    
} // end class ParIDEndereco
