#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/array_helpers.h"

// NOLINTBEGIN(*-magic-numbers)
Test(find_mean, ascending_array) {
  float numbers[5] = {1, 2, 3, 4, 5};
  cr_assert(ieee_ulp_eq(flt, 3, find_mean(numbers, 5), 4));
}

Test(find_mean, negative_array) {
  float numbers[5] = {-4, 0, -1, -2, -3};
  cr_assert(ieee_ulp_eq(flt, -2, find_mean(numbers, 5), 4));
}

Test(find_mean, balanced) {
  float numbers[6] = {1, 1, 1, 4, 4, 4};
  cr_assert(ieee_ulp_eq(flt, 2.5, find_mean(numbers, 6), 4));
}

Test(find_mean, single_digit) {
  float numbers[1] = {(float) 5.0};
  cr_assert(ieee_ulp_eq(flt, 5.0, find_mean(numbers, 1), 4));
}
// NOLINTEND(*-magic-numbers)
