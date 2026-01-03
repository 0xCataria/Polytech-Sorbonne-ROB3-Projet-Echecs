#include "mouvement.h"
#include "coup.h"

int coup_invalide(int x, int y){
    return x < 0 || x > 7 || y < 0 || y > 7;
}

int type_mouvement_repete(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(coup_invalide(x,y)) return 0;

    if(plateau[x][y].c == c)
        return 0;

    if(plateau[x][y].p == VIDE){
        ajout(creer(x,y,0), l);
        return 1;
    }

    ajout(creer(x,y,1), l);
    return 0;
}

void type_mouvement_unique(int x, int y, Couleur c, Cell** plateau, Liste* l){
    if(coup_invalide(x,y)) return;
    if(plateau[x][y].c == c) return;

    ajout(creer(x,y, plateau[x][y].p != VIDE), l);
}

/* ===== PIECES ===== */

void mouvement_tour(int x, int y, Cell** plateau, Liste* l){
    Couleur c = plateau[x][y].c;

    for(int i=x-1;i>=0 && type_mouvement_repete(i,y,c,plateau,l);i--);
    for(int i=x+1;i<8  && type_mouvement_repete(i,y,c,plateau,l);i++);
    for(int j=y-1;j>=0 && type_mouvement_repete(x,j,c,plateau,l);j--);
    for(int j=y+1;j<8  && type_mouvement_repete(x,j,c,plateau,l);j++);
}

void mouvement_fou(int x, int y, Cell** plateau, Liste* l){
    Couleur c = plateau[x][y].c;

    for(int i=1;i<8 && type_mouvement_repete(x-i,y+i,c,plateau,l);i++);
    for(int i=1;i<8 && type_mouvement_repete(x+i,y+i,c,plateau,l);i++);
    for(int i=1;i<8 && type_mouvement_repete(x+i,y-i,c,plateau,l);i++);
    for(int i=1;i<8 && type_mouvement_repete(x-i,y-i,c,plateau,l);i++);
}

void mouvement_dame(int x, int y, Cell** plateau, Liste* l){
    mouvement_tour(x,y,plateau,l);
    mouvement_fou(x,y,plateau,l);
}

void mouvement_roi(int x, int y, Cell** plateau, Liste* l){
    Couleur c = plateau[x][y].c;
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++)
            if(dx||dy)
                type_mouvement_unique(x+dx,y+dy,c,plateau,l);
}

void mouvement_cavalier(int x, int y, Cell** plateau, Liste* l){
    Couleur c = plateau[x][y].c;
    int dx[]={2,2,-2,-2,1,1,-1,-1};
    int dy[]={1,-1,1,-1,2,-2,2,-2};

    for(int i=0;i<8;i++)
        type_mouvement_unique(x+dx[i],y+dy[i],c,plateau,l);
}

void mouvement_pion(int x, int y, Cell** plateau, Liste* l){
    Couleur c = plateau[x][y].c;
    int dir = (c == BLANC) ? -1 : 1;
    int start = (c == BLANC) ? 6 : 1;

    if(!coup_invalide(x+dir,y) && plateau[x+dir][y].p == VIDE){
        ajout(creer(x+dir,y,0), l);

        if(x == start && plateau[x+2*dir][y].p == VIDE)
            ajout(creer(x+2*dir,y,0), l);
    }

    for(int d=-1; d<=1; d+=2){
        if(!coup_invalide(x+dir,y+d)
        && plateau[x+dir][y+d].p != VIDE
        && plateau[x+dir][y+d].c != c)
            ajout(creer(x+dir,y+d,1), l);
    }
}