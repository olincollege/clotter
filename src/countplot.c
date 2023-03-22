#include "array_helpers.h"
#include "constants.h"
#include "countplot.h"
#include "data_types.h"

#include <ctype.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This code makes heavy use of a magic number, 8.
 * This is due to the Unicode standard including 8 sub-blocks within
 * a single character block, so we can display values in the x-direction
 * with a higher resolution.
 *
 * Any such magic numbers are delinted.
 */

Count df_to_count(Dataframe* dataframe) {

  // place data values in its own array of length num_rows
  // for find_max_scalar and easier iteration later
  float* values = (float*)malloc(sizeof(float) * dataframe->num_cols);
  for (size_t i = 0; i < dataframe->num_cols; i++) {
    values[i] = dataframe->columns[i].numbers[0];
  }

  // initialize a scalar to keep plot lengths at a max length
  float max_scalar = find_max_scalar(values, dataframe->num_cols, PLOT_WIDTH);

  // create array of length dataframe->num_rows
  // to store the number of 1/8 charwidth blocks to plot
  int* numblocks = (int*)malloc(sizeof(int) * dataframe->num_cols);
  for (size_t i = 0; i < dataframe->num_cols; i++) {
    // scale by max_scalar to keep within plot bounds
    // scale by our block resolution to create number of sub-blocks
    // NOLINTNEXTLINE(*-magic-numbers)
    numblocks[i] = (int)floorf(values[i] * max_scalar * 8);
  }
  // done with values
  free(values);

  Count out_count;
  out_count.dataframe = dataframe;
  out_count.numblocks = numblocks;

  return out_count;
}

static void pad(size_t width, size_t length) {
  // pads a string by the width minus the length
  // printf("%i %i",width, length);
  for (size_t i = 0; i < width - length; i++) {
    printf(" ");
  }
}

static void blocks(int nblocks) {
  // returns a string of length PLOT_WIDTH filled with scale many blocks
  // NOLINTNEXTLINE(*-magic-numbers)
  float scale = (float)(nblocks) / 8;
  int num_whole = (int)floorf(scale);

  for (int i = 0; i < num_whole; i++) {
    printf("%s", WHOLE_BLOCK);
  }
  char* complement = "";
  // determine complement for blocks
  // NOLINTNEXTLINE(*-magic-numbers)
  int state = nblocks % 8;

  // once again we delint for magic numbers, since the 8 cases we have
  // are hardcoded into Unicode.
  // NOLINTBEGIN(*-magic-numbers)
  switch (state) {
  case 1:
    complement = BLOCK_1;
    break;
  case 2:
    complement = BLOCK_2;
    break;
  case 3:
    complement = BLOCK_3;
    break;
  case 4:
    complement = BLOCK_4;
    break;
  case 5:
    complement = BLOCK_5;
    break;
  case 6:
    complement = BLOCK_6;
    break;
  case 7:
    complement = BLOCK_7;
    break;
  case 8:
    complement = BLOCK_8;
    break;
  case 0:
    // for some godforsaken reason need this case to catch
    // float to int weirdness
    complement = "";
    break;
  default:
    complement = "";
  }
  // NOLINTEND(*-magic-numbers)

  printf("%s", complement);
  pad(PLOT_WIDTH, (size_t)num_whole);
}

int display_count(Count count, int num_colors) {
  printf("Number of colors: %i, Number of bars: %zu\n", num_colors,
         count.dataframe->num_cols);
  pad(NAME_SPACE, (size_t)0);
  printf(" %s\n", TOP_LEFT_CORNER);
  for (size_t i = 0; i < count.dataframe->num_cols; i++) {
    // name of row
    printf(" %s", count.dataframe->columns[i].name);
    // pad size of name with total number of chars

    pad(NAME_SPACE, (size_t)strlen(count.dataframe->columns[i].name));

    printf(LEFT_TICK);

    // Again, this is hardcoded due to the limit on the number of 3-bit
    // terminal colors that are able to be displayed.
    // NOLINTBEGIN(*-magic-numbers)
    switch ((int)i % num_colors) {
    case 6:
      printf(MAG);
      break;
    case 5:
      printf(WHT);
      break;
    case 4:
      printf(BLU);
      break;
    case 3:
      printf(YEL);
      break;
    case 2:
      printf(CYN);
      break;
    case 1:
      printf(RED);
      break;
    case 0:
      printf(GRN);
      break;
    }
    // NOLINTEND(*-magic-numbers)
    blocks(count.numblocks[i]);
    printf(RESET);
    // value in row
    printf("  %f\n", count.dataframe->columns[i].numbers[0]);
  }
  free(count.numblocks);
  pad(NAME_SPACE, 0);
  printf(" %s\n", BOTTOM_LEFT_CORNER);
  return 0;
}
