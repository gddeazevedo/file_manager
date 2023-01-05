#include "hash_table.h"


HashMap* newHashMap() {
    HashMap* map = (HashMap*) malloc(sizeof(HashMap));
    map->get = &get;
    map->put = &put;
    map->delete = &delete;
    return map;
}

static uint hash(char* key) {
    uint hash_val = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash_val += key[i];
        hash_val *= key[i];
        hash_val *= hash_val;
    }

    hash_val %= TABLE_SIZE;

    return hash_val;
}


static HashNode* search_in_table(char* key) {
    HashNode* node = table[hash(key)];

    while (node != NULL && strcmp(node->key, key) != 0) {
        node = node->next;
    }

    return node;
}

int get(char* key) {
    HashNode* node = search_in_table(key);
    if (node == NULL) return -1;
    return node->item;
}

bool put(char* key, uint item) {
    HashNode* node = search_in_table(key);

    if (node == NULL) {
        node = (HashNode*) malloc(sizeof(HashNode));
        strcpy(node->key, key);
        node->item = item;
        uint index = hash(key);
        node->next = table[index];
        table[index] = node;
        return true;
    }

    return false;
}

bool delete(char* key) {
    uint index = hash(key);
    HashNode* current = table[index];
    HashNode* aux;

    while (current != NULL && strcmp(current->key, key) != 0) {
        aux = current;
        current = current->next;
    }

    if (current == NULL) return false;

    if (current == table[index]) {
        aux = table[index];
        table[index] = table[index]->next;
        aux->next = NULL;
        free(aux);
        return true;
    }

    aux->next = current->next;
    current->next = NULL;
    free(current);
    current = NULL;
    aux = NULL;
    return true;
}
