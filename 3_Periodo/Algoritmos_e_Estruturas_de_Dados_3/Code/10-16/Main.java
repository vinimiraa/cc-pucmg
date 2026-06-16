/*
TESTE DE ÁRVORE B+

Este programa principal serve para demonstrar o uso
da Árvore B+ como um índice indireto de uma entidade qualquer.

Aqui, cada elemento será composto por uma string e um número inteiro.

Implementado pelo Prof. Marcos Kutova
v1.1 - 2021
*/

import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import aed3.ArvoreBMais;

public class Main {

  // Método principal apenas para testes
  public static void main(String[] args) {

    ArvoreBMais<ParNomeId> arvore;
    Scanner console = new Scanner(System.in);

    try {
      File d = new File("dados");
      if (!d.exists())
        d.mkdir();
      arvore = new ArvoreBMais<>(ParNomeId.class.getConstructor(), 5, "dados/arvore.db");

      int opcao;
      do {
        System.out.println("\n\n-------------------------------");
        System.out.println("              MENU");
        System.out.println("-------------------------------");
        System.out.println("1 - Inserir");
        System.out.println("2 - Buscar");
        System.out.println("3 - Excluir");
        System.out.println("4 - Listar todas");
        System.out.println("5 - Imprimir");
        System.out.println("0 - Sair");
        try {
          opcao = Integer.valueOf(console.nextLine());
        } catch (NumberFormatException e) {
          opcao = -1;
        }

        switch (opcao) {
          case 1: {
            System.out.println("\nINCLUSÃO");
            String nome;
            int id = 0;
            try {
              System.out.print("Nome: ");
              nome = console.nextLine();
              System.out.print("ID: ");
              id = Integer.valueOf(console.nextLine());
            } catch (Exception e) {
              System.out.println("Dados inválidos!");
              break;
            }
            arvore.create(new ParNomeId(nome, id));
            arvore.print();
          }
            break;
          case 2: {
            System.out.println("\nBUSCA");
            System.out.print("Nome: ");
            String nome = console.nextLine();
            // Ao passar o segundo valor como -1, ele funciona como um coringa
            // de acordo com a implementação do método compareTo na classe
            // ParIntInt
            ArrayList<ParNomeId> lista = arvore.read(new ParNomeId(nome, -1));

            // System.out.print("Num2: ");
            // int id = Integer.valueOf(console.nextLine());
            // ArrayList<ParIntInt> lista = arvore.read(new ParIntInt(nome, id));
            System.out.print("Resposta: ");
            for (int i = 0; i < lista.size(); i++)
              System.out.print(lista.get(i) + " ");
          }
            break;
          case 3: {
            System.out.println("\nEXCLUSÃO");
            System.out.print("Nome: ");
            String nome = console.nextLine();
            System.out.print("Num2: ");
            int id = Integer.valueOf(console.nextLine());
            arvore.delete(new ParNomeId(nome, id));
            arvore.print();
          }
            break;
          case 4: {
            System.out.println("\nLISTA COMPLETA");
            ArrayList<ParNomeId> lista = arvore.read(null);
            for (int i = 0; i < lista.size(); i++)
              System.out.print(lista.get(i) + " ");
          }
            break;
          case 5: {
            arvore.print();
          }
            break;
          case 0:
            break;
          default:
            System.out.println("Opção inválida");
        }
      } while (opcao != 0);
      console.close();

    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}