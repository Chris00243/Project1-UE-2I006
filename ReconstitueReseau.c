#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Exo5.h"
//#include "Exo4.h"
#include "Reseau.h"

// verifie si on passe en argument un fichier .cha
int verifieExtension(char* s) 
{
   char *extension;
   extension = strrchr(s,'.'); 
 
   if ((extension[0] == '.') && (extension[1] == 'c') && (extension[2] == 'h') && (extension[3] == 'a'))
   {
      return 0;
   }
   return 1;
}


int main(int argc, char *argv[])
{
	if(argc!=2){
		fprintf(stderr,"Nb d'arguments incorrect");
		exit(1);
	}

	if (verifieExtension(argv[1]) != 0{
		fprintf(stderr,"'%s' : format de fichier non correct,'.cha' uniquement\n",argv[1]);
		exit(2);
	}
	
	if(atoi(argv[2])<1 || atoi(argv[2])>3){
		fprintf(stderr,"Le choix de la méthode est soit 1,2 ou 3\n",);
		exit(3);
	}
  
  
  
  printf("##Reconstition du Reseau##\n\n");
  
  FILE* f=fopen(argv[1],"r");
  Chaines* C=lectureChaine(f);
  
	switch(atoi(argv[2])){
		case 1: printf("Par liste chainee\n\n");
            Reseau* R=reconstitueReseauListe(C);
            afficheReseauSVG(R,"V1");
			break;
		case 2: printf("Par Hachage\n\n");
            Reseau* R=recreeReseauHachage(C);
            afficheReseauSVG(R,"V2");
			break;
		case 3: printf("Par arbre quaternaire\n\n");
            Reseau* R=recreeReseauArbre(C);
            afficheReseauSVG(R,"V3");
			break;
	}
  
  
  return 0;
  
  }
