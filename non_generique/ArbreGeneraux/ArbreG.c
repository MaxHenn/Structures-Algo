#include "ArbreG.h"

int donneeArbreGenral(ArbreGeneral a){
    return a->donnee;
}

ArbreGeneral filsArbreGeneral(int indiceFils, ArbreGeneral a){
    return a->fils[indiceFils];
}

int estVideArbreGeneral(ArbreGeneral a){
    return a == NULL;
}

int estFeuilleArbreGeneral(int nbFils, ArbreGeneral a){
    for(int i = 0; i < nbFils; i++){
        if(!estVideArbreGeneral(filsArbreGeneral(i, a))){
            return 0;
        }
    }
    return 1;
}

ArbreGeneral initArbreGeneral(){
    return NULL;
}

ArbreGeneral createFeuilleArbreGeneral(int nbFils, int donnee){
    ArbreGeneral ag = (ArbreGeneral)malloc(sizeof(struct noeudAG));
    ag->donnee = donnee;
    ag->fils = (ArbreGeneral*)malloc(nbFils * sizeof(struct noeudAG));
    for(int i = 0; i < nbFils; i++){
        ag->fils[i] = initArbreGeneral();
    }
    return ag;
}

ArbreGeneral createNoeudArbreGeneral(int nbFils, ArbreGeneral *tabFils, int donnee){
    ArbreGeneral ag = (ArbreGeneral)malloc(sizeof(struct noeudAG));
    ag->donnee = donnee;
    ag->fils = (ArbreGeneral*)malloc(nbFils * sizeof(struct noeudAG));
    for(int i = 0; i < nbFils; i++){
        ag->fils[i] = tabFils[i];
    }
    return ag;
}

int degreNoeudArbreGeneral(int nbFils, ArbreGeneral a){
    int cpt = 0; 
    for(int i = 0; i < nbFils; i++){
        if(!estVideArbreGeneral(filsArbreGeneral(i, a))){
            cpt++;
        }
    }
    return cpt;
}

int degreArbreGeneral(int nbFils, ArbreGeneral a){
    if(estVideArbreGeneral(a) || estFeuilleArbreGeneral(nbFils, a)){
        return 0;
    }else{
        int degreMax = degreNoeudArbreGeneral(nbFils, a);
        for(int i = 0; i < nbFils; i++){
            int degreFils = degreArbreGeneral(nbFils, filsArbreGeneral(i, a));
            if(degreFils > degreMax){
                degreMax = degreFils;
            }
        }
        return degreMax;
    }
}

void afficherPrefixeArbreGeneral(int nbFils, ArbreGeneral a){
    if(!estVideArbreGeneral(a)){
        printf("%d\n", a->donnee);
        for(int i = 0; i < nbFils; i++){
            ArbreGeneral fils = filsArbreGeneral(i, a);
            afficherPrefixeArbreGeneral(nbFils, fils);
        }
    }
}