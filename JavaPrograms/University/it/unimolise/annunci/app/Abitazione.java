package it.unimolise.annunci.app;

public class Abitazione extends Immobile {

    private float balconi;
    private float garage;
    private int vani;

    public Abitazione(
            Indirizzo indirizzo,
            int annoCostruzione,
            char classeEnergetica,
            float superficeInterna,
            float balconi,
            float garage,
            int vani) {
        super(indirizzo, annoCostruzione, classeEnergetica, superficeInterna);
        this.balconi = balconi;
        this.garage = garage;
        this.vani = vani;
    }

    @Override
    public float calcolaSuperficeCommerciale() {
        /*
                superfice interna +
                l'eventuale superfice dei balconi al 30% per i primi 25 mq e al 10% per quelli aggiuntivi+
                l'eventiale superfice dei garage al 50%
         */
        float superficeCommerciale = 0;
        superficeCommerciale += this.getSuperficeInterna();
        if (this.balconi > 0) {
            if (this.balconi > 25) {
                superficeCommerciale += 25 * 0.30;
                superficeCommerciale += (this.balconi - 25) * 0.1;
            } else {
                superficeCommerciale += this.balconi * 0.30;
            }
        }
        superficeCommerciale += this.garage * 0.50;
        return superficeCommerciale;
    }

    @Override
    public String toString() {
        return "[A]" + super.toString();

    }
}
