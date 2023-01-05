#ifndef __cli_h
#define __cli_h

#include <stdio.h>
#include "../memory/memory.h"
#include "../file_manager/file_manager.h"

#define EXIT 0
#define INSERT_FILE 1
#define REMOVE_FILE 2
#define SHOW_FILE 3


/**
 * @brief Mostra o menu da aplicação
 * 
 * @param mem memória que simula a memória do computador
 */
static void show_menu(Memory* mem, HashMap* map);

/**
 * @brief Inícia a interface de comando de linha (command line interface)
 */
void run_cli();


/**
 * @brief Seleciona a opção escolhida pelo usuário
 * 
 * @param mem memória que simula a memória do computador
 * @param input opcão do usuário
 */
static void select_option(Memory* mem, HashMap* map, int input);

#endif