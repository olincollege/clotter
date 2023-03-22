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

/*
 * Deconstructs Dataframe struct, starting with the data in each Series, then freeing the Series themselves, and the Dataframe struct last. All struct members are free before freeing their respective structs.
 *
 * @param dataframe a struct containing an array of Series structs, and number of blocks.
 * 
 * @return int returns 0 if successfully executed, undefined behavior on failure.
 */
int Dataframe_free(Dataframe* dataframe);

typedef struct {
    Dataframe* dataframe;
    int* numblocks; // array containing number of 1/8 character-width blocks to plot
    // this array has length Dataframe.num_cols
    // Additional peripheral values should be added to this struct such as plot name, colors
} Count;

/*
* Deconstructs count struct, starting with the number of blocks, then freeing all struct members from each Series in the Dataframe, before freeing all Series structs from the Dataframe and freeing the Dataframe struct last. All struct members are free before freeing the struct.
 *
 * @param count struct containing a populated Dataframe struct and number of blocks.
 * 
 * @return int returns 0 if successfully executed, undefined behavior on failure.
 */
int count_free(Count* count);
