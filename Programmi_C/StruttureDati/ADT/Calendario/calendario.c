#include "calendario.h"
#include <stdio.h>
#include <stdlib.h>

struct _calendario {
    int giorno;
    int mese;
    int anno;
};

calendario nuova_data () {
    struct _calendario* data = (struct _calendario*)malloc(sizeof(struct _calendario));
    if (data != NULL) {
        data->giorno = 1;
        data->mese = 1;
        data->anno = 1900;
    }

    return data;
}

calendario set_data (calendario a, int gg, int mm, int aa) {
    printf("Old: %d/%d/%d\n", a->giorno, a->mese, a->anno);

    a->giorno = gg;
    a->mese = mm;
    a->anno = aa;

    printf("New: %d/%d/%d\n", a->giorno, a->mese, a->anno);

    return a;
}

calendario somma_giorni (calendario a, int gg) {
    while (gg + a->giorno > MAX_GIORNI_MESE) {
            a->mese++;
            if (a->mese > 12) {
                a->anno++;
                a->mese -= 12;
            }
            gg = gg - MAX_GIORNI_MESE;
    }
    a->giorno += gg;

    printf("New: %d/%d/%d\n", a->giorno, a->mese, a->anno);

    return a;
}

calendario differenza_giorni (calendario a, int gg) {
    while (a->giorno - gg < 0) {
            a->mese--;
            if (a->mese < 1) {
                a->anno--;
                a->mese += 12;
            }
            gg = gg - MAX_GIORNI_MESE;
    }
    a->giorno -= gg;

    printf("New: %d/%d/%d\n", a->giorno, a->mese, a->anno);

    return a;
}