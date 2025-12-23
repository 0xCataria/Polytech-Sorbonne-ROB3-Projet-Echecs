#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"

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

struct liste{
    struct coup *m;
};
typedef struct liste Liste;

struct coup{
    //coordonnée x y du coup possible
    int x;
    int y;
    struct coup *m;
};
typedef struct coup Coup;

struct coup* creer(int X, int Y)
{
    Coup* new;
    new = (Coup*) malloc (sizeof(Coup));
    new -> x=X;
    new -> y=Y;
    new -> m=NULL;
    return(new);
}

void ajout(Coup* c, Liste* l){
    c -> m= (l -> m);
    l -> m=c;
}