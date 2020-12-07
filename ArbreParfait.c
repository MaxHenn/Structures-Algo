#include "ArbreParfait.h"

ArbreParfait initArbreParfait(int tailleMax, int tailleDonnee){
    ArbreParfait ap;
    ap.taille = 0;
    ap.tailleMax = tailleMax;
    ap.tailleDonnee = tailleDonnee;

    //on réserve toute la place nécéssaire pour le tableau
    ap.tab = malloc(tailleMax * tailleDonnee);
    return ap;
}

void libArbreParfait(ArbreParfait *ap){
    free((*ap).tab);
    ap->taille = 0;
    ap = NULL;
}


int tailleMaxArbreParfait(ArbreParfait ap){
    return ap.tailleMax;
}

int tailleArbreParfait(ArbreParfait ap){
    return ap.taille;
}

int tailleDonneeArbreParfait(ArbreParfait ap){
    return ap.tailleDonnee;
}


int estPleinArbreParfait(ArbreParfait ap){
    return ap.taille == ap.tailleMax;
}

int estVideArbreParfait(ArbreParfait ap){
    return ap.taille = 0;
}

int existeNoeudArbreParfait(int indice, ArbreParfait ap){
    return indice < tailleArbreParfait(ap);
}

int estFeuilleArbreParfait(int indice, ArbreParfait ap){
    return existeNoeudArbreParfait(indiceFgArbreParfait(indice), ap);
}


void* donneeArbreParfait(int indice, ArbreParfait ap){
    //on ne peut pas aller chercher la donnée comme dans un tableau normal,
    //vu que l'on a pas défini de type
    //on doit donc aller chercher le bloc mémoire selon ma taille de la donnée
    return ap.tab + (indice * ap.tailleDonnee);
}

int nombreNiveauxArbreParfait(ArbreParfait ap){
    return floor(2*log2l(tailleArbreParfait(ap)));
}

int indiceFgArbreParfait(int indice){
    return 2*indice + 1;
}

int indiceFdArbreParfait(int indice){
    return 2*indice + 2;
}

int pereArbreParfait(int indice){
    return (indice-1) / 2;
}


int inserEltArbreParfait(void* elt, ArbreParfait *a){
    if(estPleinArbreParfait(*a)){
        //on ne peut pas ajouter d'elt, renvoyer FAUX
        return 0;
    }else{
        //on ne peut pas mettre l'elt dans une case directement, ne connaissant pas
        //la taille des "blocs"
        int positionElt = tailleArbreParfait(*a) * tailleDonneeArbreParfait(*a);
        memcpy(a->tab + positionElt, elt, tailleDonneeArbreParfait(*a));
        a->taille = a->taille + 1;
        return 1;
    }
}

void afficherArbreParfait(ArbreParfait a, void(*afficher)(void* elt)){
    int cpt;
    int nd = 0;
    int seuil = 1;
    int nbNiveaux = nombreNiveauxArbreParfait(a);
    while(existeNoeudArbreParfait(nd, a)){
        cpt = 0;
        //mettre le premier noeud de la ligne à la bonne position
        while(cpt < seuil && existeNoeudArbreParfait(nd, a)){
            afficher(donneeArbreParfait(nd, a));
            printf("\t");
            cpt++;
            nd++;
        }
        printf("\n");
        seuil *= 2;
    }
}