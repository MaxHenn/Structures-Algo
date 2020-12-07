#include "ArbreParfait.h"
#include "Afficher.h"

int main(){
    int tab[10] = {23, 45, 2, 12, 9, 4, 23, 0, 3, 6};
    int nElts = 10;
    
    ArbreParfait a = initArbreParfait(10, sizeof(int));
    for(int i = 0; i < nElts; i++){
        inserEltArbreParfait(&tab[i], &a);
    }
    afficherArbreParfait(a, afficherInt);
    libArbreParfait(&a);

    //test par utilisateur
    int tailleArbre;
    printf("\nTaille de l'arbre : ");
    scanf("%d", &tailleArbre);

    ArbreParfait ac = initArbreParfait(tailleArbre, sizeof(char));
    char *buffer = (char*)malloc(tailleArbre * sizeof(char));
    printf("Mot a mettre dans l'arbre (taille max : %d) : ", tailleArbre);
    scanf("%s", buffer);
    //insertion de la chaine de caractères
    int pos = 0;
    char c = buffer[pos];
    while(c != '\0'){
        inserEltArbreParfait(&c, &ac);
        pos++;
        c = buffer[pos];
    }
    afficherArbreParfait(ac, afficherChar);
    libArbreParfait(&ac);
    return 0;
}