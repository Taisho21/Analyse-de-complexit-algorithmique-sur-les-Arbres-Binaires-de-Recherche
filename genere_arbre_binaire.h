#ifndef GENERE_ARBRE_BINAIRE_H
#define GENERE_ARBRE_BINAIRE_H

#include "est_ABR.h"
#include<stdlib.h>
#include<stdio.h>

/* Construit un arbre binaire à partir de son codage en parcours préfixe.
   Les noeuds sont codés par leur valeur, les sous-arbres vides par -1. */
int construit_quelconque(Arbre *a, int **codage, int n);

/* Retourne le nombre de noeuds dans le sous-arbre gauche
   d'un arbre presque complet à n noeuds. */
int nb_noeuds_gauche(int n);

/* Transforme le parcours infixe d'un arbre presque complet à n noeuds
   en son parcours préfixe. */
void parcours_infixe_2_prefixe_presque_complet(int *prefixe, int *infixe, int n);

/* Transforme le parcours infixe en parcours préfixe pour un arbre filiforme
   dont la forme est choisie aléatoirement parmi les 2^(n-1) formes possibles. */
void parcours_infixe_2_prefixe_filiforme_aleatoire(int *prefixe, int *infixe, int n);

/* Transforme le parcours infixe en codage préfixe pour un arbre de forme
   quelconque choisie aléatoirement parmi les Cn formes possibles. */
void parcours_infixe_2_prefixe_quelconque_aleatoire(int *codage, int *infixe, int n);

/* Crée aléatoirement un ABR de forme presque complète à taille noeuds. */
int ABR_presque_complet_alea(Arbre *a, int taille);

/* Crée aléatoirement un arbre non-ABR de forme presque complète à taille noeuds. */
int non_ABR_presque_complet_alea(Arbre *a, int taille);

/* Crée aléatoirement un ABR de forme filiforme à taille noeuds. */
int ABR_filiforme_alea(Arbre *a, int taille);

/* Crée aléatoirement un arbre non-ABR de forme filiforme à taille noeuds. */
int non_ABR_filiforme_alea(Arbre *a, int taille);

/* Crée aléatoirement un ABR de forme quelconque à taille noeuds. */
int ABR_quelconque_alea(Arbre *a, int taille);

/* Crée aléatoirement un arbre non-ABR de forme quelconque à taille noeuds. */
int non_ABR_quelconque_alea(Arbre *a, int taille);

/* Affiche les valeurs de l'arbre dans l'ordre infixe. */
void affiche_infixe(Arbre a);

/* Libère récursivement toute la mémoire allouée pour l'arbre. */
void libere_arbre(Arbre a);

#endif




