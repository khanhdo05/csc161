CC := clang
CFLAGS :=

all: creditcard

clean:
	rm -f creditcard

creditcard: creditcard.c
	$(CC) $(CFLAGS) -o creditcard creditcard.c -lm

.PHONY: all clean