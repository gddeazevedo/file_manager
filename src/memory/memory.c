#include "memory.h"


Memory* newMemory() {
    Memory* mem = (Memory*) malloc(sizeof(Memory));
    mem->occupied = 0;

    for (int i = 0; i < MEMORY_LENGTH; i++) {
        mem->ram[i] = NULL;
    }

    return mem;
}

Node* newNode(char* file_content, char* file_name) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->file_content, file_content);
    strcpy(node->file_name, file_name);
    node->next = -1;
    return node;
}

bool insert_in(Memory* mem, MetaData* data, char* file_content, char* file_name) {
    if (mem->occupied == MEMORY_LENGTH) return false;

    static int prev_node = 0;
    int current_node = 0;

    if (mem->occupied == 0) {
        prev_node = 0;
    }

    while (current_node < MEMORY_LENGTH && mem->ram[current_node] != NULL) {
        current_node++;
    }

    mem->ram[current_node] = newNode(file_content, file_name);

    if (strcmp(mem->ram[prev_node]->file_name, file_name) != 0) {
        mem->ram[prev_node]->next = -1;
        prev_node = current_node;
        data->file_first_index = current_node;
    } else if (prev_node != current_node) {
        mem->ram[prev_node]->next = current_node;
        prev_node = current_node;
    }

    mem->occupied += 1;

    return true;
}

bool remove_from(Memory* mem, HashMap* map, char* file_name) {
    MetaData* meta_data = map->get(file_name);

    if (meta_data == NULL) return false;

    int index = meta_data->file_first_index;

    Node* node = mem->ram[index];

    while (index != -1 && node != NULL) {
        mem->ram[index] = NULL;
        index = node->next;
        free(node);
        node = mem->ram[index];
        mem->occupied -= 1;
    }

    map->delete(file_name);

    return true;
}
