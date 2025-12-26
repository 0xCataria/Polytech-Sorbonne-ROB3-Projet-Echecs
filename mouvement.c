#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"
#include "coup.h"

int type_mouvement_repete(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(c == plateau[x][y].c || c != COLORLESS) return 0;
    else{
        if(plateau[x][y].p == VIDE){
            Coup* coup = creer(x,y,0);
            ajout(coup,l);
            return(1);
        }
        else{
            Coup* coup = creer(x,y,1);
            ajout(coup,l);
            return(0);
        }
    }
}

void type_mouvement_unique(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(c != plateau[x][y].c && c != COLORLESS){
        if(plateau[x][y].p == VIDE){
            Coup* coup = creer(x,y,0);
            ajout(coup,l);
        }
        else{
            Coup* coup = creer(x,y,1);
            ajout(coup,l);
        }
    }
}

int coup_invalide(int x, int y){
    if(x<0 || x>7 || y<0 || y>7) return 1;
    else return 0;
}

void mouvement_tour(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    int x = coord_X;
    int y = coord_Y;
    int possible = 1;

    Couleur c = plateau[x][y].c;
    
    //Vers le haut
    while(possible == 1){
        x-=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Vers la droite
    while(possible == 1){
        y+=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Vers le bas
    while(possible == 1){
        x+=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Vers la gauche
    while(possible == 1){
        y-=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }
}

void mouvement_fou(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    int x = coord_X;
    int y = coord_Y;
    int possible = 1;

    Couleur c = plateau[x][y].c;

    //Haut-Droite
    while(possible == 1){
        y+=1;
        x-=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Bas-Droite
    while(possible == 1){
        y+=1;
        x+=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Bas-Gauche
    while(possible == 1){
        y-=1;
        x+=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }

    x = coord_X;
    y = coord_Y;
    possible = 1;

    //Haut-Gauche
    while(possible == 1){
        y-=1;
        x-=1;
        if(coup_invalide(x,y) == 1) possible = 0;
        possible = type_mouvement_repete(x,y,c,plateau,l);
    }
}

void mouvement_dame(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    mouvement_tour(coord_X,coord_Y,plateau,l);
    mouvement_fou(coord_X,coord_Y,plateau,l);
}

void mouvement_roi(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    int x = coord_X;
    int y = coord_Y;
    Couleur c = plateau[x][y].c;

    //8 positions possibles
    if(coup_invalide(x+1,y) == 0) type_mouvement_unique(x+1,y,c,plateau,l);
    if(coup_invalide(x-1,y) == 0) type_mouvement_unique(x-1,y,c,plateau,l);
    if(coup_invalide(x,y+1) == 0) type_mouvement_unique(x,y+1,c,plateau,l);
    if(coup_invalide(x,y-1) == 0) type_mouvement_unique(x,y-1,c,plateau,l);
    if(coup_invalide(x+1,y+1) == 0) type_mouvement_unique(x+1,y+1,c,plateau,l);
    if(coup_invalide(x+1,y-1) == 0) type_mouvement_unique(x+1,y-1,c,plateau,l);
    if(coup_invalide(x-1,y+1) == 0) type_mouvement_unique(x-1,y+1,c,plateau,l);
    if(coup_invalide(x-1,y-1) == 0) type_mouvement_unique(x-1,y-1,c,plateau,l);

    //pour le rock verifier si le roi a deja bouger
    //on pourra utiliser le systeme de sauvegarde des parties
    //il donne le detail de chauqe mouvement
}

void mouvement_cavalier(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    int x = coord_X;
    int y = coord_Y;
    Couleur c = plateau[x][y].c;

    //8 positions possibles
    if(coup_invalide(x+2,y+1) == 0) type_mouvement_unique(x+2,y+1,c,plateau,l);
    if(coup_invalide(x+2,y-1) == 0) type_mouvement_unique(x+2,y-1,c,plateau,l);
    if(coup_invalide(x-2,y+1) == 0) type_mouvement_unique(x-2,y+1,c,plateau,l);
    if(coup_invalide(x-2,y-1) == 0) type_mouvement_unique(x-2,y-1,c,plateau,l);
    if(coup_invalide(x+1,y+2) == 0) type_mouvement_unique(x+1,y+2,c,plateau,l);
    if(coup_invalide(x+1,y-2) == 0) type_mouvement_unique(x+1,y-2,c,plateau,l);
    if(coup_invalide(x-1,y+2) == 0) type_mouvement_unique(x-1,y+2,c,plateau,l);
    if(coup_invalide(x-1,y-2) == 0) type_mouvement_unique(x-1,y-2,c,plateau,l);
}

//Mouvement du pion

void saut_2_cases(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(coup_invalide(x,y) == 0 && plateau[x][y].p == VIDE){
        Coup* coup = creer(x,y,0);
        ajout(coup,l);
    }
}

void prise_pion(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(coup_invalide(x,y) == 0 ){
        if(plateau[x][y].p != VIDE && plateau[x][y].c != c){
            Coup* coup = creer(x,y,0);
            ajout(coup,l);
        }
    }
}

void mouvement_pion(int coord_X, int coord_Y, Cell** plateau, Liste* l){
    int x = coord_X;
    printf("x=%d\n",x);
    int y = coord_Y;
    printf("y=%d\n",y);
    Couleur c = plateau[x][y].c;
    printf("couleur=%d\n",c);

    //avancer
    if(c == BLANC){
        x-=1;
        if(coup_invalide(x,y) == 0 && plateau[x][y].p == VIDE){
            Coup* coup = creer(x,y,0);
            ajout(coup,l);
            saut_2_cases(x-1,y,c,plateau,l);
            prise_pion(x,coord_Y+1,c,plateau,l);
            prise_pion(x,coord_Y-1,c,plateau,l);
        }
    }
    if(c == NOIR){
        x+=1;
        if(coup_invalide(x,y) == 0 && plateau[x][y].p == VIDE){
            Coup* coup = creer(x,y,0);
            ajout(coup,l);
            saut_2_cases(x+1,y,c,plateau,l);
            prise_pion(x,coord_Y+1,c,plateau,l);
            prise_pion(x,coord_Y-1,c,plateau,l);
        }
    }

}

int main(){
    printf("coordonnée x : ");
    int x;
    scanf("%d",&x);
    printf("coordonnée y : ");
    int y;
    scanf("%d",&y);
    Cell** plateau = remplissage_plateau();
    Liste* l = (Liste*) malloc (sizeof(Liste));
    l->m = NULL;
    mouvement_cavalier(x,y,plateau,l);
    afficher_liste(l);
    liberer_liste_coup(l);
    return(0);
}
