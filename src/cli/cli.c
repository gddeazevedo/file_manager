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
        
        if (!insert_in(list, file_content, file_name)) {
            printf("Memória excedida!\n");
            sleep(5);
            fclose(file);
            return;
        }
    }

    fclose(file);

    printf("Arquivo salvo com sucesso!\n");
    sleep(5);
}

static void remove_file(LinkedList* list) {
    system("clear");

    printf("Digite o caminho para o arquivo que deseja remover: ");
    char file_name[50];
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, "Arquivo inexistente!\n");
        sleep(5);
        return;
    }

    fclose(file);

    remove_from(list, file_name);
    printf("Arquivo removido com sucesso!\n");
    sleep(5);
}

static void show_file(LinkedList* list) {
    printf("Digite o caminho para o arquivo que deseja verificar se está cadastrado: ");
    char file_name[50];
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, "Arquivo inexistente!\n");
        sleep(5);
        return;
    }

    fclose(file);

    SearchContent* content = search(list, file_name);

    Node* current = content->current;
    int count = content->count;

    if (current == NULL) {
        printf("Arquivo não cadastrado!\n");
        sleep(5);
        return;
    }

    printf("%s - %d nós\n", current->file_name, count);

    for (int i = 0; i < count; i++) {
        printf("%d - %p\n", i + 1, current);
        current = current->next;        
    }

    sleep(10);
}
