CC=gcc 
CFLAGS=-Wall

all: slash
slash: systeminfo.o slash.o logos.o
logos.o: systeminfo.c systeminfo.h logos.c logos.h definitions.h slash.c

clean:
	rm -f slash slash.o logos.o systeminfo.o
run: slash
	./slash