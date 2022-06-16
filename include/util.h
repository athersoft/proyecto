#ifndef UTIL_H
#define UTIL_H

#include "list.h"
#include <stdbool.h>
#include <string.h>
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
void clrscr();

char *_strdup(const char *str);


#endif
