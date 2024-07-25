#include "../test.h"

void test_accessor_at_1(void** state) {
    cvector* obj = cvector_new(3);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(cvector_at(obj, 0), &val1);
    assert_ptr_equal(cvector_at(obj, 1), &val2);
    assert_ptr_equal(cvector_at(obj, 2), &val3);

    cvector_delete(obj);
}

void test_accessor_at_bad_1(void** state) {
    cvector obj = {0};

    assert_ptr_equal(cvector_at(NULL, 0), NULL);
    assert_ptr_equal(cvector_at(&obj, 1), NULL);
    obj.array = (void**)123;
    assert_ptr_equal(cvector_at(&obj, 2), NULL);
}

void test_accessor_front_1(void** state) {
    cvector* obj = cvector_new(3);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(cvector_front(obj), &val1);

    cvector_delete(obj);
}

void test_accessor_front_bad_1(void** state) {
    cvector obj = {0};

    assert_ptr_equal(cvector_front(NULL), NULL);
    assert_ptr_equal(cvector_front(&obj), NULL);
}

void test_accessor_back_1(void** state) {
    cvector* obj = cvector_new(3);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(cvector_back(obj), &val3);

    cvector_delete(obj);
}

void test_accessor_back_bad_1(void** state) {
    cvector obj = {0};

    assert_ptr_equal(cvector_back(NULL), NULL);
    assert_ptr_equal(cvector_back(&obj), NULL);
}

void test_accessor_data_1(void** state) {
    cvector* obj = cvector_new(3);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(cvector_data(obj), obj->array);
    void** arr = cvector_data(obj);
    assert_ptr_equal(arr[0], obj->array[0]);
    assert_ptr_equal(arr[1], obj->array[1]);
    assert_ptr_equal(arr[2], obj->array[2]);

    cvector_delete(obj);
}

void test_accessor_data_bad_1(void** state) {
    assert_ptr_equal(cvector_data(NULL), NULL);
}

void test_accessor_contain_1(void** state) {
    cvector* obj = cvector_new(3);

    int with = 1;
    int without = 2;

    cvector_push_back(obj, &with);

    assert_true(cvector_contain(obj, &with));
    assert_false(cvector_contain(obj, &without));

    cvector_delete(obj);
}

void test_accessor_contain_bad_1(void** state) {
    cvector* obj = cvector_new(0);

    int without = 2;

    assert_false(cvector_contain(NULL, &without));
    assert_false(cvector_contain(obj, &without));

    cvector_delete(obj);
}
