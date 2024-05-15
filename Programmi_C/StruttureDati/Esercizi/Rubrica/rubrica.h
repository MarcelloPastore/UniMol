#define MAX_TAGLIA_NOMI 20
#define MAX_TAGLIA_NUMERO 11
#define MAX_CONTATTI 10
#define ERROR_FULL_RUBRICA -1
#define CONTACT_NOT_FOUND NULL

typedef struct _contatto* contatto;
typedef struct _rubrica* rubrica;

int add_contact (contatto, rubrica, char*, char*, char*);
void view_contacts (contatto, rubrica);
char* search_contact (contatto, rubrica, char*);
void edit_contact (contatto, rubrica, char*, char*, char*, char*);