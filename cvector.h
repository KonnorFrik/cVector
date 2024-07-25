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
// TODO: target for makefile: static and shared libs

/*
 * @mainpage
 * - cvector struct is fully open for user, be carefully while directly change it
 * - By design user may access only @Main functions. @Add-on funcs also acceptable, but not recomended
 * - FuncDesign:
 *      - Some func return common status-code (true, false). Some result of it work
 *      - In every unexpected situation 'false' will returns. It may be real error (can't allocate memory), or wrong argument passed, or anything else
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
// TODO: [ ] cvector_delete return new state of deleted object - always NULL
// variable can be fast overrided with new state! :)

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

/** @brief Search given object in storage
 * @param[in] obj    cvector object
 * @param[in] search some object for search
 * @return status true:FOUND false:ALL OTHERWISE
 * @version 0.1.0
 * @ingroup Main
 */
bool cvector_contain(cvector* obj, void* search);

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

/** @brief Increase inner memory and reallocate storage
 * @param[in, out] obj cvector object
 * @return status false:OK true:Error
 * @version 0.1.0
 * @ingroup Add-on
 */
bool cvector_increase_memory(cvector* obj);

#endif /* __CVECTOR_H__ */
