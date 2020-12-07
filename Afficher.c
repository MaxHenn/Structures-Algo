#include "Afficher.h"

void afficherInt(void* elt){
    printf("%d", *(int*)elt);
}

void afficherLong(void* elt){
    printf("%ld", *(long*)elt);
}

void afficherFloat(void* elt){
    printf("%f", *(float*)elt);
}

void afficherDouble(void* elt){
    printf("%f", *(double*)elt);
}

void afficherChar(void* elt){
    printf("%c", *(char*)elt);
}

void afficherString(void *elt){
    printf("%s ", *(char**)elt);
}
