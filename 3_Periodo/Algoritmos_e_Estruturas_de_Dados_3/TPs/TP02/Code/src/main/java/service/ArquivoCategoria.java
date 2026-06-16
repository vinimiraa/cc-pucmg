package service;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

import model.Categoria;

/**
 *  ArquivoCategoria: Classe que representa um arquivo de categorias.
 */
public class ArquivoCategoria extends Arquivo<Categoria>
{
    Arquivo<Categoria> arqTarefa;
    ArvoreBMais<ParNomeIDCategoria> arvore;

    public ArquivoCategoria ( ) throws Exception 
    {
        super( "Categorias.db", Categoria.class.getConstructor() );
        arvore = new ArvoreBMais<>
        ( 
            ParNomeIDCategoria.class.getConstructor(),
            5, 
            ".\\Code\\src\\main\\data\\Categorias.db.bpt.idx" 
        );
    } // end ArquivoCategoria ( )

    public List<Categoria> readAll( ) throws Exception 
    {
        List<Categoria> categorias = new ArrayList<>( );

        arquivo.seek( TAM_CABECALHO );
        byte lapide = ' ';
        short tam = 0;
        byte[] b = null;

        Categoria c = null;

        // Lê até o final do arquivo
        while( arquivo.getFilePointer() < arquivo.length() ) 
        {
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if( lapide != '*' ) 
            {
                c = new Categoria();
                c.fromByteArray(b);
                categorias.add(c);
            } // end if
        } // end while

        // Collections.sort( categorias );

        return ( categorias );  
    } // end readAll ( )

} // end class ArquivoCategoria
