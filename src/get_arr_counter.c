#include "game.h"

int get_length_num(int num);

int *get_arr_counter(int counter)
{
    int len = get_length_num(counter);
    
    int *arr_int = (int *) malloc(sizeof(int) * 3);

	arr_int[0] = 0;
    arr_int[1] = 0;
    arr_int[2] = 0;

    if (arr_int == NULL)
		return 0;

	if (len == 1) {
		arr_int[2] = counter;
	}
	else if (len == 2) {
			arr_int[2] = counter % 10;
			counter /= 10;
			arr_int[1] = counter;
	}
	else if (len == 3) {
		arr_int[2] = counter % 10;
		counter /= 10;
    	arr_int[1] = counter % 10;
		counter /=10;
		arr_int[0] = counter;
	}

    return arr_int;
}
