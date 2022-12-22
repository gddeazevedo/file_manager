#ifndef __file_manager
#define __file_manager

#include <unistd.h>
#include <stdlib.h>
#include "../linked_list/linked_list.h"

void insert_file(LinkedList* list);
void remove_file(LinkedList* list);
void show_file(LinkedList* list);

#endif