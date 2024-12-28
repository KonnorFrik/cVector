#include "../test.h"
#include "../../cvector_macros.h"
#include <cmocka.h>

cvectorm_declare(int);

void test_cvectorm_int_modifiers_push_back_good_1(void** state) {
    UNUSED(state);
    size_t size = 2;
    cvectorm_make_name(int) obj = {0};
    cvectorm_ctor(obj, size);

    int value_1 = 42;
    cvectorm_push_back(obj, value_1);

    assert_int_equal(cvectorm_size(obj), 1);
    assert_int_equal(cvectorm_capacity(obj), 2);
    assert_int_equal(cvectorm_at(obj, 0), 42);

    cvectorm_dtor(obj);
}


