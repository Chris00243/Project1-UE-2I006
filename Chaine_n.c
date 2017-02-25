#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SVGwriter.h"
#include "Chaine.h"

#define TAILLE_MAX 100

#define IMAGE_X 300
#define IMAGE_Y 300

CellPoint* initialise_CP(double x, double y)
{
	CellPoint* cp=(CellPoint*)malloc(sizeof(CellPoint));

	cp->x=x;
	cp->y=y;
	cp->suiv=NULL;

	return cp;
}

CellPoint* inserer_CP(CellPoint* liste, CellPoint* cp)
{
	if(liste==NULL)return cp;
	else{
		cp->suiv=liste;
		liste=cp;
		return liste;
	}
}

CellChaine* initialise_CC(int num)
{
	CellChaine* cc=malloc(sizeof(CellChaine));	
	
	cc->numero=num;
	cc->points=NULL;
	cc->suiv=NULL;

	return cc;
}

CellChaine* inserer_CC(CellChaine* liste, CellChaine* cc)
{
	if(liste==NULL)return cc;
	else{
		cc->suiv=liste;
		liste=cc;
		return liste;
	}
}

void inserer_CC_points(CellChaine* cour, CellPoint* listeP)
{
	cour->points=listeP;
}

Chaines* lectureChaine(FILE *f)
{
	Chaines* new_ch=(Chaines*)malloc(sizeof(Chaines));
	char buff[TAILLE_MAX];	

	//FILE *f=fopen(
	getChaine(f,TAILLE_MAX, buff);
	new_ch->nbChaines=readChar(f);
	
	getChaine(f,TAILLE_MAX, buff);
	new_ch->gamma=readChar(f);
	
}


void afficheChaineSVG(Chaines *C, char* nomInstance){

	SVGwriter svg;
	SVGinit(svg, nomInstance, IMAGE_X, IMAGE_Y);
	
	//pour créer une ligne avec SVG on a besoin de 2 points, donc on stocke les coordonnées du point précédent
	//->pour pouvoir créer la ligne avec le point courant 
	double X_pointPrec=0;
	double Y_pointPrec=0;

	CellChaine* cour=C->chaines;
	while(cour){
		CellPoint* cour2=cour->points;
		while(cour2){
			SVGpoint(svg, cour2->x, cour2->y);
			
			if(X_pointPrec!=0 && Y_pointPrec!=0)
			{
			//ici on passe obligatoirement par le 2eme point courant pour créer une ligne
			SVGline(svg,X_pointPrec,Y_pointPrec,cour2->x, cour2->y);
			}
			
			//récupère à chaque fois les coordonnées du point courant pour créer une nouvelle ligne si il existe un nouveau point dans la chaine
			X_pointPrec=cour2->x;
			Y_pointPrec=cour2->y;			

			cour2=cour2->suiv;
		}
	//on réinitialise à 0 pour refaire le même traitement
	X_pointPrec=0;
	Y_pointPrec=0;
		
	cour=cour->suiv;
	}

}

double longueurChaine(CellChaine *c)
{
	double longChaine=0;
	CellPoint* cour=c->points;
	
	double X_pointPrec=0;
	double Y_pointPrec=0;

	while(cour)
	{
		if(X_pointPrec!=0 && Y_pointPrec!=0)
		{
			//il doit exister un 2eme point obligatoirement pour compter une ligne
			longChaine+=sqrt(pow(cour->x-X_pointPrec,2)+pow(cour->y-Y_pointPrec,2));
		}

		X_pointPrec=cour->x;
		Y_pointPrec=cour->y;
			
		cour=cour->suiv;
	}

	return longChaine;
}

double longueurTotale(Chaines* C){
	double longTotale=0;

	CellChaine* cour=C->chaines;
	while(cour)
	{
		longTotale+=longueurChaine(cour);
		cour=cour->suiv;
	}

	return longTotale;

}

int comptePointsTotal(Chaines *C){
	int nbPointsTotal=0;

	CellChaine* cour=C->chaines;
	while(cour){
		CellPoint* cour2=cour->points;
		while(cour2){		
			nbPointsTotal++;
			cour2=cour2->suiv;
		}
		
	cour=cour->suiv;
	}
	
	return nbPointsTotal;
}
