#include "meta_data.h"

MetaData* newMetaData() {
    MetaData* data = (MetaData*) malloc(sizeof(MetaData));
    return data;
}
