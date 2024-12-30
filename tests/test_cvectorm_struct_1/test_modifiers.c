#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

void test_cvectorm_struct_foo_modifiers_push_back_good_1(void** state) {
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

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);

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

void test_cvectorm_struct_foo_modifiers_push_back_bad_1(void** state) {
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

    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 0);

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

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_clear_good_1(void** state) {
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

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);

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

    cvectorm_clear(obj);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);

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

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_clear_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_clear(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_pop_back_good_1(void** state) {
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

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);

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

    cvectorm_pop_back(obj);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);

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

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_pop_back_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_pop_back(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_pop_back_bad_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);
    cvectorm_pop_back(obj);
    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_insert_good_1(void** state) {
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

    struct_foo value_2 = {
        .ia = 2, .ib = -3,
        .fa = 2.11f, .fb = -1.1234f,
        .pca = "hello world",

        .struct_inner = {
            .ia = 2, .ib = -3,
            .fa = 2.11f, .fb = -1.1234f,
            .pca = "world bye",
        },
    };

    struct_foo value_3 = {
        .ia = 0, .ib = -1,
        .fa = 0.11f, .fb = 1.1234f,
        .pca = "first string",

        .struct_inner = {
            .ia = 0, .ib = -1,
            .fa = 2.11f, .fb = -1.1234f,
            .pca = "second string",
        },
    };

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_3);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);

    // ========= 1st value
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

    // ========= 3rd value
    assert_int_equal((cvectorm_at(obj, 1)).ia, value_3.ia);
    assert_int_equal((cvectorm_at(obj, 1)).ib, value_3.ib);
    assert_float_equal((cvectorm_at(obj, 1)).fa, value_3.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, value_3.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).pca, value_3.pca);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, value_3.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, value_3.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, value_3.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, value_3.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).struct_inner.pca, value_3.struct_inner.pca);

    cvectorm_insert(obj, 1, value_2);

    assert_int_equal(cvectorm_size(obj), 3);
    assert_int_equal(cvectorm_capacity(obj), 4);

    // ========= 1st value
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

    // ========= 2nd value
    assert_int_equal((cvectorm_at(obj, 1)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(obj, 1)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(obj, 1)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).struct_inner.pca, value_2.struct_inner.pca);

    // ========= 3rd value
    assert_int_equal((cvectorm_at(obj, 2)).ia, value_3.ia);
    assert_int_equal((cvectorm_at(obj, 2)).ib, value_3.ib);
    assert_float_equal((cvectorm_at(obj, 2)).fa, value_3.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 2)).fb, value_3.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 2)).pca, value_3.pca);

    assert_int_equal((cvectorm_at(obj, 2)).struct_inner.ia, value_3.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 2)).struct_inner.ib, value_3.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 2)).struct_inner.fa, value_3.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 2)).struct_inner.fb, value_3.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 2)).struct_inner.pca, value_3.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_insert_good_2(void** state) {
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

    struct_foo value_2 = {
        .ia = 2, .ib = -3,
        .fa = 2.11f, .fb = -1.1234f,
        .pca = "hello world",

        .struct_inner = {
            .ia = 2, .ib = -3,
            .fa = 2.11f, .fb = -1.1234f,
            .pca = "world bye",
        },
    };

    struct_foo value_3 = {
        .ia = 0, .ib = -1,
        .fa = 0.11f, .fb = 1.1234f,
        .pca = "first string",

        .struct_inner = {
            .ia = 0, .ib = -1,
            .fa = 2.11f, .fb = -1.1234f,
            .pca = "second string",
        },
    };

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);

    // ========= 1st value
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

    // ========= 2nd value
    assert_int_equal((cvectorm_at(obj, 1)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(obj, 1)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(obj, 1)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).struct_inner.pca, value_2.struct_inner.pca);

    cvectorm_insert(obj, 2, value_3);

    assert_int_equal(cvectorm_size(obj), 3);
    assert_int_equal(cvectorm_capacity(obj), 4);

    // ========= 1st value
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

    // ========= 2nd value
    assert_int_equal((cvectorm_at(obj, 1)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(obj, 1)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(obj, 1)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).struct_inner.pca, value_2.struct_inner.pca);

    // ========= 3rd value
    assert_int_equal((cvectorm_at(obj, 2)).ia, value_3.ia);
    assert_int_equal((cvectorm_at(obj, 2)).ib, value_3.ib);
    assert_float_equal((cvectorm_at(obj, 2)).fa, value_3.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 2)).fb, value_3.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 2)).pca, value_3.pca);

    assert_int_equal((cvectorm_at(obj, 2)).struct_inner.ia, value_3.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 2)).struct_inner.ib, value_3.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 2)).struct_inner.fa, value_3.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 2)).struct_inner.fb, value_3.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 2)).struct_inner.pca, value_3.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_insert_bad_1(void** state) {
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

    cvectorm_insert(obj, 0, value_1);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 0);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_insert_bad_2(void** state) {
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

    cvectorm_insert(obj, 42, value_1);

    assert_int_equal(cvectorm_size(obj), 0);
    assert_int_equal(cvectorm_capacity(obj), 2);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_erase_good_1(void** state) {
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

    struct_foo value_2 = {
        .ia = 2, .ib = -3,
        .fa = 2.11f, .fb = -1.1234f,
        .pca = "hello world",

        .struct_inner = {
            .ia = 2, .ib = -3,
            .fa = 2.11f, .fb = -1.1234f,
            .pca = "world bye",
        },
    };

    cvectorm_push_back(obj, value_1);
    cvectorm_push_back(obj, value_2);

    assert_int_equal(cvectorm_size(obj), 2);
    assert_int_equal(cvectorm_capacity(obj), 2);

    // ========= 1st value
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

    // ========= 2nd value
    assert_int_equal((cvectorm_at(obj, 1)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(obj, 1)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(obj, 1)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 1)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 1)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 1)).struct_inner.pca, value_2.struct_inner.pca);

    cvectorm_erase(obj, 0);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);

    // ========= 2nd value
    assert_int_equal((cvectorm_at(obj, 0)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(obj, 0)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(obj, 0)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 0)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(obj, 0)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(obj, 0)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(obj, 0)).struct_inner.pca, value_2.struct_inner.pca);

    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_erase_bad_1(void** state) {
    UNUSED(state);
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_erase(obj, 0);
    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_erase_bad_2(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) obj = {0};
    cvectorm_ctor(obj, size);
    cvectorm_erase(obj, 42);
    cvectorm_dtor(obj);
}

