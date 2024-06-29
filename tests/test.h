#ifndef __CVECTOR_TEST_H__
#define __CVECTOR_TEST_H__

// defaule cmocka includes
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

// for test
#include "../cvector.h"
#include <stdlib.h>

// creators
void test_creators_create_zero_size(void** state);
void test_creators_create_n_size(void** state);
void test_creators_dtor_1(void** state);
void test_creators_ctor_bad_1(void** state);
void test_creators_ctor_1(void** state);

// modifiers
void test_modifiers_push_back_1(void** state);
void test_modifiers_push_back_2(void** state);
void test_modifiers_push_back_bad_1(void** state);
void test_modifiers_pop_back_1(void** state);
void test_modifiers_pop_back_bad_1(void** state);
void test_modifiers_clear_1(void** state);
void test_modifiers_clear_bad_1(void** state);
void test_modifiers_insert_1(void** state);
void test_modifiers_insert_2(void** state);
void test_modifiers_insert_bad_1(void** state);
void test_modifiers_erase_1(void** state);
void test_modifiers_erase_bad_1(void** state);
void test_modifiers_swap_1(void** state);
void test_modifiers_swap_bad_1(void** state);
void test_modifiers_inc_mem_bad_1(void** state);

//accessors
void test_accessor_at_1(void** state);
void test_accessor_at_bad_1(void** state);
void test_accessor_front_1(void** state);
void test_accessor_front_bad_1(void** state);
void test_accessor_back_1(void** state);
void test_accessor_back_bad_1(void** state);
void test_accessor_data_1(void** state);
void test_accessor_data_bad_1(void** state);

#endif /* __CVECTOR_TEST_H__ */
