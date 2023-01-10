#include "file_manager.h"

static bool did_file_opened(char* file_name, char* error_msg) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        fprintf(stderr, error_msg);
        pause_program();
        return false;
    }

    fclose(file);
    return true;
}

static bool file_exist(Memory* mem, HashMap* map, char* file_name) {
    if (map->get(file_name) != NULL) {
        printf("Arquivo já está inserido!\n");
        pause_program();
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

    if (file_exist(mem, map, file_name)) return;
    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) return;

    FILE* file = fopen(file_name, "r");

    char file_content[SIZE_FILE_CONTENT];

    MetaData* meta_data = newMetaData();

    while (!feof(file)) {
        fgets(file_content, SIZE_FILE_CONTENT, file);
        total_nodes++;
        
        if (!insert_in(mem, meta_data, file_content, file_name)) {
            printf("Memória excedida!\n");
            remove_from(mem, map, file_name);
            fclose(file);
            pause_program();
            return;
        }
    }

    fclose(file);

    meta_data->file_size = total_nodes;
    strcpy(meta_data->file_name, file_name);

    map->put(file_name, meta_data);

    printf("Arquivo salvo com sucesso!\n");
    pause_program();
}

void remove_file(Memory* mem, HashMap* map) {
    system("clear");

    printf("Digite o caminho para o arquivo que deseja remover: ");
    char file_name[50];
    scanf("%s", file_name);

    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) {
        return;
    }

    if (!remove_from(mem, map, file_name)) {
        printf("Arquivo não está cadastrado\n");
        pause_program();
        return;
    }
    
    printf("Arquivo removido com sucesso!\n");
    pause_program();
}

void show_file(Memory* mem, HashMap* map) {
    printf("Digite o caminho para o arquivo que deseja verificar se está cadastrado: ");
    char file_name[50];
    scanf("%s", file_name);

    if (!did_file_opened(file_name, "Arquivo inexistente!\n")) {
        return;
    }

    MetaData* meta_data = map->get(file_name);

    if (meta_data == NULL) {
        fprintf(stderr, "Arquivo não cadastrado!\n");
        pause_program();
        return;
    }

    int index = meta_data->file_first_index;
    int total_nodes = meta_data->file_size;

    printf("Arquivo: %s | Nós: %d\n", file_name, total_nodes);
    sleep(1);

    Node* node = mem->ram[index];

    printf("End. - Nome do arquivo\n");
    while (index != -1 && node != NULL) {
        printf("%d - %s\n", index, node->file_name);
        index = node->next;
        node = mem->ram[index];
    }

    pause_program();
}
