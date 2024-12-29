#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_int_modifiers_push_back_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), value_1);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_push_back_bad_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};

    int value_1 = 42;
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 0);
    assert_int_equal(cvectorm_at(obj, 0), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_clear_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), value_1);

    cvectorm_clear(obj);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_clear_bad_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_clear(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_pop_back_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), value_1);

    cvectorm_pop_back(obj);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_pop_back_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(int) obj = {0};
    cvectorm_pop_back(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_pop_back_bad_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);
    cvectorm_pop_back(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_insert_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    cvectorm_push_back(obj, 1);
    cvectorm_push_back(obj, 3);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 1);
    assert_int_equal(cvectorm_at(obj, 1), 3);

    cvectorm_insert(obj, 1, 2);

    assert_int_equal(cvectorm_size(obj), 3);
    assert_int_equal(cvectorm_capacity(obj), 4);
    assert_int_equal(cvectorm_at(obj, 0), 1);
    assert_int_equal(cvectorm_at(obj, 1), 2);
    assert_int_equal(cvectorm_at(obj, 2), 3);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_insert_good_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    cvectorm_push_back(obj, 1);
    cvectorm_push_back(obj, 2);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 1);
    assert_int_equal(cvectorm_at(obj, 1), 2);

    cvectorm_insert(obj, 2, 3);

    assert_int_equal(cvectorm_size(obj), 3);
    assert_int_equal(cvectorm_capacity(obj), 4);
    assert_int_equal(cvectorm_at(obj, 0), 1);
    assert_int_equal(cvectorm_at(obj, 1), 2);
    assert_int_equal(cvectorm_at(obj, 2), 3);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_insert_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(int) obj = {0};
    cvectorm_insert(obj, 0, 2);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_insert_bad_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);
    cvectorm_insert(obj, 42, 1);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_erase_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    cvectorm_push_back(obj, 1);
    cvectorm_push_back(obj, 2);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 1);
    assert_int_equal(cvectorm_at(obj, 1), 2);

    cvectorm_erase(obj, 0);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 2);

    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_erase_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(int) obj = {0};
    cvectorm_erase(obj, 0);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_erase_bad_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);
    cvectorm_erase(obj, 42);
    cvectorm_dtor(obj);
}

void test_cvectorm_int_modifiers_swap_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) positive = {0};
    cvectorm_make_name(int) negative = {0};

    cvectorm_ctor(positive, size);
    cvectorm_ctor(negative, size);

    cvectorm_push_back(positive, 1);
    cvectorm_push_back(negative, -1);

    assert_int_equal(cvectorm_at(positive, 0), 1);
    assert_int_equal(cvectorm_at(negative, 0), -1);

    cvectorm_swap(positive, negative);

    assert_int_equal(cvectorm_at(positive, 0), -1);
    assert_int_equal(cvectorm_at(negative, 0), 1);

    cvectorm_dtor(positive);
    cvectorm_dtor(negative);
}

