#include"genere_arbre_binaire.h"


int construit_quelconque(Arbre * a, int ** codage, int n){
    if(**codage == -1){
        *a = NULL;
        (*codage)++;
        return 1;
    }
    else{
        Noeud *nouveau = malloc(sizeof(Noeud));
        if(!(nouveau)){
            return 0;
        }nouveau->valeur = **codage;
        (*codage)++;
        if(!construit_quelconque(&nouveau->fg, codage, n-1)){
            free(nouveau);
            return 0;
        }
        if(!construit_quelconque(&nouveau->fd, codage, n-1)){
            free(nouveau);
            return 0;
        }        
        *a = nouveau;
        return 1;
    }
}

int nb_noeuds_gauche(int n){
    if(n == 1)
        return 0;
    int h = 0;
    int temp = n;
    while(temp > 1){
        temp = temp / 2;
        h++;
    }
    int noeud = 0;
    int i = 0;
    while(i < h-1){
        noeud++;
        i++;
    }
    int puissance = 1;
    for(int j = 0; j < h-1; j++){
        puissance = puissance * 2;
    }
    noeud = puissance - 1;

    int total = 0;
    int puissance2 = 1;
    for(int j = 0; j<h; j++){
        puissance2 = puissance2 *2;
    }
    total = puissance2 - 1;
    int noeud_dernier = n - total;

    int max_gauche = 1;
    for(int j = 0; j <h-1; j++){
        max_gauche = max_gauche *2;
    }
    int gauche_dernier = 0;
    if(noeud_dernier < max_gauche){
        gauche_dernier = noeud_dernier;
    }else{
        gauche_dernier = max_gauche;
    }
    return noeud + gauche_dernier;

}


void parcours_infixe_2_prefixe_presque_complet(int *prefixe, int *infixe, int n){
    if(n == 0) {
        prefixe[0] = -1;
        return;
    }


    int gauche = nb_noeuds_gauche(n);
    prefixe[0] = infixe[gauche]; 
    parcours_infixe_2_prefixe_presque_complet(prefixe+1, infixe, gauche);
    parcours_infixe_2_prefixe_presque_complet(prefixe+1+(2 * gauche + 1), infixe+gauche+1, n-gauche-1);
}


void parcours_infixe_2_prefixe_filiforme_alea_aux(int * prefixe, int *infixe, int n, int *repere){
    int random = rand() % 2;


    if(n == 0){
        prefixe[*repere] = -1;
        (*repere)++;
        return;
    }
    

    if(random == 0){
        prefixe[*repere] = infixe[0];

        (*repere)++;
        prefixe[*repere] = -1; //pas de fg
        (*repere)++;
        parcours_infixe_2_prefixe_filiforme_alea_aux(prefixe, infixe+1, n-1, repere);
    }
    else {
        prefixe[*repere] = infixe[n-1];
        (*repere)++;
        parcours_infixe_2_prefixe_filiforme_alea_aux(prefixe, infixe, n-1, repere);
        prefixe[*repere] = -1; //paas de fd
        (*repere)++;
    }
    

}

void parcours_infixe_2_prefixe_filiforme_aleatoire(int *prefixe, int *infixe, int n){
    int repere = 0;
    parcours_infixe_2_prefixe_filiforme_alea_aux(prefixe, infixe, n, &repere);

}


void parcours_infixe_2_prefixe_quelconque_alea_aux(int * codage, int * infixe, int n, int *repere){
    if(n == 0){
        codage[*repere] = -1;
        (*repere)++;
        return;
    }
    int random = rand() % n;
    codage[*repere] = infixe[random];
    (*repere)++;
    parcours_infixe_2_prefixe_quelconque_alea_aux(codage, infixe, random, repere);
    parcours_infixe_2_prefixe_quelconque_alea_aux(codage, infixe + random + 1, n - random - 1, repere);
}

void parcours_infixe_2_prefixe_quelconque_aleatoire(int * codage, int * infixe, int n){
    int repere = 0;
    parcours_infixe_2_prefixe_quelconque_alea_aux(codage, infixe, n, &repere);
}


int ABR_presque_complet_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;
    
    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i-1] + rand() % 10 + 1;
    }

    int *prefixe = malloc((2*taille + 1) * sizeof(int));
    if(!prefixe){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_presque_complet(prefixe, infixe, taille); 

    int *codage = prefixe;
    int res = construit_quelconque(a, &codage, taille);

    free(infixe);
    free(prefixe);
    return res;


}

int non_ABR_presque_complet_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;



    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i - 1] + rand() % 10 + 1;
    }

    for (int i = taille - 1; i > 0; i--){
        int j = rand() % (i+1);
        int tmp = infixe[i];
        infixe[i] = infixe[j];                      
        infixe[j] = tmp;
    }



    int *prefixe = malloc((2*taille+1) * sizeof(int));
    if(!prefixe){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_presque_complet(prefixe, infixe, taille); 

    int *codage = prefixe;
    int res = construit_quelconque(a, &codage, taille);

    free(infixe);
    free(prefixe);
    return res;


}


int ABR_filiforme_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;
    
    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i-1] + rand() % 10 + 1;
    }

    int *prefixe = malloc((2*taille+1) * sizeof(int));
    if(!prefixe){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_filiforme_aleatoire(prefixe, infixe, taille); 

    int *codage = prefixe;
    int res = construit_quelconque(a, &codage, taille);

    free(infixe);
    free(prefixe);
    return res;


}







int non_ABR_filiforme_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;
    
    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i-1] + rand() % 10 + 1;
    }

     for (int i = taille - 1; i > 0; i--){
        int j = rand() % (i+1);
        int tmp = infixe[i];                            
        infixe[i] = infixe[j];
        infixe[j] = tmp;
    }

    int *prefixe = malloc((2*taille+1) * sizeof(int));
    if(!prefixe){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_filiforme_aleatoire(prefixe, infixe, taille); 

    int *codage = prefixe;
    int res = construit_quelconque(a, &codage, taille);

    free(infixe);
    free(prefixe);
    return res;


}



int ABR_quelconque_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;
        
    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i-1] + rand() % 10 + 1;
    }

    int *codage = malloc((2*taille + 1) * sizeof(int));
    if(!codage){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_quelconque_aleatoire(codage, infixe, taille); 

    int *tab = codage;
    int res = construit_quelconque(a, &tab, taille);

    free(infixe);
    free(codage);
    return res;


}


int non_ABR_quelconque_alea(Arbre * a, int taille){
    int *infixe = malloc(taille * sizeof(int));
    if(!infixe)
        return 0;
    infixe[0] = rand() % 20;
    for (int i = 1; i < taille; i++){
        infixe[i] = infixe[i-1] + rand() % 10 + 1;
    }

    for (int i = taille - 1; i > 0; i--){
        int j = rand() % (i+1);
        int tmp = infixe[i];                           
        infixe[i] = infixe[j];
        infixe[j] = tmp;
    }

    int *codage = malloc((2*taille + 1) * sizeof(int));
    if(!codage){
        free(infixe);
        return 0;
    }

    parcours_infixe_2_prefixe_quelconque_aleatoire(codage, infixe, taille); 

    int *tab = codage;
    int res = construit_quelconque(a, &tab, taille);

    free(infixe);
    free(codage);
    return res;


}




void affiche_infixe(Arbre a){
    if(a == NULL) return;
    affiche_infixe(a->fg);
    printf("%d ", a->valeur);
    affiche_infixe(a->fd);
}

void libere_arbre(Arbre a){
    if(a == NULL) return;
    libere_arbre(a->fg);
    libere_arbre(a->fd);
    free(a);
}




