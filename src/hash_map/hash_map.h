#ifndef __hash_table_h
#define __hash_table_h

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../meta_data/meta_data.h"

#define TABLE_SIZE 30
#define KEY_LEN 50

/** @struct HashNode
 *  @brief struct que representa os nós da tabela hash
 */
typedef struct __hash_node {
    char key[KEY_LEN];
    MetaData* item;
    struct __hash_node* next;
} HashNode;

/** @struct HashMap
 *  @brief struct para manipular as funções de inserir, remover e pegar dados da tabela hash
 */
typedef struct __hash_map {
    MetaData* (*get)(char* key);
    bool (*put)(char* key, MetaData* item);
    bool (*delete)(char* key);
} HashMap;

/**
 * @var hash table
 * @brief Variável global que representa a tabela hash
*/
static HashNode* table[TABLE_SIZE];


/**
 * @brief Retorna um ponteiro para struct do tipo HashMap
 */
HashMap* newHashMap();

/**
 * @brief Retorna um número inteiro positivo para um índice da tabela hash
 * 
 * @param key string que será mapeada para um índice da tabela hash
 */
static uint hash(char* key);

/**
 * @brief Busca um elemento dentro da tabela hash, return o ponteiro caso ele esteja na tabela
 * caso contrário retorna NULL
 * 
 * @param key string que será mapeada para um índice da tabela hash
 */
static HashNode* search(char* key);

/**
 * @brief Retorna os metadados que estão inseridos na tabela hash, caso não haja
 * metadados, NULL será retornado
 * 
 * @param key chave para o campo da tabela hash
 */
MetaData* get(char* key);

/**
 * @brief Insere um metadado dentro da tabela hash
 * 
 * @param key chave para o campo da tabela hash
 * @param item metadados para serem inseridos na tabela hash
 */
bool put(char* key, MetaData* item);

/**
 * @brief Deleta um metadado da tabela hash
 * 
 * @param key chave para o campo da tabela hash
 */
bool delete(char* key);

#endif