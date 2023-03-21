#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/csv2data.h"

Test(count_csv_lines, normal) {
  char* path = "/test_csvs/test.csv";
  cr_assert(eq(int, 2, count_csv_lines(path)));
}

Test(count_csv_lines, empty) {
  char* path = "/test_csvs/empty.csv";
  cr_assert(eq(int, 0, count_csv_lines(path)));
}

Test(count_csv_lines, negative) {
  char* path = "/test_csvs/negative.csv";
  cr_assert(eq(int, 3, count_csv_lines(path)));
}
