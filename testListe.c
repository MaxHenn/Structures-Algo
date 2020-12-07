#include "Liste.h"
#define DIM 10

int main(){
    //test liste entiers
    Liste li = initListe();
    int elts[DIM] = {3, 8, 5, 14, 0};
    int nElts = 5;
    unsigned int tailleInt = sizeof(int);
    for(int i = 0; i < nElts; i++){
        inserTeteListe(&elts[i], tailleInt, &li);
    }
    while (!estVideListe(li))
    {
        afficheELtListeInt(li);
        suppTeteListe(&li);
    }
    printf("\n");

    //liste de réels 
    Liste lf = initListe();
    float tab[DIM] = {2.34, 23.89, 12.8, 5.55, 9};
    int nEltsF = 5;
    unsigned int tailleFloat = sizeof(float);
    for(int i = 0; i < nEltsF; i++){
        inserTeteListe(&tab[i], tailleFloat, &lf);
    }
    while(!estVideListe(lf)){
        afficheEltListeFloat(lf);
        suppTeteListe(&lf);
    }
    printf("\n");

    //liste de caractères
    Liste lc = initListe();
    char *string = "Salut poto";
    int nEtlsC = 10;
    unsigned int tailleChar = sizeof(char);
    for(int i = 0; i < nEtlsC; i++){
        inserTeteListe(&string[i], tailleChar, &lc);
    }
    while(!estVideListe(lc)){
        afficheEltListeChar(lc);
        suppTeteListe(&lc);
    }
    printf("\n");   
    return 0;
}