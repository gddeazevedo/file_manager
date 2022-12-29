// #include "cli.h"

// /**
//  * @brief Inícia a interface de comando de linha (command line interface)
//  * 
//  * @param list lista encadeada
//  * @return void
//  */

// void run_cli() {
//     system("clear");
//     show_menu();
// }


// /**
//  * @brief Mostra o menu da aplicação
//  * 
//  * @param list lista encadeada
//  * @return void
//  */
// static void show_menu() {
//     int input = -1;

//     while (
//         input != 0 &&
//         input != 1 &&
//         input != 2 &&
//         input != 3
//     ) {
//         printf("----Bem vindo ao gerenciador de arquivos!----\n");
//         printf("(0) Sair\n");
//         printf("(1) Inserir um novo arquivo\n");
//         printf("(2) Remover arquivo\n");
//         printf("(3) Buscar arquivo\n");
//         printf("Selecionar opção: ");
//         scanf("%d", &input);
//         system("clear");
//     }

//     // select_option(list, input);
// }

// /**
//  * @brief Seleciona a opção escolhida pelo usuário
//  * 
//  * @param list lista encadeada
//  * @param input opcão do usuário
//  * @return void
//  */
// static void select_option(int input) {
//     switch (input)
//     {
//         case EXIT:
//             exit(0);
//             break;
//         case INSERT_FILE:
//             insert_file();
//             break;
//         case REMOVE_FILE:
//             remove_file();
//             break;
//         case SHOW_FILE:
//             show_file();
//             break;
//         default:
//             break;
//     }
// }
