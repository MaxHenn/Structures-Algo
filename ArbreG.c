#include "ArbreG.h"

ArbreG initArbreG(){
    return NULL;
}

int estVideArbreG(ArbreG a){
    return a == NULL;
}

int existeFils(ArbreG a){
    return a->filsAine != NULL;
}

int existeFrere(ArbreG a){
    return a->frere != NULL;
}

int nombreFreres(ArbreG a){
    int cpt = 0;
    while(existeFrere(a)){
        cpt++;
        a = frereArbreG(a);
    }
    return cpt;
}

void* donneeArbreG(ArbreG a){
    return a->donnee;
}

ArbreG filsArbreG(ArbreG a){
    return a->filsAine;
}

ArbreG frereArbreG(ArbreG a){
    return a->frere;
}

ArbreG createFeuille(void *donnee, unsigned int taille){
    ArbreG a = (ArbreG)malloc(sizeof(struct noeudAG));
    a->donnee = malloc(taille);
    memcpy(a->donnee, donnee, taille);
    a->filsAine = NULL;
    a->frere = NULL;
}

void inserFrereArbreG(void *donnee, unsigned int taille, ArbreG *a){
    //on insère le frère tout à la fin
    if(existeFrere(*a)){
        ArbreG frere = frereArbreG(*a);
        while(existeFrere(frere)){
            frere = frereArbreG(frere);
        }
        //on ajoute le frère ici
        frere->frere = createFeuille(donnee, taille);
    }else{
        (*a)->frere = createFeuille(donnee, taille);
    }
}

void inserFilsArbreG(void *donnee, unsigned int taille, ArbreG *a){
    if(existeFils(*a)){
        ArbreG fils = filsArbreG(*a);
        while(existeFrere(fils)){
            fils = frereArbreG(fils);
        }
        //on ajoute le frère ici
        fils->frere = createFeuille(donnee, taille);
    }else{
        (*a)->filsAine = createFeuille(donnee, taille);
    }
}

void afficherArbreG(ArbreG a, void(*afficher)(void *elt)){
    while(!estVideArbreG(a)){
        afficher(donneeArbreG(a));
        printf("\n");
        afficherArbreG(filsArbreG(a), afficher);
        a = frereArbreG(a);
    }
}

void afficherNiveauxArbreG(ArbreG a, void(*afficher)(void* elt)){
    File f = initFile();
    unsigned int tailleArbreG = sizeof(struct noeudAG);
    //int nbNoeudsParNiveau = nombreFreres(a) + 1;
    //on enfile tous les frères
    while(!estVideArbreG(a)){
        enfiler(&a, tailleArbreG, &f);
        a = frereArbreG(a);
    }
    while(!estVideFile(f)){
        ArbreG ag = *(ArbreG*)donneeFile(f);
        defiler(&f);
        
        afficher(donneeArbreG(ag));
        printf(" ");
        if(!existeFrere(ag)){
            printf("\n");
        }
        //on insère tous les fils
        ArbreG fils = filsArbreG(ag);
        while(!estVideArbreG(fils)){
            enfiler(&fils, tailleArbreG, &f);
            fils = frereArbreG(fils);
        }
    }
}