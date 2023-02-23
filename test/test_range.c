#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/data_handling.h"

Test(find_range, ascending_array) {
  float numbers[5] = {1, 2, 3, 4, 5};
  cr_assert(eq(flt, 4, find_range(numbers, 5)));
}

Test(find_range, negative_array) {
  float numbers[5] = {-4, 0, -1, -2, -3};
  cr_assert(eq(flt, 4, find_range(numbers, 5)));
}

Test(find_range, single_digit) {
  float numbers[1] = {5.0};
  cr_assert(eq(flt, 0.0, find_range(numbers, 1)));
}

Test(find_range, small_decimals) {
  float numbers[3] = {4.99, 5, 5.01};
  cr_assert(eq(flt, 0.02, find_range(numbers, 3)));
}
