# ABR – Analyse de Complexité

Comparaison de 3 algorithmes de vérification d'Arbre Binaire de Recherche 
en C, sur 3 morphologies d'arbres, avec analyse empirique en Python.

## Méthodes comparées
- Naïve (O(n²) dans le pire cas)
- Par définition optimisée (O(n))
- Par parcours infixe (O(n))

## Morphologies testées
- Arbre presque complet
- Arbre filiforme
- Arbre quelconque

## Compilation
gcc -Wall -Wextra main.c est_ABR.c genere_arbre_binaire.c -o abr

## Exécution
./abr  →  génère mesures.csv
python analyse_complexite.py  →  génère les graphiques
