#include "game.h"

square *createSquare(){
    square *Square = (square* ) malloc(sizeof(square));
    strcpy(Square -> type, "vacio");
    Square -> symbol = "0";
    Square -> colision = false;
}

lvl *createLevel(){
    lvl *Lvl = (lvl*) malloc(sizeof(lvl));
    Lvl -> height = 0;
    Lvl -> width = 0;
    Lvl -> posx = 0;
    Lvl -> posy = 0;
    for (int i = 0; i<100; i++){
        for (int j = 0; j<100, j++){
            Lvl -> map[i][j] = createSquare();
        }
    }
    return Lvl;
}

void showLvl(lvl *Lvl){
    for(int i = 0, i<Lvl -> width; i++){
        for(int j = 0; j< Lvl -> height; j++){
            printf("%c", lvl -> map[j][i]);
        }
        printf("\n");
    }
}