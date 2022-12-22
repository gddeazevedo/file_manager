#ifndef __file_manager
#define __file_manager

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "../linked_list/linked_list.h"

void insert_file(LinkedList* list);
void remove_file(LinkedList* list);
void show_file(LinkedList* list);

#endif