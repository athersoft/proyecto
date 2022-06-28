/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>
/*Probando*/
#include "menu.h"
#include "util.h"
#include "search.h"
#include "list.h" 
#include "map.h"
#include "game.h"
#include <windows.h>
#include <conio.h>

void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void mostrarBestiario(Map *bestiary){
    clrscr();

    printf(COLOR_CYAN"Bestiario\n"COLOR_RESET);
    if(firstMap(bestiary) == NULL ){
        printf("No hay enemigos en el bestiario");
    }else{
        printf("Nombre de la bestia\tDerrotados\n");
        for(enemy *i = firstMap(bestiary); i!= NULL; i = nextMap(bestiary)){
            printf("%s\t%d\n",i ->name,i-> deadCount);
        }
    }

    printf("\nPresione cualquier boton para volver al menu\n");

    char in;
    scanf("%c", &in);
    getchar();
}

List *load(List *list){
    FILE *save = fopen("save.txt","r");
    char c;
    while(1){
        
        stats *Stats = createStats();
        c = fgetc(save);
        if(feof(save)){
            break;
        }
        Stats->steps = c- '0';
        c = fgetc(save);
        Stats->kills = c- '0';
        c = fgetc(save);
        Stats->maxLvl = c- '0';
        c = fgetc(save);
        Stats->chests = c- '0';
        c = fgetc(save);
        Stats->hearts = c- '0';
        c = fgetc(save);
        Stats->lvls = c- '0';
        listPushBack(list, Stats);
       
    }
    fclose(save);
    return list;
}

/* main function */
int main(){
    srand(time(NULL));
    List *gameHistory = listCreate();
    //FILE *save;

    if(fopen("save.txt","r")){
        gameHistory = load(gameHistory);
    }

    
    Map *bestiary = createMap(is_equal_string,lower_than_string);
    loadBestiary(bestiary);
    //system("Torero.mp3 &");
    int in=1;
    
    while(in != 0 ){
        //fullscreen();
        
        
        Sleep(1000);
        mostrarMenu();
        fflush(stdin);
        printf(WHITE COLOR_BLACK"Ingrese su seleccion: "COLOR_RESET);
        scanf("%i", &in );
        //getchar();
        int i = 0;
        if (in == 0){
            printf(COLOR_RESET"Bye bye\n"COLOR_RESET);
            return 0;
        }
        switch(in) {
            case (1): ; // Nuevo Juego
                printf("Cargando nivel, por favor espere");
                while(i != 7){
                    Sleep(100);
                    printf(".");
                    i++;
                }
                printf("\n");
                Sleep(1000);
                player *Player = createPlayer();
                initLvl(gameHistory, 1, Player,bestiary);
                break;
            case (2):
                mostrarInstrucciones();
                break;
            case(3): // Estadisticas
                showStats(gameHistory);
                break;
            case(4): // Historial de partidas
                showHistory(gameHistory, 1);
                break;
            case(5): //Bestiario
                mostrarBestiario(bestiary);
            default:
                break;
          } 

    } // while (in != q)
    printf(COLOR_RESET"Bye bye\n"COLOR_RESET);
    return 0;
}


