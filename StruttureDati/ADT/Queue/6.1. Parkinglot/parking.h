typedef struct _parkinglot* parkinglot;
#define CAR_PARKED 0
#define CAR_IN_QUEUE 1

// Genero "Fila", "Parcheggio" e "Manovra" al momento dell'inizializzazione del parcheggio, selezionando le size interessate
parkinglot parkinglot_new(int, int);
void parkinglot_destroy(parkinglot);

// Parcheggia l'auto data in input, ritorna 0 se il parcheggio è pieno e l'auto finisce in coda, 1 se il parcheggio avviene con successo
int parkinglot_park(parkinglot, int);
// Prendo lo stack "Parcheggio" e sposto auto nello stack "Manovra" fino a liberare l'auto da far uscire, restituisco true se l'auto esce con successo e ri-sposto le auto da "Manovra" a "Parcheggio". Se l'auto non può uscire o non esiste ritorna un errore (false)
bool parkinglot_exit(parkinglot, int);
// Scorro lo stack "Parcheggio" ed incremento un contatore per identificare la posizione della macchina parcheggiata
int parkinglot_park_position(parkinglot, int);
// Scorro la queue "Fila" ed incremento un contatore per identificare la posizione della macchina in coda
int parkinglot_queue_position(parkinglot, int);
// Funzione che restituisce true se l'auto è parcheggiata o in coda, false altrimenti
bool parkinglot_check_car_presence(parkinglot, int);
// Restituisce l'id dell'ultima auto parcheggiata o -1 se non ci sono auto parcheggiate
int parkinglot_last_car_parked(parkinglot);