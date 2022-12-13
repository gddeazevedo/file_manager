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

void run_cli(LinkedList* list);
static void show_menu(LinkedList* list);
static void select_option(LinkedList* list, int input);
static void insert_file(LinkedList* list);
static void remove_file(LinkedList* list);
static void show_files(LinkedList* list);
static void search_file(LinkedList* list);
static void search_in_file(LinkedList* list);
static void show_file(LinkedList* list);

#endif