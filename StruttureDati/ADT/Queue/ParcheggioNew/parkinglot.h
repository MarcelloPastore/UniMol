#include <stdbool.h>

#define CAR_PARKED 0
#define CAR_IN_QUEUE 1

typedef struct _parkinglot* parkinglot;
/**
 * Alloca in memoria un nuovo parking lot
 *  
 * @param parking_size dimensioni del parcheggio
 * @param maneuvering_area_size dimensione dell'area di memoria
 * 
 * @return puntatore alla struttura parkinglot
  */
parkinglot parkinglot_new(int parking_size, int maneuvering_area_size);
/**
 * 
 * 
 */
void parkinglot_destroy(parkinglot pl);

/** 
* Restituisce la posizione dell'auto all'interno del parcheggio
* @param pl un parking lot non può essere NULL
* @param car_id identificativo dell'auto (intero positivodiverso da 0)
* @return -1 se l'auto non è parcheggiata o la sua posizione nel parcheggio
dove 0 indica che l'auto è alla distanza massima dall'uscita e N indica che 
è vicina all'uscita (dove N è la dimensione del parcheggio)
*/
int parkinglot_car_position(parkinglot pl, int car_id);

/** La funzione restituisce -1 se l'auto non è in coda
 * @param pl un parking lot non può essere NULL
 * @param car_id identificativo dell'auto (intero positivodiverso da 0)
 * 
 * @return -1 se l'auto non è in coda (anche se è parcheggiata), o, altrimenti, la sua posizione nella coda,
dove 0 indica che l'auto è la prossima che sarà parcheggiata. 
*/
int parkinglot_car_position_in_queue(parkinglot pl, int car_id);

/** controlla se l'auto è nel parcheggio o meno
 *  @param pl un parking lot non può essere NULL
 *  @param car_id identificativo dell'auto (intero positivodiverso da 0)
 * 
 * La funzione restituisce true se l'auto è parcheggiata o in coda,
* false altrimenti. 
*/
bool parkinglot_check_car_presence(parkinglot pl, int car_id);

/** Parcheggia l'auto data in input
 * @param pl un parking lot non può essere NULL
 * @param car_id identificativo dell'auto (intero positivodiverso da 0)
 * La funzione parcheggia l'auto data in input (car_id). 
Se l'auto viene parcheggiata, restituisce 0;
Se l'auto va in coda, restituisce 1; */
int parkinglot_park(parkinglot pl, int car_id);

/* La funzione restituisce l'identificativo dell'ultima auto parcheggiata
(quella più vicina all'uscita). La funzione restituisce -1 se nessuna
auto è parcheggiata. */
int parkinglot_last_parked_car(parkinglot pl);

/* Se car_id può uscire ed è nel parcheggio, la funzione la rimuove dal
parcheggio e restituisce true. Altrimenti, restituisce false. */
bool parkinglot_exit(parkinglot pl, int car_id);
