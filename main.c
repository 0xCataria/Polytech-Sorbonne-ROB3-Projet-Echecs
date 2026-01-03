#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "Structures.h"
#include "Initialisation.h"
#include "coup.h"
#include "convertisseur.h"
#include "mouvement.h"
#include "affichage.h"

int main(){
    setlocale(LC_ALL, "");

    Cell** plateau = remplissage_plateau();

    Liste l;
    l.m = NULL;

    Couleur joueur = BLANC;   

    while(1){
        affichage_plateau(plateau);

        vider_liste(&l);

        printf("\nTour du joueur %s\n", joueur == BLANC ? "BLANC" : "NOIR");
        printf("Emplacement de la piece a jouer : ");

        char nota[3];
        scanf("%2s", nota);

        int x, y;
        convertisseur_coord(nota, &x, &y);

        if(plateau[x][y].p == VIDE){
            printf("Case vide.\n");
            continue;
        }

        if(plateau[x][y].c != joueur){
            printf("Ce n'est pas votre piece.\n");
            continue;
        }

        switch(plateau[x][y].p){
            case PION:     mouvement_pion(x,y,plateau,&l); break;
            case TOUR:     mouvement_tour(x,y,plateau,&l); break;
            case CAVALIER: mouvement_cavalier(x,y,plateau,&l); break;
            case FOU:      mouvement_fou(x,y,plateau,&l); break;
            case DAME:     mouvement_dame(x,y,plateau,&l); break;
            case ROI:      mouvement_roi(x,y,plateau,&l); break;
            default: break;
        }

        afficher_liste(&l);

        printf("Choisissez le coup : ");
        char dest[3];
        scanf("%2s", dest);

        int xbis, ybis;
        convertisseur_coord(dest, &xbis, &ybis);

        if(!coup_dans_liste(&l, xbis, ybis)){
            printf("Coup invalide.\n");
            continue;
        }

        plateau[xbis][ybis] = plateau[x][y];
        plateau[x][y].p = VIDE;
        plateau[x][y].c = COLORLESS;

        joueur = (joueur == BLANC) ? NOIR : BLANC;
    }

    return 0;
}
