#ifndef ARBRE_G_H
#define ARBRE_G_H
#include <stdlib.h>
#include <stdio.h>

typedef struct noeudAG *ArbreGeneral;

struct noeudAG{
    int donnee;
    ArbreGeneral *fils; 
};

int donneeArbreGenral(ArbreGeneral a);
ArbreGeneral filsArbreGeneral(int indiceFils, ArbreGeneral a);
int estVideArbreGeneral(ArbreGeneral a);
int estFeuilleArbreGeneral(int nbFils, ArbreGeneral a);

ArbreGeneral initArbreGeneral();
ArbreGeneral createFeuilleArbreGeneral(int nbFils, int donnee);
ArbreGeneral createNoeudArbreGeneral(int nbFils, ArbreGeneral *tabFils, int donnee);

int degreNoeudArbreGeneral(int nbFils, ArbreGeneral a);
int degreArbreGeneral(int nbFils, ArbreGeneral a);

void afficherPrefixeArbreGeneral(int nbFils, ArbreGeneral a);

#endif