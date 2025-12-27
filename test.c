#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Structures.h"
#include "coup.h"
#include "convertisseur.h"
#include "mouvement.h"
#include "affichage.h"

void init_tour(Cell** plateau){
    plateau[4][4].p=TOUR;
    plateau[4][4].c=NOIR;
}

void init_cavalier(Cell** plateau){
    plateau[4][3].p=CAVALIER;
    plateau[4][3].c=BLANC;

    //plateau[6][2].p=CAVALIER;
    //plateau[6][2].c=NOIR;

    plateau[4][1].p=CAVALIER;
    plateau[4][1].c=BLANC;
}

void init_fou(Cell** plateau){
    plateau[4][4].p=FOU;
    plateau[4][4].c=NOIR;
}

void init_dame(Cell** plateau){
    plateau[4][4].p=DAME;
    plateau[4][4].c=NOIR;
}

void init_roi(Cell** plateau){
    plateau[0][4].p=ROI;
    plateau[0][4].c=NOIR;

    plateau[7][4].p=ROI;
    plateau[7][4].c=BLANC;
}

void init_pion(Cell** plateau){
    for (int i=0; i<8; i++){
        plateau[1][i].p=PION;
        plateau[1][i].c=NOIR;
    }
    for (int i=0; i<8; i++){
        plateau[6][i].p=PION;
        plateau[6][i].c=BLANC;
    }
}

void init_vide(Cell** plateau){
    for (int i=2; i<6; i++){
        for (int j=0; j<8; j++){
            plateau[i][j].p=VIDE;
            plateau[i][j].c=COLORLESS;
        }
    }
}

Cell** init_plateau_vide(){
	Cell** plateau = (Cell**) malloc(8*sizeof(Cell*));
	assert(plateau!=NULL);
	for(int i = 0; i < 8;i++){
		plateau[i] = (Cell*) malloc(8*sizeof(Cell));
		assert(plateau[i]!=NULL);
	}
    return(plateau);
}

Cell** remplissage_plateau(){
    Cell** plateau = init_plateau_vide();
    init_cavalier(plateau);
    return(plateau);
}

int main(){
    int val = 0;

    Cell** plateau = remplissage_plateau();
    Liste* l = (Liste*) malloc (sizeof(Liste));
    l->m = NULL;
    affichage_plateau(plateau);

    while(val == 0){
        printf("0 pour continuer :");
        scanf("%d",&val);

        printf("emplacement de la piece a jouer : ");
        char nota[3];
        scanf("%s",nota);

        int x, y;
        convertisseur_coord(nota,&x,&y);

        coup_possible(x,y,plateau,l);
        afficher_liste(l);
        liberer_liste_coup(l);
        /*
        printf("\nChoisissez le coup que vous voulez jouer :");
        char c[3];
        scanf("%s",c);

        int xbis, ybis;
        convertisseur_coord(c,&xbis,&ybis);

        plateau[xbis][ybis] = plateau[x][y];
        plateau[x][y].p = VIDE;
        plateau[x][y].c = COLORLESS;
        */
    }
    return(0);
}