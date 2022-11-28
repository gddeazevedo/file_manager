#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct __node {
    int id;
    char file_content[256];
    char file_name[40];
    struct __node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* new_LinkedList();
void insert_in(LinkedList* list, char* content);
void remove_from(LinkedList* list, char* file_name);
void search(LinkedList* list, char* file_name);


#endif