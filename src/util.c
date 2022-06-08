#include "util.h"
#include "string.h"
#include <ctype.h>

char buf[10000];

// castea un puntero (void *) a (Song *)

List *genresToList(const char *genre){
    List *list = listCreate();

    char *genresCopy = _strdup(genre);
    char *token = strtok(genresCopy, ",");

    int flag = 0;
    while(token != NULL){
        if (flag) listPushBack(list, token+1);
        else listPushBack(list, token);
        flag = 1;

        token = strtok(NULL, ",");
    }
        
    return list;
}

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

char* lower(char* word){
    int i = 0;
    while (word[i] != '\0'){
        word[i] = tolower(word[i]);
        i++;
    }
    return word;
}

int hayQueEliminar(char c, char* string_chars){
    for(int i=0 ; i<strlen(string_chars) ; i++){
        if(string_chars[i]==c) return 1;
    }
    return 0;
}

int quitar_caracteres(char* string, char* c){
    int i;
    int j;
    int elimino = 0;
    for(i=0 ; i < strlen(string) ; i++){
        if(hayQueEliminar(string[i], c)){
            elimino  = 1;
            for(j=i ; j<strlen(string)-1 ;j++){
                string[j] = string[j+1];
        }
        string[j]='\0';
        i--;
    }
}
    return elimino;
}
