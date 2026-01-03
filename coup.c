#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"
#include "convertisseur.h"
#include "mouvement.h"

//l'idee pour les coups serait d'utilisé les listes chainées

//Cela nous permettrait d'avoir un programme qui gère les mouvements classique
//puis un programme pôur les prises de pièces
//et plusieurs petit programme pour les coups spéciaux

//pour chaque mouvement/prise possible on aurait simplement à les ajouté à la chaine
//on pourra ensuite afficher cette chaine sur le plateau et au joueur
//le joueur ne pourra jouer une pièce que vers les cases appartenant à cette chaine

//pour l'affichage, j'ai penser à 2 types d'icone :
//   mouvement sur une case vide : on place un point vert sur celle ci
//   prise d'une pièce : on met la case derriere la piece en rouge

Coup* creer(int coup_X, int coup_Y, int P){
    Coup* new;
    new = (Coup*) malloc (sizeof(Coup));
    new->x=coup_X;
    new->y=coup_Y;
    new->prise=P;
    new->m=NULL;
    return(new);
}

void ajout(Coup* c, Liste* l){
    c->m= (l->m);
    l->m=c;
}

void vider_liste(Liste* l){
    Coup* ca = l->m;
    Coup* cb;

    while(ca != NULL){
        cb = ca->m;     
        free(ca);
        ca = cb;
    }
    l->m = NULL;
}


//faire les fonctions pour afficher les coups possibles
//pour cela on pourra faire une copie du plateau et la modifier

void afficher_liste(Liste *l){
    Coup *p = l->m;
    printf("Liste des coups possibles : \n");
    while( p != NULL)
        {
            char nota[3];
            convertisseur_notation(p, nota);
            printf("  %s  ", nota);
            p = p->m;
        }
    printf("\n");
}

int coup_dans_liste(Liste* l, int x, int y){
    Coup* cur = l->m;

    while(cur != NULL){
        if(cur->x == x && cur->y == y)
            return 1;
        cur = cur->m;   
    }
    return 0;
}


void coup_possible(int x, int y, Cell** plateau, Liste* l){
    if(plateau[x][y].p == VIDE) printf("Case vide, veuillez réessayer.\n");
    else if(plateau[x][y].p == PION) mouvement_pion(x,y,plateau,l);
    else if(plateau[x][y].p == TOUR) mouvement_tour(x,y,plateau,l);
    else if(plateau[x][y].p == CAVALIER) mouvement_cavalier(x,y,plateau,l);
    else if(plateau[x][y].p == FOU) mouvement_fou(x,y,plateau,l);
    else if(plateau[x][y].p == DAME) mouvement_dame(x,y,plateau,l);
    else if(plateau[x][y].p == ROI) mouvement_roi(x,y,plateau,l);
}