#include "game.h"

void print_result(int num) {
    char *score[4] = {" ___  ___ _____ ____ ____",
         "/ __)/ __|  _  |  _ | ___) ()",
         "\\__ | (__| |_| |    /)__)",
         "(___/\\___|_____|_)\\_|____) ()"};
    char *numbers[][6] = {
         {" ___  ",
          "/   \\ ",
          "| | | ",
          "\\___/ "},
         {" __   ",
          "/  |  ",
          " | |  ",
          "(___) "},
         {" ___  ",
          "(__ \\ ",
          " / _/ ",
          "(____)"},
         {" ___  ",
          "(__ ) ",
          " (_ \\ ",
          "(___/ "},
         {"  __  ",
          " /. | ",
          "(_  _)",
          "  (_| "},
         {" ___  ",
          "| __) ",
          "|__ \\ ",
          "(___/ "},
         {"  _   ",
          " / )  ",
          "/ _ \\ ",
          "\\___/ "},
         {" ___  ",
          "(__ ) ",
          " / /  ",
          "(_/   "},
         {" ___  ",
          "( _ ) ",
          "/ _ \\ ",
          "\\___/ "},
         {" ___  ",
          "/ _ \\ ",
          "\\_  / ",
          " (_/  "}
    };
    WINDOW *result = newwin(LINES, COLS, 0, 0);
    refresh();
    wattron(result, COLOR_PAIR(1));
    int flag = 0;
    if (num < 10) {
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 10 + COLS / 2, "%s", numbers[num][k]);
        }
        flag = 20;
    }
    else if (num > 9 && num < 100) {
        int num1 = num % 10;
        int num2 = (num / 10) % 10;
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 6 + COLS / 2, "%s", numbers[num2][k]);
        }
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 12 + COLS / 2, "%s", numbers[num1][k]);
        }
        flag = 25;
    }
    else if (num > 99) {
        int num1 = num % 10;
        int num2 = (num / 10) % 10;
        int num3 = (num / 100) % 10;
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 4 + COLS / 2, "%s", numbers[num3][k]);
        }
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 10 + COLS / 2, "%s", numbers[num2][k]);
        }
        for (int k = 0; k < 4; k++) {
            mvwprintw(result, k + LINES / 2 - 4, 16 + COLS / 2, "%s", numbers[num1][k]);
        }
        flag = 30;
    }
    wattroff(result, COLOR_PAIR(1));
    wattron(result, COLOR_PAIR(2));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; score[i][j] != '\0'; j++) {
            mvwprintw(result, LINES / 2 + i - 4, COLS / 2 + j - flag, "%c", score[i][j]);
        }
    }
    wattroff(result, COLOR_PAIR(2));
    wrefresh(result);
}
