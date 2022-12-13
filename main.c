#include "src/cli/cli.h"
#include "src/linked_list/linked_list.h"
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void main() {
    LinkedList* list = new_LinkedList();

    while (true) {
        run_cli(list);
    }
}