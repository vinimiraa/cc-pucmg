package util;

import java.text.Normalizer;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;

import model.Categoria;
import model.Tarefa;
import model.Rotulo;
import controller.ArquivoCategoria;
import controller.ArquivoTarefa;
import controller.ArquivoRotulo;

/**
 *  Classe de utilidade para entrada e saída de dados no console.
 *  
 *  @see java.util.Scanner
 *  @see java.time.LocalDate
 *  @see java.time.format.DateTimeFormatter
 *  @see java.time.format.DateTimeParseException
 *  @see java.util.ArrayList
 *  @see model.Categoria
 *  @see model.Tarefa
 *  @see controller.ArquivoCategoria
 *  @see controller.ArquivoTarefa
 */
public class IO 
{
    private static Scanner console = new Scanner( System.in );
    private static final String RED   = "\u001B[31m";
    private static final String RESET = "\u001B[0m";

    private static LocalDate formatarData( String dataEmString ) 
    {
        LocalDate data = null;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern( "dd/MM/yyyy" );
        try {
            data = LocalDate.parse( dataEmString, formatter );
        } catch( DateTimeParseException e ) {
            System.out.println( RED + "\nFormato de data inválido. Por favor, use o formato dd/MM/yyyy." + RESET );
        } // try-catch
        return data;
    } // formatarData ( )

