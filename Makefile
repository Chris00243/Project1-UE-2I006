all: Projet

entree_sortie.o : entree_sortie.c entree_sortie.h
	gcc -c -lm -o entree_sortie.o entree_sortie.c

SVGwriter.o : SVGwriter.h SVGwriter.c
	gcc -c -lm -o SVGwriter.o SVGwriter.c

Chaine.o: Chaine.c Chaine.h
	gcc -c -lm -o Chaine.o Chaine.c
  

  
Reseau.o : Reseau.c Reseau.h
	gcc -c -lm -o Reseau.o Reseau.c

ReconstitueReseau.o: ReconstitueReseau.c Reseau.h
	gcc -c -lm -o ReconstitueReseau.o ReconstitueReseau.c

Projet: ReconstitueReseau.o Reseau.o Chaine.o entree_sortie.o SVGwriter.o 
	gcc -lm -o Projet ReconstitueReseau.o Reseau.o Chaine.o entree_sortie.o SVGwriter.o 

clean:
	rm -f *.o Projet
