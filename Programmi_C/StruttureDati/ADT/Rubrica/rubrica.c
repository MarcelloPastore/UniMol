#include "rubrica.h"
#include <stdio.h>

struct _contatto {
    char nome[MAX_TAGLIA_NOMI];
    char cognome[MAX_TAGLIA_NOMI];
    char numero[MAX_TAGLIA_NUMERO];
};

struct _rubrica {
    contatto array_contatti[MAX_CONTATTI];
    int numero_contatti;
};

//Funzione che aggiunge un nuovo contatto alla rubrica
int add_contact (contatto a, rubrica b, char* _name, char* _surname, char* _number) {
    static int numero_contatti = 0;
    if (b->numero_contatti < MAX_CONTATTI) {
        a->nome[MAX_TAGLIA_NOMI] = _name[MAX_TAGLIA_NOMI];
        a->cognome[MAX_TAGLIA_NOMI] = _surname[MAX_TAGLIA_NOMI];
        a->numero[MAX_TAGLIA_NUMERO] = _number[MAX_TAGLIA_NUMERO];
    
        b->numero_contatti++;
        return 0;
    } else {
        return ERROR_FULL_RUBRICA;
    }
}

//Funzione che stampa tutti i contatti presenti in rubrica
void view_contacts (contatto a, rubrica b) {
    for (int i=0; i < b->numero_contatti; i++) {
        printf("|--------------------------|\n");
        printf("%s ", a->nome[i]);
        printf("%s\n\n", a->cognome[i]);
        
        printf("Numero: ");
        printf("%s", a->numero[i]);
    }
}

//Funzione che ricerca un contatto tramite il cognome e restituisce il numero
char* search_contact (contatto a, rubrica b, char* _surname) {
    for (int i=0; i < b->numero_contatti; i++) {
        if (a->cognome[i] == _surname) {
            return a->numero;
        }
    }
    return CONTACT_NOT_FOUND;
}

//Funzione che ricerca un contatto tramite il cognome e lo modifica
void edit_contact (contatto a, rubrica b,  char* _old, char* _name, char* _surname, char* _number) {
    for (int i=0; i < b->numero_contatti; i++) {
        if (a->cognome[i] == _old) {
            a->nome[i] = _name;
            a->cognome[i] = _surname;
            a->numero[i] = _number;
        }
    }
}