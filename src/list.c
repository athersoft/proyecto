#include "list.h"
#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"



ListNode * nodeCreate(void * data) {
    ListNode * new = (ListNode *)malloc(sizeof(ListNode));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * listCreate() {
     List * new = (List *)malloc(sizeof(List));
     assert(new != NULL);
     new->head = new->tail = new->current = NULL;
     new->length = 0;
     strcpy(new->name, "");
     return new;
}

void * listFirst(List * list) {
    if (list == NULL || list->head == NULL) return NULL;
    list->current = list->head;
    return (void *)list->current->data;
}

void * listNext(List * list) {
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return (void *)list->current->data;
}

void * listLast(List * list) {
    if (list == NULL || list->head == NULL) return NULL;
    list->current = list->tail;
    return (void *)list->current->data;
}

void * listPrev(List * list) {
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->prev == NULL) return NULL;
    list->current = list->current->prev;
    return (void *)list->current->data;
}

void listPushFront(List * list, void * data) {
    assert(list != NULL);
    
    ListNode * new = nodeCreate(data);
    
    if (list->head == NULL) {
        list->tail = new;
    } else {
        new->next = list->head;
        list->head->prev = new;
    }
    
    list->head = new;
    list->length++;
}

void listPushBack(List * list, void * data) {
    list->current = list->tail;
    if(list->current==NULL) listPushFront(list,data);
    else listPushCurrent(list,data);
}

void listPushCurrent(List * list, void * data) {
    assert(list != NULL && list->current !=NULL);
    ListNode * new = nodeCreate(data);

    if(list->current->next)
        new->next = list->current->next;
    new->prev = list->current;

    if(list->current->next)
        list->current->next->prev = new;
    list->current->next = new;

    if(list->current==list->tail)
        list->tail=new;

    list->length++;
}

void * listPopFront(List * list) {
    list->current = list->head;
    return listPopCurrent(list);
}

void * listPopBack(List * list) {
    list->current = list->tail;
    return listPopCurrent(list);
}

void * listPopCurrent(List * list) {
    assert(list != NULL || list->head != NULL);
    
    if (list->current == NULL) return NULL;
    
    ListNode * aux = list->current;
    
    if (aux->next != NULL) 
        aux->next->prev = aux->prev;
    
    
    if (aux->prev != NULL) 
        aux->prev->next = aux->next;
    
    
    void * data = (void *)aux->data;
    
    if(list->current == list->tail)
        list->tail = list->current->prev;

    if(list->current == list->head)
        list->head = list->current->next;
        
    list->current = aux->prev;



    
    free(aux);

    list->length--;
    
    return data;
}

void listClean(List * list) {
    assert(list != NULL);
    
    while (list->head != NULL) {
        listPopFront(list);
    }
    list->length = 0;
}

