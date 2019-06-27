#include "game.h"

void window_print_line(char **string, WINDOW **window_line, int attr, int line,  int size) {
    if (line == 0) {
        for (int i = 0; i < size; i++) {
            wattron(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            window_vertical_line(string[i], window_line[i]);
            wattroff(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            wrefresh(window_line[i]);
        }
    }
    else if (line == 1) {
        for (int i = 0; i < size; i++) {
            wattron(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            window_horizontal_line_left(string[i], window_line[i]);
            wattroff(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            wrefresh(window_line[i]);
        }
    }
    else if (line == 2) {
        for (int i = 0; i < size; i++) {
            wattron(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            window_horizontal_line_right(string[i], window_line[i]);
            wattroff(window_line[i], COLOR_PAIR(attr) | A_BOLD);
            wrefresh(window_line[i]);
        }
    }
}
