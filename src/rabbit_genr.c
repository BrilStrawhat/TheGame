#include <ncurses.h>

void rabbit_genr(int color, WINDOW *w_rabbits, char *rabbit[3]) {
	    init_pair(9,  1, COLOR_BLACK);
	    init_pair(10, 2, COLOR_BLACK);
	    init_pair(11, 3, COLOR_BLACK);
	for (int i = 0; i < 3; i++) {
    	wmove(w_rabbits, i, 2);	
    	wattron(w_rabbits, COLOR_PAIR(color));
    	waddstr(w_rabbits, rabbit[i]);
    	wrefresh(w_rabbits);
    	wattroff(w_rabbits, COLOR_PAIR(color));
    	wrefresh(w_rabbits);
	}
}
