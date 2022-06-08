#ifndef GAME_H
#define GAME_H

struct square{ //Casilla
    char *tipo;
    char simbolo;
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

lvl createLvl();
square createSquare();

void showLvl();

lvl initLvl();

#endif