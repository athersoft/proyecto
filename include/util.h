#ifndef UTIL_H
#define UTIL_H

#include "list.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "map.h"
#define COLOR_RESET   "\033[0m"
#define COLOR_RED "\033[31m"      /* Red */
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLACK "\033[30m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_PURPLE "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"


#define BLACK "\033[40m"       
#define RED "\033[41m"         
#define GREEN "\033[42m"       
#define YELLOW "\033[43m"      
#define BLUE "\033[44m"        
#define PURPLE "\033[45m"      
#define CYAN "\033[46m"        
#define WHITE "\033[47m"    
#define NEGRITA "\033[30m"

#define ROJO_POTENTE "\033[101m"

extern char buf[];
void clrscr();

char *_strdup(const char *str);

int is_equal_string(void * key1, void * key2);  
int lower_than_string(void * key1, void * key2);


#endif
