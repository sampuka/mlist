test: test.c mlist.h mlist.c
	gcc -g -o test test.c mlist.c -Wall -Wextra -std=c99

