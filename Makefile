GCC = gcc
CFLAGS = -g -Wall -Wshadow

findC: findc.o
	$(GCC) $(CFLAGS) findc.o -o findC
findc.o: findc.c findc.h
	$(GCC) $(CFLAGS) -c findc.c findc.h
