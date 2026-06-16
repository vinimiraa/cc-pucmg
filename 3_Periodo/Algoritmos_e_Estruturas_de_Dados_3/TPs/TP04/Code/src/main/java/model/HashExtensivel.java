/*
TABELA HASH EXTENSÍVEL

Os nomes dos métodos foram mantidos em inglês
apenas para manter a coerência com o resto da
disciplina:
- boolean create(T elemento)
- long read(int hashcode)
- boolean update(T novoElemento)   //  a chave (hashcode) deve ser a mesma
- boolean delete(int hashcode)

Implementado pelo Prof. Marcos Kutova
v1.1 - 2021
*/
package model;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.lang.reflect.Constructor;

import interfaces.RegistroHashExtensivel;

/**
 *  HashExtensivel: Classe que implementa a estrutura de dados Hash Extensível.
 *  Implementa a interface RegistroHashExtensivel.
 */
public class HashExtensivel<T extends RegistroHashExtensivel<T>> {

  String nomeArquivoDiretorio;
  String nomeArquivoCestos;
  RandomAccessFile arqDiretorio;
  RandomAccessFile arqCestos;
  int quantidadeDadosPorCesto;
  Diretorio diretorio;
  Constructor<T> construtor;

  public class Cesto {

    Constructor<T> construtor;
    short quantidadeMaxima; // quantidade máxima de elementos que o cesto pode conter
    short bytesPorElemento; // tamanho fixo de cada elemento em bytes
    short bytesPorCesto; // tamanho fixo do cesto em bytes

    byte profundidadeLocal; // profundidade local do cesto
    short quantidade; // quantidade de elementos presentes no cesto
    ArrayList<T> elementos; // sequência de elementos armazenados

    public Cesto(Constructor<T> ct, int qtdmax) throws Exception {
      this(ct, qtdmax, 0);
    }

    public Cesto(Constructor<T> ct, int qtdmax, int pl) throws Exception {
      construtor = ct;
      if (qtdmax > 32767)
        throw new Exception("Quantidade máxima de 32.767 elementos");
      if (pl > 127)
        throw new Exception("Profundidade local máxima de 127 bits");
      profundidadeLocal = (byte) pl;
      quantidade = 0;
      quantidadeMaxima = (short) qtdmax;
      elementos = new ArrayList<>(quantidadeMaxima);
      bytesPorElemento = ct.newInstance().size();
      bytesPorCesto = (short) (bytesPorElemento * quantidadeMaxima + 3);
    }

    public byte[] toByteArray() throws Exception {
      ByteArrayOutputStream baos = new ByteArrayOutputStream();
      DataOutputStream dos = new DataOutputStream(baos);
      dos.writeByte(profundidadeLocal);
      dos.writeShort(quantidade);
      int i = 0;
      while (i < quantidade) {
        dos.write(elementos.get(i).toByteArray());
        i++;
      }
      byte[] vazio = new byte[bytesPorElemento];
      while (i < quantidadeMaxima) {
        dos.write(vazio);
        i++;
      }
      return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws Exception {
      ByteArrayInputStream bais = new ByteArrayInputStream(ba);
      DataInputStream dis = new DataInputStream(bais);
      profundidadeLocal = dis.readByte();
      quantidade = dis.readShort();
      int i = 0;
      elementos = new ArrayList<>(quantidadeMaxima);
      byte[] dados = new byte[bytesPorElemento];
      T elem;
      while (i < quantidadeMaxima) {
        dis.read(dados);
        elem = construtor.newInstance();
        elem.fromByteArray(dados);
        elementos.add(elem);
        i++;
      }
    }

    // Inserir elementos no cesto
    public boolean create(T elem) {
      if (full())
        return false;
      int i = quantidade - 1; // posição do último elemento no cesto
      while (i >= 0 && elem.hashCode() < elementos.get(i).hashCode())
        i--;
      elementos.add(i + 1, elem);
      quantidade++;
      return true;
    }

    // Buscar um elemento no cesto
    public T read(int chave) {
      if (empty())
        return null;
      int i = 0;
      while (i < quantidade && chave > elementos.get(i).hashCode())
        i++;
      if (i < quantidade && chave == elementos.get(i).hashCode())
        return elementos.get(i);
      else
        return null;
    }

    // atualizar um elemento do cesto
    public boolean update(T elem) {
      if (empty())
        return false;
      int i = 0;
      while (i < quantidade && elem.hashCode() > elementos.get(i).hashCode())
        i++;
      if (i < quantidade && elem.hashCode() == elementos.get(i).hashCode()) {
        elementos.set(i, elem);
        return true;
      } else
        return false;
    }

    // pagar um elemento do cesto
    public boolean delete(int chave) {
      if (empty())
        return false;
      int i = 0;
      while (i < quantidade && chave > elementos.get(i).hashCode())
        i++;
      if (chave == elementos.get(i).hashCode()) {
        elementos.remove(i);
        quantidade--;
        return true;
      } else
        return false;
    }

    public boolean empty() {
      return quantidade == 0;
    }

    public boolean full() {
      return quantidade == quantidadeMaxima;
    }

    public String toString() {
      String s = "Profundidade Local: " + profundidadeLocal + "\nQuantidade: " + quantidade + "\n| ";
      int i = 0;
      while (i < quantidade) {
        s += elementos.get(i).toString() + " | ";
        i++;
      }
      while (i < quantidadeMaxima) {
        s += "- | ";
        i++;
      }
      return s;
    }

    public int size() {
      return bytesPorCesto;
    }

  }

