package it.unimolise.ristorante.app.ricette;

import it.unimolise.ristorante.app.cuochi.Cuoco;

public class Ricetta {

    //? Attributi
    private String nome;
    private Ingrediente[] ingredienti;
    private Cuoco[] cuoco;

    //? Metodi
    public String getNome() {
        return this.nome;
    }

    public Ingrediente getIngredienti() {
        return null;
    }

    public Cuoco getCuoco() {
        return null;
    }

    //? Costruttore
    public Ricetta(
            String nome,
            Ingrediente[] ingredienti
    ) {
        this.nome = nome;
        this.ingredienti = new Ingrediente[ingredienti.length];
        for (int i = 0; i < ingredienti.length; i++) {
            ingredienti[i] = this.ingredienti[i];
        }
    }
}
