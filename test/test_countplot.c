#include "../src/countplot.c"
#include "../src/data_types.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

// TODO: make tests for small parts of this file

// Test that the functions returns the proper block widths for a
// "normal" batch of inputs.
Test(df_to_count, standard_inputs) {
  float o[3] = {50.0,25.0,100.0};
  Series val1 = {.name = "TEST", .numbers = &o[0]};
  Series val2 = {.name = "JONATHAN", .numbers = &o[1]};
  Series val3 = {.name = "JENNIFER", .numbers = &o[2]};
  Series* cols[3] = {&val1,&val2,&val3};

  // pass a pointer to the first element rather than the full array
  // as expected by the function
  Dataframe df = {.columns = cols[0], .num_cols = 3, .num_rows = 1};

  Count ac_count = df_to_count(&df);

  int ex_numblocks[3] = {PLOT_WIDTH * 4, PLOT_WIDTH * 2, PLOT_WIDTH * 8};
  Count ex_count = {.dataframe = &df, .numblocks = &ex_numblocks[0]};

  for (size_t i = 0; i < df.num_cols; i++) {
    cr_assert(eq(ex_count.numblocks[i], ac_count.numblocks[i]));
  }

  free(ac_count.numblocks);
}
