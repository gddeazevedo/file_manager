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

/** @struct Node
 *  @brief struct que representa o nó de uma lista encadeada virtual
 */
typedef struct __node {
    char file_content[SIZE_FILE_CONTENT];
    char file_name[50];
    int next;
} Node;

/** @struct Memory
 *  @brief struct que representa a memória virtual
 */
typedef struct __memory {
    Node* ram[MEMORY_LENGTH];
    unsigned int occupied;
} Memory;

/**
 * @brief Retorna um ponteiro de memória virtual
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 */
Memory* newMemory();

/**
 * @brief Retorna um ponteiro de nó de lista encadeada virtual
 * 
 * @param file_content conteúdo que está dentro de um arquivo
 * @param file_name nome do arquivo
 */
Node* newNode(char* file_content, char* file_name);

/**
 * @brief Insere um nó na lista encadeada dentro da memória virtual
 * returna true caso
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 * @param file_content conteúdo que está dentro de um arquivo
 * @param file_name nome do arquivo a ser inserido
 */
bool insert_in(Memory* mem, MetaData* data, char* file_content, char* file_name);

/**
 * @brief Remove da memória virtual um arquivo
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 * @param file_name nome do arquivo a ser removido
 */
bool remove_from(Memory* mem, HashMap* map, char* file_name);

#endif