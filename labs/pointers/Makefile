CC := clang
CFLAGS := -g

all: checkA divide exchange max-array max perim-area-1 perim-area-2 time

clean:
	rm -f checkA divide exchange max-array max perim-area-1 perim-area-2 time

checkA: pcheckA.c
	$(CC) $(CFLAGS) -o checkA checkA.c

divide: divide.c
	$(CC) $(CFLAGS) -o divide divide.c

exchange: exchange.c
	$(CC) $(CFLAGS) -o exchange exchange.c 

max-array: max-array.c
	$(CC) $(CFLAGS) -o max-array max-array.c 

max: max.c
	$(CC) $(CFLAGS) -o max max.c 

perim-area-1: perim-area-1.c
	$(CC) $(CFLAGS) -o perim-area-1 perim-area-1.c 

perim-area-2: exchange.c
	$(CC) $(CFLAGS) -o perim-area-2 perim-area-2.c 

.PHONY: all clean