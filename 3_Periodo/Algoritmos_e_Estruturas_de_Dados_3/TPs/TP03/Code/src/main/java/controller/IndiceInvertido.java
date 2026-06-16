package controller;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

import model.ListaInvertida;
import model.ElementoLista;
import model.StopWords;
import model.Tarefa;
import model.Rotulo;
import util.IO;

/**
 *  Classe IndiceInvertido
 *  
 *  <p>Classe que representa um índice invertido.</p>
 *  <p>Responsável por criar, atualizar, deletar e buscar no índice invertido.</p>
 *  
 *  @see StopWords
 *  @see ListaInvertida
 */
public class IndiceInvertido 
{
    private static StopWords      stopWords;
    private static ListaInvertida listaInvertida;
    private static ArquivoRotulo  arqRotulo;

    public IndiceInvertido( ) 
    {
        try
        {
            stopWords = new StopWords( );
            listaInvertida = new ListaInvertida( 
                4,
                "data\\ListaInvertida.db.dict.idx",
                "data\\ListaInvertida.db.bloc.idx"
            );
            arqRotulo = new ArquivoRotulo( );
        } catch( Exception e ) {
            System.out.println( "Erro ao criar o índice invertido." );
        } // try-catch
    } // IndiceInvertido ( )

    public ArrayList<String> getPalavras( String titulo ) 
    {
        ArrayList<String> palavras = new ArrayList<String>( );
        String[] partes = titulo.split( " " );
        for( int i = 0; i < partes.length; i++ )
        {
            String palavra = partes[i];
            if( !stopWords.isStopWord( palavra ) )
            {
                palavras.add( palavra );
            } // if
        } // for
        return palavras;
    } // getPalavras ( )

    private static float calcularFrequencia( String palavra, ArrayList<String> palavras ) 
    {
        float frequencia = 0;
        int tamTotal = palavras.size( );
        for( int i = 0; i < tamTotal; i++ )
        {
            String palavraAtual = IO.strnormalize( palavra );
            String palavraAtualLista = IO.strnormalize( palavras.get( i ) );
            if( palavraAtual.equals( palavraAtualLista ) ){
                frequencia++;
            } // if
        } // for
        return ( (float)frequencia / tamTotal );
    } // calcularFrequencia ( )

    public void insert( int idRotulo, int idTarefa )
    {
        try
        {
            Rotulo rotulo = arqRotulo.read( idRotulo );
            String palavra = rotulo.getNome( );
            listaInvertida.create( palavra, new ElementoLista( idTarefa, 1 ) );
        } catch( Exception e ) {
            System.out.println( "Erro ao criar o índice invertido." );
        } // try-catch
    } // insert ( )

    public void insert( String titulo, int id ) 
    {
        try
        {
            ArrayList<String> palavras = getPalavras( titulo );
            for( String palavra : palavras )
            {
                float frequencia = calcularFrequencia( palavra, palavras );
                // System.out.println( "Palavra: " + palavra + " - Frequência: " + frequencia );
                listaInvertida.create( palavra, new ElementoLista( id, frequencia ) );
                
                Rotulo rotulo = new Rotulo( palavra );
                arqRotulo.create( rotulo );
            } // for
        } catch( Exception e ) {
            System.out.println( "Erro ao criar o índice invertido." );
        } // try-catch
    } // insert ( )

    public boolean update( String tituloAntigo, String tituloNovo, int id ) 
    {
        boolean result = false;
        try
        {
            ArrayList<String> palavrasAntigas = getPalavras( tituloAntigo );
            for( String palavra : palavrasAntigas )
            {
                listaInvertida.delete( palavra, id );
            } // for
            this.insert( tituloNovo, id );
            
            result = true;
        } catch( Exception e ) {
            System.out.println( "Erro ao atualizar o índice invertido." );
        } // try-catch
        return ( result );
    } // update ( )

    public boolean delete( String palavra, int id ) 
    {
        boolean result = false;
        try
        {
            ArrayList<String> palavras = getPalavras( palavra );
            for( String palavraAtual : palavras )
            {
                result = listaInvertida.delete( palavraAtual, id );
            } // for
            result = true;
        } catch( Exception e ) {
            System.out.println( "Erro ao deletar o índice invertido." );
        } // try-catch
        return ( result );
    } // delete ( )

    private String getNomeRotuloByID( int idRotulo )
    {
        String nome = "";
        try 
        {
            ArrayList<Rotulo> rotulos = arqRotulo.readAll( );
            int tam = rotulos.size( );
            boolean achou = false;
            for( int i = 0; i < tam && !achou; i++ )
            {
                Rotulo rotulo = rotulos.get( i );
                if( rotulo.getId( ) == idRotulo )
                {
                    nome = rotulo.getNome( );
                    achou = true;
                } // if
            } // for
        } catch( Exception e ) {
            System.out.println( "Erro ao buscar o nome do rótulo." );
        }
        return ( nome );
    } // getNomeRotuloByID ( )

    /**
     *  ! IMPORTANTE: Esse método possui gambiarra. Talvez não funcione, mas não sei também.
     */
    public ArrayList<Tarefa> search( int idRotulo )
    {
        ArrayList<Tarefa> result = new ArrayList<Tarefa>( );
        try
        {
            String palavra = getNomeRotuloByID( idRotulo );

            ElementoLista[] elementos = listaInvertida.read( palavra );
            Arrays.sort( elementos, Comparator.comparing( ElementoLista::getFrequencia ).reversed( ) );

            ArquivoTarefa arquivoTarefa = new ArquivoTarefa();
            for( ElementoLista elemento : elementos ) 
            {
                if( elemento != null ) 
                {
                    Tarefa tarefa = arquivoTarefa.read(elemento.getId());
                    if( tarefa != null ) {
                        result.add(tarefa);
                    } // if
                } // if
            } // for
        } catch( Exception e ) {
            System.out.println( "Erro ao buscar no índice invertido." );
        } // try-catch
        return ( result );
    } // search ( )

} // IndiceInvertido
