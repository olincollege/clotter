#pragma once

#include <stdlib.h>
#include "constants.h"

// TODO: Add unicode chars for blocks here, increase code readiblity
typedef struct {
    // cap name at 20 characters for statc compile-time size
    char name[NAME_SPACE];
    float* numbers;
} Series;

typedef struct {
    Series* columns;
    size_t num_cols;
    size_t num_rows;
    // assumes that all columns have the same length -- afaik this is true
} Dataframe;

// MEMORY ALLOCATED: numblocks should be freed when done with this struct
typedef struct {
    Dataframe* dataframe;
    int* numblocks; // array containing number of 1/8 character-width blocks to plot
    // this array has length dataframe.num_cols
    // Additional peripheral values should be added to this struct such as plot name, colors
} Count;