  protected class Diretorio {

    byte profundidadeGlobal;
    long[] enderecos;

    public Diretorio() {
      profundidadeGlobal = 0;
      enderecos = new long[1];
      enderecos[0] = 0;
    }

    public boolean atualizaEndereco(int p, long e) {
      if (p > Math.pow(2, profundidadeGlobal))
        return false;
      enderecos[p] = e;
      return true;
    }

    public byte[] toByteArray() throws IOException {
      ByteArrayOutputStream baos = new ByteArrayOutputStream();
      DataOutputStream dos = new DataOutputStream(baos);
      dos.writeByte(profundidadeGlobal);
      int quantidade = (int) Math.pow(2, profundidadeGlobal);
      int i = 0;
      while (i < quantidade) {
        dos.writeLong(enderecos[i]);
        i++;
      }
      return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
      ByteArrayInputStream bais = new ByteArrayInputStream(ba);
      DataInputStream dis = new DataInputStream(bais);
      profundidadeGlobal = dis.readByte();
      int quantidade = (int) Math.pow(2, profundidadeGlobal);
      enderecos = new long[quantidade];
      int i = 0;
      while (i < quantidade) {
        enderecos[i] = dis.readLong();
        i++;
      }
    }

    public String toString() {
      String s = "\nProfundidade global: " + profundidadeGlobal;
      int i = 0;
      int quantidade = (int) Math.pow(2, profundidadeGlobal);
      while (i < quantidade) {
        s += "\n" + i + ": " + enderecos[i];
        i++;
      }
      return s;
    }

    protected long endereço(int p) {
      if (p > Math.pow(2, profundidadeGlobal))
        return -1;
      return enderecos[p];
    }

    protected boolean duplica() {
      if (profundidadeGlobal == 127)
        return false;
      profundidadeGlobal++;
      int q1 = (int) Math.pow(2, profundidadeGlobal - 1);
      int q2 = (int) Math.pow(2, profundidadeGlobal);
      long[] novosEnderecos = new long[q2];
      int i = 0;
      while (i < q1) { // copia o vetor anterior para a primeiro metade do novo vetor
        novosEnderecos[i] = enderecos[i];
        i++;
      }
      while (i < q2) { // copia o vetor anterior para a segunda metade do novo vetor
        novosEnderecos[i] = enderecos[i - q1];
        i++;
      }
      enderecos = novosEnderecos;
      return true;
    }

    // Para efeito de determinar o cesto em que o elemento deve ser inserido,
    // só serão considerados valores absolutos da chave.
    protected int hash(int chave) {
      return Math.abs(chave) % (int) Math.pow(2, profundidadeGlobal);
    }

    // Método auxiliar para atualizar endereço ao duplicar o diretório
    protected int hash2(int chave, int pl) { // cálculo do hash para uma dada profundidade local
      return Math.abs(chave) % (int) Math.pow(2, pl);
    }

  }

  public HashExtensivel(Constructor<T> ct, int n, String nd, String nc) throws Exception {
    construtor = ct;
    quantidadeDadosPorCesto = n;
    nomeArquivoDiretorio = nd;
    nomeArquivoCestos = nc;

    arqDiretorio = new RandomAccessFile(nomeArquivoDiretorio, "rw");
    arqCestos = new RandomAccessFile(nomeArquivoCestos, "rw");

    // Se o diretório ou os cestos estiverem vazios, cria um novo diretório e lista
    // de cestos
    if (arqDiretorio.length() == 0 || arqCestos.length() == 0) {

      // Cria um novo diretório, com profundidade de 0 bits (1 único elemento)
      diretorio = new Diretorio();
      byte[] bd = diretorio.toByteArray();
      arqDiretorio.write(bd);

      // Cria um cesto vazio, já apontado pelo único elemento do diretório
      Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
      bd = c.toByteArray();
      arqCestos.seek(0);
      arqCestos.write(bd);
    }
  }

