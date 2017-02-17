#ifndef __CHAINE_H__
#define __CHAINE_H__	
#include<stdio.h>

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

CellPoint* initialise_CP(double x, double y); //initialise CellPoint
CellPoint* inserer_CP(CellPoint* liste, CellPoint* cp); //insère un CellPoint dans une liste de CellPoints
CellChaine* initialise_CC(int num); //initialise CellChaine
CellChaine* inserer_CC(CellChaine* liste, CellChaine* cc); //insère un CellChaine dans une liste de CellChaines
void inserer_CC_points(CellChaine* cour, CellPoint* listeP); //insère un point ou une liste de points dans notre CellChaine courante
Chaines* lectureChaine(FILE *f);
void ecrireChaineTxt(Chaines *C, FILE *f);
void afficheChaineSVG(Chaines *C, char* nomInstance);
double longueurTotale(Chaines *C);
int comptePointsTotal(Chaines *C);

#endif	
