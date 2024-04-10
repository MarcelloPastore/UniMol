#include <stdbool.h>

typedef struct _queue* queue; //Puntatore opaco

queue queue_new();
void queue_destroy(queue);

int queue_add(queue, char*);
int queue_peek(queue, char*);
int queue_poll(queue, char*);
int queue_size(queue);
bool queue_is_empty(queue);

void alt_printa(queue);