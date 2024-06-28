#include "../../cvector.h"

#include <stdlib.h>

cvector* cvector_new(size_t size) {
    cvector* object = calloc(1, sizeof(cvector));

    if ( cvector_ctor(object, size) ) {
        cvector_delete(object);
        object = NULL;
    }

    return object;
}

bool cvector_ctor(cvector* obj, size_t size) {
    if ( !obj ) {
        return true;
    }

    bool status = false;
    obj->array = calloc(size, sizeof(void*));
    obj->index = 0;
    obj->capasity = 0;

    if ( obj->array ) {
        obj->capasity = size;

    } else {
        status = true;
    }

    return status;
}

void cvector_dtor(cvector* obj) {
    if ( !obj ) {
        return;
    }

    if ( obj->array ) {
        free(obj->array);
        obj->array = NULL;
    }

    obj->index = obj->capasity = 0;
}

void cvector_delete(cvector* obj) {
    cvector_dtor(obj);

    if ( obj ) {
        free(obj);
    }
}
