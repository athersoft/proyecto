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

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

//Agregue las funciones que estan abajo
