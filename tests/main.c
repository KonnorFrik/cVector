#include "test.h"
#include <stdio.h>

int main() {
    int all_results = 0;

    const struct CMUnitTest test_creators[] = {
        cmocka_unit_test(test_creators_create_zero_size),
        cmocka_unit_test(test_creators_create_n_size),
        cmocka_unit_test(test_creators_dtor_1),
        cmocka_unit_test(test_creators_ctor_bad_1),
        cmocka_unit_test(test_creators_ctor_1),
    };
    // push tests
    const struct CMUnitTest test_modifiers[] = {
        cmocka_unit_test(test_modifiers_push_back_1),
        cmocka_unit_test(test_modifiers_push_back_2),
        cmocka_unit_test(test_modifiers_push_back_3),
        cmocka_unit_test(test_modifiers_push_back_bad_1),
        cmocka_unit_test(test_modifiers_pop_back_1),
        cmocka_unit_test(test_modifiers_pop_back_bad_1),
        cmocka_unit_test(test_modifiers_clear_1),
        cmocka_unit_test(test_modifiers_clear_bad_1),
        cmocka_unit_test(test_modifiers_insert_1),
        cmocka_unit_test(test_modifiers_insert_2),
        cmocka_unit_test(test_modifiers_insert_bad_1),
        cmocka_unit_test(test_modifiers_erase_1),
        cmocka_unit_test(test_modifiers_erase_bad_1),
        cmocka_unit_test(test_modifiers_swap_1),
        cmocka_unit_test(test_modifiers_swap_bad_1),
        cmocka_unit_test(test_modifiers_inc_mem_bad_1),
    };

    // access tests
    const struct CMUnitTest test_accessors[] = {
        cmocka_unit_test(test_accessor_at_1),
        cmocka_unit_test(test_accessor_at_bad_1),
        cmocka_unit_test(test_accessor_front_1),
        cmocka_unit_test(test_accessor_front_bad_1),
        cmocka_unit_test(test_accessor_back_1),
        cmocka_unit_test(test_accessor_back_bad_1),
        cmocka_unit_test(test_accessor_data_1),
        cmocka_unit_test(test_accessor_data_bad_1),
        cmocka_unit_test(test_accessor_contain_1),
        cmocka_unit_test(test_accessor_contain_bad_1),
    };

    const struct CMUnitTest test_capacity[] = {
        cmocka_unit_test(test_capacity_empty_1),
        cmocka_unit_test(test_capacity_empty_2),
        cmocka_unit_test(test_capacity_empty_bad_1),
        cmocka_unit_test(test_capacity_size_1),
        cmocka_unit_test(test_capacity_size_2),
        cmocka_unit_test(test_capacity_size_bad_1),
        cmocka_unit_test(test_capacity_capacity_1),
        cmocka_unit_test(test_capacity_capacity_bad_1),
        cmocka_unit_test(test_capacity_reserve_1),
        cmocka_unit_test(test_capacity_reserve_bad_1),
        cmocka_unit_test(test_capacity_shrink_to_fit_1),
        cmocka_unit_test(test_capacity_shrink_to_fit_bad_1),
    };

    all_results += cmocka_run_group_tests(test_creators, NULL, NULL);
    all_results += cmocka_run_group_tests(test_modifiers, NULL, NULL);
    all_results += cmocka_run_group_tests(test_accessors, NULL, NULL);
    all_results += cmocka_run_group_tests(test_capacity, NULL, NULL);

    printf("\nBad tests count: %d\n\n", all_results);
    return all_results;
}
