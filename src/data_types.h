#pragma once

#include "constants.h"

#include <stdlib.h>

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

int dataframe_free(Dataframe* dataframe);

typedef struct {
    Dataframe* dataframe;
    int* numblocks; // array containing number of 1/8 character-width blocks to plot
    // this array has length dataframe.num_cols
    // Additional peripheral values should be added to this struct such as plot name, colors
} Count;

int count_free(Count* count);
