#include "cli.h"

void run_cli() {
    LinkedList* list = new_LinkedList();
    show_menu(list);
}

void show_menu(LinkedList* list) {
    int input = 0;

    while (
        input != 1 &&
        input != 2 &&
        input != 3 &&
        input != 4 &&
        input != 5 &&
        input != 6
    ) {
        printf("----Bem vindo ao gerenciador de arquivos!----\n");
        printf("(1) Inserir um novo arquivo\n");
        printf("(2) Remover arquivo\n");
        printf("(3) Mostrar arquivos\n");
        printf("(4) Buscar arquivo\n");
        printf("(5) Buscar no arquivo\n");
        printf("(6) Mostrar um arquivo em específico\n");
        printf("Selecionar opção: ");
        scanf("%d", &input);
        system("clear");
    }
    
    select_option(list, input);
}


void select_option(LinkedList* list, int input) {
    switch (input)
    {
        case INSERT_FILE:
            insert_file(list);
            break;
        case REMOVE_FILE:
            remove_file(list);
            break;
        case SHOW_FILES:
            show_files(list);
            break;
        case SEARCH_FILE:
            search_file(list);
            break;
        case SEARCH_IN_FILE:
            search_in_file(list);
            break;
        case SHOW_FILE:
            show_file(list);
            break;
        default:
            break;
    }
}

void insert_file(LinkedList* list) {

}

void remove_file(LinkedList* list) {

}

void show_files(LinkedList* list) {

}

void search_file(LinkedList* list) {

}

void search_in_file(LinkedList* list) {

}

void show_file(LinkedList* list) {

}
