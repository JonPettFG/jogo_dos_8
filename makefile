
Jogo_dos_8: main.o 
	gcc main.o interface.o grafo.o -o Jogo_dos_8

main.o: main.c
	gcc -c main.c
	
movimentos.o: movimentos.c movimentos.h
	gcc -c movimentos.c
	
estado.o: estado.c estado.h
	gcc -c iestado.c

grafo.o: grafo.c grafo.h
	gcc -c grafo.c movimentos.o estado.h

interface.o: interface.c interface.h
	gcc -c interface.c
