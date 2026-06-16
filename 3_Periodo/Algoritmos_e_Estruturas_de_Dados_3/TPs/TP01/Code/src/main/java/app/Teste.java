package app;

import java.io.File;
import java.time.LocalDate;

import model.Tarefa;
import service.Arquivo;

/**
 * Teste
 */
public class Teste {
    
    private static Arquivo<Tarefa> arqTarefas;
    public static void main( String[] args ) {

        // Tarefas de exemplos
        Tarefa t1 = new Tarefa("Aniversario Breno", LocalDate.of(2004, 9, 15), 
                                LocalDate.of(2004, 9, 16), (byte) 0, (byte) 1);
        Tarefa t2 = new Tarefa("Fazer os exercicios de calculo", LocalDate.of(2004, 9, 15), 
                                LocalDate.of(2004, 9, 16), (byte) 0, (byte) 1);
        Tarefa t3 = new Tarefa("Ir no mercado comprar biscoito", LocalDate.of(2004, 9, 15), 
                                LocalDate.of(2004, 9, 16), (byte) 0, (byte) 1);

        int id1 = 0, id2 = 0, id3 = 0;

        try {
            // Abre (cria) o arquivo de livros, apagando o anterior (apenas para teste)
            File f = new File(".\\Codigo\\src\\main\\data\\Tarefas.db"); f.delete();
            File f2 = new File(".\\Codigo\\src\\main\\data\\Tarefas.db.c.idx"); f2.delete();
            File f3 = new File(".\\Codigo\\src\\main\\data\\Tarefas.db.d.idx"); f3.delete();

            arqTarefas = new Arquivo<>("Tarefas.db", Tarefa.class.getConstructor());

            // Insere as tarefas no arquivo
            id1 = arqTarefas.create(t1);
            t1.setId(id1);
            id2 = arqTarefas.create(t2);
            t2.setId(id2);
            id3 = arqTarefas.create(t3);
            t3.setId(id3);

            // Busca por duas tarefas
            System.out.println( arqTarefas.read(id3) );
            System.out.println( arqTarefas.read(id1) );

            // Altera o nome de uma tarefa para um nome maior e exibe o resultado
            t1.setNome("Aniversario Breno de 20 anos");
            arqTarefas.update(t1);
            System.out.println( arqTarefas.read(id1) );

            // Altera o nome de uma tarefa para um nome menor e exibe o resultado
            t1.setNome("Aniversario Breno");
            arqTarefas.update(t1);
            System.out.println( arqTarefas.read(id1) );

            // Exclui uma tarefa e exibe o resultado
            arqTarefas.delete(id2);
            Tarefa t = arqTarefas.read(id2);
            if ( t == null ) {
                System.out.println("Tarefa excluída com sucesso!");
            } else {
                System.out.println("Erro ao excluir tarefa!");
                System.out.println(t);
            } // end if

            arqTarefas.close();
        } catch (Exception e) {
            e.printStackTrace();
        } // end try catch
    } // end main

} // end class Teste
