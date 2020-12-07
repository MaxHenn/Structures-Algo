#include "ABR.h"

ABR initABR(){
    return NULL;
}

int estVideABR(ABR a){
    return a == NULL;
}

int estFeuilleABR(ABR a){
    return estVideABR(a->filsD) && estVideABR(a->filsG);
}

ABR filsGaucheABR(ABR a){
    return a->filsG;
}

ABR filsDroiteABR(ABR a){
    return a->filsD;
}

void* donneeABR(ABR a){
    return a->donnee;
}

ABR createNoeudABR(void *elt, unsigned int taille, ABR filsG, ABR filsD){
    ABR a = (ABR)malloc(sizeof(struct noeudABR));
    a->filsG = filsG;
    a->filsD = filsD;

    a->donnee = malloc(taille);
    for(int i = 0; i < taille; i++){
        *(char*)(a->donnee + i) = *(char*)(elt + i);
    }

    return a;
}

ABR createFeuilleABR(void *elt, unsigned int taille){
    return createNoeudABR(elt, taille, NULL, NULL);
}

ABR inserEltABR(void *elt, unsigned int taille, ABR a, int(*comparer)(void* a, void* b)){
    //Recherche de l'élément
    if(estVideABR(a)){
        return createFeuilleABR(elt, taille);
    }else{
        //si elt <= donnee du noeud
        if(comparer(elt, donneeABR(a)) <= 0){
            a->filsG = inserEltABR(elt, taille, a->filsG, comparer);
        }else{
            a->filsD = inserEltABR(elt, taille, a->filsD, comparer);
        }
        return a;
    }
}

int estDansABR(void *elt, ABR a, int(*comparer)(void* a, void* b)){
    if(estVideABR(a)){
        return 0;
    }else{
        int comparaison = comparer(elt, a->donnee);
        //si les données sont égales
        if(comparaison == 0){
            return 1;
        }else{
            //si la donnée de gauche est plus petite que celle de droite, on va dans filsG
            if(comparaison < 0){
                return estDansABR(elt, a->filsG, comparer);
            }else{
                return estDansABR(elt, a->filsD, comparer);
            }
        }
    }
}

ABR minABR(ABR a){
    if(estVideABR(a)){
        return NULL;
    }else{
        if(estVideABR(a->filsG)){
            return a;
        }else{
            return minABR(a->filsG);
        }
    }
}

ABR maxABR(ABR a){
    if(estVideABR(a)){
        return NULL;
    }else{
        if(estVideABR(a->filsD)){
            return a;
        }else{
            return minABR(a->filsD);
        }
    }
}

void suppRacineABR(ABR *a){
    if(estFeuilleABR(*a)){
        free((*a)->donnee);
        free(*a);
        *a = NULL;
    }else{
        ABR aa = *a;
        ABR fg = filsGaucheABR(aa);
        ABR fd = filsDroiteABR(aa);
        if(estVideABR(fd)){
            *a = fg;
        }else{
            ABR minFd = minABR(fd);
            minFd->filsG = fg;
            *a = fd;
        }
        free(aa->donnee);
        free(aa);
    }
}