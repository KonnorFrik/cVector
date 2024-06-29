#include "../test.h"

void test_capacity_empty_1(void** state) {
    cvector* obj = cvector_new(0);

    assert_true(cvector_empty(obj));

    cvector_delete(obj);
}

void test_capacity_empty_2(void** state) {
    cvector* obj = cvector_new(0);

    cvector_push_back(obj, (void*)1);

    assert_false(cvector_empty(obj));

    cvector_delete(obj);
}

void test_capacity_empty_bad_1(void** state) {
    assert_true(cvector_empty(NULL));
}
void test_capacity_size_1(void** state) {
    cvector* obj = cvector_new(0);

    assert_int_equal(cvector_size(obj), 0);

    cvector_delete(obj);
}

void test_capacity_size_2(void** state) {
    cvector* obj = cvector_new(0);

    cvector_push_back(obj, (void*)123);

    assert_int_equal(cvector_size(obj), 1);

    cvector_delete(obj);
}

void test_capacity_size_bad_1(void** state) {
    assert_int_equal(cvector_size(NULL), 0);
}

void test_capacity_capacity_1(void** state) {
    cvector* obj = cvector_new(0);

    assert_int_equal(cvector_capacity(obj), 0);

    cvector_push_back(obj, (void*)123);
    assert_int_equal(cvector_capacity(obj), 2);

    cvector_push_back(obj, (void*)123);
    cvector_push_back(obj, (void*)123);
    assert_int_equal(cvector_capacity(obj), 4);

    cvector_delete(obj);
}

void test_capacity_capacity_bad_1(void** state) {
    assert_int_equal(cvector_capacity(NULL), 0);
}

void test_capacity_reserve_1(void** state) {
    cvector* obj = cvector_new(0);

    assert_int_equal(cvector_capacity(obj), 0);

    assert_false(cvector_reserve(obj, 2));
    assert_int_equal(cvector_capacity(obj), 2);

    assert_false(cvector_reserve(obj, 16));
    assert_int_equal(cvector_capacity(obj), 16);

    assert_true(cvector_reserve(obj, 8));
    assert_int_equal(cvector_capacity(obj), 16);

    cvector_delete(obj);
}

void test_capacity_reserve_bad_1(void** state) {
    assert_true(cvector_reserve(NULL, 2));
}

void test_capacity_shrink_to_fit_1(void** state) {
    cvector* obj = cvector_new(10);

    assert_int_equal(cvector_capacity(obj), 10);

    cvector_push_back(obj, (void*)123);
    cvector_push_back(obj, (void*)124);
    assert_int_equal(cvector_capacity(obj), 10);

    assert_false(cvector_shrink_to_fit(obj));
    assert_int_equal(cvector_capacity(obj), 2);

    cvector_delete(obj);
}

void test_capacity_shrink_to_fit_bad_1(void** state) {
    assert_true(cvector_shrink_to_fit(NULL));
}

