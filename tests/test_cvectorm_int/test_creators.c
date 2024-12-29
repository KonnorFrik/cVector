#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_int_creators_zero_size(void** state) {
    UNUSED(state);
    size_t size = 0;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    assert_non_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, size);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_creators_n_size(void** state) {
    UNUSED(state);
    size_t size = 3;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    assert_non_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, size);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_creators_dtor_1(void** state) {
    UNUSED(state);
    size_t size = 3;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    assert_non_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, size);

    cvectorm_dtor(obj);

    assert_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, 0);
}

void test_cvectorm_int_creators_dtor_2(void** state) {
    UNUSED(state);
    size_t size = 3;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    assert_non_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, size);

    cvectorm_dtor(obj);
    cvectorm_dtor(obj);

    assert_null(obj.array);
    assert_int_equal(obj.index, 0);
    assert_int_equal(obj.capacity, 0);
}
