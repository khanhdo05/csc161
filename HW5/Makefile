CC := clang
CFLAGS := 

all: caesarcipher

clean:
	rm -f caesarcipher

bigrams: caesarcipher.c
	$(CC) $(CFLAGS) -o caesarcipher caesarcipher.c

.PHONY: all clean
