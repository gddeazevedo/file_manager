#include "cli.h"

void run_cli() {
    Memory* mem = newMemory();
    HashMap* map = newHashMap();

    while (true) {
        system("clear");
        show_menu(mem, map);
    }
}

static void show_menu(Memory* mem, HashMap* map) {
    int input = -1;

    while (
        input != 0 &&
        input != 1 &&
        input != 2 &&
        input != 3
    ) {
        printf("----Bem vindo ao gerenciador de arquivos!----\n");
        printf("(0) Sair\n");
        printf("(1) Inserir um novo arquivo\n");
        printf("(2) Remover arquivo\n");
        printf("(3) Buscar arquivo\n");
        printf("Selecionar opção: ");
        scanf("%d", &input);
        system("clear");
    }

    select_option(mem, map, input);
}

static void select_option(Memory* mem, HashMap* map, int input) {
    switch (input)
    {
        case EXIT:
            exit(0);
            break;
        case INSERT_FILE:
            insert_file(mem, map);
            break;
        case REMOVE_FILE:
            remove_file(mem, map);
            break;
        case SHOW_FILE:
            show_file(mem, map);
            break;
        default:
            break;
    }
}
