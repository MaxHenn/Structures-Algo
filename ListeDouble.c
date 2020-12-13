#include "ListeDouble.h"

/*****************/
/*   FONCTIONS   */
/*****************/

ListeD initListeDouble() {
    return NULL;
}

ListeD createCelluleListeDouble() {
    ListeD cel;
    cel = (ListeD)malloc(sizeof(struct celListeDouble));
    return cel;
}

ListeD initEltListeDouble(void *elt, unsigned int taille) {
    ListeD cel;
    cel = createCelluleListeDouble();
    cel->precedent = NULL;
    cel->suivant = NULL;

    cel->donnee = malloc(taille);

    for(int i = 0; i < taille; i++){
        *(char *)(cel->donnee + i) = *(char *)(elt + i);
    }

    return cel;
}



TElement_ListeCD donneeListeDouble(ListeD ld){
    return ld->donnee;
}

ListeD precedentListeDouble(ListeD ld) {
    return ld->precedent;
}

ListeD suivantListeDouble(ListeD ld) {
    return ld->suivant;
}

_Bool estVideListeDouble(ListeD ld) {
    return ld == NULL;
}

ListeD premierListeDouble(ListeD ld) {
    ListeD prem = ld;
    while (!estVideListeDouble(precedentListeDouble(prem))) {
        prem = precedentListeDouble(prem);
    }
    return prem;
}

ListeD dernierListeDouble(ListeD ld) {
    ListeD der = ld;
    while (!estVideListeDouble(suivantListeDouble(der))) {
        der = suivantListeDouble(der);
    }
    return der;
}




void inserApresListeDouble(void* elt, unsigned int taille, ListeD *ld) {
    ListeD cel;
    cel = initEltListeDouble(elt, taille);
    if (estVideListeDouble(*ld)) {
        *ld = cel;
    }
    else {
        ListeD suiv = suivantListeDouble(*ld);
        if (!estVideListeDouble(suiv)) {
            suiv->precedent = cel;
        }
        cel->suivant = suiv;

        cel->precedent = *ld;
        (*ld)->suivant = cel;
    }
}

void inserAvantListeDouble(void* elt, unsigned int taille, ListeD *ld) {
    ListeD cel;
    cel = initEltListeDouble(elt, taille);
    if (estVideListeDouble(*ld)) {
        *ld = cel;
    }
    else {
        ListeD prec = precedentListeDouble(*ld);
        if (!estVideListeDouble(prec)) {
            prec->suivant = cel;
        }
        cel->precedent = prec;

        cel->suivant = *ld;
        (*ld)->precedent = cel;
    }
}

void inserTeteListeDouble(void* elt, unsigned int taille, ListeD *ld) {
    ListeD cel = premierListeDouble(*ld);
    inserAvantListeDouble(elt, taille, &cel);
    /*
    Si tu veux que l'adresse change pour rester toujours sur la tete
        *ld = cel;
    */
}

void inserQueueListeDouble(void* elt, unsigned int taille, ListeD *ld) {
    ListeD cel = dernierListeDouble(*ld);
    inserApresListeDouble(elt, taille, &cel);
}



void suppPrecListeDouble(ListeD *ld) {
    ListeD cel = precedentListeDouble(*ld);
    if (cel == *ld) {
        *ld = initListeDouble();
    }
    else {
        (*ld)->precedent = precedentListeDouble(cel);
    }
    free(cel);
}

void suppSuivListeDouble(ListeD *ld) {
    ListeD cel = suivantListeDouble(*ld);
    if (cel == *ld) {
        *ld = initListeDouble();
    }
    else {
        (*ld)->suivant = suivantListeDouble(cel);
    }
    free(cel);
}


void suppListCirDouble(ListeD *ld) {
    ListeD p;
    p = suivantListeDouble(*ld);
    while(p != *ld) {
        ListeD cel = p;
        p = suivantListeDouble(p);
        free(cel);
    }
    free(ld);
    *ld = initListeDouble();
}



void parcoursListeDoubleInt(ListeD ld) {
    if (!estVideListeDouble(ld)) {
        ListeD p;

        p = premierListeDouble(ld);
        printf("Parcours\n");

        while(!estVideListeDouble(p)) {
            afficheELtListeDoubleInt(p);
            p = suivantListeDouble(p);
        }
        printf("\nFin du parcours\n");
    }
    else {
        printf("Pas de Parcours\n");
    }
}



void afficheELtListeDoubleInt(ListeD ld){
    printf("%d ", *(int*)(donneeListeDouble(ld)));
}

void afficheEltListeDoubleFloat(ListeD ld){
    printf("%f ", *(float*)(donneeListeDouble(ld)));
}

void afficheEltListeDoubleDouble(ListeD ld){
    printf("%f ", *(double*)(donneeListeDouble(ld)));
}

void afficheEltListeDoubleChar(ListeD ld){
    printf("%c ", *(char*)(donneeListeDouble(ld)));
}


/*************/
/*   TESTS   */
/*************/

int mainListeDouble() {
    ListeD ld = initListeDouble();
    int elt[5] = {0, 1, 2, 3, 4};
    unsigned int tailleInt = sizeof(int);

    inserAvantListeDouble(&elt[3], tailleInt, &ld);
    inserAvantListeDouble(&elt[2], tailleInt, &ld);
    inserApresListeDouble(&elt[1], tailleInt, &ld);
    inserApresListeDouble(&elt[0], tailleInt, &ld);

    //je replace la liste au bon endroit
    ld = premierListeDouble(ld);
    parcoursListeDoubleInt(ld);

    ListeD suiv = suivantListeDouble(ld);

    suppPrecListeDouble(&suiv);
    inserAvantListeDouble(&elt[3], tailleInt, &suiv);

    ld = premierListeDouble(suiv);
    parcoursListeDoubleInt(ld);

    inserTeteListeDouble(&elt[0], tailleInt, &ld);
    inserQueueListeDouble(&elt[4], tailleInt, &ld);

    parcoursListeDoubleInt(ld);

    return 0;
}
