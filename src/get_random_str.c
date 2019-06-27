#include "game.h"

char *get_random_str(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        str[i] = get_rand_char();
    }
    str[len] = '\0';
    int i = rand() % 5 + 3;
    int count_spaces = 0;
    int max_spaces = rand() % 2 + 3;

    for (; i < len && count_spaces <= max_spaces; i++) {
        int space = rand() % 5 + 6;
        for (int j = 0; j < space; j++) {
            str[i + j] = ' ';
        }
        i += space + rand() % 6 + 5;
        count_spaces++;
    }
    return str;
}