    public static String getDataHoraAtual( ) 
    {
        return ( LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd--HH-mm-ss")) );
    } // getDataHoraAtual ( )

    public static void pressEnter( ) 
    {
        System.out.print( "\nPressione ENTER para continuar..." );
        console.nextLine( );
    } // pressEnter ( )

    private static void listarStatus( ) 
    {
        System.out.println("\nEscolha um status:");
        System.out.println("1 - Pendente        ");
        System.out.println("2 - Em Andamento    ");
        System.out.println("3 - Concluída       ");
        System.out.println("4 - Cancelada       ");
        System.out.println("5 - Atrasada        ");
        System.out.print  ("Status: "            );
    } // listarStatus ( )

    private static void listarPrioridades( ) 
    {
        System.out.println( "\nEscolha uma prioridade:" );
        System.out.println( "1 - Muito Baixa          " );
        System.out.println( "2 - Baixa                " );
        System.out.println( "3 - Média                " );
        System.out.println( "4 - Alta                 " );
        System.out.println( "5 - Urgente              " );
        System.out.print  ( "Prioridade: "              );
    } // listarPrioridades ( )

    public static String lerString( String mensagem, int tamanho_min, int tamanho_max ) 
    {
        String texto = "";
        boolean dadosCompletos = false;
        do 
        {
            System.out.print( mensagem );
            texto = console.nextLine( );
            if( texto.length() == 0  || texto.length() >= tamanho_min && texto.length() <= tamanho_max ) {
                dadosCompletos = true;
            } else if( texto.length( ) < tamanho_min ) {
                System.out.println( RED + "Entrada inválida! Mínimo de " + tamanho_min + " caracteres." + RESET );
            } else if( texto.length( ) > tamanho_max ) {
                System.out.println( RED + "Texto muito longo! Máximo de " + tamanho_max + " caracteres." + RESET );
            } // if
        } while( dadosCompletos == false );
        return texto;
    } // lerString ( )
    
    // {
    //     System.out.print( mensagem );
    //     return console.nextLine( );
    // } // lerString ( )

    public static LocalDate lerData( String mensagem ) 
    {
        LocalDate data = null;
        while( data == null ) {
            System.out.print( mensagem );
            data = formatarData( console.nextLine( ) );
        } // while
        return data;
    } // lerData ( )

    public static byte lerOpcaoNumerica( String tipo, int max ) 
    {
        byte opcao = 0;
        while( opcao < 1 || opcao > max ) 
        {
            if( tipo.equals("Status") ) {
                listarStatus( );
            } else {
                listarPrioridades( );
            } // if

            try 
            {
                opcao = Byte.parseByte( console.nextLine( ) );
                if( opcao < 1 || opcao > max ) {
                    System.out.println( RED + tipo + " inválido! Escolha entre 1 e " + max + "." + RESET );
                } // if

            } catch( NumberFormatException e ) {
                System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
            } // try-catch
        } // while
        return opcao;
    } // lerOpcaoNumerica ( )

    public static int lerIdCategoria( ArquivoCategoria arqCategorias ) 
    {
        int idCategoria = -1;
        while( idCategoria < 0 ) 
        {
            listarCategorias( arqCategorias );
            System.out.print("ID da Categoria: ");
            try 
            {
                idCategoria = Integer.parseInt( console.nextLine( ) );
                if( idCategoria < 0 ) {
                    System.out.println( RED + "ID de categoria inválido!" + RESET );
                } // if
            } catch( NumberFormatException e ) {
                System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
            } // try-catch
        } // while
        return idCategoria;
    } // lerIdCategoria ( )

    public static int lerIdRotulo( ArquivoRotulo arqRotulos ) 
    {
        int idRotulo = -1;
        while( idRotulo < 0 ) 
        {
            listarRotulos( arqRotulos );
            System.out.print("ID do Rótulo: ");
            try 
            {
                idRotulo = Integer.parseInt( console.nextLine( ) );
                if( idRotulo < 0 ) {
                    System.out.println( RED + "ID de rótulo inválido!" + RESET );
                } // if
            } catch( NumberFormatException e ) {
                System.out.println( RED + "Entrada inválida! Por favor, insira um número." + RESET );
            } // try-catch
        } // while
        return idRotulo;
    } // lerIdRotulo ( )

    public static boolean listarTarefas( ArquivoTarefa arqTarefas )
    {
        boolean result = false;
        try 
        {
            ArrayList<Tarefa> lista = arqTarefas.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Nenhuma tarefa cadastrada." + RESET );
            } 
            else 
            {
                lista.sort( (t1, t2) -> Integer.compare(t1.getId(), t2.getId()) );

                System.out.println( "\nLista de tarefas:" );
                int tam = lista.size( );
                for( int i = 0; i < tam; i++ ) {
                    System.out.println( lista.get(i).getId() + ": " + lista.get(i).getNome());
                } // for
                result = true;
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível listar as tarefas!" + RESET );
        } // try-catch
        return ( result );
    } // listarTarefas ( )

    public static boolean listarCategorias( ArquivoCategoria arqCategorias )
    {
        boolean result = false;
        try
        {
            ArrayList<Categoria> lista = arqCategorias.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Nenhuma categoria cadastrada." + RESET );
            } 
            else
            {
                lista.sort( (c1, c2) -> Integer.compare(c1.getId(), c2.getId()) );
                
                System.out.println( "\nLista de categorias:" );
                int tam = lista.size( );
                for( int i = 0; i < tam; i++ ) {
                    System.out.println( lista.get(i).getId() + ": " + lista.get(i).getNome() );
                } // for
                result = true;
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível listar as categorias!" + RESET );
        } // try-catch
        return ( result );
    } // listarCategorias ( )

    public static boolean listarRotulos( ArquivoRotulo arqRotulos )
    {
        boolean result = false;
        try 
        {
            ArrayList<Rotulo> lista = arqRotulos.readAll( );

            if( lista.isEmpty( ) ) {
                System.out.println( RED + "Nenhum rótulo cadastrado." + RESET );
            } 
            else 
            {
                lista.sort( (r1, r2) -> Integer.compare( r1.getId(), r2.getId() ) );
                System.out.println( "\nLista de rótulos:" );
                int tam = lista.size( );
                for( int i = 0; i < tam; i++ ) {
                    System.out.println( lista.get(i).getId() + ": " + lista.get(i).getNome() );
                } // for
                result = true;
            } // if

        } catch( Exception e ) {
            System.out.println( RED + "Erro no sistema. Não foi possível listar os rótulos!" + RESET );
        } // try-catch
        return ( result );
    } // listarRotulos ( )

    public static String strnormalize( String str ) 
    {
        String nfdNormalizedString = Normalizer.normalize(str, Normalizer.Form.NFD);
        Pattern pattern = Pattern.compile("\\p{InCombiningDiacriticalMarks}+");
        return pattern.matcher(nfdNormalizedString).replaceAll("").toLowerCase();
    } // strnormalize ( )

} // IO
