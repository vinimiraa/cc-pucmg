package controller;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.ArrayList;

import model.LZW;

public class Backup 
{
    private static final String RED   = "\u001B[31m";
    private static final String RESET = "\u001B[0m";
    private static final String BACKUP_DIR = ".\\backups";
    private static final String DATA_DIR = ".\\data";

    public Backup( ) 
    {
        createDirectory( BACKUP_DIR );
        createDirectory( DATA_DIR );
    } // Backup ( )

    public String getBackupDir( ) 
    {
        return ( BACKUP_DIR );
    } // getBackupDir ( )

    public String getDataDir( ) 
    {
        return ( DATA_DIR );
    } // getDataDir ( )

    private void createDirectory( String path ) 
    {
        File dir = new File( path );
        if( !dir.exists( ) ) {
            dir.mkdirs( );
        } // if
    } // createDirectory ( )

    private byte[] serializeFiles( File[] files ) 
    {
        byte[] bytes = null;
        try 
        {
            ByteArrayOutputStream baos = new ByteArrayOutputStream( );
            DataOutputStream dos = new DataOutputStream(baos);
            for( File file : files ) 
            {
                if( file.isFile( ) ) 
                {
                    dos.writeUTF( file.getName( ) ); // nome do arquivo
                    byte[] fileBytes = readFile( file ); 
                    dos.writeInt( fileBytes.length );
                    dos.write( fileBytes );
                } // if
            } // for
            bytes = baos.toByteArray();
        } catch( IOException e ) {
            System.err.println( "Erro ao serializar arquivos: " + e.getMessage( ) );
        } // try-catch ( )
        return ( bytes );
    } // serializeFiles ( )

    private byte[] readFile( File file ) throws IOException 
    {
        try( FileInputStream fis = new FileInputStream( file ) ) {
            return ( fis.readAllBytes( ) );
        } // try
    } // readFile ( )

    private void writeFile( String filepath, byte[] data ) 
    {
        try( FileOutputStream fos = new FileOutputStream( filepath ) ) {
            fos.write( data );
        } catch( IOException e ) {
            System.err.println( "Erro ao escrever arquivo: " + e.getMessage( ) );
        } // try-catch
    } // writeFile ( )

    public double calculateCompressRatio( byte[] dataOriginal, byte[] dataCompressed ) 
    {
        int tamanhoOriginal = dataOriginal.length;
        int tamanhoComprimido = dataCompressed.length;
    
        double taxaCompressao = (1 - ((double) tamanhoComprimido / tamanhoOriginal)) * 100;
        return taxaCompressao;
    } // calculateCompressRatio ( )
    
    public void createBackup( String backupFile )
    {
        try
        {
            createDirectory( BACKUP_DIR );
            File dataDir = new File( DATA_DIR );

            String subDirPath = BACKUP_DIR + "\\" + backupFile.replace(".db", "");
            createDirectory( subDirPath );
    
            if( !dataDir.exists( ) ) {
                System.err.println( RED + "Diretório de dados não encontrado." + RESET );
            } 
            else
            {
                File[] files = dataDir.listFiles( );
                if( files != null ) 
                {
                    byte[] dataOrig = serializeFiles(files);
                    byte[] dataCompressed = LZW.codifica(dataOrig);
    
                    double compressRatio = calculateCompressRatio( dataOrig, dataCompressed );
                    System.out.printf( "Taxa de compressão: %.2f%%\n", compressRatio );

                    writeFile( subDirPath + "\\" + backupFile, dataCompressed );
                } // if
            } // if
        } catch( Exception e ) {
            System.out.println( "Erro ao realizar o backup: " + e.getMessage( ) );
        } // try-catch
    } // createBackup ( )

    public void restoreBackup( String backupFile )
    {
        File backup = new File( BACKUP_DIR + "\\" + backupFile );

        if( !backup.exists( ) ) 
        {
            File subDir = new File( BACKUP_DIR + "\\" + backupFile.replace(".db", "") );
            backup = new File( subDir, backupFile );
        } // if

        if( !backup.exists( ) ) {
            System.err.println( RED + "Arquivo de backup não encontrado." + RESET );
        }
        else
        {
            try 
            {
                byte[] backupData = readFile( backup );
                backupData = LZW.decodifica( backupData );

                ByteArrayInputStream bais = new ByteArrayInputStream( backupData );
                DataInputStream dis = new DataInputStream( bais );  
                clearDirectory( DATA_DIR );

                while( dis.available() > 0 ) 
                {
                    String fileName = dis.readUTF( );
                    int fileSize = dis.readInt( );
                    byte[] fileBytes = new byte[fileSize];
                    dis.readFully( fileBytes );

                    writeFile( DATA_DIR + "\\" + fileName, fileBytes );
                } // while

            } catch( Exception e ) {
                System.err.println( "Erro ao recuperar o backup: " + e.getMessage( ) );
            } // try-catch
        } // if
    } // restoreBackup ( )

    private void clearDirectory( String dirPath ) 
    {
        File dir = new File( dirPath );
        if( dir.exists( ) ) 
        {
            File[] files = dir.listFiles( );
            if( files != null ) 
            {
                for( File file : files ) 
                {
                    if( file.isFile( ) ) {
                        file.delete( );
                    } 
                    else if( file.isDirectory( ) ) 
                    {
                        clearDirectory( file.getPath( ) );
                        file.delete( );
                    } // if
                } // for
            } // if
        } // if
    } // clearDirectory ( )

    public ArrayList<String> listBackups( ) 
    {
        ArrayList<String> backups = new ArrayList<>( );
        File backupDir = new File( BACKUP_DIR );
        File[] subDirs = backupDir.listFiles( File::isDirectory );

        if( subDirs == null || subDirs.length == 0 ) {
            System.out.println( RED + "Nenhum backup encontrado." + RESET );
        } 
        else 
        {
            System.out.println( "\nBackups disponíveis:" );
            for( int i = 0; i < subDirs.length; i++ ) {
                System.out.println((i + 1) + ": " + subDirs[i].getName());
                backups.add( subDirs[i].getName( ) );
            } // for
        } // if
        return ( backups );
    } // listBackup ( )

} // Backup 
