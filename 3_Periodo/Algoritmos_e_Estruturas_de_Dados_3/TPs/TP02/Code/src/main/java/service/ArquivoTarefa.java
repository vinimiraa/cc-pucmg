package service;

import java.util.ArrayList;
import java.util.List;

import model.Tarefa;

/**
 * ArquivoTarefa: Classe que representa um arquivo de tarefas.
 */
public class ArquivoTarefa extends Arquivo<Tarefa> 
{
    ArvoreBMais<ParIDCategoriaIDTarefa> arvore;

    public ArquivoTarefa ( ) throws Exception 
    {
        super( "Tarefas.db", Tarefa.class.getConstructor() );
        arvore = new ArvoreBMais<>
        ( 
            ParIDCategoriaIDTarefa.class.getConstructor(),
            5, 
            ".\\Code\\src\\main\\data\\Tarefas.db.bpt.idx" 
        );
    } // end ArquivoTarefa ( )

    @Override
    public int create ( Tarefa obj ) throws Exception 
    {
        int id = super.create( obj );
        try {
            arvore.create( new ParIDCategoriaIDTarefa(obj.getIdCategoria(), obj.getId()) );
        } catch( Exception e ) {
            System.out.print( "" );
            e.printStackTrace( );
        } // end try-catch
        return id;
    } // end create ( )

    @Override
    public Tarefa read ( int idCategoria ) throws Exception 
    {
        ArrayList<ParIDCategoriaIDTarefa> picit = arvore.read( new ParIDCategoriaIDTarefa(idCategoria, -1) );
        return super.read( picit.get(0).getIDTarefa() );
    } // end read ( )

    /*     
    public ArrayList<Tarefa> readAll ( int idCategoria ) throws Exception 
    {
        ArrayList<ParIDCategoriaIDTarefa> picit = arvore.read( new ParIDCategoriaIDTarefa(idCategoria, -1) );
        ArrayList<Tarefa> tarefas = new ArrayList<>( );
        int i = 0;
        for( ParIDCategoriaIDTarefa p : picit ) 
        {
            System.out.println( picit.get(i));
            tarefas.add( super.read( p.getIDTarefa() ) );
            i++;
        } // end for
        return tarefas;
    } // end readAll ( ) 
     */

    public List<Tarefa> readAll ( ) throws Exception 
    {
        List<Tarefa> tarefas = new ArrayList<>( );

        arquivo.seek(TAM_CABECALHO);
        byte lapide = ' ';
        short tam = 0;
        byte[] b = null;

        Tarefa t = null;
        while( arquivo.getFilePointer() < arquivo.length() ) 
        {
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if( lapide != '*' ) 
            {
                t = new Tarefa();
                t.fromByteArray(b);
                tarefas.add(t);
            } // end if
        } // end while
        return ( tarefas );
    } // end readAll ( )

    public List<Tarefa> readAll ( int idCategoria ) throws Exception 
    {
        List<Tarefa> tarefas = new ArrayList<>( );

        arquivo.seek(TAM_CABECALHO);
        byte lapide = ' ';
        short tam = 0;
        byte[] b = null;

        Tarefa t = null;
        while( arquivo.getFilePointer() < arquivo.length() ) 
        {
            lapide = arquivo.readByte();
            tam = arquivo.readShort();
            b = new byte[tam];
            arquivo.read(b);

            if( lapide != '*' ) 
            {
                t = new Tarefa();
                t.fromByteArray(b);
                if( t.getIdCategoria() == idCategoria ) 
                {
                    tarefas.add(t);
                } // end if
            } // end if
        } // end while
        return ( tarefas );
    } // end readAll ( ) 
    

    @Override
    public boolean update ( Tarefa novaTarefa ) throws Exception 
    {
        boolean result = false;
        Tarefa tarefaAntiga = super.read( novaTarefa.getId( ) );
        if( super.update(novaTarefa) ) 
        {
            if( novaTarefa.getId() != tarefaAntiga.getId() ) 
            {
                arvore.delete( new ParIDCategoriaIDTarefa(tarefaAntiga.getIdCategoria(), tarefaAntiga.getId()) );
                arvore.create( new ParIDCategoriaIDTarefa(novaTarefa.getIdCategoria(), novaTarefa.getId()) );
            } // end if
            result = true;
        } // end if
        return result;
    } // end update ( )

    public boolean update ( Tarefa novaTarefa, int id ) throws Exception 
    {
        boolean result = false;
        Tarefa tarefaAntiga = super.read( novaTarefa.getId( ) );
        if( super.update(novaTarefa) ) 
        {
            if( novaTarefa.getIdCategoria() != tarefaAntiga.getIdCategoria() ) 
            {
                arvore.delete( new ParIDCategoriaIDTarefa(tarefaAntiga.getIdCategoria(), tarefaAntiga.getId()) );
                arvore.create( new ParIDCategoriaIDTarefa(novaTarefa.getIdCategoria(), novaTarefa.getId()) );
            } // end if
            result = true;
        } // end if
        return result;
    } // end update ( )

} // end class ArquivoTarefa