void test_cvectorm_struct_foo_modifiers_swap_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(struct_foo) positive = {0};
    cvectorm_make_name(struct_foo) negative = {0};

    cvectorm_ctor(positive, size);
    cvectorm_ctor(negative, size);

    struct_foo value_1 = {
        .ia = 1, .ib = 2,
        .fa = 1.11f, .fb = 0.1234f,
        .pca = "hello",

        .struct_inner = {
            .ia = 1, .ib = 2,
            .fa = 1.11f, .fb = 0.1234f,
            .pca = "world",
        },
    };

    struct_foo value_2 = {
        .ia = -1, .ib = -2,
        .fa = -1.11f, .fb = -0.1234f,
        .pca = "hello world",

        .struct_inner = {
            .ia = -1, .ib = -2,
            .fa = -1.11f, .fb = -0.1234f,
            .pca = "world bye",
        },
    };

    cvectorm_push_back(positive, value_1);
    cvectorm_push_back(negative, value_2);

    // ========= 1st value
    assert_int_equal((cvectorm_at(positive, 0)).ia, value_1.ia);
    assert_int_equal((cvectorm_at(positive, 0)).ib, value_1.ib);
    assert_float_equal((cvectorm_at(positive, 0)).fa, value_1.fa, 1e-5);
    assert_float_equal((cvectorm_at(positive, 0)).fb, value_1.fb, 1e-5);
    assert_string_equal((cvectorm_at(positive, 0)).pca, value_1.pca);

    assert_int_equal((cvectorm_at(positive, 0)).struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal((cvectorm_at(positive, 0)).struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal((cvectorm_at(positive, 0)).struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(positive, 0)).struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(positive, 0)).struct_inner.pca, value_1.struct_inner.pca);

    // ========= 2nd value
    assert_int_equal((cvectorm_at(negative, 0)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(negative, 0)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(negative, 0)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(negative, 0)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(negative, 0)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(negative, 0)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(negative, 0)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(negative, 0)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(negative, 0)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(negative, 0)).struct_inner.pca, value_2.struct_inner.pca);

    cvectorm_swap(positive, negative);

    // ========= 2nd value
    assert_int_equal((cvectorm_at(positive, 0)).ia, value_2.ia);
    assert_int_equal((cvectorm_at(positive, 0)).ib, value_2.ib);
    assert_float_equal((cvectorm_at(positive, 0)).fa, value_2.fa, 1e-5);
    assert_float_equal((cvectorm_at(positive, 0)).fb, value_2.fb, 1e-5);
    assert_string_equal((cvectorm_at(positive, 0)).pca, value_2.pca);

    assert_int_equal((cvectorm_at(positive, 0)).struct_inner.ia, value_2.struct_inner.ia);
    assert_int_equal((cvectorm_at(positive, 0)).struct_inner.ib, value_2.struct_inner.ib);
    assert_float_equal((cvectorm_at(positive, 0)).struct_inner.fa, value_2.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(positive, 0)).struct_inner.fb, value_2.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(positive, 0)).struct_inner.pca, value_2.struct_inner.pca);

    // ========= 1st value
    assert_int_equal((cvectorm_at(negative, 0)).ia, value_1.ia);
    assert_int_equal((cvectorm_at(negative, 0)).ib, value_1.ib);
    assert_float_equal((cvectorm_at(negative, 0)).fa, value_1.fa, 1e-5);
    assert_float_equal((cvectorm_at(negative, 0)).fb, value_1.fb, 1e-5);
    assert_string_equal((cvectorm_at(negative, 0)).pca, value_1.pca);

    assert_int_equal((cvectorm_at(negative, 0)).struct_inner.ia, value_1.struct_inner.ia);
    assert_int_equal((cvectorm_at(negative, 0)).struct_inner.ib, value_1.struct_inner.ib);
    assert_float_equal((cvectorm_at(negative, 0)).struct_inner.fa, value_1.struct_inner.fa, 1e-5);
    assert_float_equal((cvectorm_at(negative, 0)).struct_inner.fb, value_1.struct_inner.fb, 1e-5);
    assert_string_equal((cvectorm_at(negative, 0)).struct_inner.pca, value_1.struct_inner.pca);

    cvectorm_dtor(positive);
    cvectorm_dtor(negative);
}

