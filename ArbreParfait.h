#ifndef ARBRE_PARFAIT_H
#define ARBRE_PARFAIT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct{
    int tailleMax;
    int taille;
    int tailleDonnee;
    void* *tab;
}ArbreParfait;

ArbreParfait initArbreParfait(int tailleMax, int tailleDonnee);
void libArbreParfait(ArbreParfait *ap);

int tailleMaxArbreParfait(ArbreParfait ap);
int tailleArbreParfait(ArbreParfait ap);
int tailleDonneeArbreParfait(ArbreParfait ap);

int estPleinArbreParfait(ArbreParfait ap);
int estVideArbreParfait(ArbreParfait ap);
int existeNoeudArbreParfait(int indice, ArbreParfait ap);
int estFeuilleArbreParfait(int indice, ArbreParfait ap);

void* donneeArbreParfait(int indice, ArbreParfait ap);
int nombreNiveauxArbreParfait(ArbreParfait ap);
int indiceFgArbreParfait(int indice);
int indiceFdArbreParfait(int indice);
int pereArbreParfait(int indice);

int inserEltArbreParfait(void* elt, ArbreParfait *a);

void afficherArbreParfait(ArbreParfait a, void(*afficher)(void* elt));

#endif