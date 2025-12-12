#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"


Cell** init_plateau_vide(){
	Cell** plateau = (Cell**) malloc(8*sizeof(Cell*));
	assert(plateau!=NULL);
	for(int i = 0; i < 8;i++){
		plateau[i] = (Cell*) malloc(8*sizeof(Cell));
		assert(plateau[i]!=NULL);
	}
    return(plateau);
}

void remplissage_plateau(Cell** plateau){
    init_tour(plateau);
    init_cavalier(plateau);
    init_fou(plateau);
    init_dame(plateau);
    init_roi(plateau);
    init_pion(plateau);
}

void init_tour(Cell** plateau){
    plateau[0][0] -> p=TOUR;
    plateau[0][0] -> c=NOIR;

    plateau[0][7] -> p=TOUR;
    plateau[0][7] -> c=NOIR;

    plateau[7][0] -> p=TOUR;
    plateau[7][0] -> c=BLANC;

    plateau[7][7] -> p=TOUR;
    plateau[7][7] -> c=BLANC;
}

void init_cavalier(Cell** plateau){
    plateau[0][1] -> p=CAVALIER;
    plateau[0][1] -> c=NOIR;

    plateau[0][6] -> p=CAVALIER;
    plateau[0][6] -> c=NOIR;

    plateau[7][1] -> p=CAVALIER;
    plateau[7][1] -> c=BLANC;

    plateau[7][6] -> p=CAVALIER;
    plateau[7][6] -> c=BLANC;
}

void init_fou(Cell** plateau){
    plateau[0][2] -> p=FOU;
    plateau[0][2] -> c=NOIR;

    plateau[0][5] -> p=FOU;
    plateau[0][5] -> c=NOIR;

    plateau[7][2] -> p=FOU;
    plateau[7][2] -> c=BLANC;

    plateau[7][5] -> p=FOU;
    plateau[7][5] -> c=BLANC;
}

void init_dame(Cell** plateau){
    plateau[0][3] -> p=DAME;
    plateau[0][3] -> c=NOIR;

    plateau[7][3] -> p=DAME;
    plateau[7][3] -> c=BLANC;
}

void init_roi(Cell** plateau){
    plateau[0][4] -> p=ROI;
    plateau[0][4] -> c=NOIR;

    plateau[7][4] -> p=ROI;
    plateau[7][4] -> c=BLANC;
}

void init_pion(Cell** plateau){
    for (int i=0, i<8, i++){
        plateau[1][i] -> p=PION;
        plateau[1][i] -> c=NOIR;
    }
    for (int i=0, i<8, i++){
        plateau[6][i] -> p=PION;
        plateau[6][i] -> c=BLANC;
    }
}

void init_pion(Cell** plateau){
    for (int i=0, i<8, i++){
        for (int j=2, j<6, j++){
            plateau[1][i] -> p=PION;
            plateau[1][i] -> c=NOIR;
        }
    }
}
