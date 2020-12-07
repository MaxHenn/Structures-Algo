#include "Pile.h"

int main(){
    Pile p = initPile();
    double tab[10] = {2.3454, 2.342, 4.89, 3.899, 9.12};
    int nElts = 5;
    unsigned int doubleSize = sizeof(double);
    printf("Taille pile : %d\n", taillePile(p));
    for(int i = 0; i < nElts; i++){
        empiler(&tab[i], doubleSize, &p);
    }
    printf("Taille pile : %d\n", taillePile(p));

    while(!estVidePile(p)){
        double val = *(double*)donneePile(p);
        depiler(&p);
        printf("%f\n", val);
    }
    return 0;
}