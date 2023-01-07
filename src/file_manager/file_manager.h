#ifndef __file_manager
#define __file_manager

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include <string.h>
#include "../memory/memory.h"
#include "../hash_map/hash_map.h"
#include "../meta_data/meta_data.h"
#include "../helpers/helpers.h"

/**
 * @brief Insere um arquivo na memória virtual
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 */
void insert_file(Memory* mem, HashMap* map);

/**
 * @brief Remove um arquivo da memória virtual
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 */
void remove_file(Memory* mem, HashMap* map);

/**
 * @brief Mostra um arquivo que está inserido
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 */
void show_file(Memory* mem, HashMap* map);

/**
 * @brief Retorna se o arquivo abrir, false caso contrário
 * 
 * @param file_name nome do arquivo
 * @param error_msg mensagem de erro a ser exibida caso o arquivo não exista/não abra
 */
static bool did_file_opened(char* file_name, char* error_msg);

/**
 * @brief Verifica se um arquivo existe, return true se exite, false caso contrário
 * 
 * @param mem memória que simula a memória do computador
 * @param map tabela hash para armazenar metadados de arquivos
 * @param file_name nome do arquivo
 */
static bool file_exist(Memory* mem, HashMap* map, char* file_name);

#endif