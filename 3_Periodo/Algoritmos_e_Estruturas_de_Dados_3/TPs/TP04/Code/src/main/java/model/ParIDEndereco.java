package model;

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

    public ParIDEndereco( ) 
    {
        this.id = -1;
        this.endereco = -1;
    } // ParIDEndereco ( )

    public ParIDEndereco( int id, long end ) 
    {
        this.id = id;
        this.endereco = end;
    } // ParIDEndereco ( )

    public int getId( ) {
        return id;
    } // getId ( )

    public long getEndereco( ) {
        return endereco;
    } // getEndereco ( )

    @Override
    public int hashCode( ) {
        return this.id;
    } // hashCode ( )

    public short size( ) {
        return this.TAMANHO;
    } // size ( )

    public String toString( ) {
        return "(" + this.id + ";" + this.endereco + ")";
    } // toString ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.id);
        dos.writeLong(this.endereco);
        
        return ( baos.toByteArray() );
    } // toByteArray ( )

    public void fromByteArray( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        this.id = dis.readInt();
        this.endereco = dis.readLong();
    } // fromByteArray ( )
    
} // ParIDEndereco
