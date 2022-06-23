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




/* main function */
int main(){
    List *gameHistory = listCreate();
    //map *bestiary = createMap();

    int in=1;

    while(in != 0 ){

        mostrarMenu();
        fflush(stdin);
        printf(WHITE COLOR_BLACK"Ingrese su seleccion: "COLOR_RESET);
        scanf("%i ", &in );
        //getchar();
        
        if (in == 0){
            printf(COLOR_RESET"Bye bye\n"COLOR_RESET);
            return 0;
        }
        switch(in) {
            case (1): ; // Nuevo Juego
                initLvl(gameHistory);
                break;
            case (2): // Cargar Partida

                break;
            case(3): // Estadisticas

                break;
            case(11): // Debug

                break;
            default:
                break;
          } 

    } // while (in != q)
    printf(COLOR_RESET"Bye bye\n"COLOR_RESET);
    return 0;
}


