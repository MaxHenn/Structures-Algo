#ifndef LISTE_DOUBLE_H
#define LISTE_DOUBLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Afficher.h"

typedef void* TElement_ListeCD;

typedef struct celListeDouble{
    TElement_ListeCD donnee;
    struct celListeDouble *suivant;
    struct celListeDouble *precedent;
} *ListeD;

/********************************/
/* INITIALISATION DES FONCTIONS */
/********************************/

//Cellule vide
ListeD initListeDouble();
//Cellule complete
ListeD createCelluleListeDouble();
ListeD initEltListeDouble(void *elt, unsigned int taille);

TElement_ListeCD donneeListeDouble(ListeD ld);
ListeD precedentListeDouble(ListeD ld);
ListeD suivantListeDouble(ListeD ld);
_Bool estVideListeDouble(ListeD ld);
ListeD dernierListeDouble(ListeD ld);

void inserApresListeDouble(void* elt, unsigned int taille, ListeD *ld);
void inserAvantListeDouble(void* elt, unsigned int taille, ListeD *ld);
void inserTeteListeDouble(void* elt, unsigned int taille, ListeD *ld);
void inserQueueListeDouble(void* elt, unsigned int taille, ListeD *ld);
void inserSelectListeDouble(void* elt, unsigned int taille, ListeD *ld, int n);

void suppPrecListeDouble(ListeD *ld);
void suppSuivListeDouble(ListeD *ld);
//void suppTeteListeDouble(ListeD *ld);
//void suppQueueListeDouble(ListeD *ld);
void suppSelectListeCD(ListeD *ld, int n);
void suppListeDouble(ListeD *ld);

//=======Affichage d'éléments précis=======

void afficheELtListeDoubleInt(ListeD ld);
void afficheEltListeDoubleFloat(ListeD ld);
void afficheEltListeDoubleDouble(ListeD ld);
void afficheEltListeDoubleChar(ListeD ld);

void parcoursListeDoubleInt(ListeD ld);

/****** MAIN *******/
int mainListeDouble();

#endif
