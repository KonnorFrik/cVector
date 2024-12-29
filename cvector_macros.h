#ifndef __CVECTOR_MACROS_H__
#define __CVECTOR_MACROS_H__

#include <stdlib.h>
#include <string.h>

/** @brief */
#define cvectorm_make_name(type) cvectorm_##type

/** @brief */
#define cvectorm_make_ptr(type) cvectorm_##type*

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
#define cvectorm_ctor(self, size)                                            \
    (self).array = calloc((size), sizeof(__typeof__(*(self).array))); \
    if ( (self).array != NULL ) {                                            \
        (self).capacity = (size);                                            \
    }

#define cvectorm_dtor(self)       \
    if ( (self).array != NULL ) { \
        free((self).array);       \
        (self).array = NULL;      \
        (self).index = 0;         \
        (self).capacity = 0;      \
    }

// =====
// Accessors
// =====
#define cvectorm_at(self, pos)           \
    (                                            \
        (self).array == NULL ||          \
        (pos) >= (self).index            \
    )                                            \
        ? (__typeof__(*(self).array)){0} \
        : (self).array[(pos)]

#define cvectorm_front(self) \
    ( \
        (self).array == NULL \
    ) \
        ? (__typeof__(*(self).array)){0} \
        : (self).array[0]

#define cvectorm_back(self) \
    ( \
        (self).array == NULL || \
        (self).index == 0 \
    ) \
        ? (__typeof__(*(self).array)){0} \
        : (self).array[(self).index - 1]

#define cvectorm_data(self) ((self).array)

#define cvectorm_contain(self, search_var, result_var) \
    result_var = 0; \
    if ( (self).array != NULL ) { \
      for ( size_t i = 0; i < (self).index; ++i) { \
          result_var |= (memcmp(&(self).array[i], &(search_var), sizeof(search_var)) == 0); \
      } \
    }

// =====
// Capacity
// =====
#define cvectorm_empty(self) ((self).index == 0)

#define cvectorm_size(self) ((self).index)

#define cvectorm_reserve(self, new_size) \
    if ( (new_size) > (self).capacity ) { \
        void* tmp = realloc((self).array, (new_size) * sizeof(__typeof__(*(self).array))); \
        if ( tmp != NULL ) { \
            (self).array = tmp; \
            (self).capacity = new_size; \
        } \
    }

#define cvectorm_capacity(self) ((self).capacity)

#define cvectorm_shrink_to_fit(self) \
    if ( (self).index > 0 && (self).index < (self).capacity ) { \
        void* tmp = realloc((self).array, (self).index * sizeof(__typeof__(*(self).array))); \
        if ( tmp != NULL ) { \
            (self).array = tmp; \
            (self).capacity = (self).index; \
        } \
    }

// =====
// Modifiers
// =====
#define cvectorm_clear(self) \
    if ( (self).array != NULL ) { \
        memset((self).array, (__typeof__(*(self).array)){0}, (self).capacity); \
        (self).index = 0; \
    }

#define cvectorm_insert(self, pos, element) \
    if ( (self).array != NULL && (pos) <= (self).index ) { \
        if ( (pos) == (self).index ) { \
            cvectorm_push_back((self), (element)); \
        } else { \
            __typeof__(*(self).array) element_copy = (element); \
            for (size_t i = (pos); i < (self).index; ++i) { \
                __typeof__(*(self).array) tmp = (self).array[i]; \
                (self).array[i] = element_copy; \
                element_copy = tmp; \
            } \
            cvectorm_push_back((self), element_copy); \
        } \
    }

#define cvectorm_erase(self, pos) \
    if ( (self).array != NULL && (pos) < (self).index ) { \
        for (size_t i = (pos); (i + 1) < (self).index; ++i) { \
            (self).array[i] = (self).array[i + 1]; \
        } \
        --(self).index; \
    }

#define cvectorm_push_back(self, value) \
    if ( (self).array != NULL ) { \
        if ( (self).index >= (self).capacity ) { \
            size_t new_size = (self).capacity * 2; \
            new_size = new_size == 0 ? 2 : new_size; \
            void* tmp = realloc((self).array, new_size * sizeof(__typeof__(*(self).array))); \
            if ( tmp != NULL ) { \
                (self).array = tmp; \
                (self).capacity = new_size; \
            } \
        } \
        (self).array[(self).index++] = value; \
    }

#define cvectorm_pop_back(self) \
    if ( (self).array != NULL || (self).index > 0 ) { \
        (self).array[--(self).index] = (__typeof__(*(self).array)){0}; \
    }

#define cvectorm_swap(self, other) \
{ \
    __auto_type tmp = (self); \
    (self) = (other); \
    (other) = tmp; \
}

#endif /* __CVECTOR_MACROS_H__ */
