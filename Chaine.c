#ifndef CHAINE_C
#define CHAINE_C


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chaine.h"


#endif

#define TAILLE_MAX 200


/*************************  FONCTIONS STRUCTURE CellPoint ***************************************************************/





/* initialise et crée une structure CellPoint */

CellPoint* initialiser_CP(double x, double y)
{
	CellPoint* CP=(CellPoint*)malloc(sizeof(CellPoint));

	CP->x=x;
	CP->y=y;
	CP->suiv=NULL;

	return CP;
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
	int nbChaines;
	fscanf(f,"%d", &nbChaines);
	int gamma;
	fscanf(f,"%d", &gamma);
	Skip(f);
	
	Chaines *C = initialiser_C(gamma,nbChaines);
	char buff[TAILLE_MAX];	

	int numero;
	int nbPoints;
	double xP, yP;
	
	CellChaine* CC;
	CellPoint* CP;	
	
	int i;
	
	do{
		GetChaine(f,TAILLE_MAX,buff);
		
		fscanf(f,"%d %d", &numero, &nbPoints);	
		CC=initialiser_CC(numero);

		for(i=0; i<nbPoints; i++)
		{
			fscanf(f,"%lf %lf", &xP, &yP);
			CP=initialiser_CP(xP, yP);
			CC=inserer_CP_CC(CC, CP);
		}
	
	C=inserer_CC_C(C,CC);

	}while(buff != NULL);

	return C;
}

void ecrireChaineTxt(Chaines *C, FILE *f)
{
	fprintf(f,"NbChain: %d\n", C->nbChaines);
	fprintf(f,"Gamma: %d\n\n", C->gamma);
	
	CellChaine* cour=C->chaines;

	int nbPoints=0;
	char buff[TAILLE_MAX];	

	while(cour)
	{
		fprintf(f, "%d", cour->numero);
		
		CellPoint* cour2=cour->points;
		while(cour2){
			sprintf(buff,"%f %f", cour2->x, cour2->y);
			nbPoints++;
			cour2=cour2->suiv;			
		}

		fprintf(f,"%d %s",nbPoints, buff);
		nbPoints=0;
		memset(buff, 0, sizeof (buff));//vide la chaine de caractères buff
		cour=cour->suiv;
	}
	

}

