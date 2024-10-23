package gestore.app;

public class Data {

    //? Attributi
    private String giorno;
    private String mese;
    private String anno;

    //? Metodi
    public String getGiorno() {
        return this.giorno;
    }

    public String getMese() {
        return this.mese;
    }

    public String getAnno() {
        return this.anno;
    }

    public void setGiorno() {
        this.giorno = giorno;
    }

    public void setMese() {
        this.mese = mese;
    }

    public void setAnno() {
        this.anno = anno;
    }

    //? Costruttore
    public Data(
            String giorno,
            String mese,
            String anno
    ) {
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
    }
}
