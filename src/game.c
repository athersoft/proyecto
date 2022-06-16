#include "game.h"

square *createSquare(){
    square *Square = (square* ) malloc(sizeof(square));
    strcpy(Square -> type, "vacio");
    Square -> symbol = '0';
    Square -> colision = false;
    return Square;
}

lvl *createLevel(){
    lvl *Lvl = (lvl*) malloc(sizeof(lvl));
    Lvl -> height = 0;
    Lvl -> width = 0;
    Lvl -> posx = 0;
    Lvl -> posy = 0;
    for (int i = 0; i<100; i++){
        for (int j = 0; j<100; j++){
            Lvl -> map[i][j] = createSquare();
        }
    }
    return Lvl;
}

void showLvl(lvl *Lvl){
    for(int i = 0; i<Lvl -> width; i++){
        for(int j = 0; j< Lvl -> height; j++){
            printf("%c", Lvl -> map[j][i] ->symbol);
        }
        printf("\n");
    }
}

int movementX(char in){
    switch (in){
        case 'A':
            return -1;
        case 'D':
            return 1;
    }       
    return 0;
}

int movementY(char in){
    switch (in){
        case 'W':
            return -1;

        case 'S':
            return 1;

    }       
    return 0;
}

void updateLvl(lvl *Lvl){
    char in = '\0';
    fflush(stdin);
    scanf("%c", &in);
    getchar();

    Lvl -> map[Lvl -> posx + movementX(in)][Lvl -> posy + movementY(in)] = Lvl -> map[Lvl -> posx][Lvl ->posy];
    Lvl -> map[Lvl ->posx][Lvl ->posy] = createSquare();
    Lvl -> posx += movementX(in);
    Lvl -> posy += movementY(in);
}