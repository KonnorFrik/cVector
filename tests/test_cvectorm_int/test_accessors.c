#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_int_accessors_at_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    int value_2 = 123456;

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    assert_int_equal(cvectorm_at(obj, 0), value_1);
    assert_int_equal(cvectorm_at(obj, 1), value_2);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_at_bad_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};

    assert_int_equal(cvectorm_at(obj, 0), 0);
    cvectorm_ctor(obj, size);
    assert_int_equal(cvectorm_at(obj, 1), 0);
    assert_int_equal(cvectorm_at(obj, 99), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_front_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    int value_2 = 123456;

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    assert_int_equal(cvectorm_front(obj), value_1);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_front_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(int) obj = {0};

    assert_int_equal(cvectorm_front(obj), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_back_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    int value_2 = 123456;

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    assert_int_equal(cvectorm_back(obj), value_2);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_back_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(int) obj = {0};

    assert_int_equal(cvectorm_back(obj), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_data_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    int value_2 = 123456;

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    int* data = cvectorm_data(obj);

    assert_int_equal(data[0], value_1);
    assert_int_equal(data[1], value_2);
    assert_ptr_equal(data, obj.array);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_data_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(int) obj = {0};

    assert_ptr_equal(cvectorm_data(obj), NULL);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_contain_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 1;
    int value_2 = 42;

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, 2);

    int result = 0;
    cvectorm_contain(obj, value_1, result);
    assert_true(result);

    cvectorm_contain(obj, value_2, result);
    assert_false(result);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_accessors_contain_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(int) obj = {0};

    int value_1 = 1;
    int result = 0;
    cvectorm_contain(obj, value_1, result);
    assert_false(result);

    cvectorm_dtor(obj);
}
