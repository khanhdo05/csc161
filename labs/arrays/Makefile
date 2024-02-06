CC := clang
CFLAGS :=

all: max-min reverse reverse-variable face

clean:
	rm -f max-min reverse reverse-variable face

max-min: max-min.c
	$(CC) $(CFLAGS) -o max-min max-min.c

reverse: reverse.c
	$(CC) $(CFLAGS) -o reverse reverse.c

reverse-variable: reverse-variable.c
	$(CC) $(CFLAGS) -o reverse-variable reverse-variable.c

face: face.c
	$(CC) $(CFLAGS) -o face face.c

.PHONY: all clean
