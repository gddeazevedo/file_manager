#ifndef __meta_data_h
#define __meta_data_h

#include <stdlib.h>


typedef unsigned int uint;

/** @struct MetaData
 *  @brief struct que representa os metadados de um arquivo
 */
typedef struct __meta_data {
    uint file_size;
    uint file_first_index;
    char file_name[50];
} MetaData;

/**
 * @brief Retorna um ponteiro de metadado
 */
MetaData* newMetaData();

#endif
