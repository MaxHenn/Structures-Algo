#ifndef ARBRE_G_H
#define ARBRE_G_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "File.h"

typedef struct noeudAG *ArbreG;

struct noeudAG{
    void* donnee;
    ArbreG filsAine;
    ArbreG frere;
    //ArbreG pere; //optionnel
};

ArbreG initArbreG();
int estVideArbreG(ArbreG a);
int existeFils(ArbreG a);
int existeFrere(ArbreG a);
int nombreFreres(ArbreG a);
void* donneeArbreG(ArbreG a);
ArbreG filsArbreG(ArbreG a);
ArbreG frereArbreG(ArbreG a);
ArbreG createFeuille(void *donnee, unsigned int taille);

void inserFrereArbreG(void *donnee, unsigned int taille, ArbreG *a);
void inserFilsArbreG(void *donnee, unsigned int taille, ArbreG *a);

void afficherArbreG(ArbreG a, void(*afficher)(void *elt));
void afficherNiveauxArbreG(ArbreG a, void(*afficher)(void* elt));

#endif