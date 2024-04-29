/* 
----------------------------------------------------------------
Esercitazione COMPANY, creare un azienda 
----------------------------------------------------------------
*/
#include "liste.h"
#define MAX_SIZE_CHAR 20
#define MAX_SIZE_CF 17
#define MAX_SIZE_DES 200


//! Realizzo le strutture dati dell'azienda () che conterrà i dipendenti (da considerare come i nodi) 
typedef struct _azienda* azienda;
typedef struct _dipendente* dipendente;

/**
 * @brief realizza il nodo dipendente
 * 
 * @param nome 
 * @param cognome 
 * @param codice_fiscale
 * @param aree Lista di stringhe 
 * @param aree_di_resp lista di stringhe 
 * @return dipendente 
 */
dipendente dipendente_new(char* nome, char* cognome, char* cf);
/**
 * @brief aggiunge l'area di azione del dipendente
 * 
 * @param dipendente
 * @param area 
 */
char* dipendente_get_nome(dipendente d);
char* dipendente_get_cognome(dipendente d);
char* dipendente_get_codice_fiscale(dipendente d);
list_stringhe dipendente_get_aree(dipendente d);
/**
 * @brief distrugge la memoria allocata al dipendente (Come il neuralizzatore dei Man In Black) 
 * 
 * @param dipendente
 */
void dipendente_destroy(dipendente dipendnete);
/**
 * @brief Crea una nuova azienda
 * 
 * @return azienda 
 */
azienda azienda_new();
/**
 * @brief Distrugge l'azienda (Ka-Boom)
 * 
 * @param azienda
 */
void azienda_destroy(azienda a);
/**
 * @brief Aggiungere un dipendente al responsabile
 * 
 * @param dipendente
 * @param azienda
 * @param codice_fiscale_del_responsabile 
 */
void azienda_add_dipendente(dipendente dip, azienda a, char* cf_responsabile, list_string aree_aggiuntive);
/**
 * @brief restituisce i responsabili di un dipendente
 * 
 * @param azienda
 * @return list 
 */
list_dipendenti azienda_get_responsabili(azienda a, dipendente dip);
/**
 * @brief Funzione che licenzia un dipendente e ne promuove il suo successore (se presente)
 * 
 * @param azienda
 * @param codice_fiscale
 * @return int 
 */
int azienda_licenzia(azienda a, char* cf);
/**
 * @brief Restituisce l'elenco dell'azienda
 * 
 * @param azienda
 */
void azienda_livello_dipendente(azienda a, dipendente dip);
/**
 * @brief restituisce la lista dei dipendenti di un azienda
 * 
 * @param azienda
 * @return list 
 */
list_dipendenti elenco_dipendenti(azienda a);
/**
 * @brief Dettagli del dipendente singolo
 * 
 * @param dipendente
 * @return dipendente 
 */
dipendente dettagli_dipendente(azienda a, char*cf_dipendente);
/**
 * @brief Restituisce l'elenco dei dipendenti di un determinato responsabile
 * 
 * @param responsabile 
 * @return lista 
 */
list elenco_dip_da_responsabile(dipendente responsabile);
