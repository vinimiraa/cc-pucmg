package model;

/**
 *  Classe que representa um elemento de uma lista de frequências.
 *  Cada elemento é composto por um id e uma frequência.
 *  Implementa a interface Comparable para poder ser ordenado.
 */
public class ElementoLista implements Comparable<ElementoLista>, Cloneable {

    private int id;
    private float frequencia;

    public ElementoLista(int i, float f) {
        this.id = i;
        this.frequencia = f;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getFrequencia() {
        return frequencia;
    }

    public void setFrequencia(float frequencia) {
        this.frequencia = frequencia;
    }

    @Override
    public String toString() {
        return "(" + this.id + ";" + this.frequencia + ")";
    }

    @Override
    public ElementoLista clone() {
        try {
            return (ElementoLista) super.clone();
        } catch (CloneNotSupportedException e) {
            // Tratamento de exceção se a clonagem falhar
            e.printStackTrace();
            return null;
        }
    }

    @Override
    public int compareTo(ElementoLista outro) {
        return Integer.compare(this.id, outro.id);
    }
}