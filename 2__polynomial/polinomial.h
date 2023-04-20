#ifndef POLINOMIAL_H
#define POLINOMIAL_H
#include <stdlib.h>
#include "./doublylist.h"

// Assuming that coefArr starts from coef of max degree
DoublyList *createPolinomial(int *coefArr, int maxDegree);

// Assunming that poliList starts from max degree
void addPolinomial(DoublyList *target, DoublyList *toAdd);

#endif