#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/array_helpers.h"

Test(find_max, ascending_array) {
  float numbers[5] = {1, 2, 3, 4, 5};
  cr_assert(eq(flt, 5, find_max(numbers, 5)));
}

Test(find_max, negative_array) {
  float numbers[5] = {-4, 0, -1, -2, -3};
  cr_assert(eq(flt, 0, find_max(numbers, 5)));
}

Test(find_max, single_digit) {
  float numbers[1] = {(float) 5.0};
  cr_assert(eq(flt, 5.0, find_max(numbers, 1)));
}
