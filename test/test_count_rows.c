#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

#include "../src/csv2data.h"



Test(count_csv_lines, normal) {
  char* str = "../test/test_csvs/test.csv";
  int output = count_csv_lines(str);
  cr_assert(eq(output, 2));
}

// Test(count_csv_lines, empty) {
//   char* path = "/test_csvs/empty.csv";
//   cr_assert(eq(int, count_csv_lines(path), 0));
// }

// Test(count_csv_lines, negative) {
//   char* path = "/test_csvs/negative.csv";
//   cr_assert(eq(int, count_csv_lines(path), 3));
// }
