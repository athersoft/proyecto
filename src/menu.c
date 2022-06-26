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
    printf("\t2-Cargar Partida\n");
    printf("3-Estadisticas\t");
    printf("\t4-Historial de partidas\n");
    printf("5-Bestiario\t");


    printf("\t0-Salir\n\n");
}


void pantallaMuerte(){
    

                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                   
    /*printf("\nHHHHHHHHH     HHHHHHHHH                                                                                                                                  tttt                            !!!   ");                               
    printf("\nH:::::::H     H:::::::H                                                                                                                               ttt:::t                           !!:!!     ");                            
    printf("\nH:::::::H     H:::::::H                                                                                                                               t:::::t                           !:::!     ");                            
    printf("\nHH::::::H     H::::::HH                                                                                                                               t:::::t                           !:::!      ");                           
    printf("\n H:::::H     H:::::H    aaaaaaaaaaaaa      ssssssssss           mmmmmmm    mmmmmmm   uuuuuu    uuuuuu      eeeeeeeeeeee    rrrrr   rrrrrrrrr   ttttttt:::::ttttttt       ooooooooooo   !:::!      ");//           cccccccccccccccc
    printf("\n H:::::H     H:::::H    a::::::::::::a   ss::::::::::s        mm:::::::m  m:::::::mm u::::u    u::::u    ee::::::::::::ee  r::::rrr:::::::::r  t:::::::::::::::::t     oo:::::::::::oo !:::!      ");//::::::   cc:::::::::::::::c
    printf("\n H::::::HHHHH::::::H    aaaaaaaaa:::::ass:::::::::::::s      m::::::::::mm::::::::::mu::::u    u::::u   e::::::eeeee:::::eer:::::::::::::::::r t:::::::::::::::::t    o:::::::::::::::o!:::!      ");//::::::  c:::::::::::::::::c
    printf("\n H:::::::::::::::::H             a::::as::::::ssss:::::s     m::::::::::::::::::::::mu::::u    u::::u  e::::::e     e:::::err::::::rrrrr::::::rtttttt:::::::tttttt    o:::::ooooo:::::o!:::!      ");//:::::: c:::::::cccccc:::::c
    printf("\n H:::::::::::::::::H      aaaaaaa:::::a s:::::s  ssssss      m:::::mmm::::::mmm:::::mu::::u    u::::u  e:::::::eeeee::::::e r:::::r     r:::::r      t:::::t          o::::o     o::::o!:::!      ");//       c::::::c     ccccccc
    printf("\n H::::::HHHHH::::::H    aa::::::::::::a   s::::::s           m::::m   m::::m   m::::mu::::u    u::::u  e:::::::::::::::::e  r:::::r     rrrrrrr      t:::::t          o::::o     o::::o!:::!     ");//        c:::::c             
    printf("\n H:::::H     H:::::H   a::::aaaa::::::a      s::::::s        m::::m   m::::m   m::::mu::::u    u::::u  e::::::eeeeeeeeeee   r:::::r                  t:::::t          o::::o     o::::o!!:!!     ");//        c:::::c             
    printf("\n H:::::H     H:::::H  a::::a    a:::::assssss   s:::::s      m::::m   m::::m   m::::mu:::::uuuu:::::u  e:::::::e            r:::::r                  t:::::t    tttttto::::o     o::::o !!!      ");// :::::: c::::::c     ccccccc
    printf("\nHH::::::H     H::::::HHa::::a    a:::::as:::::ssss::::::s     m::::m   m::::m   m::::mu:::::::::::::::uue::::::::e           r:::::r                  t::::::tttt:::::to:::::ooooo:::::o           ");//:::::: c:::::::cccccc:::::c
    printf("\nH:::::::H     H:::::::Ha:::::aaaa::::::as::::::::::::::s      m::::m   m::::m   m::::m u:::::::::::::::u e::::::::eeeeeeee   r:::::r                  tt::::::::::::::to:::::::::::::::o !!!       ");//::::::  c:::::::::::::::::c
    printf("\nH:::::::H     H:::::::H a::::::::::aa:::as:::::::::::ss       m::::m   m::::m   m::::m  uu::::::::uu:::u  ee:::::::::::::e   r:::::r                    tt:::::::::::tt oo:::::::::::oo !!:!!        ");//       cc:::::::::::::::c
    printf("\n HHHHHHHHH     HHHHHHHHH  aaaaaaaaaa  aaaa sssssssssss         mmmmmm   mmmmmm   mmmmmm    uuuuuuuu  uuuu    eeeeeeeeeeeeee   rrrrrrr                      ttttttttttt     ooooooooooo    !!!        ");//          cccccccccccccccc
           */
    
    
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



