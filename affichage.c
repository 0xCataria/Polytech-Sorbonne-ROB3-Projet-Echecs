#include <stdio.h>
#include <stdlib.h>
#include "Structures.h"

//void case()

//faire une boucle qui parcourt le tableau
//pour chaque ligne faire une boucle qui va changer la couleur de chaque case adjacente 
//(on initialisera la couleur d'une case dans une liste et on def un id qu'on incr de 1 à chauqe case mod(2))
//des qu'on passe à une ligne diffenrente on ajoute 1 à l'id

void affichage_plateau(Cell** plateau){
    //faire une liste avec brown et beige
    const char *brown = "\033[48;5;130m";   // marron chocolat
    const char *beige = "\033[48;5;215m";  // beige très clair
    for (int i=0, i<8, i++){
        for (int j=0, j<8, j++){
            Piece *p = (plateau[i][j] -> p)
            char icone = def_icone(p);
            printf("")
        }
    }
}




int main() {
    const char *brown = "\033[48;5;94m";
    const char *beige = "\033[48;5;230m";
    const char *reset = "\033[0m";

    // Ligne type d'échiquier
    printf("%s \u2654 %s%s B %s\n%s   %s%s A     %s%s     %s\n",
           brown, reset,
           beige, reset,
           brown, reset,
           beige, reset,
           brown, reset);

    return 0;
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
| Roi (white king)        | ♔       | `\u2654`     |
| Reine (white queen)     | ♕       | `\u2655`     |
| Tour (white rook)       | ♖       | `\u2656`     |
| Fou (white bishop)      | ♗       | `\u2657`     |
| Cavalier (white knight) | ♘       | `\u2658`     |
| Pion (white pawn)       | ♙       | `\u2659`     |


| Pièce                   | Symbole | Code Unicode |
| ----------------------- | ------- | ------------ |
| Roi (black king)        | ♚       | `\u265A`     |
| Reine (black queen)     | ♛       | `\u265B`     |
| Tour (black rook)       | ♜       | `\u265C`     |
| Fou (black bishop)      | ♝       | `\u265D`     |
| Cavalier (black knight) | ♞       | `\u265E`     |
| Pion (black pawn)       | ♟       | `\u265F`     |
*/