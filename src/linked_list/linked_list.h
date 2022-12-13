#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define SIZE_FILE_CONTENT 256


typedef struct __node {
    char file_content[SIZE_FILE_CONTENT];
    char file_name[50];
    struct __node* next;
} Node;


typedef struct {
    Node* prev;
    Node* current;
} SearchContent;

typedef struct {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

LinkedList* new_LinkedList();
void insert_in(LinkedList* list, char* content, char* file_name);
void remove_from(LinkedList* list, char* file_name);
Node* search(LinkedList* list, char* file_name);


#endif