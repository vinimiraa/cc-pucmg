package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import interfaces.RegistroArvoreBMais;
import util.IO;

/**
 *  ParNomeIDCategoria: Classe que representa um par de ID Categoria e Nome.
 *  Implementa a interface RegistroArvoreBMais.
 */
public class ParNomeIDCategoria implements RegistroArvoreBMais<ParNomeIDCategoria> 
{
    private String nome;
    private int idCategoria;
    private final short TAMANHO = 30; // tamanho total em bytes
    private final short TAM_NOME = 26; // tamanho do nome em bytes

    public ParNomeIDCategoria( ) 
    {
        this( "", -1 );
    } // ParNomeIDCategoria ( )

    public ParNomeIDCategoria( String nome ) 
    {
        this( nome, -1 );
    } // ParNomeIDCategoria ( )

    public ParNomeIDCategoria( String nome, int idCategoria ) 
    {
        if( nome.getBytes().length > TAM_NOME )
            throw new IllegalArgumentException("Nome extenso demais. Diminua o número de caracteres.");
        this.nome = nome;
        this.idCategoria = idCategoria;
    } // ParNomeIDCategoria ( )

    public int getIDCategoria( ) {
        return idCategoria;
    } // getId ( )

    public String getNome( ) {
        return nome;
    } // getNome ( )

    @Override
    public ParNomeIDCategoria clone( ) 
    {
        ParNomeIDCategoria parNomeId = null;
        try {
            parNomeId = new ParNomeIDCategoria(this.nome, this.idCategoria);
        } // try
        catch ( Exception e ) {
            parNomeId = null;
            e.printStackTrace();
        } // catch
        return parNomeId;
    } // clone ( )

    public int compareTo( ParNomeIDCategoria parNomeId )
    {
        if( this.nome.equals(" ") || this.idCategoria == -1 ) {
            return 0;
        } // if
        if( parNomeId.nome.equals(" ") || parNomeId.idCategoria == -1 ) {
            return 0;
        } // if
        if( this.nome == null || parNomeId.nome == null ) {
            throw new IllegalArgumentException("Nome não pode ser nulo.");
        } // if
        return IO.strnormalize( this.nome ).compareTo( IO.strnormalize( parNomeId.nome ) );
    } // compareTo ( )

    public short size( ) {
        return this.TAMANHO;
    } // size ( )

    public String toString( ) {
        return "(" + this.nome + ";" + String.format("%3d", this.idCategoria) + ")";
    } // toString ( )

    public byte[] toByteArray( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        byte[] ba = new byte[TAM_NOME];
        byte[] baNome = this.nome.getBytes();
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
        dos.writeInt(this.idCategoria);
        
        return ( baos.toByteArray() );
    } // toByteArray ( )

    public void fromByteArray( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        byte[] b = new byte[TAM_NOME];
        dis.read(b);
        
        this.nome = (new String(b)).trim();
        this.idCategoria = dis.readInt();
    } // fromByteArray ( )
    
} // ParNomeIDCategoria
