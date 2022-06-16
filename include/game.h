#ifndef GAME_H
#define GAME_H

struct enemy{
    char name;
    int hp;
    int atk;
    int def;
}

struct square{ //Casilla
    char *type;
    char symbol;
    //Color nfsfekfne
    bool colision;

}

struct lvl{ 
    int height;
    int width;
    int posx;
    int posy;
    square map[100][100];
};

lvl *createLvl();
square *createSquare();

void updateLvl();
void showLvl();

lvl initLvl();

#endif