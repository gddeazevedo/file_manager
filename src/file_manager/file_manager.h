#ifndef __file_manager
#define __file_manager

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "../memory/memory.h"


void insert_file(Memory* mem);
void remove_file(Memory* mem);
void show_file(Memory* mem);

#endif