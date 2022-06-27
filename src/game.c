#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "menu.h"
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

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
    Square -> symbol = '=';
    Square -> colision = false;
    Square -> isText = false;
    Square -> text = (char *) malloc(sizeof(char)*20);
    strcpy(Square -> text, "");
    Square -> Enemy = NULL;
    Square -> marked = false;

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
    Player->turnos = 0;
    Player->otroturn = 0;
    return Player;
}

enemy* createBoss(lvl* Lvl){
    enemy* jefe = (enemy*) malloc(sizeof(enemy));
    int valor;
    if(Lvl->Player->lvl <=9){
        valor = 5;
    }else{
        valor = (Lvl -> Player->lvl % 10) + (Lvl -> Player->lvl /10);
    }
    //int numero;

    jefe->hpMax =  Lvl->Player->hpMax + valor;
    jefe->hp = jefe->hpMax;

    jefe->atk = Lvl->Player->atk + valor;

    jefe->def = Lvl->Player->def + valor;

    jefe->exp = Lvl->Player->expMax;
    jefe->name = malloc(sizeof(char) * 20);
    return jefe;
}

enemy *createEnemy(lvl *Lvl){
    
    srand(time(NULL));
    //player* jugador = Lvl -> Player;
    enemy *Enemy = (enemy *) malloc(sizeof(enemy));
    int valor = (Lvl -> Player->lvl % 10) + (Lvl -> Player->lvl /10);
    int numero;

    //Enemy -> hp = 1;
    numero = (rand() % (Lvl -> Player->hp)/2) + 1;
    Enemy->hpMax = numero + valor;
    Enemy->hp = Enemy->hpMax;
    
    //Enemy -> atk = 1;
    numero = (rand() % Lvl -> Player->atk) + 1;
    Enemy->atk = numero + valor;

    //Enemy -> def = 0;
    numero = (rand() % Lvl -> Player->def) + 1;
    Enemy->def = numero + valor;

    Enemy->exp = (rand() % Lvl -> Player->expMax) - 2;
    if(Enemy->exp <= 0){
        Enemy->exp = 1;
    }
    Enemy -> name = malloc(sizeof(char) * 20);
    //strcpy(Enemy -> name, "Enemigo prueba");

    Enemy -> dead = false;

    return Enemy;
    
}

/*void showLvl(lvl *Lvl){
    
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
    */

   /*
   //Descomentar para mostrar todo el mapa
    for(int i = 0; i < Lvl -> height; i++){
        for(int j = 0; j < Lvl -> width; j++){
            printf("%c", Lvl -> map[i][j] -> symbol);
        }
        printf("\n");
    }
    */
