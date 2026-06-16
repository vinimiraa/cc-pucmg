package model;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import util.IO;

public class StopWords 
{
    private static final String arquivoStopWords = ".\\code\\src\\main\\java\\model\\stopword.txt";
    private static ArrayList<String> stopWords = new ArrayList<String>( );

    public StopWords( )
    {
        File arquivo = null;
        try
        {
            arquivo = new File( arquivoStopWords );
            if( !arquivo.exists( ) )
            {
                System.out.println( "Arquivo de stop words não encontrado." );
            }
            else
            {
                Scanner leitor = new Scanner( arquivo );
                while( leitor.hasNext( ) )
                {
                    String palavra = leitor.next( );
                    stopWords.add( IO.strnormalize( palavra.trim( ) ) );
                } // while
                leitor.close( );
            } // if-else
        } catch( FileNotFoundException e ) {
            System.out.println( "Erro ao abrir o arquivo de stop words." );
        } // try-catch
    } // StopWords ( )

    public boolean isStopWord( String palavra ) {
        return stopWords.contains( IO.strnormalize( palavra ) );
    } // isStopWord ( )

    public ArrayList<String> getStopWords( ) {
        return stopWords;
    } // getStopWords ( )

    public void addStopWord( String palavra ) {
        stopWords.add( IO.strnormalize( palavra ) );
    } // addStopWord ( )

    public void removeStopWord( String palavra ) {
        stopWords.remove( IO.strnormalize( palavra ) );
    } // removeStopWord ( )

    public int size( ) {
        return stopWords.size( );
    } // size ( )

    public boolean isEmpty( ) {
        return stopWords.isEmpty( );
    } // isEmpty ( )

} // StopWords