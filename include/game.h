#ifndef GAME_H
#define GAME_H
#include <util.h>

typedef struct enemy{
    char name;
    int hp;
    int atk;
    int def;
}enemy;

typedef struct square{ //Casilla
    char *type;
    char symbol;
    //Color nfsfekfne
    bool colision;

}square;


typedef struct lvl{ 
    int height;
    int width;
    int posx;
    int posy;
    square *map[100][100];
}lvl;

lvl *createLvl();
square *createSquare();

void showLvl();

lvl initLvl();

#endif