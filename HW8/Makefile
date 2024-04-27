CC := clang
CFLAGS := -g
CFLAGS_ASAN := $(CFLAGS) -fsanitize=address

all: paranoia paranoia-asan

clean:
	rm -rf paranoia paranoia-asan paranoia.dSYM paranoia-asan.dSYM

list-practice: paranoia.c player_list.h player_list.c
	$(CC) $(CFLAGS) -o paranoia paranoia.c player_list.c

list-practice-asan: paranoia.c player_list.h player_list.c
	$(CC) $(CFLAGS_ASAN) -o paranoia-asan paranoia.c player_list.c

.PHONY: all clean
