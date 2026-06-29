#ifndef EST_ABR_H
#define EST_ABR_H

typedef struct noeud {
    int valeur;
    struct noeud *fg, *fd;
} Noeud, *Arbre;


/* Retourne la plus petite valeur d'un ABR non vide */
int abr_min(Arbre a,long long *nb_visites );

/* Retourne la plus grande valeur d'un ABR non vide */
int abr_max(Arbre a,long long *nb_visites);

/* Renvoie 1 si a est un ABR, 0 sinon (méthode naïve avec compteur) */
int est_abr_naif(Arbre a, long long *nb_visites);

int est_abr_definition_aux(Arbre a, int *min, int *max, long long *nb_visites);

/* Renvoie 1 si a est un ABR, 0 sinon (méthode optimisée avec compteur) */
int est_abr_definition(Arbre a, long long *nb_visites);

/* Renvoie 1 si un arbre est un ABR via parcours infixe croissant 
   0 sinon et compte les nœuds visités */
int infixe_croissant(Arbre a, Noeud ** dernier_noeud,long long *nb_visites);


/* Renvoie 1  si l'arbre est un ABR par méthode infixe 
    0 sinon avec comptage des visites */
int est_abr_infixe(Arbre a, long long* nb_visites) ;

#endif


