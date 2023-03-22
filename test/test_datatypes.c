#include "../src/data_types.h"
#include "../src/countplot.h"

#include <bsd/string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

// NOLINTBEGIN(*-magic-numbers)
// Test if the dataframe destructor actually frees memory successfully.
// Intended to be run with Valgrind.
Test(dataframe_free, simple_success) {

  char* test_string = "AbCD                ";
  size_t NUM_COLS = 3;
  size_t NUM_ROWS = 5;
  size_t str_len = strlen(test_string);

  Series* series_ptr = malloc(sizeof(Series) * NUM_COLS);

  for (size_t i = 0; i < NUM_COLS; i++) {
    strlcpy(series_ptr[i].name, test_string, str_len);
    series_ptr[i].numbers = (float*)malloc(sizeof(float) * NUM_ROWS);
  }

  Dataframe* dataframe = malloc(sizeof(Dataframe));

  dataframe->columns = series_ptr;
  dataframe->num_cols = 3;
  dataframe->num_rows = 5;

  cr_assert(zero(dataframe_free(dataframe)));
}

// Test if the count destructor actually frees memory successfully.
// Intended to be run with Valgrind.
Test(count_free, simple_success) {

  char* test_string = "AbCD                ";
  size_t NUM_COLS = 3;
  size_t NUM_ROWS = 5;
  size_t str_len = strlen(test_string);

  Series* series_ptr = malloc(sizeof(Series) * NUM_COLS);

  for (size_t i = 0; i < NUM_COLS; i++) {
    strlcpy(series_ptr[i].name, test_string, str_len);
    series_ptr[i].numbers = (float*)malloc(sizeof(float) * NUM_ROWS);
  }

  Dataframe* dataframe = malloc(sizeof(Dataframe));

  dataframe->columns = series_ptr;
  dataframe->num_cols = 3;
  dataframe->num_rows = 5;

  Count test_count = df_to_count(dataframe);

  cr_assert(zero(count_free(&test_count)));
}
// NOLINTEND(*-magic-numbers)
