#ifndef COMPARAISON_H
#define COMPARAISON_H

/*
 * Soient deux nombres a et b
 * Chaque fonction de comparaison renvoie :
 *  -1 si a < b,
 *   1 si a > b,
 *   0 si a == b
 */ 

int comparerInt(void* a, void* b);

int comparerFloat(void* a, void* b);

int comparerDouble(void* a, void* b);

int comparerChar(void* a, void* b);

#endif