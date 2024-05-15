typedef struct _gestione* gestione;

gestione new_array (int);
void destroy_array (gestione);

int set_element (gestione, int, int);
int get_element (gestione, int, int*);
int size_array (gestione);
gestione copy_array (gestione);
int compare_array (gestione, gestione);
void rotate_array (gestione);
float media_array (gestione);
void resize_array (gestione, int);

void array_print (gestione);