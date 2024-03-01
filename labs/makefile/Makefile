objects = farm.o chicken.o cow.o sheep.o util.o
CC = clang
CFLAGS = -g

farm: $(objects)
	$(CC) $(CFLAGS) -o farm $(objects)
farm.o: farm.c 
	cc -c farm.c
chicken.o: chicken.c chicken.h util.h
	cc -c chicken.c
cow.o: cow.c cow.h util.h
	cc -c cow.c
sheep.o: sheep.c sheep.h util.h
	cc -c sheep.c
util.o: util.c util.h
	cc -c util.c
clean:
	rm farm $(objects)

# all: farm

# farm: farm.c chicken.h chicken.c cow.h cow.c sheep.h sheep.c util.h util.c 
# 	$(CC) $(CFLAGS) -c -o farm farm.c chicken.c cow.c sheep.c util.c 

# .PHONY: clean
# clean: 
# 	rm -f farm