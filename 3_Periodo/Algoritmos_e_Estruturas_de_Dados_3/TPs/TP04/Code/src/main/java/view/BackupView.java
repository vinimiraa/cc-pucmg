package view;

import java.util.ArrayList;

import controller.Backup;
import util.IO;

class BackupView extends PrincipalView
{
    private static Backup backup;

    public BackupView ( ) throws Exception {
        backup = new Backup( );
    } // BackupView ( )

    public void menu ( ) 
    {
        try
        {
            int opcao = 0;
            do 
            {
                opcoes_menu( );
                opcao = ler_opcao( );
                executar_opcao(opcao);
            } while( opcao != 0 ); // do-while
        } catch ( Exception e ) {
            e.printStackTrace();
        } // try-catch
    } // menu ( )

    protected static void opcoes_menu( )
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início > Backup        ");
        System.out.println("1 - Realizar Backup      ");
        System.out.println("2 - Restaurar Backup     ");
        System.out.println("0 - Voltar               ");
        System.out.print  ("Opção: "                  );
    } // opcoes_menu ( )

    protected static void executar_opcao( int opcao ) throws Exception
    {
        switch( opcao ) 
        {
            case 0:
                break;
            case 1:
                realizarBackup( );
                break;
            case 2:
                restaurarBackup( );
                break;
            
            default:
                System.err.println("Opção inválida.");
        } // switch
    } // executar_opcao( )

    public static void realizarBackup( ) throws Exception
    {
        System.out.println( "\n> Relizando Backup:" );
        try
        {
            System.out.println( "\nConfirma a realização do backup? (S/N)" );
            char resp = console.nextLine( ).charAt(0);

            if( resp == 'S' || resp == 's' ) 
            {
                backup.createBackup( IO.getDataHoraAtual( )+".db" );
                System.out.println( GREEN + "Backup realizado com sucesso." + RESET );
            } else {
                System.out.println( RED + "Operação cancelada." + RESET );
            } // if
        } catch ( Exception e ) {
            System.err.println( "Erro ao realizar backup." );
        } // try-catch
    } // realizarBackup ( )

    public static void restaurarBackup( ) throws Exception
    {
        System.out.println( "\n> Restaurar Backup:" );
        
        try
        {
            ArrayList<String> backupsList =  backup.listBackups( );

            if( !backupsList.isEmpty( ) ) 
            {
                System.out.print( "ID do arquivo de backup: " );
                String input = console.nextLine( );
    
                if( input.length( ) > 0 ) 
                {
                    int idBackup = Integer.parseInt( input );
                    backup.restoreBackup( backupsList.get( idBackup-1 )+".db" );
                    System.out.println( GREEN+ "Backup restaurado com sucesso." + RESET );
                } else {
                    System.err.println( RED + "ID inválido. Operação cancelada!" + RESET);
                } // if
                
            } // if
        } catch ( Exception e ) {
            System.err.println( "Erro ao restaurar backup." );
        } // try-catch
    } // restaurarBackup ( )

} // BackUpView
