#ifndef STRUCTURES_H
#define STRUCTURES_H

enum piece
{
VIDE, PION, TOUR, CAVALIER, FOU, DAME, ROI
};
typedef enum piece Piece;

enum couleur
{
BLANC, NOIR, COLORLESS
};
typedef enum couleur Couleur;

struct cell
{
Piece p;
Couleur c;
} ;
typedef struct cell Cell;

struct coup{
    //coordonnée x y du coup possible
    int x;
    int y;

    //1 signifie que c'est une prise, 0 un mouvement
    int prise;

    struct coup *m;
};
typedef struct coup Coup;

struct liste{
    Coup *m;
};
typedef struct liste Liste;

struct partie
{
Cell** plateau;
Couleur joueur_actif;
};
typedef struct partie Partie;

#endif