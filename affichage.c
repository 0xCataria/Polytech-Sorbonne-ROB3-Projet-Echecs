#include <stdio.h>
#include <wchar.h>
#include "Structures.h"

#define FONCE "\033[48;5;130m"
#define CLAIR "\033[48;5;215m"
#define RESET "\033[0m"


wchar_t affichage_piece(char piece, char couleur){
#if MODE_AFFICHAGE == MODE_UNICODE
    if(couleur == BLANC){
        switch(piece){
            case ROI: return L'♔';
            case DAME: return L'♕';
            case TOUR: return L'♖';
            case FOU: return L'♗';
            case CAVALIER: return L'♘';
            case PION: return L'♙';
        }
    } else {
        switch(piece){
            case ROI: return L'♚';
            case DAME: return L'♛';
            case TOUR: return L'♜';
            case FOU: return L'♝';
            case CAVALIER: return L'♞';
            case PION: return L'♟';
        }
    }
    return L'·';
#else
    switch(piece){
        case ROI: return L'K';
        case DAME: return L'Q';
        case TOUR: return L'R';
        case FOU: return L'B';
        case CAVALIER: return L'N';
        case PION: return L'P';
    }
    return L'·';    
#endif
}

void afficher_case(int x, int y, Cell** plateau, int id){
    const char* fond = (id % 2 == 0) ? CLAIR : FONCE;
    wchar_t p = affichage_piece(plateau[x][y].p, plateau[x][y].c);

    printf("%s %lc %s", fond, p, RESET);
}

void affichage_plateau(Cell** plateau){
    char col[] = {'a','b','c','d','e','f','g','h'};
    int id = 0;

    for(int i = 0; i < 8; i++){
        printf("%d ", 8 - i);
        id++;

        for(int j = 0; j < 8; j++){
            afficher_case(i, j, plateau, id++);
        }
        printf("\n");
    }

    printf("  ");
    for(int i = 0; i < 8; i++)
        printf(" %c ", col[i]);
    printf("\n");
}
