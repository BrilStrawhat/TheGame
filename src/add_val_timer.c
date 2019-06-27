#include "game.h"

void add_val_timer(int *timer, int val) {
    *timer = *timer + val;
    if (*timer > MAX_TIMER)
        *timer = MAX_TIMER;
}
