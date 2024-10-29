package it.unimolise.ristorante.app.ricette;

public class TipoLitri extends Ingrediente {

    //? Attributi
    private int litri;

    //? Metodi
    public int getLitri() {
        return this.litri;
    }

    public void setLitri() {
        this.litri = litri;
    }

    //? Costruttore
    public TipoLitri(
            String nome,
            int litri
    ) {
        super(nome);
        this.litri = litri;
    }
}
