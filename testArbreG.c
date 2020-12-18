#include "ArbreG.h"
#include "Afficher.h"

int main(){
    char c[27] = "abcdefghijklmnopqrstuvwxyzA";
    int nElts = 27;
    unsigned int tailleChar = sizeof(char);

    ArbreG a = createFeuille(&c[0], tailleChar);
    for(int i = 0; i < 26; i+= 3){
        inserFilsArbreG(&c[i], tailleChar, &a);
        inserFrereArbreG(&c[i+1], tailleChar, &a);
        inserFrereArbreG(&c[i+2], tailleChar, &a);
    }

    inserFilsArbreG(&c[12], tailleChar, &(a->filsAine));

    afficherNiveauxArbreG(a, afficherChar);

    return 0;
}