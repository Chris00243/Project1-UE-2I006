#ifndef __RESEAU_H__
#define __RESEAU_H__

#include "Chaine.h"
#include "exo4.h"  // ajouté du fait qu'on a ajouté une table de HAchage dans la structure Reseau, qui sera utilisé à l'exo4

typedef struct noeud Noeud;

/* Liste chainee de noeuds (pour la liste des noeuds du reseau ET les listes des voisins de chaque noeud) */
typedef struct cellnoeud {
    Noeud *nd;               /* Pointeur vers le noeud stock\'e */
    struct cellnoeud *suiv;         /* Cellule suivante dans la liste */

    int clef; /* Je l'ai ajouté, et sera utilisé pour l'exo4 : lors de la table de Hachage */

} CellNoeud;

/* Noeud du reseau */
struct noeud{
   int num;                        /* Numero du noeud */
   double x, y;                    /* Coordonnees du noeud*/
   CellNoeud *voisins;             /* Liste des voisins du noeud */
};

/* Liste chainee de commodites */
typedef struct cellCommodite {
    Noeud *extrA, *extrB;       /* Noeuds aux extremites de la commodite */
    struct cellCommodite *suiv;     /* Cellule suivante dans la liste */
} CellCommodite;

/* Un reseau */
typedef struct {
    int nbNoeuds;                   /* Nombre de noeuds du reseau */
    int gamma;                      /* Nombre maximal de fibres par cable */
    CellNoeud *noeuds;              /* Liste des noeuds du reseau */
    CellCommodite *commodites;      /* Liste des commodites a relier */

    TH* H; /* Table de Hachage ajouté et utilisé dans l' exo4 */
	
} Reseau;

/* Fonctions ajoutées */

Noeud* initialiser_Noeud(double x, double y);
CellNoeud* initialiser_CellNoeud();
CellNoeud* creer_cellNoeud(Noeud *N);
int compteNbVoisins(CellNoeud *CN);
CellCommodite* initialiser_CellCommodite(Noeud* N1, Noeud* N2);
Reseau* initialiser_Reseau(int gamma, int num);
CellNoeud* inserer_CN_N(CellNoeud* CN, double x, double y);
CellCommodite* inserer_RCom_Com(CellCommodite *RCom, CellCommodite *Com);
Noeud* recherche_CN_N(CellNoeud *CN, double x, double y);
Noeud* recherche_N_N(Noeud N, double x, double y);
Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y);
Reseau* reconstitueReseauListe(Chaines* C);
int nbCommodite(Reseau *R);
int nbLiaison(Reseau *R);




Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y);
Reseau* reconstitueReseauListe(Chaines *C);
void ecrireReseauTxt(Reseau *R, FILE *f);
int nbLiaison(Reseau *R);
int nbCommodite(Reseau *R);
void afficheReseauSVG(Reseau *R, char* nomInstance);


#endif

