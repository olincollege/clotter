#include "../src/countplot.h"
#include "../src/data_types.h"

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

// NOLINTBEGIN
// Test that the functions returns the proper block widths for a
// "normal" batch of inputs.
Test(df_to_count, standard_inputs) {
  float data_numbers[3] = {(float)50.0, (float)25.0, (float)100.0};
  Series val1 = {.name = "TEST", .numbers = &data_numbers[0]};
  Series val2 = {.name = "JONATHAN", .numbers = &data_numbers[1]};
  Series val3 = {.name = "JENNIFER", .numbers = &data_numbers[2]};
  Series* cols[3] = {&val1,&val2,&val3};

  // pass a pointer to the first element rather than the full array
  // as expected by the function
  Dataframe dataframe = {.columns = cols[0], .num_cols = 3, .num_rows = 1};

  Count ac_count = df_to_count(&dataframe);

  int ex_numblocks[3] = {PLOT_WIDTH * 4, PLOT_WIDTH * 2, PLOT_WIDTH * 8};
  Count ex_count = {.dataframe = &dataframe, .numblocks = &ex_numblocks[0]};

  for (size_t i = 0; i < dataframe.num_cols; i++) {
    cr_assert(eq(ex_count.numblocks[i], ac_count.numblocks[i]));
  }

  free(ac_count.numblocks);
}
// NOLINTEND
