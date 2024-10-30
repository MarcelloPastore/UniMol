package it.unimol.ristorante.app.ricette;

public class IngredienteInPezzi extends Ingrediente {
    public IngredienteInPezzi(String nome, float quantita) {
        super(nome, quantita);
    }
    
    public String toString() {
        return super.toString() + " pz";
    }
}
