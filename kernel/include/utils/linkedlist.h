/*
Linked list data structure implementation
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <common.h>

/*=======================================================
    DEFINE
=========================================================*/
#define LinkedList_FOREACH(item, list) \
    for(Node* item = list->first; item != NULL; item = item->next)

#define LinkedList_getSize(list) ((list)->count)

/*=======================================================
    STRUCT
=========================================================*/
struct Node
{
    void* data;
    Node* next;
    Node* prev;
};

struct LinkedList
{
	Node*  first;
    Node*  last;
    u32int count;
};

typedef struct LinkedList LinkedList;
typedef struct Node Node;

/*=======================================================
    FUNCTION
=========================================================*/
void        LinkedList_add(LinkedList* self, void* data);

void*       LinkedList_remove(LinkedList* self, void* data);

void*       LinkedList_removeFromFront(LinkedList* self);

void*       LinkedList_getFront(LinkedList* self);

LinkedList* LinkedList_new();

void        LinkedList_destroy(LinkedList* self);

#endif
