#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_struct_foo_accessors_at_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    cvectorm_push_back(obj, value_1);

    assert_int_equal((cvectorm_at(obj, 0)).ia, value_1.ia);
    assert_int_equal((cvectorm_at(obj, 0)).ib, value_1.ib);
    assert_float_equal((cvectorm_at(obj, 0)).fa, value_1.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).fb, value_1.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 0)).pca, value_1.pca);

    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 0)).struct_inner.pca, value_1.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_at_bad_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal((cvectorm_at(obj, 0)).ia, 0);
    assert_int_equal((cvectorm_at(obj, 0)).ib, 0);
    assert_float_equal((cvectorm_at(obj, 0)).fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 0)).pca, NULL);

    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ia, 0);
    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ib, 0);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 0)).struct_inner.pca, NULL);

    cvectorm_ctor(obj, size);

    assert_int_equal((cvectorm_at(obj, 1)).ia, 0);
    assert_int_equal((cvectorm_at(obj, 1)).ib, 0);
    assert_float_equal((cvectorm_at(obj, 1)).fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 1)).pca, NULL);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, 0);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, 0);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 1)).struct_inner.pca, NULL);

    assert_int_equal((cvectorm_at(obj, 99)).ia, 0);
    assert_int_equal((cvectorm_at(obj, 99)).ib, 0);
    assert_float_equal((cvectorm_at(obj, 99)).fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 99)).fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 99)).pca, NULL);

    assert_int_equal((cvectorm_at(obj, 99)).struct_inner.ia, 0);
    assert_int_equal((cvectorm_at(obj, 99)).struct_inner.ib, 0);
    assert_float_equal((cvectorm_at(obj, 99)).struct_inner.fa, 0, 1e-5);
    assert_float_equal((cvectorm_at(obj, 99)).struct_inner.fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_at(obj, 99)).struct_inner.pca, NULL);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_front_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    cvectorm_push_back(obj, value_1);

    assert_int_equal((cvectorm_front(obj)).ia, value_1.ia);
    assert_int_equal((cvectorm_front(obj)).ib, value_1.ib);
    assert_float_equal((cvectorm_front(obj)).fa, value_1.fa, 1e-5);
    assert_float_equal((cvectorm_front(obj)).fb, value_1.fb, 1e-5);
    assert_string_equal((cvectorm_front(obj)).pca, value_1.pca);

    assert_int_equal((cvectorm_front(obj)).struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal((cvectorm_front(obj)).struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal((cvectorm_front(obj)).struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_front(obj)).struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_front(obj)).struct_inner.pca, value_1.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_front_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal((cvectorm_front(obj)).ia, 0);
    assert_int_equal((cvectorm_front(obj)).ib, 0);
    assert_float_equal((cvectorm_front(obj)).fa, 0, 1e-5);
    assert_float_equal((cvectorm_front(obj)).fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_front(obj)).pca, NULL);

    assert_int_equal((cvectorm_front(obj)).struct_inner.ia, 0);
    assert_int_equal((cvectorm_front(obj)).struct_inner.ib, 0);
    assert_float_equal((cvectorm_front(obj)).struct_inner.fa, 0, 1e-5);
    assert_float_equal((cvectorm_front(obj)).struct_inner.fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_front(obj)).struct_inner.pca, NULL);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_back_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    cvectorm_push_back(obj, value_1);

    assert_int_equal((cvectorm_back(obj)).ia, value_1.ia);
    assert_int_equal((cvectorm_back(obj)).ib, value_1.ib);
    assert_float_equal((cvectorm_back(obj)).fa, value_1.fa, 1e-5);
    assert_float_equal((cvectorm_back(obj)).fb, value_1.fb, 1e-5);
    assert_string_equal((cvectorm_back(obj)).pca, value_1.pca);

    assert_int_equal((cvectorm_back(obj)).struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal((cvectorm_back(obj)).struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal((cvectorm_back(obj)).struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_back(obj)).struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_back(obj)).struct_inner.pca, value_1.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_back_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal((cvectorm_back(obj)).ia, 0);
    assert_int_equal((cvectorm_back(obj)).ib, 0);
    assert_float_equal((cvectorm_back(obj)).fa, 0, 1e-5);
    assert_float_equal((cvectorm_back(obj)).fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_back(obj)).pca, NULL);

    assert_int_equal((cvectorm_back(obj)).struct_inner.ia, 0);
    assert_int_equal((cvectorm_back(obj)).struct_inner.ib, 0);
    assert_float_equal((cvectorm_back(obj)).struct_inner.fa, 0, 1e-5);
    assert_float_equal((cvectorm_back(obj)).struct_inner.fb, 0, 1e-5);
    assert_ptr_equal((cvectorm_back(obj)).struct_inner.pca, NULL);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_data_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    cvectorm_push_back(obj, value_1);

    struct_foo* data = cvectorm_data(obj);

    assert_int_equal(data[0].ia, value_1.ia);
    assert_int_equal(data[0].ib, value_1.ib);
    assert_float_equal(data[0].fa, value_1.fa, 1e-5);
    assert_float_equal(data[0].fb, value_1.fb, 1e-5);
    assert_string_equal(data[0].pca, value_1.pca);

    assert_int_equal(data[0].struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal(data[0].struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal(data[0].struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal(data[0].struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal(data[0].struct_inner.pca, value_1.struct_inner.pca);

    assert_ptr_equal(data, obj.array);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_data_bad_1(void** state) {
    size_t size = 2;
    UNUSED(state);
    UNUSED(size);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_ptr_equal(cvectorm_data(obj), NULL);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_contain_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    cvectorm_push_back(obj, value_1);

    int result = 0;
    cvectorm_contain(obj, value_1, result);
    assert_true(result);

    value_1.ia = 33;

    cvectorm_contain(obj, value_1, result);
    assert_false(result);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_accessors_contain_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};

    struct_foo value_1 = {
        .ia = 1, .ib = -2,
        .fa = 1.11f, .fb = -0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = -2,
            .fa = 1.11f, .fb = -0.1234f,
            .pca = "world",
        },
    };

    int result = 0;
    cvectorm_contain(obj, value_1, result);
    assert_false(result);

    cvectorm_dtor(obj);
}
