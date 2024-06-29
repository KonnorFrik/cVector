#include "../../cvector.h"

#include <stdlib.h>

// TODO: use memset here
bool cvector_clear(cvector* obj) {
    if ( !obj || !obj->array ) {
        return true;
    }

    bool status = false;
    
    for (size_t ind = 0; ind < obj->index; ++ind) {
        obj->array[ind] = NULL;
    }

    obj->index = 0;

    return status;
}

inline static void swap_void(void** v1, void** v2) {
    void* tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

bool cvector_insert(cvector* obj, size_t pos, void* element) {
    if ( !obj || !obj->array || pos > obj->index ) {
        return true;
    }

    if ( pos == obj->index ) {
        return cvector_push_back(obj, element);
    }

    bool status = false;

    if ( (obj->index + 1) >= obj->capacity ) {
        status = cvector_increase_memory(obj);
    }

    if ( !status ) {
        for (size_t ind = pos; ind < obj->index; ++ind) {
            swap_void(&(obj->array[ind]), &element);
        }
    }

    if ( !status ) {
        status = cvector_push_back(obj, element);
    }

    return status;
}

bool cvector_erase(cvector* obj, size_t pos) {
    if ( !obj || !obj->array || pos >= obj->index ) {
        return true;
    }

    bool status = false;
    obj->array[pos] = NULL;

    for (size_t ind = pos; (ind + 1) < obj->index; ++ind) {
        obj->array[ind] = obj->array[ind + 1];
    }

    obj->index--;
    // obj->array[obj->index] = NULL;

    return status;
}

bool cvector_push_back(cvector* obj, void* element) {
    if ( !obj || !obj->array ) {
        return true;
    }

    bool status = false;

    if ( obj->index >= obj->capacity ) {
        status = cvector_increase_memory(obj);
    }

    if ( !status ) {
        obj->array[obj->index++] = element;
    }
    
    return status;
}

bool cvector_pop_back(cvector* obj) {
    if ( !obj || !obj->array || obj->index == 0 ) {
        return true;
    }

    bool status = false;
    obj->array[--obj->index] = NULL;
    return status;
}

bool cvector_swap(cvector* obj_1, cvector* obj_2) {
    if ( !obj_1 || !obj_2 ) {
        return true;
    }

    bool status = false;

    cvector tmp = *obj_1;
    *obj_1 = *obj_2;
    *obj_2 = tmp;

    return status;
}

bool cvector_increase_memory(cvector* obj) {
    if ( !obj || !obj->array ) {
        return true;
    }

    bool status = false;
    size_t new_capacity = obj->capacity * 2;

    if ( new_capacity == 0 ) {
        new_capacity = 2;
    }

    void** tmp = realloc(obj->array, new_capacity * sizeof(void*));

    if ( tmp ) {
        obj->array = tmp;
        obj->capacity = new_capacity;

    } else {
        status = true;
    }

    return status;
}
