#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include <time.h>
#include "map.h"

stats *createStats(){
    stats *Stats = (stats* ) malloc(sizeof(stats));
    Stats->kills = 0;
    Stats->maxLvl = 1;
    Stats->steps = 0;
    return Stats;
}

square *createSquare(){
    square *Square = (square* ) malloc(sizeof(square));
    Square -> type = (char *) malloc(sizeof(char)*20);
    strcpy(Square -> type, "vacio");
    Square -> symbol = '0';
    Square -> colision = false;
    Square -> isText = false;
    Square -> text = (char *) malloc(sizeof(char)*20);
    strcpy(Square -> text, "");
    Square -> Enemy = NULL;

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
    Lvl -> Player = createPlayer();
    return Lvl;
}

player *createPlayer(){
    player *Player = (player *) malloc(sizeof(player));
    Player -> lvl = 1;
    Player -> atk = 1;
    Player -> def = 1;
    Player -> exp = 0;
    Player -> expMax = 5;
    Player -> hpMax = 10;
    Player -> hp = 10;
    return Player;
}

enemy *createEnemy(lvl *Lvl){
    
    srand(time(NULL));
    player* jugador = Lvl -> Player;
    enemy *Enemy = (enemy *) malloc(sizeof(enemy));
    int valor = (jugador->lvl % 10) + (jugador->lvl /10);
    int numero;

    Enemy -> hp = 1;
    numero = rand() % jugador->hp;
    Enemy->hp = numero + valor;
    
    Enemy -> atk = 1;
    numero = rand() % jugador->atk;
    Enemy->hp = numero + valor;

    Enemy -> def = 0;
    numero = rand() % jugador->def;
    Enemy->hp = numero + valor;

    Enemy -> name = malloc(sizeof(char) * 20);
    strcpy(Enemy -> name, "Enemigo prueba");

    Enemy -> dead = false;

    return Enemy;
    
}

void showLvl(lvl *Lvl){
    
    //Mostrar camara
    for(int i = Lvl->posy-4; i<Lvl -> posy+4; i++){
        for(int j = Lvl->posx-7; j<Lvl->posx+7; j++){
            if(i >= Lvl -> height || j >= Lvl -> width){
                break;
            }
            if(i >= 0 && j >= 0){
                printf("%c", Lvl->map[i][j]->symbol);
            }
        }
        printf("\n");
    }
    

   /*
   //Descomentar para mostrar todo el mapa
    for(int i = 0; i < Lvl -> height; i++){
        for(int j = 0; j < Lvl -> width; j++){
            printf("%c", Lvl -> map[i][j] -> symbol);
        }
        printf("\n");
    }
    */
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
    Square -> symbol = 'X';
    strcpy(Square -> type, "colision");
    Square -> colision = true;

    return Square;
}

square *createSquareEnemy(lvl *Lvl){
    square *Square = createSquare();
    Square -> symbol = 'E';
    strcpy(Square -> type, "enemy");
    Square -> colision = true;
    Square -> Enemy = createEnemy(Lvl);

    return Square;
}
/*void combate(){

    if (enemy->def <= 0){
        enemy->hp = enemy->hp - player->atk;
    }
    
}*/
void initLvl(List *gameHistory, Map *bestiary){
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

    //Repartir obstaculos de forma aleatoria
    srand((unsigned) __TIME__);

    int x;
    int y;
    do{
        x = rand() % Lvl->width;
    }while(x >= Lvl -> width);

    do{
        y = rand() % Lvl->height;
    }while(y >= Lvl -> height);

    
    int reps = 0;
    reps = rand() % 100;

    for(int i = 0; i < reps; i++){
        while(1){
            if(strcmp(Lvl -> map[x][y] -> type, "vacio") == 0){
                Lvl -> map[x][y] = createObstacle();
                break;
            }else{
                do{
                    x = rand() % Lvl->width;
                }while(x >= Lvl -> width);

                do{
                    y = rand() % Lvl->height;
                }while(y >= Lvl -> height);
            }
        }
    }

    //Repartir enemigos de forma aleatoria

    x = rand() % Lvl->width-1;
    y = rand() % Lvl->height-1;
    
    reps = 0;
    reps = rand() % 20;

    for(int i = 0; i < reps; i++){
        while(1){
            if(strcmp(Lvl -> map[x][y] -> type, "vacio") == 0){
                Lvl -> map[x][y] = createSquareEnemy(Lvl);
                break;
            }else{
                do{
                    x = rand() % Lvl->width;
                }while(x >= Lvl -> width);

                do{
                    y = rand() % Lvl->height;
                }while(y >= Lvl -> height);
            }
        }
    }

    stats *Stats = createStats();
    showLvl(Lvl);
    updateLvl(Lvl, gameHistory, Stats, bestiary);
}

void updateLvl(lvl *Lvl, List *gameHistory, stats *Stats, Map *bestiary){
    char in = '\0';
    fflush(stdin);
    scanf("%c", &in);
    getchar();
    clrscr();

    //Movimiento jugador
    if(Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] -> colision == false){
        Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] = Lvl -> map[Lvl -> posy][Lvl -> posx];
        Lvl -> map[Lvl ->posy][Lvl ->posx] = createSquare();
        Lvl -> posx += movementX(in);
        Lvl -> posy += movementY(in);
    }

    //Ataque jugador
    if(in == 'e'){
        if(strcmp(Lvl -> map[Lvl ->posy+1][Lvl -> posx] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy+1][Lvl -> posx] -> Enemy -> hp -= (Lvl -> Player -> atk);
        }else if(strcmp(Lvl -> map[Lvl ->posy-1][Lvl -> posx] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy-1][Lvl -> posx] -> Enemy -> hp -= (Lvl -> Player -> atk);
        } else if(strcmp(Lvl -> map[Lvl ->posy][Lvl -> posx+1] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy][Lvl -> posx+1] -> Enemy -> hp -= (Lvl -> Player -> atk);
        }else if(strcmp(Lvl -> map[Lvl ->posy][Lvl -> posx-1] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy][Lvl -> posx-1] -> Enemy -> hp -= (Lvl -> Player -> atk);
        }
    }

    //Recorrer mapa para hacer comprobaciones
    for(int i = 0; i < Lvl -> height-1; i++){
        for(int j = 0; j < Lvl -> width-1; j++){
            //Comprobacion enemigos
            if(strcmp(Lvl -> map[i][j] -> type, "enemy") == 0){
                //Comprobar si sigue vivo
                if(Lvl -> map[i][j] -> Enemy -> hp <= 0){
                    Lvl -> map[i][j] = createSquare();
                }
            }
        }
    }

    //Si se igresa un 0 se termina la partida
    if(in != '0' && Lvl -> Player -> hp > 0){
        showLvl(Lvl);
        updateLvl(Lvl, gameHistory, Stats, bestiary);
    }else if(Lvl -> Player -> hp <= 0){
        listPushFront(gameHistory, Stats);
    }
}

