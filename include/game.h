#ifndef GAME_H
#define GAME_H
#include <util.h>

typedef struct player{
    int lvl;
    int hp;
    int hpMax;
    int atk;
    int def;
}player;

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
    bool isText;
    char *text;
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

void updateLvl(lvl *Lvl);
void showLvl(lvl *Lvl);

int movementX(char in);
int movementY(char in);

lvl initLvl();

#endif