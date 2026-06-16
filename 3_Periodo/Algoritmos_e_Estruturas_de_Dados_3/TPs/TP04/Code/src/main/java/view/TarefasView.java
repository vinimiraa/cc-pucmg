package view;

import java.time.LocalDate;
import java.util.ArrayList;

import controller.ArquivoCategoria;
import controller.ArquivoTarefa;
import controller.ArquivoRotulo;
import model.Tarefa;
import util.IO;

/**
 *  Classe TarefasView
 * 
 *  <p>Classe que representa a interface de usuário para manipulação de tarefas.</p>
 * 
 *  @see PrincipalView
 */
public class TarefasView extends PrincipalView 
{
    private static ArquivoTarefa arqTarefas;
    private static ArquivoCategoria arqCategorias;
    private static ArquivoRotulo arqRotulos;

    public TarefasView( ) throws Exception 
    {
        arqTarefas = new ArquivoTarefa();
        arqCategorias = new ArquivoCategoria();
        arqRotulos = new ArquivoRotulo();
    } // MenuTarefas ( )

    public void menu( ) 
    {
        try 
        {
            int opcao = 0;
            do 
            {
                opcoes_menu( );
                opcao = ler_opcao( );
                executar_opcao( opcao );
            } while( opcao != 0 ); // do-while
        } catch( Exception e ) {
            e.printStackTrace( );
        } // try-catch
    } // menu ( )

