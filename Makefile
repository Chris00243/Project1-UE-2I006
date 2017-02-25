all: projet


entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc -c -o entree_sortie.o entree_sortie.c

ChainMain.o: ChainMain.c Chaine.h
	gcc -c -o ChainMain.o ChainMain.c

Chaine.o: Chaine.c Chaine.h
	gcc -c -o Chaine.o Chaine.c




projet: ChainMain.o Chaine.o entree_sortie.o
	gcc -o projet ChainMain.o Chaine.o entree_sortie.o

clean:
	rm -f *.o projet
