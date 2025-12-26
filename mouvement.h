#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include "Structures.h"

int type_mouvement_repete(int x, int y, Couleur c, Cell** plateau, Liste* l);

void type_mouvement_unique(int x, int y, Couleur c, Cell** plateau, Liste* l);

int coup_invalide(int x, int y);

void mouvement_tour(int coord_X, int coord_Y, Cell** plateau, Liste* l);

void mouvement_fou(int coord_X, int coord_Y, Cell** plateau, Liste* l);

void mouvement_dame(int coord_X, int coord_Y, Cell** plateau, Liste* l);

void mouvement_roi(int coord_X, int coord_Y, Cell** plateau, Liste* l);

void mouvement_cavalier(int coord_X, int coord_Y, Cell** plateau, Liste* l);

void saut_2_cases(int x, int y, Couleur c, Cell** plateau, Liste* l);

void prise_pion(int x, int y, Couleur c, Cell** plateau, Liste* l);

void mouvement_pion(int coord_X, int coord_Y, Cell** plateau, Liste* l);

#endif