  public boolean create(T elem) throws Exception {

    // Carrega todo o diretório para a memória
    byte[] bd = new byte[(int) arqDiretorio.length()];
    arqDiretorio.seek(0);
    arqDiretorio.read(bd);
    diretorio = new Diretorio();
    diretorio.fromByteArray(bd);

    // Identifica a hash do diretório,
    int i = diretorio.hash(elem.hashCode());

    // Recupera o cesto
    long enderecoCesto = diretorio.endereço(i);
    Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
    byte[] ba = new byte[c.size()];
    arqCestos.seek(enderecoCesto);
    arqCestos.read(ba);
    c.fromByteArray(ba);

    // Testa se a chave já não existe no cesto
    if (c.read(elem.hashCode()) != null)
      throw new Exception("Elemento já existe");

    // Testa se o cesto já não está cheio
    // Se não estiver, create o par de chave e dado
    if (!c.full()) {
      // Insere a chave no cesto e o atualiza
      c.create(elem);
      arqCestos.seek(enderecoCesto);
      arqCestos.write(c.toByteArray());
      return true;
    }

    // Duplica o diretório
    byte pl = c.profundidadeLocal;
    if (pl >= diretorio.profundidadeGlobal)
      diretorio.duplica();
    byte pg = diretorio.profundidadeGlobal;

    // Cria os novos cestos, com os seus dados no arquivo de cestos
    Cesto c1 = new Cesto(construtor, quantidadeDadosPorCesto, pl + 1);
    arqCestos.seek(enderecoCesto);
    arqCestos.write(c1.toByteArray());

    Cesto c2 = new Cesto(construtor, quantidadeDadosPorCesto, pl + 1);
    long novoEndereco = arqCestos.length();
    arqCestos.seek(novoEndereco);
    arqCestos.write(c2.toByteArray());

    // Atualiza os dados no diretório
    int inicio = diretorio.hash2(elem.hashCode(), c.profundidadeLocal);
    int deslocamento = (int) Math.pow(2, pl);
    int max = (int) Math.pow(2, pg);
    boolean troca = false;
    for (int j = inicio; j < max; j += deslocamento) {
      if (troca)
        diretorio.atualizaEndereco(j, novoEndereco);
      troca = !troca;
    }

    // Atualiza o arquivo do diretório
    bd = diretorio.toByteArray();
    arqDiretorio.seek(0);
    arqDiretorio.write(bd);

    // Reinsere as chaves do cesto antigo
    for (int j = 0; j < c.quantidade; j++) {
      create(c.elementos.get(j));
    }
    create(elem); // insere o nome elemento
    return true;

  }

  public T read(int chave) throws Exception {

    // Carrega o diretório
    byte[] bd = new byte[(int) arqDiretorio.length()];
    arqDiretorio.seek(0);
    arqDiretorio.read(bd);
    diretorio = new Diretorio();
    diretorio.fromByteArray(bd);

    // Identifica a hash do diretório,
    int i = diretorio.hash(chave);

    // Recupera o cesto
    long enderecoCesto = diretorio.endereço(i);
    Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
    byte[] ba = new byte[c.size()];
    arqCestos.seek(enderecoCesto);
    arqCestos.read(ba);
    c.fromByteArray(ba);

    return c.read(chave);
  }

  public boolean update(T elem) throws Exception {

    // Carrega o diretório
    byte[] bd = new byte[(int) arqDiretorio.length()];
    arqDiretorio.seek(0);
    arqDiretorio.read(bd);
    diretorio = new Diretorio();
    diretorio.fromByteArray(bd);

    // Identifica a hash do diretório,
    int i = diretorio.hash(elem.hashCode());

    // Recupera o cesto
    long enderecoCesto = diretorio.endereço(i);
    Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
    byte[] ba = new byte[c.size()];
    arqCestos.seek(enderecoCesto);
    arqCestos.read(ba);
    c.fromByteArray(ba);

    // atualiza o dado
    if (!c.update(elem))
      return false;

    // Atualiza o cesto
    arqCestos.seek(enderecoCesto);
    arqCestos.write(c.toByteArray());
    return true;

  }

  public boolean delete(int chave) throws Exception {

    // Carrega o diretório
    byte[] bd = new byte[(int) arqDiretorio.length()];
    arqDiretorio.seek(0);
    arqDiretorio.read(bd);
    diretorio = new Diretorio();
    diretorio.fromByteArray(bd);

    // Identifica a hash do diretório,
    int i = diretorio.hash(chave);

    // Recupera o cesto
    long enderecoCesto = diretorio.endereço(i);
    Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
    byte[] ba = new byte[c.size()];
    arqCestos.seek(enderecoCesto);
    arqCestos.read(ba);
    c.fromByteArray(ba);

    // delete a chave
    if (!c.delete(chave))
      return false;

    // Atualiza o cesto
    arqCestos.seek(enderecoCesto);
    arqCestos.write(c.toByteArray());
    return true;
  }

  public void print() {
    try {
      byte[] bd = new byte[(int) arqDiretorio.length()];
      arqDiretorio.seek(0);
      arqDiretorio.read(bd);
      diretorio = new Diretorio();
      diretorio.fromByteArray(bd);
      System.out.println("\nDIRETÓRIO ------------------");
      System.out.println(diretorio);

      System.out.println("\nCESTOS ---------------------");
      arqCestos.seek(0);
      while (arqCestos.getFilePointer() != arqCestos.length()) {
        System.out.println("Endereço: " + arqCestos.getFilePointer());
        Cesto c = new Cesto(construtor, quantidadeDadosPorCesto);
        byte[] ba = new byte[c.size()];
        arqCestos.read(ba);
        c.fromByteArray(ba);
        System.out.println(c + "\n");
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
