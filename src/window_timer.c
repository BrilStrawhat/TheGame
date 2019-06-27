#include "game.h"

void window_timer(int timer, WINDOW *timer_wind) {
    int part = MAX_TIMER / 53;
    int hashs = 0;

    while (timer >= 0) {
        timer -= part;
        hashs++;
    }
    for (int i = 0; i < hashs; i++) {
        mvwprintw(timer_wind, 0, i, "#");
        mvwprintw(timer_wind, 1, i, "#");
    }
    for (int i = hashs; i < 53; i++) {
        mvwprintw(timer_wind, 0, i, ".");
        mvwprintw(timer_wind, 1, i, ".");
    }
}
