#ifndef __cli_h
#define __cli_h

#include "../linked_list/linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define EXIT 0
#define INSERT_FILE 1
#define REMOVE_FILE 2
#define SHOW_FILE 3

void run_cli(LinkedList* list);
static void show_menu(LinkedList* list);
static void select_option(LinkedList* list, int input);
static void insert_file(LinkedList* list);
static void remove_file(LinkedList* list);
static void show_file(LinkedList* list);

#endif