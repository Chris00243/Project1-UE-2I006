#ifndef __CHAINE_H__
#define __CHAINE_H__

#include<stdio.h>
#include "entree_sortie.h"
#include "SVGwriter.h"

/* Liste chainee de points */
typedef struct cellPoint{
  double x,y;                   /* Coordonnees du point */
  struct cellPoint *suiv;       /* Cellule suivante dans la liste */
} CellPoint;

/* Celllule d une liste (chainee) de chaines */
typedef struct cellChaine{
  int numero;                   /* Numero de la chaine */
  CellPoint *points;            /* Liste des points de la chaine */
  struct cellChaine *suiv;      /* Cellule suivante dans la liste */
} CellChaine;

/* L'ensemble des chaines */
typedef struct {
  int gamma;                    /* Nombre maximal de fibres par cable */
  int nbChaines;                /* Nombre de chaines */
  CellChaine *chaines;          /* La liste chainee des chaines */
} Chaines;

/* initialise et crée une structure CellPoint */
CellPoint* initialiser_CP(double x, double y);

/* Affiche une structure CellPoint */
void afficher_CP( CellPoint *CP);

/* initialise une structure CellChaine */
CellChaine* initialiser_CC(int num);

/* affiche une structure CellChaine */
void afficher_CC( CellChaine *CC);

/* initialise une structure Chaines */
Chaines* initialiser_C(int gamma, int nbChaines);

/* affiche une structure Chaines */
void afficher_C( Chaines *C);

/* Insère CellPoint dans CellChaine */
CellChaine* inserer_CP_CC(CellChaine *CC, CellPoint *CP);

/* Insère CellPoint dans la liste Points de CellChaine. FONCTION UTILISEE DANS inserer_CP_CC.  On opte pour l'insertion en queue pour respecter la formation de CellChaine */
CellPoint* inserer_CP_lCP( CellPoint* lCP, CellPoint *CP);

/* Insère CellChaine dans Chaines */
Chaines* inserer_CC_C(Chaines *C, CellChaine *CC);

/* Insère CellChaine dans la liste chaines de Chaines. FONCTION UTILISEE DANS inserer_CC_C. Insertion en queue*/
CellChaine* inserer_CC_lC( CellChaine* lC, CellChaine *CC);

Chaines* lectureChaine(FILE *f);
void ecrireChaineTxt(Chaines *C, FILE *f);
void afficheChaineSVG(Chaines *C, char* nomInstance);

/* fonctions intermédiaires */

int comptePoints(CellChaine* CC);
double longueurChaine(CellChaine *c);

/* fonctions faisant appel aux fonctions intermédiaires */

double longueurTotale(Chaines *C);
int comptePointsTotal(Chaines *C);




#endif	
