#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/data_handling.h"

Test(find_min, descending_array) {
  float numbers[5] = {5, 4, 3, 2, 1};
  cr_assert(eq(flt, 1, find_min(numbers, 5)));
}

Test(find_min, negative_array) {
  float numbers[5] = {-1, 0, -4, -3, -2};
  cr_assert(eq(flt, -4, find_min(numbers, 5)));
}

Test(find_min, single_digit) {
  float numbers[1] = {5.0};
  cr_assert(eq(flt, 5.0, find_min(numbers, 1)));
}
