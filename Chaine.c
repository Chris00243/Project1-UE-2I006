#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Chaine.h"


#define TAILLE_MAX 500
#define TAILLE_MIN 50

#define IMAGE_X 300
#define IMAGE_Y 300


/*************************  FONCTIONS STRUCTURE CellPoint ***************************************************************/





					
/* initialise et crée une structure CellPoint */

CellPoint* initialiser_CP(double x, double y)
{
	CellPoint* CP=(CellPoint*)malloc(sizeof(CellPoint));
	
	if(CP==NULL) return NULL;	

	CP->x=x;
	CP->y=y;
	CP->suiv=NULL;

	return CP;
}

/* Affiche une structure CellPoint */

void afficher_CP( CellPoint *CP)
{	
	while(CP){

		printf("CellPoint (x = %.2f | y = %.2f) ==> ",CP->x,CP->y);
		CP = CP->suiv;
	
	}
	
	printf(" NULL" );
}







/*************************  FONCTIONS STRUCTURE CellChaines ***************************************************************/





/* initialise une structure CellChaine */

CellChaine* initialiser_CC(int num)
{
	CellChaine* CC=malloc(sizeof(CellChaine));	
	
	CC->numero=num;
	CC->points=NULL;
	CC->suiv=NULL;

	return CC;
}

/* affiche une structure CellChaine */

void afficher_CC( CellChaine *CC)
{
	

	while(CC){
		
		printf("[ CellChaine numéro : %d NbPoints : %d  ", CC->numero, comptePoints(CC) );
		afficher_CP(CC->points);
		printf(" ] ====> \n");	
		
		CC = CC->suiv;
	}

	printf(" NULL" );
}






/*************************  FONCTIONS STRUCTURE Chaines ***************************************************************/



			


/* initialise une structure Chaines */

Chaines* initialiser_C(int gamma, int nbChaines)
{
	Chaines *C = (Chaines *) malloc(sizeof(Chaines));
	if(C==NULL)return NULL;
	
	C->gamma = gamma;
	C->nbChaines = nbChaines;
	C->chaines = NULL;

	return C;
}

/* affiche une structure Chaines */

void afficher_C( Chaines *C)
{	
	printf("\n\n Chaines : {  ");
	if(C!=NULL){

		printf("\n\n\tgamma : %d  nbChaines : %d nbPointsTotal : %d\n\n", C->gamma, C->nbChaines, comptePointsTotal(C) );
		afficher_CC(C->chaines);
	}
	
	printf("\n\n\t } =====> FIN\n"); 

}


/*************************  FONCTIONS STRUCTURE CellPoint et CellChaine ***************************************************************/


			

/* Insère CellPoint dans CellChaine */

CellChaine* inserer_CP_CC(CellChaine *CC, CellPoint *CP)
{
	if( CC!=NULL){
		
		CC->points = inserer_CP_lCP( CC->points, CP);
		return CC;
		
	}
	
	return NULL;


}

/* Insère CellPoint dans la liste Points de CellChaine. FONCTION UTILISEE DANS inserer_CP_CC.  On opte pour l'insertion en queue pour respecter la formation de CellChaine */

CellPoint* inserer_CP_lCP( CellPoint* lCP, CellPoint *CP)
{
	if(lCP==NULL && CP==NULL) return NULL;
	if(lCP==NULL) return CP;

	CellPoint* SAVE_lCP = lCP;

	CellPoint* prec = lCP;
	lCP = lCP->suiv;	

	while(lCP){

		prec = lCP;
		lCP = lCP->suiv;

	}
	
	if(prec!=NULL){

		prec->suiv = CP;
	}
	return SAVE_lCP;
} 






/*************************  FONCTIONS STRUCTURE CellChaine et Chaines ***************************************************************/



/* Insère CellChaine dans Chaines */

Chaines* inserer_CC_C(Chaines *C, CellChaine *CC)
{
	if( C!=NULL){
		
		C->chaines = inserer_CC_lC( C->chaines, CC);
		return C;
		
	}
	
	return NULL;
}

/* Insère CellChaine dans la liste chaines de Chaines. FONCTION UTILISEE DANS inserer_CC_C. Insertion en queue*/

CellChaine* inserer_CC_lC( CellChaine* lC, CellChaine *CC)
{
	if(lC==NULL && CC==NULL) return NULL;
	if(lC==NULL) return CC;

	CellChaine* SAVE_lC = lC;

	CellChaine* prec = lC;
	lC = lC->suiv;	

	while(lC){

		prec = lC;
		lC = lC->suiv;

	}
	
	if(prec!=NULL){

		prec->suiv = CC;
	}
	
	return SAVE_lC;
	
} 











/*************************  FONCTIONS STRUCTURES ALLL ***************************************************************/

