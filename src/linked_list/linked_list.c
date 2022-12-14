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

bool remove_from(LinkedList* list, char* file_name) {
    SearchContent* content = search(list, file_name);
    Node* current = content->current;
    Node* prev = content->prev;
    int count = content->count;

    if (current != NULL && strcmp(current->file_name, file_name) == 0) {
        for (int i = 0; i < count; i++) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        }

        return true;
    }

    return false;
}

SearchContent* search(LinkedList* list, char* file_name) {
    Node* prev = list->head;
    Node* current = NULL;
    Node* aux = list->head->next;
    int count = 0;

    while (aux != NULL && strcmp(aux->file_name, file_name) != 0) {
        prev = aux;
        aux = aux->next;
    }

    if (aux != NULL && strcmp(aux->file_name, file_name) == 0) {
        current = aux;

        while (aux != NULL && strcmp(aux->file_name, file_name) == 0) {
            count++;
            aux = aux->next;
        }
    }

    SearchContent* content = (SearchContent*) malloc(sizeof(SearchContent));

    content->current = current;
    content->prev = prev;
    content->count = count;

    return content;
}
