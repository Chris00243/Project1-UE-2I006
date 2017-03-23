#include <stdlib.h>
#include <stdio.h>
#include "Chaine.h"
#include <string.h>

int main(int argc, char* argv[])
{
	
	if(argc!=3)
	{
	fprintf(stderr,"\nPb arguments! \n\n");
	exit(1);
	}

	char *nomfic_1, *nomfic_2; 

	nomfic_1 = strdup(argv[1]); // le fichier contenant les données à lire
	nomfic_2 = strdup(argv[2]); // le fichier dans lequel on sauvegardera toutes les données lues du fichier ci-dessus
	
	FILE *f, *g;

	f = fopen(nomfic_1,"r"); // ouverture en lecture du premier fichier

	Chaines* C;	
	
	

	if(f!=NULL){
		C=lectureChaine(f);
		fclose(f);
	}

	afficher_C(C); // Affiche la stucture Chaines *C

	g = fopen(nomfic_2,"w"); // ouverture du second fichier en écriture avec tronquage c à d on vide le contenu de ce fichier avant d'écrire dedans
	
	

	if(g!=NULL){
		
		ecrireChaineTxt(C, g);
		fclose(g);
	
	}


	afficheChaineSVG(C, "graph");
	
	
	return 0;

}
