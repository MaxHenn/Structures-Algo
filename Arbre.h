#ifndef ARBRE_H
#define ARBRE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct noeudArbre{
    void* donnee;
    struct noeudArbre *filsG;
    struct noeudArbre *filsD;
}*Arbre;

Arbre initArbre();

int estVideArbre(Arbre a);

int estFeuilleArbre(Arbre a);

Arbre filsGaucheArbre(Arbre a);

Arbre filsDroiteArbre(Arbre a);

void* donneeArbre(Arbre a);

Arbre createNoeudArbre(void *elt, unsigned int taille, Arbre filsG, Arbre filsD);

Arbre createFeuilleArbre(void *elt, unsigned int taille);

//nécessite de faire passer en paramètre une fonction pour comparer (void Comparaison.h)
int estDansArbre(void *elt, Arbre a, int(*comparer)(void* a, void* b));
#endif