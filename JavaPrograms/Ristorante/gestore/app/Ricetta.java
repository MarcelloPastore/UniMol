package gestore.app;

public class Ricetta {

    //? Attributi
    private String nome;
    private Ingrediente ingrediente;
    private Cuoco cuoco;

    //? Costruttore
    public String getNome() {
        return this.nome;
    }

    public Ingrediente getIngredienti() {
        return this.ingrediente;
    }

    public Cuoco getCuoco() {
        return this.cuoco;
    }

    //? Costruttore
    public Ricetta(
            String nome,
            Ingrediente ingrediente
    ) {
        this.nome = nome;
        this.ingrediente = ingrediente;
    }
}
