#include "Arbre.h"
#include "Comparaison.h"

int main(){
    int vals[10] = {0, 1, 2, 3, 4, 5};
    unsigned int intSize = sizeof(int);
    Arbre a = createFeuilleArbre(&vals[0], intSize);
    Arbre a2 = createFeuilleArbre(&vals[1], intSize);
    Arbre a3 = createNoeudArbre(&vals[2], intSize, a, a2);

    printf("%d\n", *(int*)(a3->donnee));
    printf("%d %d\n", 
        *(int*)(donneeArbre(filsGaucheArbre(a3))),
        *(int*)(donneeArbre(filsDroiteArbre(a3)))
        );

    int dansArbre = estDansArbre(&vals[5], a3, comparerInt);
    printf("%d dans l'arbre : %s\n", vals[5], dansArbre ? "Vrai" : "Faux");
    int dansArbre2 = estDansArbre(&vals[1], a3, comparerInt);
    printf("%d dans l'arbre : %s\n", vals[1], dansArbre2 ? "Vrai" : "Faux");
    return 0;
}