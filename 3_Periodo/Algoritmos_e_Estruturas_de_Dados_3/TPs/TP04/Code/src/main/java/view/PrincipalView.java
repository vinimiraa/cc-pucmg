package view;

import java.util.Scanner;

/**
 *  Classe PrincipalView
 * 
 *  <p>Classe que representa a interface de usuário principal do sistema.</p>
 * 
 *  @see CategoriasView
 *  @see TarefasView
 */
public class PrincipalView 
{
    protected static Scanner console = new Scanner( System.in );
    protected static final String GREEN = "\u001B[32m";
    protected static final String RED   = "\u001B[31m";
    protected static final String RESET = "\u001B[0m";
    public static void main( String[] args ) 
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
        } catch( Exception e ) {
            e.printStackTrace( );
        } finally {
            console.close( );
        }// try-catch
    } // main ( )

    protected static void opcoes_menu( ) 
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início                 ");
        System.out.println("1 - Categorias           ");
        System.out.println("2 - Tarefas              ");
        System.out.println("3 - Gerenciar Backups    ");
        System.out.println("0 - Sair                 ");
        System.out.print  ("Opção: "                  );
    } // pause ( )

    protected static int ler_opcao( )
    {
        int opcao = 0;
        try {
            opcao = Integer.valueOf( console.nextLine() );
        } catch( NumberFormatException e ) {
            opcao = -1;
        } // try-catch
        return opcao;
    } // ler_opcao ( )

    protected static void executar_opcao( int opcao ) throws Exception
    {
        switch( opcao ) 
        {
            case 0:
                System.out.println("Saindo...");
                break;
            case 1:
                (new CategoriasView( )).menu( );
                break;
            case 2:
                (new TarefasView( )).menu( );
                break;
            case 3:
                (new BackupView( )).menu( );
                break;
            
            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // switch
    } // executar_opcao ( )

} // PrincipalView
