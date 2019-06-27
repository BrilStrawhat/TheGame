all: get_source get_headers install clean
get_source:
	cp src/*.c .
get_headers:
	cp inc/*.h .
install:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses -o endgame *.c
clean:
	rm -rf *.c
	rm -rf *.h
	rm -rf *.o
uninstall:
	rm -rf race05
reinstall: uninstall all
