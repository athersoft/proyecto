#ifndef UTIL_H
#define UTIL_H

#include "list.h"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED "\033[31m"      /* Red */
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLACK "\033[30m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_PURPLE "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"

extern char buf[];
List * genresToList(const char * genre);
void clrscr();

char *_strdup(const char *str);
//Agregue las funciones que pasa el profe para quitar caracteres
int quitar_caracteres(char* string, char* c);
int hayQueEliminar(char c, char* string_chars);
//Agregue la funcion que hace un string completo a minuscula
char* lower(char* word);

#endif
