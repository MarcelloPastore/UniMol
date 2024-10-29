package it.unimolise.ristorante.app.ricette;

public class TipoGrammi extends Ingrediente {

    //? Attributi
    private int grammi;

    //? Metodi
    public int getGrammi() {
        return this.grammi;
    }

    public void setGrammi() {
        this.grammi = grammi;
    }

    //? Costruttore
    public TipoGrammi(
            String nome,
            int grammi
    ) {
        super(nome);
        this.grammi = grammi;
    }
}