//}
void showLvl(lvl *Lvl, List *text){
    system("cls");
    //Mostrar camara
    for(int i = Lvl->posy-4; i<Lvl -> posy+4; i++){
        for(int j = Lvl->posx-7; j<Lvl->posx+7; j++){
            if(i >= Lvl -> height || j >= Lvl -> width){
                break;
            }
            /*if(i >= 0 && j >= 0){
                printf("%c", Lvl->map[i][j]->symbol);
            }*/
            if(i >= 0 && j >= 0){
                if (strcmp(Lvl->map[i][j]->type, "colision") == 0 ){
                    if(Lvl->map[i][j]->isText){
                        printf(COLOR_YELLOW"%c  "COLOR_RESET, Lvl -> map[i][j] ->symbol);
                    }else{
                        printf("%c  ", Lvl -> map[i][j] ->symbol);
                    }
                    
                }else{
                    if (strcmp(Lvl->map[i][j]->type, "enemy")== 0 && Lvl->map[i][j]->Enemy->jefe == true){
                        printf(COLOR_PURPLE"%c  "COLOR_RESET, Lvl -> map[i][j]->symbol);
                    }else{
                        if(strcmp(Lvl->map[i][j]->type, "enemy")== 0 && Lvl->map[i][j]->Enemy->jefe == false){
                            printf(COLOR_RED"%c  "COLOR_RESET, Lvl->map[i][j]->symbol);
                        }else{
                            if (strcmp(Lvl->map[i][j]->type, "player")== 0){
                                printf(COLOR_CYAN"%c  "COLOR_RESET, Lvl -> map[i][j] ->symbol);
                            }else{
                                if (strcmp(Lvl->map[i][j]->type, "vacio")== 0){
                                    printf(COLOR_GREEN"%c  "COLOR_RESET, Lvl -> map[i][j] ->symbol);
                                }
                            }
                        }
                    }
                    if(strcmp(Lvl->map[i][j]->type, "vida")== 0){
                        printf(COLOR_PURPLE"%c  "COLOR_RESET, Lvl -> map[i][j] ->symbol);
                    }
                    
                }
            
            }
            
        }
        printf("\n");    //printf("%c", Lvl -> map[i][j] ->symbol);
    }


    //printf("\ndebería estar al final\n");
    bool close = false;
    printf("\n._______________\n");
    printf("|Salud: \t\n|");
    for(int i = 0; i < Lvl->Player->hp; i++){
        printf(COLOR_RED"%c ", 3);
        if (i > 1 && (i % 5) == 0){

            printf(COLOR_RESET"     \n|");
        }
    }
    printf(COLOR_RESET"\t\n|Ataque: %i\t", Lvl->Player->atk);

    printf("\n|Exp: %i / %i\t", Lvl->Player->exp, Lvl->Player->expMax);
    printf("Nivel: %i", Lvl->Player->lvl);
    if(Lvl->Player->turnos != 0){
        printf("\n|Recarga 'E': %i", Lvl->Player->turnos);
    }
    if(Lvl->Player->otroturn != 0){
        printf("\n|Recarga 'F': %i", Lvl->Player->otroturn);
    }
    

    printf("\n|_______________\n|");
    
    for(int i = Lvl->posy-2; i<Lvl -> posy+2; i++){
        for(int j = Lvl->posx-5; j<Lvl->posx+5; j++){
            if(i >= 0 && j >= 0 && i < Lvl->width && j < Lvl->height){
                if (strcmp(Lvl->map[i][j]->type, "enemy")== 0){
                    close = true;
                    printf("%s ", Lvl->map[i][j]->Enemy->name);
                    printf("\t");
                }
            }
        }
    }
    printf("\n|");
    int cont = 0;
    for(int i = Lvl->posy-2; i<Lvl -> posy+2; i++){
        for(int j = Lvl->posx-5; j<Lvl->posx+5; j++){
            if(i >= 0 && j >= 0 && i < Lvl->width && j < Lvl->height){
                if (strcmp(Lvl->map[i][j]->type, "enemy")== 0){
                    close = true;
                    cont++;
                    //printf("\n|%s", Lvl->map[i][j]->Enemy->name);
                    printf("Vida restante: %i%c\t", (((Lvl->map[i][j]->Enemy->hp)*100)/Lvl->map[i][j]->Enemy->hpMax), 37);
                }
            }
        }
    }
    printf("\n|");
    for (int k = 0; k < cont; k++){
        printf("____________________");
    }
    
    if (close == true){
        printf("\nEnemigo fue detectado");
        
    }


    printf("\n");
    for(char *i = listFirst(text); i != NULL; i = listNext(text)){
        printf("%s", i);
    }

    /*printf("\n\n'a'- mover a la izquierda\t");
    printf("\t'd'- mover a la derecha\n");
    printf("'w'- mover hacia arriba\t");
    printf("\t's'- mover hacia abajo\n");
    printf("\t'e' - Atacar a enemigos cercanos");*/


    //printf("\t0-Salir\n\n");
        
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

void UpLvl(lvl* Lvl, square* Square){
    Lvl->Player->atk += 1;
    Lvl->Player->hpMax += 2;
    Lvl->Player->hp = Lvl->Player->hpMax;
    Lvl->Player->def += 1;
}
void experiencia(lvl* Lvl, square* Square){
    //player* jugador = Lvl->Player;
    Lvl->Player->exp += Square->Enemy->exp;
    if (Lvl->Player->exp == Lvl->Player->expMax){
      Lvl->Player->lvl += 1;
      Lvl->Player->exp = 0;
      Lvl->Player->expMax *= 2;
      UpLvl(Lvl, Square);
    }
    if(Lvl->Player->exp > Lvl->Player->expMax){
      Lvl->Player->lvl += 1;
      Lvl->Player->exp -= Lvl->Player->expMax;
      Lvl->Player->expMax *= 2;
      UpLvl(Lvl, Square);
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
    Square -> symbol = 220;
    strcpy(Square -> type, "colision");
    Square -> colision = true;

    return Square;
}

square *createItem(char *type, char symbol){
    square *Square = createSquare();
    Square -> symbol = 3;
    strcpy(Square -> type, type);

    return Square;
}

square* createSquareBoss(lvl* Lvl){
    square* Square = createSquare();
    Square->symbol = 237;
    strcpy(Square->type, "enemy");
    Square->colision = true;
    Square->Enemy = createBoss(Lvl);
    strcpy(Square->Enemy->name, "Estigia");
    Square->Enemy->jefe = true;
    return Square;
}

square *createSquareEnemy(lvl *Lvl){
    square *Square = createSquare();
    Square -> symbol = 21;
    strcpy(Square -> type, "enemy");
    Square -> colision = true;
    Square -> Enemy = createEnemy(Lvl);
    strcpy(Square->Enemy-> name, "Enemigo prueba");

    return Square;
}



void initLvl(List *gameHistory){
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


    Lvl->map[x][y] = createSquareBoss(Lvl);
    Lvl->jefes = true;
    

    reps = 0;
    reps = rand() % 70;
    
    
    
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
    List *text = listCreate();
    stats *Stats = createStats();
    showLvl(Lvl, text);
    updateLvl(Lvl, gameHistory, Stats);
}


void updateLvl(lvl *Lvl, List *gameHistory, stats *Stats){
    List *text = listCreate();
    char in = '\0';
    char last = '\0';
    fflush(stdin);
    in = getch();
    last = in;
    /*if (GetAsyncKeyState(VK_UP) ){
        in = 'w';
    }else{
        if(GetAsyncKeyState(VK_DOWN)){
            in = 's';
        }else{
            if(GetAsyncKeyState(VK_LEFT)){
                in = 'a';
            }else{

                if(GetAsyncKeyState(VK_RIGHT)){
                    in = 'd';
                }
            }
        }
    }*/
    
    //getchar();
    system("cls");

    //Movimiento jugador
    if(Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] -> colision == false){
        if(strcmp(Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] -> type, "vida") == 0){
            listPushBack(text, "2 corazones recuperados");
            Lvl -> Player -> hp += 2;
            if(Lvl -> Player -> hpMax < Lvl -> Player -> hp){
                Lvl -> Player -> hp = Lvl -> Player -> hpMax;
            }
        }
        Lvl -> map[Lvl -> posy + movementY(in)][Lvl -> posx + movementX(in)] = Lvl -> map[Lvl -> posy][Lvl -> posx];
        Lvl -> map[Lvl ->posy][Lvl ->posx] = createSquare();
        Lvl -> posx += movementX(in);
        Lvl -> posy += movementY(in);
        Stats -> steps ++;
    }

    //char *dmg = malloc(sizeof(char)*40);
    //Ataque jugador
    if(GetAsyncKeyState(VK_DOWN)){
        if(strcmp(Lvl -> map[Lvl ->posy+1][Lvl -> posx] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy+1][Lvl -> posx] -> Enemy -> hp -= (Lvl -> Player -> atk);

            listPushBack(text, "Has hecho ");
            char *str;
            str = malloc(sizeof(char)*3);
            sprintf(str, "%d", Lvl -> Player -> atk);
            listPushBack(text, str);
            listPushBack(text, " de dano a ");
            listPushBack(text, Lvl -> map[Lvl ->posy+1][Lvl -> posx] -> Enemy -> name);
            listPushBack(text, "\n");
            
        }
    }
    if(GetAsyncKeyState(VK_UP)){
        if(strcmp(Lvl -> map[Lvl ->posy-1][Lvl -> posx] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy-1][Lvl -> posx] -> Enemy -> hp -= (Lvl -> Player -> atk);

            listPushBack(text, "Has hecho ");
            char *str;
            str = malloc(sizeof(char)*3);
            sprintf(str, "%d", Lvl -> Player -> atk);
            listPushBack(text, str);
            listPushBack(text, " de dano a ");
            listPushBack(text, Lvl -> map[Lvl ->posy-1][Lvl -> posx] -> Enemy -> name);
            listPushBack(text, "\n");

        }
        //printf("\n no mueras\n");
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        if(strcmp(Lvl -> map[Lvl ->posy][Lvl -> posx+1] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy][Lvl -> posx+1] -> Enemy -> hp -= (Lvl -> Player -> atk);

            
            listPushBack(text, "Has hecho ");
            char *str;
            str = malloc(sizeof(char)*3);
            sprintf(str, "%d", Lvl -> Player -> atk);
            listPushBack(text, str);
            listPushBack(text, " de dano a ");
            listPushBack(text, Lvl -> map[Lvl ->posy][Lvl -> posx+1] -> Enemy -> name);
            listPushBack(text, "\n");
        }
    }
    if(GetAsyncKeyState(VK_LEFT)){
        if(strcmp(Lvl -> map[Lvl ->posy][Lvl -> posx-1] -> type, "enemy") == 0){
            Lvl -> map[Lvl ->posy][Lvl -> posx-1] -> Enemy -> hp -= (Lvl -> Player -> atk);

            listPushBack(text, "Has hecho ");
            char *str;
            str = malloc(sizeof(char)*3);
            sprintf(str, "%d", Lvl -> Player -> atk);
            listPushBack(text, str);
            listPushBack(text, " de dano a ");
            listPushBack(text, Lvl -> map[Lvl ->posy][Lvl -> posx-1] -> Enemy -> name);
            listPushBack(text, "\n");
        }
    }
    if(Lvl->Player->turnos > 0){
        Lvl->Player->turnos--;
    }


    if(GetAsyncKeyState(0x45) && Lvl->Player->turnos == 0){
        
        for(int i = Lvl->posy-1; i <= Lvl->posy+1; i++){
            for(int j = Lvl->posx-1; j <=  Lvl->posx+1; j++){
                if(strcmp(Lvl->map[i][j]->type, "enemy") == 0){
                    Lvl->map[i][j]->Enemy->hp -= Lvl->Player->atk + 2;
                    Lvl->Player->turnos = 5;
                }
            }
        }

    }

    //Recorrer mapa para hacer comprobaciones
    for(int i = 1; i < Lvl -> height-1; i++){
        for(int j = 1; j < Lvl -> width-1; j++){

            //Comprobacion enemigos
            if(Lvl -> map[i][j] -> marked == false){
                if(strcmp(Lvl -> map[i][j] -> type, "enemy") == 0){

                    //Comprobar si sigue vivo
                    if(Lvl -> map[i][j] -> Enemy -> hp <= 0){
                        experiencia(Lvl, Lvl->map[i][j]);
                        listPushBack(text, Lvl -> map[i][j] -> Enemy -> name);
                        listPushBack(text, " derrotado\n");
                        Lvl -> map[i][j] = createItem("vida", 'V');
                        Stats->kills++;
                        

                    }else{
                    //Comprobar si está en rango de ataque
                    if(strcmp(Lvl -> map[i+1][j] -> type, "player") == 0 || strcmp(Lvl -> map[i-1][j] -> type, "player") == 0 || strcmp(Lvl -> map[i][j+1] -> type, "player") == 0 || strcmp(Lvl -> map[i][j-1] -> type, "player") == 0){
                        Lvl -> Player -> hp -= (Lvl -> map[i][j] -> Enemy ->atk) - (Lvl ->Player->def);

                        listPushBack(text, "Has recibido ");
                        char *str = malloc(sizeof(char)*6);
                        sprintf(str, "%d", (Lvl -> map[i][j] -> Enemy ->atk) - (Lvl ->Player->def));
                        listPushBack(text, str);
                        listPushBack(text, " de dano\n");

                    }else{
                        //Comprobar si está en rango de movimiento
                        if(abs(i - Lvl -> posy) < 5 && abs(i - Lvl -> posy) > 0){
                            if(Lvl -> posx != i){
                                if(Lvl -> posy > i){
                                    if(strcmp(Lvl -> map[i+1][j] -> type, "vacio") == 0){
                                        Lvl -> map[i+1][j] = Lvl -> map[i][j];
                                        Lvl -> map[i+1][j] -> marked = true;
                                        Lvl -> map[i][j] = createSquare();
                                    }
                                }else{
                                    if(strcmp(Lvl -> map[i-1][j] -> type, "vacio") == 0){
                                        Lvl -> map[i-1][j] = Lvl -> map[i][j];
                                        Lvl -> map[i-1][j] -> marked = true;
                                        Lvl -> map[i][j] = createSquare();
                                    }
                                }
                            }
                            
                        }else if(abs(j - Lvl -> posx) < 5){
                            if(Lvl -> posx != j){
                                if(Lvl -> posx > j){
                                    if(strcmp(Lvl -> map[i][j+1] -> type, "vacio") == 0){
                                        Lvl -> map[i][j+1] = Lvl -> map[i][j];
                                        Lvl -> map[i][j+1] -> marked = true;
                                        Lvl -> map[i][j] = createSquare();
                                    }
                                }else{
                                    if(strcmp(Lvl -> map[i][j-1] -> type, "vacio") == 0){
                                        Lvl -> map[i][j-1] = Lvl -> map[i][j];
                                        Lvl -> map[i][j-1] -> marked = true;
                                        Lvl -> map[i][j] = createSquare();
                                    }
                                }
                            }
                            
                            
                        }
                    }
                 }
                }
            }
        }
    }

    //Desmarcar todas las casillas
    for(int i = 0; i < Lvl -> height-1; i++){
        for(int j = 0; j < Lvl -> width-1; j++){
            Lvl->map[i][j]->marked = false;
        }
    }
    //Si se igresa un 0 se termina la partida
    if(in != '0' && Lvl -> Player -> hp > 0){
        showLvl(Lvl, text);
        updateLvl(Lvl, gameHistory, Stats);
    }else if(Lvl -> Player -> hp <= 0){
        Stats -> maxLvl = Lvl -> Player ->lvl;
        listPushBack(gameHistory, Stats);
        pantallaMuerte();
        
    }
}

