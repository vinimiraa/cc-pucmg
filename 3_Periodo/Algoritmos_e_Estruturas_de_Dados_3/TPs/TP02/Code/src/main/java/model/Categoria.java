package model;

import java.io.IOException;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.text.Normalizer;
import java.util.regex.Pattern;

import interfaces.Registro;

/**
 *  Categoria: classe que representa uma categoria de tarefas.
 */
public class Categoria implements Registro, Comparable<Categoria>
{
    private int       id;
    private String    nome;

    public Categoria ( ) {
        this( -1, "" );
    } // end Categoria ( )

    public Categoria ( String nome ) 
    {
        this( -1, nome );
    } // end Categoria ( )

    public Categoria( int id, String nome )
    {
        this.id   = id;
        this.nome = nome;
    } // end Categoria ( )
    
    public int getId ( ) {
        return this.id;
    } // end getId ( )
    
    public void setId ( int id ) {
        this.id = id;
    } // end setId ( )
    
    public String getNome ( ) {
        return this.nome;
    } // end getNome ( )

    public void setNome ( String nome ) {
        this.nome = nome;
    } // end setNome ( )

    public String toString ( ) 
    {
        return ("\nID..: " + this.id   +
                "\nNome: " + this.nome);
    } // end toString ( )

    public byte[] toByteArray ( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.id);
        dos.writeUTF(this.nome); // nome

        return baos.toByteArray();
    } // end toByteArray ( )

    public void fromByteArray ( byte[] b ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(b);
        DataInputStream dis = new DataInputStream(bais);

        this.id   = dis.readInt();
        this.nome = dis.readUTF();
    } // end fromByteArray ( )

    private static String strnormalize ( String str ) 
    {
        String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD);
        Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
        return pattern.matcher(nfdNormalizedString).replaceAll("").toLowerCase();
    } // end transforma ( )

    @Override
    public int compareTo( Categoria outra ) {
        return strnormalize(this.nome).compareTo( strnormalize(outra.nome) );
    } // end compareTo ( )

} // end class Categoria