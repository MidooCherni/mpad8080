ARGS = -Wall -Wextra -pedantic -std=c99
CC = gcc

mpad.exe: mpad.c
	$(CC) mpad.c -o mpad.exe $(ARGS)