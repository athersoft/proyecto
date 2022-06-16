#ifndef GAME_H
#define GAME_H

struct player{
    int lvl;
    int hp;
    int hpMax;
    int atk;
    int def;
}

struct enemy{
    char name;
    int hp;
    int hpMax;
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
void showLvl(lvl *Lvl);

int movementX(char in);
int movementY(char in);

lvl initLvl();

#endif