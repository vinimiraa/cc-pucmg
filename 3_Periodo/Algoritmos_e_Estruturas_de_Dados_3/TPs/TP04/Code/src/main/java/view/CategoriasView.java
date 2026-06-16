package view;

import controller.ArquivoCategoria;
import model.Categoria;
import util.IO;

/**
 *  Classe CategoriasView
 * 
 *  <p>Classe que representa a interface de usuário para manipulação de categorias.</p>
 * 
 *  @see PrincipalView
 */
public class CategoriasView extends PrincipalView
{
    private static ArquivoCategoria arqCategorias;

    public CategoriasView ( ) throws Exception {
        arqCategorias = new ArquivoCategoria( );
    } // MenuCategorias ( )

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
        System.out.println("> Início > Categorias    ");
        System.out.println("1 - Buscar               ");
        System.out.println("2 - Incluir              ");
        System.out.println("3 - Alterar              ");
        System.out.println("4 - Excluir              ");
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
        } // switch
    } // executar_opcao ( )

    private static Categoria lerCategoria( )
    {
        String nome = IO.lerString("\nNome da categoria (min. de 5 letras): ", 5, 50);
        return ( new Categoria( nome ) );
    } // lerCategoria ( )

    public static void incluirCategoria( ) 
    {
        System.out.println( "\n> Incluir categoria:" );
        
        Categoria novaCategoria = lerCategoria( );

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
                } // try-catch
            } // if

        } else {
            System.out.println( RED + "Operação cancelada!" + RESET );
        } // if 
    } // incluirCategoria ( )

    public static void buscarCategoria( ) throws Exception
    {
        System.out.println( "\n> Buscar Categoria:" );
    
        try 
        {
            if( IO.listarCategorias( arqCategorias ) )
            {

                System.out.print( "ID da Categoria: " );
                int id = Integer.parseInt( console.nextLine( ) );
        
                Categoria categoriaEncontrada = arqCategorias.read( id );
        
                if( categoriaEncontrada != null ) {
                    System.out.println( GREEN + categoriaEncontrada + RESET );
                } else {
                    System.out.println( RED + "Categoria não encontrada." + RESET );
                } // if
            } // if

        } catch( NumberFormatException e ) {
            System.out.println( RED + "ID inválido. Operação cancelada!" + RESET );
        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível buscar a categoria!" + RESET );
        } // try-catch
    } // buscarCategoria ( )

    public static void alterarCategoria( ) 
    {
        System.out.println( "\n> Alterar Categoria:" );
    
        try 
        {
            if( IO.listarCategorias( arqCategorias ) )
            {

                System.out.print( "ID da Categoria: " );
                int id = Integer.parseInt( console.nextLine( ) );
        
                Categoria categoriaEncontrada = arqCategorias.read( id );
        
                if( categoriaEncontrada != null ) 
                {
                    Categoria novaCategoria = lerCategoria();
        
                    if( novaCategoria != null && novaCategoria.getNome().length() > 0 ) 
                    {
                        novaCategoria.setId( id );
                        arqCategorias.update( novaCategoria );
                        System.out.println( GREEN + "Categoria alterada com sucesso." + RESET );
                    } else {
                        System.out.println( RED + "Operação cancelada!" + RESET );
                    } // if

                } else {
                    System.out.println( RED + "Categoria não encontrada." + RESET );
                } // if
            } // if

        } catch( NumberFormatException e ) {
            System.out.println(RED + "ID inválido. Operação cancelada!" + RESET);
        } catch( Exception e ) {
            System.out.println(RED + "Erro no sistema. Não foi possível alterar a categoria!" + RESET);
        } // try-catch
    } // alterarCategoria ( )
    
    public static void excluirCategoria( ) 
    {
        System.out.println( "\n> Excluir Categoria:" );

        try 
        {
            if( IO.listarCategorias( arqCategorias ) )
            {
                System.out.print( "ID da Categoria: " );
                int id = Integer.parseInt( console.nextLine( ) );
    
                Categoria categoriaEncontrada = arqCategorias.read( id );
    
                if( categoriaEncontrada != null ) 
                {
                    System.out.print( "\nCategoria:" );
                    System.out.println( categoriaEncontrada );
    
                    System.out.println( "\nConfirma a exclusão da categoria? (S/N)" );
                    char resp = console.nextLine( ).charAt( 0 );
    
                    if( resp == 'S' || resp == 's' ) 
                    {
                        boolean sucesso = arqCategorias.delete(id);
    
                        if( sucesso ) {
                            System.out.println( GREEN + "Categoria excluída com sucesso." + RESET );
                        } else {
                            System.out.println( RED + "Erro: Não foi possível excluir a categoria porque ela possui tarefas associadas." + RESET );
                        } // if
                    } // if
    
                } else {
                    System.out.println(RED + "Categoria não encontrada." + RESET);
                } // if
            } // if

        } catch (NumberFormatException e) {
            System.out.println(RED + "ID inválido. Operação cancelada!" + RESET);
        } catch (Exception e) {
            System.out.println(RED + "Erro no sistema. Não foi possível excluir a categoria!" + RESET);
        } // try-catch
    } // excluirCategoria ( )
    
} // CategoriasView