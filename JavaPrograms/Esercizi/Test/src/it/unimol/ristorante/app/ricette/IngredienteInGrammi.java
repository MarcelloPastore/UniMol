package it.unimol.ristorante.app.ricette;

public class IngredienteInGrammi extends Ingrediente {
    public IngredienteInGrammi(String nome, float quantita) {
        super(nome, quantita);
    }
    
    public String toString() {
        return super.toString() + " g";
    }
}
