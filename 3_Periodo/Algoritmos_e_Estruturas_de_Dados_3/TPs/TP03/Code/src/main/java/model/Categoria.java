package model;

import java.io.IOException;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;

import interfaces.Registro;

/**
 *  Classe Categoria
 * 
 *  <p>Classe que representa uma categoria.</p>
 *  <p>Implementa a interface Registro.</p>
 *  
 *  @see interfaces.Registro
 */
public class Categoria implements Registro
{
    private int    id;
    private String nome;

    public Categoria( ) {
        this( -1, "" );
    } // Categoria ( )

    public Categoria( String nome ) 
    {
        this( -1, nome );
    } // Categoria ( )

    public Categoria( int id, String nome )
    {
        this.id   = id;
        this.nome = nome;
    } // Categoria ( )
    
    public int getId( ) {
        return this.id;
    } // getId ( )
    
    public void setId( int id ) {
        this.id = id;
    } // setId ( )
    
    public String getNome( ) {
        return this.nome;
    } // getNome ( )

    public void setNome( String nome ) {
        this.nome = nome;
    } // setNome ( )

    public String toString( ) 
    {
        return ("\nID..: " + this.id   +
                "\nNome: " + this.nome);
    } // toString ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.id);
        dos.writeUTF(this.nome); // nome

        return baos.toByteArray();
    } // toByteArray ( )

    public void fromByteArray( byte[] b ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(b);
        DataInputStream dis = new DataInputStream(bais);

        this.id   = dis.readInt();
        this.nome = dis.readUTF();
    } // fromByteArray ( )

} // Categoria