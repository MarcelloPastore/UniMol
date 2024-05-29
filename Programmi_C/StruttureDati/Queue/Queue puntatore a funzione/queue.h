#include <stdbool.h>

typedef struct _queue* queue;

queue queue_new();
void queue_destroy(queue q);

int queue_add(queue q, void* value);
int queue_peek(queue q, void** result);
int queue_poll(queue q, void** result);
int queue_size(queue q);
bool queue_is_empty(queue q);
