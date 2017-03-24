#ifndef EXO4_H
#define EXO4_H

#include "Reseau.h"

typedef struct table_Hachage{

	int n; /* la taille du tableau de Hachage */

	CellNoeud* *Tab; /* Un tableau des pointeurs de CellNoeud avec résolution de collision par chainage */

}TH;

/* Alloue de l'espace mémoire nécessaire à la table de Hachage de taille m et initialise aussi les données */

TH* initialiser_TH(int n);

/* Fonction qui initialise CellNoeud étant donné qu'elle comprend maintenant une varaible clef  Voir Reseau.h la structure CellNoeud */

CellNoeud* initialiser_CellNoeud_avec_Clef(Noeud *N, int n);

/* la fonction qui retourne la clef */

int fonctionClef(Noeud* N, int n);

/* la fonction qui transforme a clé en une valeur entière utilisable et permet d'eviter au maximum des collisions */

int fonctionHachage(int clef, int n);

/* elle retourne un Noeud correspondant au point (x,y) de H sinon crée un Noeud de coordonnées (x,y) et l'ajoute dans H et aussi Dans R->noeuds  */

Noeud* rechercheCreeNoeudHachage(Reseau *R, TH* H, double x, double y);

#endif
