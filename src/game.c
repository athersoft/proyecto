#include <stdio.h>
#include <string.h>
#include "game.h"

square *createSquare(){
    square *Square = (square* ) malloc(sizeof(square));
    Square -> type = (char *) malloc(sizeof(char)*10);
    strcpy(Square -> type, "vacio");
    Square -> symbol = '0';
    Square -> colision = false;
    Square -> isText = false;
    Square -> text = (char *) malloc(sizeof(char)*10);
    strcpy(Square -> text, "");
    return Square;
}

lvl *createLvl(){
    lvl *Lvl = (lvl*) malloc(sizeof(lvl));
    Lvl -> height = 50;
    Lvl -> width = 50;
    Lvl -> posx = 25;
    Lvl -> posy = 25;
    for (int i = 0; i<50; i++){
        for (int j = 0; j<50; j++){
            Lvl -> map[i][j] = createSquare();
        }
    }
    strcpy(Lvl -> map[Lvl -> posx][Lvl -> posy]->type, "player");
    Lvl -> map[Lvl -> posx][Lvl -> posy]->symbol = 'J';
    Lvl -> map[Lvl -> posx][Lvl -> posy]->colision = true;
    return Lvl;
}

void showLvl(lvl *Lvl){
    /*
    for(int i = Lvl->posy-4; i<Lvl -> posy+4; i++){
        for(int j = Lvl->posx-7; j<Lvl->posx+7; j++){
            if(i >= Lvl -> height || j >= Lvl -> width){
                break;
            }
            printf("%c", Lvl -> map[i][j] ->symbol);
        }
        printf("\n");
    }
    */

    for(int i = 0; i < Lvl -> height; i++){
        for(int j = 0; j < Lvl -> width; j++){
            printf("%c", Lvl -> map[i][j] -> symbol);
        }
        printf("\n");
    }
}

int movementX(char in){
    switch (in){
        case 'a':
            return -1;
        case 'd':
            return 1;
    }       
    return 0;
}

int movementY(char in){
    switch (in){
        case 'w':
            return -1;

        case 's':
            return 1;

    }       
    return 0;
}

square *createObstacle(){ //Crea un obstaculo estandar
    square *Square = createSquare();
    Square -> symbol = 'x';
    strcpy(Square -> type, "colision");
    Square -> colision = true;

    return Square;
}

void initLvl(){
    lvl *Lvl;
    Lvl = createLvl();

    //Generacion de bordes
    for(int i = 0; i < Lvl -> width; i++){ //Borde superior
        Lvl -> map[0][i] = createObstacle();
    }
    for(int i = 0; i < Lvl -> width; i++){ //Borde inferior
        Lvl -> map[Lvl ->height -1][i] = createObstacle();
    }
    for(int i = 0; i < Lvl -> width; i++){ //Borde izquierdo
        Lvl -> map[i][0] = createObstacle();
    }
    for(int i = 0; i < Lvl -> width; i++){ //Borde derecho
        Lvl -> map[i][Lvl ->width -1] = createObstacle();
    }
    
    showLvl(Lvl);
    updateLvl(Lvl);
}

void updateLvl(lvl *Lvl){
    char in = '\0';
    fflush(stdin);
    scanf("%c", &in);
    getchar();
    clrscr();

    if(Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] -> colision == false){
        Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] = Lvl -> map[Lvl -> posy][Lvl -> posx];
        Lvl -> map[Lvl ->posy][Lvl ->posx] = createSquare();
        Lvl -> posx += movementX(in);
        Lvl -> posy += movementY(in);
    }

    showLvl(Lvl);
    if(in != '0'){
        updateLvl(Lvl);
    }
}