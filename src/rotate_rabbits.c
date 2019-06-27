#include <ncurses.h>

void rotate_rabbits(WINDOW **rabbits) {
    WINDOW *tmp_window = rabbits[0];
    for (int i = 0; i < 3; i++) {
        rabbits[i] = rabbits[i + 1];
    }
    rabbits[3] = tmp_window;
}
