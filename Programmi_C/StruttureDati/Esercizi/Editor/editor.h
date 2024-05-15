#include <stdbool.h>

typedef struct _editor* editor;

/**
 * Alloca in memoria un nuovo editor
 * 
 * @param indice indica la posizione del cursore
 * 
 * @return puntatore alla struttura editor
 */
editor editor_new();
/**
 * Libera la memoria dell'editor
 * 
 * @param e indica un editor
 */
void editor_destroy(editor e);
/**
 * Stampa l'editor 
 * 
 * @param e indica un editor
 */
void editor_testo(editor e, char* buffer);
/**
 * Stampa l'editor con il cursore
 * 
 * @param e indica un editor
 */
void editor_testo_con_cursore(editor e, char* buffer);
/**
 * Aggiunge un carattere nell'editor
 * 
 * @param e indica un editor
 * @param c indica il carattere da inserire
 */
void editor_inserisci_carattere(editor e, char c);
/**
 * Cancella l'ultimo carattere inserito
 * 
 * @param e indica un editor
 * 
 */
void editor_cancella_carattere(editor e);
/**
 * Annulla l'ultima operazione effettuata
 * 
 * @param e indica un editor 
 */
bool editor_undo(editor e);

bool editor_sposta_cursore_sinistra(editor e);
bool editor_sposta_cursore_destra(editor e);
int editor_caratteri(editor e);