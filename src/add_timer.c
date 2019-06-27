#include "game.h"

void add_timer(int *timer) {
    *timer = *timer + TIMER_VAL + 80000;
    if (*timer > MAX_TIMER)
        *timer = MAX_TIMER;
}
