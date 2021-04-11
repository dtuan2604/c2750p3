GCC = gcc
CFLAGS = -g -Wall -Wshadow

findc: findc.o
	$(GCC) $(CFLAGS) findc.o -o findc
findc.o: findc.c findc.h
	$(GCC) $(CFLAGS) -c findc.c findc.h
