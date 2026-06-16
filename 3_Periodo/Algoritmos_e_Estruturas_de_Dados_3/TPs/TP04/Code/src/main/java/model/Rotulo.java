package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.Registro;

/**
 *  Classe Rotulo
 *  
 *  <p>Classe que representa um rótulo.</p>
 *  <p>Implementa a interface Registro.</p>
 *   
 *  @see interfaces.Registro
 */
public class Rotulo implements Registro
{
    private int    id;
    private String nome;

    public Rotulo( ) {
        this( -1, "" );
    } // Rotulo ( )

    public Rotulo( String nome ) 
    {
        this( -1, nome );
    } // Rotulo ( )

    public Rotulo( int id, String nome )
    {
        this.id   = id;
        this.nome = nome;
    } // Rotulo ( )

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
        ByteArrayOutputStream dados = new ByteArrayOutputStream( );
        DataOutputStream saida = new DataOutputStream( dados );

        saida.writeInt( this.id );
        saida.writeUTF( this.nome );

        return dados.toByteArray( );
    } // toByteArray ( )

    public void fromByteArray( byte[] dados ) throws IOException
    {
        ByteArrayInputStream bais = new ByteArrayInputStream( dados );
        DataInputStream entrada = new DataInputStream( bais );

        this.id   = entrada.readInt( );
        this.nome = entrada.readUTF( );
    } // fromByteArray ( )

} // Rotulo