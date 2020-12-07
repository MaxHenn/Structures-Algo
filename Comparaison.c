#include "Comparaison.h"


int comparerInt(void* a, void* b){
    int x = *(int*)a;
    int y = *(int*)b;
    if(x == y){
        return 0;
    }
    if(x > y){
        return 1;
    } 
    return -1;
}

int comparerFloat(void* a, void* b){
    float x = *(float*)a;
    float y = *(float*)b;
    if(x == y){
        return 0;
    }
    if(x > y){
        return 1;
    } 
    return -1;
}

int comparerDouble(void* a, void* b){
    double x = *(double*)a;
    double y = *(double*)b;
    if(x == y){
        return 0;
    }
    if(x > y){
        return 1;
    } 
    return -1;
}

int comparerChar(void* a, void* b){
    char x = *(char*)a;
    char y = *(char*)b;
    if(x == y){
        return 0;
    }
    if(x > y){
        return 1;
    } 
    return -1;
}