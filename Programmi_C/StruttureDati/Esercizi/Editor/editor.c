#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "editor.h"
#include "liste.h"
#include "stack.h"

struct _editor {
    list caratteri;
    stack operazioni;
    int cursore;
};

editor editor_new(){
    struct _editor* e = (struct _editor*)malloc(sizeof(struct _editor));

    if (e != NULL){
        e->caratteri = list_new();
        e->operazioni = stack_new();
        e->cursore = 0;
    }

    return e;
}

void editor_destroy(editor e){
    list_destroy(e->caratteri);
    stack_destroy(e->operazioni);
    free(e);
}

int editor_caratteri(editor e) {
    return list_size(e->caratteri);
}

void editor_testo(editor e, char* buffer){
    iterator iter = list_iterate(e->caratteri);
    int i = 0;
    while (iterator_has_next(iter))
    {
        char value = (char)iterator_next(iter);
        buffer[i] = value;
        i++;
    }
    buffer[i] = 0;
    
}

void editor_testo_con_cursore(editor e, char* buffer);

void editor_inserisci_carattere(editor e, char a);

void editor_cancella_carattere(editor e){
    int to_delete = e->cursore-1;
    if (to_delete > 0){
        list_remove_by_index(e->caratteri, to_delete);
    }
}

bool editor_undo(editor e);

bool editor_sposta_cursore_sinistra(editor e){
    if (e->cursore>0){
        e->cursore--;
        return true;
    }
    return false;
}

bool editor_sposta_cursore_destra(editor e){
    if (e->cursore < editor_caratteri(e)){
        e->cursore++;
        return true;
    }
    return false;
}