#include "menu.h"
#include "util.h"
#include "string.h"
#include "map.h"
#include <windows.h>
#include <conio.h>

void mostrarMenu(){
    system("cls");
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

    printf(RED);
    printf(NEGRITA" _____  _                                           \n");      
    Sleep(110);
    printf("/ ____|| |                                          \n");   
    Sleep(110);
    printf("| |    | |__   __ _ _   _  __ _ _ __  _ __   ___    \n");
    Sleep(110);
    printf("| |    | '_ %c / _` | | | |/ _` | '_ %c| '_ %c / _ %c   \n", 92, 92, 92, 92);
    Sleep(110);
    printf("| |____| | | | (_| | |_| | (_| | | | | | | |  __/   \n");
    Sleep(110);
    printf("%c______|_| |_|%c__,_|%c__, |%c__,_|_| |_|_| |_|%c___|   \n", 92, 92, 92, 92, 92);
    Sleep(110);
    printf("                    __/ |                           \n");                       
    Sleep(110);
    printf("                   |___/                            \n");                        
    Sleep(110);
    printf("  ____                 _                            \n");                        
    Sleep(110);
    printf(" / __ %c               | |                           \n", 92);                        
    Sleep(110);
    printf("| |  | |_   _  ___ ___| |_                          \n");                       
    Sleep(110);
    printf("| |  | | | | |/ _ / __| __|                         \n");                    
    Sleep(110);
    printf("| |__| | |_| |  __%c__ | |_                          \n", 92);                       
    Sleep(110);
    printf(" %c___%c_%c%c__,_|%c___|___/%c__|                         ", 92, 92, 92, 92, 92, 92);                      
    Sleep(110);
    printf("\n                                                    \n"COLOR_RESET);
    Sleep(1000);

    printf("\n\n1-Nuevo Juego\t");
    printf("\t2-Instrucciones\n");
    printf("3-Estadisticas\t");
    printf("\t4-Historial de partidas\n");
    printf("5-Bestiario\t");


    printf("\t0-Salir\n\n");
}
void mostrarInstrucciones(){
    system("cls");
    int in;
    printf(COLOR_GREEN"Bienvenid%c aventurarer%c, vemos que buscas como controlar el cuerpo de Elmer\n", 64, 64);
    for(int i = 0; i < 8; i++){
        printf(".");
        Sleep(110);
    }
    Sleep(500);
    printf("\nLos movimientos b%csicos son tan simples como moverse adelante 'w'\n", 160);
    printf("dar un paso atr%cs 's', o puedes moverte con gracia hacia la izquierda 'a' o la derecha 'd'\n", 160);
    for(int i = 0; i < 3; i++){
        printf(".");
        Sleep(150);
    }
    Sleep(300);
    printf("\nTambi%cn puedes dar un %cgil giro 'e' con el que te puedes defender con m%cs potencia\n",130, 160, 160);
    printf("O dar un exagerado salto en direcci%cn de tu %cltimo paso 'f'\n", 162, 163);
    printf("Pero no te emociones tanto, que estos %cltimos te tomaran un tiempo en recuperarte", 163);
    printf("\n\n");
    for(int i = 0; i < 5; i++){
        printf(".");
        Sleep(150);
    }
    printf("\n");
    for(int i = 0; i < 7; i++){
        printf(".");
        Sleep(150);
    }
    Sleep(600);
    printf("\n%cDeseas algo m%cs?\n", 168, 160);

    printf("\n1. Si\t 2.No\t\t3...\n"COLOR_RESET);
    
    scanf("%i", &in);
    getchar();

    switch (in){
    case (1):
        printf(COLOR_GREEN"Ok...\nEn este mundo esta repleto de enemigos "COLOR_RESET);
        printf(COLOR_RED"%c"COLOR_RESET, 21);
        printf(COLOR_GREEN"\nSon capacez de golpearte si estas cerca\n");
        printf("Pero en caso de que estes cerca podras absorber su escencia "COLOR_RESET);
        printf(COLOR_PURPLE"%c"COLOR_RESET, 3);

        printf(COLOR_GREEN"\nTambi%cn te puedes encontrar con un enemigo de mayor poder"COLOR_RESET, 130);
        printf(COLOR_PURPLE" %c\n"COLOR_RESET, 237);
        printf(COLOR_GREEN"Al eliminarlos te permitir%cn viajar a otra zona de este mundo"COLOR_RESET, 160);
        getchar();
        return;
    case (2):
        printf(COLOR_GREEN"Bueno... Adi%cs, suerte en tu aventura"COLOR_RESET, 162);
        getchar();
        return;
    case (3):
        printf(COLOR_GREEN"En serio...\n");
        for(int i = 0; i < 5; i++){
            printf(".");
            Sleep(150);
        }
        Sleep(600);
        printf("\n%c%cControlas su cuerpo y no conoces su nombre!?\n", 168, 173);
        printf("Elmer Figueroa Arce");
        for(int i = 0; i < 5; i++){
            printf(".");
            Sleep(150);
        }
        printf(" Es Chayanne..");
        printf("\nMejor contin%ca tu aventura"COLOR_RESET, 163);
        getchar();

        break;    
    default:
        break;
    }

   
}

void pantallaMuerte(){
    system("cls");

                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                   

    //system("Ytu.mp3 &");
    Sleep(500);
    printf("\n##     ##    ###     ######    ##     ## ##     ## ######## ########  ########  #######    ####");   
    Sleep(130);
    printf("\n##     ##   ## ##   ##    ##   ###   ### ##     ## ##       ##     ##    ##    ##     ##   ####   ");
    Sleep(130);
    printf("\n##     ##  ##   ##  ##         #### #### ##     ## ##       ##     ##    ##    ##     ##   ####   ");
    Sleep(130);
    printf("\n######### ##     ##  ######    ## ### ## ##     ## ######   ########     ##    ##     ##    ##    ");
    Sleep(130);
    printf("\n##     ## #########       ##   ##     ## ##     ## ##       ##   ##      ##    ##     ##        ");
    Sleep(130);
    printf("\n##     ## ##     ## ##    ##   ##     ## ##     ## ##       ##    ##     ##    ##     ##   ####   ");
    Sleep(130);
    printf("\n##     ## ##     ##  ######    ##     ##  #######  ######## ##     ##    ##     #######    ####   ");
    Sleep(130);
    printf("\n\n");
    Sleep(1000);
    printf(PURPLE"Pero recuerda que este no es el final.\nSigue luchando y alcanza la victoria!!"COLOR_RESET);

    printf(RED"\nPresiona 'enter' para volver al men%c\n"COLOR_RESET, 163);
    getchar();

}



