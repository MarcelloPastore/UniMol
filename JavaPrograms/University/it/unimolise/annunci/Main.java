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
        Abitazione b = new Abitazione(
                new Indirizzo("Torrecuso", "Via Tora I", "55"),
                1950,
                'F',
                250,
                15,
                0,
                8
        );
        Abitazione c = new Abitazione(
                new Indirizzo("Palata", "Via Vincenzo Cuoco", "9"),
                1945,
                'E',
                140,
                10,
                0,
                4
        );
        gestore.addImmobile(a);
        gestore.addImmobile(b);
        gestore.addImmobile(c);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);

        if (a.equals(c)) {
            System.out.println("Uguali");
        } else {
            System.out.println("NON uguali");
        }
    }
}