void showHistory(List *gameHistory, int num){
    clrscr();
    char in = '\0';
    int max = 0;
    for(stats *i = listFirst(gameHistory); i!= NULL; i = listNext(gameHistory)){
        max++;
    }
    stats *Stats = listFirst(gameHistory);
    for(int i = 1; i < max; i++){
        Stats = listNext(gameHistory);
    }
    if(max > 0){
            printf("Partida numero %i\n\n", num);
            printf("Pasos dados: %i\n", Stats->steps);
            printf("Enemigos eliminados: %i\n", Stats->kills);
            printf("Nivel alcanzado: %i\n\n", Stats->maxLvl);
        
        if(num > 1){
            printf("a- Anterior   ");
        }else{
            printf("              ");
        }

        printf("q- Salir al menu   ");

        if(num < max){
            printf("d- Siguiente");
        }
        printf("\n\nIngrese su opcion: ");

        in = getch();
        //getchar();

        
        if(in == 'a' && num > 1){
            showHistory(gameHistory, num-1);
            }
        if(in == 'd' && num < max){
            showHistory(gameHistory, num+1);
        }
        if(in == 'q'){
            return;
        }
        getchar();
        
    }else{
        printf("No hay partidas");
    }
    //if(in == 'q'){

    //}
    
}

void showStats(List *gameHistory){
    system("cls");
    int steps = 0;
    int kills = 0;
    int maxLvl = 0;

    for(stats *i = listFirst(gameHistory); i!= NULL; i = listNext(gameHistory)){
        steps += i -> steps;
        kills += i ->kills;
        maxLvl += (i->maxLvl) -1;
    }

    printf("Pasos dados: %i\n", steps);
    printf("Enemigos derrotados: %i\n", kills);
    printf("Total de niveles conseguidos: %i\n\n", maxLvl);
    printf("Presione cualquier boton para volver al menu\n");
    getchar();

}