Chaines* lectureChaine(FILE *f)
{ 
	char buff[TAILLE_MAX];	
	GetChaine(f,TAILLE_MAX, buff);
	int nbChaines=GetEntier(f);
	
	GetChaine(f,TAILLE_MAX, buff);	
	int gamma=GetEntier(f);
	//GetChaine(f,TAILLE_MAX, buff);	
	//fscanf(f,"%d", &gamma);

	
	SkipLine(f);

	

	Chaines *C = initialiser_C(gamma,nbChaines);	

	int numero;
	int nbPoints;
	double xP, yP;
	
	CellChaine* CC;
	CellPoint* CP;	
	
	int cpt;
	int i;
	
	
	for(cpt=0; cpt<nbChaines; cpt++){
	
		numero = GetEntier(f); 
		nbPoints = GetEntier(f); 

		CC=initialiser_CC(numero);
		
		for(i=0; i<nbPoints; i++)
		{
			
			xP = GetReel(f);
			yP = GetReel(f);
			
			
			CP=initialiser_CP(xP, yP);
			CC=inserer_CP_CC(CC, CP);
			
		}

	C=inserer_CC_C(C,CC);

	}

	return C;
}

void ecrireChaineTxt(Chaines *C, FILE *f)
{
	fprintf(f,"NbChain: %d\n", C->nbChaines);
	fprintf(f,"Gamma: %d\n\n", C->gamma);
	
	CellChaine* cour=C->chaines;

	int nbPoints=0;
	char buff[TAILLE_MAX];	
	char buff1[TAILLE_MIN];

	memset(buff, 0, sizeof (buff));
	memset(buff1, 0, sizeof (buff1));

	while(cour)
	{
		fprintf(f, "%d ", cour->numero);
		
		CellPoint* cour2=cour->points;

		while(cour2){

			sprintf(buff1,"%.2f %.2f ", cour2->x, cour2->y);
			
			strcat(buff, buff1);
			nbPoints++;
			cour2=cour2->suiv;			
		}
				

		fprintf(f,"%d %s \n",nbPoints, buff);

		nbPoints=0;
		memset(buff, 0, sizeof (buff));	   //vide la chaine de caractères buff
		memset(buff1, 0, sizeof (buff1)); //vide la chaine de caractères buff1

		cour=cour->suiv;
	}
}

void afficheChaineSVG(Chaines *C, char* nomInstance){

	SVGwriter* svg =(SVGwriter*)malloc(sizeof(SVGwriter));
	if(svg==NULL){
		printf("\nallocation svg dans afficheChaineSVG echouée\n");
		return;

	}

	SVGinit(svg, nomInstance, IMAGE_X, IMAGE_Y);
	
	//pour créer une ligne avec SVG on a besoin de 2 points, donc on stocke les coordonnées du point précédent
	//->pour pouvoir créer la ligne avec le point courant 

	CellPoint *suiv = NULL;

	CellChaine* cour=C->chaines;

	while(cour){

		CellPoint* cour2=cour->points;

		if(cour2!=NULL){

			SVGpoint(svg, cour2->x, cour2->y); // on crée le premier point
		
		}

		CellPoint *prec = cour2;
		cour2 = cour2->suiv;

		while(cour2){

			SVGpoint(svg, cour2->x, cour2->y); // on crée le point suivant prec
			SVGlineRandColor(svg);
			SVGline(svg, prec->x, prec->y, cour2->x, cour2->y); // on crée la ligne : le segment
			
			prec = cour2;
			cour2=cour2->suiv;

		}

		cour=cour->suiv;
	}
	

	SVGfinalize(svg);
}

/***************** fonctions intermédiaires *******************/


/* calcule la longueur d'une structure CellChaine */

double longueurChaine(CellChaine *c)
{

	if( c->points == NULL) return 0;

	double longChaine=0;

	CellPoint *prec = c->points;
	CellPoint* cour = prec->suiv;
	
	while(cour)
	{
		
		//longChaine += sqrt(pow(prec->x-cour->x,2)+pow(prec->y-cour->y,2));
		prec = cour;	
		cour=cour->suiv;
	}

	return longChaine;
}

/* Compte le nombre de points dans une structure CellChaine */

int comptePoints(CellChaine* CC)
{
	int nbPoints = 0;
	
	if(CC->points == NULL) return nbPoints;

	CellPoint *cour = CC->points;

	while(cour){

		nbPoints += 1;
		cour = cour->suiv;
	}

	return nbPoints;

}

/******** fonctions faisant appel aux fonctions intermédiaires  **************/

/* calcule la longueur d'une structure Chaines */

double longueurTotale(Chaines* C)
{
	double longTotale=0;

	CellChaine* cour = C->chaines;

	while(cour)
	{
		longTotale += longueurChaine(cour);
		cour=cour->suiv;
	}

	return longTotale;

}

/* Compte le nombre de points dans une structure Chaines */

int comptePointsTotal(Chaines *C)
{
	int nbPointsTotal = 0;

	if(C==NULL) return nbPointsTotal;

	CellChaine * cour = C->chaines;

	while(cour){

		nbPointsTotal += comptePoints(cour);
		cour=cour->suiv;
	}
	
	return nbPointsTotal;
}

