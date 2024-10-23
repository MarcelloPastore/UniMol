package gestore.app;

public class TipoPezzi extends Ingrediente {

    //? Attributi
    private int pezzi;

    //? Metodi
    public int getPezzi() {
        return this.pezzi;
    }

    public void setPezzi() {
        this.pezzi = pezzi;
    }

    //? Costruttore
    public TipoPezzi(
            String nome,
            int pezzi
    ) {
        super(nome);
        this.pezzi = pezzi;
    }
}
