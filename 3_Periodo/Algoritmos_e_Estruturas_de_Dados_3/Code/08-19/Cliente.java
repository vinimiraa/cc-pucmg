import java.time.LocalDate;

public class Cliente {

    public int id;
    public String nome;
    public String cpf;
    public float salario;
    public LocalDate nascimento;

    public Cliente() {
        this(-1, "", "", 0F, LocalDate.now());
    }

    public Cliente(String n, String c, float s, LocalDate d) {
        this(-1, n, c, s, d);
    }

    public Cliente(int i, String n, String c, float s, LocalDate d) {
        this.id = i;
        this.nome = n;
        this.cpf = c;
        this.salario = s;
        this.nascimento = d;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public String toString() {
        return "\nID........: " + this.id +
                "\nNome......: " + this.nome +
                "\nCPF.......: " + this.cpf +
                "\nSalário...: " + this.salario +
                "\nNascimento: " + this.nascimento;
    }

}
