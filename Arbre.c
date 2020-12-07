#include "Arbre.h"

Arbre initArbre(){
    return NULL;
}

int estVideArbre(Arbre a){
    return a == NULL;
}

int estFeuilleArbre(Arbre a){
    return a->filsG == NULL && a->filsD == NULL;
}

int estFeuilleArbre(Arbre a){
    return estVideArbre(a->filsD) && estVideArbre(a->filsG);
}

Arbre filsGaucheArbre(Arbre a){
    return a->filsG;
}

Arbre filsDroiteArbre(Arbre a){
    return a->filsD;
}

void* donneeArbre(Arbre a){
    return a->donnee;
}

Arbre createNoeudArbre(void *elt, unsigned int taille, Arbre filsG, Arbre filsD){
    Arbre a = (Arbre)malloc(sizeof(struct noeudArbre));
    a->filsG = filsG;
    a->filsD = filsD;

    a->donnee = malloc(taille);
    for(int i = 0; i < taille; i++){
        *(char*)(a->donnee + i) = *(char*)(elt + i);
    }

    return a;
}

Arbre createFeuilleArbre(void *elt, unsigned int taille){
    return createNoeudArbre(elt, taille, NULL, NULL);
}

int estDansArbre(void *elt, Arbre a, int(*comparer)(void* a, void* b)){
    if(estVideArbre(a)){
        return 0;
    }else{
        if(comparer(elt, a->donnee) == 0){
            return 1;
        }else{
            int estDansArbreGauche = estDansArbre(elt, a->filsG, comparer);
            int estDansArbreDroite = estDansArbre(elt, a->filsD, comparer);
            return estDansArbreGauche || estDansArbreDroite;
        }
    }
}