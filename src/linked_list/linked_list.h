#ifndef __linked_list_h
#define __linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define SIZE_FILE_CONTENT 256


typedef struct __node {
    char file_content[SIZE_FILE_CONTENT];
    char file_name[50];
    struct __node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

typedef struct {
    Node* prev;
    Node* current;
    int count;
} SearchContent;


LinkedList* new_LinkedList();
bool insert_in(LinkedList* list, char* content, char* file_name);
bool remove_from(LinkedList* list, char* file_name);
SearchContent* search(LinkedList* list, char* file_name);

#endif