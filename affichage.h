#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Structures.h"
#include "Initialisation.h"

#define MODE_ASCII   0
#define MODE_UNICODE 1

#define MODE_AFFICHAGE MODE_UNICODE

const char* affichage_piece(int x, int y, Cell** plateau);

void afficher_cases(int x, int y, Cell** plateau, int id);

void affichage_plateau(Cell** plateau);



#endif
