#include <ncurses.h>
#include <unistd.h>

void move_rabbit_to_portal(WINDOW *rabbit, WINDOW *wmain, int *y, int *x, int path) {
    if (!path)
        mvwin(rabbit, *y, ++(*x));
    else
        mvwin(rabbit, *y, --(*x));
    wrefresh(rabbit);
    wrefresh(wmain);
}
