#ifndef LISTE_H
#define LISTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    TYPE_ENTIER,
    TYPE_REEL,
    TYPE_CHAR,
    TYPE_STRING
}TypeListe;

typedef void *Elt_Liste;

typedef struct celListe{
    Elt_Liste donnee;
    struct celListe *suivant;
}*Liste;

//=======Primitives=======

Liste initListe();

void* donneeListe(Liste l);

Liste suivantListe(Liste l);

int estVideListe(Liste l);


//=======Création et insertion=======

Liste createCellule(void *elt, unsigned int taille);

void inserTeteListe(void* elt, unsigned int taille, Liste *l);

void suppTeteListe(Liste *l);


//=======Affichage d'éléments précis=======

void afficheELtListeInt(Liste l);

void afficheEltListeFloat(Liste l);

void afficheEltListeDouble(Liste l);

void afficheEltListeChar(Liste l);

#endif