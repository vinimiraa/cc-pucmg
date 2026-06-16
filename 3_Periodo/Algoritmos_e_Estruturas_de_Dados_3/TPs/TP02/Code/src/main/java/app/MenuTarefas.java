package app;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.List;

import model.Categoria;
import model.Tarefa;
import service.ArquivoCategoria;
import service.ArquivoTarefa;

/**
 * MenuTarefas: Classe de interação com o usuário para manipulação de tarefas.
 */
public class MenuTarefas extends IO 
{
    private static ArquivoTarefa arqTarefas;
    private static ArquivoCategoria arqCategorias;

    public MenuTarefas ( ) throws Exception 
    {
        arqTarefas = new ArquivoTarefa();
        arqCategorias = new ArquivoCategoria();
    } // end MenuTarefas ( )

    public void menu ( ) 
    {
        try 
        {
            int opcao = 0;
            do 
            {
                opcoes_menu();
                opcao = ler_opcao();
                executar_opcao(opcao);
            } while (opcao != 0); // end do-while
        } catch( Exception e ) {
            e.printStackTrace();
        } // end try-catch
    } // end menu ( )

    protected static void opcoes_menu ( ) 
    {
        System.out.println("\nAEDs-III 1.0           ");
        System.out.println("-------------------------");
        System.out.println("> Início > Tarefas       ");
        System.out.println("1 - Buscar               ");
        System.out.println("2 - Incluir              ");
        System.out.println("3 - Alterar              ");
        System.out.println("4 - Excluir              ");
        System.out.println("5 - Buscar por Categoria ");
        System.out.println("0 - Voltar               ");
        System.out.print  ("Opção: "                  );
    } // end opcoes_menu ( )

