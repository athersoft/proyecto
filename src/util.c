#include "util.h"
#include "string.h"
#include <ctype.h>

char buf[10000];

// castea un puntero (void *) a (Song *)



void clrscr() {
#if defined WINDOWS || defined _win32 || defined WIN32
    system("cls");
#else 
    system("clear");
#endif
};

char * _strdup(const char * str) {
    char * aux = (char *)malloc(strlen(str) + 1);
    strcpy(aux, str);
    return aux;
}


//Agregue las funciones que estan abajo
