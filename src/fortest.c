#include <ncurses.h>
#include <stdio.h>
#include "game.h"

void print_rabbit(int head, int body, int legs, WINDOW *pers_win, int costil);
void window_part_level(WINDOW *level, char *fname);
void move_rabbit_to_choise(WINDOW *rabbit, WINDOW *wmain,int *y, int *x);
void move_rabbit_to_portal(WINDOW *rabbit, WINDOW *wmain,int *y, int *x, int path);
void rotate_rabbits(WINDOW **rabbits);
void rabbit_genr(int color, WINDOW *w_rabbits, char *rabbit[3]);
void deinit();

int main() {
	initscr();
    char *rabbit_head[3];                     
 	rabbit_head[0] = "   ___  ";
 	rabbit_head[1] = "  /. .\\";
 	rabbit_head[2] = " (  -  )";
	char *rabbit_body[3];
 	rabbit_body[0] = "/\"/---\\\"\\";
 	rabbit_body[1] = "'|     |' ";
 	rabbit_body[2] = " \\\\___//";
	char *rabbit_legs[3];
 	rabbit_legs[0] = "       ";
 	rabbit_legs[1] = "  ('Y')";
 	rabbit_legs[2] = "       ";
    int cors_y[] = {4, 4, 4, 4};
    int cors_x[] = {84, 84, 84, 84};
    int indexs[] = {0, 0, 0, 0};
    int pers_num = 0;
    int reverse_index = 0;
    bool move_left = false;
    bool move_right = false;
    bool is_first = true;
    bool is_second = false;
    bool swap_flag = false;
    init_pair(6, 1, COLOR_BLACK);
    init_pair(7, 2, COLOR_BLACK);
    init_pair(8, 3, COLOR_BLACK);
    int ch;
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);
    int index_render = 0;
    srand(time(NULL));
    if (menu_window() == 1) {
        deinit();
        exit(0);
    }
	start_color();
    curs_set(0);
	WINDOW *rabbit[4];
	WINDOW *full_level = newwin(56, 170, 0, 0);
	for (int i = 0; i < 4; i++) {
		rabbit[i] = subwin(full_level, 8, 11, 5, 84);
	}
	refresh();
	window_part_level(full_level, "concept.txt");
	for (int i = 0; i < 4; i++) {
		print_rabbit(2,3,1,rabbit[i],0);
	}
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    

    WINDOW *lines_first_horizontal[6];
    WINDOW *lines_second_horizontal[10];
    WINDOW *lines_first_vertical[43];
    WINDOW *lines_second_vertical[10];
    WINDOW *lines_third_vertical[1];
    WINDOW *lines_fourth_vertical[6];
    WINDOW *lines_fifth_vertical[1];
    WINDOW *lines_sixth_vertical[12];
    WINDOW *lines_seventh_vertical[1];
    WINDOW *lines_eighth_vertical[52];
    WINDOW *lines_nineth_vertical[5];
    WINDOW *lines_10_vertical[1];
    WINDOW *lines_11_vertical[15];
    WINDOW *lines_12_vertical[1];
    WINDOW *lines_13_vertical[5];
    WINDOW *lines_14_vertical[1];
    WINDOW *lines_15_vertical[10];
    WINDOW *lines_16_vertical[33];
    WINDOW *lines_17_vertical[1];
    WINDOW *lines_third_horizontal[6];
    WINDOW *lines_fourth_horizontal[10];
    WINDOW *lines_18_vertical[44];
    WINDOW *lines_19_vertical[7];
    char *strs_first_horizontal[6];
    char *strs_second_horizontal[10];
    char *strs_first_vertical[43];
    char *strs_second_vertical[10];
    char *strs_third_vertical[1];
    char *strs_fourth_vertical[6];
    char *strs_fifth_vertical[1];
    char *strs_sixth_vertical[12];
    char *strs_seventh_vertical[1];
    char *strs_eighth_vertical[52];
    char *strs_ninth_vertical[5];
    char *strs_10_vertical[1];
    char *strs_11_vertical[15];
    char *strs_12_vertical[1];
    char *strs_13_vertical[5];
    char *strs_14_vertical[1];
    char *strs_15_vertical[10];
    char *strs_16_vertical[33];
    char *strs_17_vertical[1];
    char *strs_third_horizontal[6];
    char *strs_fourth_horizontal[10];
    char *strs_18_vertical[44];
    char *strs_19_vertical[7];
    for (int i = 0; i < 7; i++) {
        lines_19_vertical[i] = newwin(6 - i, 1, 50+ i, 125 - i);
        strs_19_vertical[i] = get_random_str(6 - i);
    }
    for (int i = 0; i < 44; i++) {
        lines_18_vertical[i] = newwin(6, 1, 50, 126 + i);
        strs_18_vertical[i] = get_random_str(6);
    }
    for (int i = 0; i < 10; i++) {
        lines_fourth_horizontal[i] = newwin(1, 34 + i, 39 + i, 136 - i);
        strs_fourth_horizontal[i] = get_random_str(34 + i);
    }
    for (int i = 0; i < 6; i++) {
        lines_third_horizontal[i] = newwin(1, 34, 32 + i, 136);
        strs_third_horizontal[i] = get_random_str(34);
    }
    for (int i = 0; i < 1; i++) {
        lines_17_vertical[i] = newwin(27, 1, 4, 169);
        strs_17_vertical[i] = get_random_str(27);
    }
    for (int i = 0; i < 33; i++) {
        lines_16_vertical[i] = newwin(26, 1, 5, 136 + i);
        strs_16_vertical[i] = get_random_str(26);
    }
    for (int i = 0; i < 10; i++) {
        lines_15_vertical[i] = newwin(34 - i, 1, 5, 125 + i);
        strs_15_vertical[i] = get_random_str(35 - i);
    }
    for (int i = 0; i < 1; i++) {
        lines_14_vertical[i] = newwin(36, 1, 5, 124);
        strs_14_vertical[i] = get_random_str(36);
    }
    for (int i = 0; i < 5; i++) {
        lines_13_vertical[i] = newwin(41, 1, 0, 118 + i);
        strs_13_vertical[i] = get_random_str(41);
    }
    for (int i = 0; i < 1; i++) {
        lines_12_vertical[i] = newwin(38, 1, 3, 117 + i);
        strs_12_vertical[i] = get_random_str(38);
    }
    for (int i = 0; i < 15; i++) {
        lines_11_vertical[i] = newwin(37, 1, 4, 102 + i);
        strs_11_vertical[i] = get_random_str(37);
    }
    for (int i = 0; i < 1; i++) {
        lines_10_vertical[i] = newwin(36, 1, 4, 101 + i);
        strs_10_vertical[i] = get_random_str(36);
    }
    for (int i = 0; i < 5; i++) {
        lines_nineth_vertical[i] = newwin(5 - i, 1, 51 + i, 52 + i);
        strs_ninth_vertical[i] = get_random_str(5 - i);
    }
    for (int i = 0; i < 6; i++) {
        lines_first_horizontal[i] = newwin(1, 41, i + 32, 0);
        strs_first_horizontal[i] = get_random_str(41);
    }
    for (int i = 0; i < 10; i++) {
        lines_second_horizontal[i] = newwin(1, 41 + i, i + 39, 0);
        strs_second_horizontal[i] = get_random_str(41 + i);
    }
    for (int i = 0; i < 43; i++) {
        lines_first_vertical[i] = newwin(24, 1, 7, i);
        strs_first_vertical[i] = get_random_str(24);
    }
    for (int i = 0; i < 10; i++) {
        lines_second_vertical[i] = newwin(25 + i, 1, 7, i + 43);
        strs_second_vertical[i] = get_random_str(25 + i);
    }
    for (int i = 0; i < 1; i++) {
        lines_third_vertical[i] = newwin(35, 1, 6, 54 + i);
        strs_third_vertical[i] = get_random_str(35);
    }
    for (int i = 0; i < 6; i++) {
        lines_fourth_vertical[i] = newwin(41, 1, 0, 55 + i);
        strs_fourth_vertical[i] = get_random_str(41);
    }
    for (int i = 0; i < 1; i++) {
        lines_fifth_vertical[i] = newwin(38, 1, 3, 61 + i);
        strs_fifth_vertical[i] = get_random_str(38);
    }
    for (int i = 0; i < 12; i++) {
        lines_sixth_vertical[i] = newwin(37, 1, 4, 62 + i);
        strs_sixth_vertical[i] = get_random_str(37);
    }
    for (int i = 0; i < 1; i++) {
        lines_seventh_vertical[i] = newwin(36, 1, 4, 75 + i);
        strs_seventh_vertical[i] = get_random_str(36);
    }
    for (int i = 0; i < 52; i++) {
        lines_eighth_vertical[i] = newwin(6, 1, 50, i);
        strs_eighth_vertical[i] = get_random_str(6);
    }
    int counter = get_counter();
    int timer = get_timer();
	bool wrong_choice = false;
    pers *invalid_pers = generate_personage();
    WINDOW *counter_win = newwin(4, 18, 1, 32);
    WINDOW *timer_win = newwin(2, 53, 1, 63);
    WINDOW *win_1 = subwin(full_level, 3, 13, 1, 125);
	WINDOW *win_2 = subwin(full_level, 3, 13, 1, 140);
    WINDOW *win_3 = subwin(full_level, 3, 13, 1, 155);
    counter_window(counter, counter_win);
    pers *random_pers;
    while (true) {
        for (int i = 0; i < 8 && !swap_flag; i++) {
            for (int j = 0; j < 70; j++) {
                mvwaddch(full_level, i + 42, j + 53, ' ');
            }
        }
        if (is_first) {
            for (int i = 4; i > 0; i--) {
                if (indexs[reverse_index] < i * 7 && pers_num == reverse_index) {
                    print_rabbit(random_pers->head, random_pers->body, random_pers->legs, rabbit[reverse_index], 0);
                    move_rabbit_to_choise(rabbit[reverse_index], full_level, &cors_y[reverse_index], &cors_x[reverse_index]);
                    indexs[reverse_index]++;
                    if (indexs[reverse_index] == i * 7) pers_num++;
                }
                if (pers_num == 4) {
                    indexs[0] = 0;
                    indexs[1] = 0;
                    indexs[2] = 0;
                    indexs[3] = 0;
                    is_first = false;
                }
                reverse_index++;
            }
            reverse_index = 0;
        }
        else if (is_second) {
            for (int i = 4; i > 0; i--) {
                 if (indexs[reverse_index] < 7 && pers_num == reverse_index) {
                     print_rabbit(random_pers->head, random_pers->body, random_pers->legs, rabbit[reverse_index], 0);
                     move_rabbit_to_choise(rabbit[reverse_index], full_level, &cors_y[reverse_index], &cors_x[reverse_index]);
                     indexs[reverse_index]++;
                     if (indexs[reverse_index] == 7) pers_num++;
                 }
                 if (pers_num == 4) {
                     indexs[0] = 0;
                     indexs[1] = 0;
                     indexs[2] = 0;
                     indexs[3] = 0;
                 }
                 reverse_index++;
             }
            reverse_index = 0;
        }
        if (!indexs[0])
            ch = getch();
        else
            ch = 0;
        flushinp();
        switch (ch) {
            case 27:
                clear();
                if (menu_window() == 1) {
                    deinit();
                    exit(0);
                }
                break;
            case KEY_LEFT:
                move_right = false;
                move_left = true;
                swap_flag = true;
                is_second = false;
                break;
            case KEY_RIGHT:
                move_left = false;
                move_right = true;
                swap_flag = true;
                is_second = false;
                break;
        }
        if (move_right && !move_left) {
            if (indexs[0] < 10) {
                move_rabbit_to_choise(rabbit[0], full_level, &cors_y[0], &cors_x[0]);
                indexs[0]++;
            }
            if (indexs[0] >= 10) {
                if (indexs[0] < 39)
                    move_rabbit_to_portal(rabbit[0], full_level, &cors_y[0], &cors_x[0], 0);
                indexs[0]++;
            }
        }
        else if (move_left && !move_right) {
            if (indexs[0] < 10) {
                move_rabbit_to_choise(rabbit[0], full_level, &cors_y[0], &cors_x[0]);
                indexs[0]++;
            }
            if (indexs[0] >= 10) {
                if (indexs[0] < 39)
                    move_rabbit_to_portal(rabbit[0], full_level, &cors_y[0], &cors_x[0], 1);
                indexs[0]++;
            }
        }
        if (indexs[0] >= 39 && swap_flag) {
            for (int i = 0; i < 3; i++) {
                rabbit[i] = rabbit[i + 1];
                cors_x[i] = cors_x[i + 1];
                cors_y[i] = cors_y[i + 1];
            }
            if (move_left && !is_valid_personage(random_pers, invalid_pers)) {
				add_timer(&timer);
                counter++;
            }
			else if (move_left && is_valid_personage(random_pers, invalid_pers)) {
				wrong_choice = true;
			}
            if (move_right && is_valid_personage(random_pers, invalid_pers)) {
				add_timer(&timer);
                counter++;
            }
			else if (move_right && !is_valid_personage(random_pers, invalid_pers)) {
				wrong_choice = true;
			}
        	random_pers = generate_personage_chance(invalid_pers);
            indexs[0] = 0;
            indexs[1] = 0;
            indexs[2] = 0;
            indexs[3] = 0;
            cors_x[3] = 84;
            cors_y[3] = 4;
            pers_num = 0;
            is_second = true;
            swap_flag = false;
            move_right = false;
            move_left = false;
        }
        if (index_render == 20) {
        window_print_line(strs_19_vertical, lines_19_vertical, 5, 0, 6);
        window_print_line(strs_18_vertical, lines_18_vertical, 5, 0, 44);
        window_print_line(strs_fourth_horizontal, lines_fourth_horizontal, 5, 2, 10);
        window_print_line(strs_third_horizontal, lines_third_horizontal, 5, 2, 6);
        window_print_line(strs_17_vertical, lines_17_vertical, 5, 0, 1);
        window_print_line(strs_16_vertical, lines_16_vertical, 5, 0, 33);
        window_print_line(strs_15_vertical, lines_15_vertical, 5, 0, 10);
        window_print_line(strs_14_vertical, lines_14_vertical, 5, 0, 1);
        window_print_line(strs_13_vertical, lines_13_vertical, 5, 0, 5);
        window_print_line(strs_12_vertical, lines_12_vertical, 5, 0, 1);
        window_print_line(strs_11_vertical, lines_11_vertical, 5, 0, 15);
        window_print_line(strs_10_vertical, lines_10_vertical, 5, 0, 1);
        window_print_line(strs_ninth_vertical, lines_nineth_vertical, 4, 0, 5);
        window_print_line(strs_first_horizontal, lines_first_horizontal, 4, 1, 6);
        window_print_line(strs_second_horizontal, lines_second_horizontal, 4, 1, 10);
        window_print_line(strs_first_vertical, lines_first_vertical, 4, 0, 43);
        window_print_line(strs_second_vertical, lines_second_vertical, 4, 0, 10);
        window_print_line(strs_third_vertical, lines_third_vertical, 4, 0, 1);
        window_print_line(strs_fourth_vertical, lines_fourth_vertical, 4, 0, 6);
        window_print_line(strs_fifth_vertical, lines_fifth_vertical, 4, 0, 1);
        window_print_line(strs_sixth_vertical, lines_sixth_vertical, 4, 0, 12);
        window_print_line(strs_seventh_vertical, lines_seventh_vertical, 4, 0, 1);
        window_print_line(strs_eighth_vertical, lines_eighth_vertical, 4, 0, 52);
        index_render = 0;
        }
        index_render++;
		move_timer(&timer, counter);
        counter_window(counter, counter_win);
        window_timer(timer, timer_win);
        if (!(counter % 10)) {
            rabbit_genr(invalid_pers->head + 9, win_1, rabbit_head);
	        rabbit_genr(invalid_pers->body + 9, win_2, rabbit_body);
	        rabbit_genr(invalid_pers->legs + 9, win_3, rabbit_legs);
        }
		if (check_timer(timer) || wrong_choice) {
			clear();
			print_result(counter);
			sleep(2);
			clear();
			if (menu_window() == 1) {
				break;
			}
			for (int i = 0; i < 4; i++) {
				rabbit[i] = subwin(full_level, 8, 11, 5, 84);
			}
			refresh();
			window_part_level(full_level, "concept.txt");
			for (int i = 0; i < 4; i++) {
				print_rabbit(2,3,1,rabbit[i],0);
			}
			counter = get_counter();
			timer = get_timer();
			invalid_pers = generate_personage();
			wrong_choice = false;
			window_part_level(full_level, "concept.txt");
		}
        wrefresh(timer_win);
        wrefresh(counter_win);
        wrefresh(full_level);
		
        usleep(1700);
    }
    //
	endwin();
	return 0;
}

void deinit() {
    endwin();
}
