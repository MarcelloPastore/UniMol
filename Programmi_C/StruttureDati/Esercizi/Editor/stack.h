#include <stdbool.h>

typedef struct _stack* stack;

stack stack_new();
void stack_destroy(stack);

int stack_push(stack, char);
int stack_peek(stack, char*);
int stack_pop(stack, char*);
int stack_size(stack);
bool stack_is_empty(stack);

void printa(stack);