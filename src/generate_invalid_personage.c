#include "game.h"

pers *generate_invalid_personage(pers *invalid_personage) {
    pers *new_pers = malloc(sizeof(pers));

    new_pers->head = invalid_personage->head;
    new_pers->body = invalid_personage->body;
    new_pers->legs = invalid_personage->legs;
    new_pers->bonus = invalid_personage->bonus;
    return new_pers;
}
