package it.unimolise.annunci.app;

public class Indirizzo {

    private String citta;
    private String via;
    private String numeroCivico;

    public Indirizzo(String citta, String via, String numeroCivico) {
        this.citta = citta;
        this.via = via;
        this.numeroCivico = numeroCivico;
    }

    public String getCitta() {
        return citta;
    }

    public String getVia() {
        return via;
    }

    public String getNumeroCivico() {
        return numeroCivico;
    }

}
