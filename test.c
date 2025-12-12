#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum piece
{
VIDE, PION, TOUR, CAVALIER, FOU, REINE, ROI
};
typedef enum piece Piece;
enum couleur
{
BLANC, NOIR
};
typedef enum couleur Couleur;
struct cell
{
Piece p;
Couleur c;
};
typedef struct cell Cell;

void init_plateau_vide(){
	Cell** plateau = (Cell**) malloc(8*sizeof(Cell*));
	assert(plateau!=NULL);
	for(int i = 0; i < 8;i++){
		plateau[i] = (Cell*) malloc(8*sizeof(Cell));
		assert(plateau[i]!=NULL);
	}
}

int main(){
	init_plateau_vide();
	return EXIT_SUCCESS;
}
