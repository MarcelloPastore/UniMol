package it.unimolise.annunci.app;

public class LocaleCommerciale extends Immobile {

    private float volume;

    public LocaleCommerciale(Indirizzo indirizzo,
            int annoCostruzione,
            char classeEnergetica,
            float superficeInterna,
            float volume) {
        super(indirizzo, annoCostruzione, classeEnergetica, superficeInterna);
        this.volume = volume;
    }

    public float calcolaSuperficeCommerciale() {
        return this.getSuperficeInterna() + volume;
    }
}
