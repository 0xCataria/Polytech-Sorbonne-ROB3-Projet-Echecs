#ifndef INITIALISATION_H
#define INITIALISATION_H
#include "Structures.h"

Cell** init_plateau_vide();

Cell** remplissage_plateau();

void init_tour(Cell** plateau);

void init_cavalier(Cell** plateau);

void init_fou(Cell** plateau);

void init_dame(Cell** plateau);

void init_roi(Cell** plateau);

void init_pion(Cell** plateau);

void init_vide(Cell** plateau);

#endif