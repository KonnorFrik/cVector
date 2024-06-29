/** @file
 * cVector is a container for store pointers to any other objects
 */

 /** @defgroup Main
 * Library elements (functions, enums, etc) which user can use by design
 */

 /** @defgroup Add-on
 * Library elements (functions, enums, etc) which user don't need to use by design, but can be accessed by user in a specific situations
 */
#ifndef __CVECTOR_H__
#define __CVECTOR_H__

#include <stddef.h>
#include <stdbool.h>

/*
 * Rules:
 * - Is struct open for user ?
 * - User can access only @Main functions
 * - FuncDesign:
 *      - What func must return (Status, Data, Mixed) ? Mixed
 *          - If func return status, what type is it (int, uint8_t, typedef'ed enum) ? bool
 *          - If func return status, this is true,false or more specific status-code ? true-false
 *      - What to do if can't allocate memory ? return false as error
 *      - All func have prefix cvector_*
 */

/** @brief cvector struct
 * @version 0.1.0
 */
struct cvector_ {
    void** array; ///< main storage
    size_t index; ///< index to next-to-write element
    size_t capacity; ///< maximum elements with current allocated memory
};

typedef struct cvector_ cvector;

// TODO: [X] Create & delete
// [IT] new - arg: size; return pointer to a new cvector object; call ctor     @Main
// [IT] ctor - arg: size, cvector; allow size = 0; init cvector struct inside           @Add-on
// [IT] dtor - delete cvector ONLY inside                                      @Add-on
// [IT] delete - arg: pointer to cvector; Call dtor, safe free pointer         @Main

/** @brief Allocate and create new cvector object
 * @param[in] size Initial size of cvector storage
 * @return object New cvector object or NULL if can't allocate memory
 * @version 0.1.0
 * @ingroup Main
 */
cvector* cvector_new(size_t size);

/** @brief Allocate inside and init given cvector object
 * @param[out] obj cvector object for init inside 
 * @param[in]      size Initial size of cvector storage
 * @return status false:OK, true:Error 
 * @version 0.1.0
 * @ingroup Add-on
 */
bool cvector_ctor(cvector* obj, size_t size);

/** @brief Destroy and free all inside of given object
 * @param[in, out] obj cvector object for destroy
 * @version 0.1.0
 * @ingroup Add-on
 */
void cvector_dtor(cvector* obj);

/** @brief Delete(free) given object
 * @param[in, out] obj cvector object for delete
 * @version 0.1.0
 * @ingroup Main
 */
void cvector_delete(cvector* obj);
// TODO: cvector_delete return new state of deleted object - always NULL
// variable can be fast overrided with new state


// TODO: [ ] element access
// [ ] at - arg: position; return element at specified position
// [ ] front - return first element
// [ ] back - return last element
// [ ] data - return pointer to raw array with data

/** @brief access specified element with bounds checking
 * @param[in] obj cvector object
 * @param[in] pos Position for access
 * @return ptr Pointer to stored object or NULL if error occurred
 * @version 0.1.0
 * @ingroup Main
 */
void* cvector_at(cvector* obj, size_t pos);

/** @brief access first element
 * @param[in] obj cvector object
 * @return ptr Pointer to stored object or NULL if error occurred
 * @version 0.1.0
 * @ingroup Main
 */
void* cvector_front(cvector* obj);

/** @brief access last element
 * @param[in] obj cvector object
 * @return ptr Pointer to stored object or NULL if error occurred
 * @version 0.1.0
 * @ingroup Main
 */
void* cvector_back(cvector* obj);

/** @brief Raw access to cvector storage
 * @param[in] obj cvector object
 * @return ptr Pointer to storage of object or NULL if error occurred
 * @version 0.1.0
 * @ingroup Main
 */
void* cvector_data(cvector* obj);


// TODO: [ ] capacity
// [ ] empty - is object empty
// [ ] size - return size of writed objects
// [ ] reserve - arg: size; allocate more memory
// [ ] capacity - returns the number of elements that can be held in currently allocated storage
// [ ] shrink_to_fit - reduces memory usage by freeing unused memory

/** @brief Status is storage empty
 * @param[in] obj cvector object
 * @return status true:Empty false:Otherwise
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_empty(cvector* obj);

/** @brief Count of already stored elements
 * @param[in] obj cvector object
 * @return size 
 * @version 0.1.0
 * @ingroup Main
 */
size_t cvector_size(cvector* obj);

/** @brief Allocate more memory inside of given object
 * @param[in] obj cvector object
 * @param[in] new_size New bigger count for store
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_reserve(cvector* obj, size_t new_size);

/** @brief Get current possible count of elements to write
 * @param[in] obj cvector object
 * @return capacity 
 * @version 0.1.0
 * @ingroup Main
 */
size_t cvector_capacity(cvector* obj);

/** @brief Reduce memory 
 * @param[in] obj cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_shrink_to_fit(cvector* obj);


// TODO: [ ] modifiers
// [I ] clear - clears the contents
// [I ] insert - arg: position; inserts elements into concrete position
// [I ] erase - arg: position; erases element at pos
// [I ] push_back - arg: pointer to any object; append new pointer at the end
// [I ] pop_back - delete pointer from end
// [I ] swap - arg: cvector; swaps the contents

/** @brief Clear all storage
 * @param[in] obj cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_clear(cvector* obj);


/** @brief Insert given element at given position
 * @param[in, out] obj cvector object
 * @param[in]      pos Position for insert
 * @param[in]      element Element for insert
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_insert(cvector* obj, size_t pos, void* element);

/** @brief Delete element from given position
 * @param[in, out] obj cvector object
 * @param[in]      pos Position for erase
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_erase(cvector* obj, size_t pos);

/** @brief Append given element at the end
 * @param[in, out] obj cvector object
 * @param[in]      element Element for append
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_push_back(cvector* obj, void* element);

/** @brief Delete element from the end
 * @param[in, out] obj cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_pop_back(cvector* obj);

/** @brief Swap content of two objects
 * @param[in, out] obj_1 cvector object
 * @param[in, out] obj_2 cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_swap(cvector* obj_1, cvector* obj_2);


// TODO: [ ] Add-ons
// [I ] increase_memory - arg: cvector; increase memory with formula capacity = capacity * 2

/** @brief Increase inner memory and reallocate storage
 * @param[in, out] obj cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Add-on
 */
bool cvector_increase_memory(cvector* obj);

#endif /* __CVECTOR_H__ */
