#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/csv2data.h"

Test(count_row_length, normal) {
  char* str = "../test/test_csvs/test.csv";
  cr_assert(eq(int, count_row_length(str), 11));
}
