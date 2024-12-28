#ifndef __CVECTOR_MACROS_H__
#define __CVECTOR_MACROS_H__

#include <stdlib.h>

/** @brief */
#define cvectorm_make_name(type) cvector_##type

/** @brief */
#define cvectorm_make_ptr(type) cvector_##type*

/** @brief */
#define cvectorm_declare(type) \
    typedef struct {           \
        type* array;           \
        size_t index;          \
        size_t capacity;       \
    } cvectorm_make_name(type)

// =====
// Creators
// =====
#define cvectorm_ctor(cvectorm_var, size)                                            \
    (cvectorm_var).array = calloc((size), sizeof(__typeof__(*(cvectorm_var).array))); \
    if ( (cvectorm_var).array != NULL ) {                                            \
        (cvectorm_var).capacity = (size);                                            \
    }

#define cvectorm_dtor(cvectorm_var)       \
    if ( (cvectorm_var).array != NULL ) { \
        free((cvectorm_var).array);       \
        (cvectorm_var).array = NULL;      \
        (cvectorm_var).index = 0;         \
        (cvectorm_var).capacity = 0;      \
    }

// =====
// Accessors
// =====
#define cvectorm_at(cvectorm_var, pos)           \
    (                                            \
        (cvectorm_var).array == NULL ||          \
        (pos) >= (cvectorm_var).index            \
    )                                            \
        ? (__typeof__(*(cvectorm_var).array)){0} \
        : (cvectorm_var).array[(pos)]

#define cvectorm_front(cvectorm_var) \
    ( \
        (cvectorm_var).array == NULL \
    ) \
        ? (__typeof__(*(cvectorm_var).array)){0} \
        : (cvectorm_var).array[0]

#define cvectorm_back(cvectorm_var) \
    ( \
        (cvectorm_var).array == NULL || \
        (cvectorm_var).index == 0 \
    ) \
        ? (__typeof__(*(cvectorm_var).array)){0} \
        : (cvectorm_var).array[(cvectorm_var).index - 1]

#define cvectorm_data(cvectorm_var) ((cvectorm_var).array)

#define cvectorm_contain(cvectorm_var, search_var, result_var) \
    result_var = 0; \
    if ( (cvectorm_var).array != NULL ) { \
      for ( size_t i = 0; i < (cvectorm_var).index; ++i) { \
          result_var |= (cvectorm_var).array[i] == (search_var); \
      } \
    }

// =====
// Capacity
// =====
#define cvectorm_empty(cvectorm_var) ((cvectorm_var).index == 0)

#define cvectorm_size(cvectorm_var) ((cvectorm_var).index)

#define cvectorm_reserve(cvectorm_var, new_size) \
    if ( (new_size) > (cvectorm_var).capacity ) { \
        void* tmp = realloc((cvectorm_var).array, (new_size) * sizeof(__typeof__(*(cvectorm_var).array))); \
        if ( tmp != NULL ) { \
            (cvectorm_var).array = tmp; \
            (cvectorm_var).capacity = new_size; \
        } \
    }

#define cvectorm_capacity(cvectorm_var) ((cvectorm_var).capacity)

#define cvectorm_shrink_to_fit(cvectorm_var) \
    if ( (cvectorm_var).index > 0 && (cvectorm_var).index < (cvectorm_var).capacity ) { \
        void* tmp = realloc((cvectorm_var).array, (cvectorm_var).index * sizeof(__typeof__(*(cvectorm_var).array))); \
        if ( tmp != NULL ) { \
            (cvectorm_var).array = tmp; \
            (cvectorm_var).capacity = (cvectorm_var).index; \
        } \
    }

// =====
// Modifiers
// =====
#define cvectorm_clear(cvectorm_var) \
    if ( (cvectorm_var).array != NULL ) { \
        memset((cvectorm_var).array, (__typeof__(*(cvectorm_var).array)){0}, (cvectorm_var).capacity); \
        (cvectorm_var).index = 0; \
    }

#define cvectorm_push_back(cvectorm_var, value) \
    if ( (cvectorm_var).array != NULL ) { \
        if ( (cvectorm_var).index >= (cvectorm_var).capacity ) { \
            size_t new_size = (cvectorm_var).capacity * 2; \
            new_size = new_size == 0 ? 2 : new_size; \
            void* tmp = realloc((cvectorm_var).array, new_size * sizeof(__typeof__(*(cvectorm_var).array))); \
            if ( tmp != NULL ) { \
                (cvectorm_var).array = tmp; \
                (cvectorm_var).capacity = new_size; \
            } \
        } \
        (cvectorm_var).array[(cvectorm_var).index++] = value; \
    }

#define cvectorm_pop_back(cvectorm_var) \
    if ( (cvectorm_var).array != NULL || (cvectorm_var).index > 0 ) { \
        (cvectorm_var).array[--(cvectorm_var).index] = (__typeof__(*(cvectorm_var).array)){0}; \
    }

#endif /* __CVECTOR_MACROS_H__ */
