#include "game.h"

void free_personage(pers *personage) {
    free(personage);
    personage = NULL;
} 
