#ifndef __memory_h
#define __memory_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../meta_data/meta_data.h"
#include "../hash_map/hash_map.h"

#define SIZE_FILE_CONTENT 256
#define MEMORY_LENGTH 1000

typedef struct __node {
    char file_content[SIZE_FILE_CONTENT];
    char file_name[50];
    int next;
} Node;

typedef struct __memory {
    Node* ram[MEMORY_LENGTH];
    unsigned int occupied;
} Memory;

Memory* newMemory();
Node* newNode(char* file_content, char* file_name);
bool insert_in(Memory* mem, MetaData* data, char* file_content, char* file_name);
bool remove_from(Memory* mem, HashMap* map, char* file_name);

#endif