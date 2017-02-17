#include <stdio.h>
#include <stdlib.h>
#include "Chaine.h"

#define TAILLE_MAX 100

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
