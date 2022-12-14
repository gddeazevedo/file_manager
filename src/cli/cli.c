#include "cli.h"

void run_cli(LinkedList* list) {
    system("clear");
    show_menu(list);
}

static void show_menu(LinkedList* list) {
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
        printf("(0) Sair\n");
        printf("(1) Inserir um novo arquivo\n");
        printf("(2) Remover arquivo\n");
        printf("(3) Mostrar arquivos\n");
        printf("(4) Buscar arquivo\n");
        printf("(5) Buscar no arquivo\n");
        printf("(6) Mostrar um arquivo em específico\n");
        printf("Selecionar opção: ");
        scanf("%d", &input);
        system("clear");

        if (input == 0) exit(0);
    }

    select_option(list, input);
}


static void select_option(LinkedList* list, int input) {
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

static void insert_file(LinkedList* list) {
    system("clear");

    printf("Digite o caminho para o arquivo: ");
    char file_name[50];
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, "Error in opening file!\n");
        sleep(5);
        return;
    }

    char file_content[SIZE_FILE_CONTENT];

    while (!feof(file)) {
        fgets(file_content, SIZE_FILE_CONTENT, file);
        insert_in(list, file_content, file_name);
    }

    fclose(file);

    printf("Arquivo salvo com sucesso!\n");
    sleep(5);
}

static void remove_file(LinkedList* list) {

}

static void show_files(LinkedList* list) {
    Node* current_file = list->head->next;

}

static void search_file(LinkedList* list) {

}

static void search_in_file(LinkedList* list) {

}

static void show_file(LinkedList* list) {

}
