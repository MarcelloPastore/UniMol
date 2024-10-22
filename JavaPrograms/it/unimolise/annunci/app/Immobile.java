package it.unimolise.annunci.app;

public class Immobile {

    // Attributi
    private static int counter = 0;//Counter

    private Indirizzo indirizzo;
    private int codice;
    private int annoCostruzione;
    private char classeEnergetica;
    private float prezzo;
    private float superficeInterna;

    //Costruttore
    public Immobile(
            Indirizzo indirizzo,
            int annoCostruzione,
            char classeEnergetica,
            float superficeInterna) {
        this.indirizzo = indirizzo;
        this.codice = Immobile.counter;
        Immobile.counter++; //codice incrementale
        this.annoCostruzione = annoCostruzione;
        this.classeEnergetica = classeEnergetica;
        this.superficeInterna = superficeInterna;
    }

    //metodi
    public int getCodice() {
        return this.codice;
    }

    public void setPrezzo() {
        this.prezzo = prezzo;
    }

    public float getPrezzo() {
        return this.prezzo;
    }

    public float calcolaSuperficeCommerciale() {
        return -1;
    }

    public float calcolaPrezzoMetroQuadro() {
        return this.prezzo / this.calcolaSuperficeCommerciale();
    }

    public float getSuperficeInterna() {
        return this.superficeInterna;
    }

    public Indirizzo getIndirizzo() {
        return this.indirizzo;
    }

    public String toString() {
        return "[" + this.codice + "] " + this.indirizzo + " - " + this.calcolaSuperficeCommerciale();
    }

    public boolean equals(Object other) {
        if (!(other instanceof Immobile)) {
            return false;
        }
        Immobile otherImmobile = (Immobile) other;

        return this.indirizzo.equals(otherImmobile.indirizzo);
    }
}
