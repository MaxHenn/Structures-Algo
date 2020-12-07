#include "File.h"

int estVideFile(File f){
    return tailleFile(f) == 0;
}

File initFile(){
    File f;
    f.taille = 0;
    f.tete = 0; 
    f.queue = 0;
    return f;
}

//les données entrent par la queue de la file est partent par la tête

void* donneeFile(File f){
    return f.tete->donnee;
}

int tailleFile(File f){
    return f.taille;
}

void enfiler(void* elt, unsigned int taille, File *f){
    //création de l'élément 
    EltFile eltFile = (EltFile)malloc(sizeof(struct celFile));
    eltFile->donnee = malloc(taille);
    for(int i = 0; i < taille; i++){
        *(char *)(eltFile->donnee + i) = *(char *)(elt + i);
    }

    //si il n'y a pas encore d'éléments dans la file,
    //le nouvel élément est alors la tête ET la queue
    if(estVideFile(*f)){
        (*f).tete = eltFile;
        (*f).queue = eltFile;
    }else{
        (*f).queue->suivant = eltFile;
        (*f).queue = eltFile;
    }
    (*f).taille = tailleFile(*f) + 1;
}

void defiler(File *f){
    if(!estVideFile(*f)){
        EltFile tete = (*f).tete;
        (*f).tete = tete->suivant;
        free(tete->donnee);
        free(tete);
        (*f).taille = tailleFile(*f) - 1;
        //si il ne restait qu'un élément 
        if(estVideFile(*f)){
            (*f).queue = NULL;
        }
    }
}