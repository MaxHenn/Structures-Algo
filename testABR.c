#include "ABR.h"
#include "Comparaison.h"

int puissanceInt(int base, int exposant);

void afficherABR(ABR a);

int main(){
    double vals[10] = {2.456, 8.932, 3.544, 0.00001, 12.345, 2.12, 3.44, 93.5};
    int nElts = 8;
    unsigned int doubleSize = sizeof(double);
    ABR abr = initABR();
    for(int i = 0; i < nElts; i++){
        abr = inserEltABR(&vals[i], doubleSize, abr, comparerDouble);
    }
    suppRacineABR(&abr);
    afficherABR(abr);
    return 0;
}

void affABRrec(ABR a, int espace){
    if(!estVideABR(a)){
        espace += 10; //valeur arbitraire, elle définit l'espace entre un noeud et ses fils

        //on affiche d'abord le sous-arbre de droite
        affABRrec(filsDroiteABR(a), espace);

        printf("\n");
        //on met l'espace nécéssaire
        for(int i = 0; i < espace; i++){
            printf(" ");
        }
        printf("%f\n", *(double*)(a->donnee));

        //on peut afficher le fils de gauche maintenant
        affABRrec(filsGaucheABR(a), espace);
    }
}

//affiche l'arbre de gauche à droite
void afficherABR(ABR abr){
    affABRrec(abr, 0);
}

int puissanceInt(int base, int exposant){
    int res = 1;
    while(exposant > 0){
        res *= base;
        exposant--;
    }
    return res;
}