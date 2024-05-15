#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
#include "parkinglot.h"

struct _parkinglot {
    queue coda_auto;
    stack parcheggio;
    stack area_manovra;

    int parking_size;
    int maneuvering_area_size;
};
parkinglot parkinglot_new(int parking_size, int maneuvering_area_size){
    struct _parkinglot* pl = (struct _parkinglot*)malloc(sizeof(struct _parkinglot));

    if (pl != NULL)
    {
        pl -> coda_auto = queue_new();
        pl -> parcheggio = stack_new();
        pl -> area_manovra = stack_new();
        pl -> parking_size = parking_size;
        pl -> maneuvering_area_size = maneuvering_area_size;
    }

    return pl;
}

void parkinglot_destroy(parkinglot pl){
    queue_destroy(pl->coda_auto);
    stack_destroy(pl->parcheggio);
    stack_destroy(pl->area_manovra);
    free(pl);
}

int parkinglot_park(parkinglot pl, int car_id){
    if (stack_size(pl->parcheggio) < pl->parking_size){
        stack_push(pl->parcheggio, car_id);
        return CAR_PARKED;
    }else {
        queue_add(pl->coda_auto, car_id);
        return CAR_IN_QUEUE;
    }
}

bool parkinglot_exit(parkinglot pl, int car_id){
    int parked_car;
    do{
         int r =  stack_pop(pl->parcheggio, &parked_car);
         if (r == 0 && parked_car != car_id){
            stack_push(pl->area_manovra, parked_car);
         }
    }
    while (parked_car != car_id && 
    stack_size(pl->area_manovra)<pl->maneuvering_area_size && 
    !stack_is_empty(pl->parcheggio));
    
    while (!stack_is_empty(pl->area_manovra)){
        int car_to_repark;
        stack_pop(pl->area_manovra, &car_to_repark);
        stack_push(pl->parcheggio, car_to_repark);
    }
    if (parked_car == car_id){
        if (!queue_is_empty(pl->coda_auto)){
        int new_car_to_park;
        queue_poll(pl->coda_auto, &new_car_to_park);
        stack_push(pl->parcheggio, new_car_to_park);
        }
        return true;
    }
    return false;
}