#include "data_types.h"
#include "array_helpers.h"
#include "constants.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: mode into a helper function

static Count df_to_count(const Dataframe df) {

  // place data values in its own array of length num_rows
  // for find_max_scalar and easier iteration later
  float* values = malloc(sizeof(float) * df.num_rows);
  for (size_t i = 0; i < df.num_rows; i++) {
    values[i] = df.columns[i].numbers[0];
  }

  // initialize a scalar to keep plot lengths at a max length
  float max_scalar = find_max_scalar(values, df.num_rows, PLOT_WIDTH);

  // create array of length df.num_rows
  // to store the number of 1/8 charwidth blocks to plot
  int* numblocks = malloc(sizeof(int) * df.num_rows);
  for (size_t i = 0; i < df.num_rows; i++) {
    // scale by max_scalar to keep within plot bounds
    // scale by 1/8 because we plot with 1/8 resolution
    numblocks[i] = (int)floor(values[i] * max_scalar * (float)8);
  }
  // done with values
  free(values);

  Count out_count = {.dataframe = df, .numblocks = numblocks};

  return out_count;
}

static void blocks(int* nblocks) {
  // returns a string of length 20 filled with scale many blocks, resolution
  // 1/8.
  char* whole_block = "\U00002588";
  float scale = (float)*nblocks / 8;
  int b_ = floor(scale);
  char output[21 - b_];

  for (int i = 0; i < b_; i++) {
    printf("%s", whole_block);
  }
  char* complement = "";
  // determine complement for blocks
  int state = (int)round((scale - (float)b_) * 8);
  switch (state) {
  case 1:
    complement = "\U0000258F";
    break;
  case 2:
    complement = "\U0000258E";
    break;
  case 3:
    complement = "\U0000258D";
    break;
  case 4:
    complement = "\U0000258C";
    break;
  case 5:
    complement = "\U0000258B";
    break;
  case 6:
    complement = "\U0000258A";
    break;
  case 7:
    complement = "\U00002589";
    break;
  case 8:
    complement = "\U00002588";
    break;
  case 0:
    // for some godforsaken reason need this case to catch float to int
    // weirdness
    complement = "";
  }
  printf("%s", complement);
  for (int i = 0; i < (PLOT_WIDTH-20) - b_; i++) {
    printf(" ");
  }
}

int display_count(Count ct, int* num_colors) {
  // unsure if this will continue to work with the new structs
  // -- need length of series array
  printf("Number of colors: %i, Number of bars: %zu\n", *num_colors,
         ct.dataframe.num_cols);

  printf("\t\t\U0000250F\n");
  for (size_t i = 0; i < ct.dataframe.num_cols; i++) {
    // name of row
    printf("%s\t", ct.dataframe.columns[i].name);

    printf("\U0000252B");
    switch (i % *num_colors) {
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
    blocks(&ct.numblocks[i]);
    free(ct.numblocks);
    printf(RESET);
    // value in row
    // TODO: error catch incorrect format of data being handed off.
    printf("\t%f\n", ct.dataframe.columns[i].numbers[0]);
  }
  printf("\t\t\U00002517\n");
  return 0;
}


// TODO: explain this test case
int main(void) {

  int nc = 4;
  float o[3] = {600.0, 200.0, 1400.0};
  int nb[3];

  Series val1 = {
      .name = "TESTtest",
      .numbers = &o[0],
  };
  Series val2 = {
      .name = "JONATHAN",
      .numbers = &o[1],
  };
  Series val3 = {
      .name = "JENNIFER",
      .numbers = &o[2],
  };

  Series* cols = malloc(sizeof(Series) * 3);
  Dataframe v = {.columns = cols, .num_cols = 3, .num_rows = 1};

  Count ct = df_to_count(v);

  for (int j = 0; j < sizeof(nb); j++) {
    nb[j] = (o[j] / 70) * 8;
  }
  ct.numblocks = nb;
  display_count(ct, &nc);
  free(cols);
}
