#ifndef MENU_H
#define MENU_H

#include "../linked_list/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

#define INSERT_FILE 1
#define REMOVE_FILE 2
#define SHOW_FILES  3
#define SEARCH_FILE 4
#define SEARCH_IN_FILE 5
#define SHOW_FILE 6

void run_cli();
void show_menu(LinkedList* list);
void select_option(LinkedList* list, int input);
void insert_file(LinkedList* list);
void remove_file(LinkedList* list);
void show_files(LinkedList* list);
void search_file(LinkedList* list);
void search_in_file(LinkedList* list);
void show_file(LinkedList* list);

#endif