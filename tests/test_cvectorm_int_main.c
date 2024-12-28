#include "test.h"
#include <stdio.h>

void test_cvectorm_int_creators_zero_size(void** state);
void test_cvectorm_int_creators_n_size(void** state);
void test_cvectorm_int_creators_dtor_1(void** state);

void test_cvectorm_int_modifiers_push_back_good_1(void** state);

void test_cvectorm_int_accessors_at_good_1(void** state);
void test_cvectorm_int_accessors_at_bad_1(void** state);
void test_cvectorm_int_accessors_front_good_1(void** state);
void test_cvectorm_int_accessors_front_bad_1(void** state);
void test_cvectorm_int_accessors_back_good_1(void** state);
void test_cvectorm_int_accessors_back_bad_1(void** state);
void test_cvectorm_int_accessors_data_good_1(void** state);
void test_cvectorm_int_accessors_data_bad_1(void** state);
void test_cvectorm_int_accessors_contain_good_1(void** state);
void test_cvectorm_int_accessors_contain_bad_1(void** state);

void test_cvectorm_int_capacity_empty_good_1(void** state);
void test_cvectorm_int_capacity_empty_bad_1(void** state);
void test_cvectorm_int_capacity_size_good_1(void** state);
void test_cvectorm_int_capacity_size_bad_1(void** state);
void test_cvectorm_int_capacity_capacity_good_1(void** state);
void test_cvectorm_int_capacity_capacity_good_2(void** state);
void test_cvectorm_int_capacity_capacity_bad_1(void** state);
void test_cvectorm_int_capacity_reserve_good_1(void** state);
void test_cvectorm_int_capacity_reserve_good_2(void** state);
void test_cvectorm_int_capacity_shrink_to_fit_good_1(void** state);
void test_cvectorm_int_capacity_shrink_to_fit_bad_1(void** state);

int main() {
    int all_results = 0;

    const struct CMUnitTest test_creators[] = {
        cmocka_unit_test(test_cvectorm_int_creators_zero_size),
        cmocka_unit_test(test_cvectorm_int_creators_n_size),
        cmocka_unit_test(test_cvectorm_int_creators_dtor_1),
    };

    // modifiers tests
    const struct CMUnitTest test_modifiers[] = {
        cmocka_unit_test(test_cvectorm_int_modifiers_push_back_good_1),
    };

    // access tests
    const struct CMUnitTest test_accessors[] = {
        cmocka_unit_test(test_cvectorm_int_accessors_at_good_1),
        cmocka_unit_test(test_cvectorm_int_accessors_at_bad_1),
        cmocka_unit_test(test_cvectorm_int_accessors_front_good_1),
        cmocka_unit_test(test_cvectorm_int_accessors_front_bad_1),
        cmocka_unit_test(test_cvectorm_int_accessors_back_good_1),
        cmocka_unit_test(test_cvectorm_int_accessors_back_bad_1),
        cmocka_unit_test(test_cvectorm_int_accessors_data_good_1),
        cmocka_unit_test(test_cvectorm_int_accessors_data_bad_1),
        cmocka_unit_test(test_cvectorm_int_accessors_contain_good_1),
        cmocka_unit_test(test_cvectorm_int_accessors_contain_bad_1),
    };

    // capacity tests
    const struct CMUnitTest test_capacity[] = {
        cmocka_unit_test(test_cvectorm_int_capacity_empty_good_1),
        cmocka_unit_test(test_cvectorm_int_capacity_empty_bad_1),
        cmocka_unit_test(test_cvectorm_int_capacity_size_good_1),
        cmocka_unit_test(test_cvectorm_int_capacity_size_bad_1),
        cmocka_unit_test(test_cvectorm_int_capacity_capacity_good_1),
        cmocka_unit_test(test_cvectorm_int_capacity_capacity_good_2),
        cmocka_unit_test(test_cvectorm_int_capacity_capacity_bad_1),
        cmocka_unit_test(test_cvectorm_int_capacity_reserve_good_1),
        cmocka_unit_test(test_cvectorm_int_capacity_reserve_good_2),
        cmocka_unit_test(test_cvectorm_int_capacity_shrink_to_fit_good_1),
        cmocka_unit_test(test_cvectorm_int_capacity_shrink_to_fit_bad_1),
    };

    all_results += cmocka_run_group_tests(test_creators, NULL, NULL);
    all_results += cmocka_run_group_tests(test_modifiers, NULL, NULL);
    all_results += cmocka_run_group_tests(test_accessors, NULL, NULL);
    all_results += cmocka_run_group_tests(test_capacity, NULL, NULL);

    printf("\nBad tests count: %d\n\n", all_results);
    return all_results;
}
