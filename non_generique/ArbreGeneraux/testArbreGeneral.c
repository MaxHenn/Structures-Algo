#include "ArbreG.h"

int main(){
    //construction de l'arbre du TD
    
    //noeud 11
    int nbFils = 4;
    ArbreGeneral fils[4];
    fils[0] = createFeuilleArbreGeneral(nbFils, 0);
    fils[1] = createFeuilleArbreGeneral(nbFils, 4);
    for (int i = 2; i < nbFils; i++){
        fils[i] = initArbreGeneral();
    }
    ArbreGeneral n11 = createNoeudArbreGeneral(nbFils, fils, 11);
    
    //noeud 8
    fils[0] = n11;
    fils[1] = createFeuilleArbreGeneral(nbFils, 2);
    fils[2] = createFeuilleArbreGeneral(nbFils, 5);
    for (int i = 3; i < nbFils; i++){
        fils[i] = initArbreGeneral();
    }
    ArbreGeneral n8 = createNoeudArbreGeneral(nbFils, fils, 8);

    //noeud 3
    fils[0] = createFeuilleArbreGeneral(nbFils, -6);
    fils[1] = createFeuilleArbreGeneral(nbFils, 10);
    for (int i = 2; i < nbFils; i++){
        fils[i] = initArbreGeneral();
    }
    ArbreGeneral n3 = createNoeudArbreGeneral(nbFils, fils, 3);

    //racine
    fils[0] = n3;
    fils[1] = n8;
    fils[2] = createFeuilleArbreGeneral(nbFils, 9);
    for (int i = 3; i < nbFils; i++){
        fils[i] = initArbreGeneral();
    }
    ArbreGeneral ag = createNoeudArbreGeneral(nbFils, fils, 15);

    printf("affichage prefixe de l'arbre : \n");
    afficherPrefixeArbreGeneral(nbFils, ag);

    printf("degre du noeud 3 : %d\n", degreNoeudArbreGeneral(nbFils, n3));
    printf("degre de l'arbre : %d\n", degreArbreGeneral(nbFils, ag));
    return 0;
}