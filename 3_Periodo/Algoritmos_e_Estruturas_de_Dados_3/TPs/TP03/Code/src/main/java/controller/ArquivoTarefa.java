package controller;

import java.util.ArrayList;

import model.ArvoreBMais;
import model.ParIDCategoriaIDTarefa;
import model.ParIDRotuloIDTarefa;
import model.Tarefa;

/**
 *  Classe ArquivoTarefa
 * 
 *  <p>Classe que representa um arquivo de tarefas.</p>
 *  <p>Implementa a interface RegistroArvoreBMais.</p>
 *  <p>Extende a classe Arquivo.</p>
 *  
 *  @see Arquivo
 *  @see Tarefa
 *  @see ParIDCategoriaIDTarefa
 */
public class ArquivoTarefa extends Arquivo<Tarefa> 
{
    ArvoreBMais<ParIDCategoriaIDTarefa> arvoreCategoriaTarefa;
    ArvoreBMais<ParIDRotuloIDTarefa> arvoreRotuloTarefa;
    IndiceInvertido indiceInvertido;

    public ArquivoTarefa( ) throws Exception 
    {
        super( "Tarefas.db", Tarefa.class.getConstructor() );
        arvoreCategoriaTarefa = new ArvoreBMais<> 
        ( 
            ParIDCategoriaIDTarefa.class.getConstructor(),
            5, 
            "data\\Tarefas.db.arvoreCategoria.idx" 
        );

        arvoreRotuloTarefa = new ArvoreBMais<>
        (
            ParIDRotuloIDTarefa.class.getConstructor(),
            5,
            "data\\Tarefas.db.arvoreRotulo.idx"
        );

        indiceInvertido = new IndiceInvertido( );
    } // ArquivoTarefa ( )

    @Override
    public int create( Tarefa tarefa ) throws Exception 
    {
        int id = super.create( tarefa );
        try {
            arvoreCategoriaTarefa.create( new ParIDCategoriaIDTarefa( tarefa.getIdCategoria(), tarefa.getId() ) );

            ArrayList<Integer> rotulos = new ArrayList<>( );
            for( int idRotulo = 1; idRotulo <= rotulos.size( ); idRotulo++ ) {
                rotulos.add( idRotulo );
                arvoreRotuloTarefa.create( new ParIDRotuloIDTarefa( idRotulo, tarefa.getId( ) ) );
            } // for
            tarefa.setIdRotulos(rotulos);
            indiceInvertido.insert( tarefa.getNome( ), tarefa.getId( ) );

        } catch( Exception e ) {
            System.out.print( "Erro ao criar tarefa no índice: " + e.getMessage( ) );
        } // try-catch
        return ( id );
    } // create ( )

    public ArrayList<Tarefa> readAll( ) throws Exception {
        return readAll( -1 );
    } // readAll ( )

    public ArrayList<Tarefa> readAll( int idCategoria ) throws Exception 
    {
        ArrayList<Tarefa> tarefas = new ArrayList<>();
        try 
        {
            ArrayList<ParIDCategoriaIDTarefa> listaTarefas;
            
            if( idCategoria == -1 ) {
                listaTarefas = arvoreCategoriaTarefa.read( new ParIDCategoriaIDTarefa(-1, -1) );
            } else {
                listaTarefas = arvoreCategoriaTarefa.read( new ParIDCategoriaIDTarefa(idCategoria, -1) );
            } // if

            for( ParIDCategoriaIDTarefa parIdId : listaTarefas ) {
                tarefas.add( super.read( parIdId.getIDTarefa( ) ) );
            } // for

        } catch( Exception e ) {
            System.out.println("Erro ao ler tarefas: " + e.getMessage());
        } // try-catch
        return ( tarefas );
    } // readAll ( )

    public ArrayList<Tarefa> readAllByRotulo( int idRotulo ) 
    {
        ArrayList<Tarefa> tarefas = new ArrayList<>( );
        try 
        {
            tarefas = indiceInvertido.search( idRotulo );
        } catch( Exception e ) {
            System.out.println( "Erro ao ler tarefas por rótulo: " + e.getMessage( ) );
        } // try-catch
        return ( tarefas );
    } // readAllByRotulo ( )

    @Override
    public boolean update ( Tarefa novaTarefa ) throws Exception 
    {
        boolean result = false;
        Tarefa tarefaAntiga = super.read( novaTarefa.getId( ) );
        result = super.update( novaTarefa );
        if( result ) 
        {
            try
            {
                if( novaTarefa.getId() != tarefaAntiga.getId() ) 
                {
                    arvoreCategoriaTarefa.delete( new ParIDCategoriaIDTarefa( tarefaAntiga.getIdCategoria(), tarefaAntiga.getId() ) );
                    arvoreCategoriaTarefa.create( new ParIDCategoriaIDTarefa( novaTarefa.getIdCategoria(), novaTarefa.getId() ) );
                } // if

                if( !novaTarefa.getIdRotulos( ).equals( tarefaAntiga.getIdRotulos( ) ) ) 
                {
                    for( int idRotulo : tarefaAntiga.getIdRotulos( ) ) {
                        arvoreRotuloTarefa.delete( new ParIDRotuloIDTarefa( idRotulo, tarefaAntiga.getId( ) ) );
                    } // for
                    for( int idRotulo : novaTarefa.getIdRotulos( ) ) {
                        arvoreRotuloTarefa.create( new ParIDRotuloIDTarefa( idRotulo, novaTarefa.getId( ) ) );
                    } // for
                } // if

                if( !novaTarefa.getNome( ).equals( tarefaAntiga.getNome( ) ) ) {
                    indiceInvertido.update(tarefaAntiga.getNome(), novaTarefa.getNome(), novaTarefa.getId());
                }
            } catch( Exception e ) {
                System.out.println( "Erro ao atualizar o índice: " + e.getMessage( ) );
            } // try-catch
        } // if
        return ( result );
    } // update ( )

    @Override
    public boolean delete( int id ) throws Exception 
    {
        boolean result = false;
        Tarefa tarefa = super.read( id );
        if( super.delete( id ) ) 
        {
            try 
            {
                arvoreCategoriaTarefa.delete( new ParIDCategoriaIDTarefa( tarefa.getIdCategoria(), id ) );
                
                ArrayList<Integer> rotulos = tarefa.getIdRotulos( );
                for( int idRotulo : rotulos ) {
                    arvoreRotuloTarefa.delete( new ParIDRotuloIDTarefa( idRotulo, id ) );
                } // for

                indiceInvertido.delete( tarefa.getNome( ), id );
                
                result = true;
            } catch( Exception e ) {
                System.out.println( "Erro ao deletar tarefa do índice: " + e.getMessage( ) );
            } // try-catch
        } // if
        return ( result );
    } // delete ( )

} // ArquivoTarefa
