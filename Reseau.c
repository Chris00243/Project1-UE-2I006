#include <stdlib.h>
#include <stdio.h>
#include "Reseau.h"

/********** FONCTIONS Noeud *************************************/

Noeud* initialiser_noeud(int num, double x, double y)
{

	Noeud* n = (Noeud*)malloc(sizeof(Noeud));

	if(n==NULL)return NULL;

	n->num=num;
	n->x=x;
	n->y=y;
	n->voisins=NULL;
			
	return n;
}



/******* FONCTIONS CellNoeud ******************************************/

CellNoeud* initialiser_cellNoeud()
{
	CellNoeud *cn = (CellNoeud*)malloc(sizeof(CellNoeud));

	cn->nd = NULL;
	cn->suiv = NULL;
}

/******* FONCTIONS COMMODITES ******************************************/

CellCommodite* initialiser_cellCommodite(Noeud* N1, Noeud* N2)
{

	CellCommodite* cc = (CellCommodite*)malloc(sizeof(CellCommodite));

	if(cc==NULL)return NULL;

	cc->extrA=N1;
	cc->extrB=N2;
	cc->suiv=NULL;
			
	return cc;
}

/******* FONCTIONS Reseau ******************************************/

Reseau* initialiser_reseau(int nbNoeuds, int gamma)
{
	Reseau* r = (Reseau*)malloc(sizeof(Reseau));

	if(r==NULL)return NULL;

	r->nbNoeuds = nbNoeuds;
	r->gamma = gamma;
	r->noeuds = NULL;
	r->commodites = NULL;

	return r;
}

//insérer un Noeud dans un CellNoeud
void inserer_CN_N(CellNoeud* CN, Noeud* N)
{

	if(CN->nd==NULL){

		CN->nd=N;
		return;
		
	}
	
		CellNoeud* cour=CN;
		
		while(cour->suiv){
			cour=cour->suiv;
		}
		cour->nd->voisins->suiv=cour;
		cour->nd=N;
	}

}

void inserer_lCN_CN(CellNoeud* lCN, CellNoeud* CN)
{
	if(lCN==NULL)
	{
		lCN=CN;	
	}
	else
	{
		N->voisins->suiv=CN;
		CN->nd=N;
	}
}

void inserer_R_CN(Reseau* R, CellNoeud* CN){
	
	if(R->noeuds==NULL)R->noeuds=CN;
	else{
		CN->suiv=noeuds;
		noeuds=CN;
	}
}

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){
	CellNoeud* cour=R->noeuds;

	while(cour){
		if(cour->nd->x==x && cour->nd->y==y){
			return cour->nd;
		}

	cour=cour->suivant;
	}

	Noeud* N=initialiser_noeud(R->nbNoeuds+1, x, y);
	CellNoeud* CN=initialiser_cellNoeud(N);
	inserer_R_CN(R,CN);
	
	R->nbNoeuds++;

	return N;
}

Reseau* reconstitueReseauListe(Chaines* C){
	int nbPointsTotal=0;	
	
	
