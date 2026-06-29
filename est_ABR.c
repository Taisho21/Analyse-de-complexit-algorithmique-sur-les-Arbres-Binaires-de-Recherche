#include<stdlib.h>
#include<stdio.h>
#include "est_ABR.h"


// 1.1 Application de la définition - Approche naïve
int abr_min(Arbre a, long long *nb_visites) {
    if (!a) return -1;
    while (a->fg != NULL) {
        (*nb_visites)++;
        a = a->fg;
    }
    (*nb_visites)++;
    return a->valeur;
}

int abr_max(Arbre a, long long *nb_visites) {
    if (!a) return -1;
    while (a->fd != NULL) {
        (*nb_visites)++;
        a = a->fd;
    }
    (*nb_visites)++;
    return a->valeur;
}

int est_abr_naif(Arbre a, long long *nb_visites) {
    if (!a) return 1;
    (*nb_visites)++;
    if (a->fg && abr_max(a->fg, nb_visites) >= a->valeur) return 0;
    if (a->fd && abr_min(a->fd, nb_visites) <= a->valeur) return 0;
    if (!est_abr_naif(a->fg, nb_visites)) return 0;
    if (!est_abr_naif(a->fd, nb_visites)) return 0;
    return 1;
}

// 1.2 Application de la définition - Approche optimisée

int est_abr_definition_aux(Arbre a, int *min, int *max, long long *nb_visites){
    if (!a) return 1;
    (*nb_visites)++;

    int min_g = 0, max_g = 0, min_d = 0, max_d = 0;

    if (a->fg){
        if (!est_abr_definition_aux(a->fg, &min_g, &max_g, nb_visites)) return 0;
        if (max_g >= a->valeur) return 0;
    }

    if (a->fd){
        if (!est_abr_definition_aux(a->fd, &min_d, &max_d, nb_visites)) return 0;
        if (min_d <= a->valeur) return 0;
    }

    *min = (a->fg) ? min_g : a->valeur;
    *max = (a->fd) ? max_d : a->valeur;

    return 1;
}


int est_abr_definition(Arbre a, long long *nb_visites){
    int min, max;
    return est_abr_definition_aux(a, &min, &max, nb_visites);
}


// 1.3 Application de la caractérisation d’un ABR par son parcours infixe:

int infixe_croissant(Arbre a, Noeud ** dernier_noeud,long long *nb_visites)
{
    if(!a )  return 1;
    
    (*nb_visites) ++;

    if(!infixe_croissant(a->fg,dernier_noeud,nb_visites))
       return 0;

    
    if(*dernier_noeud && (*dernier_noeud)->valeur > a->valeur)
       return 0;

    *dernier_noeud=a;

    return infixe_croissant(a->fd,dernier_noeud,nb_visites);
}

int est_abr_infixe(Arbre a, long long* nb_visites) 
{
    Noeud *dernier_noeud =NULL;
    return infixe_croissant(a,&dernier_noeud,nb_visites);
}


