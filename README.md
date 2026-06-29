# ABR – Analyse de Complexité

Analyse empirique de 3 algorithmes de vérification d'ABR en C (naïf, définition, infixe) sur 100 à 100 000 nœuds. Benchmarks automatisés et visualisation log/log en Python/Matplotlib.

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
