#include "game.h"

pers *generate_personage() {
    pers *new_pers = malloc(sizeof(pers));

    new_pers->head = rand() % HEAD;
    new_pers->body = rand() % BODY;
    new_pers->legs = rand() % LEGS;
    new_pers->bonus = 0;
    return new_pers;
}
