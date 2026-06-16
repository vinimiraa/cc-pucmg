package app;

import java.util.List;

import model.Categoria;
import service.ArquivoCategoria;

/**
 *  MenuCategorias: Classe de interação com o usuário para manipulação de categorias.
 */
public class MenuCategorias extends IO
{
    private static ArquivoCategoria arqCategorias;

    public MenuCategorias ( ) throws Exception {
        arqCategorias = new ArquivoCategoria( );
    } // end MenuCategorias ( )

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
            } while( opcao != 0 ); // end do-while
        } catch ( Exception e ) {
            e.printStackTrace();
        } // end try-catch
    } // end menu ( )

    protected static void opcoes_menu( )
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início > Categorias    ");
        System.out.println("1 - Buscar               ");
        System.out.println("2 - Incluir              ");
        System.out.println("3 - Alterar              ");
        System.out.println("4 - Excluir              ");
        System.out.println("0 - Voltar               ");
        System.out.print  ("Opção: "                  );
    } // end opcoes_menu ( )

    protected static void executar_opcao( int opcao )
    {
        switch( opcao ) 
        {
            case 0:
                break;
            case 1:
                buscarCategoria( );
                break;
            case 2:
                incluirCategoria( );
                break;
            case 3:
                alterarCategoria( );
                break;
            case 4:
                excluirCategoria( );
                break;
            
            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // end switch
    } // end executar_opcao ( )

    private static void listarCategorias( List<Categoria> lista )
    {
        if( lista != null ) 
        {
            System.out.println( "\nLista de categorias:" );
            int tam = lista.size( );
            for( int i = 0; i < tam; i++ ) {
                System.out.println( (i+1) + ": " + lista.get(i).getNome() );
            } // end for
        } // end if
    } // end listarCategorias ( )

    private static Categoria ler_Categoria( )
    {
        String nome = "";
        boolean dadosCompletos = false;
        do 
        {
            System.out.print( "\nNome da categoria (min. de 5 letras): " );
            nome = console.nextLine( );

            if( nome.length( ) >= 5 || nome.length( ) == 0 ) {
                dadosCompletos = true;
            } else {
                System.err.println( "O nome da categoria deve ter no mínimo 5 caracteres." );
            } // end if
        } while( dadosCompletos == false ); // end do-while

        return ( new Categoria( nome ) );
    } // end ler_Categoria ( )

    public static void incluirCategoria( ) 
    {
        System.out.println( "\n> Incluir categoria:" );
        
        Categoria novaCategoria = ler_Categoria( );

        if( novaCategoria != null && novaCategoria.getNome().length() > 0 ) 
        {
            System.out.println( "Confirma a inclusão da categoria? (S/N)" );
            char resp = console.nextLine().charAt(0);

            if( resp=='S' || resp=='s' ) 
            {
                try 
                {
                    arqCategorias.create( novaCategoria );
                    System.out.println( GREEN + "Categoria criada com sucesso." + RESET);
                } catch( Exception e ) {
                    System.out.println( RED + "Erro do sistema. Não foi possível criar a categoria!" + RESET );
                } // end try-catch
            } // end if
        } else {
            System.out.println( RED + "Operação cancelada!" + RESET );
        } // end if 
    } // end incluirCategoria ( )

    public static void buscarCategoria( ) 
    {
        System.out.println( "\n> Buscar Categoria:" );
        
        try 
        {
            List<Categoria> lista = arqCategorias.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Não há categoria cadastrada." + RESET );
            } 
            else 
            {
                listarCategorias( lista );

                System.out.print( "Nome da Categoria: " );
                String nome = console.nextLine(); 
                
                if( nome.length() > 0 ) 
                {
                    Categoria categoriaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size( );
                    for( int i = 0; i < tam && !encontrada; i++ )
                    {
                        if( lista.get(i).getNome().equalsIgnoreCase(nome) ) 
                        { 
                            categoriaEncontrada = lista.get(i);
                            encontrada = true;
                        }//end if
                    } // end for
        
                    if( categoriaEncontrada != null ) {
                        System.out.println( GREEN + categoriaEncontrada + RESET );
                    } else {
                        System.out.println( RED + "Categoria não encontrada." + RESET );
                    }//end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.err.println( RED + "Erro no sistema. Não foi possível buscar a categoria!" + RESET );
        } //end try
    } // end buscarCategoria ( )

    public static void alterarCategoria( ) 
    {
        System.out.println( "\n> Alterar Categoria:" );
    
        try 
        {
            List<Categoria> lista = arqCategorias.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Não há categoria cadastrada." + RESET );
            } 
            else
            {
                System.out.println( "\nLista de categorias:" );
                listarCategorias( lista );

                System.out.print( "Nome da Categoria: " );
                String nome = console.nextLine(); 

                if( nome.length() > 0 ) 
                {
                    Categoria categoriaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size( );
                    for( int i = 0; i < tam && !encontrada; i++ )
                    {
                        if( lista.get(i).getNome().equalsIgnoreCase(nome) ) 
                        { 
                            categoriaEncontrada = lista.get(i);
                            encontrada = true;
                        }//end if
                    } // end for

                    if( categoriaEncontrada != null ) 
                    {
                        Categoria novaCategoria = ler_Categoria();
                        
                        if( novaCategoria != null && novaCategoria.getNome().length() > 0 )
                        {  
                            novaCategoria.setId( categoriaEncontrada.getId() );
                            arqCategorias.update( novaCategoria );
                            System.out.println( GREEN + "Categoria alterada com sucesso." + RESET );
                        } else {
                            System.out.println( RED + "Operação cancelada!" + RESET );
                        }// end if
                    } else {
                        System.out.println( RED + "Categoria não encontrada." + RESET );
                    }//end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível alterar a categoria!" + RESET );
        }//end try
    } // end alterarCategoria
    
    public static void excluirCategoria( ) 
    {
        System.out.println( "\n> Excluir Categoria:" );

        try 
        {
            List<Categoria> lista = arqCategorias.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Não há categoria cadastrada." + RESET );
            } 
            else
            {
                System.out.println( "\nLista de categorias:" );
                listarCategorias( lista );

                System.out.print("Nome da categoria: ");
                String nome = console.nextLine(); 

                if( nome.length() > 0 )
                {
                    Categoria categoriaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size( );
                    for( int i = 0; i < tam && !encontrada; i++ )
                    {
                        if( lista.get(i).getNome().equalsIgnoreCase(nome) ) 
                        { 
                            categoriaEncontrada = lista.get(i);
                            encontrada = true;
                        }//end if
                    } // end for
        
                    if( categoriaEncontrada != null ) 
                    {
                        System.out.print  ( "\nCategoria:" );
                        System.out.println( categoriaEncontrada );

                        System.out.println("\nConfirma a exclusão da categoria? (S/N)");
                        char resp = console.nextLine().charAt(0);  
            
                        if( resp == 'S' || resp == 's' ) 
                        {
                            boolean sucesso = arqCategorias.delete( categoriaEncontrada.getId() );

                            if( sucesso ) {
                                System.out.println( GREEN + "Categoria excluída com sucesso." + RESET );
                            } else {
                                System.out.println( RED + "Erro: Não foi possível excluir a categoria." + RESET );
                            }// end if
                        }// end if
                    } else {
                        System.out.println(RED + "Categoria não encontrada." + RESET);
                    } //end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível excluir a categoria!" + RESET );
        } // end try
    } //end excluirCategoria
    
} // end class MenuCategorias1