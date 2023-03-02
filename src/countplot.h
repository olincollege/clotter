
#include "../src/data_types.h"

#pragma once



/*
 * Plots a Count plot in the terminal from given data in a series struct.
 *
 * Program takes an array of series structs, for each row in the data that was 
 * interpreted. Looping through this array, each row of the plot is built; printing
 * the name, relative size of the value, and the real value. 
 *
 * @param values array of Series structs corresponding to each row of data
 *
 */
int count(Count all, int* num_colors);



