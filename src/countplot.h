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
int display_count(Count count, int num_colors);

/* Take a pointer for a Dataframe object and turn that object into a Count.
 *
 * This function looks into the pointer at the Dataframe and does the analysis
 * necessary to determine the number of 1/8 Unicode blocks to plot the data
 * in the terminal.
 *
 * @param dataframe A pointer to the dataframe to be analyzed.
 */
Count df_to_count(Dataframe* dataframe);
