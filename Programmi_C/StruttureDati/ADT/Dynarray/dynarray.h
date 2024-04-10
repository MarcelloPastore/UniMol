#define ERROR_FULL_DYNARRAY 1
#define ERROR_INVALID_INDEX 2

typedef struct _dynarray* dynarray;

dynarray dynarray_new ();
void dynarray_destroy (dynarray);

int dynarray_add_element (dynarray, int);
void dynarray_clear (dynarray);
int dynarray_get_element (dynarray, int, int*);
int dynarray_set_element (dynarray, int, int);
int dynarray_size (dynarray);

void dynarray_print (dynarray);