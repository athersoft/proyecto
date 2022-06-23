#include "menu.h"
#include "util.h"
#include "string.h"
#include "map.h"
#include <windows.h>
#include <conio.h>

void mostrarMenu(){
    clrscr();
    //printf("%s", buf);
    //strcpy(buf, "");

    //printf("Chayanne Quest\n");
    /*for(int i = 0; i< 33; i++ ){
        printf(COLOR_BLACK"%c", 219);
        Sleep(15);
    }*/
    /*printf("\n%c", 219);
    printf(PURPLE"\tChayanne Quest"COLOR_RESET);
    printf(COLOR_BLACK"\t\t%c\n", 219);*/
    //printf("%c\t----------------\n\t%c", 219, 219);
    /*for(int i = 0; i< 33; i++ ){
        printf(COLOR_BLACK"%c", 219);
        Sleep(15);
    }*/

    /*printf("_____________\n");
    printf("| __________|\n");
    for (int i = 0; i < 4; i++){
        printf("| |\n");
    }
    printf("| |_________\n");
    printf("|___________|\n");}*/

    
    printf(" _____ _\n");                                        
    printf("/ ____| |\n");                                       
    printf("| |    | |__   __ _ _   _  __ _ _ __  _ __   ___\n");
    printf("| |    | '_ %c / _` | | | |/ _` | '_ %c| '_ %c / _ %c \n", 92, 92, 92, 92);
    printf("| |____| | | | (_| | |_| | (_| | | | | | | |  __/ \n");
    printf("%c_____|_| |_|%c__,_|%c__, |%c__,_|_| |_|_| |_|%c___|\n", 92, 92, 92, 92, 92);
    printf("                    __/ |\n");                       
    printf("                   |___/\n");                        
    printf("  ____                 _ \n");                        
    printf(" / __ %c               | |\n", 92);                        
    printf("| |  | |_   _  ___ ___| |_\n");                       
    printf("| |  | | | | |/ _ / __| __|  \n");                    
    printf("| |__| | |_| |  __%c__ | |_\n", 92);                       
    printf(" %c___%c_%c%c__,_|%c___|___/%c__|\n", 92, 92, 92, 92, 92, 92);                      


    
    
    

    printf(COLOR_RESET"\n\n1-Nuevo Juego\t");
    printf("\t2-Cargar Partida\n");
    printf("3-Estadisticas\t");
    printf("\t4-Historial de partidas\n");
    printf("5-Bestiario\t");


    printf("\t0-Salir\n\n");
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



