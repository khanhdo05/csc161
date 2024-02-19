CC := clang
CFLAGS := -g

all: partA partB

clean:
	rm -f partA partB

partA: partA.c
	$(CC) $(CFLAGS) -o partA partA.c

partB: partB.c
	$(CC) $(CFLAGS) -o partB partB.c

.PHONY: all clean
