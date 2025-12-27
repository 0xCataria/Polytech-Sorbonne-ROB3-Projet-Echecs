#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"

//les pièces n'apparaisse pas de la bonne couleur à cause du terminal
//ce dernier fait en sorte de rendre le texte visible 
//donc pas de couleur foncer su un fond foncer et inversement
const char* affichage_piece(int x, int y, Cell** plateau){
    char piece = (plateau[x][y].p);
    char couleur_piece = (plateau[x][y].c);

    //printf("[%d,%d] :", piece, couleur_piece);

    if(piece == DAME){
        if(couleur_piece == NOIR) return("\033[30m Q ");
        else return("\033[97m Q ");
    }
    else if(piece == ROI){
        if(couleur_piece == NOIR) return("\033[30m K ");
        else return("\033[97m K ");
    }
    else if(piece == FOU){
        if(couleur_piece == NOIR) return("\033[30m B ");
        else return("\033[97m B ");
    }
    else if(piece == CAVALIER){
        if(couleur_piece == NOIR) return("\033[30m N ");
        else return("\033[97m N ");
    }
    else if(piece == TOUR){
        if(couleur_piece == NOIR) return("\033[30m R ");
        else return("\033[97m R ");
    }
    else if(piece == PION){
        if(couleur_piece == NOIR) return("\033[30m P ");
        else return("\033[97m P ");
    }
    else{
        return("   ");
    }
}

/* affichage avec les symboles
const char* affichage_piece(int x, int y, Cell** plateau){
    char piece = (plateau[x][y].p);
    char couleur_piece = (plateau[x][y].c);
    if(piece == DAME){
        if(couleur_piece == NOIR) return("\u265B");
        else return("\u2655");
    }
    else if(piece == ROI){
        if(couleur_piece == NOIR) return("\u265A");
        else return("\u2654");
    }
    else if(piece == FOU){
        if(couleur_piece == NOIR) return("\u265D");
        else return("\u2657");
    }
    else if(piece == CAVALIER){
        if(couleur_piece == NOIR) return("\u265E");
        else return("\u2657");
    }
    else if(piece == TOUR){
        if(couleur_piece == NOIR) return("\u265C");
        else return("\u2656");
    }
    else if(piece == PION){
        if(couleur_piece == NOIR) return("\u265F");
        else return("\u2659");
    }
    else{
        return(" ");
    }
}
*/
void cases(int x, int y, Cell** plateau, int id){
    // Couleur des cases
    const char *Fonce = "\033[48;5;130m"; 
    const char *Clair = "\033[48;5;215m";
    const char *reset = "\033[0m";
    const char *couleur[] = {Clair, Fonce};
    const char *p = affichage_piece(x,y,plateau);
    printf("%s%s%s", couleur[id%2], p, reset);
}

void affichage_plateau(Cell** plateau){
    int id = 0; //l'indice sert à inverser la couleur du fond des cases
    char colonne[] = {'a','b','c','d','e','f','g','h'};
    for (int i=0; i<8; i++){
        printf("%d ", 8-i); //numero ligne
        id++;
        for (int j=0; j<8; j++){
            cases(i,j,plateau,id);
            id ++;
        }
        printf("\n");
    }
    printf("  ");
    for (int k=0; k<8; k++) printf(" %c ",colonne[k]); // numero colonne
    printf("\n");
}

/*
| Pièce                   | Symbole | Code Unicode |
| ----------------------- | ------- | ------------ |
| Roi (white king)        | ♔       | "\u2654"     |
| Reine (white queen)     | ♕       | "\u2655"     |
| Tour (white rook)       | ♖       | "\u2656"     |
| Fou (white bishop)      | ♗       | "\u2657"     |
| Cavalier (white knight) | ♘       | "\u2658"     |
| Pion (white pawn)       | ♙       | "\u2659"     |


| Pièce                   | Symbole | Code Unicode |
| ----------------------- | ------- | ------------ |
| Roi (black king)        | ♚       | "\u265A"     |
| Reine (black queen)     | ♛       | "\u265B"     |
| Tour (black rook)       | ♜       | "\u265C"     |
| Fou (black bishop)      | ♝       | "\u265D"     |
| Cavalier (black knight) | ♞       | "\u265E"     |
| Pion (black pawn)       | ♟       | "\u265F"     |
*/