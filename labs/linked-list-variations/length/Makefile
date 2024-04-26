CC := clang
CFLAGS := -g
CFLAGS_ASAN := $(CFLAGS) -fsanitize=address

all: list-practice list-practice-asan

clean:
	rm -rf list-practice list-practice-asan list-practice.dSYM list-practice-asan.dSYM

list-practice: main.c string_list.h string_list.c
	$(CC) $(CFLAGS) -o list-practice main.c string_list.c

list-practice-asan: main.c string_list.h string_list.c
	$(CC) $(CFLAGS_ASAN) -o list-practice-asan main.c string_list.c

.PHONY: all clean
