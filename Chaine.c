#ifndef __CHAINE_C__
#define __CHAINE_ C__	
#include<stdio.h>

include "Chaine.h"



#endif 


/*************************  FONCTIONS STRUCTURE CellPoint ***************************************************************/





/* initialise et crée une structure CellPoint */

CellPoint* initialise_CP(double x, double y)
{
	CellPoint* CP=(CellPoint*)malloc(sizeof(CellPoint));

	CP->x=x;
	CP->y=y;
	CP->suiv=NULL;

	return CP;
}







/*************************  FONCTIONS STRUCTURE CellChaines ***************************************************************/





/* initialise une structure CellChaine */

CellChaine* initialise_CC(int num)
{
	CellChaine* CC=malloc(sizeof(CellChaine));	
	
	CC->numero=num;
	CC->points=NULL;
	CC->suiv=NULL;

	return CC;
}






/*************************  FONCTIONS STRUCTURE Chaines ***************************************************************/





/* initialise une structure Chaines */

Chaines* initialiser_C(Chaines* C)
{
	(*C) = (Chaines *) malloc(sizeof(Chaines) );
	
	C->gamma = 0;
	C->nbChaines = 0;
	C->chaines = NULL;
}










/*************************  FONCTIONS STRUCTURE CellPoint et CellChaine ***************************************************************/



/* Insère CellPoint dans CellChaine */

CellChaines* inserer_CP_CC(CellChaines *CC, CellPoint *CP)
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
	if(lCP=NULL && CP=NULL) return NULL;
	if(lCP=NULL) return CP;

	CellPoint* SAVE_lCP = lCP;

	CellPoint* prec = lCP;
	lCP = lCP->suiv;	

	while(lCP){

		prec = lCP;
		lCP = lCP->suiv;

	}
	
	if(prec!=NULL){

		prec->suiv = CP;
		return SAVE_lCP;
	}

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
	if(lC=NULL && CP=NULL) return NULL;
	if(lCP=NULL) return CC;

	CellPoint* SAVE_lC = lC;

	CellChaine* prec = lC;
	lC = lC->suiv;	

	while(lC){

		prec = lC;
		lC = lC->suiv;

	}
	
	if(prec!=NULL){

		prec->suiv = CC;
		return SAVE_lC;
	}
} 











/*************************  FONCTIONS STRUCTURES ALLL ***************************************************************/

Chaines* lectureChaine(FILE *f)
{ 

	

}