    protected static void opcoes_menu( ) 
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início > Tarefas       ");
        System.out.println("1 - Buscar               ");
        System.out.println("2 - Incluir              ");
        System.out.println("3 - Alterar              ");
        System.out.println("4 - Excluir              ");
        System.out.println("5 - Gerenciar Rótulos    ");
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
                buscarTarefa( );
                break;
            case 2:
                incluirTarefa( );
                break;
            case 3:
                alterarTarefa( );
                break;
            case 4:
                excluirTarefa( );
                break;
            case 5:
                (new RotuloView( )).menu( );
                break;

            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // switch
    } // executar_opcao ( )

    public static Tarefa lerTarefa( )
    {
        Tarefa tarefa = null;
        try
        {
            String nome = IO.lerString( "\nNome: ", 3, 120 );

            if( nome.length( ) > 0 )
            {

                LocalDate dataCriacao = IO.lerData( "\nData de Criação (dd/MM/yyyy): " );
                LocalDate dataConclusao = IO.lerData( "\nData de Conclusão (dd/MM/yyyy): " );
                byte status = IO.lerOpcaoNumerica( "Status", 5 );
                byte prioridade = IO.lerOpcaoNumerica( "Prioridade", 5 );
                int idCategoria = IO.lerIdCategoria( arqCategorias );  

                tarefa = new Tarefa( nome, dataCriacao, dataConclusao, status, prioridade, idCategoria );

            } else {
                System.out.println( RED + "Operação cancelada!" + RESET );
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "\nErro ao ler tarefa!" + RESET );
        } // try-catch
        return tarefa;
    } // lerTarefa ( )

    public static void incluirTarefa( ) 
    {
        System.out.println( "\n> Incluir Tarefa:" );

        try 
        {
            if( arqCategorias.exitemCategorias( ) == false )
            {
                System.out.println( RED + "Não há categorias cadastradas!" + RESET );
            } 
            else 
            {
                Tarefa novaTarefa = lerTarefa( );
                if( novaTarefa != null ) 
                {
                    System.out.println( "\nConfirma inclusão da tarefa? (S/N)" );
                    char resp = console.nextLine().charAt(0);
                
                    if( resp == 'S' || resp == 's' ) 
                    {
                        try {
                            arqTarefas.create( novaTarefa );
                            System.out.println( GREEN + "Tarefa incluída com sucesso!" + RESET );
                        } catch( Exception e ) {
                            System.out.println( RED + "Erro do sistema. Não foi possível criar a tarefa!" + RESET );
                        } // try-catch
                    } else {
                        System.out.println( RED + "Inclusão cancelada!" + RESET );
                    } // if
                } // if
            } // if
            
        } catch( Exception e ) {
            System.out.println( RED + "Erro ao incluir tarefa!" + RESET );
        } // try-catch
    } // incluirTarefa ( )

    private static void buscarPorID( ) 
    {
        System.out.println( "\n> Buscar Tarefa por ID:" );

        try 
        {
            if( IO.listarTarefas( arqTarefas ) ) 
            {
                String input = IO.lerString( "ID da Tarefa: ", 1, 5 );
    
                if( input.length() > 0 ) 
                {
                    int id = Integer.parseInt( input );
                    Tarefa tarefa = arqTarefas.read( id );
    
                    if( tarefa != null ) {
                        System.out.println( GREEN + tarefa + RESET );
                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    } // if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // if
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro ao buscar tarefa por identificador!" + RESET );
        } // try-catch
    } // buscarPorID ( )

    private static void buscarPorNome( )
    {
        System.out.println( "\n> Buscar Tarefa por Nome Completo:" );

        try 
        {
            String nome = IO.lerString( "\nNome da Tarefa: ", 3, 50 );
    
            if( nome.length() > 0 ) 
            {
                ArrayList<Tarefa> tarefas = arqTarefas.readAll( );
                
                boolean encontrou = false;
                int tam = tarefas.size( );
                for( int i = 0; i < tam && !encontrou; i++ ) 
                {
                    Tarefa tarefa = tarefas.get( i );
                    if( tarefa.getNome().equals( nome ) ) 
                    {
                        System.out.println( GREEN + tarefa + RESET );
                        encontrou = true;
                    } // if
                } // for
    
                if( !encontrou ) {
                    System.out.println( RED + "Tarefa não encontrada." + RESET );
                } // if
    
            } else {
                System.out.println( RED + "Operação cancelada!" + RESET );
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro ao buscar tarefa por nome completo!" + RESET );
        } // try-catch
    } // buscarPorNome ( )

    private static void buscarPorCategoria( )
    {
        System.out.println( "\n> Buscar Tarefa por Categoria:" );

        try 
        {
            if( IO.listarCategorias( arqCategorias ) )
            {
                System.out.print( "ID da Categoria: " );
                int idCategoria = Integer.parseInt( console.nextLine( ) );
                
                if( idCategoria > 0 ) 
                {
                    ArrayList<Tarefa> tarefas = arqTarefas.readAll( idCategoria );
    
                    if( tarefas.isEmpty( ) ) {
                        System.out.println( RED + "Não há tarefas cadastradas!" + RESET );
                    } 
                    else 
                    {
                        System.out.println( "\nLista de tarefas:" );
                        for( Tarefa tarefa : tarefas ) {
                            System.out.println( GREEN + tarefa + RESET );
                        } // for
                    } // if
    
                } else {
                    System.out.println( RED + "ID inválido!" + RESET );
                } // if
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro buscar tarefa por categoria!" + RESET );
        } // try-catch
    } // buscarPorCategoria ( )

    public static void buscarPorRotulo( )
    {
        System.out.println( "\n> Buscar Tarefa por Rótulo:" );

        try 
        {
            if( IO.listarRotulos( arqRotulos ) ) 
            {
                System.out.print( "ID do Rótulo: " );
                String input = console.nextLine( );
                
                if( input.length() > 0 ) 
                {
                    int idRotulo = Integer.parseInt( input );

                    ArrayList<Tarefa> tarefas = arqTarefas.readAllByRotulo( idRotulo );
    
                    if( tarefas.isEmpty( ) ) {
                        System.out.println( RED + "Não há tarefas cadastradas!" + RESET );
                    } 
                    else 
                    {
                        System.out.println( "\nLista de tarefas:" );
                        for( Tarefa tarefa : tarefas ) {
                            System.out.println( GREEN + tarefa + RESET );
                        } // for
                    } // if

                } else {
                    System.out.println( RED + "Operação Cancelada!" + RESET );
                } // if
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro ao buscar tarefa por rótulo!" + RESET );
        } // try-catch
    }

    public static void buscarTarefa( ) 
    {
        System.out.println( "\n> Buscar Tarefa:" );
    
        try 
        {
            System.out.println( "1. Buscar por ID            " );
            System.out.println( "2. Buscar por Nome Completo " );
            System.out.println( "3. Buscar por Categoria     " );
            System.out.println( "4. Buscar por Rótulo        " );
            System.out.println( "0. Cancelar                 " );
            System.out.print  ( "Opção: " );

            int opcao = Integer.parseInt( console.nextLine( ) );

            switch ( opcao ) 
            {
                case 0:
                    break;
                case 1:
                    buscarPorID( );
                    break;
                case 2:
                    buscarPorNome( );
                    break;
                case 3:
                    buscarPorCategoria( );
                    break;
                case 4:
                    buscarPorRotulo( );
                    break;
                default:
                    System.out.println( RED + "Opção inválida!" + RESET );
                    break;
            } // switch

        } catch( Exception e ) {
            System.out.println( RED + "Erro ao buscar tarefa!" + RESET );
        } // try-catch
    } // buscarTarefa ( )
    
    public static void alterarTarefa( ) 
    {
        System.out.println( "\n> Alterar Tarefa:" );
    
        try 
        {
            if( IO.listarTarefas( arqTarefas ) ) 
            {
                System.out.print( "ID da Tarefa: " );
                String input = console.nextLine( );
    
                if( input.length() > 0 ) 
                {
                    int id = Integer.parseInt( input );
                    Tarefa tarefaAtual = arqTarefas.read( id );
    
                    if( tarefaAtual != null ) 
                    {
                        System.out.println( "\nDados atuais:" );
                        System.out.println( tarefaAtual );
    
                        System.out.println( "\nInforme os novos dados:" );
                        Tarefa novaTarefa = lerTarefa( );
    
                        if( novaTarefa != null ) 
                        {
                            novaTarefa.setId( id );
                            arqTarefas.update( novaTarefa );
                            System.out.println( GREEN + "Tarefa alterada com sucesso." + RESET );
                        } // if

                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    } // if
                    
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // if
            } // if

        } catch (Exception e) {
            System.out.println( RED + "Erro ao alterar tarefa!" + RESET );
        } // try-catch
    } // alterarTarefa ( )
    
    public static void excluirTarefa( ) 
    {
        System.out.println( "\n> Excluir Tarefa:" );
    
        try 
        {
            if( IO.listarTarefas( arqTarefas ) ) 
            {
                System.out.print( "ID da Tarefa: " );
                String input = console.nextLine( );
    
                if( input.length() > 0 ) 
                {
                    int id = Integer.parseInt( input );
                    Tarefa tarefa = arqTarefas.read( id );
    
                    if( tarefa != null ) 
                    {
                        System.out.println( "\nTarefa:" );
                        System.out.println( tarefa );
    
                        System.out.println( "\nConfirma a exclusão da tarefa? (S/N)" );
                        char resp = console.nextLine( ).charAt( 0 );
    
                        if( resp == 'S' || resp == 's' ) 
                        {
                            boolean sucesso = arqTarefas.delete(id);
    
                            if( sucesso ) {
                                System.out.println( GREEN + "Tarefa excluída com sucesso." + RESET );
                            } else {
                                System.out.println( RED + "Erro: Não foi possível excluir a tarefa." + RESET );
                            } // if
                        } else {
                            System.out.println( RED + "Operação cancelada!" + RESET );
                        } // if

                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    } // if

                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // if

            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro ao excluir tarefa!" + RESET );
        } // try-catch
    } // excluirTarefa ( )

} // TarefasView
