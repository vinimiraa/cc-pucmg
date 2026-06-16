package controller;

import java.util.ArrayList;

import model.ArvoreBMais;
import model.ParNomeIDRotulo;
import model.Rotulo;

public class ArquivoRotulo extends Arquivo<Rotulo> 
{
    ArvoreBMais<ParNomeIDRotulo> arvore;

    public ArquivoRotulo( ) throws Exception
    {
        super( "Rotulos.db", Rotulo.class.getConstructor( ) );
        arvore = new ArvoreBMais<>
        ( 
            ParNomeIDRotulo.class.getConstructor( ),
            5, 
            "data\\Rotulos.db.arvore.idx" 
        );
    } // ArquivoRotulo ( )

    @Override
    public int create( Rotulo rotulo ) throws Exception
    {
        int id = super.create( rotulo );
        try
        {
            arvore.create( new ParNomeIDRotulo( rotulo.getNome( ), rotulo.getId( ) ) );
        } catch( Exception e ) {
            System.out.println( "Erro ao criar rotulo no índice: " + e.getMessage( ) );
        } // try-catch
        return ( id );
    } // create ( )

    @Override
    public boolean update( Rotulo novoRotulo ) throws Exception
    {
        boolean result = false;
        Rotulo rotuloAntigo = super.read( novoRotulo.getId( ) );
        result = super.update( novoRotulo );
        if( result ) 
        {
            try 
            {
                if( !rotuloAntigo.getNome( ).equals( novoRotulo.getNome( ) ) ) 
                {
                    arvore.delete( new ParNomeIDRotulo( rotuloAntigo.getNome( ), rotuloAntigo.getId( ) ) );
                    arvore.create( new ParNomeIDRotulo( novoRotulo.getNome( ), novoRotulo.getId( ) ) );
                } // if
            } catch( Exception e ) {
                System.out.println( "Erro ao atualizar rotulo no índice: " + e.getMessage( ) );
            } // try-catch
        } // if
        return ( result );
    } // update ( )

    @Override
    public boolean delete( int id ) throws Exception
    {
        boolean result = false;
        Rotulo rotulo = super.read( id );
        result = super.delete( id );
        if( result ) 
        {
            try
            {
                arvore.delete( new ParNomeIDRotulo( rotulo.getNome( ), rotulo.getId( ) ) );
            } catch( Exception e ) {
                System.out.println( "Erro ao deletar rotulo no índice: " + e.getMessage( ) );
            } // try-catch
        } // if
        return ( result );
    } // delete ( )

    public ArrayList<Rotulo> readAll( ) throws Exception
    {
        ArrayList<ParNomeIDRotulo> listaNomeId = null;
        ArrayList<Rotulo> rotulos = new ArrayList<>( );
        try 
        {
            listaNomeId = arvore.read( new ParNomeIDRotulo( " ", -1 ) );
            for( ParNomeIDRotulo parNomeId : listaNomeId ) {
                rotulos.add( super.read( parNomeId.getIDRotulo( ) ) );
            } // for
        } catch( Exception e ) {
            System.out.print( e.getMessage( ) );
        } // try-catch
        return ( rotulos );
    } // readAll ( )
    
} // ArquivoRotulo
