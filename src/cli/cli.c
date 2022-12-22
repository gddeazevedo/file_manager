#include "cli.h"

void run_cli(LinkedList* list) {
    system("clear");
    show_menu(list);
}

static void show_menu(LinkedList* list) {
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

    select_option(list, input);
}

static void select_option(LinkedList* list, int input) {
    switch (input)
    {
        case EXIT:
            exit(0);
            break;
        case INSERT_FILE:
            insert_file(list);
            break;
        case REMOVE_FILE:
            remove_file(list);
            break;
        case SHOW_FILE:
            show_file(list);
            break;
        default:
            break;
    }
}
