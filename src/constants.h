#pragma once


#include <string.h>

// count plot structure chars
#define TOP_LEFT_CORNER     "\U0000250C"
#define BOTTOM_LEFT_CORNER  "\U00002514"
#define LEFT_TICK           "\U00002524"

// Blocks
#define WHOLE_BLOCK "\U00002588"
#define BLOCK_1 "\U0000258F"
#define BLOCK_2 "\U0000258E"
#define BLOCK_3 "\U0000258D"
#define BLOCK_4 "\U0000258C"
#define BLOCK_5 "\U0000258B"
#define BLOCK_6 "\U0000258A"
#define BLOCK_7 "\U00002589"
#define BLOCK_8 "\U00002588"

// color format codes
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

// plot constants that are used throughout multiple functions
enum {
  PLOT_WIDTH = 80,
  NAME_SPACE = 20,
};
