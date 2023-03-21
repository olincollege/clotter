#pragma once


#include <string.h>

// plot structure chars

#define TOP_LEFT_CORNER     "\U0000250C"
#define TOP_RIGHT_CORNER    
#define BOTTOM_LEFT_CORNER  "\U00002514"
#define BOTTOM_RIGHT_CORNER "\U00002518"
#define LEFT_TICK           "\U00002524"
#define BOTTOM_TICK         
#define HORIZONTAL_BAR      
#define VERTICAL_BAR        

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


// Braille chars
#define BLANK_BRAILLE "\U00002800"
// Single 
#define TL "\U00002801"
#define TR "\U00002808"
#define MTL "\U00002802"
#define MTR "\U00002810"
#define MBL "\U00002804"
#define MBR "\U00002820"
#define BL "\U00002840"
#define BR "\U00002880"
// double
#define MBL_MTR 
#define MTL_TR
#define BL_MBR
#define MTL_MBR
#define BL_MBR
#define MBL_BR
// quad
#define BL_TR
#define TL_BR
#define BL_TL
#define TR_BR
// color format codes
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

/**
 * An enum that contains various important constants.
 */

enum {
  PLOT_WIDTH = 80,
  NAME_SPACE = 20,
};
