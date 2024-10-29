package it.unimolise.ristorante.app.cuochi;

public class Cuoco {

    //? Attributi
    private String nome;
    private String cognome;
    private static int codice = 0; //? Counter
    private Data data;
    private Ricetta ricetta;

    //? Metodi
    public String getNome() {
        return this.nome;
    }

    public String getCognome() {
        return this.cognome;
    }

    public Data getData() {
        return this.data;
    }

    public int getCodice() {
        return this.codice;
    }

    public Ricetta getRicetta() {
        return this.ricetta;
    }

    public void setNome() {
        this.nome = nome;
    }

    public void setCognome() {
        this.cognome = cognome;
    }

    //? Costruttore
    public Cuoco(
            String nome,
            String cognome,
            Data data
    ) {
        this.nome = nome;
        this.cognome = cognome;
        this.data = data;
    }
}
