#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "est_ABR.h"
#include "genere_arbre_binaire.h"

int main(void) {
    srand(time(NULL));

    FILE *f = fopen("mesures.csv", "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return 1;
    }

    fprintf(f, "Taille;Morphologie;Methode;Nb_visites;Temps\n");

    int tailles[] = {100, 500, 1000, 2000, 5000, 10000, 100000};
    int nb_tailles = 6;
    int repetitions = 10;

    for (int i = 0; i < nb_tailles; i++) {
        int n = tailles[i];
        printf("Taille : %d\n", n);

        for (int rep = 0; rep < repetitions; rep++) {
            Arbre a;
            long long nb_visites;
            struct timespec debut, fin;
            double temps;

            // --- ABR presque complet ---
            ABR_presque_complet_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_presque_complet;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_presque_complet;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_presque_complet;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);

            // --- non ABR presque complet ---
            non_ABR_presque_complet_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_presque_complet;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_presque_complet;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_presque_complet;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);

            // --- ABR filiforme ---
            ABR_filiforme_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_filiforme;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_filiforme;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_filiforme;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);

            // --- non ABR filiforme ---
            non_ABR_filiforme_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_filiforme;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_filiforme;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_filiforme;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);

            // --- ABR quelconque ---
            ABR_quelconque_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_quelconque;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_quelconque;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;ABR_quelconque;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);

            // --- non ABR quelconque ---
            non_ABR_quelconque_alea(&a, n);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_naif(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_quelconque;naif;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_definition(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_quelconque;definition;%lld;%f\n", n, nb_visites, temps);

            nb_visites = 0;
            clock_gettime(CLOCK_MONOTONIC, &debut);
            est_abr_infixe(a, &nb_visites);
            clock_gettime(CLOCK_MONOTONIC, &fin);
            temps = (fin.tv_sec - debut.tv_sec) + (fin.tv_nsec - debut.tv_nsec) / 1e9;
            fprintf(f, "%d;non_ABR_quelconque;infixe;%lld;%f\n", n, nb_visites, temps);

            libere_arbre(a);
        }
    }

    fclose(f);
 
    return 0;
}

