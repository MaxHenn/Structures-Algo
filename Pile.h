#ifndef PILE_H
#define PILE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct celPile{
    void *donnee;
    struct celPile *suivant;
}*EltPile;

typedef struct{
    int taille;
    EltPile tete;
}Pile;


//=======Primitives=======
int estVidePile(Pile p);

int taillePile(Pile p);

//voit l'élément au sommet de la pile, mais ne l'enlève pas
void* donneePile(Pile p);

//=======Insertion & suppression=======
Pile initPile();

void empiler(void *elt, int taille, Pile *p);

void depiler(Pile *p);

#endif