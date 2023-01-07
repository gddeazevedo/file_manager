#ifndef __hash_table_h
#define __hash_table_h

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../meta_data/meta_data.h"

#define TABLE_SIZE 30
#define KEY_LEN 50


typedef struct __hash_node {
    char key[KEY_LEN];
    MetaData* item;
    struct __hash_node* next;
} HashNode;

typedef struct __hash_map {
    int (*get)(char* key);
    bool (*put)(char* key, uint item);
    bool (*delete)(char* key);
} HashMap;

static HashNode* table[TABLE_SIZE];

HashMap* newHashMap();
static uint hash(char* key);
static HashNode* search_in_table(char* key);
MetaData* get(char* key);
bool put(char* key, MetaData* item);
bool delete(char* key);

void print_table();

#endif