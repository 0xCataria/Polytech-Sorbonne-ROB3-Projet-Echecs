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

struct coup
{
int xFrom;
int yFrom;
int xTo;
int yTo;
} ;
typedef struct coup Coup;

struct partie
{
Cell** plateau;
Couleur joueur_actif;
};
typedef struct partie Partie;

#endif