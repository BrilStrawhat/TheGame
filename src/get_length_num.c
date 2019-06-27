int get_length_num(int num) {
    int len = 1;

    while(num > 9) {
	    len++;
	    num /= 10;
    }
    return len;
}
