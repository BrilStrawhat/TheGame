#include "game.h"

pers *generate_personage_chance(pers *invalid_personage) {
    int rand_num = rand() % 100;
    if (rand_num < 50) {
        return generate_valid_personage(invalid_personage);
    }
    else if (rand_num > 49) {
        return generate_invalid_personage(invalid_personage);
    }
    return NULL;
}
