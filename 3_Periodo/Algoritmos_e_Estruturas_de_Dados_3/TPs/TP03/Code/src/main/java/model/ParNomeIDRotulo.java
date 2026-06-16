package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroArvoreBMais;
import util.IO;

public class ParNomeIDRotulo implements RegistroArvoreBMais<ParNomeIDRotulo> 
{
    private String nome;
    private int idRotulo;
    private final short TAMANHO = 30; // tamanho total em bytes
    private final short TAM_NOME = 26; // tamanho do nome em bytes

    public ParNomeIDRotulo( ) 
    {
        this( "", -1 );
    } // ParNomeIDRotulo ( )

    public ParNomeIDRotulo( String nome ) 
    {
        this( nome, -1 );
    } // ParNomeIDRotulo ( )

    public ParNomeIDRotulo( String nome, int idRotulo ) 
    {
        if( nome.getBytes().length > TAM_NOME )
            throw new IllegalArgumentException("Nome extenso demais. Diminua o número de caracteres.");
        this.nome = nome;
        this.idRotulo = idRotulo;
    } // ParNomeIDRotulo ( )

    public int getIDRotulo( ) {
        return idRotulo;
    } // getId ( )

    public String getNome( ) {
        return nome;
    } // getNome ( )

    public ParNomeIDRotulo clone( ) 
    {
        ParNomeIDRotulo parNomeId = null;
        try {
            parNomeId = new ParNomeIDRotulo(this.nome, this.idRotulo);
        } // try
        catch ( Exception e ) {
            parNomeId = null;
            e.printStackTrace();
        } // catch
        return parNomeId;
    } // clone ( )

    public String toString( ) {
        return ( "("+ this.nome +", "+ String.format( "%3d" ,this.idRotulo) + ")" );
    } // toString ( )

    public int compareTo( ParNomeIDRotulo parNomeId )
    {
        if( this.nome.equals(" ") || this.idRotulo == -1 ) {
            return 0;
        } // if
        if( parNomeId.nome.equals(" ") || parNomeId.idRotulo == -1 ) {
            return 0;
        } // if
        if( this.nome == null || parNomeId.nome == null ) {
            throw new IllegalArgumentException("Nome não pode ser nulo.");
        } // if
        return IO.strnormalize( this.nome ).compareTo( IO.strnormalize( parNomeId.nome ) );
    } // compareTo ( )

    public short size( ) 
    {
        return this.TAMANHO;
    } // size ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream( );
        DataOutputStream dos = new DataOutputStream( baos );

        byte[] ba = new byte[TAM_NOME];
        byte[] baNome = nome.getBytes();
        int i = 0;
        while( i < baNome.length ) {
            ba[i] = baNome[i];
            i++;
        } // while
        while( i < TAM_NOME ) {
            ba[i] = ' ';
            i++;
        } // while

        dos.write( ba );
        dos.writeInt( idRotulo );

        return ( baos.toByteArray( ) );
    } // toByteArray ( )

    public void fromByteArray( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream( ba );
        DataInputStream dis = new DataInputStream( bais );
        
        byte[] baNome = new byte[TAM_NOME];
        dis.read( baNome );

        this.nome = (new String( baNome )).trim();
        this.idRotulo = dis.readInt( );
    } // fromByteArray ( )

} // ParNomeIDRotulo
