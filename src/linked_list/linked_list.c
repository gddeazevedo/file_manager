#include "linked_list.h"

LinkedList* new_LinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = (Node*) malloc(sizeof(Node));
    list->tail = list->head;
    return list;
}