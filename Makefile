all: Projet


entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc -c -lm -o entree_sortie.o entree_sortie.c

SVGwriter.o : SVGwriter.h SVGwriter.c
	gcc -c -lm -o SVGwriter.o SVGwriter.c

ChainMain.o: ChainMain.c Chaine.h Reseau.h
	gcc -c -lm -o ChainMain.o ChainMain.c

Chaine.o: Chaine.c Chaine.h
	gcc -c -lm -o Chaine.o Chaine.c

Reseau.o : Reseau.h Reseau.c
	gcc -c -lm -o Reseau.o Reseau.c

Projet: ChainMain.o Chaine.o entree_sortie.o SVGwriter.o 
	gcc -lm -o Projet ChainMain.o Chaine.o entree_sortie.o SVGwriter.o 

clean:
	rm -f *.o Projet
