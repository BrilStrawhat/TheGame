#include "game.h"

void regenerate_personage(pers *personage){
    personage->head = rand() % HEAD;
    personage->body = rand() % BODY;
    personage->legs = rand() % LEGS;
    personage->bonus = 0;
}
