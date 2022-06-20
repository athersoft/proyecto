/* Entrada y salida estándar */
#include <stdio.h>

/* manipulación de Strings */
#include <string.h>

#include "menu.h"
#include "util.h"
#include "search.h"
#include "list.h" 
#include "map.h"
#include "game.h"



/* main function */
int main(){

    int in;
    //list *gameHistory = createList();
    //map *bestiary = createMap();

    while(in != 0 ){
        mostrarMenu();
        fflush(stdin);
        printf("Ingrese su seleccion: ");
        scanf("%i", &in);
        //getchar();

        switch(in) {
            case (1): ; // Nuevo Juego
                initLvl();
                break;
            case (2): // Cargar Partida

                break;
            case(3): // Estadisticas

                break;
            case('B'): // Mostrar palabras mas frecuentes

                break;
            case('A'): // Mostrar palabras mas relevantes

                break;
            case(11): // Debug

                break;
            case('C'):
            

                break;
            
            default:
                break;
          } 

    } // while (in != q)
    printf("Bye bye\n");
    return 0;
}


