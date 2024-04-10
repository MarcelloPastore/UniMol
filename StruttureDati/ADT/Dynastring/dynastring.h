#define ERROR_FULL_DYNARRAY 1
#define ERROR_INVALID_INDEX 2

typedef struct _dynastring* dynastring;

dynastring dynastring_new ();
void dynastring_destroy (dynastring);

int dynastring_add_element (dynastring, char*);
void dynastring_clear (dynastring);
int dynastring_set_element (dynastring, int, char*);
int dynastring_size (dynastring);
void dynastring_remove_element (dynastring, int);

void dynastring_print (dynastring);