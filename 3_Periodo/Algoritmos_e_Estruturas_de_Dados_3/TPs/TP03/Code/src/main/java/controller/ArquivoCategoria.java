package controller;

import java.util.ArrayList;

import model.ArvoreBMais;
import model.ParNomeIDCategoria;
import interfaces.RegistroArvoreBMais;
import model.Categoria;
import model.Tarefa;

/**
 *  Classe ArquivoCategoria
 *  
 *  <p>Classe que representa um arquivo de categorias.</p>
 *  <p>Implementa a interface RegistroArvoreBMais.</p>
 *  <p>Extende a classe Arquivo.</p>
 *  
 *  @see Arquivo
 *  @see Categoria
 *  @see ParNomeIDCategoria
 *  @see ArvoreBMais
 *  @see RegistroArvoreBMais
 */
public class ArquivoCategoria extends Arquivo<Categoria>
{
    ArvoreBMais<ParNomeIDCategoria> arvore;

    public ArquivoCategoria( ) throws Exception 
    {
        super( "Categorias.db", Categoria.class.getConstructor() );
        arvore = new ArvoreBMais<>
        ( 
            ParNomeIDCategoria.class.getConstructor(),
            5, 
            "data\\Categorias.db.arvore.idx" 
        );
    } // ArquivoCategoria ( )

    @Override
    public int create( Categoria categoria ) throws Exception 
    {
        int id = super.create( categoria );
        try
        {
            arvore.create( new ParNomeIDCategoria( categoria.getNome(), categoria.getId() ) );
        } catch( Exception e ) {
            System.out.println("Erro ao criar categoria no índice: " + e.getMessage());
        } // try-catch
        return ( id );
    } // create ( )

    public ArrayList<Categoria> readAll( ) throws Exception
    {
        ArrayList<ParNomeIDCategoria> listaNomeId = null;
        ArrayList<Categoria> categorias = new ArrayList<>( );
        try 
        {
            listaNomeId = arvore.read( new ParNomeIDCategoria(" ", -1) );
            for( ParNomeIDCategoria parNomeId : listaNomeId ) {
                categorias.add( super.read( parNomeId.getIDCategoria() ) );
            } // for
        } catch( Exception e ) {
            System.out.print( e.getMessage( ) );
        } // try-catch
        return ( categorias );
    } // readAll ( )

    @Override
    public boolean update( Categoria novaCategoria ) throws Exception 
    {
        boolean result = false;
        Categoria categoriaAntiga = super.read( novaCategoria.getId() );
        result = super.update( novaCategoria );
        if( result ) 
        {
            try 
            {
                if( !novaCategoria.getNome().equals(categoriaAntiga.getNome()) ) 
                {
                    arvore.delete( new ParNomeIDCategoria( categoriaAntiga.getNome(), categoriaAntiga.getId() ) );
                    arvore.create( new ParNomeIDCategoria( novaCategoria.getNome(), novaCategoria.getId() ) );
                } // if
            } catch( Exception e ) {
                System.out.println( "Erro ao atualizar categoria no índice: " + e.getMessage( ) );
            } // try-catch
        } // if
        return ( result );
    } // update ( )

    @Override
    public boolean delete( int id ) throws Exception 
    {
        boolean result = false;
        Categoria categoria = super.read( id );

        if( temTarefasAssociadas( categoria ) == false ) 
        {
            if( super.delete( id ) ) 
            {
                try 
                {
                    arvore.delete( new ParNomeIDCategoria( categoria.getNome(), categoria.getId() ) );
                    result = true;
                } catch ( Exception e ) {
                    System.out.println("Erro ao deletar categoria no índice: " + e.getMessage());
                } // try-catch
            } // if
        } // if
        return ( result );
    } // delete ( )

    private boolean temTarefasAssociadas( Categoria categoria ) 
    {
        boolean result = true;
        try 
        {
            ArquivoTarefa arquivoTarefa = new ArquivoTarefa( );
            ArrayList<Tarefa> tarefas = arquivoTarefa.readAll( categoria.getId( ) );
            if( tarefas.isEmpty( ) ) {
                result = false;
            } // if
        } catch( Exception e ) {
            System.out.println( "Erro ao verificar tarefas associadas à categoria: " + e.getMessage( ) );
        } // try-catch
        return ( result );
    } // temTarefasAssociadas ( )

    public boolean exitemCategorias( ) throws Exception 
    {
        boolean result = false;
        ArrayList<Categoria> categorias = this.readAll( );
        if( categorias.isEmpty( ) == false ) {
            result = true;
        } // if
        return ( result );
    } // exitemCategorias ( )

} // ArquivoCategoria
