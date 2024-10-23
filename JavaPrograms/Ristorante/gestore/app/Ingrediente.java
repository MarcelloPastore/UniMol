package gestore.app;

public class Ingrediente {

    //? Attributi
    private String nome;

    //? Metodi
    public String getNomeIngrediente() {
        return this.nome;
    }

    public void setNomeIngrediente() {
        this.nome = nome;
    }

    //? Costruttore
    public Ingrediente(
            String nome
    ) {
        this.nome = nome;
    }
}
