#ifndef GAME_H
#define GAME_H
#include <util.h>

typedef struct stats{
    int steps;
    int kills;
    int interaction;
    int hearts;
    int chests;
    int lvls;
    int maxLvl;
}stats;

typedef struct player{
    int lvl;
    int hp;
    int hpMax;
    int atk;
    int def;
    int exp;
    int expMax;
    int turnos;
    int otroturn;
}player;

typedef struct enemy{
    char* name;
    int hp;
    int hpMax;
    int atk;
    int def;
    int exp;
    bool jefe;
    bool dead;
    int deadCount;
}enemy;

typedef struct square{ //Casilla
    char *type;
    char symbol;
    bool marked;
    bool colision;
    bool isText;
    char *text;
    enemy *Enemy;
}square;


typedef struct lvl{ 
    int height;
    int width;
    int posx;
    int posy;
    bool jefes;
    int dificulty;
    player *Player;
    square *map[100][100];
}lvl;

stats *createStats();

lvl *createLvl();
void initLvl(List *gameHistory, int dificulty, player *Player,Map *bestiary);

square *createSquare();
square *createObstacle();

enemy *createEnemy(lvl *Lvl);

player *createPlayer();

void updateLvl(lvl *Lvl, List *gameHistory, stats *Stats,Map *bestiary);
void showLvl(lvl *Lvl, List *text);

void UpLvl(lvl* Lvl, square* Square);
void experiencia(lvl* LvL, square* Square);


int movementX(char in);
int movementY(char in);

void showHistory(List *gameHistory, int num);

void showStats(List *gameHistory);
void save(stats *Stats);

void saveBestiary(Map *bestiary);
void loadBestiary(Map *bestiary,lvl *Lvl);

#endif