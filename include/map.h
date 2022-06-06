#ifndef MAP_H
#define MAP_H





typedef struct Node {
    void * key;
    /*! Puntero al dato */
    void * data;

    /*! Puntero al siguiente nodo */
    struct Node * next;

    /*! Puntero al anterior nodo */
    struct Node * prev;
}Node;

typedef struct Map Map;

struct Map {
    /*! Puntero al incio (cabeza) de la lista */
    Node * head;

    /*! Puntero al final (cola) de la lista */
    Node * tail;

    /*! Puntero para poder recorrer la lista */
    Node * current;

    int (*is_equal)(void* key1, void* key2);
    int (*lower_than)(void* key1, void* key2);

};

//Agregar lower_than desde que se crea el mapa
Map * createMap(int (*is_equal)(void* key1, void* key2),int (*lower_than)(void* key1, void* key2));

void insertMap(Map * map, void * key, void * value);

void * eraseMap(Map * map, void * key);

void * searchMap(Map * map, void * key);

void * firstMap(Map * map);

void * nextMap(Map * map);

void setSortFunction(Map* map, int (*lower_than)(void* key1, void* key2));

void _pushFront(Map * list, void * key, void * value);

void showInContext(char *word, char *title, Map *mapWords, Map *mapBooks);
#endif /* MAP_h */