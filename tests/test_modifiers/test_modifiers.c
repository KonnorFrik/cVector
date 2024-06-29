#include "../test.h"

void test_modifiers_push_back_1(void** state) {
    cvector* obj = cvector_new(0);

    assert_non_null(obj);

    int val = 123;

    assert_false(cvector_push_back(obj, &val));

    assert_int_equal(obj->index, 1);
    assert_int_equal(obj->capacity, 2);

    cvector_delete(obj);
}

void test_modifiers_push_back_2(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val = 123;

    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));

    assert_int_equal(obj->index, 3);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_push_back_3(void** state) {
    cvector* obj = cvector_new(0);

    assert_non_null(obj);

    int val = 123;

    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));
    assert_false(cvector_push_back(obj, &val));

    assert_int_equal(obj->index, 5);
    assert_int_equal(obj->capacity, 8);

    cvector_delete(obj);
}

void test_modifiers_push_back_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_push_back(NULL, NULL));
    assert_true(cvector_push_back(&obj, NULL));
}

void test_modifiers_pop_back_1(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val2);
    assert_ptr_equal(obj->array[2], &val3);

    assert_int_equal(obj->index, 3);
    assert_int_equal(obj->capacity, 4);

    assert_false(cvector_pop_back(obj));

    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val2);

    assert_int_equal(obj->index, 2);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_pop_back_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_pop_back(NULL));
    assert_true(cvector_pop_back(&obj));
}


void test_modifiers_clear_1(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val = 123;

    cvector_push_back(obj, &val);
    cvector_push_back(obj, &val);
    cvector_push_back(obj, &val);

    cvector_clear(obj);

    assert_int_equal(obj->index, 0);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_clear_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_clear(NULL));
    assert_true(cvector_clear(&obj));

}

void test_modifiers_insert_1(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val3);

    assert_false(cvector_insert(obj, 1, &val2));
    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val2);
    assert_ptr_equal(obj->array[2], &val3);

    assert_int_equal(obj->index, 3);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_insert_2(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val3);

    assert_false(cvector_insert(obj, 2, &val2));
    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val3);
    assert_ptr_equal(obj->array[2], &val2);

    assert_int_equal(obj->index, 3);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_insert_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_insert(NULL, 0, NULL));
    assert_true(cvector_insert(&obj, 0, NULL));
    obj.array = (void**)123;
    assert_true(cvector_insert(&obj, 2, NULL));
}

void test_modifiers_erase_1(void** state) {
    cvector* obj = cvector_new(2);

    assert_non_null(obj);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    cvector_push_back(obj, &val3);

    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val2);
    assert_ptr_equal(obj->array[2], &val3);

    assert_false(cvector_erase(obj, 1));

    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val3);

    assert_int_equal(obj->index, 2);
    assert_int_equal(obj->capacity, 4);

    cvector_delete(obj);
}

void test_modifiers_erase_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_erase(NULL, 0));
    assert_true(cvector_erase(&obj, 0));
    obj.array = (void**)123;
    assert_true(cvector_erase(&obj, 1));
}

void test_modifiers_swap_1(void** state) {
    cvector* obj = cvector_new(2);
    cvector* obj2 = cvector_new(0);

    assert_non_null(obj);

    int val1 = 1;
    int val2 = 2;
    int val3 = 3;

    cvector_push_back(obj, &val1);
    cvector_push_back(obj, &val2);
    assert_ptr_equal(obj->array[0], &val1);
    assert_ptr_equal(obj->array[1], &val2);
    assert_int_equal(obj->index, 2);
    assert_int_equal(obj->capacity, 2);

    cvector_push_back(obj2, &val3);
    assert_ptr_equal(obj2->array[0], &val3);
    assert_int_equal(obj2->index, 1);
    assert_int_equal(obj2->capacity, 2);

    assert_false(cvector_swap(obj, obj2));

    assert_ptr_equal(obj2->array[0], &val1);
    assert_ptr_equal(obj2->array[1], &val2);
    assert_int_equal(obj2->index, 2);
    assert_int_equal(obj2->capacity, 2);

    assert_ptr_equal(obj->array[0], &val3);
    assert_int_equal(obj->index, 1);
    assert_int_equal(obj->capacity, 2);

    cvector_delete(obj);
    cvector_delete(obj2);
}

void test_modifiers_swap_bad_1(void** state) {
    assert_true(cvector_swap(NULL, NULL));
}

void test_modifiers_inc_mem_bad_1(void** state) {
    cvector obj = {0};

    assert_true(cvector_increase_memory(NULL));
    assert_true(cvector_increase_memory(&obj));
}
