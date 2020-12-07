#include "Liste.h"

Liste initListe(){
    return NULL;
}

Liste createCellule(void *elt, unsigned int taille){
    Liste cel = (Liste)malloc(sizeof(struct celListe));
    cel->suivant = NULL;
    cel->donnee = malloc(taille);

    //on copie le contenu de elt dans cel->donnee
    //on utilise 'char' car c'est le type le plus petit possible
    //sizeof(char) < sizeof(...)
    for(int i = 0; i < taille; i++){
        *(char *)(cel->donnee + i) = *(char *)(elt + i);
    }

    return cel;
}

void* donneeListe(Liste l){
    return l->donnee;
}

Liste suivantListe(Liste l){
    return l->suivant;
}

int estVideListe(Liste l){
    return l == NULL;
}

void inserTeteListe(void* elt, unsigned int taille, Liste *l){
    Liste cel = createCellule(elt, taille);
    cel->suivant = *l;
    *l = cel;
}

void suppTeteListe(Liste *l){
    if(!estVideListe(*l)){
        Liste tete = *l;
        *l = suivantListe(*l);
        //il faut libérer la mémoire de la donnée aussi
        free(tete->donnee);
        free(tete);
    }
}

void afficheELtListeInt(Liste l){
    printf("%d ", *(int*)(l->donnee));
}

void afficheEltListeFloat(Liste l){
    printf("%f ", *(float*)(l->donnee));
}

void afficheEltListeDouble(Liste l){
    printf("%f ", *(double*)(l->donnee));
}

void afficheEltListeChar(Liste l){
    printf("%c ", *(char*)(l->donnee));
}