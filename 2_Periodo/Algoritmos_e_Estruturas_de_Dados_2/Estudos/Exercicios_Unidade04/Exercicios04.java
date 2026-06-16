class Celula {
    public int elemento;
    public Celula prox;

    public Celula() {
        this(0);
    }

    public Celula(int x) {
        this.elemento = x;
        this.prox = null;
    }
}

class Pilha extends Celula {
    private Celula topo;

    public Pilha() {
        topo = null;
    }

    public void inserir(int x) {
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }

    public int remover() throws Exception {
        if (topo == null)
            throw new Exception("Erro!");
        int elemento = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return elemento;
    }

    public void mostrar() {
        System.out.print("[ ");
        for (Celula i = topo; i != null; i = i.prox) {
            System.out.print(i.elemento + " ");
        }
        System.out.println("]");
    }

    /*
     * Seja nossa Pilha, faça um método que retorna soma dos elementos contidos na
     * mesma
     */
    int somar() {
        int resp = 0;
        for (Celula i = topo; i != null; i = i.prox) {
            resp += i.elemento;
        }
        return (resp);
    }

    /*
     * Seja nossa Pilha, faça um método RECURSIVO que retorna soma dos elementos
     * contidos na mesma
     */
    int somar(Celula i) {
        int resp = 0;
        if (i != null) {
            resp += i.elemento + somar(i.prox);
        }
        return (resp);
    }

    int somarRec() {
        return (somar(topo));
    }

    /*
     * Seja nossa Pilha, faça um método que retorna o maior elemento contido na
     * mesma
     */
    int maiorElemento() {
        int maior = topo.elemento;
        for (Celula i = topo.prox; i != null; i = i.prox) {
            if (i.elemento > maior) {
                maior = i.elemento;
            }
        }
        return (maior);
    }

    /*
     * Seja nossa Pilha, faça um método RECURSIVO que retorna o maior elemento
     * contido na mesma
     */
    private int maiorElemento(Celula i) {
        int maior = -1;
        if (i != null) {
            maior = maiorElemento(i.prox);
            if (i.elemento > maior) {
                maior = i.elemento;
            }
        }
        return (maior);
    }

    int maiorElementoRec() {
        return (maiorElemento(topo));
    }

    /*
     * Seja nossa Pilha, faça um método RECURSIVO para mostrar os elementos da pilha
     * na ordem em que os mesmos serão removidos
     */
    private void mostrarRemocao(Celula i) {
        if (i != null) {
            System.out.print(" " + i.elemento + " ");
            mostrarRemocao(i.prox);
        }
    }

    void mostrarOrdemRemocao() {
        System.out.print("{");
        mostrarRemocao(topo);
        System.out.println("}");
    }

    /*
     * Seja nossa Pilha, faça um método RECURSIVO para mostrar os elementos da pilha
     * na ordem em que os mesmos foram inseridos
     */
    private void mostrarInsercao(Celula i) {
        if (i != null) {
            mostrarInsercao(i.prox);
            System.out.print(" " + i.elemento + " ");
        }
    }

    void mostrarOrdemInsercao() {
        System.out.print("{");
        mostrarInsercao(topo);
        System.out.println("}");
    }
}

/**
 * Exercicios
 */
public class Exercicios04 extends Pilha {

    public static void main(String[] args) {
        Pilha pilha = new Pilha();
        for (int i = 0; i < 10; i++) {
            pilha.inserir(i);
        }
        pilha.mostrar();

        System.out.println("Soma dos Elementos : " + pilha.somar());
        System.out.println("Soma dos Elementos Recursivo: " + pilha.somarRec());
        System.out.println("Maior Elemento : " + pilha.maiorElemento());
        System.out.println("Maior Elemento Recursivo: " + pilha.maiorElementoRec());
        System.out.print("Mostrar em Ordem de Remocao Recursivo: ");
        pilha.mostrarOrdemRemocao();
        System.out.print("Mostrar em Ordem de Insercao Recursivo: ");
        pilha.mostrarOrdemInsercao();
    }
}