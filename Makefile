CC=gcc 
CFLAGS=-Wall

all: slash
slash: systeminfo.o slash.o
logos.o: systeminfo.c systeminfo.h definitions.h slash.c 

clean:
	rm -f slash slash.o
run: slash
	./slash