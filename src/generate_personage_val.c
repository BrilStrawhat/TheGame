#include "game.h"

pers *generate_personage_val(int head, int body, int legs, int bonus) {
    pers *new_person = (pers *) malloc(sizeof(pers));
    
    new_person->head = head;
    new_person->body = body;
    new_person->legs = legs;
    new_person->bonus = bonus;
    return new_person; 
}
