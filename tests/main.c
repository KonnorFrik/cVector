#include "test.h"
#include <stdio.h>

int main() {
    int all_results = 0;

    const struct CMUnitTest test_creators[] = {
        cmocka_unit_test(test_creators_create_zero_size),
        cmocka_unit_test(test_creators_create_n_size),
        cmocka_unit_test(test_creators_dtor_1),
        cmocka_unit_test(test_creators_ctor_bad_1),
    };
    all_results += cmocka_run_group_tests(test_creators, NULL, NULL);

    printf("\nBad tests count: %d\n\n", all_results);
    return all_results;
}
