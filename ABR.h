#ifndef ABR_H
#define ABR_H
#include <stdlib.h>
#include <stdio.h>

typedef struct noeudABR{
    void* donnee;
    struct noeudABR *filsG;
    struct noeudABR *filsD;
}*ABR;

ABR initABR();

int estVideABR(ABR a);

ABR filsGaucheABR(ABR a);

ABR filsDroiteABR(ABR a);

void* donneeABR(ABR a);

ABR createNoeudABR(void *elt, unsigned int taille, ABR filsG, ABR filsD);

ABR createFeuilleABR(void *elt, unsigned int taille);

ABR inserEltABR(void *elt, unsigned int taille, ABR a, int(*comparer)(void* a, void* b));

//nécessite de faire passer en paramètre une fonction pour comparer (void Comparaison.h)
int estDansABR(void *elt, ABR a, int (*comparer)(void* a, void* b));

ABR minABR(ABR a);

ABR maxABR(ABR a);

void suppRacineABR(ABR *a);
#endif