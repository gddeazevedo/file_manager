#include "file_manager.h"

static bool did_file_opened(char* file_name, char* error_msg) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, error_msg);
        sleep(5);
        return false;
    }

    fclose(file);
    return true;
}

static bool file_exist(Memory* mem, char* file_name) {
    if (search(mem, file_name) != -1) {
        printf("Arquivo já está inserido!\n");
        sleep(5);
        return true;
    }

    return false;
}

void insert_file(Memory* mem, HashMap* map) {
    system("clear");

    printf("Digite o caminho para o arquivo: ");
    char file_name[50];
    scanf("%s", file_name);

    int total_nodes = 0;

    if (file_exist(mem, file_name)) return;
    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) return;

    FILE* file = fopen(file_name, "r");

    char file_content[SIZE_FILE_CONTENT];

    while (!feof(file)) {
        fgets(file_content, SIZE_FILE_CONTENT, file);
        total_nodes++;
        
        if (!insert_in(mem, file_content, file_name)) {
            printf("Memória excedida!\n");
            sleep(5);
            fclose(file);
            return;
        }
    }

    fclose(file);

    map->put(file_name, total_nodes);

    printf("Arquivo salvo com sucesso!\n");
    sleep(5);
}

void remove_file(Memory* mem, HashMap* map) {
    system("clear");

    printf("Digite o caminho para o arquivo que deseja remover: ");
    char file_name[50];
    scanf("%s", file_name);

    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) {
        return;
    }

    map->delete(file_name);
    remove_from(mem, file_name);
    printf("Arquivo removido com sucesso!\n");
    sleep(5);
}

void show_file(Memory* mem, HashMap* map) {
    printf("Digite o caminho para o arquivo que deseja verificar se está cadastrado: ");
    char file_name[50];
    scanf("%s", file_name);

    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) {
        return;
    }

    int index = search(mem, file_name);

    if (index == -1) {
        fprintf(stderr, "Arquivo não cadastrado!\n");
        sleep(5);
        return;
    }

    int total_nodes = map->get(file_name);

    printf("Arquivo: %s | Nós: %d\n", file_name, total_nodes);
    sleep(2);

    Node* node = mem->ram[index];

    printf("End. - Nome do arquivo\n");
    while (index != -1 && node != NULL) {
        printf("%d - %s\n", index, node->file_name);
        index = node->next;
        node = mem->ram[index];
    }

    char op = 'a';
    __fpurge(stdin);

    while (op != 'q') {
        printf("Digite 'q' e aperte enter para sair: ");
        scanf("%c", &op);
    }
}
