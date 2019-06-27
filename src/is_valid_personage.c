#include "game.h"

bool is_valid_personage(pers *personage, pers *invalid_personage) {
    if (personage->head != invalid_personage->head)
	    return true;
    if (personage->body != invalid_personage->body)
	    return true;
    if (personage->legs != invalid_personage->legs)
	    return true;
    return false;
}
