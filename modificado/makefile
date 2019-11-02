# makefile
CFLAGS = -Wall -pedantic
CC = g++

# all: compila todo el programa y elimina los archivos objeto
all: make_tp1 clean

#make_tp1: compila todo el programa a partir de los archivos objeto de todos los archivos .c
make_tp1: main.o calcular_error.o cmdline.o complejo.o dft.o leer_cmdline.o
	$(CC) $(CFLAGS) -o tp1 main.o calcular_error.o cmdline.o complejo.o dft.o leer_cmdline.o

main_casos_prueba.o: main.cpp complejo.h array.h dft.h leer_cmdline.h calcular_error.h
	$(CC) $(CFLAGS) -o main.o -c main.cpp

calcular_error.o: calcular_error.cpp array.h calcular_error.h complejo.h
	$(CC) $(CFLAGS) -o calcular_error.o -c calcular_error.cpp

cmdline.o: cmdline.cc cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o -c cmdline.cc

complejo.o: complejo.cc complejo.h
	$(CC) $(CFLAGS) -o complejo.o -c complejo.cc

dft.o: dft.cc dft.h
	$(CC) $(CFLAGS) -o dft.o -c dft.cc

leer_cmdline.o: leer_cmdline.cpp cmdline.h
	$(CC) $(CFLAGS) -o leer_cmdline.o -c leer_cmdline.cpp

#clean: elimina los archivos objeto compilados
clean:
	rm *.o
