#include "../../cvector.h"

void* cvector_at(cvector* obj, size_t pos) {
    if ( !obj || !obj->array || pos >= obj->index ) {
        return NULL;
    }

    return obj->array[pos];
}

void* cvector_front(cvector* obj) {
    if ( !obj || !obj->array ) {
        return NULL;
    }

    return obj->array[0];
}

void* cvector_back(cvector* obj) {
    if ( !obj || !obj->array || obj->index == 0) {
        return NULL;
    }

    return obj->array[obj->index - 1];
}

void* cvector_data(cvector* obj) {
    if ( !obj ) {
        return NULL;
    }

    return obj->array;
}
