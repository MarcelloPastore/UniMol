package it.unimol.ristorante.app.ricette;

public class IngredienteInLitri extends Ingrediente {
    public IngredienteInLitri(String nome, float quantita) {
        super(nome, quantita);
    }
    
    public String toString() {
        return super.toString() + " l";
    }
}
