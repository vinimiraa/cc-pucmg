package model;

import java.time.LocalDate;
import java.io.IOException;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.ByteArrayInputStream;
import java.io.DataInputStream;

import interfaces.Registro;

/**
 *  Tarefa: Classe que representa uma tarefa a ser realizada.
 */
public class Tarefa implements Registro {
    private int       id;
    private String    nome;
    private LocalDate dataCriacao;
    private LocalDate dataConclusao;
    private byte      status;
    private byte      prioridade;

    public Tarefa ( ) {
        this(-1, "", LocalDate.now(), LocalDate.now(), (byte) -1, (byte) -1);
    } // end Tarefa ( )

    public Tarefa ( String nome, LocalDate dataCriacao, LocalDate dataConclusao, byte status, byte prioridade ) {
        this.nome          = nome;
        this.dataCriacao   = dataCriacao;
        this.dataConclusao = dataConclusao;
        this.status        = status;
        this.prioridade    = prioridade;
    } // end Tarefa ( )

    public Tarefa( int id, String nome, LocalDate dataCriacao, LocalDate dataConclusao, byte status, byte prioridade ) {
        this.id            = id;
        this.nome          = nome;
        this.dataCriacao   = dataCriacao;
        this.dataConclusao = dataConclusao;
        this.status        = status;
        this.prioridade    = prioridade;
    } // end Tarefa ( )
    
    public int getId ( ) {
        return this.id;
    } // end getId ( )
    
    public void setId ( int id ) {
        this.id = id;
    } // end setId ( )
    
    public String getNome ( ) {
        return this.nome;
    } // end getNome ( )

    public void setNome ( String nome ) {
        this.nome = nome;
    } // end setNome ( )

    public LocalDate getDataCriacao ( ) {
        return this.dataCriacao;
    } // end getDataCriacao ( )

    public void setDataCriacao ( LocalDate dataCriacao ) {
        this.dataCriacao = dataCriacao;
    } // end setDataCriacao ( )

    public LocalDate getDataConclusao ( ) {
        return this.dataConclusao;
    } // end getDataConclusao ( )

    public void setDataConclusao ( LocalDate dataConclusao ) {
        this.dataConclusao = dataConclusao;
    } // end setDataConclusao ( )

    public byte getStatus ( ) {
        return this.status;
    } // end getStatus ( )

    public void setStatus ( byte status ) {
        this.status = status;
    } // end setStatus ( )

    public byte getPrioridade ( ) {
        return this.prioridade;
    } // end getPrioridade ( )

    public void setPrioridade ( byte prioridade ) {
        this.prioridade = prioridade;
    } // end setPrioridade ( )

    public String toString ( ) {
        return  "\nID...............: " + this.id            +
                "\nNome.............: " + this.nome          +
                "\nData de Criacao..: " + this.dataCriacao   +
                "\nData de Conclusao: " + this.dataConclusao +
                "\nStatus...........: " + this.status        +
                "\nPrioridade.......: " + this.prioridade;
    } // end toString ( )

    public byte[] toByteArray ( ) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt (this.id);
        dos.writeUTF (this.nome); // nome
        dos.writeInt ((int)this.dataCriacao.toEpochDay()); // data de criação
        dos.writeInt ((int)this.dataConclusao.toEpochDay()); // data de conclusão
        dos.writeByte(this.status); // status
        dos.writeByte(this.prioridade); // prioridade

        return baos.toByteArray();
    } // end toByteArray ( )

    public void fromByteArray ( byte[] b ) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(b);
        DataInputStream dis = new DataInputStream(bais);

        this.id            = dis.readInt();
        this.nome          = dis.readUTF();
        this.dataCriacao   = LocalDate.ofEpochDay(dis.readInt());
        this.dataConclusao = LocalDate.ofEpochDay(dis.readInt());
        this.status        = dis.readByte();
        this.prioridade    = dis.readByte();
    } // end fromByteArray ( )

} // end class Tarefa