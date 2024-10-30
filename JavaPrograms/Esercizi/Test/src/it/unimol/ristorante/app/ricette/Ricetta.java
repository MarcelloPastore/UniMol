package it.unimol.ristorante.app.ricette;

import it.unimol.ristorante.app.cuochi.Cuoco;

public class Ricetta {
    private String nome;
    private Ingrediente[] ingredienti;
    private Cuoco[] cuochi;
    private int numCuochi;
    
    public Ricetta(String nome, Ingrediente[] ingredienti) {
        this.nome = nome;
        this.ingredienti = new Ingrediente[ingredienti.length];
        for (int i = 0; i < ingredienti.length; i++) {
            this.ingredienti[i] = ingredienti[i];
        }
        
        this.cuochi = new Cuoco[100];
        this.numCuochi = 0;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public Ingrediente[] getIngredienti() {
        Ingrediente[] ingredienti = new Ingrediente[this.ingredienti.length];
        
        for (int i = 0; i < this.ingredienti.length; i++) {
            ingredienti[i] = this.ingredienti[i];
        }
        
        return ingredienti;
    }
    
    public void addCuoco(Cuoco cuoco) {
        this.cuochi[this.numCuochi] = cuoco;
        this.numCuochi++;
    }
    
    public Cuoco[] getCuochi() {
        Cuoco[] cuochi = new Cuoco[this.numCuochi];
        
        for (int i = 0; i < this.numCuochi; i++) {
            cuochi[i] = this.cuochi[i];
        }
        
        return cuochi;
    }
}
