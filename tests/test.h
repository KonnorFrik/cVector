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

void test_creators_create_zero_size(void** state);
void test_creators_create_n_size(void** state);
void test_creators_dtor_1(void** state);
void test_creators_ctor_bad_1(void** state);

#endif /* __CVECTOR_TEST_H__ */
