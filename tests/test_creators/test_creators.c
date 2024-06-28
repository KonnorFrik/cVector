#include "../test.h"

void test_creators_create_zero_size(void** state) {
    size_t size = 0;
    cvector* obj = cvector_new(size);

    assert_non_null(obj);
    assert_non_null(obj->array);
    assert_int_equal(obj->index, 0);
    assert_int_equal(obj->capasity, size);

    cvector_delete(obj);
}

void test_creators_create_n_size(void** state) {
    size_t size = 3;
    cvector* obj = cvector_new(size);

    assert_non_null(obj);
    assert_non_null(obj->array);
    assert_int_equal(obj->index, 0);
    assert_int_equal(obj->capasity, size);

    cvector_delete(obj);
}

void test_creators_dtor_1(void** state) {
    size_t size = 3;
    cvector* obj = cvector_new(size);

    cvector_dtor(obj);

    assert_null(obj->array);
    assert_int_equal(obj->index, 0);
    assert_int_equal(obj->capasity, 0);

    cvector_delete(obj);
}

void test_creators_ctor_bad_1(void** state) {
    assert_true(cvector_ctor(NULL, 0));
}

