#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

#define HEAD 3
#define BODY 3
#define LEGS 3
#define BONUS 0

#define MAX_TIMER 1000000
#define TIMER_VAL 22500

#define MENU_TXT "menu.txt"
#define MENU_START_BUTTON_TXT "menu_start_button.txt"
#define MENU_QUIT_BUTTON_TXT "menu_quit_button.txt"

#define WIDTH 170
#define HEIGHT 55

typedef struct personage {
    int head; // от 0 до 2
    int body; // от 0 до 2
    int legs; // от 0 до 2
    int bonus;
} pers;

//personage
pers *generate_personage(); //get rand personage
void free_personage(pers *personage); //free memory 
bool is_valid_personage(pers *personage, pers *invalid_personage); // check personage
void regenerate_personage(pers *personage); // regenerate personage
pers *generate_invalid_personage(pers *invalid_personage); // generate invalid personage
pers *generate_valid_personage(pers *invalid_personage); // generate valid personage
pers *generate_personage_val(int head, int body, int legs, int bonus); // generate personage by values
void set_bonus_personage(pers *personage, int bonus); // set bonus on personage
pers *generate_personage_chance(pers *invalid_personage); //generate personage by chance
//

//counter
int *get_arr_counter(int counter); //return array of digits from number //TODO
int get_counter(); //return new counter;
void add_count(int *counter); //add 1 to counter
void add_val_count(int *counter, int value); // add value to counter
int get_length_num(int num); // return length of num
//

//timer
int get_timer(); //return 0 timer
void move_timer(int *timer, int counter); //substract timer
bool check_timer(int timer); // check timer 0
void add_timer(int *timer); // add TIMER_VAL to timer
void add_val_timer(int *timer, int val); // add custom val to timer
void window_timer(int timer, WINDOW *timer_wind);
//

//menu
int menu_window();
void window_timer(int timer, WINDOW *timer_wind);
void counter_window(int counter, WINDOW *counter_wind);
void window_horizontal_line_right(char *string, WINDOW *window_line);
void window_horizontal_line_left(char *string, WINDOW *window_line);
void window_vertical_line(char *string, WINDOW *window_line);
void window_print_line(char **string, WINDOW **window_line, int attr, int line, int size);
void print_result(int num);
//

//string
char *get_random_str(int len);
char get_rand_char();
//

//delete personage
char *atomizating_personage(char *str);
char *deleting_personage(char *str);

#endif
