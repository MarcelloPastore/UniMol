package it.unimol.ristorante.app.ricette;

public class Ingrediente {
    private String nome;
    private float quantita;
    
    protected Ingrediente(String nome, float quantita) {
        this.nome = nome;
        this.quantita = quantita;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public float getQuantita() {
        return this.quantita;
    }
    
    public String toString() {
        return this.nome + " - " + this.quantita;
    }
}
