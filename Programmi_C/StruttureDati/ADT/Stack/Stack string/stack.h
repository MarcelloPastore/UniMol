#include <stdbool.h>
// ! Definiamo la struttura della pila
typedef struct _stack* stack;
// ! Definiamo le funzioni essenziali della pila
stack stack_new();
void stack_destroy(stack s);
int stack_push(stack s, char value);
int stack_peek(stack s, char *result);
int stack_pop(stack s, char *result);
int stack_size(stack s);
bool stack_is_empty(stack s);