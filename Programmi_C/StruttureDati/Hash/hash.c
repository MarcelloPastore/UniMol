
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "./List_standard/list.h"

typedef struct _entity{
    char* key;
    int value;
}hash_entity;

struct _hash {
    int capacity;
    list* buckets;
};

int hashing (char* str, int capacity){
    int key = 0;
    for (size_t i = 0; i < strlen(str); i++){
        key += str[i];
        key %= capacity;
    }
    return key;
}


hash hash_new(int capacity){
    (struct _hash*) h = (struct _hash*)malloc(sizeof(struct _hash));
    if (h!= NULL){
        h->capacity = capacity;
        h->buckets = (list*)malloc(sizeof(list) * h->capacity);
        for (size_t i = 0; i < (h->capacity-1); i++){
            h->buckets[i] = list_new(TYPE_POINTER);//con le union non dobbiamo modificare la lista
        }
    }
}

void destroy_hash(hash h){
    for (size_t i = 0; i < h->capacity; i++){
        list l = h->buckets[i];
        iterator iter = list_iterate(l);
        while (iterator_has_next(iter) && result!=NULL){
            listelement e = iterator_next(iter);
            hash_entity* entity = (hash_entity*)e.pval;
            free(entity);
        }
    iterator_destroy(iter);
    list_destroy(l);
    }
    free(h->buckets);
    free(h);
}

void hash_set(hash h, char* key, int value){
    int bucket_number = hashing(key, h->capacity);
    list l = h->buckets[bucket_number];

    iterator iter = list_iterate(l);
    bool found == false;
    while (iterator_has_next(iter) && result!=NULL){
        listelement e = iterator_next(iter);
        hash_entity* entity = (hash_entity*)e.pval;
        if (strcmp(entity->key, key) == 0){
            entity->value = value;
            found = true;
        }
    }
    iterator_destroy(iter);
    if (!found){
        hash_entity* entity = (hash_entity*)malloc(sizeof(hash_entity));
        entity->key = key;
        entity->value = value;

        listelement element;
        element.pval = (void*)entity;
        list_append(l, element);
    } 
}

int hash_get(hash h, charh* key){
    int bucket_number = hashing(key, h->capacity);
    list l = h->buckets[bucket_number];

    iterator iter = list_iterate(l);
    hash_entity* result = NULL;
    while (iterator_has_next(iter) && result!=NULL){
        listelement e = iterator_next(iter);
        hash_entity* entity = (hash_entity*)e.pval;
        if (strcmp(entity->key, key) == 0){
            result = entity;
        }
    }
    iterator_destroy(iter);
    if (result!=NULL){
        return entity->value;
    } else {
        return -1;
    }
}
int hash_size(hash h){
    int totalsize = 0;
    for (size_t i = 0; i < h->capacity; i++){
        totalsize += list_size(h->buckets[i]);
    }
    return totalsize;
}