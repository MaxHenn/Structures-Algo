#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct celFile{
    void *donnee;
    struct celFile *suivant;
}*EltFile;

typedef struct{
    int taille;
    EltFile tete;
    EltFile queue;
}File;

int estVideFile(File f);

File initFile();

void* donneeFile(File f);

int tailleFile(File f);

void enfiler(void* elt, unsigned int taille, File *f);

void defiler(File *f);

#endif