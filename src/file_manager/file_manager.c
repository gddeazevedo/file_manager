#include "file_manager.h"


void insert_file(LinkedList* list) {
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

void remove_file(LinkedList* list) {
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

void show_file(LinkedList* list) {
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

    char op = 'a';
    __fpurge(stdin);

    while (op != 'q') {
        printf("Digite 'q' e aperte enter para sair: ");
        scanf("%c", &op);
    }
}
