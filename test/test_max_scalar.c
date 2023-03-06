#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/array_helpers.h"

Test(find_max_scalar, ascending_array) {
  float numbers[5] = {1, 2, 3, 4, 5};
  cr_assert(ieee_ulp_eq(flt, 1, find_max_scalar(numbers, 5, 5), 4));
}

Test(find_max_scalar, negative_array) {
  float numbers[5] = {-4, 0, -1, -2, -3};
  cr_assert(ieee_ulp_eq(flt, (5.0 / -4.0), find_max_scalar(numbers, 5, 5), 4));
}

Test(find_max_scalar, single_digit) {
  float numbers[1] = {(float) 5.0};
  cr_assert(ieee_ulp_eq(flt, 2.0, find_max_scalar(numbers, 1, 10), 4));
}
