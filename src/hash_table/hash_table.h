#ifndef __hash_table_h
#define __hash_table_h

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 30
#define KEY_LEN 50

typedef unsigned int uint;

typedef struct __hash_node {
    char key[KEY_LEN];
    uint item;
    struct __hash_node* next;
} HashNode;

static HashNode* table[TABLE_SIZE];

static uint hash(char* key);
static HashNode* search_in_table(char* key);
int get(char* key);
bool put(char* key, int item);
bool delete(char* key);

#endif