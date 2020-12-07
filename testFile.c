#include "File.h"

int main(){
    char *string = "Salut poto";
    int nElts = 10;
    unsigned int charSize = sizeof(char);

    File f = initFile();
    for(int i = 0; i < nElts; i++){
        enfiler(&string[i], charSize, &f);
        printf("Taille file : %d\n", tailleFile(f));
    }

    while(!estVideFile(f)){
        char c = *(char*)donneeFile(f);
        defiler(&f);
        printf("%c", c);
    }
    printf("\n");
}