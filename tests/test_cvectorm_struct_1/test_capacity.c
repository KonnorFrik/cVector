#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_struct_foo_capacity_empty_good_1(void** state) {
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

    assert_true(cvectorm_empty(obj));
    cvectorm_push_back(obj, value_1);
    assert_false(cvectorm_empty(obj));

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_empty_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_true(cvectorm_empty(obj));

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_size_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);

    assert_int_equal(cvectorm_size(obj), 0);

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
    assert_int_equal(cvectorm_size(obj), 1);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_size_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal(cvectorm_size(obj), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_capacity_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal(cvectorm_capacity(obj), 0);
    cvectorm_ctor(obj, size);
    assert_int_equal(cvectorm_capacity(obj), 2);

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
    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_capacity_good_2(void** state) {
    UNUSED(state);
    size_t size = 0;
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal(cvectorm_capacity(obj), 0);
    cvectorm_ctor(obj, size);
    assert_int_equal(cvectorm_capacity(obj), 0);

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
    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_capacity_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal(cvectorm_capacity(obj), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_reserve_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};

    cvectorm_ctor(obj, size);
    assert_int_equal(cvectorm_capacity(obj), 2);

    cvectorm_reserve(obj, 4);
    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_reserve(obj, 8);
    assert_int_equal(cvectorm_capacity(obj), 8);

    cvectorm_reserve(obj, 4);
    assert_int_equal(cvectorm_capacity(obj), 8);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_reserve_good_2(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};

    assert_int_equal(cvectorm_capacity(obj), 0);

    cvectorm_reserve(obj, 4);
    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_reserve(obj, 8);
    assert_int_equal(cvectorm_capacity(obj), 8);

    cvectorm_reserve(obj, 4);
    assert_int_equal(cvectorm_capacity(obj), 8);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_shrink_to_fit_good_1(void** state) {
    UNUSED(state);
    size_t size = 4;
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

    cvectorm_ctor(obj, size);
    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_shrink_to_fit(obj);

    assert_int_equal(cvectorm_capacity(obj), 2);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_capacity_shrink_to_fit_bad_1(void** state) {
    UNUSED(state);
    size_t size = 4;
    cvectorm_make_name(struct_foo) obj = {0};

    cvectorm_ctor(obj, size);

    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_shrink_to_fit(obj);

    assert_int_equal(cvectorm_capacity(obj), 4);

    cvectorm_dtor(obj);
}

