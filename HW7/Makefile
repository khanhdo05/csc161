CC := clang

all: grocery-list

grocery-list: grocery-list.c
	$(CC) -g -fsanitize=address -o grocery-list grocery-list.c

clean:
	rm -f grocery-list
	
.PHONY: all clean