#ifndef COUP_H
#define COUP_H
#include "Structures.h"

Coup* creer(int X, int Y, int P);

void ajout(Coup* c, Liste* l);

void liberer_liste_coup(Liste* l);

void afficher_liste(Liste *l);

void coup_possible(int x, int y, Cell** plateau, Liste* l);

#endif