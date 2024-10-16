package it.unimol.annunci.app;

public class Immobile {
    // Attributi
    private static int counter = 0;//Counter

    private Indirizzo indirizzo;
    private int codice;
    private int annoCostruzione;
    private char classeEnergetica;
    private float prezzo;
    private float superficeInterna;
    
    //metodi
    public int getCodice{
        return this.codice;
    }
    
    public void setPrezzo(){
        this.prezzo = prezzo;
    }

    public int getPrezzo(){
        return this.prezzo;
    }

    public float calcolaSuperficeCommerciale(){
        return-1;
    }

    public float calcolaPrezzoMetroQuadro(){
        return this.prezzo / this.calcolaSuperficeCommerciale();
    }

    //Costruttore
    public Immobile(
    Indirizzo indirizzo, 
    int codice, 
    int annoCostruzione, 
    char classeEnergetica, 
    float prezzo, 
    float superficeInterna) {
        this.indirizzo = indirizzo;
        this.codice = Immobile.counter;
        Immobile.counter++; //codice incrementale
        this.annoCostruzione = annoCostruzione;
        this.classeEnergetica = classeEnergetica;
        this.superficeInterna = superficeInterna;
    }

}