#ifndef EXO5_H
#define EXO5_H

#include "Reseau.h"


/* arbre quaternaire contenant les noeuds du reseau */

typedef struct arbreQuat{

	double xc , yc; /* Coordonnees du centre de la cellule */
	double coteX;  /* Longueur de la cellule */
	double coteY;  /* Hauteur de la cellule */
	Noeud* noeud;  /* Pointeur vers le noeud du reseau */
	struct arbreQuat *so; /* Sous-arbre sud-ouest, pour x < xc et y < yc */
	struct arbreQuat *se; /* Sous-arbre sud-est, pour x >= xc et y < yc */
	struct arbreQuat *no; /* Sous-arbre nord-ouest, pour x < xc et y >= yc */
	struct arbreQuat *ne; /* Sous-arbre nord-est, pour x >= xc et y >= yc */


} ArbreQuat;

/* initialise l'ArbreQuat */

ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY)

/* les coordonnée minimales des points du Reseau */

void chaineCoordMinMax(Chaines* C, double* xmin, double* ymin, double* xmax, double* ymax);

/* les coordonées minimales */

void minimales(Chaine *C, double *xmin, double *ymin);

/* les coordonées maximales */

void maximales(Chaine *C, double *xmax, double *ymax);

/* insertion : elle determine la region à insérer l'arbre dans un arbre  */

ArbreQuat* inserer_AB_AB(ArbreQuat *parent, ArbreQuat *a);

/* inserer un noeud dans un ArbreQuat */
ArbreQuat* insererNoeudArbre(Noeud* n, ArbreQuat* a, ArbreQuat* parent);

/* Reconstitution reseau */
Reseau* recreeReseauArbre(Chaines* C);

#endif
