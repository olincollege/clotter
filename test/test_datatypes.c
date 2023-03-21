#include "../src/data_types.h"

#include <bsd/string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>



// NOLINTBEGIN(*-magic-numbers)
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
// NOLINTEND(*-magic-numbers)
