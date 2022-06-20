#include "menu.h"
#include "util.h"
#include "string.h"
#include "map.h"

void mostrarMenu(){
    clrscr();
    printf("%s", buf);
    strcpy(buf, "");

    printf("Chayanne Quest\n");

    printf("1-Nuevo Juego\n");
    printf("2-Cargar Partida\n");
    printf("3-Estadisticas\n");
    printf("4-Historial de partidas\n");
    printf("5-Bestiario\n");



    printf("0-Salir\n");
}

void mostrarMenuBuscar(){
    clrscr();
    printf("%s", buf);
    strcpy(buf, "");


    printf(COLOR_CYAN"Menu de busqueda\n"COLOR_RESET);
    printf("'n': Por Titulo\n");
    printf("'t': Por Palabra\n");
    printf("'e': Salir\n");
    
                
}



