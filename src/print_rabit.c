#include <ncurses.h>
#include <stdlib.h>

void print_rabbit(int head, int body, int legs, WINDOW *pers_win, int costil) {
    head++;
    body++;
    legs++;
    if (costil == 0) {
	    init_pair(6, head, COLOR_BLACK);
	    init_pair(7, body, COLOR_BLACK);
    	init_pair(8, legs, COLOR_BLACK);
    }
	int color = 6;
	char *rabbit[8];
	rabbit[0] = "         ";
	rabbit[1] = "    ___  ";
	rabbit[2] = "   /. .\\  ";
	rabbit[3] = "  (  -  )  ";
	rabbit[4] = " /\"/---\\\"\\  ";
	rabbit[5] = " '|     |'  ";
	rabbit[6] = "  \\\\___//  ";
	rabbit[7] = "   ('Y')  ";

	for (int i = 0; i < 8; i++) {
		if (i == 4)
			color = 7;
		else if (i == 7)
			color = 8;
		wmove(pers_win, i, 0);	
		wattron(pers_win, COLOR_PAIR(color));
		waddstr(pers_win, rabbit[i]);
		wrefresh(pers_win);
		wattroff(pers_win, COLOR_PAIR(color));
		wrefresh(pers_win);
	}
}
