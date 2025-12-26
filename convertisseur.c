#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"
#include "coup.h"

char* convertisseur_notation(Coup* c){
    int x = c->x;
    int y = c->y;
    char colonne[] = {'a','b','c','d','e','f','g','h'};

    char lettre = colonne[y];
    char numero = '8' - x;
    char notation[3] = {lettre, numero, '\0'};

    return notation;
}

int convertisseur_coord(char* n[3]){
    char lettre = n[0];
    char numero = n[1];
    char colonne[] = {'a','b','c','d','e','f','g','h'};

    int x = '8' - numero;
    int y = 0;
    for(int i=0; i<8; i++){
        if(colonne[i] == lettre){
            y = i;
        }
    }

    return (x, y);
}