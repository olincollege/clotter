#include "../src/data_types.h"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

// NOLINTBEGIN(*-magic-numbers)
Test(dataframe_free, simple_success) {

  size_t NUM_COLS = 3;
  size_t NUM_ROWS = 5;

  Series* series_ptr = malloc(sizeof(Series) * NUM_COLS);

  for (size_t i = 0; i < NUM_COLS; i++) {
    strcpy(series_ptr[i].name, "AbCD                ");
    series_ptr[i].numbers = malloc(sizeof(float) * NUM_ROWS);
  }

  Dataframe* dataframe = malloc(sizeof(Dataframe));

  dataframe->columns = series_ptr;
  dataframe->num_cols = 3;
  dataframe->num_rows = 5;

  cr_assert(zero(dataframe_free(dataframe)));
}
// NOLINTEND(*-magic-numbers)
