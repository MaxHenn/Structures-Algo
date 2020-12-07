#include "Pile.h"

int estVidePile(Pile p){
    return p.taille == 0;
}

int taillePile(Pile p){
    return p.taille;
}

//voit l'élément au sommet de la pile, mais ne l'enlève pas
void* donneePile(Pile p){
    return p.tete->donnee;
}

//=======Insertion & suppression=======
Pile initPile(){
    Pile p;
    p.taille = 0;
    p.tete = NULL;
    return p;
}

void empiler(void *elt, int taille, Pile *p){
    //création de la cellule de la pile
    EltPile eltPile = (EltPile)malloc(sizeof(struct celPile));
    EltPile tete = (*p).tete;

    eltPile->suivant = tete;
    eltPile->donnee = malloc(taille);
    for(int i = 0; i < taille; i++){
        *(char *)(eltPile->donnee + i) = *(char *)(elt + i);
    }

    //insertion dans la pile
    (*p).tete = eltPile;
    (*p).taille = taillePile(*p) + 1;
}

void depiler(Pile *p){
    if(!estVidePile(*p)){
        EltPile eltPile = (*p).tete;
        (*p).tete = (*p).tete->suivant;
        free(eltPile->donnee);
        free(eltPile);
        (*p).taille = taillePile(*p) - 1;
    }
    
}