#ifndef __file_manager
#define __file_manager

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include <string.h>
#include "../memory/memory.h"
#include "../hash_table/hash_table.h"
#include "../meta_data/meta_data.h"


void insert_file(Memory* mem, HashMap* map);
void remove_file(Memory* mem, HashMap* map);
void show_file(Memory* mem, HashMap* map);
static bool did_file_opened(char* file_name, char* error_msg);
static bool file_exist(Memory* mem, HashMap* map, char* file_name);

#endif