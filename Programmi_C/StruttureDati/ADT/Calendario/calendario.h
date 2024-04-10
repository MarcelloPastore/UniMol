#define MAX_GIORNI_MESE 30

typedef struct _calendario* calendario;


calendario nuova_data();
calendario set_data (calendario, int, int, int);
calendario somma_giorni (calendario, int);
calendario differenza_giorni (calendario, int);