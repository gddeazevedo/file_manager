#include "src/memory/memory.h"
#include "src/file_manager/file_manager.h"

int main() {
    // run_cli();

    Memory* mem = newMemory();

    insert_file(mem); // test2
    insert_file(mem); // test1
    remove_from(mem, "test2.txt");
    insert_file(mem); // test3

    show_file(mem);

    // for (int i = 0; i < MEMORY_LENGTH; i++) {
    //     if (mem->ram[i] != NULL) {
    //         printf("%d - %s - %d\n", i, mem->ram[i]->file_name, mem->ram[i]->next);
    //     }
    // }

    return 0;
}
