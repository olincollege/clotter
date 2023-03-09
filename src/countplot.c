#include "array_helpers.h"
#include "constants.h"
#include "data_types.h"

#include <ctype.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: mode into a helper function

static Count df_to_count(Dataframe* df) {

  // place data values in its own array of length num_rows
  // for find_max_scalar and easier iteration later
  float* values = (float*)malloc(sizeof(float) * df->num_cols);
  for (size_t i = 0; i < df->num_cols; i++) {
    values[i] = df->columns[i].numbers[0];
  }

  // initialize a scalar to keep plot lengths at a max length
  float max_scalar = find_max_scalar(values, df->num_cols, PLOT_WIDTH);

  // create array of length df->num_rows
  // to store the number of 1/8 charwidth blocks to plot
  int* numblocks = (int*)malloc(sizeof(int) * df->num_cols);
  for (size_t i = 0; i < df->num_cols; i++) {
    // scale by max_scalar to keep within plot bounds
    // scale by 1/8 because we plot with 1/8 resolution
    numblocks[i] = (int)floor(values[i] * max_scalar * 8);
  }
  // done with values
  free(values);

  Count out_count;
  out_count.dataframe = df;
  out_count.numblocks = numblocks;

  return out_count;
}

static void pad(int width, int length) {
  // pads a string by the width minus the length
  // printf("%i %i",width, length);
  for (int i = 0; i < (size_t)width - length; i++) {
    printf(" ");
  }
}

static void blocks(int nblocks) {
  // returns a string of length PLOT_WIDTH filled with scale many blocks,
  // resolution 1/8.
  float scale = (float)(nblocks) / 8;
  int b_ = (int)floor(scale);
  char output[PLOT_WIDTH - b_];

  for (int i = 0; i < b_; i++) {
    printf("%s", WHOLE_BLOCK);
  }
  char* complement = "";
  // determine complement for blocks
  int state = nblocks % 8;

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
    // for some godforsaken reason need this case to catch float to int
    // weirdness
    complement = "";
  }
  printf("%s", complement);
  pad(PLOT_WIDTH, b_);
}

int display_count(Count ct, int num_colors) {
  // unsure if this will continue to work with the new structs
  // -- need length of series array
  printf("Number of colors: %i, Number of bars: %zu\n", num_colors,
         ct.dataframe->num_cols);
  pad(NAME_SPACE, 0);
  printf(" %s\n", TOP_LEFT_CORNER);
  for (size_t i = 0; i < ct.dataframe->num_cols; i++) {
    // name of row
    printf(" %s", ct.dataframe->columns[i].name);
    // pad size of name with total number of chars

    pad(NAME_SPACE, strlen(ct.dataframe->columns[i].name));

    printf(LEFT_TICK);

    switch (i % num_colors) {
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
    blocks(ct.numblocks[i]);
    printf(RESET);
    // value in row
    // TODO: error catch incorrect format of data being handed off.
    printf("  %f\n", ct.dataframe->columns[i].numbers[0]);
  }
  free(ct.numblocks);
  pad(NAME_SPACE, 0);
  printf(" %s\n", BOTTOM_LEFT_CORNER);
  return 0;
}
// TODO: explain this test case
int main(void) {

  int nc = 4;
  float o1 = 600;
  float o2 = 200;
  float o3 = 1400;
  float o4 = 500;

  Series val1 = {
      .name = "TESTtest",
      .numbers = &o1,
  };
  Series val2 = {
      .name = "JONATHAN",
      .numbers = &o2,
  };
  Series val3 = {
      .name = "JENNIFER",
      .numbers = &o3,
  };
  Series val4 = {
      .name = "LARRYLARRY",
      .numbers = &o4,
  };

  Series* cols = (Series*)malloc(sizeof(Series) * 4);
  cols[0] = val1;
  cols[1] = val2;
  cols[2] = val3;
  cols[3] = val4;
  Dataframe v = {.columns = cols, .num_cols = 4, .num_rows = 1};

  Count ct = df_to_count(&v);

  display_count(ct, nc);
  free(cols);

  return 0;
}
