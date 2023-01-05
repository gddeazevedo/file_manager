#include "hash_table.h"


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

bool put(char* key, int item) {
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
