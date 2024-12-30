/** @file
 * @brief Implementation of cvector macros version
 */
#ifndef __CVECTOR_MACROS_H__
#define __CVECTOR_MACROS_H__

#include <stdlib.h>
#include <string.h>

/** @brief Create type name for declared struct */
#define cvectorm_make_name(type) cvectorm_##type

/** @brief Create a struct of typed cvector with given type */
#define cvectorm_declare(type)  \
    typedef struct {            \
        type* array;            \
        size_t index;           \
        size_t capacity;        \
    } cvectorm_make_name(type)

// =====
// Creators
// =====

/** @brief Constructor for cvectorm
 * @param[in, out] self cvectorm struct variable
 * @param[in]      size Initial size (count of elements)
 */
#define cvectorm_ctor(self, size)                                            \
    (self).array = calloc((size), sizeof(__typeof__(*(self).array))); \
    if ( (self).array != NULL ) {                                            \
        (self).capacity = (size);                                            \
    }

/** @brief Destructor for cvectorm
 * @param[in, out] self cvectorm struct variable
 */
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

// TODO: change ternary 

/** @brief Get element at given position
 * @param[in] self cvectorm struct variable
 * @param[in] pos  Index of element in range [0, .index] not inclusive .index
 * @return Element at position or null version of element
 */
#define cvectorm_at(self, pos)            \
    (                                     \
        (self).array == NULL ||           \
        (pos) >= (self).index             \
    )                                     \
        ? (__typeof__(*(self).array)){0}  \
        : (self).array[(pos)]

/** @brief Get first element
 * @param[in] self cvectorm struct variable
 * @return Element at index 0 or null version of element
 */
#define cvectorm_front(self) \
    ( \
        (self).array == NULL \
    ) \
        ? (__typeof__(*(self).array)){0} \
        : (self).array[0]

/** @brief Get last element
 * @param[in] self cvectorm struct variable
 * @return Element at last index or null version of element
 */
#define cvectorm_back(self) \
    ( \
        (self).array == NULL || \
        (self).index == 0 \
    ) \
        ? (__typeof__(*(self).array)){0} \
        : (self).array[(self).index - 1]

/** @brief Get raw array of elements
 * @param[in] self cvectorm struct variable
 * @return Pointer to raw array of stored elements
 */
#define cvectorm_data(self) ((self).array)

/** @brief Check if given element is in storage
 *
 * The 'result_var' will be always overwrite with 0 before search
 *
 * @param[in] self cvectorm struct variable
 * @param[in]      search_var Variable for search
 * @param[in, out] result_var Variable with result (0 - Not contain, 1 - Contain)
 */
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

/** @brief Check if storage is empty
 * @param[in] self cvectorm struct variable
 * @return 0 - Not empty, 1 - Empty
 */
#define cvectorm_empty(self) ((self).index == 0)

/** @brief Get current size of storage
 * @param[in] self cvectorm struct variable
 * @return actual size
 */
#define cvectorm_size(self) ((self).index)

/** @brief Reallocate more memory for storage
 *
 * Reallocate only if 'new_size' is bigger then actual size 
 *
 * @param[in, out] self     cvectorm struct variable
 * @param[in]      new_size New count of elements
 */
#define cvectorm_reserve(self, new_size) \
    if ( (new_size) > (self).capacity ) { \
        void* tmp = realloc((self).array, (new_size) * sizeof(__typeof__(*(self).array))); \
        if ( tmp != NULL ) { \
            (self).array = tmp; \
            (self).capacity = (new_size); \
        } \
    }

/** @brief Get current capacity of storage
 * @param[in] self cvectorm struct variable
 * @return actual capacity
 */
#define cvectorm_capacity(self) ((self).capacity)

/** @brief Reallocate memory to smaller size
 *
 * Reallocate only if actual size less then actual capacity
 *
 * @param[in] self cvectorm struct variable
 */
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

/** @brief Set null version of element for all of them
 * @param[in, out] self cvectorm struct variable
 */
#define cvectorm_clear(self) \
    if ( (self).array != NULL ) { \
        memset((self).array, 0, (self).capacity); \
        (self).index = 0; \
    }

/** @brief Add new element at given position
 * @param[in, out] self cvectorm struct variable
 * @param[in]      pos  Position for insert in range [0, .index] inclusive .index
 * @param[in]      element Element for insert
 */
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

/** @brief Delete element at given position
 * @param[in, out] self cvectorm struct variable
 * @param[in]      pos  Position for delete in range [0, .index] not inclusive .index
 */
#define cvectorm_erase(self, pos) \
    if ( (self).array != NULL && (pos) < (self).index ) { \
        for (size_t i = (pos); (i + 1) < (self).index; ++i) { \
            (self).array[i] = (self).array[i + 1]; \
        } \
        --(self).index; \
    }

/** @brief Add new element at the end of storage
 *
 * Reallocate memory to bigger if needed
 *
 * @param[in, out] self cvectorm struct variable
 * @param[in]      element Element for add
 */
#define cvectorm_push_back(self, element) \
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
        (self).array[(self).index++] = (element); \
    }

/** @brief Set null version of element in the end of storage
 * @param[in, out] self cvectorm struct variable
 */
#define cvectorm_pop_back(self) \
    if ( (self).array != NULL && (self).index > 0 ) { \
        (self).array[--(self).index] = (__typeof__(*(self).array)){0}; \
    }

/** @brief Swap 2 cvectorm's with only one type
 * @param[in, out] self  cvectorm struct variable
 * @param[in, out] other cvectorm struct variable
 */
#define cvectorm_swap(self, other) \
{ \
    __auto_type tmp = (self); \
    (self) = (other); \
    (other) = tmp; \
}

#endif /* __CVECTOR_MACROS_H__ */
