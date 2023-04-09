OBJS	= main.o suma.o czesc_wspolna.o roznica.o roznica_symetryczna.o rowne.o zawiera.o
SOURCE	= main.c suma.c czesc_wspolna.c roznica.c roznica_symetryczna.c rowne.c zawiera.c
HEADER	= 
OUT	= app
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

suma.o: suma.c
	$(CC) $(FLAGS) suma.c 

czesc_wspolna.o: czesc_wspolna.c
	$(CC) $(FLAGS) czesc_wspolna.c 

roznica.o: roznica.c
	$(CC) $(FLAGS) roznica.c 

roznica_symetryczna.o: roznica_symetryczna.c
	$(CC) $(FLAGS) roznica_symetryczna.c 

rowne.o: rowne.c
	$(CC) $(FLAGS) rowne.c 

zawiera.o: zawiera.c
	$(CC) $(FLAGS) zawiera.c 


clean:
	rm -f $(OBJS) $(OUT)