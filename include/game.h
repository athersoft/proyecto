#ifndef GAME_H
#define GAME_H

struct casilla{
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
    casilla map[100][100];
};



#endif