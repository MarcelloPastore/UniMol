/* 
----------------------------------------------------------------
Esercitazione COMPANY, creare un azienda 
----------------------------------------------------------------
*/
#include "liste.h"


//! Realizzo le strutture dati dell'azienda () che conterrà i dipendenti (da considerare come i nodi) 
typedef struct _azienda* azienda;
typedef struct _dipendente* dipendente;

/**
 * @brief realizza il nodo dipendente
 * 
 * @param nome 
 * @param cognome 
 * @param cf 
 * @param aree Lista di stringhe 
 * @param livello 
 * @return dipendente 
 */
dipendente dipendente_new(char* nome, char* cognome, char* cf, list aree, int livello);
/**
 * @brief distrugge la memoria alloca al dipendente (Come il neuralizzatore dei Man In Black) 
 * 
 * @param dip 
 */
void dipendente_destroy(dipendente dip);
/**
 * @brief Ritorna il responsabile dell'albero (o sottoalbero) azienda
 * 
 * @param a Azienda
 * @return dipendente 
 */
dipendente dipendente_get_responsbile(azienda a);
/**
 * @brief Crea una nuova azienda
 * 
 * @return azienda 
 */
azienda azienda_new();
/**
 * @brief Distrugge l'azienda (Ka-Boom)
 * 
 * @param a Azienda
 */
void azienda_destroy(azienda a);
/**
 * @brief definisce il resposabile (root) dell'albero (o sottoalbero) preso in considerazione
 * 
 * @param a Azienda
 * @param responsabile //
 */
void azienda_set_responsabile(azienda a, dipendente responsabile);
/**
 * @brief restituisce la grandezza dell'azienda
 * 
 * @param a Azienda
 * @return int 
 */
int azienda_licenzia(azienda a, char* cf);
/**
 * @brief Restituisce l'elenco dell'azienda
 * 
 * @param a Azienda
 */
void azienda_livello_dipendente(azienda a, dipendente dip);
/**
 * @brief Aggiunge un dipendente all'azienda    
 * 
 * @param a Azienda
 * @param dip Dipendente
 */
void azienda_add_dipendente(azienda a, dipendente dip);
