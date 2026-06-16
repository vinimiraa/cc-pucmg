/*
 *  -------------------------- Documentacao
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP01Q08 - 13 / 03 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Arquivo.java
 *       Windows: javac Arquivo.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Arquivo
 *       Windows: java Arquivo
 *   
*/

import java.io.RandomAccessFile;

public class Arquivo 
{
    /**
     *  Funcao principal
     *  @param args
     */
    public static void main ( String[] args )
    {
        MyIO.setCharset("UTF-8");

        int n = 0; 
        String filename = "ARQUIVO.TXT";

        n = MyIO.readInt();

        writeDoubleToFile( n, filename);
        
        readDoubleFromFile( n, filename );
    } // end main ( )

    /**
     *  Funcao para escrever numero real no arquivo.
     *  @param input - Double: Numero real a ser escrito no arquivo.
     *  @param filename - String: Nome do arquivo.
     */
    public static void writeDoubleToFile( int n, String filename )
    {
        try 
        {
            RandomAccessFile file = new RandomAccessFile( filename, "rw" );
            for( int x = 0; x < n; x = x + 1 )
            {
                double input = MyIO.readDouble();
                file.writeDouble( input );
            } // end for
            file.close();
        } 
        catch( Exception e )
        {
            MyIO.println( "ERRO: " + e.getMessage() );
        } // end try catch
    } // end writeDoubleToFile ( )

    /**
     *  Funcao para ler numero real do arquivo e mostrar na tela.
     *  @param filename - String: Nome do Arquivo.
     */
    public static void readDoubleFromFile( int n, String filename )
    {
        try 
        {
            RandomAccessFile file = new RandomAccessFile( filename, "rw" );
            int fileLen = (int)file.length();
            for( int x = 0; x < n; x = x + 1 )
            {
                fileLen -= 8;
                file.seek(fileLen);
                double value = file.readDouble();
                if( value == (int)value )
                {  
                    MyIO.println( (int)value );
                }
                else
                {
                    MyIO.println( value );
                } // end if
            } // end for
            file.close();
        } 
        catch( Exception e )
        {
            MyIO.println( "ERRO: " + e.getMessage() );
        } // end try catch
    } // end readDoubleToFile ( )

} // end class
