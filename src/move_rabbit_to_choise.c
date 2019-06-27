#include <ncurses.h>
#include <unistd.h>

void move_rabbit_to_choise(WINDOW *rabbit, WINDOW *wmain, int *y, int *x) {
	mvwin(rabbit, ++(*y), *x);
	wrefresh(rabbit);
	wrefresh(wmain);
}	
