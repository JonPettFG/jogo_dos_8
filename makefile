
Jogo_dos_8: main.o listas.o
	gcc main.o listas.o interface.o grafos.o interface.o -o Jogo_dos_8

main.o: main.c
	gcc -c main.c

listas.o: listas.c listas.h
	gcc -c listas.c

grafos.o: grafos.c grafos.h
	gcc -c grafos.c listas.o

interface.o: interface.c interface.h
	gcc -c interface.c
