#include "game.h"

char *deleting_personage(char *str) {
    char *str_new = malloc(strlen(str) + 1);
    for (unsigned long i = 0; i < strlen(str); i++) {
        str_new[i] = ' ';
    }
    str_new[strlen(str)] = '\0';
    return str_new;
}
