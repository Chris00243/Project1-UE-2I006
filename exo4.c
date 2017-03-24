#include "exo4.h" 
#define A 0.618033989

/************************************************** LES FONCTIONS DE LA STRUCTURE TH  *********************************************************/



/* Alloue de l'espace mémoire nécessaire à la table de Hachage de taille n et initialise aussi les données */

TH* initialiser_TH(int n)
{
	TH* T = (TH*)malloc(sizeof(TH));
	if(T==NULL) return NULL;

	T->n = n;

	T->Tab = (CellNoeud**)maloc(n*sizeof(CellNoeud*));
	if(T->Tab==NULL) return NULL;

	int i;

	for(i=0; i<n; i++){

		T->Tab[i] = NULL;
	}


	return T;

}


/************************************************** LES FONCTIONS DE LA STRUCTURE CellNoeud  *********************************************************/


/* Fonction qui initialise CellNoeud étant donné qu'elle comprend maintenant une varaible clef  Voir Reseau.h la structure CellNoeud */

CellNoeud* initialiser_CellNoeud_avec_Clef(Noeud *N, int n)
{
	CellNoeud* CN = creer_cellNoeud(N);
	if(CN==NULL) return NULL;
	CN->clef = fonctionClef(CN->nd, n);
	return CN;
}




/********************************************************* LES FONCTIONS DE HACHAGE *************************************************************************/

/* la fonction qui retourne la clef */

int fonctionClef(Noeud* N, int n)
{
	return fonctionHachage( (int)( (N->y)+( (N->x + N->y)(N->x + N->y +1) )/2 ), n );

}

/* la fonction qui transforme a clé en une valeur entière utilisable et permet d'eviter au maximum des collisions */

int fonctionHachage(int clef, int n)
{
	return (int)( n*( clef*A - (int)(clef*A) ) );	

}


/********************************************************* LES FONCTIONS INDISPENSABLES *************************************************************************/

/* Insertion des CellNoeud dans la table de Hachage à partir de leur clef */
void inserer_CN_TH(TH *H, CellNoeud *CN)
{
	if(H==NULL || CN==NULL) return;
	
	CN->suiv = H->Tab[CN->clef];
	H->Tab[CN->clef] = CN;

	return H;

}


}

/* elle retourne un Noeud correspondant au point (x,y) de H sinon crée un Noeud de coordonnées (x,y) et l'ajoute dans H et aussi Dans R->noeuds  */

Noeud* rechercheCreeNoeudHachage(Reseau *R, TH* H, double x, double y)
{
	for(i=0;i<H->n;i++){
		
		if(H->T[i]==NULL) continue;
	
		if(H->T[i]->nd->x == x && H->T[i]->nd->y == y) return H->T[i]->nd;
				
		CellNoeud *cour =  H->T[i]->suiv

		while(cour){
	
			if(cour->nd->x == x && cour->nd->y == y) return cour->nd;
			cour = cour->suiv;
		}
	}
		CellNoeud *C = creer_CellNoeud( initialiser_Noeud(x, y) );    // ajout dans la liste noeuds
		C->suiv = R->noeuds;
		R->noeuds = C;
		
		H = inserer_CN_TH(H, C); 		// ajout dans la table de Hachage 

		printf("\nNoeud ajouté\n");
		return C->nd; 	
}	




