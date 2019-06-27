#include "game.h"

void move_timer(int *timer, int counter) {
    if (counter < 70)
        *timer -= counter * 2 + 300;
    else
        *timer -= 70 * 2 + 300;
}
