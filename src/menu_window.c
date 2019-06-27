#include "game.h"

static char *get_rand_symbols(char *s);
static char *get_rand_lines(char *s);

int menu_window() {
    char *menu[] = {
"     ______  _______          ____   _________________      _____    ____                  ",
"    |      \\/       \\    ____|\\   \\ /                 \\ ___|\\    \\  |    |_____      _____ ",
"   /          /\\     \\  /    /\\    \\______     ______/ |    |\\    \\ |    |\\    \\    /    / ",
"  /     /\\   / /\\     ||    |  |    |     /    /       |    | |    ||    | \\    \\  /    /  ",
" /     /\\ \\_/ / /    /||    |__|    |     |   |        |    |/    / |    |  \\    \\/    /   ",
"|     |  \\|_|/ /    / ||    .--.    |     |   |        |    |\\    \\ |    |  /    /\\    \\   ",
"|     |       |    |  ||    |  |    |    /   //        |    | |    ||    | /    /  \\    \\  ",
"|\\____\\       |____|  /|____|  |____|   /___//         |____| |____||____|/____/ /\\ \\____\\ ",
"| |    |      |    | / |    |  |    |  |    |          |    | |    ||    ||    |/  \\|    | ",
" \\|____|      |____|/  |____|  |____|  |____|          |____| |____||____||____|    |____| ",
"                                                                                           ",
"          _____     ____   ____          _____      ____        _____         ______       ",
"      ___|\\    \\   |    | |    |    ____|\\    \\    |    |   ___|\\    \\    ___|\\     \\      ",
"     /    /\\    \\  |    | |    |   /     /\\    \\   |    |  /    /\\    \\  |     \\     \\     ",
"    |    |  |    | |    |_|    |  /     /  \\    \\  |    | |    |  |    | |     ,_____/|    ",
"    |    |  |____| |    .-.    | |     |    |    | |    | |    |  |____| |     \\--'\\_|/    ",
"    |    |   ____  |    | |    | |     |    |    | |    | |    |   ____  |     /___/|      ",
"    |    |  |    | |    | |    | |\\     \\  /    /| |    | |    |  |    | |     \\____|\\     ",
"    |\\ ___\\/    /| |____| |____| | \\_____\\/____/ | |____| |\\ ___\\/    /| |____ '     /|    ",
"    | |   /____/ | |    | |    |  \\ |    ||    | / |    | | |   /____/ | |    /_____/ |    ",
"     \\|___|    | / |____| |____|   \\|____||____|/  |____|  \\|___|    | / |____|     | /    ",
"          |____|/                                                |____|/       |_____|/    "
    };
    char *start[] = {
"    ______________    ____  ______",
"  / ___/_  __/   |  / __ \\/_  __/",
"  \\__ \\ / / / /| | / /_/ / / /   ",
" ___/ // / / ___ |/ _, _/ / /    ",
"/____//_/ /_/  |_/_/ |_| /_/     ",
"                                 "
    };
    char *quit[] = {
"    ____  __  ____________",
"   / __ \\/ / / /  _/_  __/",
" / / / / / / // /  / /   ",
"/ /_/ / /_/ // /  / /    ",
"\\___\\_\\____/___/ /_/     ",
"                         "
    };
    int selection = 0;
    int max_selection = 1;
    int min_selection = 0;
    int ch;
    int flag = 1;
    int exit = 0;
    keypad(stdscr, true);
    curs_set(0);
    noecho();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(A_BOLD | COLOR_PAIR(1));
    for (int i = 0; i < 15 && flag; i++) {
        for (int j = 0; j < 22; j++) {
            mvprintw(HEIGHT / 2 - 25 + j, (WIDTH - strlen(menu[j])) / 2, "%s", get_rand_symbols(menu[j]));
            refresh();
            usleep(5000);
        }
    }
    flag = 0;
    for (int i = 0; i < 22; i++) {
        mvprintw(HEIGHT / 2 - 25 + i, (WIDTH - strlen(menu[i])) / 2, "%s", menu[i]);
        refresh();
        usleep(25000);
    }
    while (true) {
        int rand_animation = rand() % 5;
        if (rand_animation == 1) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 22; i++) {
                int r = rand() % 3;
                if (r == 2) {
                    attroff(COLOR_PAIR(1));
                    attron(COLOR_PAIR(2));
                    mvprintw(HEIGHT / 2 - 25 + i, (WIDTH - strlen(menu[i])) / 2, "%s", get_rand_symbols(menu[i]));
                    attron(COLOR_PAIR(2));
                    attron(COLOR_PAIR(1));
                }
                else
                    mvprintw(HEIGHT / 2 - 25 + i, (WIDTH - strlen(menu[i])) / 2, "%s", menu[i]);
                refresh();
                usleep(2000);
            }
            for (int i = 0; i < 22; i++) {
                mvprintw(HEIGHT / 2 - 25 + i, (WIDTH - strlen(menu[i])) / 2, "%s", menu[i]);
                refresh();
                usleep(5000);
            }
            attron(COLOR_PAIR(1));
        }
        if (selection == 1) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 5; i++) {
                mvprintw(HEIGHT / 2 + 8 + i, (WIDTH - strlen(quit[i])) / 2, "%s", quit[i]);
            }
            mvprintw(HEIGHT / 2 + 8 + 5, (WIDTH - strlen(quit[5])) / 2, "%s", quit[5]);
            attroff(COLOR_PAIR(1));
            mvprintw(HEIGHT / 2 + 5, (WIDTH - strlen(start[5])) / 2, "%s", get_rand_lines(start[5]));
            for (int i = 0; i < 15 && flag; i++) {
                for (int j = 0; j < 5; j++) {
                    mvprintw(HEIGHT / 2 + j, (WIDTH - strlen(start[j])) / 2, "%s", get_rand_symbols(start[j]));
                    refresh();
                    usleep(2000);
                }
            }
            attron(COLOR_PAIR(1));
        }
        else if (selection == 0) {
            attron(COLOR_PAIR(1));
            for (int i = 0; i < 5; i++) {
                 mvprintw(HEIGHT / 2 + i, (WIDTH - strlen(start[i])) / 2, "%s", start[i]);
            }
            mvprintw(HEIGHT / 2 + 5, (WIDTH - strlen(start[5])) / 2, "%s", start[5]);
            attroff(COLOR_PAIR(1));
            mvprintw(HEIGHT / 2 + 8 + 5, (WIDTH - strlen(quit[5])) / 2, "%s", get_rand_lines(quit[5]));
            for (int i = 0; i < 15 && flag; i++) {
                 for (int j = 0; j < 5; j++) {
                     mvprintw(HEIGHT / 2 + 8 + j, (WIDTH - strlen(quit[j])) / 2, "%s", get_rand_symbols(quit[j]));
                     refresh();
                     usleep(2000);
                 }
            }
            attron(COLOR_PAIR(1));
        }
        attroff(COLOR_PAIR(1));
        for (int i = 0; i < 5; i++) {
            if (selection == 0) {
                attron(COLOR_PAIR(1));
            }
            mvprintw(HEIGHT / 2 + i, (WIDTH - strlen(start[i])) / 2, "%s", start[i]);
            refresh();
            usleep(5000);
        }
        attroff(COLOR_PAIR(1));
        for (int i = 0; i < 5; i++) {
            if (selection == 1) {
                attron(COLOR_PAIR(1));
            }
            mvprintw(HEIGHT / 2 + 8 + i, (WIDTH - strlen(quit[i])) / 2, "%s", quit[i]);
            refresh();
            usleep(5000);
        }
        attroff(COLOR_PAIR(1));
        flag = 0;
        refresh();
        if (exit) {
            break;
        }
        ch = getch();
        flushinp();
        switch (ch) {
            case 10:
                if (selection == 0) {
                    exit = 1;
                }
                else if (selection == 1) {
                    clear();
                    return 2;
                }
                break;
            case KEY_UP:
                selection++;
                flag = 1;
                if (selection > max_selection) {
                    selection = min_selection;
                }
                break;
            case KEY_DOWN:
                selection--;
                flag = 1;
                if (selection < min_selection) {
                    selection = max_selection;
                }
                break;
        }
    }
    clear();
    return 1;
}

static char *get_rand_lines(char *s) {
    int len = strlen(s) - 6;
    
    char *new_str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int rand_num = rand() % 2;
        if (rand_num == 1) {
            new_str[i] = '+';
        }
        else if (rand_num == 0) {
            new_str[i] = '~';
        }
    }
    new_str[len] = '\0';
    return new_str;
}

static char *get_rand_symbols(char *s) {
    int len = strlen(s);
    char *new_str = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') 
            new_str[i] = rand() % 14 + 32;
        else
            new_str[i] = ' ';
    }
    new_str[len] = '\0';
    return new_str;
}
