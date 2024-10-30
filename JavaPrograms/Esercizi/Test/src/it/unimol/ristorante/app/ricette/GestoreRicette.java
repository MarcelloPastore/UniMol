package it.unimol.ristorante.app.ricette;

public class GestoreRicette {
    private Ricetta[] ricette;
    private int numRicette;
    
    public GestoreRicette() {
        this.ricette = new Ricetta[1000];
        this.numRicette = 0;
    }
    
    public void addRicetta(Ricetta ricetta) {
        this.ricette[this.numRicette] = ricetta;
        this.numRicette++;
    }
    
    public Ricetta getRicetta(String nome) {
        for (int i = 0; i < this.numRicette; i++) {
            Ricetta ricetta = this.ricette[i];
            if (ricetta.getNome().equals(nome))
                return ricetta;
        }
        
        return null;
    }
}
