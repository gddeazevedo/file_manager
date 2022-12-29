#ifndef __cli_h
#define __cli_h

#include <stdio.h>
#include "../memory/memory.h"
#include "../file_manager/file_manager.h"

#define EXIT 0
#define INSERT_FILE 1
#define REMOVE_FILE 2
#define SHOW_FILE 3

void run_cli();
static void show_menu();
static void select_option(int input);

#endif