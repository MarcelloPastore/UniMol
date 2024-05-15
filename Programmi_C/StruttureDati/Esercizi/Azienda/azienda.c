#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "azienda.h"


//* Definisco le strutture dati come da .h

struct _dipendente{
    char* nome;
    char* cognome;
    char* codice_fiscale;
    list aree;
    list area_responsabile;
    struct _dipendente* left;
    struct _dipendente* right;
};
struct _azienda{
    char* nome;
    char* descrizione;
    struct _dipendente* root;
};



dipendente dipendente_new(char* nome, char* cognome, char* cf){
    struct _dipendente* dipendente = (struct _dipendente*)malloc(sizeof(struct _dipendente));
    if(dipendente != NULL){
        dipendente->nome = (char*)malloc(sizeof(char*)*MAX_SIZE_CHAR);
        dipendente->cognome = (char*)malloc(sizeof(char*)*MAX_SIZE_CHAR);
        dipendente->codice_fiscale = (char*)malloc(sizeof(char*)*MAX_SIZE_CF);

        if (dipendente->nome != NULL && dipendente->cognome!=NULL && dipendente->codice_fiscale!=NULL){
            strcpy(dipendente->nome, nome);
            strcpy(dipendente->cognome, cognome);
            strcpy(dipendente->codice_fiscale, cf);
            dipendente->aree = list_new();
            dipendente->area_responsabile = list_new();
            dipendente->left = NULL;
            dipendente->right = NULL;
        }
    }
    return dipendente;
}

void dipendente_destroy(dipendente dip);

azienda azienda_new(char* nome, char* descrizione){
    struct _azienda* azienda = (struct _azienda*)malloc(sizeof(struct _azienda));
    if (azienda!=NULL){
        azienda->nome=(char*)malloc(sizeof(char*)*MAX_SIZE_CHAR);
        azienda->descrizione=(char*)malloc(sizeof(char*)*MAX_SIZE_DES);
        azienda->root = NULL;
        if (azienda->nome != NULL && azienda->descrizione!=NULL){
            strcpy(azienda->nome, nome);
            strcpy(azienda->descrizione, descrizione);
        }
    }
    return azienda;
}

void azienda_destroy(azienda a);

void azienda_add_dipendente(dipendente dip, azienda a, char* cf_responsabile);

list azienda_get_responsabili(azienda a, dipendente dip);

int azienda_licenzia(azienda a, char* cf);

void azienda_livello_dipendente(azienda a, dipendente dip);

list elenco_dipendenti(azienda a);

dipendente dettagli_dipendente(dipendente dip);

list elenco_dip_da_responsabile(dipendente responsabile);