#include "linked_list.h"

// Using head as auxiliar node

LinkedList* new_LinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = (Node*) malloc(sizeof(Node));
    list->head->next = NULL;
    list->tail = list->head;
    return list;
}

void insert_in(LinkedList* list, char* content, char* file_name) {
    if (list->length > MAX_LENGTH) return;

    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->file_content, content);
    strcpy(new_node->file_name, file_name);
    new_node->next = NULL;
    list->tail->next = new_node;
    list->tail = new_node;
    list->length += 1;
}

void remove_from(LinkedList* list, char* file_name) {
    Node* current = search(list, file_name);

    if (current != NULL && strcmp(current->file_name, file_name) == 0) {
        
    }
}

Node* search(LinkedList* list, char* file_name) {
    Node* prev = list->head;
    Node* current = list->head->next;

    while (current != NULL && strcmp(current->file_name, file_name) != 0) {
        prev = current;
        current = current->next;
    }

    return current;
}
