#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "Structures.h"
#include "Initialisation.h"

const char* affichage_piece(int x, int y, Cell** plateau);

void cases(int x, int y, Cell** plateau, int id);

void affichage_plateau(Cell** plateau);



#endif