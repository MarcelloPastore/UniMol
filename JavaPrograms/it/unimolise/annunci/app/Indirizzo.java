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

    public String toString() {
        return this.via + " ("
                + this.citta + ") "
                + this.numeroCivico;
    }

    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }
        if (!(other instanceof Indirizzo)) {
            return false;
        }
        Indirizzo otherIndirizzo = (Indirizzo) other;
        if (this.citta == null || this.via == null || this.numeroCivico == null) {
            return false;
        }
        return this.citta.equals(otherIndirizzo.citta)
                && this.via.equals(otherIndirizzo.via)
                && this.numeroCivico.equals(otherIndirizzo.numeroCivico);
    }

    public int hashCode() {
        return this.citta.hashCode()
                + this.via.hashCode()
                + this.numeroCivico.hashCode();
    }
}
