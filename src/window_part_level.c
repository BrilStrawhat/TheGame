#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>

void window_part_level(WINDOW *level, char *fname) {
	char buf;
	int y = 0;
	int x = 0;
	int fd;
	
	fd = open(fname, O_RDONLY);
	for (; read(fd, &buf, 1) == true; x++) {
		if (buf == '\n') {
			x = -1;
			y += 1;
			continue;
		}
		mvwprintw(level, y, x, &buf);
	}
	close(fd);
	wrefresh(level);
}
