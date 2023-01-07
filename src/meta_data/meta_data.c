#include "meta_data.h"

MetaData* newMetaData(uint file_size, uint file_first_index, char* file_name) {
    MetaData* data = (MetaData*) malloc(sizeof(MetaData));
    strcpy(data->file_name, file_name);
    data->file_size = file_size;
    data->file_first_index = file_first_index;
    return data;
}
