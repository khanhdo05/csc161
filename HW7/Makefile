CC := clang

all: grocery-list

clean:
	rm -f caesarcipher

grocery-list: grocery-list.c
	$(CC) -g -fsanitize=address -o grocery-list grocery-list.c

.PHONY: all clean