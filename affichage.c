#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"
#include "Initialisation.h"

char affichage_piece(int x, int y, Cell** plateau){
    char piece = (plateau[x][y] -> p);
    char couleur_piece = (plateau[x][y] -> c);
    if(piece = DAME){
        if(couleur_piece = NOIR) return("\u265B");
        else return("\u2655");
    }
    else if(piece = ROI){
        if(couleur_piece = NOIR) return("\u265A");
        else return("\u2654");
    }
    else if(piece = FOU){
        if(couleur_piece = NOIR) return("\u265D");
        else return("\u2657");
    }
    else if(piece = CAVALIER){
        if(couleur_piece = NOIR) return("\u265E");
        else return("\u2657");
    }
    else if(piece = TOUR){
        if(couleur_piece = NOIR) return("\u265C");
        else return("\u2656");
    }
    else if(piece = PION){
        if(couleur_piece = NOIR) return("\u265F");
        else return("\u2659");
    }
    else if(piece = VIDE){
        return(' ');
    }
}

void case(int x, int y, Cell** plateau, int id){
    // Couleur des cases
    const char *Fonce = "\033[48;5;130m"; 
    const char *Clair = "\033[48;5;215m";
    const char *reset = "\033[0m";
    char couleur = {Fonce, Clair};
    char p = affichage_piece(x,y,plateau);
    printf("%s %c %s", couleur[id%2], p, reset);
}

void affichage_plateau(Cell** plateau){
    int id = 1; //l'indice sert à inverser la couleur du fond des cases
    char colonne[] = {'a','b','c','d','e','f','g','h'};
    for (int i=0, i<8, i++){
        printf("%d", i+1) //numero ligne
        id ++:
        for (int j=0, j<8, j++){
            case(i,j,plateau,id);
            id ++;
        }
    }
    for (int k=0, k<9, k++) printf("%c\t",colonne[k]); // numero colonne
}




int main() {
    Cell** plateau = remplissage_plateau();
    affichage_plateau(plateau);
}






/*
void afficher_carre() {
    const char *bg = "\033[47m";   // fond rouge
    const char *white = "\033[97m"; // texte blanc
    const char *black = "\033[30m"; // texte noir
    const char *reset = "\033[0m";

    printf("%s %sP%s %s", bg, black, bg, reset);
    printf("%s %sQ%s %s", bg, black, bg, reset);
    printf("%s %sK%s %s", bg, black, bg, reset);
    printf("%s %sB%s %s", bg, black, bg, reset);
    printf("%s %sN%s %s", bg, black, bg, reset);
    printf("%s %sR%s %s\n", bg, black, bg, reset);
    printf("%s %sP%s %s", bg, white, bg, reset);
    printf("%s %sQ%s %s", bg, white, bg, reset);
    printf("%s %sK%s %s", bg, white, bg, reset);
    printf("%s %sB%s %s", bg, white, bg, reset);
    printf("%s %sN%s %s", bg, white, bg, reset);
    printf("%s %sR%s %s\n", bg, white, bg, reset);


}

int main() {
    afficher_carre();
    return 0;
}


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