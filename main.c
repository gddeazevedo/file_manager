#include "src/cli/cli.h"
#include "src/linked_list/linked_list.h"

void main() {
    LinkedList* list = new_LinkedList();

    while (true) {
        run_cli(list);
    }
}