package it.unimolise.annunci;

import it.unimolise.annunci.app.Abitazione;
import it.unimolise.annunci.app.GestoreImmobili;
import it.unimolise.annunci.app.Indirizzo;

public class Main {

    public static void main(String[] arg) {
        GestoreImmobili gestore = new GestoreImmobili();

        Abitazione a = new Abitazione(
                new Indirizzo("Termoli", "Via Asia", "1"),
                1980,
                'F',
                140,
                13,
                0,
                5
        );
        gestore.addImmobile(a);
        System.out.println(a.calcolaSuperficeCommerciale());
    }
}
