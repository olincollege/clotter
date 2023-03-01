
#include "colors.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void blocks(float* scale) {
  // returns a string of length 20 filled with scale many blocks, resolution
  // 1/8.
  char* whole_block = "\U00002588";
  int b_ = floor(*scale);
  char output[21 - b_];

  for (int i = 0; i < b_; i++) {
    printf("%s", whole_block);
  }
  char* complement = "";
  // determine complement for blocks
  int state = (int)round((*scale - (float)b_) * 8);
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
  for (int i = 0; i < 20 - b_; i++) {
    printf(" ");
  }
}

int count(char** names, float* values, float* b, int* num_colors) {
  // TODO: need to switch to using struct that we have defined, currently
  // using arrays
  int data_size = sizeof(values) / sizeof(*values);
  printf("Number of colors: %i, Number of bars: %i\n", *num_colors, data_size);

  printf("\t\t\U0000250F\n");
  for (int i = 0; i < data_size; i++) {
    // name of row
    printf("%s\t", names[i]);

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
    blocks(&b[i]);
    printf(RESET);
    // value in row
    printf("\t%f\n", values[i]);
  }
  printf("\t\t\U00002517\n");
  return 0;
}
