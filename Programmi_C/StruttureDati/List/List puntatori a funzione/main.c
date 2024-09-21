#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

// O(N^2)
void print_list_2(list l){
    int size = list_size(l);
    for (int i = 0; i < size; i++)// O(N)
    {
        int element;
        list_get_element(l, i, &element);// O(N)
        printf("%d, ", element);
    }
    printf("\n");
    
}
// O(N)
void print_list3(list l){
    iterator iter = list_iterate(l);
    while (iterator_has_next(iter)){
        int element = iterator_next(iter);
        printf("%d ", element );
        }
        iterator_destroy(iter);
}   

list merge_list(list l1, list l2){
    list l3 = list_new();

    iterator iter1 = list_iterate(l1);
    iterator iter2 = list_iterate(l2);

    int last1;
    int last2;

    if (iterator_has_next(iter1)) {
        last1 = iterator_next(iter1);
    }else {
        while (iterator_has_next(iter2)){
            list_append(l3, iterator_next(iter2));        
            }
            iterator_destroy(iter2);
            iterator_destroy(iter1);
            return l3;
    }
    if (iterator_has_next(iter1)) {
        last2 = iterator_next(iter2);
    }else {
        while (iterator_has_next(iter1)){
            list_append(l3, iterator_next(iter1));        
        }
        iterator_destroy(iter2);
        iterator_destroy(iter1);
        return l3;
    }
    do {
        if (last1 < last2){
            list_append(l3, last1);
            last1 = iterator_next(iter1);
        } else {
            list_append(l3, last2);
            last2 = iterator_next(iter2);
        }
        // confrontiamo last1 e last2
        // aggiungiamo a l3 il minore
        // aggiorniamo last1 o last2

    } while (iterator_has_next(iter1) && iterator_has_next(iter2));

    if (last1 < last2){
        list_append(l3, last1);
        list_append(l3, last2);
    }else {
        list_append(l3, last2);
        list_append(l3, last1);
    }
    

    while (iterator_has_next(iter1)){
        /* aggiungi a l3 */
        int value = iterator_next(iter1);
        list_append(l3, value);
    }
    while (iterator_has_next(iter2)){
        /* aggiungi a l3 */
        int value = iterator_next(iter2);
        list_append(l3, value);
    }
    iterator_destroy(iter2);
    iterator_destroy(iter1);
    return l3;
}

int main () {
    list x = list_new();
    int answer;
    do
    {
        printf("\nInserisci un elemento della lista o -1 per uscire: ");
        scanf("%d", &answer);
        if (answer != -1) {
            list_append(x, answer);
        }
    } while (answer != -1);

    printf("\nSize: %d", list_size_rec(x));
    printf("\n");
    
    print_list(x);
    remove_duplicates(x);
    // list_remove_all_values(x, 2);
    printf("Lista senza duplicati: ");
    print_list(x);

    printf("Size: %d\n", list_size_rec(x));
    /* list l1 = list_new();
    list l2 = list_new();
    list_append(l1, 1);
    list_append(l1, 2);
    list_append(l1, 5);
    list_append(l1, 6);
    
    list_append(l2, 3);
    list_append(l2, 4);

    print_list(l1);
    print_list(l2);

    list l3 = merge_list(l1, l2);

    print_list(l3);

    list_destroy(l1);
    list_destroy(l2);
    list_destroy(l3); */


    return 0;
}
