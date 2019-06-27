#include "game.h"

static char get_rchar();

char *atomizating_personage(char *str) {
    char *str_new = malloc(strlen(str) + 1);
    for (unsigned long i = 0; i < strlen(str); i++) {
        str_new[i] = get_rchar();
    }
    str_new[strlen(str)] = '\0';
    return str_new;
}

static char get_rchar() {
    int r = rand() % 3;
    if (r == 0) 
        return ' ';
    else
        return rand() % 6 + 32;
}
