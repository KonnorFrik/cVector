#include "../../cvector.h"
#include <stdlib.h>

bool cvector_empty(cvector* obj) {
    if ( !obj ) {
        return true;
    }

    return obj->index == 0;
}

size_t cvector_size(cvector* obj) {
    if ( !obj ) {
        return 0;
    }

    return obj->index;
}

bool cvector_reserve(cvector* obj, size_t new_size) {
    if ( !obj || new_size <= obj->capacity ) {
        return true;
    }

    bool status = false;
    void** tmp = realloc(obj->array, new_size * sizeof(void*));

    if ( tmp ) {
        obj->array = tmp;
        obj->capacity = new_size;

    } else {
        status = true;
    }

    return status;
}

size_t cvector_capacity(cvector* obj) {
    if ( !obj ) {
        return 0;
    }

    return obj->capacity;
}

bool cvector_shrink_to_fit(cvector* obj) {
    if ( !obj ) {
        return true;
    }

    bool status = false;

    if ( obj->index > 0 ) {
        void** tmp = realloc(obj->array, obj->index * sizeof(void*));

        if ( tmp ) {
            obj->array = tmp;
            obj->capacity = obj->index;

        } else {
            status = true;
        }
    }

    return status;
}
