package app;

import java.util.Scanner;

/**
 *  IO: Classe de entrada e saída de dados do usuário.
 */
public class IO 
{
    protected static Scanner console = new Scanner( System.in );
    protected static final String GREEN = "\u001B[32m";
    protected static final String RED = "\u001B[31m";
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
            } while( opcao != 0 ); // end do-while
        } catch ( Exception e ) {
            e.printStackTrace();
        } finally {
            console.close( );
        }// end try-catch
    } // end main ( )

    protected static void opcoes_menu( ) 
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início                 ");
        System.out.println("1 - Categorias           ");
        System.out.println("2 - Tarefas              ");
        System.out.println("0 - Sair                 ");
        System.out.print  ("Opção: "                  );
    } // end pause ( )

    protected static int ler_opcao( )
    {
        int opcao = 0;
        try {
            opcao = Integer.valueOf( console.nextLine() );
        } catch( NumberFormatException e ) {
            opcao = -1;
        } // end try-catch
        return opcao;
    } // end ler_opcao ( )

    protected static void executar_opcao( int opcao ) throws Exception
    {
        switch( opcao ) 
        {
            case 0:
                System.out.println("Saindo...");
                break;
            case 1:
                (new MenuCategorias( )).menu( );
                break;
            case 2:
                (new MenuTarefas()).menu();
                break;
            
            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // end switch
    } // end executar_opcao ( )

} // end class IO