    protected static void executar_opcao ( int opcao ) 
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
                buscarTarefaPorCategoria( );
                break;

            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // end switch
    } // end executar_opcao ( )

    public static LocalDate formatarData ( String dataEmString ) 
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        LocalDate data = null;
        try {
            data = LocalDate.parse(dataEmString, formatter);
        } catch( DateTimeParseException e ) {
            System.out.println(RED + "\nFormato de data inválido. Por favor, use o formato dd/MM/yyyy." + RESET);
        } // end try-catch
        return data;
    } // end formatarData ( )

    private static void listarStatus ( ) 
    {
        System.out.println("\nEscolha um status:");
        System.out.println("1 - Pendente        ");
        System.out.println("2 - Em Andamento    ");
        System.out.println("3 - Concluída       ");
        System.out.println("4 - Cancelada       ");
        System.out.println("5 - Atrasada        ");
        System.out.print  ("Status: "            );
    } // end listarStatus ( )

    private static void listarPrioridades ( ) 
    {
        System.out.println( "\nEscolha uma prioridade:" );
        System.out.println( "1 - Muito Baixa          " );
        System.out.println( "2 - Baixa                " );
        System.out.println( "3 - Média                " );
        System.out.println( "4 - Alta                 " );
        System.out.println( "5 - Urgente              " );
        System.out.print  ( "Prioridade: "              );
    } // end listarPrioridades ( )

    private static void listarTarefas ( List<Tarefa> lista ) 
    {
        if( lista != null ) 
        {
            System.out.println( "\nLista de tarefas:" );
            int tam = lista.size( );
            for( int i = 0; i < tam; i++ ) {
                System.out.println( (i+1) + ": " + lista.get(i).getNome() );
            } // end for
        } // end if
    } // end listarTarefas ( )

    private static void listarCategorias ( List<Categoria> lista ) 
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

    public static Tarefa lerTarefa ( )
    {
        Tarefa tarefa = null;
        try
        {
            List<Categoria> categorias = arqCategorias.readAll( );

            if( categorias.isEmpty( ) ) 
            {
                System.out.println( RED + "Não há categorias cadastradas!" + RESET );
            } 
            else 
            {
                System.out.print( "\nNome: " );
                String nome = console.nextLine( );

                if( nome.length( ) > 0 ) 
                {
                    LocalDate dataCriacao = null;
                    while( dataCriacao == null ) 
                    {
                        System.out.print( "\nData de Criação (dd/MM/yyyy): " );
                        String dc1 = console.nextLine( );
                        dataCriacao = formatarData( dc1 );
                    } // end while

                    LocalDate dataConclusao = null;
                    while( dataConclusao == null ) 
                    {
                        System.out.print( "\nData de Conclusão (dd/MM/yyyy): " );
                        String dc2 = console.nextLine( );
                        dataConclusao = formatarData( dc2 );
                    } // end while

                    byte status = 0;
                    while( status < 1 || status > 5 ) 
                    {
                        listarStatus();
                        try 
                        {
                            status = Byte.parseByte( console.nextLine( ) );
                            if( status < 1 || status > 5 ) {
                                System.out.println( RED + "Status inválido! Escolha um valor entre 1 e 5." + RESET );
                            } // end if
                        } catch( NumberFormatException e ) {
                            System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
                        } // end try-catch
                    } // end while

                    byte prioridade = 0;
                    while( prioridade < 1 || prioridade > 5 ) 
                    {
                        listarPrioridades();
                        try 
                        {
                            prioridade = Byte.parseByte( console.nextLine() );
                            if( prioridade < 1 || prioridade > 5 ) {
                                System.out.println( RED + "Prioridade inválida! Escolha um valor entre 1 e 5." + RESET );
                            } // end if
                        } catch( NumberFormatException e ) {
                            System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
                        } // end try-catch
                    } // end while

                    listarCategorias( categorias );
                    int idCategoria = -1;
                    while( idCategoria < 0 || idCategoria > categorias.size() ) 
                    {
                        System.out.print("Categoria (ID): ");
                        try 
                        {
                            idCategoria = Integer.parseInt( console.nextLine() );
                            if( idCategoria < 0 || idCategoria > categorias.size( ) ) {
                                System.out.println( RED + "ID de categoria inválido!" + RESET );
                            } // end if
                        } catch( NumberFormatException e ) {
                            System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
                        } // end try-catch
                    } // end while

                    tarefa = new Tarefa( nome, dataCriacao, dataConclusao, status, prioridade, idCategoria );
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if
        } catch( Exception e ) {
            System.out.println( RED + "\nErro ao ler tarefa!" + RESET );
        } // end try-catch
        return tarefa;
    } // end lerTarefa ( )

    public static void incluirTarefa ( ) 
    {
        System.out.println( "\n> Incluir Tarefa:" );

        try 
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
                    } // end try-catch
                } else {
                    System.out.println( RED + "Inclusão cancelada!" + RESET );
                } // end if
            } // end if
        } catch( Exception e ) {
            System.out.println( RED + "Erro ao incluir tarefa!" + RESET );
        } // end try-catch
    } // end incluirTarefa ( )

    public static void buscarTarefa( )
    {
        System.out.println( "\n> Buscar Tarefa:" );
        
        try 
        {
            List<Tarefa> lista = arqTarefas.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Não há tarefas cadastrada." + RESET );
            } 
            else 
            {
                listarTarefas( lista );

                System.out.print( "ID da Tarefa: " );
                String input = console.nextLine(); 
                
                if( input.length() > 0 ) 
                {
                    Tarefa tarefaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size( );
                    int id = Integer.parseInt(input);
                    for( int i = 0; i < tam && !encontrada; i++ )
                    {
                        if( lista.get(i).getId() == id ) 
                        { 
                            tarefaEncontrada = lista.get(i);
                            encontrada = true;
                        }//end if
                    } // end for
        
                    if( tarefaEncontrada != null ) {
                        System.out.println( GREEN + tarefaEncontrada + RESET );
                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    }//end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.err.println( RED + "Erro no sistema. Não foi possível buscar a tarefa!" + RESET );
        } //end try
    } // end buscarTarefa ( )

    public static void alterarTarefa ( ) 
    {
        System.out.println("\n> Alterar Tarefa:");

        try 
        {
            List<Tarefa> lista = arqTarefas.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Não há tarefa cadastrada." + RESET );
            } 
            else 
            {
                listarTarefas( lista );

                System.out.print("ID da Tarefa: ");
                String input = console.nextLine( );

                if( input.length() > 0 ) 
                {
                    Tarefa tarefaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size();
                    int id = Integer.parseInt(input);
                    for( int i = 0; i < tam && !encontrada; i++ ) 
                    {
                        if( lista.get(i).getId() == id )
                        {
                            tarefaEncontrada = lista.get(i);
                            encontrada = true;
                        } // end if
                    } // end for

                    if( tarefaEncontrada != null ) 
                    {
                        System.out.print( "\nInforme os novos dados:" );
                        Tarefa novaTarefa = lerTarefa( );

                        if( novaTarefa != null && novaTarefa.getNome().length() > 0 ) 
                        {
                            novaTarefa.setId( tarefaEncontrada.getId() );
                            arqTarefas.update( novaTarefa );
                            System.out.println( GREEN + "Tarefa alterada com sucesso." + RESET );
                        } else {
                            System.out.println( RED + "Operação cancelada!" + RESET );
                        } // end if
                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    } // end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível alterar a Tarefa!" + RESET );
            e.printStackTrace( );
        } // end try
    } // end alterarTarefa ( )

    public static void excluirTarefa ( ) 
    {
        System.out.println("\n> Excluir Tarefa:");

        try
        {
            List<Tarefa> lista = arqTarefas.readAll();

            if( lista.isEmpty() ) {
                System.out.println(RED + "Não há tarefa cadastrada." + RESET);
            } 
            else 
            {
                listarTarefas( lista );

                System.out.print("ID da tarefa: ");
                String input = console.nextLine();

                if( input.length() > 0 ) 
                {
                    Tarefa tarefaEncontrada = null;
                    boolean encontrada = false;
                    int tam = lista.size();
                    int id = Integer.parseInt(input);
                    for( int i = 0; i < tam && !encontrada; i++ ) 
                    {
                        if( lista.get(i).getId() == id ) 
                        {
                            tarefaEncontrada = lista.get(i);
                            encontrada = true;
                        } // end if
                    } // end for

                    if( tarefaEncontrada != null ) 
                    {
                        System.out.print("\nTarefa:");
                        System.out.println(tarefaEncontrada);

                        System.out.println("\nConfirma a exclusão da tarefa? (S/N)");
                        char resp = console.nextLine().charAt(0);

                        if( resp == 'S' || resp == 's' ) 
                        {
                            boolean sucesso = arqTarefas.delete( tarefaEncontrada.getId() );

                            if( sucesso ) {
                                System.out.println( GREEN + "Tarefa excluída com sucesso." + RESET );
                            } else {
                                System.out.println( RED + "Erro: Não foi possível excluir a tarefa." + RESET );
                            } // end if
                        } // end if
                    } else {
                        System.out.println( RED + "Tarefa não encontrada." + RESET );
                    } // end if
                } else {
                    System.out.println( RED + "Operação cancelada!" + RESET );
                } // end if
            } // end if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível excluir a tarefa!" + RESET );
        } // end try
    } // end excluirTarefa ( )

    public static boolean buscarTarefaPorCategoria( )
    {
        boolean result = false;
        System.out.println( "\n> Buscar Tarefa por Categoria:" );

        try 
        {
            List<Categoria> categorias = arqCategorias.readAll( );

            if( categorias.isEmpty( ) ) 
            {
                System.out.println( RED + "Não há categorias cadastradas!" + RESET );
            }
            else
            {
                listarCategorias( categorias );
                System.out.print( "ID da Categoria: " );
                int idCategoria = Integer.parseInt( console.nextLine( ) );
                
                if( idCategoria > 0 ) 
                {
                    List<Tarefa> tarefas = arqTarefas.readAll( idCategoria );

                    if( tarefas.isEmpty( ) ) 
                    {
                        System.out.println( RED + "Não há tarefas cadastradas!" + RESET );
                    } 
                    else 
                    {
                        System.out.println( "\nLista de tarefas:" );
                        for( Tarefa tarefa : tarefas ) 
                        {
                            System.out.println( GREEN + tarefa + RESET );
                        } // end for
                        result = true;
                    } // end if
                } else {
                    System.out.println( RED + "ID inválido!" + RESET );
                } // end if
            } // end if
        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível buscar tarefa!" + RESET );
        } // end try-catch

        return result;
    } // end buscarTarefa ( )

} // end class MenuTarefas
