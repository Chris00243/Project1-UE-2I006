

/* initialise l'ArbreQuat */

ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY)
{
	ArbreQuat *AB = (ArbreQuat*)malloc(sizeof(ArbreQuat);
	if(AB==NULL) return NULL;

	AB->xc = xc;
	AB->yc = yc;
	AB->coteX = coteX;
	AB->coteY = coteY;
		
	AB->noeud = NULL;
	AB->se = NULL; 
	AB->so = NULL;
	AB->no = NULL;
	AB->ne = NULL;

	return AB;
}


/* les coordonnée minimales et maximales des points du Reseau */

void chaineCoordMinMax(Chaines* C, double* xmin, double* ymin, double* xmax, double* ymax)
{
	minimales(C, xmin, ymin);
	maximales(C, xmax, ymax);	

}

/* les coordonées minimales */

void minimales(Chaine *C, double *xmin, double *ymin)
{
	CellChaine *CC = C->chaines;

	CellPoint *CP = CC->points;

	double X = CP->x;
	double Y = CP->y;

	CP = CP->suiv;

	while(CC){
	
		while(CP){
	
			if(CP->x < X) X = CP->x;
			if(CP->y < Y) Y = CP->y;

			CP = CP->suiv;
		}
	
		CC = CC->suiv;
	}

	*xmin = X;
	*ymin = Y;

}

/* les coordonées maximales */

void maximales(Chaine *C, double *xmax, double *ymax)
{
	CellChaine *CC = C->chaines;

	CellPoint *CP = CC->points;

	double X = CP->x;
	double Y = CP->y;

	CP = CP->suiv;

	while(CC){
	
		while(CP){
	
			if(CP->x > X) X = CP->x;
			if(CP->y > Y) Y = CP->y;

			CP = CP->suiv;
		}
	
		CC = CC->suiv;
	}

	*xmax = X;
	*ymax = Y;

}


/* insertion : elle determine la region à insérer l'arbre dans un arbre  */

ArbreQuat* inserer_AB_AB(ArbreQuat *parent, ArbreQuat *a)
{
	double x = a->noeud->x;
	double y = a->noeud->y;

	double xc = parent->xc;
	double yc = parent->yc;

	ArbreQuat *O = NULL;

	if(x>=xc && y>=yc){
		
	 	if(parent->ne==NULL){

			 parent->ne = a; // Nord-Est
	 		 return parent;

		}

		insererNoeudArbre(a->noeud, O, parent->ne);	

	}

	if(x<xc && y>=yc){

		 if(parent->no==NULL){
	
			parent->no = a; // Nord-Ouest
			return parent;
		 }
		
		insererNoeudArbre(a->noeud, O, parent->no);
	}
	
	if(x>=xc && y<yc){

		if(parent->se==NULL){
 			parent->se = a; // Sud-Est
		 	return parent;
		 }

		insererNoeudArbre(a->noeud, O, parent->se);
		
	}

	if(x<xc && y<yc){

		 if(parent->so==NULL){

			parent->so = a; // Sud-Ouest
		 	return parent;
		 }
		
		insererNoeudArbre(a->noeud, O, parent->so);
	}
}


/* inserer un noeud dans un ArbreQuat */
ArbreQuat* insererNoeudArbre(Noeud* n, ArbreQuat* a, ArbreQuat* parent);
{

	if(a==NULL){
		
		double coteX = parent->coteX - parent->xc;
		double coteY = parent->coteY - parent->yc;

		double xc = coteX/2;
		double yc = coteY/2;

		ArbreQuat* a = creerArbreQuat(xc, yc, coteX,coteY);
		a->noeud = n;

		return inserer_AB_AB(parent, a);


	}

	if( a->noeud != NULL){

		ArbreQuat *b = NULL;
		ArbreQuat *c = NULL;

		Noeud *N = a->noeud;
				
		a->noeud == NULL;

		a = insererNoeudArbre(n, b, a);

		return insererNoeudArbre(N, c, a);
	}

	if( a!=NULL && a->noeud == NULL){

		ArbreQuat *b = NULL;

		return insererNoeudArbre(n, b, a);

	}


}

/* Reconstitution reseau */
Reseau* recreeReseauArbre(Chaines* C)
{
	CellChaine *CC = C->chaines;
	
	Cellpoint *CP = CC->points;

	// calcul des minimales et maximales

	double xmin, xmax, ymin, ymax;

	chaineCoordMinMax(C, &xmin, &ymin, &xmax, &ymax);

	// détermination des coordonées du centre 

		double xc, yc;
		xc = (xmax-xmin)/2;
		yc = (ymax-ymin)/2;
	// déterminnation de la hauteur et la longueur

		double coteX, coteY;
		coteX=xmax+xmin;
		coteY=ymax+ymin;
		
		ArbreQuat*parent = creerArbreQuat(xc,yc,coteX,coteY);

		while(CC){
			
			while(CP){

				ArbreQuat* a;

				insererNoeudArbre(initialiser_Noeud(CP->x, CP->y), a, parent);
				
				CP = CP->suiv;
			
			}
			
			CC = CC->suiv;		
		}

}






