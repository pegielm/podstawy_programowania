OBJS	= main.o animal.o map_direction.o move_direction.o rectangular_map.o vector.o
TEST    = test.o animal.o map_direction.o move_direction.o rectangular_map.o vector.o
SOURCE	= main.c animal.c map_direction.c move_direction.c rectangular_map.c vector.c
HEADER	= map_direction.h move_direction.h rectangular_map.h vector.h
OUT	= a.exe
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

test.o: test.c
	$(CC) $(FLAGS) test.c

animal.o: animal.c
	$(CC) $(FLAGS) animal.c 

map_direction.o: map_direction.c
	$(CC) $(FLAGS) map_direction.c 

move_direction.o: move_direction.c
	$(CC) $(FLAGS) move_direction.c 

rectangular_map.o: rectangular_map.c
	$(CC) $(FLAGS) rectangular_map.c 

vector.o: vector.c
	$(CC) $(FLAGS) vector.c 

test: $(TEST)
	$(CC) -g $(TEST) -o test $(LFLAGS)

clean:
	-del -fR $(OBJS) $(OUT).exe test.exe test.o