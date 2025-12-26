#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"
#include "coup.h"
#include "convertisseur.h"
#include "mouvement.h"
#include "affichage.h"

int main(){
    int val = 0;

    Cell** plateau = remplissage_plateau();
    Liste* l = (Liste*) malloc (sizeof(Liste));
    l->m = NULL;

    while(val == 0){
        printf("emplacement de la piece a jouer : ");
        char nota[3];
        scanf("%s",nota);

        int x, y;
        convertisseur_coord(nota,&x,&y);

        if(plateau[x][y].p == VIDE) printf("Case vide, veuillez réessayer.\n");
        else if(plateau[x][y].p == PION) mouvement_pion(x,y,plateau,l);
        else if(plateau[x][y].p == TOUR) mouvement_tour(x,y,plateau,l);
        else if(plateau[x][y].p == CAVALIER) mouvement_cavalier(x,y,plateau,l);
        else if(plateau[x][y].p == FOU) mouvement_fou(x,y,plateau,l);
        else if(plateau[x][y].p == DAME) mouvement_dame(x,y,plateau,l);
        else if(plateau[x][y].p == ROI) mouvement_roi(x,y,plateau,l);

        afficher_liste(l);
        printf("\nChoisissez le coup que vous voulez jouer :");
        char c[3];
        scanf("%s",c);

        int xbis, ybis;
        convertisseur_coord(c,&xbis,&ybis);

        plateau[xbis][ybis] = plateau[x][y];
        plateau[x][y].p = VIDE;
        plateau[x][y].c = COLORLESS;
    }
    return(0);
}