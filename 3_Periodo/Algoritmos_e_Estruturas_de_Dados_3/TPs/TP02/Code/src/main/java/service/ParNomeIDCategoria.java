package service;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.text.Normalizer;
import java.util.regex.Pattern;

import interfaces.RegistroArvoreBMais;

/**
 *  ParNomeIDCategoria: Classe que representa um par de ID Categoria e Nome.
 *  Implementa a interface RegistroArvoreBMais.
 */
public class ParNomeIDCategoria implements RegistroArvoreBMais<ParNomeIDCategoria> 
{
    private String nome;
    private int idCategoria;
    private final short TAMANHO = 32; // tamanho em bytes

    public ParNomeIDCategoria ( ) 
    {
        this( "", -1 );
    } // end ParNomeIDCategoria ( )

    public ParNomeIDCategoria ( String nome ) 
    {
        this( nome, -1 );
    } // end ParNomeIDCategoria ( )

    public ParNomeIDCategoria ( String nome, int idCategoria ) 
    {
        if( nome.getBytes().length > 28 )
            throw new IllegalArgumentException("Nome extenso demais. Diminua o número de caracteres.");
        this.nome = nome;
        this.idCategoria = idCategoria;
    } // end ParNomeIDCategoria ( )

    public int getIDCategoria ( ) {
        return idCategoria;
    } // end getId ( )

    public String getNome ( ) {
        return nome;
    } // end getNome ( )

    @Override
    public ParNomeIDCategoria clone ( ) 
    {
        ParNomeIDCategoria pnic = null;
        try {
            pnic = new ParNomeIDCategoria(this.nome, this.idCategoria);
        } // end try
        catch ( Exception e ) {
            pnic = null;
            e.printStackTrace();
        } // end catch
        return pnic;
    } // end clone ( )

    private static String strnormalize ( String str ) 
    {
        String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD);
        Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
        return pattern.matcher(nfdNormalizedString).replaceAll("").toLowerCase();
    } // end transforma ( )

    public int compareTo ( ParNomeIDCategoria picn ) 
    {
        return strnormalize(this.nome).compareTo( strnormalize(picn.nome) );
    } // end compareTo ( )

    public short size ( ) {
        return this.TAMANHO;
    } // end size ( )

    public String toString ( ) {
        return "(" + this.nome + ";" + String.format("%3d", this.idCategoria) + ")";
    } // end toString ( )

    public byte[] toByteArray ( ) throws IOException 
    {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        byte[] ba = new byte[28];
        byte[] baNome = this.nome.getBytes();
        int i = 0;
        while( i < baNome.length && i < ba.length ) {
            ba[i] = baNome[i];
            i++;
        } // end while
        while( i < 28 ) {
            ba[i] = ' ';
            i++;
        } // end while

        dos.write( baNome );
        dos.writeInt(this.idCategoria);
        
        return ( baos.toByteArray() );
    } // end toByteArray ( )

    public void fromByteArray ( byte[] ba ) throws IOException 
    {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
    
        byte[] b = new byte[28];
        dis.read(b);
        
        this.nome = (new String(b)).trim();
        this.idCategoria = dis.readInt();
    } // end fromByteArray ( )
    
} // end class ParNomeIDCategoria
