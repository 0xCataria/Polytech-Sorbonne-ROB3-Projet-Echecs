#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include "Structures.h"

int coup_invalide(int x, int y);

void mouvement_pion(int x, int y, Cell** plateau, Liste* l);
void mouvement_tour(int x, int y, Cell** plateau, Liste* l);
void mouvement_fou(int x, int y, Cell** plateau, Liste* l);
void mouvement_dame(int x, int y, Cell** plateau, Liste* l);
void mouvement_roi(int x, int y, Cell** plateau, Liste* l);
void mouvement_cavalier(int x, int y, Cell** plateau, Liste* l);

#endif
