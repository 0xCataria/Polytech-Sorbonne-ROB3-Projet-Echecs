#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"

void convertisseur_notation(Coup* c, char notation[3]){
    char colonne[] = {'a','b','c','d','e','f','g','h'};

    char lettre = colonne[c->y];
    char numero = '8' - (c->x);

    notation[0] = lettre;
    notation[1] = numero;
    notation[2] = '\0';
}

void convertisseur_coord(char n[3], int* x, int* y){
    char lettre = n[0];
    char numero = n[1];
    char colonne[] = {'a','b','c','d','e','f','g','h'};

    *x = '8' - numero;
    for(int i=0; i<8; i++){
        if(colonne[i] == lettre){
            *y = i;
        }
    }
}