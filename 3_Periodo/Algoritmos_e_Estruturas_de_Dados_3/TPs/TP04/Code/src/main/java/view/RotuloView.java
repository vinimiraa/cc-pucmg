package view;

import controller.ArquivoRotulo;
import controller.ArquivoTarefa;
import controller.IndiceInvertido;
import model.Tarefa;
import model.Rotulo;
import util.*;

/**
 *  Classe RotulosView
 * 
 *  <p>Classe que representa a interface de usuário para manipulação de Rotulos.</p>
 * 
 *  @see PrincipalView
 */
public class RotuloView extends PrincipalView
{
    private static ArquivoRotulo arqRotulos;
    private static ArquivoTarefa arqTarefas;
    private static IndiceInvertido indiceInvertido;

    public RotuloView ( ) throws Exception {
        arqRotulos = new ArquivoRotulo( );
        arqTarefas = new ArquivoTarefa( );
        indiceInvertido = new IndiceInvertido( );
    } // MenuRotulos ( )

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
        System.out.println("\nAEDs-III 1.0              ");
        System.out.println("----------------------------");
        System.out.println("> Início > Tarefas > Rotulos");
        System.out.println("1 - Buscar                  ");
        System.out.println("2 - Incluir                 ");
        System.out.println("3 - Alterar                 ");
        System.out.println("4 - Excluir                 ");
        System.out.println("0 - Voltar                  ");
        System.out.print  ("Opção: "                     );
    } // opcoes_menu ( )

    protected static void executar_opcao( int opcao ) throws Exception
    {
        switch( opcao ) 
        {
            case 0:
                break;
            case 1:
                buscarRotulo( );
                break;
            case 2:
                incluirRotulo( );
                break;
            case 3:
                alterarRotulo( );
                break;
            case 4:
                excluirRotulo( );
                break;
            
            default:
                System.out.println( RED + "Opção inválida!" + RESET );
                break;
        } // switch
    } // executar_opcao ( )

    private static Rotulo lerRotulo( )
    {
        String nome = IO.lerString("\nNome da Rotulo (min. de 2 letras): ", 2, 50);
        return ( new Rotulo( nome ) );
    } // lerRotulo ( )

    public static void incluirRotulo( ) 
    {
        System.out.println( "\n> Incluir Rotulo:" );
        
        Rotulo novoRotulo = lerRotulo( );

        if( novoRotulo != null && novoRotulo.getNome().length() > 0 ) 
        {
            System.out.println( "Confirma a inclusão da Rotulo? (S/N)" );
            char resp = console.nextLine().charAt(0);

            if( resp=='S' || resp=='s' ) 
            {
                try 
                {
                    arqRotulos.create( novoRotulo );
                    System.out.println( GREEN + "Rotulo criada com sucesso." + RESET);

                    System.out.println( "Deseja associar o Rotulo a uma tarefa? (S/N)" );
                    char resp2 = console.nextLine().charAt(0);

                    if( resp2=='S' || resp2=='s' ) 
                    {
                        if( IO.listarTarefas( arqTarefas ) )
                        {
                            System.out.print( "ID da Tarefa: " );
                            int idTarefa = Integer.parseInt( console.nextLine( ) );

                            Tarefa tarefa = arqTarefas.read( idTarefa );
                            if( tarefa != null ) 
                            {
                                int idRotulo = novoRotulo.getId();
                                tarefa.addIdRotulo( idRotulo );
                                arqTarefas.update( tarefa );
                                indiceInvertido.insert( idRotulo, idTarefa );
                                System.out.println( GREEN + "Rotulo associada a tarefa com sucesso." + RESET );
                            } else {
                                System.out.println( RED + "Tarefa não encontrada." + RESET );
                            } // if
                        } // if
                    } // if
                } catch( Exception e ) {
                    System.out.println( RED + "Erro do sistema. Não foi possível criar a Rotulo!" + RESET );
                } // try-catch
            } // if

        } else {
            System.out.println( RED + "Operação cancelada!" + RESET );
        } // if 
    } // incluirRotulo ( )

    public static void buscarRotulo( ) throws Exception
    {
        System.out.println( "\n> Buscar Rotulo:" );
    
        try 
        {
            if( IO.listarRotulos( arqRotulos ) )
            {

                System.out.print( "ID da Rotulo: " );
                int id = Integer.parseInt( console.nextLine( ) );
        
                Rotulo RotuloEncontrada = arqRotulos.read( id );
        
                if( RotuloEncontrada != null ) {
                    System.out.println( GREEN + RotuloEncontrada + RESET );
                } else {
                    System.out.println( RED + "Rotulo não encontrada." + RESET );
                } // if
            } // if

        } catch( NumberFormatException e ) {
            System.out.println( RED + "ID inválido. Operação cancelada!" + RESET );
        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível buscar a Rotulo!" + RESET );
        } // try-catch
    } // buscarRotulo ( )

    public static void alterarRotulo( ) 
    {
        System.out.println( "\n> Alterar Rotulo:" );
    
        try 
        {
            if( IO.listarRotulos( arqRotulos ) )
            {

                System.out.print( "ID da Rotulo: " );
                int id = Integer.parseInt( console.nextLine( ) );
        
                Rotulo RotuloEncontrada = arqRotulos.read( id );
        
                if( RotuloEncontrada != null ) 
                {
                    Rotulo novaRotulo = lerRotulo();
        
                    if( novaRotulo != null && novaRotulo.getNome().length() > 0 ) 
                    {
                        novaRotulo.setId( id );
                        arqRotulos.update( novaRotulo );
                        System.out.println( GREEN + "Rotulo alterada com sucesso." + RESET );
                    } else {
                        System.out.println( RED + "Operação cancelada!" + RESET );
                    } // if

                } else {
                    System.out.println( RED + "Rotulo não encontrada." + RESET );
                } // if
            } // if

        } catch( NumberFormatException e ) {
            System.out.println(RED + "ID inválido. Operação cancelada!" + RESET);
        } catch( Exception e ) {
            System.out.println(RED + "Erro no sistema. Não foi possível alterar a Rotulo!" + RESET);
        } // try-catch
    } // alterarRotulo ( )
    
    public static void excluirRotulo( ) 
    {
        System.out.println( "\n> Excluir Rotulo:" );

        try 
        {
            if( IO.listarRotulos( arqRotulos ) )
            {
                System.out.print( "ID da Rotulo: " );
                int id = Integer.parseInt( console.nextLine( ) );
    
                Rotulo RotuloEncontrada = arqRotulos.read( id );
    
                if( RotuloEncontrada != null ) 
                {
                    System.out.print( "\nRotulo:" );
                    System.out.println( RotuloEncontrada );
    
                    System.out.println( "\nConfirma a exclusão da Rotulo? (S/N)" );
                    char resp = console.nextLine( ).charAt( 0 );
    
                    if( resp == 'S' || resp == 's' ) 
                    {
                        boolean sucesso = arqRotulos.delete(id);
    
                        if( sucesso ) {
                            System.out.println( GREEN + "Rotulo excluída com sucesso." + RESET );
                        } else {
                            System.out.println( RED + "Erro: Não foi possível excluir a Rotulo porque ela possui tarefas associadas." + RESET );
                        } // if
                    } // if
    
                } else {
                    System.out.println(RED + "Rotulo não encontrada." + RESET);
                } // if
            } // if

        } catch (NumberFormatException e) {
            System.out.println(RED + "ID inválido. Operação cancelada!" + RESET);
        } catch (Exception e) {
            System.out.println(RED + "Erro no sistema. Não foi possível excluir a Rotulo!" + RESET);
        } // try-catch
    } // excluirRotulo ( )
    
} // RotulosView